#include "ThreadManager.h"

#include "Core/CoreTLS.h"
#include "Core/GlobalInitializer.h"
#include "Job/GlobalQueue.h"
#include "Job/JobQueue.h"
#include "Job/JobTimer.h"
#include "Util/Time.h"
#include <atomic>


namespace ServerCore
{

ThreadManager::ThreadManager()
{
	// Main Thread
	InitTLS();
}

ThreadManager::~ThreadManager()
{
	JoinAll();
}

void ThreadManager::Launch(const std::function<void(void)>& _callback)
{
	LockGuard guard(m_MtxLock);

	m_Threads.push_back(std::thread([=]()
		{
			InitTLS();
			_callback();
			DestroyTLS();
		}));
}

void ThreadManager::JoinAll()
{
	for (std::thread& t : m_Threads)
	{
		if (t.joinable())
			t.join();
	}
	m_Threads.clear();
}

void ThreadManager::InitTLS()
{
	static std::atomic<uint32> SThreadId = 1;
	tls_ThreadId = SThreadId.fetch_add(1);
}

void ThreadManager::DestroyTLS()
{

}

void ThreadManager::DoGlobalQueueWork()
{
	while (true)
	{
		uint64 now = Time::GetTickCount64();
		if (now > tls_EndTickCount)
			break;

		std::shared_ptr<JobQueue> jobQueue = g_GlobalQueue->Pop();
		if (jobQueue == nullptr)
			break;

		jobQueue->Execute();
	}
}

void ThreadManager::CheckJobTimer()
{
	const uint64 now = Time::GetTickCount64();

	g_JobTimer->Distribute(now);
}
}