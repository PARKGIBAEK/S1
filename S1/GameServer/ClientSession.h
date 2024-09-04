#pragma once
#include "Network/PacketSession.h"
#include "Network/SessionBase.h"
#include "Core/Types.h"

namespace GameServer
{
using namespace ServerCore;

class ClientSession final : public PacketSession
{
public:
    ClientSession();

protected:
    void OnRecvPacket(BYTE* _buffer, int32 _len) override;

public:
    ~ClientSession() override;
    void Start() override;
    void HandleRecv(const std::size_t _len) override;
    void OnDisconnected() override;
    void OnAsyncRecvFailed(const boost::system::error_code& _ec) override;
    void OnShutdownFailed(const boost::system::error_code& _ec) override;
    void OnAsyncSendFailed(const boost::system::error_code& _ec) override;
    void OnAsyncRecv(const int32 _len) override;
    void OnAsyncSend(const int32 _countSendBuffer) override;
    void OnSetConnectSocketFailed() override;

    int32 GetSessionId() const { return m_sessionId; }

    friend std::ostream& operator<<(std::ostream& _os, const ClientSession& _session);
    friend std::wostream& operator<<(std::wostream& _os, const ClientSession& _session);

private:
    int32 m_sessionId;
    static std::atomic<int32> s_ClientSessionId;
};

inline std::atomic<int32> ClientSession::s_ClientSessionId = 0;
}
