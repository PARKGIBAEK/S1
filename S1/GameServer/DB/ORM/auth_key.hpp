
#pragma once

#include <boost/mysql.hpp>
#include <boost/mysql/tcp.hpp>
#include <boost/describe.hpp>
#include <string>
#include <iostream>
#include <format>

namespace ORM {

struct auth_key
{
    int id; // int
    std::string key_value; // varchar(256)
    boost::mysql::datetime created_at; // timestamp
};

BOOST_DESCRIBE_STRUCT(auth_key, (), (id, key_value, created_at));

class auth_key_orm
{
public:
    // 데이터베이스 쿼리 호출
    static bool insert(boost::mysql::tcp_connection* conn, std::string key_value, boost::mysql::datetime created_at);
    static boost::mysql::results select_all(boost::mysql::tcp_connection* conn);
    static boost::mysql::results select_by_key_value(boost::mysql::tcp_connection* conn, std::string key_value);
    static boost::mysql::results select_by_id(boost::mysql::tcp_connection* conn, int id);
    static std::uint64_t update_key_value_by_key_value(boost::mysql::tcp_connection* conn, std::string new_key_value, std::string key_value);
    static std::uint64_t update_key_value_by_id(boost::mysql::tcp_connection* conn, std::string new_key_value, int id);
    static std::uint64_t update_created_at_by_key_value(boost::mysql::tcp_connection* conn, boost::mysql::datetime new_created_at, std::string key_value);
    static std::uint64_t update_created_at_by_id(boost::mysql::tcp_connection* conn, boost::mysql::datetime new_created_at, int id);
    static std::uint64_t delete_by_key_value(boost::mysql::tcp_connection* conn, std::string key_value);
    static std::uint64_t delete_by_id(boost::mysql::tcp_connection* conn, int id);

    // 저장 프로시저 호출
    static bool sp_insert(boost::mysql::tcp_connection* conn, std::string key_value, boost::mysql::datetime created_at);
    static boost::mysql::results sp_select_all(boost::mysql::tcp_connection* conn);
    static boost::mysql::results sp_select_all_by_key_value(boost::mysql::tcp_connection* conn, std::string key_value);
    static boost::mysql::results sp_select_all_by_id(boost::mysql::tcp_connection* conn, int id);
    static std::uint64_t sp_set_key_value_by_key_value(boost::mysql::tcp_connection* conn, std::string new_key_value, std::string key_value);
    static std::uint64_t sp_set_key_value_by_id(boost::mysql::tcp_connection* conn, std::string new_key_value, int id);
    static std::uint64_t sp_set_created_at_by_key_value(boost::mysql::tcp_connection* conn, boost::mysql::datetime new_created_at, std::string key_value);
    static std::uint64_t sp_set_created_at_by_id(boost::mysql::tcp_connection* conn, boost::mysql::datetime new_created_at, int id);
    static std::uint64_t sp_delete_by_key_value(boost::mysql::tcp_connection* conn, std::string key_value);
    static std::uint64_t sp_delete_by_id(boost::mysql::tcp_connection* conn, int id);
};

// 데이터베이스 쿼리 호출 구현부

inline bool auth_key_orm::insert(boost::mysql::tcp_connection* conn, std::string key_value, boost::mysql::datetime created_at)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("INSERT INTO auth_key (key_value, created_at) VALUES ({key_value}, {created_at})");
        conn->execute(query, result);
        return result.affected_rows() > 0;
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
        return false;
    }
}
    

inline boost::mysql::results auth_key_orm::select_all(boost::mysql::tcp_connection* conn)
{
    boost::mysql::results result;
    try
    {
        conn->execute("SELECT * FROM auth_key", result);
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
    }
    return result;
}
    

inline boost::mysql::results auth_key_orm::select_by_key_value(boost::mysql::tcp_connection* conn, std::string key_value)
{
    boost::mysql::results result;
    try
    {
        std::string query = std::format("SELECT * FROM auth_key WHERE key_value = {key_value}");
        conn->execute(query, result);
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
    }
    return result;
}
    

inline boost::mysql::results auth_key_orm::select_by_id(boost::mysql::tcp_connection* conn, int id)
{
    boost::mysql::results result;
    try
    {
        std::string query = std::format("SELECT * FROM auth_key WHERE id = {id}");
        conn->execute(query, result);
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
    }
    return result;
}
    

