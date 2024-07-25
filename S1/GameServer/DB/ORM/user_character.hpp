
#pragma once

#include <boost/mysql.hpp>
#include <boost/mysql/tcp.hpp>
#include <boost/describe.hpp>
#include <string>
#include <iostream>
#include <format>

namespace ORM {

struct user_character
{
    int id; // int
    int user_account_id; // int
    std::string character_name; // varchar(50)
    int level; // int
    long long experience; // bigint
    long long gold; // bigint
    boost::mysql::datetime created_at; // timestamp
    boost::mysql::datetime updated_at; // timestamp
};

BOOST_DESCRIBE_STRUCT(user_character, (), (id, user_account_id, character_name, level, experience, gold, created_at, updated_at));

class user_character_orm
{
public:
    // 데이터베이스 쿼리 호출
    static bool insert(boost::mysql::tcp_connection* conn, int user_account_id, std::string character_name, int level, long long experience, long long gold, boost::mysql::datetime created_at, boost::mysql::datetime updated_at);
    static boost::mysql::results select_all(boost::mysql::tcp_connection* conn);
    static boost::mysql::results select_by_character_name(boost::mysql::tcp_connection* conn, std::string character_name);
    static boost::mysql::results select_by_user_account_id(boost::mysql::tcp_connection* conn, int user_account_id);
    static boost::mysql::results select_by_id(boost::mysql::tcp_connection* conn, int id);
    static std::uint64_t update_user_account_id_by_character_name(boost::mysql::tcp_connection* conn, int new_user_account_id, std::string character_name);
    static std::uint64_t update_user_account_id_by_user_account_id(boost::mysql::tcp_connection* conn, int new_user_account_id, int user_account_id);
    static std::uint64_t update_user_account_id_by_id(boost::mysql::tcp_connection* conn, int new_user_account_id, int id);
    static std::uint64_t update_character_name_by_character_name(boost::mysql::tcp_connection* conn, std::string new_character_name, std::string character_name);
    static std::uint64_t update_character_name_by_user_account_id(boost::mysql::tcp_connection* conn, std::string new_character_name, int user_account_id);
    static std::uint64_t update_character_name_by_id(boost::mysql::tcp_connection* conn, std::string new_character_name, int id);
    static std::uint64_t update_level_by_character_name(boost::mysql::tcp_connection* conn, int new_level, std::string character_name);
    static std::uint64_t update_level_by_user_account_id(boost::mysql::tcp_connection* conn, int new_level, int user_account_id);
    static std::uint64_t update_level_by_id(boost::mysql::tcp_connection* conn, int new_level, int id);
    static std::uint64_t update_experience_by_character_name(boost::mysql::tcp_connection* conn, long long new_experience, std::string character_name);
    static std::uint64_t update_experience_by_user_account_id(boost::mysql::tcp_connection* conn, long long new_experience, int user_account_id);
    static std::uint64_t update_experience_by_id(boost::mysql::tcp_connection* conn, long long new_experience, int id);
    static std::uint64_t update_gold_by_character_name(boost::mysql::tcp_connection* conn, long long new_gold, std::string character_name);
    static std::uint64_t update_gold_by_user_account_id(boost::mysql::tcp_connection* conn, long long new_gold, int user_account_id);
    static std::uint64_t update_gold_by_id(boost::mysql::tcp_connection* conn, long long new_gold, int id);
    static std::uint64_t update_created_at_by_character_name(boost::mysql::tcp_connection* conn, boost::mysql::datetime new_created_at, std::string character_name);
    static std::uint64_t update_created_at_by_user_account_id(boost::mysql::tcp_connection* conn, boost::mysql::datetime new_created_at, int user_account_id);
    static std::uint64_t update_created_at_by_id(boost::mysql::tcp_connection* conn, boost::mysql::datetime new_created_at, int id);
    static std::uint64_t update_updated_at_by_character_name(boost::mysql::tcp_connection* conn, boost::mysql::datetime new_updated_at, std::string character_name);
    static std::uint64_t update_updated_at_by_user_account_id(boost::mysql::tcp_connection* conn, boost::mysql::datetime new_updated_at, int user_account_id);
    static std::uint64_t update_updated_at_by_id(boost::mysql::tcp_connection* conn, boost::mysql::datetime new_updated_at, int id);
    static std::uint64_t delete_by_character_name(boost::mysql::tcp_connection* conn, std::string character_name);
    static std::uint64_t delete_by_user_account_id(boost::mysql::tcp_connection* conn, int user_account_id);
    static std::uint64_t delete_by_id(boost::mysql::tcp_connection* conn, int id);

