#include "pch.h"
#include "SessionBase.h"

#include <iostream>

#include "NetHelper.h"
#include "Log/ConsoleLog.h"
#include "Memory/MemoryManager.h"

namespace ServerCore
{
constexpr int LOCKFREE_QUEUE_SIZE = 400;

SessionBase::SessionBase()
    : m_socket(nullptr), m_sendQueue(LOCKFREE_QUEUE_SIZE)
{
}

SessionBase::~SessionBase()
{
    Disconnect();
}

void SessionBase::SetSocket(std::shared_ptr<TcpSocket> _socket)
{
    m_socket = _socket;
}

void SessionBase::SetSocket(TcpSocket&& _socket)
{
    m_socket = MakeShared<TcpSocket>(std::move(_socket));
}

void SessionBase::SetEndpoint(TcpEndpoint& _ep)
{
    m_endpoint = _ep;
}


void SessionBase::SetConnectedSocket(std::shared_ptr<TcpSocket> _socket)
{
    m_socket = _socket;
    if (NetHelper::IsValidSocket(m_socket))
    {
        OnSetConnectSocketFailed();
    }
}

void SessionBase::SetConnectedSocket(TcpSocket&& _socket)
{
    m_socket = MakeShared<TcpSocket>(std::move(_socket));
    if (NetHelper::IsValidSocket(m_socket))
    {
        OnSetConnectSocketFailed();
    }
}

void SessionBase::SetIoContext(std::shared_ptr<asio::io_context> _ioContext)
{
    m_ioContext = _ioContext;
}

void SessionBase::Start()
{
    m_stopRequest.store(false);
    ContinueAsyncRecv();
}

void SessionBase::Disconnect()
{
    m_stopRequest.store(true);
    if (!NetHelper::IsValidSocket(m_socket))
        return;
    auto self(shared_from_this());
    asio::post(m_socket->get_executor(), [self]()
        {
            boost::system::error_code ec;
            self->m_socket->shutdown(asio::ip::tcp::socket::shutdown_both, ec); // NOLINT(bugprone-unused-return-value)

            if (ec)
            {
                self->OnShutdownFailed(ec);
            }
            else
            {
                self->OnDisconnected();
            }
        });
}

void SessionBase::ContinueAsyncRecv()
{
    if (m_stopRequest)
        return;

    // auto self(shared_from_this());
    m_socket->async_receive(asio::buffer(m_recvBuffer.WritePos(), m_recvBuffer.FreeSize()),
        [this](const boost::system::error_code& _ec, std::size_t _len)
        {
            if (!_ec)
            {
#ifdef _DEBUG
                this->OnAsyncRecv(_len);
#endif
                this->HandleRecv(_len);

            }
            else
            {
                this->OnAsyncRecvFailed(_ec);
                this->Disconnect();
            }
        });
}

void SessionBase::HandleRecv(const std::size_t _len)
{
    // 받은 데이터 크기가 0이면 boost::asio단에서 끊어버리므로 예외 처리 필요 없음
    if (!m_recvBuffer.OnWrite(_len))
    {
        ConsoleLog::WriteStdErr(L"Failed 'HandleRecv' : Received 0 bytes");
        Disconnect();
    }

    int32 dataSize = m_recvBuffer.DataSize();
    int32 processedLength = OnRecv(m_recvBuffer.ReadPos(), dataSize);
    if (processedLength < 0 || m_recvBuffer.OnRead(processedLength) == false)
    {
        ConsoleLog::WriteStdErr(L"Failed 'HandleRecv' : Received data exceeds the size of the RecvBuffer ");
        Disconnect();
    }
    m_recvBuffer.Clean();
    ContinueAsyncRecv();
}

void SessionBase::EnqueueSendBuffer(ConstSendBuffer* _sendBuffer)
{
    if (!IsOpened())
        return;

    m_sendQueue.push(_sendBuffer);

    if (m_isSending.exchange(true) == false) // 어차피 m_isSending이 true이면 전송 중이기 때문에 true로 바뀌어도 상관 없음
    {
        FlushSendQueueAsync();
    }
}

void SessionBase::EnqueueSendBuffer(std::shared_ptr<ConstSendBuffer> _sendBuffer)
{
    if (!IsOpened())
        return;

    m_sendQueue.push(_sendBuffer.get());

    if (m_isSending.exchange(true) == false) // 어차피 m_isSending이 true이면 전송 중이기 때문에 true로 바뀌어도 상관 없음
    {
        FlushSendQueueAsync();
    }
}

void SessionBase::EnqueueSendBuffer(std::shared_ptr<SendBuffer> _sendBuffer)
{
    if (!IsOpened())
        return;

    ConstSendBuffer* constSendBuffer = new ConstSendBuffer(_sendBuffer.get());
    m_sendQueue.push(constSendBuffer);

    if (m_isSending.exchange(true) == false) // 어차피 m_isSending이 true이면 전송 중이기 때문에 true로 바뀌어도 상관 없음
    {
        FlushSendQueueAsync();
    }
}

void SessionBase::EnqueueSendBuffer(SendBuffer* _sendBuffer)
{
    if (!IsOpened())
        return;

    ConstSendBuffer* constSendBuffer = new ConstSendBuffer(_sendBuffer);
    m_sendQueue.push(constSendBuffer);

    if (m_isSending.exchange(true) == false) // 어차피 m_isSending이 true이면 전송 중이기 때문에 true로 바뀌어도 상관 없음
    {
        FlushSendQueueAsync();
    }
}

/* FlushSendQueueAsync 함수 호출 진입 시점부터
m_isSending.exchange(false)호출까지는
m_isSending값이 무조건 true임을 보장하며
다른 thread가 들어올 수가 없음

그러나 while문을 탈출하는 시점에
다른 스레드에서 Session의 m_isSending의 값이 true이면
m_sendQueue에 메시지를 삽입할 수 있다.
따라서 exchange(false)가 호출되는 시점에
m_sendQueue에는 메시지가 남아있을 수 있다.

그러므로 m_socket->async_send를 호출하고
Session이 예상치 못하게 종료될 경우
m_SendQueue에 남아있는 메시지를 처리하지 않게 되는 경우를 고려해야 한다.
따라서 m_socket->async_send부분의 완료 콜백에서
m_sendQueue가 비었는지 확인하고
FlushSendQueueAsync 함수를 한번더 호출해주어야 할 수도 있다.*/
void SessionBase::FlushSendQueueAsync()
{
    if (!IsOpened())
        return;

    // std::vector<boost::asio::const_buffer> buffers;
    Vector<boost::asio::const_buffer> buffers;
    int32 sendCountForProfiling = 0;
    while (!m_sendQueue.empty())
    {
        ConstSendBuffer* constSendBuffer;
        m_sendQueue.pop(constSendBuffer);
        sendCountForProfiling++;
        asio::const_buffer buf(reinterpret_cast<void*>(*constSendBuffer->Buffer()), constSendBuffer->WriteSize());
        buffers.emplace_back(buf);
    }

    m_isSending.exchange(false); // 여기까지 m_isSending은 무조건 true임

    if (buffers.empty())
        return;

    auto self(shared_from_this());
    m_socket->async_send(
        buffers, [this, sendCountForProfiling](const boost::system::error_code& _ec, const std::size_t _len)
        {
            if (!_ec)
            {
#ifdef _DEBUG
                OnAsyncSend(sendCountForProfiling);
#endif

                if (m_sendQueue.empty())
                    return;
                bool isSending = false;
                if (m_isSending.compare_exchange_strong(isSending, true) && !m_sendQueue.empty())
                {
                    FlushSendQueueAsync();
                }
            }
            else
            {
                OnAsyncSendFailed(_ec);

                Disconnect();
            }
        });
}

bool SessionBase::IsOpened() const
{
    if (!m_socket->is_open())
    {
        return false;
    }
    /* remote_endpoint()함수호출 시 에러 발생 가능한 경우
     1. 원격 피어가 연결을 닫았지만, 로컬 소켓이 아직 이를 감지하지 못한 경우 */
    boost::system::error_code ec;
    m_socket->remote_endpoint(ec);
    return !ec;
}
void SessionBase::SetSessionId(uint32 _sessionId)
{
    m_sessionId = _sessionId;
}

}
