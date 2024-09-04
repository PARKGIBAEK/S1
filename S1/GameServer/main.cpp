#include "pch.h" // 라이브러리 링킹을 위한 코드
#include "Core/GlobalInitializer.h" // 가장 먼저 포함 시켜야 전역 객체 초기화가 순서 보장됨
#include "Memory/MemoryManager.h"
#include "DB/MySqlConnectionPool.h"
#include "DB/ORM/item_accessory_orm.hpp"
#include "Network/NetHelper.h"
#include "Core/CoreTLS.h"
#include "Network/PacketHandler.h"
#include "Thread/ThreadManager.h"
#include "Util/Time.h"
#include "Core/BoostTypes.h"
#include "ServerService.h"
#include "ClientSession.h"
#include "Job/GlobalJobQueue.h"

using namespace ServerCore;
using namespace GameServer;
using namespace DB;
using namespace std::chrono_literals;
constexpr int WORKER_TICK = 64;

void DoWorkerJob(std::shared_ptr<IoContext> ioContext)
{
    while (true)
    {
        tls_EndTickCount = Time::GetTickCount64() + WORKER_TICK;

        // Handle network I/O -> Handle ingame logic by Packethandler

        // Processing incoming I/O Jobs in the ioContext
        ioContext->run_for(10ms);

        // Processing scheduled jobs
        ThreadManager::CheckJobScheduler();

        // Distributing Jobs from the global queue
        g_GlobalJobQueue->DoDistributedProcessingFromGlobalJobQueue();
    }
}


int main()
{
    GlobalInitializer::Init();
    PacketHandler::Init();

    auto ioContext = MakeShared<IoContext>();
    boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::tcp::v4(), 8080);
    boost::asio::ip::tcp::acceptor acceptor(*ioContext, endpoint);
    auto ep = NetHelper::CreateAnyEndpoint(8000);
    auto gameServerService = MakeShared<ServerService<ClientSession>>(
        ep,
        ioContext,
        2
    );
    ASSERT_CRASH(gameServerService->Start());

    for (int i = 0; i < std::thread::hardware_concurrency() - 1; i++)
        g_ThreadManager->Launch([=]()
        {
            DoWorkerJob(ioContext);
        });

    DoWorkerJob(ioContext);
    g_ThreadManager->JoinAll();
}
