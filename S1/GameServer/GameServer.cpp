#include <filesystem>
#include <boost/asio/spawn.hpp>
#include "LibConfig.h" // 라이브러리 링킹을 위한 코드
#include "Core/GlobalInitializer.h" // 가장 먼저 포함 시켜야 전역 객체 초기화가 순서 보장됨
#include "DB/ConnectionTest.h"
#include "DB/MySqlConnectionPool.h"

#include "DB/ORMTest.h"
#include "DB/ORM/user_inventory.hpp"

using namespace ServerCore;
using namespace DB;

void PrintResult(const mysql::results& result)
{
    // for debugging
    if (!result.rows().empty())
    {
        auto sz = result.size();
        for (int i = 0; i < result.size(); i++)
        {
            for (const mysql::row_view& row : result.at(i).rows())
            {
                auto new_id = row[0].as_int64();
                auto new_user_character_id = row[1].as_int64();
                auto new_item_id = row[2].as_int64();
                auto new_item_quantity = row[3].as_int64();
                auto created_at = row[4].as_datetime();
                auto updated_at = row[5].as_datetime();
                std::cout << new_id << ", " << new_user_character_id << ", " << new_item_id << ", " <<
                    new_item_quantity << ", " << created_at << ", " << updated_at << std::endl;
            }
        }
    }
    else
    {
        std::cout << "No result set" << std::endl;
    }
}

int main()
{
    std::cout << "TEST GameServer\n";
    try
    {
        boost::asio::io_context ioContext;
        // DB::ConnectionTest connectionTest("..\\..\\..\\DB\\config.txt", ioContext, 100);
        // connectionTest.TestConnectionPool();
        MySqlConnectionPool mysqlConnectionPool("..\\..\\..\\DB\\config.txt", ioContext, 100);
        // auto conn = mysqlConnectionPool.GetPooledConnection();
        // ORMTest test(&ioContext,&mysqlConnectionPool);
        // test.StartTest();
        ORM::user_inventory_orm::sp_insert(mysqlConnectionPool.GetPooledConnection(),3,10100002,2,mysql::datetime::now());
        auto result = ORM::user_inventory_orm::sp_select_all_by_user_character_id(mysqlConnectionPool.GetPooledConnection(),3);
        PrintResult(result);
    }
    catch (boost::mysql::error_code& ec)
    {
        std::cout << ec.what();
    }
    catch (std::exception& ex)
    {
        std::cout << ex.what();
    }
}
