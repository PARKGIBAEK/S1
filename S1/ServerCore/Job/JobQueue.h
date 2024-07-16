#pragma once
#include <memory>
#include "Core/Types.h"
#include "Memory/ObjectPool.h"
#include "Job/JobTimer.h"
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

	/*Ret(T::*memFunc)(Args...)는 Template 문법으로 함수 포인터를 구현한 것이다.
	템플릿인자 T의 멤버 함수에 대한 함수 포인터를 의미다.
	즉, 반환타입이 Ret이며, 가변 인자 Args...를 매개변수로 갖는 T클래스의 멤버 함수 포인터를 지칭한다.*/
	template <typename T, typename Ret, typename... Args>
	void DoAsync(Ret(T::* _memFunc)(Args...), Args... _args)
	{
		std::shared_ptr<T> owner = std::static_pointer_cast<T>(shared_from_this());
		Push(ObjectPool<Job>::MakeShared(owner, _memFunc, std::forward<Args>(_args)...));
	}

	void DoTimer(const uint64 tickAfter, CallbackType&& _callback)
	{
		std::shared_ptr<Job> job = ObjectPool<Job>::MakeShared(std::move(_callback));
		g_JobTimer->Reserve(tickAfter, shared_from_this(), job);
	}

	template <typename T, typename Ret, typename... Args>
	void DoTimer(const uint64 _tickAfter, Ret(T::* _memFunc)(Args...), Args... _args)
	{
		std::shared_ptr<T> owner = std::static_pointer_cast<T>(shared_from_this());
		std::shared_ptr<Job> job = ObjectPool<Job>::MakeShared(owner, _memFunc, std::forward<Args>(_args)...);
		g_JobTimer->Reserve(_tickAfter, shared_from_this(), job);
	}

	void ClearJobs() { _jobs.Clear(); }

public:
	/* _jobs에 job을 넣는다. 단, 바쁘면
	pushOnly == false : Job처리까지 수행*/

	void Push(std::shared_ptr<Job> _job, bool _pushOnly = false);
	void Execute();

protected:
	LockQueue<std::shared_ptr<Job>> _jobs;
	std::atomic<int32> _jobCount;
};
}
