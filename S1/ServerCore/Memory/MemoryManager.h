#pragma once
#include <vector>
#include <memory>
#include "Core/Types.h"
#include "Memory/PoolAllocator.h"

namespace ServerCore
{
class MemoryPool;

class MemoryManager
{
    enum
    {
        /*	0~1024 byte까지 32byte단위,
            1025~2048 byte까지 128 btye단위,
            2049~4096 byte까지 256 byte단위로 할당*/
        POOL_COUNT = (1024 / 32) + (1024 / 128) + (2048 / 256),
        MAX_ALLOC_SIZE = 4096,
    };

public:
    MemoryManager();
    ~MemoryManager();

    void* Allocate(int32 size);
    void Release(void* ptr);

private:
    std::vector<MemoryPool*> pools; //할당된 모든 메모리를 해제하기 위해 메모리 참조를 모두 보관

    // 할당할 메모리 크기에 맞는 메모리 풀을 빠르게 찾기 위한 테이블(생성자 참고)
    MemoryPool* poolTable[MAX_ALLOC_SIZE + 1];
};

#define USE_POOL_ALLOCATOR /* If you want to use regular memory allocation, you can annotate this macro */


#ifdef USE_POOL_ALLOCATOR
template <typename Type, typename... Args>
Type* XNew(Args&&... _args)
{
    Type* memory = static_cast<Type*>(PoolAllocator::AllocateMemory(sizeof(Type)));
    new(memory) Type(std::forward<Args>(_args)...);
    return memory;
}

template <typename Type>
void XDelete(Type* _obj)
{
    // 소멸자 호출 후 메모리 풀에 반납
    _obj->~Type();
    PoolAllocator::ReleaseMemory(_obj);
}


template <typename Type, typename... Args>
std::shared_ptr<Type> MakeShared(Args&&... _args)
{
    // shared_ptr로 반환해 주기
    return std::shared_ptr<Type>(
         XNew<Type>(std::forward<Args>(_args)...),
         XDelete<Type>
     );

     // return std::make_shared<Type>( XNew<Type>(std::forward<Args>(_args)...), XDelete<Type> ); // 컴파일 실패
}

#else

template<typename Type, typename... Args>
Type* XNew(Args&&... _args)
{
    return new Type(std::forward<Args>(_args)...);
}

template<typename Type>
void XDelete(Type* _obj)
{// 소멸자 호출 후 메모리 풀에 반납
    _obj->~Type();
    delete _obj;
}

template<typename Type, typename... Args>
std::shared_ptr<Type> MakeShared(Args&&... args)
{
    return std::shared_ptr<Type>(std::forward<Args>(args)...);
}

#endif
}
