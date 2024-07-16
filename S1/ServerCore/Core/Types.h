#pragma once
#include <mutex>
#include <atomic>

namespace ServerCore
{
using BYTE = unsigned char;
using int8 = std::int8_t;
using int16 = std::int16_t;
using int32 = std::int32_t;
using int64 = std::int64_t;
using uint8 = std::uint8_t;
using uint16 = std::uint16_t;
using uint32 = std::uint32_t;
using uint64 = std::uint64_t;
using WCHAR = wchar_t;
template <typename T>
using Atomic = std::atomic<T>;
using Mutex = std::mutex;
using CondVar = std::condition_variable;
using UniqueLock = std::unique_lock<std::mutex>;
using LockGuard = std::lock_guard<std::mutex>;
constexpr uint64 UINF = static_cast<uint64>(-1);
constexpr int64 INF = static_cast<uint64>(-1) >> 1;


// aligned size by architecture
#if defined(_WIN64) || defined(__x86_64__) || defined(__ppc64__) || defined(__LP64__) || defined(_LP64)
#define LOCK_FREE_QUEUE_NODE_ALIGNMENT_VALUE 8
#elif defined(_WIN32) || defined(__i386__) || defined(__ppc__) || defined(__ILP32__)
#define LOCK_FREE_QUEUE_NODE_ALIGNMENT_VALUE 4
#else
#define LOCK_FREE_QUEUE_NODE_ALIGNMENT_VALUE 0 // Unknown alignment
#endif

enum class MEMORY_ALIGNMENT
{
    FOR_MEMORY_POOL = LOCK_FREE_QUEUE_NODE_ALIGNMENT_VALUE
};


enum class ALLOCATION
{
    DEFAULT_RECV_BUFFER_SIZE = 0x1000
};


/*	Size Checker	*/
#define size16(val)		static_cast<int16>(sizeof(val))
#define size32(val)		static_cast<int32>(sizeof(val))
#define len16(arr)		static_cast<int16>(sizeof(arr)/sizeof((arr)[0]))
#define len32(arr)		static_cast<int32>(sizeof(arr)/sizeof((arr)[0]))

//#define _STOMP_ALLOCATOR
}
