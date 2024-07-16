#include "PoolAllocator.h"

#include "Core/GlobalInitializer.h"
#include "Memory/MemoryManager.h"



namespace ServerCore
{
void* PoolAllocator::AllocateMemory(int32 size)
{
    return g_MemoryManager->Allocate(size);
}

void PoolAllocator::ReleaseMemory(void* ptr)
{
    g_MemoryManager->Release(ptr);
}
}