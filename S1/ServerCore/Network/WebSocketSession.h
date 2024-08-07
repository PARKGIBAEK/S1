#pragma once
#include <iostream>
#include <boost/beast/core.hpp>
#include <boost/beast/websocket.hpp>
#include <boost/asio/ip/tcp.hpp>

namespace beast = boost::beast;
namespace http = beast::http;
namespace websocket = beast::websocket;
namespace net = boost::asio;
using tcp = boost::asio::ip::tcp;

class WebSocketSession : std::enable_shared_from_this<WebSocketSession>
{
public:
    explicit WebSocketSession(boost::asio::ip::tcp::socket _socket)
        : m_ws(std::move(_socket))
    {
    }

    void Start()
    {
        m_ws.async_accept(
            beast::bind_front_handler(&WebSocketSession::OnAccept,
                shared_from_this()));
    }

    void close()
    {
        m_ws.async_close(websocket::close_code::normal,
            beast::bind_front_handler(
                &WebSocketSession::OnClose,
                shared_from_this()));
    }

private:

    void OnAccept(beast::error_code ec)
    {
        if(ec)
            return Fail(ec,"Accept");
        DoRead();
    }

    void DoRead()
    {
        m_ws.async_read(m_buffer,
            beast::bind_front_handler(&WebSocketSession::OnRead,
                shared_from_this()));
    }

    void OnRead(beast::error_code ec, std::size_t bytesTransferred)
    {
        if(ec)
            return Fail(ec,"Read");
        m_ws.text(m_ws.got_text()); // 텍스트 메시지인지 설정

        // 받은 메시지 문자열로 변환
        std::string received = beast::buffers_to_string(m_buffer.data());
        std::cout<<"Received : "<<received<<std::endl;

        m_ws.async_write(m_buffer.data(),beast::bind_front_handler(&WebSocketSession::OnWrite,shared_from_this()));

    }

    void OnWrite(beast::error_code ec, std::size_t bytesTransferred)
    {
        if(ec)
            return Fail(ec,"Write");
        // 버퍼 비우기
        m_buffer.consume(m_buffer.size());

        // 다음 메시지 읽기
        DoRead();
    }

    void OnClose(beast::error_code ec)
    {
        if (ec)
            return Fail(ec, "close");

        std::cout << "WebSocket connection closed" << std::endl;
        // 여기서 필요한 정리 작업
    }

    void Fail(beast::error_code ec, char const* what)
    {
        std::cerr << what << ": " << ec.message() << "\n";
    }
    websocket::stream<beast::tcp_stream> m_ws;
    beast::flat_buffer m_buffer;
};