    // 저장 프로시저 호출
    static bool sp_insert(boost::mysql::tcp_connection* conn, int user_account_id, std::string character_name, int level, long long experience, long long gold, boost::mysql::datetime created_at);
    static boost::mysql::results sp_select_all(boost::mysql::tcp_connection* conn);
    static boost::mysql::results sp_select_all_by_character_name(boost::mysql::tcp_connection* conn, std::string character_name);
    static boost::mysql::results sp_select_all_by_user_account_id(boost::mysql::tcp_connection* conn, int user_account_id);
    static boost::mysql::results sp_select_all_by_id(boost::mysql::tcp_connection* conn, int id);
    static std::uint64_t sp_set_user_account_id_by_character_name(boost::mysql::tcp_connection* conn, int new_user_account_id, std::string character_name);
    static std::uint64_t sp_set_user_account_id_by_user_account_id(boost::mysql::tcp_connection* conn, int new_user_account_id, int user_account_id);
    static std::uint64_t sp_set_user_account_id_by_id(boost::mysql::tcp_connection* conn, int new_user_account_id, int id);
    static std::uint64_t sp_set_character_name_by_character_name(boost::mysql::tcp_connection* conn, std::string new_character_name, std::string character_name);
    static std::uint64_t sp_set_character_name_by_user_account_id(boost::mysql::tcp_connection* conn, std::string new_character_name, int user_account_id);
    static std::uint64_t sp_set_character_name_by_id(boost::mysql::tcp_connection* conn, std::string new_character_name, int id);
    static std::uint64_t sp_set_level_by_character_name(boost::mysql::tcp_connection* conn, int new_level, std::string character_name);
    static std::uint64_t sp_set_level_by_user_account_id(boost::mysql::tcp_connection* conn, int new_level, int user_account_id);
    static std::uint64_t sp_set_level_by_id(boost::mysql::tcp_connection* conn, int new_level, int id);
    static std::uint64_t sp_set_experience_by_character_name(boost::mysql::tcp_connection* conn, long long new_experience, std::string character_name);
    static std::uint64_t sp_set_experience_by_user_account_id(boost::mysql::tcp_connection* conn, long long new_experience, int user_account_id);
    static std::uint64_t sp_set_experience_by_id(boost::mysql::tcp_connection* conn, long long new_experience, int id);
    static std::uint64_t sp_set_gold_by_character_name(boost::mysql::tcp_connection* conn, long long new_gold, std::string character_name);
    static std::uint64_t sp_set_gold_by_user_account_id(boost::mysql::tcp_connection* conn, long long new_gold, int user_account_id);
    static std::uint64_t sp_set_gold_by_id(boost::mysql::tcp_connection* conn, long long new_gold, int id);
    static std::uint64_t sp_set_created_at_by_character_name(boost::mysql::tcp_connection* conn, boost::mysql::datetime new_created_at, std::string character_name);
    static std::uint64_t sp_set_created_at_by_user_account_id(boost::mysql::tcp_connection* conn, boost::mysql::datetime new_created_at, int user_account_id);
    static std::uint64_t sp_set_created_at_by_id(boost::mysql::tcp_connection* conn, boost::mysql::datetime new_created_at, int id);
    static std::uint64_t sp_delete_by_character_name(boost::mysql::tcp_connection* conn, std::string character_name);
    static std::uint64_t sp_delete_by_user_account_id(boost::mysql::tcp_connection* conn, int user_account_id);
    static std::uint64_t sp_delete_by_id(boost::mysql::tcp_connection* conn, int id);
};

// 데이터베이스 쿼리 호출 구현부

inline bool user_character_orm::insert(boost::mysql::tcp_connection* conn, int user_account_id, std::string character_name, int level, long long experience, long long gold, boost::mysql::datetime created_at, boost::mysql::datetime updated_at)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("INSERT INTO user_character (user_account_id, character_name, level, experience, gold, created_at, updated_at) VALUES ({user_account_id}, {character_name}, {level}, {experience}, {gold}, {created_at}, {updated_at})");
        conn->execute(query, result);
        return result.affected_rows() > 0;
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
        return false;
    }
}
    

