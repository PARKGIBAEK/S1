#pragma once
#include "Core/BoostTypes.h"

namespace Temp
{
class Temp
{
private:
    void KeepIoContextRun(std::shared_ptr<ServerCore::IoContext> _ioContext);
    void DbTest();
};



template <typename SessionType>
class has_disconnect_class
{
    std::vector<std::shared_ptr<SessionType>> m_sessions;

public:
    void AddSession(std::shared_ptr<SessionType> session)
    {
        m_sessions.push_back(session);
    }

    void CloseSessions()
    {


        for (auto& session : m_sessions)
        {
            session->Disconnect();
        }
    }
};
}
