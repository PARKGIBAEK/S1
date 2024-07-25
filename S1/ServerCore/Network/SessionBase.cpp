#include "SessionBase.h"

#include <iostream>

#include "NetHelper.h"
#include "Log/ConsoleLog.h"

namespace ServerCore
{

SessionBase::SessionBase(asio::io_context& _ioContext)
    : m_SessionId(++Session_Id), m_Socket(std::make_shared<TcpSocket>(_ioContext))
{
}

SessionBase::SessionBase(std::shared_ptr<TcpSocket> _socket, const TcpEndPoint& _endpoint)
    : m_SessionId(++Session_Id), m_Socket(_socket), m_Endpoint(_endpoint)
{
}

SessionBase::~SessionBase()
{
    Disconnect();
}

void SessionBase::SetSocket(std::shared_ptr<TcpSocket> _socket)
{
    if (NetHelper::IsValidSocket(m_Socket))
    {
        boost::system::error_code ec;
        m_Socket->close(ec);
        if (ec) {
            std::cerr << "Error closing socket: " << ec.message() << std::endl;
        }
    }
    m_Socket = std::move(_socket);
    if(!NetHelper::IsValidSocket(m_Socket))
    {
        std::wstringstream msg;
        msg << L"Shutdown failed : Session(" <<m_SessionId<<") has invalid socket";
        ConsoleLog::WriteStdErr(msg.str());
    }
}

void SessionBase::Start()
{
    m_StopRequest.store(false);
    StartAsyncRecv();
}

void SessionBase::Disconnect()
{
    m_StopRequest.store(true);
    auto self(shared_from_this());
    asio::post(m_Socket->get_executor(), [this,self]()
    {
        boost::system::error_code ec;
        m_Socket->shutdown(asio::ip::tcp::socket::shutdown_both, ec);  // NOLINT(bugprone-unused-return-value)

        if (ec)
        {
            std::wstringstream msg;
            msg << L"Shutdown failed : " << ec.message().c_str();
            ConsoleLog::WriteStdErr(msg.str());
        }
        else
        {
            std::wcout << L"Session(" << m_SessionId << ") successfully disconnected." << std::endl;
        }
    });
}

void SessionBase::StartAsyncRecv()
{
    if(m_StopRequest)
        return;
    
    auto self(shared_from_this());
    m_Socket->async_receive(asio::buffer(m_RecvBuffer.WritePos(),m_RecvBuffer.FreeSize()),
        [this,self](const boost::system::error_code& ec, std::size_t len)
        {
            if (!ec) {
                HandleAsyncRecv(len);
            } else {
                std::wstringstream msg;
                msg << L"socket error : Session("<<Session_Id<<") - failed async_receive\n" << ec.message().c_str();
                ConsoleLog::WriteStdErr(msg.str());
                Disconnect();
            }
        });
}

void SessionBase::HandleAsyncRecv(std::size_t _len)
{
    // 0받으면 boost::asio단에서 끊어버리므로 처리할 필요 없음
    if(!m_RecvBuffer.OnWrite(_len))
    {
        Disconnect();
    }

    int32 dataSize = m_RecvBuffer.DataSize();
    int32 processedLength = OnRecv(m_RecvBuffer.ReadPos(),dataSize);
    if(processedLength<0||dataSize<processedLength||m_RecvBuffer.OnRead(processedLength)==false)
    {
        Disconnect();
    }
    m_RecvBuffer.Clean();
    StartAsyncRecv();
}

void SessionBase::Send(ConstSendBuffer* _sendBuffer)
{
    if (!IsOpened())
        return;

    bool startedSend = false;

    m_SendQueue.push(_sendBuffer);

    if (m_StartedSend.exchange(true) == false)
        startedSend = true;

    if (startedSend)
        StartAsyncSend();
}

void SessionBase::StartAsyncSend()
{
    if(!IsOpened())
        return;

    // std::vector<boost::asio::const_buffer> buffers;
    Vector<boost::asio::const_buffer> buffers;
    int32 writeSize = 0;
    while (!m_SendQueue.empty())
    {
        ConstSendBuffer* constSendBuffer;
        m_SendQueue.pop(constSendBuffer);
        writeSize += constSendBuffer->WriteSize();
        asio::const_buffer buf(reinterpret_cast<void*>(*constSendBuffer->Buffer()),constSendBuffer->WriteSize());
        buffers.emplace_back(buf);
    }

    auto self(shared_from_this());
    m_Socket->async_send(buffers,[this,self](const boost::system::error_code& _ec, const std::size_t _len)
    {
        if (!_ec) {
            std::cout << "Session("<<Session_Id<<") Sent " << _len << " bytes successfully." << std::endl;
            // send는 CPS로 반복할 필요 없음
        } else {
            std::wstringstream msg;
            msg << L"socket error : Session("<<Session_Id<<") - failed async_send\n" << _ec.message().c_str();
            ConsoleLog::WriteStdErr(msg.str());
            Disconnect();
        }
    });
}

void SessionBase::HandleAsyncSend(std::size_t _len)
{
}

bool SessionBase::IsOpened()
{
    return m_Socket->is_open();
}

int32 SessionBase::OnRecv(BYTE* _buffer, int32 _len)
{
    if(m_RecvBuffer.OnWrite(_len))
    {
        std::wstringstream msg;
        msg << L"RecvBuffer error : Session("<<Session_Id<<") - received size is larger than FreeSize.\n";
        ConsoleLog::WriteStdErr(msg.str());
        Disconnect();
    }
    while(true)
    {
        // 패킷 헤더 수신 확인
        if(m_RecvBuffer.DataSize()<HEADER_SIZE)
            break;
        // 파싱 가능한 패킷 사이즈만큼 수신했는지 확인
        PacketHeader* packetHeader = reinterpret_cast<PacketHeader*>(m_RecvBuffer.ReadPos());
        if(m_RecvBuffer.DataSize() < packetHeader->size)
            break;
        OnRecvPacket(packetHeader); // TODO : 자식 클래스에서 재정의 필수
        m_RecvBuffer.OnRead(packetHeader->size);
    }
    StartAsyncRecv();

    return _len;
}

}
