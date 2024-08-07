#pragma once

#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/ssl.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/ssl/error.hpp>
#include <boost/asio/ssl/stream.hpp>
#include <string>
#include <future>

namespace beast = boost::beast;
namespace http = beast::http;
namespace net = boost::asio;
namespace ssl = net::ssl;
using tcp = net::ip::tcp;

class HttpClient {
public:
    HttpClient(const std::string& host, const std::string& port);
    ~HttpClient();

    std::future<std::string> SendRequest(const std::string& target,
                                         const std::string& method,
                                         const std::string& body = "");

private:
    std::string host_;
    std::string port_;
    net::io_context ioc_;
    ssl::context ctx_;
    std::unique_ptr<beast::ssl_stream<beast::tcp_stream>> stream_;

    void connect();
    void disconnect();
};
