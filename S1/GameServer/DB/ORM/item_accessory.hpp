
#pragma once

#include <boost/mysql.hpp>
#include <boost/mysql/tcp.hpp>
#include <boost/describe.hpp>
#include <vector>
#include <string>
#include <chrono>

namespace ORM {

struct item_accessory
{
    // 멤버 변수
    int id; // int
    std::string item_name; // varchar(30)
    std::string item_description; // text(65535)
    int item_effect; // int
};
BOOST_DESCRIBE_STRUCT(item_accessory, (), (id, item_name, item_description, item_effect));

// 데이터베이스 연산
void insert(boost::mysql::tcp_connection& conn, const item_accessory& obj);
std::vector<item_accessory> select_all(boost::mysql::tcp_connection& conn);
std::vector<item_accessory> select_all_by_id(boost::mysql::tcp_connection& conn, int id);
void update_item_name_by_id(boost::mysql::tcp_connection& conn, std::string new_item_name, int id);
void update_item_description_by_id(boost::mysql::tcp_connection& conn, std::string new_item_description, int id);
void update_item_effect_by_id(boost::mysql::tcp_connection& conn, int new_item_effect, int id);
void delete_by_id(boost::mysql::tcp_connection& conn, int id);

// 저장 프로시저 호출
void sp_insert(boost::mysql::tcp_connection& conn, const item_accessory& obj);
std::vector<item_accessory> sp_select_all(boost::mysql::tcp_connection& conn);
std::vector<item_accessory> sp_select_all_by_id(boost::mysql::tcp_connection& conn, int id);
void sp_set_item_name_by_id(boost::mysql::tcp_connection& conn, std::string new_item_name, int id);
void sp_set_item_description_by_id(boost::mysql::tcp_connection& conn, std::string new_item_description, int id);
void sp_set_item_effect_by_id(boost::mysql::tcp_connection& conn, int new_item_effect, int id);
void sp_delete_by_id(boost::mysql::tcp_connection& conn, int id);

// 구현부

void ORM::insert(boost::mysql::tcp_connection& conn, const item_accessory& obj) {
    conn.execute("INSERT INTO item_accessory (id, item_name, item_description, item_effect) VALUES (?, ?, ?, ?)",
                 obj.id, obj.item_name, obj.item_description, obj.item_effect);
}


std::vector<item_accessory> ORM::select_all(boost::mysql::tcp_connection& conn) {
    boost::mysql::results result;
    conn.execute("SELECT * FROM item_accessory", result);
    std::vector<item_accessory> objects;
    for (const auto& row : result.rows()) {
        item_accessory obj;
        obj.id = row[0].as_int64();
        obj.item_name = row[1].as_string();
        obj.item_description = row[2].as_string();
        obj.item_effect = row[3].as_int64();
        objects.push_back(obj);
    }
    return objects;
}


std::vector<item_accessory> ORM::select_all_by_id(boost::mysql::tcp_connection& conn, int id) {
    boost::mysql::results result;
    conn.execute("SELECT * FROM item_accessory WHERE id = ?",
                 id);
    std::vector<item_accessory> objects;
    for (const auto& row : result.rows()) {
        item_accessory obj;
        obj.id = row[0].as_int64();
        obj.item_name = row[1].as_string();
        obj.item_description = row[2].as_string();
        obj.item_effect = row[3].as_int64();
        objects.push_back(obj);
    }
    return objects;
}


void ORM::update_item_name_by_id(boost::mysql::tcp_connection& conn, std::string new_item_name, int id) {
    conn.execute("UPDATE item_accessory SET item_name = ? WHERE id = ?",
                 new_item_name, id);
}


void ORM::update_item_description_by_id(boost::mysql::tcp_connection& conn, std::string new_item_description, int id) {
    conn.execute("UPDATE item_accessory SET item_description = ? WHERE id = ?",
                 new_item_description, id);
}


void ORM::update_item_effect_by_id(boost::mysql::tcp_connection& conn, int new_item_effect, int id) {
    conn.execute("UPDATE item_accessory SET item_effect = ? WHERE id = ?",
                 new_item_effect, id);
}


void ORM::delete_by_id(boost::mysql::tcp_connection& conn, int id) {
    conn.execute("DELETE FROM item_accessory WHERE id = ?",
                 id);
}


