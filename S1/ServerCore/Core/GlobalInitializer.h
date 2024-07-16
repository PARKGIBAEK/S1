#pragma once
#include <iostream>
#include <atomic>

namespace ServerCore
{
/* <sql.h>나 ,<sqlext.h>같은 ODBC API가
 * 크로스 플래폼 기반임에도 불구하고
 * 플래폼 버전에 따른 종속성을 보이고 있어서 임시로 제거해 둠
 * 관련 라이브러리는 DB~로 시작함
 * DBConnection
 */

class DeadLockProfiler;
class ThreadManager;
class MemoryManager;
class SendBufferManager;
class GlobalQueue;
class JobTimer;
class ConsoleLog;

extern DeadLockProfiler* g_DeadLockProfiler;
extern ThreadManager* g_ThreadManager;
extern MemoryManager* g_MemoryManager;
extern SendBufferManager* g_SendBufferManager;
extern GlobalQueue* g_GlobalQueue;
extern JobTimer* g_JobTimer;
extern ConsoleLog* g_ConsoleLogger;

class GlobalInitializer
{
public:
    static void Init()
    {
        static GlobalInitializer instance; // scoped static
        if (m_IsInitialized)
            std::cout << "CoreInitializer has already been initialized" << std::endl;
        else
        {
            m_IsInitialized.store(true);
            std::cout << "CoreInitializer is initialized" << std::endl;
        }
        instance.DummyMethod();
    }

private:
    GlobalInitializer();
    ~GlobalInitializer();

    static void DummyMethod()
    {
    }

    GlobalInitializer(const GlobalInitializer&) = delete;
    GlobalInitializer& operator=(const GlobalInitializer&) = delete;
    static std::atomic<bool> m_IsInitialized;
};
}
