#pragma once
#include "Core/Types.h"



namespace ServerCore
{
class PoolAllocator
{
public:
    static void*	AllocateMemory(int32 _size);
    static void		ReleaseMemory(void* _ptr);
};
}
