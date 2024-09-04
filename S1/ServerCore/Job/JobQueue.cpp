#include "pch.h"
#include "JobQueue.h"
#include "Core/CoreTLS.h"
#include "Job/GlobalJobQueue.h"
#include "Util/Time.h"


namespace ServerCore
{
void JobQueue::Push(std::shared_ptr<Job> _job, const bool _pushOnly)
{
    const int32 prevJobCount = m_jobCount.fetch_add(1);
    m_jobs.Push(_job); // WRITE_LOCK

    // The thread that inserts the first job is responsible for executing it.
    if (prevJobCount == 0)
    {
        /* If 'tls_CurrentJobQueue' is not nullptr, it means the current thread is handling another JobQueue.
        But this is a logical error because when the 'prevJobCount == 0' condition is met, it implies that the current thread is not handling any JobQueue.
        However, TLS (Thread-Local Storage) guarantees that race conditions do not occur, as each thread has its own instance of the TLS variable. Therefore, if 'tls_CurrentJobQueue' is not 'nullptr', it indicates that the code is missing an appropriate code line to set 'tls_CurrentJobQueue' to 'nullptr'.
        In short, after 'JobQueue::Execute()' has completed successfully, 'tls_CurrentJobQueue' should always be 'nullptr'.(Therefore, the code 'tls_CurrentJobQueue == nullptr' is virtually unnecessary)
        And if 'pushOnly' is 'true'(pushOnly == true), the job is not executed but instead pushed to the GlobalJobQueue, allowing another thread to pick it up.
         */

        if (tls_CurrentJobQueue == nullptr && _pushOnly == false)
        {
            Execute();
        }
        else
        {
            // Push the 'this(JobQueue)' to the GlobalJobQueue so that a thread with the capacity to execute the Job can pick it up.
            g_GlobalJobQueue->Push(shared_from_this());
        }
    }
}

void JobQueue::Execute()
{
    tls_CurrentJobQueue = this;

    while (true)
    {
        Vector<std::shared_ptr<Job>> jobs;
        m_jobs.PopAll(OUT jobs);

        const int32 jobCount = static_cast<int32>(jobs.size());
        for (int32 i = 0; i < jobCount; i++)
            jobs[i]->Execute();

        // Terminate if there are no jobs left except for the fetched jobs.
        if (m_jobCount.fetch_sub(jobCount) == jobCount)
        {
            tls_CurrentJobQueue = nullptr;
            return;
        }

        /* If there are still remaining jobs to process
          but the current thread has spent too much time on job processing,
          hand the jobs over to the GlobalJobQueue
          so that another thread can handle them.*/
        const uint64 now = Time::GetTickCount64();
        if (now >= tls_EndTickCount)
        {
            tls_CurrentJobQueue = nullptr;
            // Push the 'this(JobQueue)' to the GlobalJobQueue so that a thread with the capacity to execute the Job can pick it up.
            g_GlobalJobQueue->Push(shared_from_this());
            break;
        }
    }
}
}
