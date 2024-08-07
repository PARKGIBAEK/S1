#include <filesystem>
#include <boost/asio/spawn.hpp>
#include "LibConfig.h" // 라이브러리 링킹을 위한 코드
#include "Core/GlobalInitializer.h" // 가장 먼저 포함 시켜야 전역 객체 초기화가 순서 보장됨
#include "DB/ConnectionTest.h"
#include "DB/MySqlConnectionPool.h"
#include "DB/ORMTest.h"
#include "DB/ORM/auth_key_orm.hpp"
#include "DB/ORM/item_accessory_orm.hpp"
#include "DB/ORM/user_test_orm.hpp"
#include "Thread/ThreadManager.h"

using namespace ServerCore;
using namespace DB;

std::shared_ptr<MySqlConnectionPool> dbConnectionPool;
int main()
{
    std::cout << "GameServer TEST\n";
    try
    {
        boost::asio::io_context ioContext;
        // Create a work object to keep io_context running
        std::unique_ptr<boost::asio::io_context::work> work = std::make_unique<boost::asio::io_context::work>(ioContext);
        // work.reset();
        // Create a connection pool
        dbConnectionPool = std::make_shared<MySqlConnectionPool>("..\\..\\..\\DB\\config.txt", ioContext, 100);


    }
    catch
    (boost::mysql::error_code& ec)
    {
        std::cout << ec.what();
    }
    catch
    (std::exception& ex)
    {
        std::cout << ex.what();
    }
}
