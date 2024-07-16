#pragma once
#include <string>
#include <vector>
#include <boost/asio.hpp>
#include <boost/mysql/connection_pool.hpp>
#include <boost/lockfree/queue.hpp>
#include <boost/mysql/tcp.hpp>

#include "Core/Types.h"

using namespace boost;
using namespace ServerCore;

// #define DB_TEST_MODE

/*  boost::mysql::tcp_connection을 사용한 단순한 pooling 방식을 선택한 이유 :
 *  boost::mysql::pooled_connection은 아직 experimental이라 제대로 작동하지 않음 */
class MySqlConnectionPool : public asio::noncopyable
{
    enum Config
    {
        host,
        port,
        user,
        password,
        database,
    };

public:
    MySqlConnectionPool(const std::string& _filename, asio::io_context& _ioContext, int32 _poolSize);
    ~MySqlConnectionPool();
    bool CreateConnectionPool(int32 _poolCount);
    mysql::tcp_connection* CreateConnection();
    mysql::tcp_connection* GetPooledConnection();
    void ReturnConnection(mysql::tcp_connection* conn);

private:
    static std::vector<std::string> ReadConfig(const std::string& filename);
    void CleanupConnectionPool();

    //deleted
    MySqlConnectionPool(const MySqlConnectionPool&) = delete;
    MySqlConnectionPool& operator=(const MySqlConnectionPool&) = delete;

private:
    std::vector<std::string> m_connectionConfig;
    lockfree::queue<mysql::tcp_connection*> m_connectionPool;
    std::atomic<int32> m_poolAvailable;
    std::atomic<int32> m_poolBorrowed;
    asio::io_context& m_ioContext;
    asio::ip::basic_resolver_results<asio::ip::tcp>* m_endpoints;
    mysql::handshake_params* m_params;

#if defined(DB_TEST_MODE)
    bool TestConnect(mysql::tcp_connection* conn);
    bool TestConnectionPool();
    std::string m_testTableName = "users";
#endif
};
