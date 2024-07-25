using Microsoft.AspNetCore.Mvc;
using Microsoft.IdentityModel.Tokens;
using System.IdentityModel.Tokens.Jwt;
using System.Security.Claims;
using System.Text;
using API.Services;

namespace API.Controllers;

[ApiController]
[Route("[controller]")]
public class AuthController : ControllerBase
{
    private readonly IConfiguration _configuration;
    private readonly KeyService _keyService;
    private readonly UserService _userService;

    public AuthController(IConfiguration configuration, KeyService keyService, UserService userService)
    {
        _configuration = configuration;
        _keyService = keyService;
        _userService = userService;
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

    /// <summary>
    /// Issue a JWT(JSON Web Token)
    /// </summary>
    /// <param name="login"></param>
    /// <returns></returns>
    [HttpPost("login")]
    public async Task<IActionResult> Login([FromBody] LoginModel login)
    {
        var isValid = await _userService.ValidateUserByIdAndPassword(login.UserId, login.Password);
        if (!isValid)
        {
            return Unauthorized("Invalid credentials");
        }

        var tokenHandler = new JwtSecurityTokenHandler();
        var key = _keyService.GetActiveKeys().First();
        var tokenDescriptor = new SecurityTokenDescriptor
        {
            Subject = new ClaimsIdentity(new Claim[]
            {
                new Claim(ClaimTypes.Name, login.UserId)
            }),
            Expires = DateTime.UtcNow.AddHours(1), // 만료 기간 1시간 
            SigningCredentials =
                new SigningCredentials(key,
                    SecurityAlgorithms.HmacSha512), // 인증 키를 512비트짜리로 변경(기본 256비트짜리이므로 변경하려면 HmacSha256으로 변경해야 함)
            Issuer = _configuration["JwtSettings:Issuer"]
        };
        var token = tokenHandler.CreateToken(tokenDescriptor);
        var tokenString = tokenHandler.WriteToken(token);

        return Ok(new { Token = tokenString });
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