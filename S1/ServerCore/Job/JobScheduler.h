#pragma once
#include <memory>
#include "Memory/Container.h"
#include "Core/CoreMacro.h"
#include "Core/Types.h"
#include "Job/ScheduledJob.h"



namespace ServerCore
{
class Job;
class JobQueue;
/*--------------
	JobTimer
---------------*/
/*
  전역 객체이며, ScheduledJob의 executeTick에 맞춰 Job을
  - ScheduledJob의 실행시각이 지났으면 실행될 수 있게 JobQueue에 넣어 주는 역할
*/
class JobScheduler
{
public:
    // Insert jobs into the `Priority_Queue` based on the `executeTick`.
	void			ScheduleJobAfterTick(uint64 _tick, std::weak_ptr<JobQueue> _owner, std::shared_ptr<Job> _job);
    // If the job's execution time has passed, send it to the owner(JobQueue).
	void			EnqueueReadyJobs(uint64 _now);

	void			Clear();

private:
	DECLARE_SINGLE_LOCK;
	PriorityQueue<ScheduledJob>		m_scheduledJobs;
	std::atomic<bool>				m_isDistributing;
};
}
