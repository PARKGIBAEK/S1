#include "SendBufferManager.h"

#include "Core/GlobalInitializer.h"
#include "Core/CoreTLS.h"
#include "Memory/MemoryManager.h"
#include "Network/SendBufferChunk.h"
#include "SendBuffer.h"
#include "ConstSendBuffer.h"

namespace ServerCore
{

std::shared_ptr<SendBuffer> SendBufferManager::Open(uint32 _reqSize)
{
    if (tls_SendBufferChunk == nullptr)
    {
        tls_SendBufferChunk = SendBufferManager::Pop(); // WRITE_LOCK
        tls_SendBufferChunk->ResetBuffer();
    }

    ASSERT_CRASH(tls_SendBufferChunk->IsOpen() == false)

    // 다 썼으면 버리고 새걸 교체
    if (tls_SendBufferChunk->FreeSize() < _reqSize)
    {
        tls_SendBufferChunk = SendBufferManager::Pop(); // WRITE_LOCK
        tls_SendBufferChunk->ResetBuffer();
    }

    return tls_SendBufferChunk->Open(_reqSize);
}

std::shared_ptr<ConstSendBuffer> SendBufferManager::OpenConst(uint32 _reqSize)
{
    if (tls_SendBufferChunk == nullptr)
    {
        tls_SendBufferChunk = SendBufferManager::Pop(); // WRITE_LOCK
        tls_SendBufferChunk->ResetBuffer();
    }

    ASSERT_CRASH(tls_SendBufferChunk->IsOpen() == false);

    // 다 썼으면 버리고 새걸 교체
    if (tls_SendBufferChunk->FreeSize() < _reqSize)
    {
        tls_SendBufferChunk = SendBufferManager::Pop(); // WRITE_LOCK
        tls_SendBufferChunk->ResetBuffer();
    }

    return tls_SendBufferChunk->OpenConst(_reqSize);
}

std::shared_ptr<SendBufferChunk>  SendBufferManager::Pop()
{
    {
        WRITE_LOCK;
        if (sendBufferChunks.empty() == false)
        {
            std::shared_ptr<SendBufferChunk>  sendBufferChunk = sendBufferChunks.back();
            sendBufferChunks.pop_back();
            return sendBufferChunk;
        }
    }

    // Pooling
    // SendBufferChunk* 인스턴스를 SendBufferManager::sendBufferChunks에 다시 반환
    // PushGlobal은 shared_ptr의 소멸자
    return std::shared_ptr<SendBufferChunk> (XNew<SendBufferChunk>(), PushGlobal);
}

void SendBufferManager::Push(std::shared_ptr<SendBufferChunk>  _buffer)
{
    WRITE_LOCK;
    sendBufferChunks.emplace_back(_buffer);
}

void SendBufferManager::PushGlobal(SendBufferChunk* _buffer)
{
    g_SendBufferManager->Push(std::shared_ptr<SendBufferChunk> (_buffer, PushGlobal));
}

}
