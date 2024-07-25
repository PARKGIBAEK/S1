
#pragma once

#include <boost/mysql.hpp>
#include <boost/mysql/tcp.hpp>
#include <boost/describe.hpp>
#include <string>
#include <iostream>
#include <format>

namespace ORM {

struct item_accessory
{
    int id; // int
    std::string item_name; // varchar(30)
    std::string item_description; // text(65535)
    int item_effect; // int
};

BOOST_DESCRIBE_STRUCT(item_accessory, (), (id, item_name, item_description, item_effect));

class item_accessory_orm
{
public:
    // 데이터베이스 쿼리 호출
    static bool insert(boost::mysql::tcp_connection* conn, int id, std::string item_name, std::string item_description, int item_effect);
    static boost::mysql::results select_all(boost::mysql::tcp_connection* conn);
    static boost::mysql::results select_by_id(boost::mysql::tcp_connection* conn, int id);
    static std::uint64_t update_id_by_id(boost::mysql::tcp_connection* conn, int new_id, int id);
    static std::uint64_t update_item_name_by_id(boost::mysql::tcp_connection* conn, std::string new_item_name, int id);
    static std::uint64_t update_item_description_by_id(boost::mysql::tcp_connection* conn, std::string new_item_description, int id);
    static std::uint64_t update_item_effect_by_id(boost::mysql::tcp_connection* conn, int new_item_effect, int id);
    static std::uint64_t delete_by_id(boost::mysql::tcp_connection* conn, int id);

    // 저장 프로시저 호출
    static bool sp_insert(boost::mysql::tcp_connection* conn, int id, std::string item_name, std::string item_description, int item_effect);
    static boost::mysql::results sp_select_all(boost::mysql::tcp_connection* conn);
    static boost::mysql::results sp_select_all_by_id(boost::mysql::tcp_connection* conn, int id);
    static std::uint64_t sp_set_item_name_by_id(boost::mysql::tcp_connection* conn, std::string new_item_name, int id);
    static std::uint64_t sp_set_item_description_by_id(boost::mysql::tcp_connection* conn, std::string new_item_description, int id);
    static std::uint64_t sp_set_item_effect_by_id(boost::mysql::tcp_connection* conn, int new_item_effect, int id);
    static std::uint64_t sp_delete_by_id(boost::mysql::tcp_connection* conn, int id);
};

// 데이터베이스 쿼리 호출 구현부

inline bool item_accessory_orm::insert(boost::mysql::tcp_connection* conn, int id, std::string item_name, std::string item_description, int item_effect)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("INSERT INTO item_accessory (id, item_name, item_description, item_effect) VALUES ({id}, {item_name}, {item_description}, {item_effect})");
        conn->execute(query, result);
        return result.affected_rows() > 0;
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
        return false;
    }
}
    

inline boost::mysql::results item_accessory_orm::select_all(boost::mysql::tcp_connection* conn)
{
    boost::mysql::results result;
    try
    {
        conn->execute("SELECT * FROM item_accessory", result);
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
    }
    return result;
}
    

inline boost::mysql::results item_accessory_orm::select_by_id(boost::mysql::tcp_connection* conn, int id)
{
    boost::mysql::results result;
    try
    {
        std::string query = std::format("SELECT * FROM item_accessory WHERE id = {id}");
        conn->execute(query, result);
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
    }
    return result;
}
    

inline std::uint64_t item_accessory_orm::update_id_by_id(boost::mysql::tcp_connection* conn, int new_id, int id)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("UPDATE item_accessory SET id = {new_id} WHERE id = {id}");
        conn->execute(query, result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t item_accessory_orm::update_item_name_by_id(boost::mysql::tcp_connection* conn, std::string new_item_name, int id)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("UPDATE item_accessory SET item_name = {new_item_name} WHERE id = {id}");
        conn->execute(query, result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t item_accessory_orm::update_item_description_by_id(boost::mysql::tcp_connection* conn, std::string new_item_description, int id)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("UPDATE item_accessory SET item_description = {new_item_description} WHERE id = {id}");
        conn->execute(query, result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t item_accessory_orm::update_item_effect_by_id(boost::mysql::tcp_connection* conn, int new_item_effect, int id)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("UPDATE item_accessory SET item_effect = {new_item_effect} WHERE id = {id}");
        conn->execute(query, result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t item_accessory_orm::delete_by_id(boost::mysql::tcp_connection* conn, int id)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("DELETE FROM item_accessory WHERE id = {id}");
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

inline bool item_accessory_orm::sp_insert(boost::mysql::tcp_connection* conn, int id, std::string item_name, std::string item_description, int item_effect)
{
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_11(?, ?, ?, ?)");
        boost::mysql::results result;
        conn->execute(stmt.bind(id, item_name, item_description, item_effect), result);
        std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        return result.affected_rows() > 0;
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }
}
    

inline boost::mysql::results item_accessory_orm::sp_select_all(boost::mysql::tcp_connection* conn)
{
    boost::mysql::results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_12()");
        conn->execute(stmt.bind(), result);
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_select_all: " << e.what() << std::endl;
    }
    return result;
}
    

inline boost::mysql::results item_accessory_orm::sp_select_all_by_id(boost::mysql::tcp_connection* conn, int id)
{
    boost::mysql::results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_13(?)");
        conn->execute(stmt.bind(id), result);
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_select_all_by_id: " << e.what() << std::endl;
    }
    return result;
}
    

inline std::uint64_t item_accessory_orm::sp_set_item_name_by_id(boost::mysql::tcp_connection* conn, std::string new_item_name, int id)
{
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_15(?, ?)");
        boost::mysql::results result;
        conn->execute(stmt.bind(new_item_name, id), result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_set_item_name_by_id: " << e.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t item_accessory_orm::sp_set_item_description_by_id(boost::mysql::tcp_connection* conn, std::string new_item_description, int id)
{
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_16(?, ?)");
        boost::mysql::results result;
        conn->execute(stmt.bind(new_item_description, id), result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_set_item_description_by_id: " << e.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t item_accessory_orm::sp_set_item_effect_by_id(boost::mysql::tcp_connection* conn, int new_item_effect, int id)
{
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_17(?, ?)");
        boost::mysql::results result;
        conn->execute(stmt.bind(new_item_effect, id), result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_set_item_effect_by_id: " << e.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t item_accessory_orm::sp_delete_by_id(boost::mysql::tcp_connection* conn, int id)
{
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_18(?)");
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
