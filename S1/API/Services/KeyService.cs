using System.Security.Cryptography;
using API.DB;
using API.Models;
using Microsoft.IdentityModel.Tokens;
using StackExchange.Redis;

namespace API.Services;

public class KeyService
{
    private readonly RedisManager _redisManager;
    private readonly GameServerDbContext _dbContext;
    private const string SetKey = "user:keys";

    public KeyService(GameServerDbContext dbContext, RedisManager redisManager)
    {
        try
        {

            _dbContext = dbContext;
            _redisManager = redisManager;
        }
        catch (Exception e)
        {
            Console.WriteLine(e);
            Console.WriteLine(e);
        }
    }

    // GetActiveKeys 메서드를 수정하여 SymmetricSecurityKey를 직접 반환
    public string GenerateKey()
    {
        return GenerateRandomKey();
    }


    // public async Task RegisterUserKey(string userId, string key)
    // {
    //     // 기존 set삭제
    //     await _redisManager._connectionPool.QueryRedisAsync(db => db.KeyDeleteAsync(userId));
    //     // 새로운 set 등록하기
    //     await _redisManager._connectionPool.QueryRedisAsync(db => db.SetAddAsync(userId, key));
    //     // userId에 해당하는 set 만료시간 1시간으로 설정
    //     await _redisManager._connectionPool.QueryRedisAsync(db => db.KeyExpireAsync(userId, TimeSpan.FromHours(1)));
    // }
    //
    // public async Task<bool> DeleteUserKey(string userId, string key)
    // {
    //     // 기존 set삭제
    //     return await _redisManager._connectionPool.QueryRedisAsync(db => db.KeyDeleteAsync(userId));
    // }
    //
    // private async Task DeleteAllUserKeys()
    // {
    //     var keys = _redisManager._server.Keys(pattern:"*");
    //     var tasks = new List<Task>();
    //
    //     foreach (var key in keys)
    //     {
    //         if (await _redisManager._database.KeyTypeAsync(key) == RedisType.Set) // 키의 타입이 Set인지 확인
    //         {
    //             tasks.Add(_redisManager._database.KeyDeleteAsync(key)); // 집합 삭제
    //         }
    //     }
    //
    //     await Task.WhenAll(tasks); // 모든 삭제 작업을 병렬로 실행
    // }
    //
    // public async Task<string[]> GetAllUserKeys()
    // {
    //     var members = await _redisManager._connectionPool.QueryRedisAsync(db => db.SetMembersAsync(SetKey));
    //     return members.Select(m => m.ToString()).ToArray();
    // }

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

    // JWT토큰키 생성
    public IEnumerable<SecurityKey> GenerateSecurityKey()
    {
        // 예시: RSA 키를 사용하는 경우
        var rsa = new RSACryptoServiceProvider(2048);
        var key = new RsaSecurityKey(rsa)
        {
            KeyId = GenerateKey()
        };

        return new List<SecurityKey> { key };
    }
}
