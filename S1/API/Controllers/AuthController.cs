using Microsoft.AspNetCore.Mvc;
using Microsoft.IdentityModel.Tokens;
using System.IdentityModel.Tokens.Jwt;
using System.Security.Claims;
using System.Text;
using API.DB;
using API.Helper;
using API.Services;
using StackExchange.Redis;

namespace API.Controllers;

[ApiController]
[Route("[controller]")]
public class AuthController : ControllerBase
{
    private readonly IConfiguration _configuration;
    private readonly KeyService _keyService;
    private readonly UserService _userService;
    private readonly RedisManager _redisManager;

    public AuthController(IConfiguration configuration, KeyService keyService, UserService userService,
        RedisManager redisManager)
    {
        _configuration = configuration;
        _keyService = keyService;
        _userService = userService;
        _redisManager = redisManager;
    }

    /// <summary>
    /// Register user account
    /// </summary>
    /// <param name="model"></param>
    /// <returns></returns>
    [HttpPost("register")]
    public async Task<IActionResult> Register([FromBody] RegisterModel model)
    {
        var userByUserId = await _userService.GetUserAccountByUserId(model.UserId);
        if (userByUserId != null)
        {
            return BadRequest("User ID already exists");
        }

        var result = await _userService.RegisterUser(model.UserId, model.Username, model.Password, model.Email);
        if (result)
        {
            return Ok("User registered successfully");
        }

        return BadRequest("Registration failed");
    }

    [HttpPost("login")]
    public async Task<IActionResult> Login([FromBody] LoginModel login)
    {
        var isValid = await _userService.ValidateUserByIdAndPassword(login.UserId, login.Password);
        if (!isValid)
        {
            return Unauthorized("Invalid credentials");
        }

        var key = _keyService.GenerateKey();
        // 만료시간 1시간짜리 등록
        var userId = login.UserId;
        await _redisManager.QueryRedisAsync(db => db.SetAddAsync(userId, "1234"));
        await _redisManager.QueryRedisAsync(db => db.KeyExpireAsync(userId,TimeSpan.FromHours(1)));
        return Ok(new { Token= key });
    }
}

public class LoginModel
{
    public string UserId { get; set; }
    public string Password { get; set; }
}

public class RegisterModel
{
    public string UserId { get; set; }
    public string Username { get; set; }
    public string Password { get; set; }
    public string Email { get; set; }
}
