
#pragma once

#include <boost/mysql.hpp>
#include <boost/mysql/tcp.hpp>
#include <boost/describe.hpp>
#include <vector>
#include <string>
#include <chrono>

namespace ORM {

struct user_account
{
    // 멤버 변수
    int id; // int
    std::string user_id; // varchar(24)
    std::string user_name; // varchar(50)
    std::string password; // varchar(255)
    std::string email; // varchar(100)
    boost::mysql::datetime created_at; // timestamp
    boost::mysql::datetime updated_at; // timestamp
};
BOOST_DESCRIBE_STRUCT(user_account, (), (id, user_id, user_name, password, email, created_at, updated_at));

// 데이터베이스 연산
void insert(boost::mysql::tcp_connection& conn, const user_account& obj);
std::vector<user_account> select_all(boost::mysql::tcp_connection& conn);
std::vector<user_account> select_all_by_email(boost::mysql::tcp_connection& conn, std::string email);
std::vector<user_account> select_all_by_id(boost::mysql::tcp_connection& conn, int id);
std::vector<user_account> select_all_by_user_id(boost::mysql::tcp_connection& conn, std::string user_id);
std::vector<user_account> select_all_by_user_name(boost::mysql::tcp_connection& conn, std::string user_name);
void update_user_id_by_email(boost::mysql::tcp_connection& conn, std::string new_user_id, std::string email);
void update_user_id_by_id(boost::mysql::tcp_connection& conn, std::string new_user_id, int id);
void update_user_id_by_user_id(boost::mysql::tcp_connection& conn, std::string new_user_id, std::string user_id);
void update_user_id_by_user_name(boost::mysql::tcp_connection& conn, std::string new_user_id, std::string user_name);
void update_user_name_by_email(boost::mysql::tcp_connection& conn, std::string new_user_name, std::string email);
void update_user_name_by_id(boost::mysql::tcp_connection& conn, std::string new_user_name, int id);
void update_user_name_by_user_id(boost::mysql::tcp_connection& conn, std::string new_user_name, std::string user_id);
void update_user_name_by_user_name(boost::mysql::tcp_connection& conn, std::string new_user_name, std::string user_name);
void update_password_by_email(boost::mysql::tcp_connection& conn, std::string new_password, std::string email);
void update_password_by_id(boost::mysql::tcp_connection& conn, std::string new_password, int id);
void update_password_by_user_id(boost::mysql::tcp_connection& conn, std::string new_password, std::string user_id);
void update_password_by_user_name(boost::mysql::tcp_connection& conn, std::string new_password, std::string user_name);
void update_email_by_email(boost::mysql::tcp_connection& conn, std::string new_email, std::string email);
void update_email_by_id(boost::mysql::tcp_connection& conn, std::string new_email, int id);
void update_email_by_user_id(boost::mysql::tcp_connection& conn, std::string new_email, std::string user_id);
void update_email_by_user_name(boost::mysql::tcp_connection& conn, std::string new_email, std::string user_name);
void update_created_at_by_email(boost::mysql::tcp_connection& conn, boost::mysql::datetime new_created_at, std::string email);
void update_created_at_by_id(boost::mysql::tcp_connection& conn, boost::mysql::datetime new_created_at, int id);
void update_created_at_by_user_id(boost::mysql::tcp_connection& conn, boost::mysql::datetime new_created_at, std::string user_id);
void update_created_at_by_user_name(boost::mysql::tcp_connection& conn, boost::mysql::datetime new_created_at, std::string user_name);
void delete_by_email(boost::mysql::tcp_connection& conn, std::string email);
void delete_by_id(boost::mysql::tcp_connection& conn, int id);
void delete_by_user_id(boost::mysql::tcp_connection& conn, std::string user_id);
void delete_by_user_name(boost::mysql::tcp_connection& conn, std::string user_name);

// 저장 프로시저 호출
void sp_insert(boost::mysql::tcp_connection& conn, const user_account& obj);
std::vector<user_account> sp_select_all(boost::mysql::tcp_connection& conn);
std::vector<user_account> sp_select_all_by_email(boost::mysql::tcp_connection& conn, std::string email);
std::vector<user_account> sp_select_all_by_id(boost::mysql::tcp_connection& conn, int id);
std::vector<user_account> sp_select_all_by_user_id(boost::mysql::tcp_connection& conn, std::string user_id);
std::vector<user_account> sp_select_all_by_user_name(boost::mysql::tcp_connection& conn, std::string user_name);
void sp_set_user_id_by_email(boost::mysql::tcp_connection& conn, std::string new_user_id, std::string email);
void sp_set_user_id_by_id(boost::mysql::tcp_connection& conn, std::string new_user_id, int id);
void sp_set_user_id_by_user_id(boost::mysql::tcp_connection& conn, std::string new_user_id, std::string user_id);
void sp_set_user_id_by_user_name(boost::mysql::tcp_connection& conn, std::string new_user_id, std::string user_name);
void sp_set_user_name_by_email(boost::mysql::tcp_connection& conn, std::string new_user_name, std::string email);
void sp_set_user_name_by_id(boost::mysql::tcp_connection& conn, std::string new_user_name, int id);
void sp_set_user_name_by_user_id(boost::mysql::tcp_connection& conn, std::string new_user_name, std::string user_id);
void sp_set_user_name_by_user_name(boost::mysql::tcp_connection& conn, std::string new_user_name, std::string user_name);
void sp_set_password_by_email(boost::mysql::tcp_connection& conn, std::string new_password, std::string email);
void sp_set_password_by_id(boost::mysql::tcp_connection& conn, std::string new_password, int id);
void sp_set_password_by_user_id(boost::mysql::tcp_connection& conn, std::string new_password, std::string user_id);
void sp_set_password_by_user_name(boost::mysql::tcp_connection& conn, std::string new_password, std::string user_name);
void sp_set_email_by_email(boost::mysql::tcp_connection& conn, std::string new_email, std::string email);
void sp_set_email_by_id(boost::mysql::tcp_connection& conn, std::string new_email, int id);
void sp_set_email_by_user_id(boost::mysql::tcp_connection& conn, std::string new_email, std::string user_id);
void sp_set_email_by_user_name(boost::mysql::tcp_connection& conn, std::string new_email, std::string user_name);
void sp_set_created_at_by_email(boost::mysql::tcp_connection& conn, boost::mysql::datetime new_created_at, std::string email);
void sp_set_created_at_by_id(boost::mysql::tcp_connection& conn, boost::mysql::datetime new_created_at, int id);
void sp_set_created_at_by_user_id(boost::mysql::tcp_connection& conn, boost::mysql::datetime new_created_at, std::string user_id);
void sp_set_created_at_by_user_name(boost::mysql::tcp_connection& conn, boost::mysql::datetime new_created_at, std::string user_name);
void sp_delete_by_email(boost::mysql::tcp_connection& conn, std::string email);
void sp_delete_by_id(boost::mysql::tcp_connection& conn, int id);
void sp_delete_by_user_id(boost::mysql::tcp_connection& conn, std::string user_id);
void sp_delete_by_user_name(boost::mysql::tcp_connection& conn, std::string user_name);

// 구현부

void ORM::insert(boost::mysql::tcp_connection& conn, const user_account& obj) {
    conn.execute("INSERT INTO user_account (user_id, user_name, password, email, created_at) VALUES (?, ?, ?, ?, ?)",
                 obj.user_id, obj.user_name, obj.password, obj.email, obj.created_at);
}


std::vector<user_account> ORM::select_all(boost::mysql::tcp_connection& conn) {
    boost::mysql::results result;
    conn.execute("SELECT * FROM user_account", result);
    std::vector<user_account> objects;
    for (const auto& row : result.rows()) {
        user_account obj;
        obj.id = row[0].as_int64();
        obj.user_id = row[1].as_string();
        obj.user_name = row[2].as_string();
        obj.password = row[3].as_string();
        obj.email = row[4].as_string();
        obj.created_at = boost::mysql::datetime(row[5].as_datetime());
        obj.updated_at = boost::mysql::datetime(row[6].as_datetime());
        objects.push_back(obj);
    }
    return objects;
}


std::vector<user_account> ORM::select_all_by_email(boost::mysql::tcp_connection& conn, std::string email) {
    boost::mysql::results result;
    conn.execute("SELECT * FROM user_account WHERE email = ?",
                 email);
    std::vector<user_account> objects;
    for (const auto& row : result.rows()) {
        user_account obj;
        obj.id = row[0].as_int64();
        obj.user_id = row[1].as_string();
        obj.user_name = row[2].as_string();
        obj.password = row[3].as_string();
        obj.email = row[4].as_string();
        obj.created_at = boost::mysql::datetime(row[5].as_datetime());
        obj.updated_at = boost::mysql::datetime(row[6].as_datetime());
        objects.push_back(obj);
    }
    return objects;
}


std::vector<user_account> ORM::select_all_by_id(boost::mysql::tcp_connection& conn, int id) {
    boost::mysql::results result;
    conn.execute("SELECT * FROM user_account WHERE id = ?",
                 id);
    std::vector<user_account> objects;
    for (const auto& row : result.rows()) {
        user_account obj;
        obj.id = row[0].as_int64();
        obj.user_id = row[1].as_string();
        obj.user_name = row[2].as_string();
        obj.password = row[3].as_string();
        obj.email = row[4].as_string();
        obj.created_at = boost::mysql::datetime(row[5].as_datetime());
        obj.updated_at = boost::mysql::datetime(row[6].as_datetime());
        objects.push_back(obj);
    }
    return objects;
}


std::vector<user_account> ORM::select_all_by_user_id(boost::mysql::tcp_connection& conn, std::string user_id) {
    boost::mysql::results result;
    conn.execute("SELECT * FROM user_account WHERE user_id = ?",
                 user_id);
    std::vector<user_account> objects;
    for (const auto& row : result.rows()) {
        user_account obj;
        obj.id = row[0].as_int64();
        obj.user_id = row[1].as_string();
        obj.user_name = row[2].as_string();
        obj.password = row[3].as_string();
        obj.email = row[4].as_string();
        obj.created_at = boost::mysql::datetime(row[5].as_datetime());
        obj.updated_at = boost::mysql::datetime(row[6].as_datetime());
        objects.push_back(obj);
    }
    return objects;
}


std::vector<user_account> ORM::select_all_by_user_name(boost::mysql::tcp_connection& conn, std::string user_name) {
    boost::mysql::results result;
    conn.execute("SELECT * FROM user_account WHERE user_name = ?",
                 user_name);
    std::vector<user_account> objects;
    for (const auto& row : result.rows()) {
        user_account obj;
        obj.id = row[0].as_int64();
        obj.user_id = row[1].as_string();
        obj.user_name = row[2].as_string();
        obj.password = row[3].as_string();
        obj.email = row[4].as_string();
        obj.created_at = boost::mysql::datetime(row[5].as_datetime());
        obj.updated_at = boost::mysql::datetime(row[6].as_datetime());
        objects.push_back(obj);
    }
    return objects;
}


void ORM::update_user_id_by_email(boost::mysql::tcp_connection& conn, std::string new_user_id, std::string email) {
    conn.execute("UPDATE user_account SET user_id = ? WHERE email = ?",
                 new_user_id, email);
}


void ORM::update_user_id_by_id(boost::mysql::tcp_connection& conn, std::string new_user_id, int id) {
    conn.execute("UPDATE user_account SET user_id = ? WHERE id = ?",
                 new_user_id, id);
}


void ORM::update_user_id_by_user_id(boost::mysql::tcp_connection& conn, std::string new_user_id, std::string user_id) {
    conn.execute("UPDATE user_account SET user_id = ? WHERE user_id = ?",
                 new_user_id, user_id);
}


void ORM::update_user_id_by_user_name(boost::mysql::tcp_connection& conn, std::string new_user_id, std::string user_name) {
    conn.execute("UPDATE user_account SET user_id = ? WHERE user_name = ?",
                 new_user_id, user_name);
}


void ORM::update_user_name_by_email(boost::mysql::tcp_connection& conn, std::string new_user_name, std::string email) {
    conn.execute("UPDATE user_account SET user_name = ? WHERE email = ?",
                 new_user_name, email);
}


void ORM::update_user_name_by_id(boost::mysql::tcp_connection& conn, std::string new_user_name, int id) {
    conn.execute("UPDATE user_account SET user_name = ? WHERE id = ?",
                 new_user_name, id);
}


void ORM::update_user_name_by_user_id(boost::mysql::tcp_connection& conn, std::string new_user_name, std::string user_id) {
    conn.execute("UPDATE user_account SET user_name = ? WHERE user_id = ?",
                 new_user_name, user_id);
}


void ORM::update_user_name_by_user_name(boost::mysql::tcp_connection& conn, std::string new_user_name, std::string user_name) {
    conn.execute("UPDATE user_account SET user_name = ? WHERE user_name = ?",
                 new_user_name, user_name);
}


void ORM::update_password_by_email(boost::mysql::tcp_connection& conn, std::string new_password, std::string email) {
    conn.execute("UPDATE user_account SET password = ? WHERE email = ?",
                 new_password, email);
}


void ORM::update_password_by_id(boost::mysql::tcp_connection& conn, std::string new_password, int id) {
    conn.execute("UPDATE user_account SET password = ? WHERE id = ?",
                 new_password, id);
}


void ORM::update_password_by_user_id(boost::mysql::tcp_connection& conn, std::string new_password, std::string user_id) {
    conn.execute("UPDATE user_account SET password = ? WHERE user_id = ?",
                 new_password, user_id);
}


void ORM::update_password_by_user_name(boost::mysql::tcp_connection& conn, std::string new_password, std::string user_name) {
    conn.execute("UPDATE user_account SET password = ? WHERE user_name = ?",
                 new_password, user_name);
}


void ORM::update_email_by_email(boost::mysql::tcp_connection& conn, std::string new_email, std::string email) {
    conn.execute("UPDATE user_account SET email = ? WHERE email = ?",
                 new_email, email);
}


void ORM::update_email_by_id(boost::mysql::tcp_connection& conn, std::string new_email, int id) {
    conn.execute("UPDATE user_account SET email = ? WHERE id = ?",
                 new_email, id);
}


void ORM::update_email_by_user_id(boost::mysql::tcp_connection& conn, std::string new_email, std::string user_id) {
    conn.execute("UPDATE user_account SET email = ? WHERE user_id = ?",
                 new_email, user_id);
}


void ORM::update_email_by_user_name(boost::mysql::tcp_connection& conn, std::string new_email, std::string user_name) {
    conn.execute("UPDATE user_account SET email = ? WHERE user_name = ?",
                 new_email, user_name);
}


void ORM::update_created_at_by_email(boost::mysql::tcp_connection& conn, boost::mysql::datetime new_created_at, std::string email) {
    conn.execute("UPDATE user_account SET created_at = ? WHERE email = ?",
                 new_created_at, email);
}


void ORM::update_created_at_by_id(boost::mysql::tcp_connection& conn, boost::mysql::datetime new_created_at, int id) {
    conn.execute("UPDATE user_account SET created_at = ? WHERE id = ?",
                 new_created_at, id);
}


void ORM::update_created_at_by_user_id(boost::mysql::tcp_connection& conn, boost::mysql::datetime new_created_at, std::string user_id) {
    conn.execute("UPDATE user_account SET created_at = ? WHERE user_id = ?",
                 new_created_at, user_id);
}


void ORM::update_created_at_by_user_name(boost::mysql::tcp_connection& conn, boost::mysql::datetime new_created_at, std::string user_name) {
    conn.execute("UPDATE user_account SET created_at = ? WHERE user_name = ?",
                 new_created_at, user_name);
}


void ORM::delete_by_email(boost::mysql::tcp_connection& conn, std::string email) {
    conn.execute("DELETE FROM user_account WHERE email = ?",
                 email);
}


void ORM::delete_by_id(boost::mysql::tcp_connection& conn, int id) {
    conn.execute("DELETE FROM user_account WHERE id = ?",
                 id);
}


void ORM::delete_by_user_id(boost::mysql::tcp_connection& conn, std::string user_id) {
    conn.execute("DELETE FROM user_account WHERE user_id = ?",
                 user_id);
}


void ORM::delete_by_user_name(boost::mysql::tcp_connection& conn, std::string user_name) {
    conn.execute("DELETE FROM user_account WHERE user_name = ?",
                 user_name);
}


