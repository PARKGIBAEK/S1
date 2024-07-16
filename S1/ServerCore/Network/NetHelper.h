#pragma once
#include <boost/asio.hpp>
#include "NetTypes.h"

namespace ServerCore
{
using namespace boost;

class NetHelper
{
public:
	// socket
	static bool IsValidSocket(const TcpSocket& _socket) {
		if (!_socket.is_open())
			return false;

		// 소켓의 원격 엔드포인트를 가져올 때 오류 코드가 발생하는지 확인
		boost::system::error_code ec;
		_socket.remote_endpoint(ec);
		if (ec) 
			return false;
		return true;
	}
	
	static bool IsValidSocket(std::shared_ptr<TcpSocket> _socket) {
		if (!_socket->is_open())
			return false;

		// 소켓의 원격 엔드포인트를 가져올 때 오류 코드가 발생하는지 확인
		boost::system::error_code ec;
		_socket->remote_endpoint(ec);
		if (ec) 
			return false;
		return true;
	}
	
	static bool IsValidSocket(const UdpSocket& _socket) {
		if (!_socket.is_open())
			return false;

		// 소켓의 원격 엔드포인트를 가져올 때 오류 코드가 발생하는지 확인
		boost::system::error_code ec;
		_socket.remote_endpoint(ec);
		if (ec) 
			return false;
		return true;
	}
	static bool IsValidSocket(std::shared_ptr<UdpSocket> _socket) {
		if (!_socket->is_open())
			return false;

		// 소켓의 원격 엔드포인트를 가져올 때 오류 코드가 발생하는지 확인
		boost::system::error_code ec;
		_socket->remote_endpoint(ec);
		if (ec) 
			return false;
		return true;
	}

	static TcpSocket CreateSocket(asio::io_context& _ctx, bool _no_delay = true,
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
		
		if(_reuse_address)
			SetSocketReusable(socket);
		if(_no_delay)
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
	static TcpEndPoint CreateAnyEndpoint(uint16_t port)
	{
		return asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port);
	}

	static TcpEndPoint CreateLoopbackEndpoint(uint16_t port)
	{
		return TcpEndPoint(boost::asio::ip::make_address("127.0.0.1"), port);
	}

	static TcpEndPoint CreateEndpoint(const std::string& ip, uint16_t port)
	{
		return TcpEndPoint(boost::asio::ip::make_address(ip), port);
	}

	// acceptor
	static asio::ip::tcp::acceptor CreateAcceptor(boost::asio::io_context& ctx, uint16_t port)
	{
		asio::ip::tcp::acceptor acceptor(ctx, TcpEndPoint(asio::ip::tcp::v4(), port));
		// 소켓 옵션 설정
		static const boost::asio::socket_base::reuse_address reuse_address_option(true);
		acceptor.set_option(reuse_address_option);

		return acceptor;
	}

	static boost::asio::ip::tcp::acceptor CreateAcceptor(boost::asio::io_context& ctx, const std::string& ip,
	                                                     const uint16_t port)
	{
		// IP 주소와 포트로 엔드포인트 생성
		boost::asio::ip::address ip_address = boost::asio::ip::make_address(ip);
		TcpEndPoint endpoint(ip_address, port);

		// Acceptor 생성
		asio::ip::tcp::acceptor acceptor(ctx, endpoint);

		// 소켓 옵션 설정
		static const boost::asio::socket_base::reuse_address reuse_address_option(true);
		acceptor.set_option(reuse_address_option);

		acceptor.bind(endpoint);

		return acceptor;
	}
};
}