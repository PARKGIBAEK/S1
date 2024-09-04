#include "pch.h"
#include "GlobalJobQueue.h"

#include "Core/CoreTLS.h"
#include "Job/JobQueue.h"
#include "Util/Time.h"

namespace ServerCore
{
void GlobalJobQueue::Push(std::shared_ptr<JobQueue> _jobQueue)
{
	m_jobQueues.Push(_jobQueue);
}

std::shared_ptr<JobQueue> GlobalJobQueue::Pop()
{
	return m_jobQueues.Pop();
}

void GlobalJobQueue::DoDistributedProcessingFromGlobalJobQueue()
{
    while (true)
    {
        uint64 now = Time::GetTickCount64();
        if (now > tls_EndTickCount)
            break;

        std::shared_ptr<JobQueue> jobQueue = g_GlobalJobQueue->Pop();
        if (jobQueue == nullptr)
            break;

        jobQueue->Execute();
    }
}
}
