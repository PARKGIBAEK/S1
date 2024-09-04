#pragma once
#include <boost/asio.hpp>
#include "Core/BoostTypes.h"
#include "Log/ConsoleLog.h"
#include "Memory/MemoryManager.h"

namespace ServerCore
{
using namespace boost;

class NetHelper
{
public:
    // socket
    static bool IsValidSocket(const TcpSocket& _socket)
    {
        if (!_socket.is_open())
            return false;

        // 소켓의 원격 엔드포인트를 가져올 때 오류 코드가 발생하는지 확인
        boost::system::error_code ec;
        _socket.remote_endpoint(ec);
        if (ec)
            return false;
        return true;
    }

    static bool IsValidSocket(std::shared_ptr<TcpSocket> _socket)
    {
        if (!_socket->is_open())
            return false;

        // 소켓의 원격 엔드포인트를 가져올 때 오류 코드가 발생하는지 확인
        boost::system::error_code ec;
        _socket->remote_endpoint(ec);
        if (ec)
        {
            // remote_endpoint에서 발생할 수 있는 주요 에러 처리
            if (ec == boost::asio::error::not_connected)
            {
                // std::cout << "Socket is not connected." << std::endl;
                return false;
            }
            else if (ec == boost::asio::error::bad_descriptor)
            {
                // std::cout << "Socket has a bad descriptor." << std::endl;
                return false;
            }
            else
            {
                return true;
            }
            // std::cout << "Unexpected error in remote_endpoint: " << ec.message() << std::endl;
            // return false;
        }
        return true;
    }

    static bool IsValidSocket(const UdpSocket& _socket)
    {
        if (!_socket.is_open())
            return false;

        // 소켓의 원격 엔드포인트를 가져올 때 오류 코드가 발생하는지 확인
        boost::system::error_code ec;
        _socket.remote_endpoint(ec);
        if (ec)
            return false;
        return true;
    }

    static bool IsValidSocket(std::shared_ptr<UdpSocket> _socket)
    {
        if (!_socket->is_open())
            return false;

        // 소켓의 원격 엔드포인트를 가져올 때 오류 코드가 발생하는지 확인
        boost::system::error_code ec;
        _socket->remote_endpoint(ec);
        if (ec)
            return false;
        return true;
    }

    static TcpSocket CreateSocket(IoContext& _ctx, bool _no_delay = true,
        bool _reuse_address = true)
    {
        TcpSocket socket(_ctx);
        // socket을 open하지 않고 조작하면 예외 발생
        boost::system::error_code ec;
        if (!socket.is_open())
            socket.open(asio::ip::tcp::v4(), ec);

        if (ec)
        {
            throw std::runtime_error("failed to create a socket");
        }

        if (_reuse_address)
            SetSocketReusable(socket);
        if (_no_delay)
            SetSocketNoDelay(socket);

        return socket;
    }

    static std::shared_ptr<TcpSocket> CreateSocket(IoContext& _ctx, TcpEndpoint& _ep, bool _no_delay = true,
        bool _reuse_address = true)
    {
        std::shared_ptr<TcpSocket> socket = MakeShared<TcpSocket>(_ctx, _ep);
        // socket을 open하지 않고 조작하면 예외 발생
        boost::system::error_code ec;
        if (!socket->is_open())
            socket->open(asio::ip::tcp::v4(), ec);

        if (ec)
        {
            throw std::runtime_error("failed to create a socket");
        }

        if (_reuse_address)
            SetSocketReusable(*socket);
        if (_no_delay)
            SetSocketNoDelay(*socket);

        return socket;
    }

    static std::shared_ptr<TcpSocket> CreateSocket(std::shared_ptr<IoContext> _ctx, bool _no_delay = true,
        bool _reuse_address = true)
    {
        std::shared_ptr<TcpSocket> socket = MakeShared<TcpSocket>(*_ctx);
        // socket을 open하지 않고 조작하면 예외 발생
        boost::system::error_code ec;
        if (!socket->is_open())
            socket->open(asio::ip::tcp::v4(), ec);

        if (ec)
        {
            throw std::runtime_error("failed to create a socket");
        }

        if (_reuse_address)
            SetSocketReusable(*socket);
        if (_no_delay)
            SetSocketNoDelay(*socket);

        return socket;
    }

    static std::shared_ptr<TcpSocket> CreateSocket(std::shared_ptr<IoContext> _ctx, TcpEndpoint& _ep, bool _no_delay = true,
        bool _reuse_address = true)
    {
        std::shared_ptr<TcpSocket> socket = MakeShared<TcpSocket>(*_ctx, _ep);
        // socket을 open하지 않고 조작하면 예외 발생
        boost::system::error_code ec;
        if (!socket->is_open())
            socket->open(asio::ip::tcp::v4(), ec);

        if (ec)
        {
            throw std::runtime_error("failed to create a socket");
        }

        if (_reuse_address)
            SetSocketReusable(*socket);
        if (_no_delay)
            SetSocketNoDelay(*socket);

        return socket;
    }

