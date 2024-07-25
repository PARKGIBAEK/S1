
#pragma once

#include <boost/mysql.hpp>
#include <boost/mysql/tcp.hpp>
#include <boost/describe.hpp>
#include <string>
#include <iostream>
#include <format>

namespace ORM {

struct user_inventory
{
    int id; // int
    int user_character_id; // int
    int item_id; // int
    int item_quantity; // int
    boost::mysql::datetime created_at; // timestamp
    boost::mysql::datetime updated_at; // timestamp
};

BOOST_DESCRIBE_STRUCT(user_inventory, (), (id, user_character_id, item_id, item_quantity, created_at, updated_at));

class user_inventory_orm
{
public:
    // 데이터베이스 쿼리 호출
    static bool insert(boost::mysql::tcp_connection* conn, int user_character_id, int item_id, int item_quantity, boost::mysql::datetime created_at, boost::mysql::datetime updated_at);
    static boost::mysql::results select_all(boost::mysql::tcp_connection* conn);
    static boost::mysql::results select_by_user_character_id(boost::mysql::tcp_connection* conn, int user_character_id);
    static boost::mysql::results select_by_id(boost::mysql::tcp_connection* conn, int id);
    static std::uint64_t update_user_character_id_by_user_character_id(boost::mysql::tcp_connection* conn, int new_user_character_id, int user_character_id);
    static std::uint64_t update_user_character_id_by_id(boost::mysql::tcp_connection* conn, int new_user_character_id, int id);
    static std::uint64_t update_item_id_by_user_character_id(boost::mysql::tcp_connection* conn, int new_item_id, int user_character_id);
    static std::uint64_t update_item_id_by_id(boost::mysql::tcp_connection* conn, int new_item_id, int id);
    static std::uint64_t update_item_quantity_by_user_character_id(boost::mysql::tcp_connection* conn, int new_item_quantity, int user_character_id);
    static std::uint64_t update_item_quantity_by_id(boost::mysql::tcp_connection* conn, int new_item_quantity, int id);
    static std::uint64_t update_created_at_by_user_character_id(boost::mysql::tcp_connection* conn, boost::mysql::datetime new_created_at, int user_character_id);
    static std::uint64_t update_created_at_by_id(boost::mysql::tcp_connection* conn, boost::mysql::datetime new_created_at, int id);
    static std::uint64_t update_updated_at_by_user_character_id(boost::mysql::tcp_connection* conn, boost::mysql::datetime new_updated_at, int user_character_id);
    static std::uint64_t update_updated_at_by_id(boost::mysql::tcp_connection* conn, boost::mysql::datetime new_updated_at, int id);
    static std::uint64_t delete_by_user_character_id(boost::mysql::tcp_connection* conn, int user_character_id);
    static std::uint64_t delete_by_id(boost::mysql::tcp_connection* conn, int id);

    // 저장 프로시저 호출
    static bool sp_insert(boost::mysql::tcp_connection* conn, int user_character_id, int item_id, int item_quantity, boost::mysql::datetime created_at);
    static boost::mysql::results sp_select_all(boost::mysql::tcp_connection* conn);
    static boost::mysql::results sp_select_all_by_user_character_id(boost::mysql::tcp_connection* conn, int user_character_id);
    static boost::mysql::results sp_select_all_by_id(boost::mysql::tcp_connection* conn, int id);
    static std::uint64_t sp_set_user_character_id_by_user_character_id(boost::mysql::tcp_connection* conn, int new_user_character_id, int user_character_id);
    static std::uint64_t sp_set_user_character_id_by_id(boost::mysql::tcp_connection* conn, int new_user_character_id, int id);
    static std::uint64_t sp_set_item_id_by_user_character_id(boost::mysql::tcp_connection* conn, int new_item_id, int user_character_id);
    static std::uint64_t sp_set_item_id_by_id(boost::mysql::tcp_connection* conn, int new_item_id, int id);
    static std::uint64_t sp_set_item_quantity_by_user_character_id(boost::mysql::tcp_connection* conn, int new_item_quantity, int user_character_id);
    static std::uint64_t sp_set_item_quantity_by_id(boost::mysql::tcp_connection* conn, int new_item_quantity, int id);
    static std::uint64_t sp_set_created_at_by_user_character_id(boost::mysql::tcp_connection* conn, boost::mysql::datetime new_created_at, int user_character_id);
    static std::uint64_t sp_set_created_at_by_id(boost::mysql::tcp_connection* conn, boost::mysql::datetime new_created_at, int id);
    static std::uint64_t sp_delete_by_user_character_id(boost::mysql::tcp_connection* conn, int user_character_id);
    static std::uint64_t sp_delete_by_id(boost::mysql::tcp_connection* conn, int id);
};

// 데이터베이스 쿼리 호출 구현부

inline bool user_inventory_orm::insert(boost::mysql::tcp_connection* conn, int user_character_id, int item_id, int item_quantity, boost::mysql::datetime created_at, boost::mysql::datetime updated_at)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("INSERT INTO user_inventory (user_character_id, item_id, item_quantity, created_at, updated_at) VALUES ({user_character_id}, {item_id}, {item_quantity}, {created_at}, {updated_at})");
        conn->execute(query, result);
        return result.affected_rows() > 0;
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
        return false;
    }
}
    

