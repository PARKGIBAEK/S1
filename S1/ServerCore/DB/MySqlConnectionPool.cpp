﻿#include "MySqlConnectionPool.h"
#include <fstream>
#include <iostream>
#include <boost/asio.hpp>
#include <boost/mysql.hpp>
#include <boost/asio/spawn.hpp>
#include <boost/mysql/error_with_diagnostics.hpp>
#include <boost/mysql/handshake_params.hpp>
#include "Util/Path.h"

#if defined(DB_TEST_MODE)
#include "user.h"
#endif
using namespace ServerCore;


// The CA file that signed the server's certificate
constexpr const char CA_PEM[] = R"%(-----BEGIN CERTIFICATE-----
MIIDZzCCAk+gAwIBAgIUWznm2UoxXw3j7HCcp9PpiayTvFQwDQYJKoZIhvcNAQEL
BQAwQjELMAkGA1UEBhMCQVUxEzARBgNVBAgMClNvbWUtU3RhdGUxDjAMBgNVBAoM
BW15c3FsMQ4wDAYDVQQDDAVteXNxbDAgFw0yMDA0MDQxNDMwMjNaGA8zMDE5MDgw
NjE0MzAyM1owQjELMAkGA1UEBhMCQVUxEzARBgNVBAgMClNvbWUtU3RhdGUxDjAM
BgNVBAoMBW15c3FsMQ4wDAYDVQQDDAVteXNxbDCCASIwDQYJKoZIhvcNAQEBBQAD
ggEPADCCAQoCggEBAN0WYdvsDb+a0TxOGPejcwZT0zvTrf921mmDUlrLN1Z0hJ/S
ydgQCSD7Q+6za4lTFZCXcvs52xvvS2gfC0yXyYLCT/jA4RQRxuF+/+w1gDWEbGk0
KzEpsBuKrEIvEaVdoS78SxInnW/aegshdrRRocp4JQ6KHsZgkLTxSwPfYSUmMUo0
cRO0Q/ak3VK8NP13A6ZFvZjrBxjS3cSw9HqilgADcyj1D4EokvfI1C9LrgwgLlZC
XVkjjBqqoMXGGlnXOEK+pm8bU68HM/QvMBkb1Amo8pioNaaYgqJUCP0Ch0iu1nUU
HtsWt6emXv0jANgIW0oga7xcT4MDGN/M+IRWLTECAwEAAaNTMFEwHQYDVR0OBBYE
FNxhaGwf5ePPhzK7yOAKD3VF6wm2MB8GA1UdIwQYMBaAFNxhaGwf5ePPhzK7yOAK
D3VF6wm2MA8GA1UdEwEB/wQFMAMBAf8wDQYJKoZIhvcNAQELBQADggEBAAoeJCAX
IDCFoAaZoQ1niI6Ac/cds8G8It0UCcFGSg+HrZ0YujJxWIruRCUG60Q2OAbEvn0+
uRpTm+4tV1Wt92WFeuRyqkomozx0g4CyfsxGX/x8mLhKPFK/7K9iTXM4/t+xQC4f
J+iRmPVsMKQ8YsHYiWVhlOMH9XJQiqERCB2kOKJCH6xkaF2k0GbM2sGgbS7Z6lrd
fsFTOIVx0VxLVsZnWX3byE9ghnDR5jn18u30Cpb/R/ShxNUGIHqRa4DkM5la6uZX
W1fpSW11JBSUv4WnOO0C2rlIu7UJWOROqZZ0OsybPRGGwagcyff2qVRuI2XFvAMk
OzBrmpfHEhF6NDU=
-----END CERTIFICATE-----
)%";


// '_filename' is a directory based on the path of the executable
MySqlConnectionPool::MySqlConnectionPool(const std::string& _filename, asio::io_context& _ioContext, int32 _poolSize):
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

MySqlConnectionPool::~MySqlConnectionPool()
{
    CleanupConnectionPool();
}

bool MySqlConnectionPool::CreateConnectionPool(int32 _poolCount)
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


mysql::tcp_connection* MySqlConnectionPool::CreateConnection()
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


mysql::tcp_connection* MySqlConnectionPool::GetPooledConnection()
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

std::vector<std::string> MySqlConnectionPool::ReadConfig(const std::string& filename)
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

void MySqlConnectionPool::ReturnConnection(mysql::tcp_connection* conn)
{
    m_connectionPool.push(conn);
    m_poolAvailable.fetch_add(1);
    m_poolBorrowed.fetch_sub(1);
}

void MySqlConnectionPool::CleanupConnectionPool()
{
    mysql::tcp_connection* conn;
    while (m_connectionPool.pop(conn))
    {
        conn->close();
        std::cout << "DB Connection closed" << std::endl;
        delete conn;
    }
}

#if defined(DB_TEST_MODE)
bool MySqlConnectionPool::TestConnect(mysql::tcp_connection* conn)
{
    // test for user table.
    const char* sql = "SELECT * from users";
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

bool MySqlConnectionPool::TestConnectionPool()
{
    std::atomic<int64_t> count;
    auto lambda = [this,&count]()
    {
        while (count < 1000)
        {
            auto conn = GetPooledConnection();
            std::string sql = std::format("SELECT * from {}",m_testTableName);
            mysql::results result;
            conn->execute(sql, result);

            // for (const auto& meta : result.meta())
            //     std::cout << meta.column_name() << '\t';
            //
            // for (auto row : result.rows())
            // {
            //     auto columns = row.size();
            //     for (int i = 0; i < columns; i++)
            //         std::cout << row.at(i) << "\t";
            //     std::cout << '\n';
            // }
            // std::cout.flush();
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
#endif