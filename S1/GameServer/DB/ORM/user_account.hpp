
#pragma once

#include <boost/mysql.hpp>
#include <boost/mysql/tcp.hpp>
#include <boost/describe.hpp>
#include <string>
#include <iostream>
#include <format>

namespace ORM {

struct user_account
{
    int id; // int
    std::string user_id; // varchar(24)
    std::string user_name; // varchar(50)
    std::string password; // varchar(255)
    std::string email; // varchar(100)
    boost::mysql::datetime created_at; // timestamp
    boost::mysql::datetime updated_at; // timestamp
};

BOOST_DESCRIBE_STRUCT(user_account, (), (id, user_id, user_name, password, email, created_at, updated_at));

class user_account_orm
{
public:
    // 데이터베이스 쿼리 호출
    static bool insert(boost::mysql::tcp_connection* conn, std::string user_id, std::string user_name, std::string password, std::string email, boost::mysql::datetime created_at, boost::mysql::datetime updated_at);
    static boost::mysql::results select_all(boost::mysql::tcp_connection* conn);
    static boost::mysql::results select_by_email(boost::mysql::tcp_connection* conn, std::string email);
    static boost::mysql::results select_by_id(boost::mysql::tcp_connection* conn, int id);
    static boost::mysql::results select_by_user_id(boost::mysql::tcp_connection* conn, std::string user_id);
    static boost::mysql::results select_by_user_name(boost::mysql::tcp_connection* conn, std::string user_name);
    static std::uint64_t update_user_id_by_email(boost::mysql::tcp_connection* conn, std::string new_user_id, std::string email);
    static std::uint64_t update_user_id_by_id(boost::mysql::tcp_connection* conn, std::string new_user_id, int id);
    static std::uint64_t update_user_id_by_user_id(boost::mysql::tcp_connection* conn, std::string new_user_id, std::string user_id);
    static std::uint64_t update_user_id_by_user_name(boost::mysql::tcp_connection* conn, std::string new_user_id, std::string user_name);
    static std::uint64_t update_user_name_by_email(boost::mysql::tcp_connection* conn, std::string new_user_name, std::string email);
    static std::uint64_t update_user_name_by_id(boost::mysql::tcp_connection* conn, std::string new_user_name, int id);
    static std::uint64_t update_user_name_by_user_id(boost::mysql::tcp_connection* conn, std::string new_user_name, std::string user_id);
    static std::uint64_t update_user_name_by_user_name(boost::mysql::tcp_connection* conn, std::string new_user_name, std::string user_name);
    static std::uint64_t update_password_by_email(boost::mysql::tcp_connection* conn, std::string new_password, std::string email);
    static std::uint64_t update_password_by_id(boost::mysql::tcp_connection* conn, std::string new_password, int id);
    static std::uint64_t update_password_by_user_id(boost::mysql::tcp_connection* conn, std::string new_password, std::string user_id);
    static std::uint64_t update_password_by_user_name(boost::mysql::tcp_connection* conn, std::string new_password, std::string user_name);
    static std::uint64_t update_email_by_email(boost::mysql::tcp_connection* conn, std::string new_email, std::string email);
    static std::uint64_t update_email_by_id(boost::mysql::tcp_connection* conn, std::string new_email, int id);
    static std::uint64_t update_email_by_user_id(boost::mysql::tcp_connection* conn, std::string new_email, std::string user_id);
    static std::uint64_t update_email_by_user_name(boost::mysql::tcp_connection* conn, std::string new_email, std::string user_name);
    static std::uint64_t update_created_at_by_email(boost::mysql::tcp_connection* conn, boost::mysql::datetime new_created_at, std::string email);
    static std::uint64_t update_created_at_by_id(boost::mysql::tcp_connection* conn, boost::mysql::datetime new_created_at, int id);
    static std::uint64_t update_created_at_by_user_id(boost::mysql::tcp_connection* conn, boost::mysql::datetime new_created_at, std::string user_id);
    static std::uint64_t update_created_at_by_user_name(boost::mysql::tcp_connection* conn, boost::mysql::datetime new_created_at, std::string user_name);
    static std::uint64_t update_updated_at_by_email(boost::mysql::tcp_connection* conn, boost::mysql::datetime new_updated_at, std::string email);
    static std::uint64_t update_updated_at_by_id(boost::mysql::tcp_connection* conn, boost::mysql::datetime new_updated_at, int id);
    static std::uint64_t update_updated_at_by_user_id(boost::mysql::tcp_connection* conn, boost::mysql::datetime new_updated_at, std::string user_id);
    static std::uint64_t update_updated_at_by_user_name(boost::mysql::tcp_connection* conn, boost::mysql::datetime new_updated_at, std::string user_name);
    static std::uint64_t delete_by_email(boost::mysql::tcp_connection* conn, std::string email);
    static std::uint64_t delete_by_id(boost::mysql::tcp_connection* conn, int id);
    static std::uint64_t delete_by_user_id(boost::mysql::tcp_connection* conn, std::string user_id);
    static std::uint64_t delete_by_user_name(boost::mysql::tcp_connection* conn, std::string user_name);

