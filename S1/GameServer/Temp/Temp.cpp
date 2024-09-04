#include "pch.h"
#include "Temp.h"

#include "ServerService.h"
#include "Core/BoostTypes.h"
#include "DB/MySqlConnectionPool.h"
#include "DB/ORM/user_inventory_orm.hpp"

namespace Temp
{
using namespace ServerCore;
using namespace GameServer;
using namespace DB;


void Temp::KeepIoContextRun(std::shared_ptr<ServerCore::IoContext> _ioContext)
{
    //Create a work object to keep io_context running
    std::unique_ptr<IoContext::work> work = std::make_unique<IoContext::work>(*_ioContext);
}

void Temp::DbTest()
{
    try
    {
        auto ioContext = std::make_shared<IoContext>();
        // Create a work object to keep io_context running
        std::unique_ptr<IoContext::work> work = std::make_unique<
            IoContext::work>(*ioContext);
        // work.reset(); // reset io_context

        // Create a connection pool
        std::shared_ptr<DB::MySqlConnectionPool> dbConnectionPool = std::make_shared<MySqlConnectionPool>(
            "..\\..\\..\\DB\\config.txt", *ioContext, 100);

        mysql::tcp_connection* pooledConnection = dbConnectionPool->GetPooledConnection();

        int result = ORM_test::user_inventory_orm::insert_into_user_inventory_character_id_N_item_id(
            pooledConnection, 1, 10011001);

        if (result != -1)
        {
            std::cout << "insertion succeeded" << std::endl;;
        }

        dbConnectionPool->ReturnConnection(pooledConnection);
    }
    catch
    (boost::mysql::error_code& ec)
    {
        std::cout << ec.what();
    }
    catch
    (std::runtime_error& ex)
    {
        std::cout << ex.what();
    }
}
}
