#include <filesystem>
#include <memory>
#include <boost/asio/co_spawn.hpp>
#include <boost/asio/spawn.hpp>
#include <boost/mysql/static_results.hpp>
#include "LibConfig.h" // 라이브러리 링킹을 위한 코드
#include "Core/GlobalInitializer.h" // 가장 먼저 포함 시켜야 전역 객체 초기화가 순서 보장됨
#include "DB/ConnectionTest.h"
#include "DB/MySqlConnectionPool.h"

using namespace ServerCore;

int main()
{
	std::cout << "TEST GameServer\n";
	try
	{
		boost::asio::io_context ioContext;
		// DB::ConnectionTest connectionTest("..\\..\\..\\DB\\config.txt", ioContext, 100);
		// connectionTest.TestConnectionPool();
		MySqlConnectionPool mysqlConnectionPool("..\\..\\..\\DB\\config.txt", ioContext, 100);
		auto conn = mysqlConnectionPool.GetPooledConnection();
	}
	catch (std::exception ex)
	{
		std::cout << ex.what();
	}
}