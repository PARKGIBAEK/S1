#pragma once
#include "ClientSession.h"
#include "Network/SessionManager.h"
#include "Network/Service.h"
#include "Core/BoostTypes.h"
#include "Network/NetHelper.h"

using namespace ServerCore;

namespace GameServer
{

template <typename SessionType>
class ServerService : public Service
{
public:
    ServerService(TcpEndpoint& _endpoint, std::shared_ptr<IoContext> _ioContext,
        int32 _maxSessionCount);
    virtual ~ServerService() override;

    bool Start() override;
    void RunAcceptor();

private:
    void CloseService() override;

protected:
    bool CanStart() override;

private:
    ServerService() = delete;
    ServerService(const ServerService&) = delete;
    ServerService(ServerService&& _service) = delete;
    ServerService& operator=(const ServerService&) = delete;
    ServerService& operator=(ServerService&&) = delete;

private:
    std::shared_ptr<TcpAcceptor> m_acceptor;
    std::atomic<bool> isListening;
    std::vector<std::shared_ptr<std::thread>> m_workerThreads;
    std::shared_ptr<SessionManager<SessionType>> m_sessionManager;
};


////////////////////////////////////
// Template class implementations //
////////////////////////////////////

template <typename SessionType>
ServerService<SessionType>::ServerService(TcpEndpoint& _endpoint, std::shared_ptr<IoContext> _ioContext,
    int32 _maxSessionCount)
    : Service(_endpoint, _ioContext, _maxSessionCount), isListening(false)
{
    //m_acceptor = NetHelper::CreateAcceptor(m_ioContext, m_endpoint);
    m_acceptor = MakeShared<TcpAcceptor>(m_ioContext);
    m_sessionManager = MakeShared<SessionManager<SessionType>>(_ioContext, _endpoint);
}

template <typename SessionType>
bool ServerService<SessionType>::Start()
{
    m_acceptor->bind(m_endpoint);
    m_acceptor->listen();
    // calling multiple 'async_accept' on a single 'TcpAcceptor(asio::ip::tcp::acceptor)' will cause an error.
    m_workerThreads.emplace_back(MakeShared<std::thread>(&ServerService::RunAcceptor, this));

    return true;
}

template <typename SessionType>
void ServerService<SessionType>::RunAcceptor()
{
    // std::cout << "ServerService::RunAcceptor()" << std::endl;
    // TcpSocket newSocket = NetHelper::CreateSocket(*m_ioContext);
    isListening.exchange(true);
    m_acceptor->async_accept(
        [this](system::error_code ec, boost::asio::ip::tcp::socket&& newSocket)
        {
            if (!ec)
            {
                auto newSession = this->m_sessionManager->CreateSession();
                newSession->SetConnectedSocket(std::move(newSocket));
                std::wcout << "New connection has established : " << newSession << std::endl;
                newSession->Start();
            }
            else
            {
                std::wstringstream ss;
                ss << L"Accept failed" << ec.what().c_str();
                ConsoleLog::WriteStdErr(ss.str());
            }

            this->RunAcceptor();
        }
    );
}

template <typename SessionType>
ServerService<SessionType>::~ServerService()
{
    CloseService();
}

template <typename SessionType>
void ServerService<SessionType>::CloseService()
{
    m_sessionManager->CloseAllSessions();
}

template <typename SessionType>
bool ServerService<SessionType>::CanStart()
{
    return isListening.load();
}

}