    void ORM::sp_insert(boost::mysql::tcp_connection& conn, const user_account& obj) {
        try {
            auto stmt = conn.prepare_statement("CALL sp_73(?, ?, ?, ?, ?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(obj.user_id, obj.user_name, obj.password, obj.email, obj.created_at), result);
            std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        } catch (const boost::mysql::error_with_diagnostics& e) {
            std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        }
    }
    

    std::vector<user_account> ORM::sp_select_all(boost::mysql::tcp_connection& conn) {
        std::vector<user_account> objects;
        try {
            auto stmt = conn.prepare_statement("CALL sp_74()");
            boost::mysql::results result;
            conn.execute(stmt.bind(), result);
            for (const auto& row : result.rows()) {
                user_account obj;
                obj.id = row[0].as_int64();
            obj.user_id = row[1].as_string();
            obj.user_name = row[2].as_string();
            obj.password = row[3].as_string();
            obj.email = row[4].as_string();
            obj.created_at = boost::mysql::datetime(row[5].as_datetime());
            obj.updated_at = boost::mysql::datetime(row[6].as_datetime());
                objects.push_back(obj);
            }
        } catch (const boost::mysql::error_with_diagnostics& e) {
            std::cerr << "Error in sp_select_all: " << e.what() << std::endl;
        }
        return objects;
    }
    

    std::vector<user_account> ORM::sp_select_all_by_email(boost::mysql::tcp_connection& conn, std::string email) {
        std::vector<user_account> objects;
        try {
            auto stmt = conn.prepare_statement("CALL sp_75(?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(email), result);
            for (const auto& row : result.rows()) {
                user_account obj;
                obj.id = row[0].as_int64();
            obj.user_id = row[1].as_string();
            obj.user_name = row[2].as_string();
            obj.password = row[3].as_string();
            obj.email = row[4].as_string();
            obj.created_at = boost::mysql::datetime(row[5].as_datetime());
            obj.updated_at = boost::mysql::datetime(row[6].as_datetime());
                objects.push_back(obj);
            }
        } catch (const boost::mysql::error_with_diagnostics& e) {
            std::cerr << "Error in sp_select_all_by_email: " << e.what() << std::endl;
        }
        return objects;
    }
    

    std::vector<user_account> ORM::sp_select_all_by_id(boost::mysql::tcp_connection& conn, int id) {
        std::vector<user_account> objects;
        try {
            auto stmt = conn.prepare_statement("CALL sp_76(?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(id), result);
            for (const auto& row : result.rows()) {
                user_account obj;
                obj.id = row[0].as_int64();
            obj.user_id = row[1].as_string();
            obj.user_name = row[2].as_string();
            obj.password = row[3].as_string();
            obj.email = row[4].as_string();
            obj.created_at = boost::mysql::datetime(row[5].as_datetime());
            obj.updated_at = boost::mysql::datetime(row[6].as_datetime());
                objects.push_back(obj);
            }
        } catch (const boost::mysql::error_with_diagnostics& e) {
            std::cerr << "Error in sp_select_all_by_id: " << e.what() << std::endl;
        }
        return objects;
    }
    

    std::vector<user_account> ORM::sp_select_all_by_user_id(boost::mysql::tcp_connection& conn, std::string user_id) {
        std::vector<user_account> objects;
        try {
            auto stmt = conn.prepare_statement("CALL sp_77(?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(user_id), result);
            for (const auto& row : result.rows()) {
                user_account obj;
                obj.id = row[0].as_int64();
            obj.user_id = row[1].as_string();
            obj.user_name = row[2].as_string();
            obj.password = row[3].as_string();
            obj.email = row[4].as_string();
            obj.created_at = boost::mysql::datetime(row[5].as_datetime());
            obj.updated_at = boost::mysql::datetime(row[6].as_datetime());
                objects.push_back(obj);
            }
        } catch (const boost::mysql::error_with_diagnostics& e) {
            std::cerr << "Error in sp_select_all_by_user_id: " << e.what() << std::endl;
        }
        return objects;
    }
    

    std::vector<user_account> ORM::sp_select_all_by_user_name(boost::mysql::tcp_connection& conn, std::string user_name) {
        std::vector<user_account> objects;
        try {
            auto stmt = conn.prepare_statement("CALL sp_78(?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(user_name), result);
            for (const auto& row : result.rows()) {
                user_account obj;
                obj.id = row[0].as_int64();
            obj.user_id = row[1].as_string();
            obj.user_name = row[2].as_string();
            obj.password = row[3].as_string();
            obj.email = row[4].as_string();
            obj.created_at = boost::mysql::datetime(row[5].as_datetime());
            obj.updated_at = boost::mysql::datetime(row[6].as_datetime());
                objects.push_back(obj);
            }
        } catch (const boost::mysql::error_with_diagnostics& e) {
            std::cerr << "Error in sp_select_all_by_user_name: " << e.what() << std::endl;
        }
        return objects;
    }
    

    void ORM::sp_set_user_id_by_email(boost::mysql::tcp_connection& conn, std::string new_user_id, std::string email) {
        try {
            auto stmt = conn.prepare_statement("CALL sp_79(?, ?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(new_user_id, email), result);
            std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        } catch (const boost::mysql::error_with_diagnostics& e) {
            std::cerr << "Error in sp_set_user_id_by_email: " << e.what() << std::endl;
        }
    }
    

    void ORM::sp_set_user_id_by_id(boost::mysql::tcp_connection& conn, std::string new_user_id, int id) {
        try {
            auto stmt = conn.prepare_statement("CALL sp_80(?, ?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(new_user_id, id), result);
            std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        } catch (const boost::mysql::error_with_diagnostics& e) {
            std::cerr << "Error in sp_set_user_id_by_id: " << e.what() << std::endl;
        }
    }
    

    void ORM::sp_set_user_id_by_user_id(boost::mysql::tcp_connection& conn, std::string new_user_id, std::string user_id) {
        try {
            auto stmt = conn.prepare_statement("CALL sp_81(?, ?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(new_user_id, user_id), result);
            std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        } catch (const boost::mysql::error_with_diagnostics& e) {
            std::cerr << "Error in sp_set_user_id_by_user_id: " << e.what() << std::endl;
        }
    }
    

    void ORM::sp_set_user_id_by_user_name(boost::mysql::tcp_connection& conn, std::string new_user_id, std::string user_name) {
        try {
            auto stmt = conn.prepare_statement("CALL sp_82(?, ?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(new_user_id, user_name), result);
            std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        } catch (const boost::mysql::error_with_diagnostics& e) {
            std::cerr << "Error in sp_set_user_id_by_user_name: " << e.what() << std::endl;
        }
    }
    

    void ORM::sp_set_user_name_by_email(boost::mysql::tcp_connection& conn, std::string new_user_name, std::string email) {
        try {
            auto stmt = conn.prepare_statement("CALL sp_83(?, ?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(new_user_name, email), result);
            std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        } catch (const boost::mysql::error_with_diagnostics& e) {
            std::cerr << "Error in sp_set_user_name_by_email: " << e.what() << std::endl;
        }
    }
    

    void ORM::sp_set_user_name_by_id(boost::mysql::tcp_connection& conn, std::string new_user_name, int id) {
        try {
            auto stmt = conn.prepare_statement("CALL sp_84(?, ?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(new_user_name, id), result);
            std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        } catch (const boost::mysql::error_with_diagnostics& e) {
            std::cerr << "Error in sp_set_user_name_by_id: " << e.what() << std::endl;
        }
    }
    

    void ORM::sp_set_user_name_by_user_id(boost::mysql::tcp_connection& conn, std::string new_user_name, std::string user_id) {
        try {
            auto stmt = conn.prepare_statement("CALL sp_85(?, ?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(new_user_name, user_id), result);
            std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        } catch (const boost::mysql::error_with_diagnostics& e) {
            std::cerr << "Error in sp_set_user_name_by_user_id: " << e.what() << std::endl;
        }
    }
    

    void ORM::sp_set_user_name_by_user_name(boost::mysql::tcp_connection& conn, std::string new_user_name, std::string user_name) {
        try {
            auto stmt = conn.prepare_statement("CALL sp_86(?, ?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(new_user_name, user_name), result);
            std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        } catch (const boost::mysql::error_with_diagnostics& e) {
            std::cerr << "Error in sp_set_user_name_by_user_name: " << e.what() << std::endl;
        }
    }
    

    void ORM::sp_set_password_by_email(boost::mysql::tcp_connection& conn, std::string new_password, std::string email) {
        try {
            auto stmt = conn.prepare_statement("CALL sp_87(?, ?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(new_password, email), result);
            std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        } catch (const boost::mysql::error_with_diagnostics& e) {
            std::cerr << "Error in sp_set_password_by_email: " << e.what() << std::endl;
        }
    }
    

    void ORM::sp_set_password_by_id(boost::mysql::tcp_connection& conn, std::string new_password, int id) {
        try {
            auto stmt = conn.prepare_statement("CALL sp_88(?, ?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(new_password, id), result);
            std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        } catch (const boost::mysql::error_with_diagnostics& e) {
            std::cerr << "Error in sp_set_password_by_id: " << e.what() << std::endl;
        }
    }
    

    void ORM::sp_set_password_by_user_id(boost::mysql::tcp_connection& conn, std::string new_password, std::string user_id) {
        try {
            auto stmt = conn.prepare_statement("CALL sp_89(?, ?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(new_password, user_id), result);
            std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        } catch (const boost::mysql::error_with_diagnostics& e) {
            std::cerr << "Error in sp_set_password_by_user_id: " << e.what() << std::endl;
        }
    }
    

    void ORM::sp_set_password_by_user_name(boost::mysql::tcp_connection& conn, std::string new_password, std::string user_name) {
        try {
            auto stmt = conn.prepare_statement("CALL sp_90(?, ?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(new_password, user_name), result);
            std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        } catch (const boost::mysql::error_with_diagnostics& e) {
            std::cerr << "Error in sp_set_password_by_user_name: " << e.what() << std::endl;
        }
    }
    

    void ORM::sp_set_email_by_email(boost::mysql::tcp_connection& conn, std::string new_email, std::string email) {
        try {
            auto stmt = conn.prepare_statement("CALL sp_91(?, ?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(new_email, email), result);
            std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        } catch (const boost::mysql::error_with_diagnostics& e) {
            std::cerr << "Error in sp_set_email_by_email: " << e.what() << std::endl;
        }
    }
    

    void ORM::sp_set_email_by_id(boost::mysql::tcp_connection& conn, std::string new_email, int id) {
        try {
            auto stmt = conn.prepare_statement("CALL sp_92(?, ?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(new_email, id), result);
            std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        } catch (const boost::mysql::error_with_diagnostics& e) {
            std::cerr << "Error in sp_set_email_by_id: " << e.what() << std::endl;
        }
    }
    

    void ORM::sp_set_email_by_user_id(boost::mysql::tcp_connection& conn, std::string new_email, std::string user_id) {
        try {
            auto stmt = conn.prepare_statement("CALL sp_93(?, ?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(new_email, user_id), result);
            std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        } catch (const boost::mysql::error_with_diagnostics& e) {
            std::cerr << "Error in sp_set_email_by_user_id: " << e.what() << std::endl;
        }
    }
    

    void ORM::sp_set_email_by_user_name(boost::mysql::tcp_connection& conn, std::string new_email, std::string user_name) {
        try {
            auto stmt = conn.prepare_statement("CALL sp_94(?, ?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(new_email, user_name), result);
            std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        } catch (const boost::mysql::error_with_diagnostics& e) {
            std::cerr << "Error in sp_set_email_by_user_name: " << e.what() << std::endl;
        }
    }
    

    void ORM::sp_set_created_at_by_email(boost::mysql::tcp_connection& conn, boost::mysql::datetime new_created_at, std::string email) {
        try {
            auto stmt = conn.prepare_statement("CALL sp_95(?, ?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(new_created_at, email), result);
            std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        } catch (const boost::mysql::error_with_diagnostics& e) {
            std::cerr << "Error in sp_set_created_at_by_email: " << e.what() << std::endl;
        }
    }
    

    void ORM::sp_set_created_at_by_id(boost::mysql::tcp_connection& conn, boost::mysql::datetime new_created_at, int id) {
        try {
            auto stmt = conn.prepare_statement("CALL sp_96(?, ?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(new_created_at, id), result);
            std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        } catch (const boost::mysql::error_with_diagnostics& e) {
            std::cerr << "Error in sp_set_created_at_by_id: " << e.what() << std::endl;
        }
    }
    

    void ORM::sp_set_created_at_by_user_id(boost::mysql::tcp_connection& conn, boost::mysql::datetime new_created_at, std::string user_id) {
        try {
            auto stmt = conn.prepare_statement("CALL sp_97(?, ?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(new_created_at, user_id), result);
            std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        } catch (const boost::mysql::error_with_diagnostics& e) {
            std::cerr << "Error in sp_set_created_at_by_user_id: " << e.what() << std::endl;
        }
    }
    

    void ORM::sp_set_created_at_by_user_name(boost::mysql::tcp_connection& conn, boost::mysql::datetime new_created_at, std::string user_name) {
        try {
            auto stmt = conn.prepare_statement("CALL sp_98(?, ?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(new_created_at, user_name), result);
            std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        } catch (const boost::mysql::error_with_diagnostics& e) {
            std::cerr << "Error in sp_set_created_at_by_user_name: " << e.what() << std::endl;
        }
    }
    

    void ORM::sp_delete_by_email(boost::mysql::tcp_connection& conn, std::string email) {
        try {
            auto stmt = conn.prepare_statement("CALL sp_103(?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(email), result);
            std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        } catch (const boost::mysql::error_with_diagnostics& e) {
            std::cerr << "Error in sp_delete_by_email: " << e.what() << std::endl;
        }
    }
    

    void ORM::sp_delete_by_id(boost::mysql::tcp_connection& conn, int id) {
        try {
            auto stmt = conn.prepare_statement("CALL sp_104(?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(id), result);
            std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        } catch (const boost::mysql::error_with_diagnostics& e) {
            std::cerr << "Error in sp_delete_by_id: " << e.what() << std::endl;
        }
    }
    

    void ORM::sp_delete_by_user_id(boost::mysql::tcp_connection& conn, std::string user_id) {
        try {
            auto stmt = conn.prepare_statement("CALL sp_105(?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(user_id), result);
            std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        } catch (const boost::mysql::error_with_diagnostics& e) {
            std::cerr << "Error in sp_delete_by_user_id: " << e.what() << std::endl;
        }
    }
    

    void ORM::sp_delete_by_user_name(boost::mysql::tcp_connection& conn, std::string user_name) {
        try {
            auto stmt = conn.prepare_statement("CALL sp_106(?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(user_name), result);
            std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        } catch (const boost::mysql::error_with_diagnostics& e) {
            std::cerr << "Error in sp_delete_by_user_name: " << e.what() << std::endl;
        }
    }
    

} // namespace ORM
