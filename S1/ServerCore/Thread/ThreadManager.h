#pragma once
#include <thread>
#include <functional>
#include <mutex>
#include <vector>

namespace ServerCore
{

class ThreadManager
{
public:

	ThreadManager();
	~ThreadManager();
	// 쓰레드 컨테이너(vector<thread>	threads)에 쓰레드를 추가하고,
	// 동시에 해당 쓰레에서 함수객체 callback을 수행한다
	void Launch(const std::function<void(void)>& _callback);
	// 쓰레드 컨테이너(vector<thread>	threads)에 있는 모든 쓰레드들에 대하여 join을 수행하고,
	// join이 반환하면 쓰레드 컨테이너를 비운다
	void JoinAll();
	// static void DoGlobalQueueWork(); // GlobalJobQueue로 이전
	static void CheckJobScheduler();
private:
	static void InitTLS();
	static void DestroyTLS();


private:
	std::mutex m_MtxLock;
	std::vector<std::thread> m_Threads;
};
}
