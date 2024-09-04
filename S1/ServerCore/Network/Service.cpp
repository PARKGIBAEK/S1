#include "pch.h"
#include "Service.h"

#include "SendBuffer.h"
#include "ConstSendBuffer.h"
#include "SessionBase.h"
#include "NetHelper.h"
#include "Log/ConsoleLog.h"

namespace ServerCore
{
Service::Service(TcpEndpoint& _endpoint, std::shared_ptr<IoContext> _ioContext, int32 _maxSessionCount)
    : m_endpoint(_endpoint), m_socket(*_ioContext, _endpoint),
      m_ioContext(_ioContext), m_maxSessionCount(_maxSessionCount)
{

}

Service::~Service()
{
}

std::shared_ptr<IoContext> Service::GetIoContext() const
{
    return m_ioContext;
}

int32 Service::GetMaxSessionCount() const
{
    return m_maxSessionCount;
}

TcpEndpoint Service::GetTcpEndpoint() const
{
    return m_endpoint;
}
}