    // 저장 프로시저 호출
    static bool sp_insert(boost::mysql::tcp_connection* conn, std::string user_id, std::string user_name, std::string password, std::string email, boost::mysql::datetime created_at);
    static boost::mysql::results sp_select_all(boost::mysql::tcp_connection* conn);
    static boost::mysql::results sp_select_all_by_email(boost::mysql::tcp_connection* conn, std::string email);
    static boost::mysql::results sp_select_all_by_id(boost::mysql::tcp_connection* conn, int id);
    static boost::mysql::results sp_select_all_by_user_id(boost::mysql::tcp_connection* conn, std::string user_id);
    static boost::mysql::results sp_select_all_by_user_name(boost::mysql::tcp_connection* conn, std::string user_name);
    static std::uint64_t sp_set_user_id_by_email(boost::mysql::tcp_connection* conn, std::string new_user_id, std::string email);
    static std::uint64_t sp_set_user_id_by_id(boost::mysql::tcp_connection* conn, std::string new_user_id, int id);
    static std::uint64_t sp_set_user_id_by_user_id(boost::mysql::tcp_connection* conn, std::string new_user_id, std::string user_id);
    static std::uint64_t sp_set_user_id_by_user_name(boost::mysql::tcp_connection* conn, std::string new_user_id, std::string user_name);
    static std::uint64_t sp_set_user_name_by_email(boost::mysql::tcp_connection* conn, std::string new_user_name, std::string email);
    static std::uint64_t sp_set_user_name_by_id(boost::mysql::tcp_connection* conn, std::string new_user_name, int id);
    static std::uint64_t sp_set_user_name_by_user_id(boost::mysql::tcp_connection* conn, std::string new_user_name, std::string user_id);
    static std::uint64_t sp_set_user_name_by_user_name(boost::mysql::tcp_connection* conn, std::string new_user_name, std::string user_name);
    static std::uint64_t sp_set_password_by_email(boost::mysql::tcp_connection* conn, std::string new_password, std::string email);
    static std::uint64_t sp_set_password_by_id(boost::mysql::tcp_connection* conn, std::string new_password, int id);
    static std::uint64_t sp_set_password_by_user_id(boost::mysql::tcp_connection* conn, std::string new_password, std::string user_id);
    static std::uint64_t sp_set_password_by_user_name(boost::mysql::tcp_connection* conn, std::string new_password, std::string user_name);
    static std::uint64_t sp_set_email_by_email(boost::mysql::tcp_connection* conn, std::string new_email, std::string email);
    static std::uint64_t sp_set_email_by_id(boost::mysql::tcp_connection* conn, std::string new_email, int id);
    static std::uint64_t sp_set_email_by_user_id(boost::mysql::tcp_connection* conn, std::string new_email, std::string user_id);
    static std::uint64_t sp_set_email_by_user_name(boost::mysql::tcp_connection* conn, std::string new_email, std::string user_name);
    static std::uint64_t sp_set_created_at_by_email(boost::mysql::tcp_connection* conn, boost::mysql::datetime new_created_at, std::string email);
    static std::uint64_t sp_set_created_at_by_id(boost::mysql::tcp_connection* conn, boost::mysql::datetime new_created_at, int id);
    static std::uint64_t sp_set_created_at_by_user_id(boost::mysql::tcp_connection* conn, boost::mysql::datetime new_created_at, std::string user_id);
    static std::uint64_t sp_set_created_at_by_user_name(boost::mysql::tcp_connection* conn, boost::mysql::datetime new_created_at, std::string user_name);
    static std::uint64_t sp_delete_by_email(boost::mysql::tcp_connection* conn, std::string email);
    static std::uint64_t sp_delete_by_id(boost::mysql::tcp_connection* conn, int id);
    static std::uint64_t sp_delete_by_user_id(boost::mysql::tcp_connection* conn, std::string user_id);
    static std::uint64_t sp_delete_by_user_name(boost::mysql::tcp_connection* conn, std::string user_name);
};

// 데이터베이스 쿼리 호출 구현부

inline bool user_account_orm::insert(boost::mysql::tcp_connection* conn, std::string user_id, std::string user_name, std::string password, std::string email, boost::mysql::datetime created_at, boost::mysql::datetime updated_at)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("INSERT INTO user_account (user_id, user_name, password, email, created_at, updated_at) VALUES ({user_id}, {user_name}, {password}, {email}, {created_at}, {updated_at})");
        conn->execute(query, result);
        return result.affected_rows() > 0;
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
        return false;
    }
}
    

