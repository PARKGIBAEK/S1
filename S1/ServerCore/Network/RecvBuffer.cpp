#include "pch.h"
#include "RecvBuffer.h"


namespace ServerCore
{
RecvBuffer::RecvBuffer() : m_BufferSize(static_cast<int32>(ALLOCATION::DEFAULT_RECV_BUFFER_SIZE))
{
    m_Capacity = m_BufferSize * BUFFER_COUNT;
    m_Buffer.resize(m_Capacity);
}

RecvBuffer::RecvBuffer(int32 _bufferSize) : m_BufferSize(_bufferSize)
{
    m_Capacity = m_BufferSize * BUFFER_COUNT;
    m_Buffer.resize(m_Capacity);
}

void RecvBuffer::Clean()
{
    int32 dataSize = DataSize();

    if (0 == dataSize)
    {
        m_ReadCursor = m_WriteCursor = 0;
    }
    else if (FreeSize() < m_BufferSize)
    {
        // 여유 공간이 버퍼 1개 크기 미만이면, 데이터를 앞으로 당기기
        ::memcpy(&m_Buffer[0], &m_Buffer[m_ReadCursor], dataSize);
        m_ReadCursor = 0;
        m_WriteCursor = dataSize;
    }
}

bool RecvBuffer::OnRead(int32 _numOfBytes)
{
    if (_numOfBytes > DataSize())
        return false; // 수신된 데이터를 초과한 양을 처리한 경우

    m_ReadCursor += _numOfBytes;
    return true;
}

bool RecvBuffer::OnWrite(int32 _numOfBytes)
{
    if (_numOfBytes > FreeSize())
        return false;

    m_WriteCursor += _numOfBytes;
    return true;
}

}
