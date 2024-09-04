#pragma once
#include <functional>
#include <memory>

#include "Core/CoreMacro.h"
#include "Core/BoostTypes.h"
#include "Memory/Container.h"


namespace ServerCore
{
class SendBuffer;
class ConstSendBuffer;
class SessionBase;

using SessionFactory = std::function<std::shared_ptr<SessionBase>(void)>;

class Service : public std::enable_shared_from_this<Service>
{
public:
    Service(TcpEndpoint& _endpoint, std::shared_ptr<IoContext> _ioContext,
            int32 _maxSessionCount = 1);
    virtual ~Service();
    std::shared_ptr<IoContext> GetIoContext() const;
    virtual bool Start() =0;

protected:
    virtual bool CanStart() =0;
    virtual void CloseService() = 0;
    int32 GetMaxSessionCount() const;
    TcpEndpoint GetTcpEndpoint() const;

private:
    Service() = delete;
    Service(const Service& _service) = delete;
    Service(Service&& _service) = delete;
    Service& operator=(const Service&) = delete;
    Service& operator=(Service&&) = delete;

protected:
    DECLARE_SINGLE_LOCK;
    TcpEndpoint m_endpoint;
    TcpSocket m_socket;
    std::shared_ptr<IoContext> m_ioContext;
    const int32 m_maxSessionCount;
};
}
