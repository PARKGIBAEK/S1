#include "pch.h"
#include "ConnectionTest.h"

#include <fstream>
#include <iostream>
#include "Util/Path.h"


namespace DB
{

// '_filename' is a directory based on the path of the executable
ConnectionTest::ConnectionTest(const std::string& _filename, asio::io_context& _ioContext, int32 _poolSize):
    m_connectionPool(_poolSize), m_ioContext(
        _ioContext)
{
    try
    {
        std::string configFilePath = Path::GetRelativeFilePath(_filename);
        m_connectionConfig = ReadConfig(configFilePath);
        if (false == CreateConnectionPool(_poolSize))
            throw std::runtime_error("Failed to create MySql connection pool");
    }
    catch (std::exception ex)
    {
        std::cout << ex.what();
    }
}

ConnectionTest::~ConnectionTest()
{
    CleanupConnectionPool();
}

bool ConnectionTest::CreateConnectionPool(int32 _poolCount)
{
    // Application config
    const std::string host = m_connectionConfig[Config::host];
    const std::string port = m_connectionConfig[Config::port];
    const std::string user = m_connectionConfig[Config::user];
    const std::string password = m_connectionConfig[Config::password];
    const std::string database = m_connectionConfig[Config::database];

    if (m_connectionConfig.size() != 5)
        throw std::runtime_error("Invalid configuration");

    // Resolver for hostname resolution
    asio::ip::tcp::resolver resolver(m_ioContext.get_executor());

    // Connection params
    m_params = new mysql::handshake_params{
        user,
        password,
        database
    };

    m_endpoints = new asio::ip::basic_resolver_results<asio::ip::tcp>(resolver.resolve(host, port));

    for (int i = 0; i < _poolCount; i++)
    {
        // mysql::tcp_connection* conn = new mysql::tcp_connection(m_ioContext);
        mysql::tcp_connection* conn = CreateConnection();
        ReturnConnection(conn);


        // if(!TestConnect(conn))
        //     throw std::runtime_error("Invalid connection");
    }

    return true;
}


mysql::tcp_connection* ConnectionTest::CreateConnection()
{
    mysql::tcp_connection* conn = new mysql::tcp_connection(m_ioContext);

    try
    {
        conn->connect(*m_endpoints->begin(), *m_params);
    }
    catch (const mysql::error_with_diagnostics& err)
    {
        std::cerr << "Failed to create connection at " << m_poolAvailable + m_poolBorrowed << std::endl;
        std::cerr << "Error: " << err.what() << ", error code: " << err.code() << '\n'
            << "Server diagnostics: " << err.get_diagnostics().server_message() << std::endl;
        return nullptr;
    }
    catch (std::exception ex)
    {
        std::cout << ex.what();
    }

    m_poolBorrowed.fetch_add(1);
    return conn;
}


mysql::tcp_connection* ConnectionTest::GetPooledConnection()
{
    mysql::tcp_connection* conn;
    if (m_connectionPool.pop(conn))
    {
        m_poolAvailable.fetch_sub(1);
        return conn;
    }
    else
    {
        m_poolBorrowed.fetch_add(1);
        return CreateConnection();
    }
}

std::vector<std::string> ConnectionTest::ReadConfig(const std::string& filename)
{
    std::ifstream file(filename);
    std::vector<std::string> config;

    if (file.is_open())
    {
        std::string line;
        while (std::getline(file, line))
        {
            config.push_back(line);
        }
        file.close();
    }
    else
    {
        throw std::runtime_error("Unable to open file");
    }

    return config;
}

void ConnectionTest::ReturnConnection(mysql::tcp_connection* conn)
{
    m_connectionPool.push(conn);
    m_poolAvailable.fetch_add(1);
    m_poolBorrowed.fetch_sub(1);
}

void ConnectionTest::CleanupConnectionPool()
{
    mysql::tcp_connection* conn;
    while (m_connectionPool.pop(conn))
    {
        conn->close();
        std::cout << "DB Connection closed" << std::endl;
        delete conn;
    }
}

bool ConnectionTest::TestConnect(mysql::tcp_connection* conn)
{
    // test for user table.
    const char* sql = "SELECT * from user_test";
    mysql::results result;
    conn->execute(sql, result);

    for (const auto& meta : result.meta())
        std::cout << meta.column_name() << '\t';

    for (auto row : result.rows())
    {
        auto columns = row.size();
        for (int i = 0; i < columns; i++)
            std::cout << row.at(i) << "\t";
        std::cout << '\n';
    }
    std::cout.flush();

    return true;
}

bool ConnectionTest::TestConnectionPool()
{
    std::atomic<int64_t> count=0;
    auto lambda = [this,&count]()
    {
        while (count < m_poolAvailable)
        {
            auto conn = GetPooledConnection();
            std::string sql = std::format("SELECT * from {}",m_testTableName);
            mysql::results result;
            conn->execute(sql, result);

            for (const auto& meta : result.meta())
                std::cout << meta.column_name() << '\t';

            for (auto row : result.rows())
            {
                auto columns = row.size();
                for (int i = 0; i < columns; i++)
                    std::cout << row.at(i) << "\t";
                std::cout << '\n';
            }
            std::cout.flush();
            std::cout << "Done - " << ++count << std::endl;
            ReturnConnection(conn);
            using namespace std::chrono_literals;
            std::this_thread::sleep_for(0.1s);
        }
    };
    asio::io_context ioContext;
    std::vector<std::thread> threads;
    for (int i = 0; i < 10; i++)
    {
        threads.emplace_back(lambda);
    }

    for (auto& thread : threads)
        thread.join();

    return true;
}
}
