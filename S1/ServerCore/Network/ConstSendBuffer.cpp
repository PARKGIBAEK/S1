#include "pch.h"
#include "ConstSendBuffer.h"
#include "Core/CoreMacro.h"
#include "SendBufferChunk.h"

namespace ServerCore
{
ConstSendBuffer::ConstSendBuffer(std::shared_ptr<SendBufferChunk> _owner, const BYTE* _buffer, const uint32 _allocSize)
    : m_Buffer(_buffer), m_AllocSize(_allocSize), m_WriteSize(_allocSize), m_Owner(_owner)
{
}

ConstSendBuffer::ConstSendBuffer(SendBuffer* _sendBuffer)
    : m_Buffer(_sendBuffer->m_Buffer), m_AllocSize(_sendBuffer->m_AllocSize), m_WriteSize(_sendBuffer->m_WriteSize),
      m_Owner(_sendBuffer->m_Owner)
{
}

ConstSendBuffer::~ConstSendBuffer()
{
}

const BYTE* ConstSendBuffer::Buffer() const
{
    return m_Buffer;
}

uint32 ConstSendBuffer::AllocSize() const
{
    return m_AllocSize;
}

uint32 ConstSendBuffer::WriteSize() const
{
    return m_WriteSize;
}

// void ConstSendBuffer::Close(uint32 _writeSize)
// {
//     ASSERT_CRASH(m_AllocSize >= _writeSize);
//     m_Owner->Close(_writeSize);
// }
}
