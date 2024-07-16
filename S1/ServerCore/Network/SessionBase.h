#pragma once
#include <memory>
#include <boost/asio.hpp>
#include <boost/lockfree/queue.hpp>
#include "NetHelper.h"
#include "NetTypes.h"
#include "RecvBuffer.h"
#include "PacketHeader.h"
#include "ConstSendBuffer.h"

namespace ServerCore
{
using namespace boost;

class SessionBase : public std::enable_shared_from_this<SessionBase>
{

public:
    SessionBase(asio::io_context& _ioContext);
    SessionBase(std::shared_ptr<TcpSocket> _socket,
                const TcpEndPoint& _endpoint);
    virtual         ~SessionBase();
    void            SetSocket(std::shared_ptr<TcpSocket> _socket);
    virtual void    Start();
    void            Disconnect();
    void            StartAsyncRecv();
    virtual void    HandleAsyncRecv(std::size_t _len);
    void            Send(ConstSendBuffer* _sendBuffer);
    void            StartAsyncSend();
    virtual void    HandleAsyncSend(std::size_t _len);
    bool            IsOpened();
protected:
    virtual void    OnRecvPacket(PacketHeader* _packetHeader)=0;
    
private:
    int32           OnRecv(BYTE* _buffer, int32 _len);
    
private:
    static std::atomic<int32>       Session_Id;
    int32                           m_SessionId;
    std::shared_ptr<TcpSocket>      m_Socket;
    TcpEndPoint                     m_Endpoint;
    RecvBuffer                      m_RecvBuffer;
    std::atomic<bool>               m_StopRequest;
    std::atomic<bool>               m_StartedSend;
    lockfree::queue<ConstSendBuffer*>    m_SendQueue;
    lockfree::queue<asio::const_buffer*>  m_SendQueue2;
};
}