inline boost::mysql::results user_account_orm::select_all(boost::mysql::tcp_connection* conn)
{
    boost::mysql::results result;
    try
    {
        conn->execute("SELECT * FROM user_account", result);
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
    }
    return result;
}
    

inline boost::mysql::results user_account_orm::select_by_email(boost::mysql::tcp_connection* conn, std::string email)
{
    boost::mysql::results result;
    try
    {
        std::string query = std::format("SELECT * FROM user_account WHERE email = {email}");
        conn->execute(query, result);
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
    }
    return result;
}
    

inline boost::mysql::results user_account_orm::select_by_id(boost::mysql::tcp_connection* conn, int id)
{
    boost::mysql::results result;
    try
    {
        std::string query = std::format("SELECT * FROM user_account WHERE id = {id}");
        conn->execute(query, result);
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
    }
    return result;
}
    

inline boost::mysql::results user_account_orm::select_by_user_id(boost::mysql::tcp_connection* conn, std::string user_id)
{
    boost::mysql::results result;
    try
    {
        std::string query = std::format("SELECT * FROM user_account WHERE user_id = {user_id}");
        conn->execute(query, result);
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
    }
    return result;
}
    

inline boost::mysql::results user_account_orm::select_by_user_name(boost::mysql::tcp_connection* conn, std::string user_name)
{
    boost::mysql::results result;
    try
    {
        std::string query = std::format("SELECT * FROM user_account WHERE user_name = {user_name}");
        conn->execute(query, result);
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
    }
    return result;
}
    

