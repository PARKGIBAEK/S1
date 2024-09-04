#pragma once
#include <memory>

#include "SendBuffer.h"
#include "Core/Types.h"

namespace ServerCore
{

class SendBufferChunk;
class SendBuffer;
class ConstSendBuffer
{
public:
    ConstSendBuffer(std::shared_ptr<SendBufferChunk> _owner, const BYTE* _buffer, uint32 _allocSize);
    ConstSendBuffer(SendBuffer* _sendBuffer);
    ~ConstSendBuffer();

    const BYTE* Buffer() const;
    uint32 AllocSize() const;
    uint32 WriteSize() const;

    ConstSendBuffer(const ConstSendBuffer&) = delete;
    ConstSendBuffer(ConstSendBuffer&&)=delete;
    ConstSendBuffer& operator=(const ConstSendBuffer&) = delete;
    ConstSendBuffer& operator=(const ConstSendBuffer&&) = delete;

private:
    const BYTE* m_Buffer;
    const uint32 m_AllocSize;
    const uint32 m_WriteSize;
    std::weak_ptr<SendBufferChunk> m_Owner;
};
}
