#include "pch.h"
#include "SendBufferChunk.h"
#include "Network/SendBuffer.h"
#include "Network/ConstSendBuffer.h"
#include "Core/CoreMacro.h"
#include "Memory/ObjectPool.h"


namespace ServerCore
{
SendBufferChunk::SendBufferChunk(): m_Buffer(), m_IsOpen(false), m_UsedSize(0)
{
}

SendBufferChunk::~SendBufferChunk()
{
}

void SendBufferChunk::ResetBuffer()
{
    m_IsOpen = false;
    m_UsedSize = 0;
}

std::shared_ptr<SendBuffer> SendBufferChunk::Open(uint32 _allocSize)
{
    ASSERT_CRASH(_allocSize <= SEND_BUFFER_CHUNK_SIZE)
    ASSERT_CRASH(m_IsOpen == false)

    if (_allocSize > FreeSize())
        return nullptr;

    m_IsOpen = true;

    return ObjectPool<SendBuffer>::MakeShared(shared_from_this(), Buffer(), _allocSize);
}

std::shared_ptr<ConstSendBuffer> SendBufferChunk::OpenConst(uint32 _allocSize)
{
    ASSERT_CRASH(_allocSize <= SEND_BUFFER_CHUNK_SIZE)
    ASSERT_CRASH(m_IsOpen == false)

    if (_allocSize > FreeSize())
        return nullptr;

    m_IsOpen = true;

    return ObjectPool<ConstSendBuffer>::MakeShared(shared_from_this(), Buffer(), _allocSize);
}

void SendBufferChunk::Close(uint32 _writeSize)
{
    ASSERT_CRASH(m_IsOpen == true);
    m_IsOpen = false;
    m_UsedSize += _writeSize;
}

bool SendBufferChunk::IsOpen() const
{
    return m_IsOpen;
}

BYTE* SendBufferChunk::Buffer()
{
    return &m_Buffer[m_UsedSize];
}

uint32 SendBufferChunk::FreeSize()
{
    return static_cast<uint32>(m_Buffer.size()) - m_UsedSize;
}
}