inline std::uint64_t auth_key_orm::update_key_value_by_key_value(boost::mysql::tcp_connection* conn, std::string new_key_value, std::string key_value)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("UPDATE auth_key SET key_value = {new_key_value} WHERE key_value = {key_value}");
        conn->execute(query, result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t auth_key_orm::update_key_value_by_id(boost::mysql::tcp_connection* conn, std::string new_key_value, int id)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("UPDATE auth_key SET key_value = {new_key_value} WHERE id = {id}");
        conn->execute(query, result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t auth_key_orm::update_created_at_by_key_value(boost::mysql::tcp_connection* conn, boost::mysql::datetime new_created_at, std::string key_value)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("UPDATE auth_key SET created_at = {new_created_at} WHERE key_value = {key_value}");
        conn->execute(query, result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t auth_key_orm::update_created_at_by_id(boost::mysql::tcp_connection* conn, boost::mysql::datetime new_created_at, int id)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("UPDATE auth_key SET created_at = {new_created_at} WHERE id = {id}");
        conn->execute(query, result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t auth_key_orm::delete_by_key_value(boost::mysql::tcp_connection* conn, std::string key_value)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("DELETE FROM auth_key WHERE key_value = {key_value}");
        conn->execute(query, result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t auth_key_orm::delete_by_id(boost::mysql::tcp_connection* conn, int id)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("DELETE FROM auth_key WHERE id = {id}");
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

inline bool auth_key_orm::sp_insert(boost::mysql::tcp_connection* conn, std::string key_value, boost::mysql::datetime created_at)
{
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_1(?, ?)");
        boost::mysql::results result;
        conn->execute(stmt.bind(key_value, created_at), result);
        std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        return result.affected_rows() > 0;
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }
}
    

inline boost::mysql::results auth_key_orm::sp_select_all(boost::mysql::tcp_connection* conn)
{
    boost::mysql::results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_2()");
        conn->execute(stmt.bind(), result);
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_select_all: " << e.what() << std::endl;
    }
    return result;
}
    

inline boost::mysql::results auth_key_orm::sp_select_all_by_key_value(boost::mysql::tcp_connection* conn, std::string key_value)
{
    boost::mysql::results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_3(?)");
        conn->execute(stmt.bind(key_value), result);
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_select_all_by_key_value: " << e.what() << std::endl;
    }
    return result;
}
    

inline boost::mysql::results auth_key_orm::sp_select_all_by_id(boost::mysql::tcp_connection* conn, int id)
{
    boost::mysql::results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_4(?)");
        conn->execute(stmt.bind(id), result);
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_select_all_by_id: " << e.what() << std::endl;
    }
    return result;
}
    

inline std::uint64_t auth_key_orm::sp_set_key_value_by_key_value(boost::mysql::tcp_connection* conn, std::string new_key_value, std::string key_value)
{
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_5(?, ?)");
        boost::mysql::results result;
        conn->execute(stmt.bind(new_key_value, key_value), result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_set_key_value_by_key_value: " << e.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t auth_key_orm::sp_set_key_value_by_id(boost::mysql::tcp_connection* conn, std::string new_key_value, int id)
{
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_6(?, ?)");
        boost::mysql::results result;
        conn->execute(stmt.bind(new_key_value, id), result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_set_key_value_by_id: " << e.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t auth_key_orm::sp_set_created_at_by_key_value(boost::mysql::tcp_connection* conn, boost::mysql::datetime new_created_at, std::string key_value)
{
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_7(?, ?)");
        boost::mysql::results result;
        conn->execute(stmt.bind(new_created_at, key_value), result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_set_created_at_by_key_value: " << e.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t auth_key_orm::sp_set_created_at_by_id(boost::mysql::tcp_connection* conn, boost::mysql::datetime new_created_at, int id)
{
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_8(?, ?)");
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
    

inline std::uint64_t auth_key_orm::sp_delete_by_key_value(boost::mysql::tcp_connection* conn, std::string key_value)
{
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_9(?)");
        boost::mysql::results result;
        conn->execute(stmt.bind(key_value), result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_delete_by_key_value: " << e.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t auth_key_orm::sp_delete_by_id(boost::mysql::tcp_connection* conn, int id)
{
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10(?)");
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
