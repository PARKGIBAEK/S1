#include "pch.h"
#include "PoolAllocator.h"

#include "Core/GlobalInitializer.h"
#include "Memory/MemoryManager.h"



namespace ServerCore
{
void* PoolAllocator::AllocateMemory(int32 _size)
{
    return g_MemoryManager->Allocate(_size);
}

void PoolAllocator::ReleaseMemory(void* _ptr)
{
    g_MemoryManager->Release(_ptr);
}
}