inline std::uint64_t user_account_orm::update_user_id_by_email(boost::mysql::tcp_connection* conn, std::string new_user_id, std::string email)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("UPDATE user_account SET user_id = {new_user_id} WHERE email = {email}");
        conn->execute(query, result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_account_orm::update_user_id_by_id(boost::mysql::tcp_connection* conn, std::string new_user_id, int id)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("UPDATE user_account SET user_id = {new_user_id} WHERE id = {id}");
        conn->execute(query, result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_account_orm::update_user_id_by_user_id(boost::mysql::tcp_connection* conn, std::string new_user_id, std::string user_id)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("UPDATE user_account SET user_id = {new_user_id} WHERE user_id = {user_id}");
        conn->execute(query, result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_account_orm::update_user_id_by_user_name(boost::mysql::tcp_connection* conn, std::string new_user_id, std::string user_name)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("UPDATE user_account SET user_id = {new_user_id} WHERE user_name = {user_name}");
        conn->execute(query, result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_account_orm::update_user_name_by_email(boost::mysql::tcp_connection* conn, std::string new_user_name, std::string email)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("UPDATE user_account SET user_name = {new_user_name} WHERE email = {email}");
        conn->execute(query, result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_account_orm::update_user_name_by_id(boost::mysql::tcp_connection* conn, std::string new_user_name, int id)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("UPDATE user_account SET user_name = {new_user_name} WHERE id = {id}");
        conn->execute(query, result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_account_orm::update_user_name_by_user_id(boost::mysql::tcp_connection* conn, std::string new_user_name, std::string user_id)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("UPDATE user_account SET user_name = {new_user_name} WHERE user_id = {user_id}");
        conn->execute(query, result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_account_orm::update_user_name_by_user_name(boost::mysql::tcp_connection* conn, std::string new_user_name, std::string user_name)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("UPDATE user_account SET user_name = {new_user_name} WHERE user_name = {user_name}");
        conn->execute(query, result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_account_orm::update_password_by_email(boost::mysql::tcp_connection* conn, std::string new_password, std::string email)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("UPDATE user_account SET password = {new_password} WHERE email = {email}");
        conn->execute(query, result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_account_orm::update_password_by_id(boost::mysql::tcp_connection* conn, std::string new_password, int id)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("UPDATE user_account SET password = {new_password} WHERE id = {id}");
        conn->execute(query, result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_account_orm::update_password_by_user_id(boost::mysql::tcp_connection* conn, std::string new_password, std::string user_id)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("UPDATE user_account SET password = {new_password} WHERE user_id = {user_id}");
        conn->execute(query, result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_account_orm::update_password_by_user_name(boost::mysql::tcp_connection* conn, std::string new_password, std::string user_name)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("UPDATE user_account SET password = {new_password} WHERE user_name = {user_name}");
        conn->execute(query, result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_account_orm::update_email_by_email(boost::mysql::tcp_connection* conn, std::string new_email, std::string email)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("UPDATE user_account SET email = {new_email} WHERE email = {email}");
        conn->execute(query, result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_account_orm::update_email_by_id(boost::mysql::tcp_connection* conn, std::string new_email, int id)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("UPDATE user_account SET email = {new_email} WHERE id = {id}");
        conn->execute(query, result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_account_orm::update_email_by_user_id(boost::mysql::tcp_connection* conn, std::string new_email, std::string user_id)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("UPDATE user_account SET email = {new_email} WHERE user_id = {user_id}");
        conn->execute(query, result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_account_orm::update_email_by_user_name(boost::mysql::tcp_connection* conn, std::string new_email, std::string user_name)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("UPDATE user_account SET email = {new_email} WHERE user_name = {user_name}");
        conn->execute(query, result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_account_orm::update_created_at_by_email(boost::mysql::tcp_connection* conn, boost::mysql::datetime new_created_at, std::string email)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("UPDATE user_account SET created_at = {new_created_at} WHERE email = {email}");
        conn->execute(query, result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_account_orm::update_created_at_by_id(boost::mysql::tcp_connection* conn, boost::mysql::datetime new_created_at, int id)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("UPDATE user_account SET created_at = {new_created_at} WHERE id = {id}");
        conn->execute(query, result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_account_orm::update_created_at_by_user_id(boost::mysql::tcp_connection* conn, boost::mysql::datetime new_created_at, std::string user_id)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("UPDATE user_account SET created_at = {new_created_at} WHERE user_id = {user_id}");
        conn->execute(query, result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_account_orm::update_created_at_by_user_name(boost::mysql::tcp_connection* conn, boost::mysql::datetime new_created_at, std::string user_name)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("UPDATE user_account SET created_at = {new_created_at} WHERE user_name = {user_name}");
        conn->execute(query, result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_account_orm::update_updated_at_by_email(boost::mysql::tcp_connection* conn, boost::mysql::datetime new_updated_at, std::string email)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("UPDATE user_account SET updated_at = {new_updated_at} WHERE email = {email}");
        conn->execute(query, result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_account_orm::update_updated_at_by_id(boost::mysql::tcp_connection* conn, boost::mysql::datetime new_updated_at, int id)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("UPDATE user_account SET updated_at = {new_updated_at} WHERE id = {id}");
        conn->execute(query, result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_account_orm::update_updated_at_by_user_id(boost::mysql::tcp_connection* conn, boost::mysql::datetime new_updated_at, std::string user_id)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("UPDATE user_account SET updated_at = {new_updated_at} WHERE user_id = {user_id}");
        conn->execute(query, result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_account_orm::update_updated_at_by_user_name(boost::mysql::tcp_connection* conn, boost::mysql::datetime new_updated_at, std::string user_name)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("UPDATE user_account SET updated_at = {new_updated_at} WHERE user_name = {user_name}");
        conn->execute(query, result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_account_orm::delete_by_email(boost::mysql::tcp_connection* conn, std::string email)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("DELETE FROM user_account WHERE email = {email}");
        conn->execute(query, result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_account_orm::delete_by_id(boost::mysql::tcp_connection* conn, int id)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("DELETE FROM user_account WHERE id = {id}");
        conn->execute(query, result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_account_orm::delete_by_user_id(boost::mysql::tcp_connection* conn, std::string user_id)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("DELETE FROM user_account WHERE user_id = {user_id}");
        conn->execute(query, result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_code& ec)
    {
        std::cerr << ec.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_account_orm::delete_by_user_name(boost::mysql::tcp_connection* conn, std::string user_name)
{
    try
    {
        boost::mysql::results result;
        std::string query = std::format("DELETE FROM user_account WHERE user_name = {user_name}");
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

inline bool user_account_orm::sp_insert(boost::mysql::tcp_connection* conn, std::string user_id, std::string user_name, std::string password, std::string email, boost::mysql::datetime created_at)
{
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_37(?, ?, ?, ?, ?)");
        boost::mysql::results result;
        conn->execute(stmt.bind(user_id, user_name, password, email, created_at), result);
        std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        return result.affected_rows() > 0;
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }
}
    

inline boost::mysql::results user_account_orm::sp_select_all(boost::mysql::tcp_connection* conn)
{
    boost::mysql::results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_38()");
        conn->execute(stmt.bind(), result);
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_select_all: " << e.what() << std::endl;
    }
    return result;
}
    

inline boost::mysql::results user_account_orm::sp_select_all_by_email(boost::mysql::tcp_connection* conn, std::string email)
{
    boost::mysql::results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_39(?)");
        conn->execute(stmt.bind(email), result);
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_select_all_by_email: " << e.what() << std::endl;
    }
    return result;
}
    

inline boost::mysql::results user_account_orm::sp_select_all_by_id(boost::mysql::tcp_connection* conn, int id)
{
    boost::mysql::results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_40(?)");
        conn->execute(stmt.bind(id), result);
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_select_all_by_id: " << e.what() << std::endl;
    }
    return result;
}
    

inline boost::mysql::results user_account_orm::sp_select_all_by_user_id(boost::mysql::tcp_connection* conn, std::string user_id)
{
    boost::mysql::results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_41(?)");
        conn->execute(stmt.bind(user_id), result);
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_select_all_by_user_id: " << e.what() << std::endl;
    }
    return result;
}
    

inline boost::mysql::results user_account_orm::sp_select_all_by_user_name(boost::mysql::tcp_connection* conn, std::string user_name)
{
    boost::mysql::results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_42(?)");
        conn->execute(stmt.bind(user_name), result);
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_select_all_by_user_name: " << e.what() << std::endl;
    }
    return result;
}
    

inline std::uint64_t user_account_orm::sp_set_user_id_by_email(boost::mysql::tcp_connection* conn, std::string new_user_id, std::string email)
{
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_43(?, ?)");
        boost::mysql::results result;
        conn->execute(stmt.bind(new_user_id, email), result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_set_user_id_by_email: " << e.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_account_orm::sp_set_user_id_by_id(boost::mysql::tcp_connection* conn, std::string new_user_id, int id)
{
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_44(?, ?)");
        boost::mysql::results result;
        conn->execute(stmt.bind(new_user_id, id), result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_set_user_id_by_id: " << e.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_account_orm::sp_set_user_id_by_user_id(boost::mysql::tcp_connection* conn, std::string new_user_id, std::string user_id)
{
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_45(?, ?)");
        boost::mysql::results result;
        conn->execute(stmt.bind(new_user_id, user_id), result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_set_user_id_by_user_id: " << e.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_account_orm::sp_set_user_id_by_user_name(boost::mysql::tcp_connection* conn, std::string new_user_id, std::string user_name)
{
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_46(?, ?)");
        boost::mysql::results result;
        conn->execute(stmt.bind(new_user_id, user_name), result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_set_user_id_by_user_name: " << e.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_account_orm::sp_set_user_name_by_email(boost::mysql::tcp_connection* conn, std::string new_user_name, std::string email)
{
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_47(?, ?)");
        boost::mysql::results result;
        conn->execute(stmt.bind(new_user_name, email), result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_set_user_name_by_email: " << e.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_account_orm::sp_set_user_name_by_id(boost::mysql::tcp_connection* conn, std::string new_user_name, int id)
{
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_48(?, ?)");
        boost::mysql::results result;
        conn->execute(stmt.bind(new_user_name, id), result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_set_user_name_by_id: " << e.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_account_orm::sp_set_user_name_by_user_id(boost::mysql::tcp_connection* conn, std::string new_user_name, std::string user_id)
{
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_49(?, ?)");
        boost::mysql::results result;
        conn->execute(stmt.bind(new_user_name, user_id), result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_set_user_name_by_user_id: " << e.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_account_orm::sp_set_user_name_by_user_name(boost::mysql::tcp_connection* conn, std::string new_user_name, std::string user_name)
{
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_50(?, ?)");
        boost::mysql::results result;
        conn->execute(stmt.bind(new_user_name, user_name), result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_set_user_name_by_user_name: " << e.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_account_orm::sp_set_password_by_email(boost::mysql::tcp_connection* conn, std::string new_password, std::string email)
{
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_51(?, ?)");
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
    

inline std::uint64_t user_account_orm::sp_set_password_by_id(boost::mysql::tcp_connection* conn, std::string new_password, int id)
{
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_52(?, ?)");
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
    

inline std::uint64_t user_account_orm::sp_set_password_by_user_id(boost::mysql::tcp_connection* conn, std::string new_password, std::string user_id)
{
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_53(?, ?)");
        boost::mysql::results result;
        conn->execute(stmt.bind(new_password, user_id), result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_set_password_by_user_id: " << e.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_account_orm::sp_set_password_by_user_name(boost::mysql::tcp_connection* conn, std::string new_password, std::string user_name)
{
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_54(?, ?)");
        boost::mysql::results result;
        conn->execute(stmt.bind(new_password, user_name), result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_set_password_by_user_name: " << e.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_account_orm::sp_set_email_by_email(boost::mysql::tcp_connection* conn, std::string new_email, std::string email)
{
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_55(?, ?)");
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
    

inline std::uint64_t user_account_orm::sp_set_email_by_id(boost::mysql::tcp_connection* conn, std::string new_email, int id)
{
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_56(?, ?)");
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
    

inline std::uint64_t user_account_orm::sp_set_email_by_user_id(boost::mysql::tcp_connection* conn, std::string new_email, std::string user_id)
{
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_57(?, ?)");
        boost::mysql::results result;
        conn->execute(stmt.bind(new_email, user_id), result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_set_email_by_user_id: " << e.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_account_orm::sp_set_email_by_user_name(boost::mysql::tcp_connection* conn, std::string new_email, std::string user_name)
{
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_58(?, ?)");
        boost::mysql::results result;
        conn->execute(stmt.bind(new_email, user_name), result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_set_email_by_user_name: " << e.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_account_orm::sp_set_created_at_by_email(boost::mysql::tcp_connection* conn, boost::mysql::datetime new_created_at, std::string email)
{
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_59(?, ?)");
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
    

inline std::uint64_t user_account_orm::sp_set_created_at_by_id(boost::mysql::tcp_connection* conn, boost::mysql::datetime new_created_at, int id)
{
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_60(?, ?)");
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
    

inline std::uint64_t user_account_orm::sp_set_created_at_by_user_id(boost::mysql::tcp_connection* conn, boost::mysql::datetime new_created_at, std::string user_id)
{
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_61(?, ?)");
        boost::mysql::results result;
        conn->execute(stmt.bind(new_created_at, user_id), result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_set_created_at_by_user_id: " << e.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_account_orm::sp_set_created_at_by_user_name(boost::mysql::tcp_connection* conn, boost::mysql::datetime new_created_at, std::string user_name)
{
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_62(?, ?)");
        boost::mysql::results result;
        conn->execute(stmt.bind(new_created_at, user_name), result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_set_created_at_by_user_name: " << e.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_account_orm::sp_delete_by_email(boost::mysql::tcp_connection* conn, std::string email)
{
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_67(?)");
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
    

inline std::uint64_t user_account_orm::sp_delete_by_id(boost::mysql::tcp_connection* conn, int id)
{
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_68(?)");
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
    

inline std::uint64_t user_account_orm::sp_delete_by_user_id(boost::mysql::tcp_connection* conn, std::string user_id)
{
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_69(?)");
        boost::mysql::results result;
        conn->execute(stmt.bind(user_id), result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_delete_by_user_id: " << e.what() << std::endl;
        return 0;
    }
}
    

inline std::uint64_t user_account_orm::sp_delete_by_user_name(boost::mysql::tcp_connection* conn, std::string user_name)
{
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_70(?)");
        boost::mysql::results result;
        conn->execute(stmt.bind(user_name), result);
        return result.affected_rows();
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_delete_by_user_name: " << e.what() << std::endl;
        return 0;
    }
}
    

} // namespace ORM
