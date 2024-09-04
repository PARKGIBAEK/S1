#pragma once
#include <memory>
#include "Core/Types.h"
#include "Memory/ObjectPool.h"
#include "Job/JobScheduler.h"
#include "Job/Job.h"
#include "Core/GlobalInitializer.h"
#include "Util/LockQueue.h"


namespace ServerCore
{

class JobQueue : public std::enable_shared_from_this<JobQueue>
{
public:
	virtual ~JobQueue() = default;
	void DoAsync(CallbackType&& _callback)
	{
		Push(ObjectPool<Job>::MakeShared(std::move(_callback)));
	}

	// `Ret(T::*memFunc)(Args...)` is a template syntax for a function pointer.
	// It refers to a member function pointer of class `T`
	// that returns `Ret` and takes parameters of types `Args...`.
	template <typename T, typename Ret, typename... Args>
	void DoAsync(Ret(T::* _memFunc)(Args...), Args... _args)
	{
		std::shared_ptr<T> owner = std::static_pointer_cast<T>(shared_from_this());
		Push(ObjectPool<Job>::MakeShared(owner, _memFunc, std::forward<Args>(_args)...));
	}

	void ScheduleJob(const uint64 tickAfter, CallbackType&& _callback)
	{
		std::shared_ptr<Job> job = ObjectPool<Job>::MakeShared(std::move(_callback));
		g_JobScheduler->ScheduleJobAfterTick(tickAfter, shared_from_this(), job);
	}

	template <typename T, typename Ret, typename... Args>
	void ScheduleJob(const uint64 _tickAfter, Ret(T::* _memFunc)(Args...), Args... _args)
	{
		std::shared_ptr<T> owner = std::static_pointer_cast<T>(shared_from_this());
		std::shared_ptr<Job> job = ObjectPool<Job>::MakeShared(owner, _memFunc, std::forward<Args>(_args)...);
		g_JobScheduler->ScheduleJobAfterTick(_tickAfter, shared_from_this(), job);
	}

	void ClearJobs() { m_jobs.Clear(); }

public:
	// If 'pushOnly' is 'false', execute the _job as well.
	void Push(std::shared_ptr<Job> _job, bool _pushOnly = false);
    // When the 'Execute' function returns, always set 'tls_CurrentJobQueue' to 'nullptr'.
	void Execute();

protected:
	LockQueue<std::shared_ptr<Job>> m_jobs;
	std::atomic<int32> m_jobCount;
};
}
