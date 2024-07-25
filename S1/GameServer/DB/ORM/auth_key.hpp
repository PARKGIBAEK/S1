
#pragma once

#include <boost/mysql.hpp>
#include <boost/mysql/tcp.hpp>
#include <boost/describe.hpp>
#include <vector>
#include <string>
#include <chrono>

namespace ORM {

struct auth_key
{
    // 멤버 변수
    int id; // int
    std::string key_value; // varchar(256)
    boost::mysql::datetime created_at; // timestamp
};
BOOST_DESCRIBE_STRUCT(auth_key, (), (id, key_value, created_at));

// 데이터베이스 연산
void insert(boost::mysql::tcp_connection& conn, const auth_key& obj);
std::vector<auth_key> select_all(boost::mysql::tcp_connection& conn);
std::vector<auth_key> select_all_by_key_value(boost::mysql::tcp_connection& conn, std::string key_value);
std::vector<auth_key> select_all_by_id(boost::mysql::tcp_connection& conn, int id);
void update_key_value_by_key_value(boost::mysql::tcp_connection& conn, std::string new_key_value, std::string key_value);
void update_key_value_by_id(boost::mysql::tcp_connection& conn, std::string new_key_value, int id);
void update_created_at_by_key_value(boost::mysql::tcp_connection& conn, boost::mysql::datetime new_created_at, std::string key_value);
void update_created_at_by_id(boost::mysql::tcp_connection& conn, boost::mysql::datetime new_created_at, int id);
void delete_by_key_value(boost::mysql::tcp_connection& conn, std::string key_value);
void delete_by_id(boost::mysql::tcp_connection& conn, int id);

// 저장 프로시저 호출
void sp_insert(boost::mysql::tcp_connection& conn, const auth_key& obj);
std::vector<auth_key> sp_select_all(boost::mysql::tcp_connection& conn);
std::vector<auth_key> sp_select_all_by_key_value(boost::mysql::tcp_connection& conn, std::string key_value);
std::vector<auth_key> sp_select_all_by_id(boost::mysql::tcp_connection& conn, int id);
void sp_set_key_value_by_key_value(boost::mysql::tcp_connection& conn, std::string new_key_value, std::string key_value);
void sp_set_key_value_by_id(boost::mysql::tcp_connection& conn, std::string new_key_value, int id);
void sp_set_created_at_by_key_value(boost::mysql::tcp_connection& conn, boost::mysql::datetime new_created_at, std::string key_value);
void sp_set_created_at_by_id(boost::mysql::tcp_connection& conn, boost::mysql::datetime new_created_at, int id);
void sp_delete_by_key_value(boost::mysql::tcp_connection& conn, std::string key_value);
void sp_delete_by_id(boost::mysql::tcp_connection& conn, int id);

// 구현부

void ORM::insert(boost::mysql::tcp_connection& conn, const auth_key& obj) {
    conn.execute("INSERT INTO auth_key (key_value, created_at) VALUES (?, ?)",
                 obj.key_value, obj.created_at);
}


std::vector<auth_key> ORM::select_all(boost::mysql::tcp_connection& conn) {
    boost::mysql::results result;
    conn.execute("SELECT * FROM auth_key", result);
    std::vector<auth_key> objects;
    for (const auto& row : result.rows()) {
        auth_key obj;
        obj.id = row[0].as_int64();
        obj.key_value = row[1].as_string();
        obj.created_at = boost::mysql::datetime(row[2].as_datetime());
        objects.push_back(obj);
    }
    return objects;
}


std::vector<auth_key> ORM::select_all_by_key_value(boost::mysql::tcp_connection& conn, std::string key_value) {
    boost::mysql::results result;
    conn.execute("SELECT * FROM auth_key WHERE key_value = ?",
                 key_value);
    std::vector<auth_key> objects;
    for (const auto& row : result.rows()) {
        auth_key obj;
        obj.id = row[0].as_int64();
        obj.key_value = row[1].as_string();
        obj.created_at = boost::mysql::datetime(row[2].as_datetime());
        objects.push_back(obj);
    }
    return objects;
}


std::vector<auth_key> ORM::select_all_by_id(boost::mysql::tcp_connection& conn, int id) {
    boost::mysql::results result;
    conn.execute("SELECT * FROM auth_key WHERE id = ?",
                 id);
    std::vector<auth_key> objects;
    for (const auto& row : result.rows()) {
        auth_key obj;
        obj.id = row[0].as_int64();
        obj.key_value = row[1].as_string();
        obj.created_at = boost::mysql::datetime(row[2].as_datetime());
        objects.push_back(obj);
    }
    return objects;
}


void ORM::update_key_value_by_key_value(boost::mysql::tcp_connection& conn, std::string new_key_value, std::string key_value) {
    conn.execute("UPDATE auth_key SET key_value = ? WHERE key_value = ?",
                 new_key_value, key_value);
}


void ORM::update_key_value_by_id(boost::mysql::tcp_connection& conn, std::string new_key_value, int id) {
    conn.execute("UPDATE auth_key SET key_value = ? WHERE id = ?",
                 new_key_value, id);
}


void ORM::update_created_at_by_key_value(boost::mysql::tcp_connection& conn, boost::mysql::datetime new_created_at, std::string key_value) {
    conn.execute("UPDATE auth_key SET created_at = ? WHERE key_value = ?",
                 new_created_at, key_value);
}


void ORM::update_created_at_by_id(boost::mysql::tcp_connection& conn, boost::mysql::datetime new_created_at, int id) {
    conn.execute("UPDATE auth_key SET created_at = ? WHERE id = ?",
                 new_created_at, id);
}


void ORM::delete_by_key_value(boost::mysql::tcp_connection& conn, std::string key_value) {
    conn.execute("DELETE FROM auth_key WHERE key_value = ?",
                 key_value);
}


void ORM::delete_by_id(boost::mysql::tcp_connection& conn, int id) {
    conn.execute("DELETE FROM auth_key WHERE id = ?",
                 id);
}


