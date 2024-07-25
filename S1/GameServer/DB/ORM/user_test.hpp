
#pragma once

#include <boost/mysql.hpp>
#include <boost/mysql/tcp.hpp>
#include <boost/describe.hpp>
#include <vector>
#include <string>
#include <chrono>

namespace ORM {

struct user_test
{
    // 멤버 변수
    int id; // int
    std::string username; // varchar(32)
    std::string password; // varchar(32)
    std::string email; // varchar(64)
    boost::mysql::datetime created_at; // timestamp
    boost::mysql::datetime updated_at; // timestamp
};
BOOST_DESCRIBE_STRUCT(user_test, (), (id, username, password, email, created_at, updated_at));

// 데이터베이스 연산
void insert(boost::mysql::tcp_connection& conn, const user_test& obj);
std::vector<user_test> select_all(boost::mysql::tcp_connection& conn);
std::vector<user_test> select_all_by_email(boost::mysql::tcp_connection& conn, std::string email);
std::vector<user_test> select_all_by_id(boost::mysql::tcp_connection& conn, int id);
void update_username_by_email(boost::mysql::tcp_connection& conn, std::string new_username, std::string email);
void update_username_by_id(boost::mysql::tcp_connection& conn, std::string new_username, int id);
void update_password_by_email(boost::mysql::tcp_connection& conn, std::string new_password, std::string email);
void update_password_by_id(boost::mysql::tcp_connection& conn, std::string new_password, int id);
void update_email_by_email(boost::mysql::tcp_connection& conn, std::string new_email, std::string email);
void update_email_by_id(boost::mysql::tcp_connection& conn, std::string new_email, int id);
void update_created_at_by_email(boost::mysql::tcp_connection& conn, boost::mysql::datetime new_created_at, std::string email);
void update_created_at_by_id(boost::mysql::tcp_connection& conn, boost::mysql::datetime new_created_at, int id);
void delete_by_email(boost::mysql::tcp_connection& conn, std::string email);
void delete_by_id(boost::mysql::tcp_connection& conn, int id);

// 저장 프로시저 호출
void sp_insert(boost::mysql::tcp_connection& conn, const user_test& obj);
std::vector<user_test> sp_select_all(boost::mysql::tcp_connection& conn);
std::vector<user_test> sp_select_all_by_email(boost::mysql::tcp_connection& conn, std::string email);
std::vector<user_test> sp_select_all_by_id(boost::mysql::tcp_connection& conn, int id);
void sp_set_username_by_email(boost::mysql::tcp_connection& conn, std::string new_username, std::string email);
void sp_set_username_by_id(boost::mysql::tcp_connection& conn, std::string new_username, int id);
void sp_set_password_by_email(boost::mysql::tcp_connection& conn, std::string new_password, std::string email);
void sp_set_password_by_id(boost::mysql::tcp_connection& conn, std::string new_password, int id);
void sp_set_email_by_email(boost::mysql::tcp_connection& conn, std::string new_email, std::string email);
void sp_set_email_by_id(boost::mysql::tcp_connection& conn, std::string new_email, int id);
void sp_set_created_at_by_email(boost::mysql::tcp_connection& conn, boost::mysql::datetime new_created_at, std::string email);
void sp_set_created_at_by_id(boost::mysql::tcp_connection& conn, boost::mysql::datetime new_created_at, int id);
void sp_delete_by_email(boost::mysql::tcp_connection& conn, std::string email);
void sp_delete_by_id(boost::mysql::tcp_connection& conn, int id);

// 구현부

void ORM::insert(boost::mysql::tcp_connection& conn, const user_test& obj) {
    conn.execute("INSERT INTO user_test (username, password, email, created_at) VALUES (?, ?, ?, ?)",
                 obj.username, obj.password, obj.email, obj.created_at);
}


std::vector<user_test> ORM::select_all(boost::mysql::tcp_connection& conn) {
    boost::mysql::results result;
    conn.execute("SELECT * FROM user_test", result);
    std::vector<user_test> objects;
    for (const auto& row : result.rows()) {
        user_test obj;
        obj.id = row[0].as_int64();
        obj.username = row[1].as_string();
        obj.password = row[2].as_string();
        obj.email = row[3].as_string();
        obj.created_at = boost::mysql::datetime(row[4].as_datetime());
        obj.updated_at = boost::mysql::datetime(row[5].as_datetime());
        objects.push_back(obj);
    }
    return objects;
}


std::vector<user_test> ORM::select_all_by_email(boost::mysql::tcp_connection& conn, std::string email) {
    boost::mysql::results result;
    conn.execute("SELECT * FROM user_test WHERE email = ?",
                 email);
    std::vector<user_test> objects;
    for (const auto& row : result.rows()) {
        user_test obj;
        obj.id = row[0].as_int64();
        obj.username = row[1].as_string();
        obj.password = row[2].as_string();
        obj.email = row[3].as_string();
        obj.created_at = boost::mysql::datetime(row[4].as_datetime());
        obj.updated_at = boost::mysql::datetime(row[5].as_datetime());
        objects.push_back(obj);
    }
    return objects;
}


std::vector<user_test> ORM::select_all_by_id(boost::mysql::tcp_connection& conn, int id) {
    boost::mysql::results result;
    conn.execute("SELECT * FROM user_test WHERE id = ?",
                 id);
    std::vector<user_test> objects;
    for (const auto& row : result.rows()) {
        user_test obj;
        obj.id = row[0].as_int64();
        obj.username = row[1].as_string();
        obj.password = row[2].as_string();
        obj.email = row[3].as_string();
        obj.created_at = boost::mysql::datetime(row[4].as_datetime());
        obj.updated_at = boost::mysql::datetime(row[5].as_datetime());
        objects.push_back(obj);
    }
    return objects;
}


void ORM::update_username_by_email(boost::mysql::tcp_connection& conn, std::string new_username, std::string email) {
    conn.execute("UPDATE user_test SET username = ? WHERE email = ?",
                 new_username, email);
}


void ORM::update_username_by_id(boost::mysql::tcp_connection& conn, std::string new_username, int id) {
    conn.execute("UPDATE user_test SET username = ? WHERE id = ?",
                 new_username, id);
}


void ORM::update_password_by_email(boost::mysql::tcp_connection& conn, std::string new_password, std::string email) {
    conn.execute("UPDATE user_test SET password = ? WHERE email = ?",
                 new_password, email);
}


void ORM::update_password_by_id(boost::mysql::tcp_connection& conn, std::string new_password, int id) {
    conn.execute("UPDATE user_test SET password = ? WHERE id = ?",
                 new_password, id);
}


void ORM::update_email_by_email(boost::mysql::tcp_connection& conn, std::string new_email, std::string email) {
    conn.execute("UPDATE user_test SET email = ? WHERE email = ?",
                 new_email, email);
}


void ORM::update_email_by_id(boost::mysql::tcp_connection& conn, std::string new_email, int id) {
    conn.execute("UPDATE user_test SET email = ? WHERE id = ?",
                 new_email, id);
}


void ORM::update_created_at_by_email(boost::mysql::tcp_connection& conn, boost::mysql::datetime new_created_at, std::string email) {
    conn.execute("UPDATE user_test SET created_at = ? WHERE email = ?",
                 new_created_at, email);
}


void ORM::update_created_at_by_id(boost::mysql::tcp_connection& conn, boost::mysql::datetime new_created_at, int id) {
    conn.execute("UPDATE user_test SET created_at = ? WHERE id = ?",
                 new_created_at, id);
}


void ORM::delete_by_email(boost::mysql::tcp_connection& conn, std::string email) {
    conn.execute("DELETE FROM user_test WHERE email = ?",
                 email);
}


void ORM::delete_by_id(boost::mysql::tcp_connection& conn, int id) {
    conn.execute("DELETE FROM user_test WHERE id = ?",
                 id);
}