inline boost::mysql::results user_inventory_orm::select_all(boost::mysql::tcp_connection* conn)
{
    boost::mysql::results result;
    try
    {
        conn->execute("SELECT * FROM user_inventory", result);
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
    }
    return result;
}
    

inline boost::mysql::results user_inventory_orm::select_by_user_character_id(boost::mysql::tcp_connection* conn, int user_character_id)
{
    boost::mysql::results result;
    try
    {
        std::string query = std::format("SELECT * FROM user_inventory WHERE user_character_id = {user_character_id}");
        conn->execute(query, result);
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
    }
    return result;
}
    

inline boost::mysql::results user_inventory_orm::select_by_id(boost::mysql::tcp_connection* conn, int id)
{
    boost::mysql::results result;
    try
    {
        std::string query = std::format("SELECT * FROM user_inventory WHERE id = {id}");
        conn->execute(query, result);
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
    }
    return result;
}
    

inline std::uint64_t user_inventory_orm::update_user_character_id_by_user_character_id(boost::mysql::tcp_connection* conn, int new_user_character_id, int user_character_id)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("UPDATE user_inventory SET user_character_id = {new_user_character_id} WHERE user_character_id = {user_character_id}");
        conn->execute(query, result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_inventory_orm::update_user_character_id_by_id(boost::mysql::tcp_connection* conn, int new_user_character_id, int id)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("UPDATE user_inventory SET user_character_id = {new_user_character_id} WHERE id = {id}");
        conn->execute(query, result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_inventory_orm::update_item_id_by_user_character_id(boost::mysql::tcp_connection* conn, int new_item_id, int user_character_id)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("UPDATE user_inventory SET item_id = {new_item_id} WHERE user_character_id = {user_character_id}");
        conn->execute(query, result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_inventory_orm::update_item_id_by_id(boost::mysql::tcp_connection* conn, int new_item_id, int id)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("UPDATE user_inventory SET item_id = {new_item_id} WHERE id = {id}");
        conn->execute(query, result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_inventory_orm::update_item_quantity_by_user_character_id(boost::mysql::tcp_connection* conn, int new_item_quantity, int user_character_id)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("UPDATE user_inventory SET item_quantity = {new_item_quantity} WHERE user_character_id = {user_character_id}");
        conn->execute(query, result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_inventory_orm::update_item_quantity_by_id(boost::mysql::tcp_connection* conn, int new_item_quantity, int id)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("UPDATE user_inventory SET item_quantity = {new_item_quantity} WHERE id = {id}");
        conn->execute(query, result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_inventory_orm::update_created_at_by_user_character_id(boost::mysql::tcp_connection* conn, boost::mysql::datetime new_created_at, int user_character_id)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("UPDATE user_inventory SET created_at = {new_created_at} WHERE user_character_id = {user_character_id}");
        conn->execute(query, result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_inventory_orm::update_created_at_by_id(boost::mysql::tcp_connection* conn, boost::mysql::datetime new_created_at, int id)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("UPDATE user_inventory SET created_at = {new_created_at} WHERE id = {id}");
        conn->execute(query, result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_inventory_orm::update_updated_at_by_user_character_id(boost::mysql::tcp_connection* conn, boost::mysql::datetime new_updated_at, int user_character_id)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("UPDATE user_inventory SET updated_at = {new_updated_at} WHERE user_character_id = {user_character_id}");
        conn->execute(query, result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_inventory_orm::update_updated_at_by_id(boost::mysql::tcp_connection* conn, boost::mysql::datetime new_updated_at, int id)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("UPDATE user_inventory SET updated_at = {new_updated_at} WHERE id = {id}");
        conn->execute(query, result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_inventory_orm::delete_by_user_character_id(boost::mysql::tcp_connection* conn, int user_character_id)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("DELETE FROM user_inventory WHERE user_character_id = {user_character_id}");
        conn->execute(query, result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_inventory_orm::delete_by_id(boost::mysql::tcp_connection* conn, int id)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("DELETE FROM user_inventory WHERE id = {id}");
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

inline bool user_inventory_orm::sp_insert(boost::mysql::tcp_connection* conn, int user_character_id, int item_id, int item_quantity, boost::mysql::datetime created_at)
{
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_100(?, ?, ?, ?)");
        boost::mysql::results result;
        conn->execute(stmt.bind(user_character_id, item_id, item_quantity, created_at), result);
        std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        return result.affected_rows() > 0;
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }
}
    

inline boost::mysql::results user_inventory_orm::sp_select_all(boost::mysql::tcp_connection* conn)
{
    boost::mysql::results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_101()");
        conn->execute(stmt.bind(), result);
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_select_all: " << e.what() << std::endl;
    }
    return result;
}
    

inline boost::mysql::results user_inventory_orm::sp_select_all_by_user_character_id(boost::mysql::tcp_connection* conn, int user_character_id)
{
    boost::mysql::results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_102(?)");
        conn->execute(stmt.bind(user_character_id), result);
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_select_all_by_user_character_id: " << e.what() << std::endl;
    }
    return result;
}
    

inline boost::mysql::results user_inventory_orm::sp_select_all_by_id(boost::mysql::tcp_connection* conn, int id)
{
    boost::mysql::results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_103(?)");
        conn->execute(stmt.bind(id), result);
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_select_all_by_id: " << e.what() << std::endl;
    }
    return result;
}
    

inline std::uint64_t user_inventory_orm::sp_set_user_character_id_by_user_character_id(boost::mysql::tcp_connection* conn, int new_user_character_id, int user_character_id)
{
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_104(?, ?)");
        boost::mysql::results result;
        conn->execute(stmt.bind(new_user_character_id, user_character_id), result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_set_user_character_id_by_user_character_id: " << e.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_inventory_orm::sp_set_user_character_id_by_id(boost::mysql::tcp_connection* conn, int new_user_character_id, int id)
{
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_105(?, ?)");
        boost::mysql::results result;
        conn->execute(stmt.bind(new_user_character_id, id), result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_set_user_character_id_by_id: " << e.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_inventory_orm::sp_set_item_id_by_user_character_id(boost::mysql::tcp_connection* conn, int new_item_id, int user_character_id)
{
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_106(?, ?)");
        boost::mysql::results result;
        conn->execute(stmt.bind(new_item_id, user_character_id), result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_set_item_id_by_user_character_id: " << e.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_inventory_orm::sp_set_item_id_by_id(boost::mysql::tcp_connection* conn, int new_item_id, int id)
{
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_107(?, ?)");
        boost::mysql::results result;
        conn->execute(stmt.bind(new_item_id, id), result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_set_item_id_by_id: " << e.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_inventory_orm::sp_set_item_quantity_by_user_character_id(boost::mysql::tcp_connection* conn, int new_item_quantity, int user_character_id)
{
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_108(?, ?)");
        boost::mysql::results result;
        conn->execute(stmt.bind(new_item_quantity, user_character_id), result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_set_item_quantity_by_user_character_id: " << e.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_inventory_orm::sp_set_item_quantity_by_id(boost::mysql::tcp_connection* conn, int new_item_quantity, int id)
{
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_109(?, ?)");
        boost::mysql::results result;
        conn->execute(stmt.bind(new_item_quantity, id), result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_set_item_quantity_by_id: " << e.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_inventory_orm::sp_set_created_at_by_user_character_id(boost::mysql::tcp_connection* conn, boost::mysql::datetime new_created_at, int user_character_id)
{
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_110(?, ?)");
        boost::mysql::results result;
        conn->execute(stmt.bind(new_created_at, user_character_id), result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_set_created_at_by_user_character_id: " << e.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_inventory_orm::sp_set_created_at_by_id(boost::mysql::tcp_connection* conn, boost::mysql::datetime new_created_at, int id)
{
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_111(?, ?)");
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
    

inline std::uint64_t user_inventory_orm::sp_delete_by_user_character_id(boost::mysql::tcp_connection* conn, int user_character_id)
{
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_114(?)");
        boost::mysql::results result;
        conn->execute(stmt.bind(user_character_id), result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_delete_by_user_character_id: " << e.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_inventory_orm::sp_delete_by_id(boost::mysql::tcp_connection* conn, int id)
{
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_115(?)");
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