    void ORM::sp_insert(boost::mysql::tcp_connection& conn, const auth_key& obj) {
        try {
            auto stmt = conn.prepare_statement("CALL sp_1(?, ?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(obj.key_value, obj.created_at), result);
            std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        } catch (const boost::mysql::error_with_diagnostics& e) {
            std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        }
    }
    

    std::vector<auth_key> ORM::sp_select_all(boost::mysql::tcp_connection& conn) {
        std::vector<auth_key> objects;
        try {
            auto stmt = conn.prepare_statement("CALL sp_2()");
            boost::mysql::results result;
            conn.execute(stmt.bind(), result);
            for (const auto& row : result.rows()) {
                auth_key obj;
                obj.id = row[0].as_int64();
            obj.key_value = row[1].as_string();
            obj.created_at = boost::mysql::datetime(row[2].as_datetime());
                objects.push_back(obj);
            }
        } catch (const boost::mysql::error_with_diagnostics& e) {
            std::cerr << "Error in sp_select_all: " << e.what() << std::endl;
        }
        return objects;
    }
    

    std::vector<auth_key> ORM::sp_select_all_by_key_value(boost::mysql::tcp_connection& conn, std::string key_value) {
        std::vector<auth_key> objects;
        try {
            auto stmt = conn.prepare_statement("CALL sp_3(?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(key_value), result);
            for (const auto& row : result.rows()) {
                auth_key obj;
                obj.id = row[0].as_int64();
            obj.key_value = row[1].as_string();
            obj.created_at = boost::mysql::datetime(row[2].as_datetime());
                objects.push_back(obj);
            }
        } catch (const boost::mysql::error_with_diagnostics& e) {
            std::cerr << "Error in sp_select_all_by_key_value: " << e.what() << std::endl;
        }
        return objects;
    }
    

    std::vector<auth_key> ORM::sp_select_all_by_id(boost::mysql::tcp_connection& conn, int id) {
        std::vector<auth_key> objects;
        try {
            auto stmt = conn.prepare_statement("CALL sp_4(?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(id), result);
            for (const auto& row : result.rows()) {
                auth_key obj;
                obj.id = row[0].as_int64();
            obj.key_value = row[1].as_string();
            obj.created_at = boost::mysql::datetime(row[2].as_datetime());
                objects.push_back(obj);
            }
        } catch (const boost::mysql::error_with_diagnostics& e) {
            std::cerr << "Error in sp_select_all_by_id: " << e.what() << std::endl;
        }
        return objects;
    }
    

    void ORM::sp_set_key_value_by_key_value(boost::mysql::tcp_connection& conn, std::string new_key_value, std::string key_value) {
        try {
            auto stmt = conn.prepare_statement("CALL sp_5(?, ?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(new_key_value, key_value), result);
            std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        } catch (const boost::mysql::error_with_diagnostics& e) {
            std::cerr << "Error in sp_set_key_value_by_key_value: " << e.what() << std::endl;
        }
    }
    

    void ORM::sp_set_key_value_by_id(boost::mysql::tcp_connection& conn, std::string new_key_value, int id) {
        try {
            auto stmt = conn.prepare_statement("CALL sp_6(?, ?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(new_key_value, id), result);
            std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        } catch (const boost::mysql::error_with_diagnostics& e) {
            std::cerr << "Error in sp_set_key_value_by_id: " << e.what() << std::endl;
        }
    }
    

    void ORM::sp_set_created_at_by_key_value(boost::mysql::tcp_connection& conn, boost::mysql::datetime new_created_at, std::string key_value) {
        try {
            auto stmt = conn.prepare_statement("CALL sp_7(?, ?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(new_created_at, key_value), result);
            std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        } catch (const boost::mysql::error_with_diagnostics& e) {
            std::cerr << "Error in sp_set_created_at_by_key_value: " << e.what() << std::endl;
        }
    }
    

    void ORM::sp_set_created_at_by_id(boost::mysql::tcp_connection& conn, boost::mysql::datetime new_created_at, int id) {
        try {
            auto stmt = conn.prepare_statement("CALL sp_8(?, ?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(new_created_at, id), result);
            std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        } catch (const boost::mysql::error_with_diagnostics& e) {
            std::cerr << "Error in sp_set_created_at_by_id: " << e.what() << std::endl;
        }
    }
    

    void ORM::sp_delete_by_key_value(boost::mysql::tcp_connection& conn, std::string key_value) {
        try {
            auto stmt = conn.prepare_statement("CALL sp_9(?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(key_value), result);
            std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        } catch (const boost::mysql::error_with_diagnostics& e) {
            std::cerr << "Error in sp_delete_by_key_value: " << e.what() << std::endl;
        }
    }
    

    void ORM::sp_delete_by_id(boost::mysql::tcp_connection& conn, int id) {
        try {
            auto stmt = conn.prepare_statement("CALL sp_10(?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(id), result);
            std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        } catch (const boost::mysql::error_with_diagnostics& e) {
            std::cerr << "Error in sp_delete_by_id: " << e.what() << std::endl;
        }
    }
    

} // namespace ORM
