// Program.cs

using System.IdentityModel.Tokens.Jwt;
using System.Text.Json;
using API.Data;
using API.DB;
using API.Services;
using Microsoft.AspNetCore.Authentication.JwtBearer;
using Microsoft.AspNetCore.Diagnostics;
using Microsoft.EntityFrameworkCore;
using Microsoft.Extensions.Configuration;
using Microsoft.IdentityModel.Tokens;
using Microsoft.OpenApi.Models;

var builder = WebApplication.CreateBuilder(args);

// get "DefaultConnectionString" under "DefaultConnection" item from 'appsettings.json'
var connectionString = builder.Configuration.GetConnectionString("DefaultConnection");

// execute an sp for init
// 테이블 전부 날리고 초기화 함(생성된 유저 계정도 다 날라가므로 원치 않으면 주석처리)
var sqlFilePath = Path.Combine(AppContext.BaseDirectory, "../../../DB/SQL/create_table.sql");

if (connectionString == null)
    throw new Exception("connectionString is null");

MyQueryExecutor.ExecuteSqlScript(connectionString, sqlFilePath);


// add DbContext to Services & set option 'UseMySql'
builder.Services.AddDbContext<GameDbContext>(options =>
    options.UseMySql(connectionString, ServerVersion.AutoDetect(connectionString)));


// register services
builder.Services.AddScoped<KeyService>();
builder.Services.AddScoped<UserService>();

// get "JwtSettings" item from 'appsettings.json'
var jwtSettings = builder.Configuration.GetSection("JwtSettings");

// settings about JWT
builder.Services.AddAuthentication(JwtBearerDefaults.AuthenticationScheme)
    .AddJwtBearer(options =>
    {
        options.TokenValidationParameters = new TokenValidationParameters
        {
            ValidateIssuer = true,
            ValidateAudience = false,
            ValidateLifetime = true,
            ValidateIssuerSigningKey = true,
            ValidIssuer = jwtSettings["Issuer"],
            IssuerSigningKeyResolver = (token, securityToken, kid, validationParameters) =>
            {
                var keyService = builder.Services.BuildServiceProvider().GetRequiredService<KeyService>();
                return keyService.GetActiveKeys(); // JWT 인증 토큰을 발급 받기 위한 랜덤키를 KeyService에서 가져온다
            },
            ClockSkew = TimeSpan.Zero
        };

        options.Events = new JwtBearerEvents
        {
            OnAuthenticationFailed = context =>
            {
                Console.WriteLine($"OnAuthenticationFailed: {context.Exception}");
                return Task.CompletedTask;
            },
            OnTokenValidated = context =>
            {
                Console.WriteLine($"OnTokenValidated: {context.SecurityToken}");
                return Task.CompletedTask;
            },
            OnMessageReceived = context =>
            {
                Console.WriteLine($"OnMessageReceived: {context.Token}");
                return Task.CompletedTask;
            },
            OnChallenge = context =>
            {
                Console.WriteLine($"OnChallenge: {context.Error}, {context.ErrorDescription}");
                return Task.CompletedTask;
            }
        };
    });

// Add services to the container.
builder.Services.AddControllers();

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
    var context = services.GetRequiredService<GameDbContext>();

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

    var keyService = scope.ServiceProvider.GetRequiredService<KeyService>();
    if (!keyService.GetActiveKeys().Any())
    {
        keyService.GenerateAndSaveKey();
    }

    // 7일 이전 키 삭제
    keyService.DeleteExpiredKeys();

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
