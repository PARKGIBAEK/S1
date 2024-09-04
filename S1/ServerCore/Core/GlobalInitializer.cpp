#include "pch.h"
#include "GlobalInitializer.h"
#include "Thread/DeadLockProfiler.h"
#include "Thread/ThreadManager.h"
#include "Memory/MemoryManager.h"
#include "Network/SendBufferManager.h"
#include "Job/GlobalJobQueue.h"
#include "Job/JobScheduler.h"
// #include "DB/DBConnectionPool.h"
#include "Log/ConsoleLog.h"

namespace ServerCore
{

DeadLockProfiler* g_DeadLockProfiler = nullptr;
ThreadManager* g_ThreadManager = nullptr;
MemoryManager* g_MemoryManager = nullptr;
SendBufferManager* g_SendBufferManager = nullptr;
GlobalJobQueue* g_GlobalJobQueue = nullptr;
JobScheduler* g_JobScheduler = nullptr;
ConsoleLog* g_ConsoleLogger = nullptr;

std::atomic<bool> GlobalInitializer::m_IsInitialized = false;

GlobalInitializer::GlobalInitializer()
{
	DEBUG_LOG("Initializing Core global variables...");

	g_ConsoleLogger = new ConsoleLog();
	DEBUG_LOG("[ GConsoleLogger ]  -  Initialized");

	g_DeadLockProfiler = new DeadLockProfiler();
	DEBUG_LOG("[ GDeadLockProfiler ]  -  Initialized");

	g_ThreadManager = new ThreadManager();
	DEBUG_LOG("[ GThreadManager ]  -  Initialized");

	g_MemoryManager = new MemoryManager();
	DEBUG_LOG("[ GMemoryManager ]  -  Initialized");

	g_SendBufferManager = new SendBufferManager();
	DEBUG_LOG("[ GSendBufferManager ]  -  Initialized");

	g_GlobalJobQueue = new GlobalJobQueue();
	DEBUG_LOG("[ GGlobalQueue ]  -  Initialized");

	g_JobScheduler = new JobScheduler();
	DEBUG_LOG("[ GJobTimer ]  -  Initialized");

	DEBUG_LOG("[ GDeadLockProfiler ]  -  Initialized");

	DEBUG_LOG("Completed initialization of Core global variables");
}

GlobalInitializer::~GlobalInitializer()
{
	delete g_ThreadManager;
	g_ThreadManager = nullptr;
	delete g_GlobalJobQueue;
	g_GlobalJobQueue = nullptr;
	delete g_SendBufferManager;
	g_SendBufferManager = nullptr;
	delete g_JobScheduler;
	g_JobScheduler = nullptr;
	delete g_DeadLockProfiler;
	g_DeadLockProfiler = nullptr;

	delete g_ConsoleLogger;
	g_ConsoleLogger = nullptr;

	delete g_MemoryManager; // 풀링 때문에 마지막에 소멸시켜야 함(먼저 소멸시키면 SendBuffer 같은 풀링 객체 소멸자에서 Heap 관련 Crash)
	g_MemoryManager = nullptr;

}
}
