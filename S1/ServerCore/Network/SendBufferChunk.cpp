#include "SendBufferChunk.h"
#include "Network/SendBuffer.h"
#include "Network/ConstSendBuffer.h"
#include "Core/CoreMacro.h"
#include "Memory/ObjectPool.h"


namespace ServerCore
{
SendBufferChunk::SendBufferChunk(): buffer(), isOpen(false), usedSize(0)
{
}

SendBufferChunk::~SendBufferChunk()
{
}

void SendBufferChunk::ResetBuffer()
{
    isOpen = false;
    usedSize = 0;
}

std::shared_ptr<SendBuffer> SendBufferChunk::Open(uint32 _allocSize)
{
    ASSERT_CRASH(_allocSize <= SEND_BUFFER_CHUNK_SIZE)
    ASSERT_CRASH(isOpen == false)

    if (_allocSize > FreeSize())
        return nullptr;

    isOpen = true;

    return ObjectPool<SendBuffer>::MakeShared(shared_from_this(), Buffer(), _allocSize);
}

std::shared_ptr<ConstSendBuffer> SendBufferChunk::OpenConst(uint32 _allocSize)
{
    ASSERT_CRASH(_allocSize <= SEND_BUFFER_CHUNK_SIZE)
    ASSERT_CRASH(isOpen == false)

    if (_allocSize > FreeSize())
        return nullptr;

    isOpen = true;

    return ObjectPool<ConstSendBuffer>::MakeShared(shared_from_this(), Buffer(), _allocSize);
}

void SendBufferChunk::Close(uint32 _writeSize)
{
    ASSERT_CRASH(isOpen == true);
    isOpen = false;
    usedSize += _writeSize;
}

bool SendBufferChunk::IsOpen() const
{
    return isOpen;
}

BYTE* SendBufferChunk::Buffer()
{
    return &buffer[usedSize];
}

uint32 SendBufferChunk::FreeSize()
{
    return static_cast<uint32>(buffer.size()) - usedSize;
}
}
