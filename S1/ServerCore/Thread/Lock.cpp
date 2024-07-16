#include "Lock.h"
#include <thread>
#include "Core/GlobalInitializer.h"
#include "Core/CoreMacro.h"
#include "Core/CoreTLS.h"
#include "Thread/DeadLockProfiler.h"
#include "Util/Time.h"

namespace ServerCore
{
Lock::Lock(): lockFlag(EMPTY_FLAG), writeCount(0)
{
}

void Lock::WriteLock(const char* name)
{
#if _DEBUG
    if (g_DeadLockProfiler)
        g_DeadLockProfiler->PushLock(name);
#endif

    const uint32 lockThreadId = (lockFlag.load() & WRITE_THREAD_MASK) >> 16;
    if (tls_ThreadId == lockThreadId)
    {
        // 동일한 쓰레드가 WriteLock을 잡고 있는 경우(재귀로 Lock을 잡은 경우)
        writeCount++;
        return;
    }

    // WriteLock을 잡기 위한 경합
    const uint64 beginTick = Time::GetTickCount64();
    const uint32 desired = ((tls_ThreadId << 16) & WRITE_THREAD_MASK);
    while (true)
    {
        for (uint32 spinCount = 0; spinCount < MAX_SPIN_COUNT; spinCount++)
        {
            uint32 expected = EMPTY_FLAG;
            if (lockFlag.compare_exchange_strong(OUT expected, desired))
            {
                writeCount++; // WriteLock을 잡은 쓰레드 갯수 1 증가
                return;
            }
        }

        if (Time::GetTickCount64() - beginTick >= ACQUIRE_TIMEOUT_TICK)
            CRASH("LOCK_TIMEOUT");

        std::this_thread::yield();
    }
}

void Lock::WriteUnlock(const char* name)
{
#if _DEBUG
    if (g_DeadLockProfiler)
        g_DeadLockProfiler->PopLock(name);
#endif

    // WriteLock이 잡혀 있는 상태에서 ReadLock이 함께 잡혀있다면 로직 오류
    if ((lockFlag.load() & READ_COUNT_MASK) != 0)
        CRASH("INVALID_UNLOCK_ORDER");

    const int32 lockCount = --writeCount;
    if (lockCount == 0)
        lockFlag.store(EMPTY_FLAG);
}

void Lock::ReadLock(const char* name)
{
#if _DEBUG
    if (g_DeadLockProfiler)
        g_DeadLockProfiler->PushLock(name);
#endif


    const uint32 lockThreadId = (lockFlag.load() & WRITE_THREAD_MASK) >> 16;
    if (tls_ThreadId == lockThreadId)
    {
        // WriteLock을 잡고있는 쓰레드가 ReadLock도 잡으려고 하는 경우
        lockFlag.fetch_add(1); // ReadLock을 잡은 스레드 갯수 증가
        return;
    }

    // 아무도 소유하고 있지 않을 때 경합해서 공유 카운트를 올린다.
    const uint64 beginTick = Time::GetTickCount64();
    while (true)
    {
        for (uint32 spinCount = 0; spinCount < MAX_SPIN_COUNT; spinCount++)
        {
            uint32 expected = (lockFlag.load() & READ_COUNT_MASK);
            if (lockFlag.compare_exchange_strong(OUT expected, expected + 1))
                return;
        }

        if (Time::GetTickCount64() - beginTick >= ACQUIRE_TIMEOUT_TICK)
            CRASH("LOCK_TIMEOUT");

        std::this_thread::yield();
    }
}

void Lock::ReadUnlock(const char* name)
{
#if _DEBUG
    if (g_DeadLockProfiler)
        g_DeadLockProfiler->PopLock(name);
#endif

    if ((lockFlag.fetch_sub(1) & READ_COUNT_MASK) == 0)
        CRASH("MULTIPLE_UNLOCK");
}

ReadLockGuard::ReadLockGuard(Lock& _lock, const char* _name)
    : lock(_lock), name(_name)
{
    lock.ReadLock(_name);
}

WriteLockGuard::WriteLockGuard(Lock& _lock, const char* _name)

    : lock(_lock), name(_name) { _lock.WriteLock(_name); }

WriteLockGuard::~WriteLockGuard()
{
    lock.WriteUnlock(name);
}
}