    // 이 함수가 반환하는 소켓은 NetHelper의 멤버 IoContext에 귀속됨
    static TcpSocket CreateDummySocket()
    {
        TcpSocket socket(dummyIoCtx);
        // socket을 open하지 않고 조작하면 예외 발생
        boost::system::error_code ec;
        if (!socket.is_open())
            socket.open(asio::ip::tcp::v4(), ec);

        if (ec)
        {
            throw std::runtime_error("failed to create a socket");
        }

        SetSocketReusable(socket);
        SetSocketNoDelay(socket);

        return socket;
    }

    static void SetSocketNoDelay(TcpSocket& socket)
    {
        static const asio::ip::tcp::no_delay no_delay_option(true);
        socket.set_option(no_delay_option);
    }

    static void SetSocketReusable(asio::ip::tcp::socket& socket)
    {
        static const boost::asio::socket_base::reuse_address reuse_address_option(true);
        socket.set_option(reuse_address_option);
    }

    // endpoint
    static TcpEndpoint CreateAnyEndpoint(uint16_t port)
    {
        return TcpEndpoint(boost::asio::ip::address_v4::any(), port);
    }

    static TcpEndpoint CreateLoopbackEndpoint(uint16_t port)
    {
        return TcpEndpoint(boost::asio::ip::make_address("127.0.0.1"), port);
    }

    static TcpEndpoint CreateEndpoint(const std::string& ip, uint16_t port)
    {
        return TcpEndpoint(boost::asio::ip::make_address(ip), port);
    }

    // acceptor
    static TcpAcceptor CreateAcceptor(IoContext& ctx, uint16_t port)
    {
        TcpAcceptor acceptor(ctx, TcpEndpoint(asio::ip::tcp::v4(), port));
        // 소켓 옵션 설정
        static const boost::asio::socket_base::reuse_address reuse_address_option(true);
        acceptor.set_option(reuse_address_option);

        return acceptor;
    }

    static TcpAcceptor CreateAcceptor(boost::asio::io_context& ctx, const std::string& ip, const uint16_t port)
    {
        // IP 주소와 포트로 엔드포인트 생성
        boost::asio::ip::address ip_address = boost::asio::ip::make_address(ip);
        TcpEndpoint endpoint(ip_address, port);

        // Acceptor 생성
        TcpAcceptor acceptor(ctx, endpoint);

        // 소켓 옵션 설정
        static const boost::asio::socket_base::reuse_address reuse_address_option(true);
        acceptor.set_option(reuse_address_option);

        acceptor.bind(endpoint);

        return acceptor;
    }

    static TcpAcceptor CreateAcceptor(IoContext& ctx, const TcpEndpoint& endpoint)
    {
        // Acceptor 생성
        TcpAcceptor acceptor(ctx, endpoint);

        // 소켓 옵션 설정
        static const boost::asio::socket_base::reuse_address reuse_address_option(true);
        acceptor.set_option(reuse_address_option);

        acceptor.bind(endpoint);

        return acceptor;
    }

    static std::shared_ptr<TcpAcceptor> CreateAcceptor(std::shared_ptr<IoContext> _ctx,  TcpEndpoint& _endpoint)
    {
        // Acceptor 생성
        std::shared_ptr<TcpAcceptor> acceptor;

        try {
            acceptor = MakeShared<TcpAcceptor>(*_ctx, _endpoint);
        }
        catch (std::exception& e) {
            std::cout << e.what() << std::endl;
        }

        // 소켓 옵션 설정
        static const boost::asio::socket_base::reuse_address reuse_address_option(true);
        boost::system::error_code ec;
        acceptor->set_option(reuse_address_option, ec);
        if (ec)
        {
            std::wstringstream ss;

            ss << L"Failed to set reuse_address option: " << ec.message().c_str() << std::endl;
            ConsoleLog::WriteStdErr(ss.str());
            throw std::runtime_error("Failed to set reuse_address option");
        }
        // acceptor->bind(_endpoint); // acceptor 생성자에서 bind를 호출하기 때문에 2번 호출 금지

        return acceptor;
    }


    static std::shared_ptr<TcpAcceptor> CreateAcceptor(std::shared_ptr<IoContext> _ctx,
        std::shared_ptr<TcpEndpoint> _endpoint)
    {
        // Acceptor 생성
        std::shared_ptr<TcpAcceptor> acceptor = MakeShared<TcpAcceptor>(*_ctx, *_endpoint);

        // 소켓 옵션 설정
        static const boost::asio::socket_base::reuse_address reuse_address_option(true);
        acceptor->set_option(reuse_address_option);

        acceptor->bind(*_endpoint);

        return acceptor;
    }

private:
    static IoContext dummyIoCtx;
};

inline IoContext NetHelper::dummyIoCtx;
}
