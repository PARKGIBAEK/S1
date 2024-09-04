#include "pch.h"
#include "JobScheduler.h"
#include "Job/Job.h"
#include "Job/JobData.h"
#include "Job/JobQueue.h"
#include "Util/Time.h"
#include "Memory/ObjectPool.h"


namespace ServerCore
{
void JobScheduler::ScheduleJobAfterTick(const uint64 _tick, std::weak_ptr<JobQueue> _owner, std::shared_ptr<Job> _job)
{
    const uint64 executeTick = Time::GetTickCount64() + _tick;
    JobData* jobData = ObjectPool<JobData>::Pop(_owner, _job);

    WRITE_LOCK;

    m_scheduledJobs.emplace(ScheduledJob{executeTick, jobData});
}

void JobScheduler::EnqueueReadyJobs(const uint64 _now)
{
    /* acquire atomic lock (only one thread can pass through at a time) */
    if (m_isDistributing.exchange(true) == true)
        return;

    Vector<ScheduledJob> scheduledJobs;

    // atomic lock이 있어서 WRITE_LOCK이 필요 없는 것 같아보여서 주석 처리함
    // {
    //     WRITE_LOCK;

        // Fetching 'ScheduledJob's from the queue that have exceeded their scheduled time
        while (!m_scheduledJobs.empty())
        {
            const ScheduledJob& scheduledJob = m_scheduledJobs.top();
            if (_now < scheduledJob.m_scheduledTime)
                break;

            scheduledJobs.push_back(scheduledJob);
            m_scheduledJobs.pop();
        }

    // }

    // Push the Jobs to its 'onwerJobQueue' if it is valid
    for (ScheduledJob& scheduledJob : scheduledJobs)
    {
        if (std::shared_ptr<JobQueue> ownerJobQueue = scheduledJob.m_jobData->m_owner.lock())
            ownerJobQueue->Push(scheduledJob.m_jobData->m_job, true);

        // Return the object(ScheduledJob) to the pool
        ObjectPool<JobData>::Push(scheduledJob.m_jobData);
    }

    /* release atomic lock*/
    m_isDistributing.store(false);
}

void JobScheduler::Clear()
{
    WRITE_LOCK;

    while (m_scheduledJobs.empty() == false)
    {
        const ScheduledJob& scheduledJob = m_scheduledJobs.top();
        ObjectPool<JobData>::Push(scheduledJob.m_jobData);
        m_scheduledJobs.pop();
    }
}
}