    void ORM::sp_insert(boost::mysql::tcp_connection& conn, const user_test& obj) {
        try {
            auto stmt = conn.prepare_statement("CALL sp_231(?, ?, ?, ?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(obj.username, obj.password, obj.email, obj.created_at), result);
            std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        } catch (const boost::mysql::error_with_diagnostics& e) {
            std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        }
    }
    

    std::vector<user_test> ORM::sp_select_all(boost::mysql::tcp_connection& conn) {
        std::vector<user_test> objects;
        try {
            auto stmt = conn.prepare_statement("CALL sp_232()");
            boost::mysql::results result;
            conn.execute(stmt.bind(), result);
            for (const auto& row : result.rows()) {
                user_test obj;
                obj.id = row[0].as_int64();
            obj.username = row[1].as_string();
            obj.password = row[2].as_string();
            obj.email = row[3].as_string();
            obj.created_at = boost::mysql::datetime(row[4].as_datetime());
            obj.updated_at = boost::mysql::datetime(row[5].as_datetime());
                objects.push_back(obj);
            }
        } catch (const boost::mysql::error_with_diagnostics& e) {
            std::cerr << "Error in sp_select_all: " << e.what() << std::endl;
        }
        return objects;
    }
    

    std::vector<user_test> ORM::sp_select_all_by_email(boost::mysql::tcp_connection& conn, std::string email) {
        std::vector<user_test> objects;
        try {
            auto stmt = conn.prepare_statement("CALL sp_233(?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(email), result);
            for (const auto& row : result.rows()) {
                user_test obj;
                obj.id = row[0].as_int64();
            obj.username = row[1].as_string();
            obj.password = row[2].as_string();
            obj.email = row[3].as_string();
            obj.created_at = boost::mysql::datetime(row[4].as_datetime());
            obj.updated_at = boost::mysql::datetime(row[5].as_datetime());
                objects.push_back(obj);
            }
        } catch (const boost::mysql::error_with_diagnostics& e) {
            std::cerr << "Error in sp_select_all_by_email: " << e.what() << std::endl;
        }
        return objects;
    }
    

    std::vector<user_test> ORM::sp_select_all_by_id(boost::mysql::tcp_connection& conn, int id) {
        std::vector<user_test> objects;
        try {
            auto stmt = conn.prepare_statement("CALL sp_234(?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(id), result);
            for (const auto& row : result.rows()) {
                user_test obj;
                obj.id = row[0].as_int64();
            obj.username = row[1].as_string();
            obj.password = row[2].as_string();
            obj.email = row[3].as_string();
            obj.created_at = boost::mysql::datetime(row[4].as_datetime());
            obj.updated_at = boost::mysql::datetime(row[5].as_datetime());
                objects.push_back(obj);
            }
        } catch (const boost::mysql::error_with_diagnostics& e) {
            std::cerr << "Error in sp_select_all_by_id: " << e.what() << std::endl;
        }
        return objects;
    }
    

    void ORM::sp_set_username_by_email(boost::mysql::tcp_connection& conn, std::string new_username, std::string email) {
        try {
            auto stmt = conn.prepare_statement("CALL sp_235(?, ?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(new_username, email), result);
            std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        } catch (const boost::mysql::error_with_diagnostics& e) {
            std::cerr << "Error in sp_set_username_by_email: " << e.what() << std::endl;
        }
    }
    

    void ORM::sp_set_username_by_id(boost::mysql::tcp_connection& conn, std::string new_username, int id) {
        try {
            auto stmt = conn.prepare_statement("CALL sp_236(?, ?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(new_username, id), result);
            std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        } catch (const boost::mysql::error_with_diagnostics& e) {
            std::cerr << "Error in sp_set_username_by_id: " << e.what() << std::endl;
        }
    }
    

    void ORM::sp_set_password_by_email(boost::mysql::tcp_connection& conn, std::string new_password, std::string email) {
        try {
            auto stmt = conn.prepare_statement("CALL sp_237(?, ?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(new_password, email), result);
            std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        } catch (const boost::mysql::error_with_diagnostics& e) {
            std::cerr << "Error in sp_set_password_by_email: " << e.what() << std::endl;
        }
    }
    

    void ORM::sp_set_password_by_id(boost::mysql::tcp_connection& conn, std::string new_password, int id) {
        try {
            auto stmt = conn.prepare_statement("CALL sp_238(?, ?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(new_password, id), result);
            std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        } catch (const boost::mysql::error_with_diagnostics& e) {
            std::cerr << "Error in sp_set_password_by_id: " << e.what() << std::endl;
        }
    }
    

    void ORM::sp_set_email_by_email(boost::mysql::tcp_connection& conn, std::string new_email, std::string email) {
        try {
            auto stmt = conn.prepare_statement("CALL sp_239(?, ?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(new_email, email), result);
            std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        } catch (const boost::mysql::error_with_diagnostics& e) {
            std::cerr << "Error in sp_set_email_by_email: " << e.what() << std::endl;
        }
    }
    

    void ORM::sp_set_email_by_id(boost::mysql::tcp_connection& conn, std::string new_email, int id) {
        try {
            auto stmt = conn.prepare_statement("CALL sp_240(?, ?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(new_email, id), result);
            std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        } catch (const boost::mysql::error_with_diagnostics& e) {
            std::cerr << "Error in sp_set_email_by_id: " << e.what() << std::endl;
        }
    }
    

    void ORM::sp_set_created_at_by_email(boost::mysql::tcp_connection& conn, boost::mysql::datetime new_created_at, std::string email) {
        try {
            auto stmt = conn.prepare_statement("CALL sp_241(?, ?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(new_created_at, email), result);
            std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        } catch (const boost::mysql::error_with_diagnostics& e) {
            std::cerr << "Error in sp_set_created_at_by_email: " << e.what() << std::endl;
        }
    }
    

    void ORM::sp_set_created_at_by_id(boost::mysql::tcp_connection& conn, boost::mysql::datetime new_created_at, int id) {
        try {
            auto stmt = conn.prepare_statement("CALL sp_242(?, ?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(new_created_at, id), result);
            std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        } catch (const boost::mysql::error_with_diagnostics& e) {
            std::cerr << "Error in sp_set_created_at_by_id: " << e.what() << std::endl;
        }
    }
    

    void ORM::sp_delete_by_email(boost::mysql::tcp_connection& conn, std::string email) {
        try {
            auto stmt = conn.prepare_statement("CALL sp_245(?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(email), result);
            std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        } catch (const boost::mysql::error_with_diagnostics& e) {
            std::cerr << "Error in sp_delete_by_email: " << e.what() << std::endl;
        }
    }
    

    void ORM::sp_delete_by_id(boost::mysql::tcp_connection& conn, int id) {
        try {
            auto stmt = conn.prepare_statement("CALL sp_246(?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(id), result);
            std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        } catch (const boost::mysql::error_with_diagnostics& e) {
            std::cerr << "Error in sp_delete_by_id: " << e.what() << std::endl;
        }
    }
    

} // namespace ORM
