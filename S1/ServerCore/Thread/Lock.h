#pragma once
#include <atomic>
#include "Core/Types.h"


namespace ServerCore
{
//////////////////////
//   RW SpinLock  //
/////////////////////

class Lock
{
    /*--------------------------------------------

    * 32 bit flag usage  :  [WWWWWWWW][WWWWWWWW][RRRRRRRR][RRRRRRRR]
      W : WriteFlag (Exclusive-lock Owner ThreadId)
      R : ReadFlag (Shared Lock Count)

    ---------------------------------------------*/
    enum LOCK_FLAG : uint32
    {
        ACQUIRE_TIMEOUT_TICK = 10000,
        MAX_SPIN_COUNT = 5000,
        WRITE_THREAD_MASK = 0xFFFF'0000,
        READ_COUNT_MASK = 0x0000'FFFF,
        EMPTY_FLAG = 0x0000'0000
    };

public:
    Lock() :m_lockFlag(LOCK_FLAG::EMPTY_FLAG), m_writeCount(0) {}
    void WriteLock(const char* m_name);
    void WriteUnlock(const char* m_name);
    void ReadLock(const char* m_name);
    void ReadUnlock(const char* m_name);

private:
    std::atomic<uint32> m_lockFlag;
    uint16 m_writeCount;
};


//////////////////////
//    LockGuards    //
//////////////////////

class ReadLockGuard
{
public:
    ReadLockGuard(Lock& _lock, const char* _name);

    ~ReadLockGuard();

private:
    Lock& m_lock;
    const char* m_name;
};


class WriteLockGuard
{
public:
    WriteLockGuard(Lock& _lock, const char* _name);
    ~WriteLockGuard();

private:
    Lock& m_lock;
    const char* m_name;
};
}
