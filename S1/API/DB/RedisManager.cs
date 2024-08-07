using API.Helper;
using StackExchange.Redis;

namespace API.DB;

public class RedisManager
{
    internal readonly IDatabase _database;
    internal readonly IServer _server;
    private readonly ConnectionMultiplexer _connectionPool;

    public RedisManager(string connectionString, int poolSize)
    {
        try
        {
            // _connectionPool = new(connectionString, poolSize);
            var options = new ConfigurationOptions()
            {
                EndPoints = { connectionString },
                AbortOnConnectFail = false,
                ConnectTimeout = 5000,
                SyncTimeout = 5000
            };

            _connectionPool = ConnectionMultiplexer.ConnectAsync(options).Result;
            _database = _connectionPool.GetDatabase();
            if (_connectionPool.IsConnected)
            {
                ConsoleHelper.PrintSuccessMessage($"Connected to redis-server({_connectionPool.Configuration})");
            }
        }
        catch (RedisConnectionException ex)
        {
            Console.WriteLine(ex);
            if (ex.InnerException != null)
            {
                Console.WriteLine($"내부 예외: {ex.InnerException.Message}");
            }
        }

        // _database = _connectionPool.GetConnectionAsync().Result.Connection.GetDatabase();
        // _server = _redis.GetServer(_redis.GetEndPoints()[0]);
    }

    public async Task QueryRedisAsync(Func<IDatabase, Task> redisAction)
    {
        // var db = _connectionPool.GetDatabase();
        await redisAction(_database);
    }


}
