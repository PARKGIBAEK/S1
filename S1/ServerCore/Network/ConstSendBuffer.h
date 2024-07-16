#pragma once
#include <memory>
#include "Core/Types.h"

namespace ServerCore
{

class SendBufferChunk;

class ConstSendBuffer
{
public:
    ConstSendBuffer(std::shared_ptr<SendBufferChunk> _owner, const BYTE* _buffer, uint32 _allocSize);
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
    std::shared_ptr<SendBufferChunk> m_Owner;
};
}
