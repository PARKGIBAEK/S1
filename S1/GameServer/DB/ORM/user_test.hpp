
#pragma once

#include <boost/mysql.hpp>
#include <boost/mysql/tcp.hpp>
#include <boost/describe.hpp>
#include <string>
#include <iostream>
#include <format>

namespace ORM {

struct user_test
{
    int id; // int
    std::string username; // varchar(32)
    std::string password; // varchar(32)
    std::string email; // varchar(64)
    boost::mysql::datetime created_at; // timestamp
    boost::mysql::datetime updated_at; // timestamp
};

BOOST_DESCRIBE_STRUCT(user_test, (), (id, username, password, email, created_at, updated_at));

class user_test_orm
{
public:
    // 데이터베이스 쿼리 호출
    static bool insert(boost::mysql::tcp_connection* conn, std::string username, std::string password, std::string email, boost::mysql::datetime created_at, boost::mysql::datetime updated_at);
    static boost::mysql::results select_all(boost::mysql::tcp_connection* conn);
    static boost::mysql::results select_by_email(boost::mysql::tcp_connection* conn, std::string email);
    static boost::mysql::results select_by_id(boost::mysql::tcp_connection* conn, int id);
    static std::uint64_t update_username_by_email(boost::mysql::tcp_connection* conn, std::string new_username, std::string email);
    static std::uint64_t update_username_by_id(boost::mysql::tcp_connection* conn, std::string new_username, int id);
    static std::uint64_t update_password_by_email(boost::mysql::tcp_connection* conn, std::string new_password, std::string email);
    static std::uint64_t update_password_by_id(boost::mysql::tcp_connection* conn, std::string new_password, int id);
    static std::uint64_t update_email_by_email(boost::mysql::tcp_connection* conn, std::string new_email, std::string email);
    static std::uint64_t update_email_by_id(boost::mysql::tcp_connection* conn, std::string new_email, int id);
    static std::uint64_t update_created_at_by_email(boost::mysql::tcp_connection* conn, boost::mysql::datetime new_created_at, std::string email);
    static std::uint64_t update_created_at_by_id(boost::mysql::tcp_connection* conn, boost::mysql::datetime new_created_at, int id);
    static std::uint64_t update_updated_at_by_email(boost::mysql::tcp_connection* conn, boost::mysql::datetime new_updated_at, std::string email);
    static std::uint64_t update_updated_at_by_id(boost::mysql::tcp_connection* conn, boost::mysql::datetime new_updated_at, int id);
    static std::uint64_t delete_by_email(boost::mysql::tcp_connection* conn, std::string email);
    static std::uint64_t delete_by_id(boost::mysql::tcp_connection* conn, int id);

    // 저장 프로시저 호출
    static bool sp_insert(boost::mysql::tcp_connection* conn, std::string username, std::string password, std::string email, boost::mysql::datetime created_at);
    static boost::mysql::results sp_select_all(boost::mysql::tcp_connection* conn);
    static boost::mysql::results sp_select_all_by_email(boost::mysql::tcp_connection* conn, std::string email);
    static boost::mysql::results sp_select_all_by_id(boost::mysql::tcp_connection* conn, int id);
    static std::uint64_t sp_set_username_by_email(boost::mysql::tcp_connection* conn, std::string new_username, std::string email);
    static std::uint64_t sp_set_username_by_id(boost::mysql::tcp_connection* conn, std::string new_username, int id);
    static std::uint64_t sp_set_password_by_email(boost::mysql::tcp_connection* conn, std::string new_password, std::string email);
    static std::uint64_t sp_set_password_by_id(boost::mysql::tcp_connection* conn, std::string new_password, int id);
    static std::uint64_t sp_set_email_by_email(boost::mysql::tcp_connection* conn, std::string new_email, std::string email);
    static std::uint64_t sp_set_email_by_id(boost::mysql::tcp_connection* conn, std::string new_email, int id);
    static std::uint64_t sp_set_created_at_by_email(boost::mysql::tcp_connection* conn, boost::mysql::datetime new_created_at, std::string email);
    static std::uint64_t sp_set_created_at_by_id(boost::mysql::tcp_connection* conn, boost::mysql::datetime new_created_at, int id);
    static std::uint64_t sp_delete_by_email(boost::mysql::tcp_connection* conn, std::string email);
    static std::uint64_t sp_delete_by_id(boost::mysql::tcp_connection* conn, int id);
};

// 데이터베이스 쿼리 호출 구현부

inline bool user_test_orm::insert(boost::mysql::tcp_connection* conn, std::string username, std::string password, std::string email, boost::mysql::datetime created_at, boost::mysql::datetime updated_at)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("INSERT INTO user_test (username, password, email, created_at, updated_at) VALUES ({username}, {password}, {email}, {created_at}, {updated_at})");
        conn->execute(query, result);
        return result.affected_rows() > 0;
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
        return false;
    }
}
    

