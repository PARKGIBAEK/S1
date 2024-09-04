#include "pch.h"
#include "ClientSession.h"

#include "Log/ConsoleLog.h"
#include "Network/PacketHandler.h"

namespace GameServer
{
ClientSession::ClientSession(): m_sessionId(s_ClientSessionId++)
{
}


void ClientSession::OnRecvPacket(BYTE* _buffer, int32 _len)
{
    std::shared_ptr<PacketSession> packetSession = static_pointer_cast<PacketSession>(shared_from_this());
    PacketHandler::HandlePacket(packetSession, _buffer, _len);
}

ClientSession::~ClientSession()
{
}

void ClientSession::Start()
{
    SessionBase::Start();
}

void ClientSession::HandleRecv(const std::size_t _len)
{
    SessionBase::HandleRecv(_len);
}

void ClientSession::OnDisconnected()
{
    std::wstringstream msg;
    msg << L"ClientSession(" << m_sessionId << ") disconnected successfully.";
    ConsoleLog::WriteStdOut(msg.str());
}

void ClientSession::OnAsyncRecvFailed(const boost::system::error_code& _ec)
{
    std::wstringstream msg;
    msg << L"socket error : ClientSession(" << m_sessionId << ") - failed async_receive\n" <<
        _ec.message().c_str();
    ConsoleLog::WriteStdErr(msg.str());
}

void ClientSession::OnShutdownFailed(const boost::system::error_code& _ec)
{
    std::wstringstream msg;
    msg << *this << L"Shutdown failed : " << _ec.message().c_str();
    ConsoleLog::WriteStdErr(msg.str());
    m_socket->close();
}

void ClientSession::OnAsyncSendFailed(const boost::system::error_code& _ec)
{
    std::wstringstream msg;
    msg << L"socket error : " << *this << " - failed async_send\n" << _ec.message().c_str();
    ConsoleLog::WriteStdErr(msg.str());
}

void ClientSession::OnAsyncRecv(int32 _len)
{
    std::wstringstream msg;
    msg << *this << L"Recv " << _len << L" bytes(" << _len <<
        L" bytes) successfully" << std::endl;
    ConsoleLog::WriteStdOut(msg.str());
}

void ClientSession::OnAsyncSend(const int32 _countSendBuffer)
{
    std::wstringstream msg;
    msg << *this << L" Sent " << _countSendBuffer << L" packets successfully" << std::endl;
    ConsoleLog::WriteStdOut(msg.str());
}

void ClientSession::OnSetConnectSocketFailed()
{
    std::wstringstream msg;
    msg << *this << L" failed to set socket";
    ConsoleLog::WriteStdErr(msg.str());
}

std::ostream& operator<<(std::ostream& _os, const ClientSession& _session)
{
    _os << "ClientSession(" << _session.m_sessionId << ")";
    return _os;
}

std::wostream& operator<<(std::wostream& _os, const ClientSession& _session)
{
    _os << L"ClientSession(" << _session.m_sessionId << L")";
    return _os;
}
}
