#pragma once
#include <boost/asio.hpp>

namespace ServerCore
{

using namespace boost;

using TcpSocket = asio::ip::tcp::socket;
using UdpSocket = asio::ip::udp::socket;
using TcpEndPoint = asio::ip::tcp::endpoint;
using UdpEndPoint = asio::ip::udp::endpoint;
}