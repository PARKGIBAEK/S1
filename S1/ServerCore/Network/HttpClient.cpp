#include "pch.h"
#include "HttpClient.h"
#include <iostream>

HttpClient::HttpClient(const std::string& host, const std::string& port)
    : m_Host(host), m_Port(port), m_Ctx(ssl::context::tlsv12_client)
{
    m_Ctx.set_verify_mode(ssl::verify_peer);
    m_Ctx.set_default_verify_paths();

    // HTTP/2 지원을 위한 ALPN 설정
    SSL_CTX_set_alpn_protos(m_Ctx.native_handle(), reinterpret_cast<const unsigned char*>("\x02h2\x08http/1.1"), 6);

    connect();
}

HttpClient::~HttpClient()
{
    disconnect();
}

void HttpClient::connect()
{
    tcp::resolver resolver(m_Ioc);
    auto const results = resolver.resolve(m_Host, m_Port);

    stream_ = std::make_unique<beast::ssl_stream<beast::tcp_stream>>(m_Ioc, m_Ctx);

    // SNI 설정
    if (!SSL_set_tlsext_host_name(stream_->native_handle(), m_Host.c_str()))
    {
        beast::error_code ec{static_cast<int>(::ERR_get_error()), net::error::get_ssl_category()};
        throw beast::system_error{ec};
    }

    beast::get_lowest_layer(*stream_).connect(results);
    stream_->handshake(ssl::stream_base::client);
}

void HttpClient::disconnect()
{
    beast::error_code ec;
    stream_->shutdown(ec);
    if (ec && ec != beast::errc::not_connected)
        throw beast::system_error{ec};
}

std::future<std::string> HttpClient::SendRequest(const std::string& method,
                                                 const std::string& target,
                                                 const std::string& body)
{
    return std::async(std::launch::async, [this, method, target, body]()
    {
        try
        {
            http::request<http::string_body> req{http::string_to_verb(method), target, 11};
            req.set(http::field::host, m_Host);
            req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);

            if (!body.empty())
            {
                req.set(http::field::content_type, "application/json");
                req.body() = body;
                req.prepare_payload();
            }

            http::write(*stream_, req);

            beast::flat_buffer buffer;
            http::response<http::dynamic_body> res;
            http::read(*stream_, buffer, res);

            return beast::buffers_to_string(res.body().data());
        }
        catch (std::exception const& e)
        {
            std::cerr << "Error: " << e.what() << std::endl;
            return std::string("Error: ") + e.what();
        }
    });
}
