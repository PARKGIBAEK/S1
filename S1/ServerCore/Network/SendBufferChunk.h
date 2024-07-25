#pragma once

#include <array>
#include <memory>
#include "Core/Types.h"


namespace ServerCore
{


class SendBuffer;
class ConstSendBuffer;

class SendBufferChunk : public std::enable_shared_from_this<SendBufferChunk>
{
    enum
    {
        SEND_BUFFER_CHUNK_SIZE = 0x2000,
    };

public:
    SendBufferChunk();
    ~SendBufferChunk();

    void					    ResetBuffer();
    std::shared_ptr<SendBuffer>	Open(uint32 _allocSize);
    std::shared_ptr<ConstSendBuffer>	OpenConst(uint32 _allocSize);
    void					    Close(uint32 _writeSize);
    
    bool					    IsOpen() const;
    BYTE*					    Buffer();
    uint32					    FreeSize();

    SendBufferChunk(const SendBufferChunk&) = delete;
    SendBufferChunk(SendBufferChunk&&)=delete;
    SendBufferChunk& operator=(const SendBufferChunk&) = delete;
    SendBufferChunk& operator=(const SendBufferChunk&&) = delete;
private:
    std::array<BYTE, SEND_BUFFER_CHUNK_SIZE>	buffer;
    bool									    isOpen;
    uint32									    usedSize; // buffer cursor
};
}