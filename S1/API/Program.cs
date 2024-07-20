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
// ���̺� ���� ������ �ʱ�ȭ ��(������ ���� ������ �� ���󰡹Ƿ� ��ġ ������ �ּ�ó��)
var sqlFilePath = Path.Combine(AppContext.BaseDirectory, "../../../DB/SQL/pre_stored_procedures.sql");
MyQueryExecutor.ExecuteSqlScript(connectionString, sqlFilePath);


// add DbContext to Services & set option 'UseMySql'
builder.Services.AddDbContext<MyDbContext>(options =>
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
                return keyService.GetActiveKeys(); // JWT ���� ��ū�� �߱� �ޱ� ���� ����Ű�� KeyService���� �����´�
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
        // swagger�� Bearer������ ���� ���� �߰�
        In = ParameterLocation.Header, // JWT��ū�� HTTP ��û�� ����� ���Ե��� ��Ÿ��
        Description = "Please enter JWT with Bearer into field", // Swagger UIǥ�� �� ����
        Name = "Authorization", // ��� �̸��� Authorization����
        Type = SecuritySchemeType.ApiKey, // ���� ������ ������ ApiKey�� ����
        // ApiKey�� HTTP ���, ���� �Ű� ���� �Ǵ� ��Ű�� ��ġ�� �� �ִ� API Ű�� ��Ÿ��
        Scheme = "Bearer" // ���� ���� ��Ű���� Bearer�� ����(Bearer ��Ű���� JWT �Ǵ� OAuth 2.0 ��ū�� ������� ��Ÿ��)
    });

    // add security requirement
    // ��� ��������Ʈ�� ���� Bearer ��ū�� �䱸�ϵ��� ����
    options.AddSecurityRequirement(new OpenApiSecurityRequirement
    {
        // OpenApiSecurityRequirement�� ����Ͽ� ���� ��Ű���� �ش� ��Ű���� ����Ǵ� �������� ����
        {
            new OpenApiSecurityScheme // ���� ��Ű���� ����
            {
                Reference = new OpenApiReference
                {
                    Type = ReferenceType.SecurityScheme, // ���� ������ SecurityScheme���� ����
                    Id = "Bearer" // ������ ������ Bearer ���� ���� ��Ű���� ����
                }
            },
            new string[] { } // �� ���� ��Ű���� ��� �������� ������� ��Ÿ��
            // �� �迭�� ����Ͽ� ��� ��������Ʈ�� ���� �� ��Ű���� �䱸�ϵ��� ����
        }
    });
});

var app = builder.Build();


// generate a random key from KeyService in the initial settings
using (var scope = app.Services.CreateScope())
{
    var services = scope.ServiceProvider;
    var context = services.GetRequiredService<MyDbContext>();

    // �����ͺ��̽��� �̹� �����ϴ� ��� ���̱׷��̼��� �������� �ʰ� ��� ����
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

    // 7�� ���� Ű ����
    keyService.DeleteExpiredKeys();

    // �ӽ� admin ���� �����ϱ�
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