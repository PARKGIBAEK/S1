using System.Security.Cryptography;
using System.Text;
using API.Data;
using API.Model;
using Microsoft.IdentityModel.Tokens;

namespace API.Services;

/* JWT 인증 토큰을 발급 받기 위한 랜덤키를 DB에 생성하고 가져온다
 * 참고로 '~Service'류의 네이밍은 DbContext를 통해 DB와 통신하는 것들이다 */
public class KeyService(MyDbContext dbContext)
{
    // GetActiveKeys 메서드를 수정하여 SymmetricSecurityKey를 직접 반환
    public List<SecurityKey> GetActiveKeys()
    {
        try
        {
            var keys = dbContext.auth_key
                .Where(k => k.created_at > DateTime.UtcNow.AddDays(-1))
                .Select(k => new SymmetricSecurityKey(Convert.FromBase64String(k.key_value)) as SecurityKey)
                .ToList();

            if (!keys.Any())
            {
                GenerateAndSaveKey();
                keys = dbContext.auth_key
                    .Where(k => k.created_at > DateTime.UtcNow.AddDays(-1))
                    .Select(k => new SymmetricSecurityKey(Convert.FromBase64String(k.key_value)) as SecurityKey)
                    .ToList();
            }
        
            return keys;
        }
        catch (Exception ex)
        {
            Console.WriteLine($"Error in GetActiveKeys: {ex.Message}");
            Console.WriteLine($"Stack Trace: {ex.StackTrace}");
            // 여기서 빈 리스트를 반환하거나 기본 키를 생성할 수 있습니다.
            return new List<SecurityKey>();
        }
    }
    
    public void GenerateAndSaveKey()
    {
        var newRandomGeneratedKey = GenerateRandomKey();
        var keyEntity = new auth_key
        {
            key_value = newRandomGeneratedKey,
            created_at = DateTime.UtcNow,
        };

        dbContext.auth_key.Add(keyEntity);
        dbContext.SaveChanges();
    }
    
    // key valid in 24 hours
    public void DeleteExpiredKeys()
    {
        var expiryDate = DateTime.UtcNow.AddDays(-1); // keys generated before 24 hours
        var expiredKeys = dbContext.auth_key.Where(k => k.created_at <= expiryDate).ToList();
        dbContext.auth_key.RemoveRange(expiredKeys);
        dbContext.SaveChanges();
    }

    // JWT토큰 생성에 사용되는 인증키의 길이는 기본적으로 (32바이트)256비트이다.
    // 그러나 이 프로젝트에서는 (64바이트)512비트를 사용한다.
    // 따라서 AuthController에서 JWT토큰을 생성할 때
    // 256비트 알고리즘이 아닌 512비트 알고리즘으로 변경하도록 명시해주고 있다.(권고사항)
    private string GenerateRandomKey(int sizeInBytes = 64) // 32바이트 = 256비트
    {
        using var randomNumberGenerator = RandomNumberGenerator.Create();
        var byteArray = new byte[sizeInBytes];
        randomNumberGenerator.GetBytes(byteArray);
        return Convert.ToBase64String(byteArray);
    }
    
}