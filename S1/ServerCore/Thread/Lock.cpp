#include "pch.h"
#include "Lock.h"
#include <thread>
#include "Core/GlobalInitializer.h"
#include "Core/CoreMacro.h"
#include "Core/CoreTLS.h"
#include "Thread/DeadLockProfiler.h"
#include "Util/Time.h"

namespace ServerCore
{

void Lock::WriteLock(const char* m_name)
{
#if _DEBUG
    if (g_DeadLockProfiler)
        g_DeadLockProfiler->PushLock(m_name);
#endif
    const uint32 lockThreadId = (m_lockFlag.load() & WRITE_THREAD_MASK) >> 16;
    if (tls_ThreadId == lockThreadId)
    {
        // 동일한 쓰레드가 WriteLock을 잡고 있는 경우(재귀로 Lock을 잡은 경우)
        m_writeCount++;
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
            if (m_lockFlag.compare_exchange_strong(OUT expected, desired))
            {
                m_writeCount++; // WriteLock을 잡은 쓰레드 갯수 1 증가
                return;
            }
        }

        const auto now = Time::GetTickCount64();
        if (now - beginTick >= ACQUIRE_TIMEOUT_TICK)
            CRASH("LOCK_TIMEOUT")

            std::this_thread::yield();
    }
}

void Lock::WriteUnlock(const char* m_name)
{
#if _DEBUG
    if (g_DeadLockProfiler)
        g_DeadLockProfiler->PopLock(m_name);
#endif

    // WriteLock이 잡혀 있는 상태에서 ReadLock이 함께 잡혀있다면 로직 오류
    if ((m_lockFlag.load() & READ_COUNT_MASK) != 0)
        CRASH("INVALID_UNLOCK_ORDER")

        const int32 lockCount = --m_writeCount;
    if (lockCount == 0)
        m_lockFlag.store(EMPTY_FLAG);
}

void Lock::ReadLock(const char* m_name)
{
#if _DEBUG
    if (g_DeadLockProfiler)
        g_DeadLockProfiler->PushLock(m_name);
#endif


    const uint32 lockThreadId = (m_lockFlag.load() & WRITE_THREAD_MASK) >> 16;
    if (tls_ThreadId == lockThreadId)
    {
        // WriteLock을 잡고있는 쓰레드가 ReadLock도 잡으려고 하는 경우
        m_lockFlag.fetch_add(1); // ReadLock을 잡은 스레드 갯수 증가
        return;
    }

    // 아무도 소유하고 있지 않을 때 경합해서 공유 카운트를 올린다.
    const uint64 beginTick = Time::GetTickCount64();
    while (true)
    {
        for (uint32 spinCount = 0; spinCount < MAX_SPIN_COUNT; spinCount++)
        {
            uint32 expected = (m_lockFlag.load() & READ_COUNT_MASK);
            if (m_lockFlag.compare_exchange_strong(OUT expected, expected + 1))
                return;
        }
        const auto now = Time::GetTickCount64();
        if (now - beginTick >= ACQUIRE_TIMEOUT_TICK)
            CRASH("LOCK_TIMEOUT")

            std::this_thread::yield();
    }
}

void Lock::ReadUnlock(const char* m_name)
{
#if _DEBUG
    if (g_DeadLockProfiler)
        g_DeadLockProfiler->PopLock(m_name);
#endif

    if ((m_lockFlag.fetch_sub(1) & READ_COUNT_MASK) == 0)
        CRASH("MULTIPLE_UNLOCK")
}

ReadLockGuard::ReadLockGuard(Lock& _lock, const char* _name)
    : m_lock(_lock), m_name(_name)
{
    m_lock.ReadLock(_name);
}

ReadLockGuard::~ReadLockGuard()
{
    m_lock.ReadUnlock(m_name);
}


WriteLockGuard::WriteLockGuard(Lock& _lock, const char* _name)
    : m_lock(_lock), m_name(_name)
{
    _lock.WriteLock(_name);
}

WriteLockGuard::~WriteLockGuard()
{
    m_lock.WriteUnlock(m_name);
}

}
