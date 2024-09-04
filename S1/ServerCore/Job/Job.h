#pragma once
#include <functional>
#include <memory>



namespace ServerCore
{


using CallbackType = std::function<void()>;


class Job
{
public:
	Job(CallbackType&& callback) : m_callback(std::move(callback))
	{
	}

	template<typename T, typename Ret, typename... Args>
	Job(std::shared_ptr<T> owner, Ret(T::* memFunc)(Args...), Args&&... args)
	{
		m_callback = [owner, memFunc, args...]()
		{
			(owner.get()->*memFunc)(args...); // owner의 함수 포인터
		};
	}

	void Execute()
	{
		m_callback();
	}

private:
	CallbackType m_callback;
};
}