inline boost::mysql::results user_character_orm::select_all(boost::mysql::tcp_connection* conn)
{
    boost::mysql::results result;
    try
    {
        conn->execute("SELECT * FROM user_character", result);
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
    }
    return result;
}
    

inline boost::mysql::results user_character_orm::select_by_character_name(boost::mysql::tcp_connection* conn, std::string character_name)
{
    boost::mysql::results result;
    try
    {
        std::string query = std::format("SELECT * FROM user_character WHERE character_name = {character_name}");
        conn->execute(query, result);
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
    }
    return result;
}
    

inline boost::mysql::results user_character_orm::select_by_user_account_id(boost::mysql::tcp_connection* conn, int user_account_id)
{
    boost::mysql::results result;
    try
    {
        std::string query = std::format("SELECT * FROM user_character WHERE user_account_id = {user_account_id}");
        conn->execute(query, result);
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
    }
    return result;
}
    

inline boost::mysql::results user_character_orm::select_by_id(boost::mysql::tcp_connection* conn, int id)
{
    boost::mysql::results result;
    try
    {
        std::string query = std::format("SELECT * FROM user_character WHERE id = {id}");
        conn->execute(query, result);
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
    }
    return result;
}
    

inline std::uint64_t user_character_orm::update_user_account_id_by_character_name(boost::mysql::tcp_connection* conn, int new_user_account_id, std::string character_name)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("UPDATE user_character SET user_account_id = {new_user_account_id} WHERE character_name = {character_name}");
        conn->execute(query, result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_character_orm::update_user_account_id_by_user_account_id(boost::mysql::tcp_connection* conn, int new_user_account_id, int user_account_id)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("UPDATE user_character SET user_account_id = {new_user_account_id} WHERE user_account_id = {user_account_id}");
        conn->execute(query, result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_character_orm::update_user_account_id_by_id(boost::mysql::tcp_connection* conn, int new_user_account_id, int id)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("UPDATE user_character SET user_account_id = {new_user_account_id} WHERE id = {id}");
        conn->execute(query, result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_character_orm::update_character_name_by_character_name(boost::mysql::tcp_connection* conn, std::string new_character_name, std::string character_name)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("UPDATE user_character SET character_name = {new_character_name} WHERE character_name = {character_name}");
        conn->execute(query, result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_character_orm::update_character_name_by_user_account_id(boost::mysql::tcp_connection* conn, std::string new_character_name, int user_account_id)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("UPDATE user_character SET character_name = {new_character_name} WHERE user_account_id = {user_account_id}");
        conn->execute(query, result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_character_orm::update_character_name_by_id(boost::mysql::tcp_connection* conn, std::string new_character_name, int id)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("UPDATE user_character SET character_name = {new_character_name} WHERE id = {id}");
        conn->execute(query, result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_character_orm::update_level_by_character_name(boost::mysql::tcp_connection* conn, int new_level, std::string character_name)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("UPDATE user_character SET level = {new_level} WHERE character_name = {character_name}");
        conn->execute(query, result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_character_orm::update_level_by_user_account_id(boost::mysql::tcp_connection* conn, int new_level, int user_account_id)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("UPDATE user_character SET level = {new_level} WHERE user_account_id = {user_account_id}");
        conn->execute(query, result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_character_orm::update_level_by_id(boost::mysql::tcp_connection* conn, int new_level, int id)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("UPDATE user_character SET level = {new_level} WHERE id = {id}");
        conn->execute(query, result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_character_orm::update_experience_by_character_name(boost::mysql::tcp_connection* conn, long long new_experience, std::string character_name)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("UPDATE user_character SET experience = {new_experience} WHERE character_name = {character_name}");
        conn->execute(query, result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_character_orm::update_experience_by_user_account_id(boost::mysql::tcp_connection* conn, long long new_experience, int user_account_id)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("UPDATE user_character SET experience = {new_experience} WHERE user_account_id = {user_account_id}");
        conn->execute(query, result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_character_orm::update_experience_by_id(boost::mysql::tcp_connection* conn, long long new_experience, int id)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("UPDATE user_character SET experience = {new_experience} WHERE id = {id}");
        conn->execute(query, result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_character_orm::update_gold_by_character_name(boost::mysql::tcp_connection* conn, long long new_gold, std::string character_name)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("UPDATE user_character SET gold = {new_gold} WHERE character_name = {character_name}");
        conn->execute(query, result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_character_orm::update_gold_by_user_account_id(boost::mysql::tcp_connection* conn, long long new_gold, int user_account_id)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("UPDATE user_character SET gold = {new_gold} WHERE user_account_id = {user_account_id}");
        conn->execute(query, result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_character_orm::update_gold_by_id(boost::mysql::tcp_connection* conn, long long new_gold, int id)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("UPDATE user_character SET gold = {new_gold} WHERE id = {id}");
        conn->execute(query, result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_character_orm::update_created_at_by_character_name(boost::mysql::tcp_connection* conn, boost::mysql::datetime new_created_at, std::string character_name)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("UPDATE user_character SET created_at = {new_created_at} WHERE character_name = {character_name}");
        conn->execute(query, result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_character_orm::update_created_at_by_user_account_id(boost::mysql::tcp_connection* conn, boost::mysql::datetime new_created_at, int user_account_id)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("UPDATE user_character SET created_at = {new_created_at} WHERE user_account_id = {user_account_id}");
        conn->execute(query, result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_character_orm::update_created_at_by_id(boost::mysql::tcp_connection* conn, boost::mysql::datetime new_created_at, int id)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("UPDATE user_character SET created_at = {new_created_at} WHERE id = {id}");
        conn->execute(query, result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_character_orm::update_updated_at_by_character_name(boost::mysql::tcp_connection* conn, boost::mysql::datetime new_updated_at, std::string character_name)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("UPDATE user_character SET updated_at = {new_updated_at} WHERE character_name = {character_name}");
        conn->execute(query, result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_character_orm::update_updated_at_by_user_account_id(boost::mysql::tcp_connection* conn, boost::mysql::datetime new_updated_at, int user_account_id)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("UPDATE user_character SET updated_at = {new_updated_at} WHERE user_account_id = {user_account_id}");
        conn->execute(query, result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_character_orm::update_updated_at_by_id(boost::mysql::tcp_connection* conn, boost::mysql::datetime new_updated_at, int id)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("UPDATE user_character SET updated_at = {new_updated_at} WHERE id = {id}");
        conn->execute(query, result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_character_orm::delete_by_character_name(boost::mysql::tcp_connection* conn, std::string character_name)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("DELETE FROM user_character WHERE character_name = {character_name}");
        conn->execute(query, result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_character_orm::delete_by_user_account_id(boost::mysql::tcp_connection* conn, int user_account_id)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("DELETE FROM user_character WHERE user_account_id = {user_account_id}");
        conn->execute(query, result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_character_orm::delete_by_id(boost::mysql::tcp_connection* conn, int id)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("DELETE FROM user_character WHERE id = {id}");
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

inline bool user_character_orm::sp_insert(boost::mysql::tcp_connection* conn, int user_account_id, std::string character_name, int level, long long experience, long long gold, boost::mysql::datetime created_at)
{
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_71(?, ?, ?, ?, ?, ?)");
        boost::mysql::results result;
        conn->execute(stmt.bind(user_account_id, character_name, level, experience, gold, created_at), result);
        std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        return result.affected_rows() > 0;
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }
}
    

inline boost::mysql::results user_character_orm::sp_select_all(boost::mysql::tcp_connection* conn)
{
    boost::mysql::results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_72()");
        conn->execute(stmt.bind(), result);
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_select_all: " << e.what() << std::endl;
    }
    return result;
}
    

inline boost::mysql::results user_character_orm::sp_select_all_by_character_name(boost::mysql::tcp_connection* conn, std::string character_name)
{
    boost::mysql::results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_73(?)");
        conn->execute(stmt.bind(character_name), result);
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_select_all_by_character_name: " << e.what() << std::endl;
    }
    return result;
}
    

inline boost::mysql::results user_character_orm::sp_select_all_by_user_account_id(boost::mysql::tcp_connection* conn, int user_account_id)
{
    boost::mysql::results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_74(?)");
        conn->execute(stmt.bind(user_account_id), result);
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_select_all_by_user_account_id: " << e.what() << std::endl;
    }
    return result;
}
    

inline boost::mysql::results user_character_orm::sp_select_all_by_id(boost::mysql::tcp_connection* conn, int id)
{
    boost::mysql::results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_75(?)");
        conn->execute(stmt.bind(id), result);
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_select_all_by_id: " << e.what() << std::endl;
    }
    return result;
}
    

inline std::uint64_t user_character_orm::sp_set_user_account_id_by_character_name(boost::mysql::tcp_connection* conn, int new_user_account_id, std::string character_name)
{
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_76(?, ?)");
        boost::mysql::results result;
        conn->execute(stmt.bind(new_user_account_id, character_name), result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_set_user_account_id_by_character_name: " << e.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_character_orm::sp_set_user_account_id_by_user_account_id(boost::mysql::tcp_connection* conn, int new_user_account_id, int user_account_id)
{
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_77(?, ?)");
        boost::mysql::results result;
        conn->execute(stmt.bind(new_user_account_id, user_account_id), result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_set_user_account_id_by_user_account_id: " << e.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_character_orm::sp_set_user_account_id_by_id(boost::mysql::tcp_connection* conn, int new_user_account_id, int id)
{
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_78(?, ?)");
        boost::mysql::results result;
        conn->execute(stmt.bind(new_user_account_id, id), result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_set_user_account_id_by_id: " << e.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_character_orm::sp_set_character_name_by_character_name(boost::mysql::tcp_connection* conn, std::string new_character_name, std::string character_name)
{
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_79(?, ?)");
        boost::mysql::results result;
        conn->execute(stmt.bind(new_character_name, character_name), result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_set_character_name_by_character_name: " << e.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_character_orm::sp_set_character_name_by_user_account_id(boost::mysql::tcp_connection* conn, std::string new_character_name, int user_account_id)
{
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_80(?, ?)");
        boost::mysql::results result;
        conn->execute(stmt.bind(new_character_name, user_account_id), result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_set_character_name_by_user_account_id: " << e.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_character_orm::sp_set_character_name_by_id(boost::mysql::tcp_connection* conn, std::string new_character_name, int id)
{
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_81(?, ?)");
        boost::mysql::results result;
        conn->execute(stmt.bind(new_character_name, id), result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_set_character_name_by_id: " << e.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_character_orm::sp_set_level_by_character_name(boost::mysql::tcp_connection* conn, int new_level, std::string character_name)
{
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_82(?, ?)");
        boost::mysql::results result;
        conn->execute(stmt.bind(new_level, character_name), result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_set_level_by_character_name: " << e.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_character_orm::sp_set_level_by_user_account_id(boost::mysql::tcp_connection* conn, int new_level, int user_account_id)
{
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_83(?, ?)");
        boost::mysql::results result;
        conn->execute(stmt.bind(new_level, user_account_id), result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_set_level_by_user_account_id: " << e.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_character_orm::sp_set_level_by_id(boost::mysql::tcp_connection* conn, int new_level, int id)
{
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_84(?, ?)");
        boost::mysql::results result;
        conn->execute(stmt.bind(new_level, id), result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_set_level_by_id: " << e.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_character_orm::sp_set_experience_by_character_name(boost::mysql::tcp_connection* conn, long long new_experience, std::string character_name)
{
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_85(?, ?)");
        boost::mysql::results result;
        conn->execute(stmt.bind(new_experience, character_name), result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_set_experience_by_character_name: " << e.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_character_orm::sp_set_experience_by_user_account_id(boost::mysql::tcp_connection* conn, long long new_experience, int user_account_id)
{
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_86(?, ?)");
        boost::mysql::results result;
        conn->execute(stmt.bind(new_experience, user_account_id), result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_set_experience_by_user_account_id: " << e.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_character_orm::sp_set_experience_by_id(boost::mysql::tcp_connection* conn, long long new_experience, int id)
{
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_87(?, ?)");
        boost::mysql::results result;
        conn->execute(stmt.bind(new_experience, id), result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_set_experience_by_id: " << e.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_character_orm::sp_set_gold_by_character_name(boost::mysql::tcp_connection* conn, long long new_gold, std::string character_name)
{
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_88(?, ?)");
        boost::mysql::results result;
        conn->execute(stmt.bind(new_gold, character_name), result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_set_gold_by_character_name: " << e.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_character_orm::sp_set_gold_by_user_account_id(boost::mysql::tcp_connection* conn, long long new_gold, int user_account_id)
{
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_89(?, ?)");
        boost::mysql::results result;
        conn->execute(stmt.bind(new_gold, user_account_id), result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_set_gold_by_user_account_id: " << e.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_character_orm::sp_set_gold_by_id(boost::mysql::tcp_connection* conn, long long new_gold, int id)
{
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_90(?, ?)");
        boost::mysql::results result;
        conn->execute(stmt.bind(new_gold, id), result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_set_gold_by_id: " << e.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_character_orm::sp_set_created_at_by_character_name(boost::mysql::tcp_connection* conn, boost::mysql::datetime new_created_at, std::string character_name)
{
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_91(?, ?)");
        boost::mysql::results result;
        conn->execute(stmt.bind(new_created_at, character_name), result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_set_created_at_by_character_name: " << e.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_character_orm::sp_set_created_at_by_user_account_id(boost::mysql::tcp_connection* conn, boost::mysql::datetime new_created_at, int user_account_id)
{
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_92(?, ?)");
        boost::mysql::results result;
        conn->execute(stmt.bind(new_created_at, user_account_id), result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_set_created_at_by_user_account_id: " << e.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_character_orm::sp_set_created_at_by_id(boost::mysql::tcp_connection* conn, boost::mysql::datetime new_created_at, int id)
{
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_93(?, ?)");
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
    

inline std::uint64_t user_character_orm::sp_delete_by_character_name(boost::mysql::tcp_connection* conn, std::string character_name)
{
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_97(?)");
        boost::mysql::results result;
        conn->execute(stmt.bind(character_name), result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_delete_by_character_name: " << e.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_character_orm::sp_delete_by_user_account_id(boost::mysql::tcp_connection* conn, int user_account_id)
{
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_98(?)");
        boost::mysql::results result;
        conn->execute(stmt.bind(user_account_id), result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_delete_by_user_account_id: " << e.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_character_orm::sp_delete_by_id(boost::mysql::tcp_connection* conn, int id)
{
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_99(?)");
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
