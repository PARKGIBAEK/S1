#pragma once
#include "pch.h"
#include <boost/asio.hpp>
#include <boost/lockfree/queue.hpp>

namespace ServerCore
{

using namespace boost;

using Tcp = asio::ip::tcp;
using Udp = asio::ip::udp;
using TcpSocket = asio::ip::tcp::socket;
using UdpSocket = asio::ip::udp::socket;
using TcpEndpoint = asio::ip::tcp::endpoint;
using UdpEndpoint = asio::ip::udp::endpoint;
using TcpAcceptor = asio::ip::tcp::acceptor;
using IoContext = asio::io_context;
using IoService = asio::io_context;

template <typename T>
using LockfreeQueue = lockfree::queue<T>;

template<typename T>
using LockfreeQueueRef = std::shared_ptr<LockfreeQueue<T>>;
}
