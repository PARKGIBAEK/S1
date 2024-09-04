#pragma once

#include "Core/CoreMacro.h"
#include "Memory/Container.h"
#include "Memory/MemoryManager.h"
#include "Network/PacketSession.h"
#include "Network/SendBuffer.h"
#include "Util/SFINAEs.h"
#include "Network/NetHelper.h"
#include "Util/SFINAEs.h"

namespace ServerCore
{

template <typename SessionType>
class SessionManager
{
    static_assert(std::is_base_of_v<SessionBase, SessionType>, "SessionType must derive from SessionBase");
public:
    SessionManager(std::shared_ptr<IoContext> ioContext, TcpEndpoint& _ep);
    std::shared_ptr<SessionType> CreateSession();
    void AddSession(std::shared_ptr<SessionType> _clientSession);
    void RemoveSession(std::shared_ptr<SessionType> _clientSession);
    void Broadcast(std::shared_ptr<SendBuffer> _sendBuffer);
    void Broadcast(std::shared_ptr<ConstSendBuffer> _constSendBuffer);
    void Broadcast(ConstSendBuffer* _constSendBuffer);
    void Broadcast(SendBuffer* _sendBuffer);
    void CloseAllSessions();

    SessionManager() = delete;

private:
    DECLARE_SINGLE_LOCK;
    TcpEndpoint m_endpoint;
    std::shared_ptr<IoContext> m_ioContext;
    Set<std::shared_ptr<SessionType>> m_sessions;
    std::atomic<uint32> m_sessionId;
};

template <typename SessionType>
std::shared_ptr<SessionType> SessionManager<SessionType>::CreateSession()
{
    static_assert(std::is_base_of_v<SessionBase, SessionType>, "SessionType must be derived from SessionBase");
    // Sessions 생성
    auto newSession = MakeShared<SessionType>();
    // Session io_context 초기화
    newSession->SetIoContext(m_ioContext);
    // 소켓 생성
    auto newSocket = NetHelper::CreateSocket(*m_ioContext,m_endpoint);
    // Session socket초기화
    newSession->SetSocket(newSocket);
    // Session endpoint초기화
    newSession->SetEndpoint(m_endpoint);
    return newSession;
}
template <typename SessionType>
void SessionManager<SessionType>::AddSession(std::shared_ptr<SessionType> _session)
{
    static std::atomic<uint32> s_SessionId = 1;
    _session->SetSessionId(s_SessionId.fetch_add(1));
    WRITE_LOCK;
    m_sessions.insert(_session);
}

template <typename SessionType>
void SessionManager<SessionType>::RemoveSession(std::shared_ptr<SessionType> _session)
{

    static_assert(has_member_variable_v<&SessionType::m_sessionId>, "SessionType must contain member variable 'm_sessionId'");
    WRITE_LOCK;
    m_sessions.erase(_session);
}

template <typename SessionType>
void SessionManager<SessionType>::Broadcast(std::shared_ptr<SendBuffer> _sendBuffer)
{
    static_assert(has_member_func_with_signature_v<SessionType, &SessionType::EnqueueSendBuffer, void, std::shared_ptr<SendBuffer>>, "SessionType must have member function 'void EnqueueSendBuffer(std::shared_ptr<SendBuffer>)'");

    WRITE_LOCK;
    for (auto& session : m_sessions)
        session->EnqueueSendBuffer(_sendBuffer);
}

template <typename SessionType>
void SessionManager<SessionType>::Broadcast(std::shared_ptr<ConstSendBuffer> _constSendBuffer)
{
    static_assert(has_member_func_with_signature_v<SessionType, &SessionType::EnqueueSendBuffer, void, std::shared_ptr<ConstSendBuffer>>, "SessionType must have member function 'void EnqueueSendBuffer(std::shared_ptr<ConstSendBuffer>)'");

    WRITE_LOCK;
    for (auto& session : m_sessions)
        session->EnqueueSendBuffer(_constSendBuffer);
}

template <typename SessionType>
void SessionManager<SessionType>::Broadcast(ConstSendBuffer* _constSendBuffer)
{
    static_assert(has_member_func_with_signature_v<SessionType, &SessionType::EnqueueSendBuffer, void, ConstSendBuffer*>, "SessionType must have member function 'void EnqueueSendBuffer(ConstSendBuffer*)'");

    WRITE_LOCK;
    for (auto& session : m_sessions)
        session->EnqueueSendBuffer(_constSendBuffer);
}

template <typename SessionType>
void SessionManager<SessionType>::Broadcast(SendBuffer* _sendBuffer)
{
    static_assert(has_member_func_with_signature_v<SessionType, &SessionType::EnqueueSendBuffer, void, SendBuffer*>, "SessionType must have member function 'void EnqueueSendBuffer(SendBuffer*)'");

    WRITE_LOCK;
    for (auto& session : m_sessions)
        session->EnqueueSendBuffer(_sendBuffer);
}

template <typename SessionType>
SessionManager<SessionType>::SessionManager(std::shared_ptr<IoContext> ioContext, TcpEndpoint& _ep)
{
    m_ioContext = ioContext;
    m_endpoint = _ep;
}


template <typename SessionType>
void SessionManager<SessionType>::CloseAllSessions()
{
    WRITE_LOCK;
    for (auto& session : m_sessions)
        session->Disconnect();
}
}