inline boost::mysql::results user_test_orm::select_all(boost::mysql::tcp_connection* conn)
{
    boost::mysql::results result;
    try
    {
        conn->execute("SELECT * FROM user_test", result);
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
    }
    return result;
}
    

inline boost::mysql::results user_test_orm::select_by_email(boost::mysql::tcp_connection* conn, std::string email)
{
    boost::mysql::results result;
    try
    {
        std::string query = std::format("SELECT * FROM user_test WHERE email = {email}");
        conn->execute(query, result);
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
    }
    return result;
}
    

inline boost::mysql::results user_test_orm::select_by_id(boost::mysql::tcp_connection* conn, int id)
{
    boost::mysql::results result;
    try
    {
        std::string query = std::format("SELECT * FROM user_test WHERE id = {id}");
        conn->execute(query, result);
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
    }
    return result;
}
    

inline std::uint64_t user_test_orm::update_username_by_email(boost::mysql::tcp_connection* conn, std::string new_username, std::string email)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("UPDATE user_test SET username = {new_username} WHERE email = {email}");
        conn->execute(query, result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_test_orm::update_username_by_id(boost::mysql::tcp_connection* conn, std::string new_username, int id)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("UPDATE user_test SET username = {new_username} WHERE id = {id}");
        conn->execute(query, result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_test_orm::update_password_by_email(boost::mysql::tcp_connection* conn, std::string new_password, std::string email)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("UPDATE user_test SET password = {new_password} WHERE email = {email}");
        conn->execute(query, result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_test_orm::update_password_by_id(boost::mysql::tcp_connection* conn, std::string new_password, int id)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("UPDATE user_test SET password = {new_password} WHERE id = {id}");
        conn->execute(query, result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_test_orm::update_email_by_email(boost::mysql::tcp_connection* conn, std::string new_email, std::string email)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("UPDATE user_test SET email = {new_email} WHERE email = {email}");
        conn->execute(query, result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_test_orm::update_email_by_id(boost::mysql::tcp_connection* conn, std::string new_email, int id)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("UPDATE user_test SET email = {new_email} WHERE id = {id}");
        conn->execute(query, result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_test_orm::update_created_at_by_email(boost::mysql::tcp_connection* conn, boost::mysql::datetime new_created_at, std::string email)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("UPDATE user_test SET created_at = {new_created_at} WHERE email = {email}");
        conn->execute(query, result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_test_orm::update_created_at_by_id(boost::mysql::tcp_connection* conn, boost::mysql::datetime new_created_at, int id)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("UPDATE user_test SET created_at = {new_created_at} WHERE id = {id}");
        conn->execute(query, result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_test_orm::update_updated_at_by_email(boost::mysql::tcp_connection* conn, boost::mysql::datetime new_updated_at, std::string email)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("UPDATE user_test SET updated_at = {new_updated_at} WHERE email = {email}");
        conn->execute(query, result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_test_orm::update_updated_at_by_id(boost::mysql::tcp_connection* conn, boost::mysql::datetime new_updated_at, int id)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("UPDATE user_test SET updated_at = {new_updated_at} WHERE id = {id}");
        conn->execute(query, result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_test_orm::delete_by_email(boost::mysql::tcp_connection* conn, std::string email)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("DELETE FROM user_test WHERE email = {email}");
        conn->execute(query, result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_test_orm::delete_by_id(boost::mysql::tcp_connection* conn, int id)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("DELETE FROM user_test WHERE id = {id}");
        conn->execute(query, result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
        return 0;
    }
}
    

// 저장 프로시저 호출 구현부

inline bool user_test_orm::sp_insert(boost::mysql::tcp_connection* conn, std::string username, std::string password, std::string email, boost::mysql::datetime created_at)
{
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_116(?, ?, ?, ?)");
        boost::mysql::results result;
        conn->execute(stmt.bind(username, password, email, created_at), result);
        std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        return result.affected_rows() > 0;
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }
}
    

inline boost::mysql::results user_test_orm::sp_select_all(boost::mysql::tcp_connection* conn)
{
    boost::mysql::results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_117()");
        conn->execute(stmt.bind(), result);
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_select_all: " << e.what() << std::endl;
    }
    return result;
}
    

inline boost::mysql::results user_test_orm::sp_select_all_by_email(boost::mysql::tcp_connection* conn, std::string email)
{
    boost::mysql::results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_118(?)");
        conn->execute(stmt.bind(email), result);
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_select_all_by_email: " << e.what() << std::endl;
    }
    return result;
}
    

inline boost::mysql::results user_test_orm::sp_select_all_by_id(boost::mysql::tcp_connection* conn, int id)
{
    boost::mysql::results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_119(?)");
        conn->execute(stmt.bind(id), result);
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_select_all_by_id: " << e.what() << std::endl;
    }
    return result;
}
    

inline std::uint64_t user_test_orm::sp_set_username_by_email(boost::mysql::tcp_connection* conn, std::string new_username, std::string email)
{
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_120(?, ?)");
        boost::mysql::results result;
        conn->execute(stmt.bind(new_username, email), result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_set_username_by_email: " << e.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_test_orm::sp_set_username_by_id(boost::mysql::tcp_connection* conn, std::string new_username, int id)
{
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_121(?, ?)");
        boost::mysql::results result;
        conn->execute(stmt.bind(new_username, id), result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_set_username_by_id: " << e.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_test_orm::sp_set_password_by_email(boost::mysql::tcp_connection* conn, std::string new_password, std::string email)
{
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_122(?, ?)");
        boost::mysql::results result;
        conn->execute(stmt.bind(new_password, email), result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_set_password_by_email: " << e.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_test_orm::sp_set_password_by_id(boost::mysql::tcp_connection* conn, std::string new_password, int id)
{
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_123(?, ?)");
        boost::mysql::results result;
        conn->execute(stmt.bind(new_password, id), result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_set_password_by_id: " << e.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_test_orm::sp_set_email_by_email(boost::mysql::tcp_connection* conn, std::string new_email, std::string email)
{
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_124(?, ?)");
        boost::mysql::results result;
        conn->execute(stmt.bind(new_email, email), result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_set_email_by_email: " << e.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_test_orm::sp_set_email_by_id(boost::mysql::tcp_connection* conn, std::string new_email, int id)
{
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_125(?, ?)");
        boost::mysql::results result;
        conn->execute(stmt.bind(new_email, id), result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_set_email_by_id: " << e.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_test_orm::sp_set_created_at_by_email(boost::mysql::tcp_connection* conn, boost::mysql::datetime new_created_at, std::string email)
{
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_126(?, ?)");
        boost::mysql::results result;
        conn->execute(stmt.bind(new_created_at, email), result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_set_created_at_by_email: " << e.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_test_orm::sp_set_created_at_by_id(boost::mysql::tcp_connection* conn, boost::mysql::datetime new_created_at, int id)
{
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_127(?, ?)");
        boost::mysql::results result;
        conn->execute(stmt.bind(new_created_at, id), result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_set_created_at_by_id: " << e.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_test_orm::sp_delete_by_email(boost::mysql::tcp_connection* conn, std::string email)
{
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_130(?)");
        boost::mysql::results result;
        conn->execute(stmt.bind(email), result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_delete_by_email: " << e.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_test_orm::sp_delete_by_id(boost::mysql::tcp_connection* conn, int id)
{
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_131(?)");
        boost::mysql::results result;
        conn->execute(stmt.bind(id), result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_delete_by_id: " << e.what() << std::endl;
        return 0;
    }
}
    

} // namespace ORM
