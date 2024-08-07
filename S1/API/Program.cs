// Program.cs
using System.Text.Json;
using API.DB;
using API.Helper;
using API.Models;
using API.Services;
using Microsoft.AspNetCore.Authentication.JwtBearer;
using Microsoft.AspNetCore.Diagnostics;
using Microsoft.AspNetCore.Mvc.Controllers;
using Microsoft.EntityFrameworkCore;
using Microsoft.IdentityModel.Tokens;
using Microsoft.OpenApi.Models;

var builder = WebApplication.CreateBuilder(args);

// get "DefaultConnectionString" under "DefaultConnection" item from 'appsettings.json'
var connectionString = builder.Configuration.GetConnectionString("DefaultConnection");

// execute an sp for init
// 테이블 전부 날리고 초기화 함(생성된 유저 계정도 다 날라가므로 원치 않으면 주석처리)
string? dbSetupFile = builder.Configuration["DbSetupFile"];
var sqlFilePath = Path.Combine(AppContext.BaseDirectory, dbSetupFile);

if (connectionString == null)
    throw new Exception("connectionString is null");

// MyQueryExecutor.ExecuteSqlScript(connectionString, sqlFilePath);


// add DbContext to Services & set option 'UseMySql'
builder.Services.AddDbContext<GameServerDbContext>(options =>
    options.UseMySql(builder.Configuration.GetConnectionString("DefaultConnection"), ServerVersion.AutoDetect(connectionString)));


// register services
builder.Services.AddScoped<KeyService>();
builder.Services.AddScoped<UserService>();

// settings about JWT
builder.Services.AddJwtAuthentication(builder.Configuration);

// Add services to the container.
builder.Services.AddControllers();

/*
 * AddSingleton매서드는 서비스를 싱글톤으로 등록한다.
 * 첫번째 제네릭 인자는 해당 서비스의 인터페이스 타입을 기입하며,
 * 두번째 제네릭 인자는 해당 서비스의 인터페이스를 구현한 실제 클래스 타입이다.
 * 참고로 IControllerActivator는 ASP.NET Core MVC에서 컨트롤러 인스턴스의 생성/해제를 정의하는 인터페이스다.
 */
// Register a RedisManager as a Singleton
builder.Services.AddSingleton<RedisManager>(sp =>
    new RedisManager(builder.Configuration.GetConnectionString("RedisConnection"), poolSize: 5));
builder.Services.AddTransient<IStartupFilter, ControllerLoggingStartupFilter>();

// Add logging service
builder.Services.AddLogging(logging =>
{
    logging.ClearProviders();
    logging.AddConsole();
    logging.AddDebug();
});

// Learn more about configuring Swagger/OpenAPI at https://aka.ms/aspnetcore/swashbuckle
// set Swagger
builder.Services.AddEndpointsApiExplorer();
builder.Services.AddSwaggerGen(options =>
{
    // add security definition
    options.AddSecurityDefinition("Bearer", new OpenApiSecurityScheme
    {
        // swagger에 Bearer형식의 보안 정의 추가
        In = ParameterLocation.Header, // JWT토큰이 HTTP 요청의 헤더에 포함됨을 나타냄
        Description = "Please enter JWT with Bearer into field", // Swagger UI표시 될 설명
        Name = "Authorization", // 헤더 이름을 Authorization으로
        Type = SecuritySchemeType.ApiKey, // 보안 정의의 유형을 ApiKey로 설정
        // ApiKey는 HTTP 헤더, 쿼리 매개 변수 또는 쿠키에 위치할 수 있는 API 키를 나타냄
        Scheme = "Bearer" // 보안 인증 스키마를 Bearer로 설정(Bearer 스키마는 JWT 또는 OAuth 2.0 토큰을 사용함을 나타냄)
    });

    // add security requirement
    // 모든 엔드포인트에 대해 Bearer 토큰을 요구하도록 지정
    options.AddSecurityRequirement(new OpenApiSecurityRequirement
    {
        // OpenApiSecurityRequirement를 사용하여 보안 스키마와 해당 스키마가 적용되는 스코프를 정의
        {
            new OpenApiSecurityScheme // 보안 스키마를 정의
            {
                Reference = new OpenApiReference
                {
                    Type = ReferenceType.SecurityScheme, // 참조 유형을 SecurityScheme으로 설정
                    Id = "Bearer" // 위에서 정의한 Bearer 보안 인증 스키마를 참조
                }
            },
            new string[] { } // 이 보안 스키마가 모든 스코프에 적용됨을 나타냄
            // 빈 배열을 사용하여 모든 엔드포인트에 대해 이 스키마를 요구하도록 설정
        }
    });
});

var app = builder.Build();


// generate a random key from KeyService in the initial settings
using (var scope = app.Services.CreateScope())
{
    var services = scope.ServiceProvider;
    var context = services.GetRequiredService<GameServerDbContext>();

    // 데이터베이스가 이미 존재하는 경우 마이그레이션을 적용하지 않고 계속 진행
    if (context.Database.CanConnect())
    {
        Console.WriteLine("Database already exists. Skipping migration.");
    }
    else
    {
        Console.WriteLine("Creating database and applying migrations...");
        context.Database.Migrate();
    }

    // 임시 admin 계정 생성하기
    try
    {
        var userService = services.GetRequiredService<UserService>();
        var adminExists = await userService.GetUserAccountByUserId("admin");

        if (adminExists == null)
        {
            await userService.RegisterUser("admin", "admin", "admin", "admin@test.com");
        }
    }
    catch (Exception ex)
    {
        Console.WriteLine($"Error : creating admin user: {ex.Message}");
    }
}

// Configure the HTTP request pipeline.
if (app.Environment.IsDevelopment())
{
    app.UseSwagger();
    app.UseSwaggerUI();
}

app.UseExceptionHandler("/Error");
app.UseHttpsRedirection();
app.UseStaticFiles();

app.UseRouting();
app.UseAuthentication();
app.UseAuthorization();

app.MapControllers();

app.UseExceptionHandler(a => a.Run(async context =>
{
    var exceptionHandlerPathFeature = context.Features.Get<IExceptionHandlerPathFeature>();
    var exception = exceptionHandlerPathFeature.Error;

    var result = JsonSerializer.Serialize(new { error = exception.Message });
    context.Response.ContentType = "application/json";
    await context.Response.WriteAsync(result);
}));

app.Run();
