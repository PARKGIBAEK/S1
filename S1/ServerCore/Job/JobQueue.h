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

	/*Ret(T::*memFunc)(Args...)�� Template �������� �Լ� �����͸� ������ ���̴�.
	���ø����� T�� ��� �Լ��� ���� �Լ� �����͸� �ǹ̴�.
	��, ��ȯŸ���� Ret�̸�, ���� ���� Args...�� �Ű������� ���� TŬ������ ��� �Լ� �����͸� ��Ī�Ѵ�.*/
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
	/* _jobs�� job�� �ִ´�. ��, �ٻڸ�
	pushOnly == false : Jobó������ ����*/

	void Push(std::shared_ptr<Job> _job, bool _pushOnly = false);
	void Execute();

protected:
	LockQueue<std::shared_ptr<Job>> _jobs;
	std::atomic<int32> _jobCount;
};
}
