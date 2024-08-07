using API.Models;
using Microsoft.EntityFrameworkCore;

namespace API.Services;

/* UserService는 로그인 인증 후 JWT토큰을 발급받기 위한 Random Key를 DB에서 가져오는 용도이다*/

public class UserService(GameServerDbContext dbContext)
{
    public async Task<bool> RegisterUser(string userId, string username, string password, string email)
    {
        var hashedPassword = BCrypt.Net.BCrypt.HashPassword(password);
        var user = new UserAccount()
        {
            UserId = userId,
            UserName = username,
            Password = hashedPassword, // DB에 저장할 때 Hashing된 값으로 저장됨
            Email = email,
            // CreatedAt = DateTime.Now, // Default 값으로 자동 생성인데 오류나서 일단 추가함
            // UpdatedAt = DateTime.Now
        };

        dbContext.UserAccounts.Add(user);
        await dbContext.SaveChangesAsync();
        return true;
    }

    public async Task<UserAccount?> GetUserAccountByUserId(string userId)
    {
        UserAccount? userAccount = await dbContext.UserAccounts.FirstOrDefaultAsync(userAccount => userAccount.UserId == userId);
        return userAccount;
    }

    public async Task<bool> ValidateUserByIdAndPassword(string userId, string password)
    {
        var user = await GetUserAccountByUserId(userId);
        if (user == null)
            return false;

        try
        {
            return BCrypt.Net.BCrypt.Verify(password, user.Password);
        }
        catch (Exception ex)
        {
            Console.WriteLine($"Error verifying password: {ex.Message}");
            return false;
        }
    }
}
