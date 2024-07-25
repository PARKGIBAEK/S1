#pragma once
#include <string>
#include <vector>
#include <boost/asio.hpp>
#include <boost/mysql/connection_pool.hpp>
#include <boost/lockfree/queue.hpp>
#include <boost/mysql/tcp.hpp>

#include "Core/Types.h"


using namespace boost;


namespace DB
{
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
    MySqlConnectionPool(const std::string& _filename, asio::io_context& _ioContext, std::int32_t _poolSize);
    ~MySqlConnectionPool();
    bool CreateConnectionPool(std::int32_t _poolCount);
    mysql::tcp_connection* CreateConnection();
    mysql::tcp_connection* GetPooledConnection();
    void ReturnConnection(mysql::tcp_connection* conn);
    void CleanupConnectionPool();

private:
    static std::vector<std::string> ReadConfig(const std::string& filename);

    //deleted
    MySqlConnectionPool(const MySqlConnectionPool&) = delete;
    MySqlConnectionPool& operator=(const MySqlConnectionPool&) = delete;

private:
    std::vector<std::string> m_connectionConfig;
    lockfree::queue<mysql::tcp_connection*> m_connectionPool;
    std::atomic<std::int32_t> m_poolAvailable;
    std::atomic<std::int32_t> m_poolBorrowed;
    asio::io_context& m_ioContext;
    asio::ip::basic_resolver_results<asio::ip::tcp>* m_endpoints;
    mysql::handshake_params* m_params;

#define MY_TEST_CODE

#if defined(MY_TEST_CODE)
    // test.users 테이블이 존재해야 한다
    bool TestConnect(mysql::tcp_connection* conn);
    bool TestConnectionPool();
    std::string m_testTableName = "user_test";
#endif
};
}
