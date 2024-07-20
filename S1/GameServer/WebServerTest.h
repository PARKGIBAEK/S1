// #include <boost/beast/core.hpp>
// #include <boost/beast/http.hpp>
// #include <boost/beast/version.hpp>
// #include <boost/asio/ip/tcp.hpp>
// #include <boost/asio/strand.hpp>
// #include <boost/mysql/connection.hpp>
// #include <boost/mysql/results.hpp>
// #include <boost/config.hpp>
// #include <iostream>
// #include <string>
// #include <memory>
// #include <boost/mysql/tcp.hpp>
//
// namespace beast = boost::beast;
// namespace http = beast::http;
// namespace net = boost::asio;
// namespace mysql = boost::mysql;
// using tcp = boost::asio::ip::tcp;
//
// // 데이터베이스 연결 함수
// mysql::tcp_connection connect_to_db(net::io_context& ioc) {
//     mysql::tcp_connection conn(ioc);
//     mysql::connect_params params;
//     params.server_address = "localhost";
//     params.username = "your_username";
//     params.password = "your_password";
//     params.database = "your_database";
//
//     conn.connect(params);
//     return conn;
// }
//
// // 비밀번호 해싱 함수
// std::string hash_password(const std::string& password) {
//     return boost::crypto::hash<boost::crypto::sha256>(password);
// }
//
// // HTTP 요청 처리 클래스
// class http_connection : public std::enable_shared_from_this<http_connection>
// {
//     tcp::socket m_Socket;
//     beast::flat_buffer m_Buffer;
//     http::request<http::string_body> m_Req;
//     http::response<http::string_body> m_Res;
//     mysql::tcp_connection& m_DbConn;
//
// public:
//     http_connection(tcp::socket socket, mysql::tcp_connection& db_conn)
//         : m_Socket(std::move(socket)), m_DbConn(db_conn) {}
//
//     void start() {
//         read_request();
//     }
//
//     void read_request() {
//         auto self = shared_from_this();
//         http::async_read(m_Socket, m_Buffer, m_Req,
//             [self](beast::error_code ec, std::size_t) {
//                 if (!ec) self->process_request();
//             });
//     }
//
//     void process_request() {
//         if (m_Req.method() == http::verb::post) {
//             if (m_Req.target() == "/register") {
//                 handle_register();
//             } else if (m_Req.target() == "/login") {
//                 handle_login();
//             }
//         }
//         write_response();
//     }
//
//     void handle_register() {
//         // 요청 본문에서 사용자 데이터 추출
//         std::string username = /* extract username from req_.body() */;
//         std::string password = /* extract password from req_.body() */;
//
//         std::string hashed_password = hash_password(password);
//
//         try {
//             mysql::results result;
//             m_DbConn.execute("INSERT INTO users (username, password) VALUES (?, ?)",
//                               result, username, hashed_password);
//             m_Res.result(http::status::created);
//             m_Res.set(http::field::content_type, "text/plain");
//             m_Res.body() = "Registration successful";
//         } catch (const mysql::error_code& e) {
//             m_Res.result(http::status::internal_server_error);
//             m_Res.set(http::field::content_type, "text/plain");
//             m_Res.body() = "Registration failed: " + std::string(e.what());
//         }
//     }
//
//     void handle_login() {
//         // 요청 본문에서 사용자 데이터 추출
//         std::string username = /* extract username from req_.body() */;
//         std::string password = /* extract password from req_.body() */;
//
//         std::string hashed_password = hash_password(password);
//
//         try {
//             mysql::results result;
//             m_DbConn.execute("SELECT * FROM users WHERE username = ? AND password = ?",
//                               result, username, hashed_password);
//             if (result.rows().size() > 0) {
//                 m_Res.result(http::status::ok);
//                 m_Res.set(http::field::content_type, "text/plain");
//                 m_Res.body() = "Login successful";
//             } else {
//                 m_Res.result(http::status::unauthorized);
//                 m_Res.set(http::field::content_type, "text/plain");
//                 m_Res.body() = "Login failed: Invalid credentials";
//             }
//         } catch (const mysql::error_code& e) {
//             m_Res.result(http::status::internal_server_error);
//             m_Res.set(http::field::content_type, "text/plain");
//             m_Res.body() = "Login failed: " + std::string(e.what());
//         }
//     }
//
//     void write_response() {
//         auto self = shared_from_this();
//         m_Res.version(m_Req.version());
//         m_Res.keep_alive(false);
//         http::async_write(m_Socket, m_Res,
//             [self](beast::error_code ec, std::size_t) {
//                 self->m_Socket.shutdown(tcp::socket::shutdown_send, ec);
//             });
//     }
// };
//
// // HTTP 서버 클래스
// class http_server {
//     net::io_context& ioc_;
//     tcp::acceptor acceptor_;
//     mysql::tcp_connection db_conn_;
//
// public:
//     http_server(net::io_context& ioc, unsigned short port)
//         : ioc_(ioc), acceptor_(ioc, {tcp::v4(), port}), db_conn_(connect_to_db(ioc)) {}
//
//     void run() {
//         accept();
//     }
//
// private:
//     void accept() {
//         acceptor_.async_accept(ioc_,
//             [this](beast::error_code ec, tcp::socket socket) {
//                 if (!ec)
//                     {
//                     std::make_shared<http_connection>(std::move(socket), db_conn_)->start();
//                 }
//                 accept();
//             });
//     }
// };
//
// int main() {
//     try {
//         net::io_context ioc{1};
//         unsigned short port = 8080;
//
//         http_server server{ioc, port};
//         server.run();
//         ioc.run();
//     } catch (const std::exception& e) {
//         std::cerr << "Error: " << e.what() << std::endl;
//         return EXIT_FAILURE;
//     }
// }