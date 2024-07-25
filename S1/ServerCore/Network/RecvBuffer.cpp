#include "RecvBuffer.h"


namespace ServerCore
{
RecvBuffer::RecvBuffer() : bufferSize(static_cast<int32>(ALLOCATION::DEFAULT_RECV_BUFFER_SIZE))
{
    capacity = bufferSize * BUFFER_COUNT;
    buffer.resize(capacity);
}

RecvBuffer::RecvBuffer(int32 _bufferSize) : bufferSize(_bufferSize)
{
    capacity = bufferSize * BUFFER_COUNT;
    buffer.resize(capacity);
}

void RecvBuffer::Clean()
{
    int32 dataSize = DataSize();

    if (0 == dataSize)
    {
        readCursor = writeCursor = 0;
    }
    else if (FreeSize() < bufferSize)
    {
        // 여유 공간이 버퍼 1개 크기 미만이면, 데이터를 앞으로 당기기
        ::memcpy(&buffer[0], &buffer[readCursor], dataSize);
        readCursor = 0;
        writeCursor = dataSize;
    }
}

bool RecvBuffer::OnRead(int32 _numOfBytes)
{
    if (_numOfBytes > DataSize())
        return false;

    readCursor += _numOfBytes;
    return true;
}

bool RecvBuffer::OnWrite(int32 _numOfBytes)
{
    if (_numOfBytes > FreeSize())
        return false;

    writeCursor += _numOfBytes;
    return true;
}

}
