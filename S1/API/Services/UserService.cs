using API.Data;
using API.Model;
using Microsoft.EntityFrameworkCore;

namespace API.Services;

/* UserService는 로그인 인증 후 JWT토큰을 발급받기 위한 Random Key를 DB에서 가져오는 용도이다*/

public class UserService(MyDbContext context)
{
    public async Task<bool> RegisterUser(string userId, string username, string password, string email)
    {
        var hashedPassword = BCrypt.Net.BCrypt.HashPassword(password);
        var user = new user_accounts
        {
            user_id = userId,
            user_name = username,
            password = hashedPassword, // DB에 저장할 때 Hashing된 값으로 저장됨
            email = email,
            created_at = DateTime.Now, // Default 값으로 자동 생성인데 오류나서 일단 추가함
            updated_at = DateTime.Now
        };

        context.user_accounts.Add(user);
        await context.SaveChangesAsync();
        return true;
    }

    public async Task<user_accounts?> GetUserAccountByUserId(string userId)
    {
        user_accounts? userAccounts = await context.user_accounts.FirstOrDefaultAsync(userAccount => userAccount.user_id == userId);
        return userAccounts;
    }

    public async Task<bool> ValidateUserByIdAndPassword(string userId, string password)
    {
        var user = await GetUserAccountByUserId(userId);
        if (user == null)
            return false;

        try
        {
            return BCrypt.Net.BCrypt.Verify(password, user.password);
        }
        catch (Exception ex)
        {
            Console.WriteLine($"Error verifying password: {ex.Message}");
            return false;
        }
    }
}