    void ORM::sp_insert(boost::mysql::tcp_connection& conn, const item_accessory& obj) {
        try {
            auto stmt = conn.prepare_statement("CALL sp_21(?, ?, ?, ?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(obj.id, obj.item_name, obj.item_description, obj.item_effect), result);
            std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        } catch (const boost::mysql::error_with_diagnostics& e) {
            std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        }
    }
    

    std::vector<item_accessory> ORM::sp_select_all(boost::mysql::tcp_connection& conn) {
        std::vector<item_accessory> objects;
        try {
            auto stmt = conn.prepare_statement("CALL sp_22()");
            boost::mysql::results result;
            conn.execute(stmt.bind(), result);
            for (const auto& row : result.rows()) {
                item_accessory obj;
                obj.id = row[0].as_int64();
            obj.item_name = row[1].as_string();
            obj.item_description = row[2].as_string();
            obj.item_effect = row[3].as_int64();
                objects.push_back(obj);
            }
        } catch (const boost::mysql::error_with_diagnostics& e) {
            std::cerr << "Error in sp_select_all: " << e.what() << std::endl;
        }
        return objects;
    }
    

    std::vector<item_accessory> ORM::sp_select_all_by_id(boost::mysql::tcp_connection& conn, int id) {
        std::vector<item_accessory> objects;
        try {
            auto stmt = conn.prepare_statement("CALL sp_23(?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(id), result);
            for (const auto& row : result.rows()) {
                item_accessory obj;
                obj.id = row[0].as_int64();
            obj.item_name = row[1].as_string();
            obj.item_description = row[2].as_string();
            obj.item_effect = row[3].as_int64();
                objects.push_back(obj);
            }
        } catch (const boost::mysql::error_with_diagnostics& e) {
            std::cerr << "Error in sp_select_all_by_id: " << e.what() << std::endl;
        }
        return objects;
    }
    

    void ORM::sp_set_item_name_by_id(boost::mysql::tcp_connection& conn, std::string new_item_name, int id) {
        try {
            auto stmt = conn.prepare_statement("CALL sp_25(?, ?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(new_item_name, id), result);
            std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        } catch (const boost::mysql::error_with_diagnostics& e) {
            std::cerr << "Error in sp_set_item_name_by_id: " << e.what() << std::endl;
        }
    }
    

    void ORM::sp_set_item_description_by_id(boost::mysql::tcp_connection& conn, std::string new_item_description, int id) {
        try {
            auto stmt = conn.prepare_statement("CALL sp_26(?, ?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(new_item_description, id), result);
            std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        } catch (const boost::mysql::error_with_diagnostics& e) {
            std::cerr << "Error in sp_set_item_description_by_id: " << e.what() << std::endl;
        }
    }
    

    void ORM::sp_set_item_effect_by_id(boost::mysql::tcp_connection& conn, int new_item_effect, int id) {
        try {
            auto stmt = conn.prepare_statement("CALL sp_27(?, ?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(new_item_effect, id), result);
            std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        } catch (const boost::mysql::error_with_diagnostics& e) {
            std::cerr << "Error in sp_set_item_effect_by_id: " << e.what() << std::endl;
        }
    }
    

    void ORM::sp_delete_by_id(boost::mysql::tcp_connection& conn, int id) {
        try {
            auto stmt = conn.prepare_statement("CALL sp_28(?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(id), result);
            std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        } catch (const boost::mysql::error_with_diagnostics& e) {
            std::cerr << "Error in sp_delete_by_id: " << e.what() << std::endl;
        }
    }
    

} // namespace ORM
