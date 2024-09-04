#pragma once
#include <memory>
#include <boost/asio.hpp>
#include <boost/lockfree/queue.hpp>
#include "Core/Types.h"
#include "Core/BoostTypes.h"
#include "RecvBuffer.h"
#include "PacketHeader.h"
#include "ConstSendBuffer.h"
#include "SendBuffer.h"

namespace ServerCore
{
using namespace boost;

class SessionBase : public std::enable_shared_from_this<SessionBase>
{
public:
    SessionBase();
    virtual ~SessionBase();
    void SetSocket(std::shared_ptr<TcpSocket> _socket);
    void SetSocket(TcpSocket&& _socket);
    void SetEndpoint(TcpEndpoint& _ep);
    void SetConnectedSocket(std::shared_ptr<TcpSocket> _socket);
    void SetConnectedSocket(TcpSocket&& _socket);
    void SetIoContext(std::shared_ptr<asio::io_context> _ioContext);
    virtual void Start();
    void Disconnect();
    void ContinueAsyncRecv();
    virtual void HandleRecv(const std::size_t _len);
    void EnqueueSendBuffer(ConstSendBuffer* _sendBuffer);
    void EnqueueSendBuffer(std::shared_ptr<ConstSendBuffer> _sendBuffer);
    void EnqueueSendBuffer(SendBuffer* _sendBuffer);
    void EnqueueSendBuffer(std::shared_ptr<SendBuffer> _sendBuffer);
    void FlushSendQueueAsync();
    bool IsOpened() const;
    void SetSessionId(uint32 _sessionId);

    virtual void OnDisconnected() = 0;
    virtual void OnAsyncRecv(const int32 _len) =0;
    virtual void OnAsyncRecvFailed(const boost::system::error_code& _ec) =0;
    virtual void OnAsyncSend(const int32 _countSendBuffer) =0;
    virtual void OnAsyncSendFailed(const boost::system::error_code& _ec) =0;
    virtual void OnShutdownFailed(const boost::system::error_code& _ec) =0;
    virtual void OnSetConnectSocketFailed() =0;


protected:
    virtual int32 OnRecv(BYTE* _buffer, int32 _len) =0; // Packet Header 확인

protected:
    uint32 m_sessionId;
    std::shared_ptr<asio::io_context> m_ioContext;
    std::shared_ptr<TcpSocket> m_socket;
    TcpEndpoint m_endpoint;
    RecvBuffer m_recvBuffer;
    std::atomic<bool> m_stopRequest;
    std::atomic<bool> m_isSending;
    LockfreeQueue<ConstSendBuffer*> m_sendQueue;
};
}
