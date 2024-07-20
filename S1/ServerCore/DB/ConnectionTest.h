#pragma once
#include <string>
#include <boost/lockfree/queue.hpp>
#include <boost/mysql/tcp.hpp>

#include "Core/Types.h"

namespace DB
{

using namespace ServerCore;
using namespace boost;

class ConnectionTest : public asio::noncopyable
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
    ConnectionTest(const std::string& _filename, asio::io_context& _ioContext, int32 _poolSize);
    ~ConnectionTest();
    bool CreateConnectionPool(ServerCore::int32 _poolCount);
    mysql::tcp_connection* CreateConnection();
    mysql::tcp_connection* GetPooledConnection();
    void ReturnConnection(mysql::tcp_connection* conn);
    
    // test.users 테이블이 존재해야 한다
    bool TestConnect(mysql::tcp_connection* conn);
    bool TestConnectionPool();
    
private:
    static std::vector<std::string> ReadConfig(const std::string& filename);
    void CleanupConnectionPool();

    //deleted
    ConnectionTest(const ConnectionTest&) = delete;
    ConnectionTest& operator=(const ConnectionTest&) = delete;

private:
    std::vector<std::string> m_connectionConfig;
    lockfree::queue<mysql::tcp_connection*> m_connectionPool;
    std::atomic<int32> m_poolAvailable;
    std::atomic<int32> m_poolBorrowed;
    asio::io_context& m_ioContext;
    asio::ip::basic_resolver_results<asio::ip::tcp>* m_endpoints;
    mysql::handshake_params* m_params;

   
    std::string m_testTableName = "user_test";
    std::string m_testDatabaseName = "test";
};
}
