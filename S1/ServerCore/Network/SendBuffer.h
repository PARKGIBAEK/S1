#pragma once
#include <memory>

#include "ConstSendBuffer.h"
#include "Core/Types.h"

namespace ServerCore
{
class SendBufferChunk;
class ConstSendBuffer;

class SendBuffer : public std::enable_shared_from_this<SendBuffer>
{
    friend class ConstSendBuffer;

public:
    SendBuffer(std::shared_ptr<SendBufferChunk> _owner, BYTE* _buffer, uint32 _allocSize);
    ~SendBuffer();

    BYTE* Buffer() const;
    const BYTE* ConstBuffer() const;
    explicit operator ConstSendBuffer() const;
    uint32 AllocSize() const;
    uint32 WriteSize() const;
    void Close(uint32 _writeSize);


    SendBuffer(const SendBuffer&) = delete;
    SendBuffer(SendBuffer&&) = delete;
    SendBuffer& operator=(const SendBuffer&) = delete;
    SendBuffer& operator=(const SendBuffer&&) = delete;

private:
    BYTE* m_Buffer;
    uint32 m_AllocSize;
    uint32 m_WriteSize;
    std::weak_ptr<SendBufferChunk> m_Owner;
};
}
