
#pragma once

#include <boost/mysql.hpp>
#include <boost/mysql/tcp.hpp>
#include <boost/describe.hpp>
#include <vector>
#include <string>
#include <chrono>

namespace ORM {

struct user_character
{
    // 멤버 변수
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

// 데이터베이스 연산
void insert(boost::mysql::tcp_connection& conn, const user_character& obj);
std::vector<user_character> select_all(boost::mysql::tcp_connection& conn);
std::vector<user_character> select_all_by_character_name(boost::mysql::tcp_connection& conn, std::string character_name);
std::vector<user_character> select_all_by_user_account_id(boost::mysql::tcp_connection& conn, int user_account_id);
std::vector<user_character> select_all_by_id(boost::mysql::tcp_connection& conn, int id);
void update_user_account_id_by_character_name(boost::mysql::tcp_connection& conn, int new_user_account_id, std::string character_name);
void update_user_account_id_by_user_account_id(boost::mysql::tcp_connection& conn, int new_user_account_id, int user_account_id);
void update_user_account_id_by_id(boost::mysql::tcp_connection& conn, int new_user_account_id, int id);
void update_character_name_by_character_name(boost::mysql::tcp_connection& conn, std::string new_character_name, std::string character_name);
void update_character_name_by_user_account_id(boost::mysql::tcp_connection& conn, std::string new_character_name, int user_account_id);
void update_character_name_by_id(boost::mysql::tcp_connection& conn, std::string new_character_name, int id);
void update_level_by_character_name(boost::mysql::tcp_connection& conn, int new_level, std::string character_name);
void update_level_by_user_account_id(boost::mysql::tcp_connection& conn, int new_level, int user_account_id);
void update_level_by_id(boost::mysql::tcp_connection& conn, int new_level, int id);
void update_experience_by_character_name(boost::mysql::tcp_connection& conn, long long new_experience, std::string character_name);
void update_experience_by_user_account_id(boost::mysql::tcp_connection& conn, long long new_experience, int user_account_id);
void update_experience_by_id(boost::mysql::tcp_connection& conn, long long new_experience, int id);
void update_gold_by_character_name(boost::mysql::tcp_connection& conn, long long new_gold, std::string character_name);
void update_gold_by_user_account_id(boost::mysql::tcp_connection& conn, long long new_gold, int user_account_id);
void update_gold_by_id(boost::mysql::tcp_connection& conn, long long new_gold, int id);
void update_created_at_by_character_name(boost::mysql::tcp_connection& conn, boost::mysql::datetime new_created_at, std::string character_name);
void update_created_at_by_user_account_id(boost::mysql::tcp_connection& conn, boost::mysql::datetime new_created_at, int user_account_id);
void update_created_at_by_id(boost::mysql::tcp_connection& conn, boost::mysql::datetime new_created_at, int id);
void delete_by_character_name(boost::mysql::tcp_connection& conn, std::string character_name);
void delete_by_user_account_id(boost::mysql::tcp_connection& conn, int user_account_id);
void delete_by_id(boost::mysql::tcp_connection& conn, int id);

// 저장 프로시저 호출
void sp_insert(boost::mysql::tcp_connection& conn, const user_character& obj);
std::vector<user_character> sp_select_all(boost::mysql::tcp_connection& conn);
std::vector<user_character> sp_select_all_by_character_name(boost::mysql::tcp_connection& conn, std::string character_name);
std::vector<user_character> sp_select_all_by_user_account_id(boost::mysql::tcp_connection& conn, int user_account_id);
std::vector<user_character> sp_select_all_by_id(boost::mysql::tcp_connection& conn, int id);
void sp_set_user_account_id_by_character_name(boost::mysql::tcp_connection& conn, int new_user_account_id, std::string character_name);
void sp_set_user_account_id_by_user_account_id(boost::mysql::tcp_connection& conn, int new_user_account_id, int user_account_id);
void sp_set_user_account_id_by_id(boost::mysql::tcp_connection& conn, int new_user_account_id, int id);
void sp_set_character_name_by_character_name(boost::mysql::tcp_connection& conn, std::string new_character_name, std::string character_name);
void sp_set_character_name_by_user_account_id(boost::mysql::tcp_connection& conn, std::string new_character_name, int user_account_id);
void sp_set_character_name_by_id(boost::mysql::tcp_connection& conn, std::string new_character_name, int id);
void sp_set_level_by_character_name(boost::mysql::tcp_connection& conn, int new_level, std::string character_name);
void sp_set_level_by_user_account_id(boost::mysql::tcp_connection& conn, int new_level, int user_account_id);
void sp_set_level_by_id(boost::mysql::tcp_connection& conn, int new_level, int id);
void sp_set_experience_by_character_name(boost::mysql::tcp_connection& conn, long long new_experience, std::string character_name);
void sp_set_experience_by_user_account_id(boost::mysql::tcp_connection& conn, long long new_experience, int user_account_id);
void sp_set_experience_by_id(boost::mysql::tcp_connection& conn, long long new_experience, int id);
void sp_set_gold_by_character_name(boost::mysql::tcp_connection& conn, long long new_gold, std::string character_name);
void sp_set_gold_by_user_account_id(boost::mysql::tcp_connection& conn, long long new_gold, int user_account_id);
void sp_set_gold_by_id(boost::mysql::tcp_connection& conn, long long new_gold, int id);
void sp_set_created_at_by_character_name(boost::mysql::tcp_connection& conn, boost::mysql::datetime new_created_at, std::string character_name);
void sp_set_created_at_by_user_account_id(boost::mysql::tcp_connection& conn, boost::mysql::datetime new_created_at, int user_account_id);
void sp_set_created_at_by_id(boost::mysql::tcp_connection& conn, boost::mysql::datetime new_created_at, int id);
void sp_delete_by_character_name(boost::mysql::tcp_connection& conn, std::string character_name);
void sp_delete_by_user_account_id(boost::mysql::tcp_connection& conn, int user_account_id);
void sp_delete_by_id(boost::mysql::tcp_connection& conn, int id);

// 구현부

void ORM::insert(boost::mysql::tcp_connection& conn, const user_character& obj) {
    conn.execute("INSERT INTO user_character (user_account_id, character_name, level, experience, gold, created_at) VALUES (?, ?, ?, ?, ?, ?)",
                 obj.user_account_id, obj.character_name, obj.level, obj.experience, obj.gold, obj.created_at);
}


std::vector<user_character> ORM::select_all(boost::mysql::tcp_connection& conn) {
    boost::mysql::results result;
    conn.execute("SELECT * FROM user_character", result);
    std::vector<user_character> objects;
    for (const auto& row : result.rows()) {
        user_character obj;
        obj.id = row[0].as_int64();
        obj.user_account_id = row[1].as_int64();
        obj.character_name = row[2].as_string();
        obj.level = row[3].as_int64();
        obj.experience = row[4].as_int64();
        obj.gold = row[5].as_int64();
        obj.created_at = boost::mysql::datetime(row[6].as_datetime());
        obj.updated_at = boost::mysql::datetime(row[7].as_datetime());
        objects.push_back(obj);
    }
    return objects;
}


std::vector<user_character> ORM::select_all_by_character_name(boost::mysql::tcp_connection& conn, std::string character_name) {
    boost::mysql::results result;
    conn.execute("SELECT * FROM user_character WHERE character_name = ?",
                 character_name);
    std::vector<user_character> objects;
    for (const auto& row : result.rows()) {
        user_character obj;
        obj.id = row[0].as_int64();
        obj.user_account_id = row[1].as_int64();
        obj.character_name = row[2].as_string();
        obj.level = row[3].as_int64();
        obj.experience = row[4].as_int64();
        obj.gold = row[5].as_int64();
        obj.created_at = boost::mysql::datetime(row[6].as_datetime());
        obj.updated_at = boost::mysql::datetime(row[7].as_datetime());
        objects.push_back(obj);
    }
    return objects;
}


std::vector<user_character> ORM::select_all_by_user_account_id(boost::mysql::tcp_connection& conn, int user_account_id) {
    boost::mysql::results result;
    conn.execute("SELECT * FROM user_character WHERE user_account_id = ?",
                 user_account_id);
    std::vector<user_character> objects;
    for (const auto& row : result.rows()) {
        user_character obj;
        obj.id = row[0].as_int64();
        obj.user_account_id = row[1].as_int64();
        obj.character_name = row[2].as_string();
        obj.level = row[3].as_int64();
        obj.experience = row[4].as_int64();
        obj.gold = row[5].as_int64();
        obj.created_at = boost::mysql::datetime(row[6].as_datetime());
        obj.updated_at = boost::mysql::datetime(row[7].as_datetime());
        objects.push_back(obj);
    }
    return objects;
}


std::vector<user_character> ORM::select_all_by_id(boost::mysql::tcp_connection& conn, int id) {
    boost::mysql::results result;
    conn.execute("SELECT * FROM user_character WHERE id = ?",
                 id);
    std::vector<user_character> objects;
    for (const auto& row : result.rows()) {
        user_character obj;
        obj.id = row[0].as_int64();
        obj.user_account_id = row[1].as_int64();
        obj.character_name = row[2].as_string();
        obj.level = row[3].as_int64();
        obj.experience = row[4].as_int64();
        obj.gold = row[5].as_int64();
        obj.created_at = boost::mysql::datetime(row[6].as_datetime());
        obj.updated_at = boost::mysql::datetime(row[7].as_datetime());
        objects.push_back(obj);
    }
    return objects;
}


void ORM::update_user_account_id_by_character_name(boost::mysql::tcp_connection& conn, int new_user_account_id, std::string character_name) {
    conn.execute("UPDATE user_character SET user_account_id = ? WHERE character_name = ?",
                 new_user_account_id, character_name);
}


void ORM::update_user_account_id_by_user_account_id(boost::mysql::tcp_connection& conn, int new_user_account_id, int user_account_id) {
    conn.execute("UPDATE user_character SET user_account_id = ? WHERE user_account_id = ?",
                 new_user_account_id, user_account_id);
}


void ORM::update_user_account_id_by_id(boost::mysql::tcp_connection& conn, int new_user_account_id, int id) {
    conn.execute("UPDATE user_character SET user_account_id = ? WHERE id = ?",
                 new_user_account_id, id);
}


void ORM::update_character_name_by_character_name(boost::mysql::tcp_connection& conn, std::string new_character_name, std::string character_name) {
    conn.execute("UPDATE user_character SET character_name = ? WHERE character_name = ?",
                 new_character_name, character_name);
}


void ORM::update_character_name_by_user_account_id(boost::mysql::tcp_connection& conn, std::string new_character_name, int user_account_id) {
    conn.execute("UPDATE user_character SET character_name = ? WHERE user_account_id = ?",
                 new_character_name, user_account_id);
}


void ORM::update_character_name_by_id(boost::mysql::tcp_connection& conn, std::string new_character_name, int id) {
    conn.execute("UPDATE user_character SET character_name = ? WHERE id = ?",
                 new_character_name, id);
}


void ORM::update_level_by_character_name(boost::mysql::tcp_connection& conn, int new_level, std::string character_name) {
    conn.execute("UPDATE user_character SET level = ? WHERE character_name = ?",
                 new_level, character_name);
}


void ORM::update_level_by_user_account_id(boost::mysql::tcp_connection& conn, int new_level, int user_account_id) {
    conn.execute("UPDATE user_character SET level = ? WHERE user_account_id = ?",
                 new_level, user_account_id);
}


void ORM::update_level_by_id(boost::mysql::tcp_connection& conn, int new_level, int id) {
    conn.execute("UPDATE user_character SET level = ? WHERE id = ?",
                 new_level, id);
}


void ORM::update_experience_by_character_name(boost::mysql::tcp_connection& conn, long long new_experience, std::string character_name) {
    conn.execute("UPDATE user_character SET experience = ? WHERE character_name = ?",
                 new_experience, character_name);
}


void ORM::update_experience_by_user_account_id(boost::mysql::tcp_connection& conn, long long new_experience, int user_account_id) {
    conn.execute("UPDATE user_character SET experience = ? WHERE user_account_id = ?",
                 new_experience, user_account_id);
}


void ORM::update_experience_by_id(boost::mysql::tcp_connection& conn, long long new_experience, int id) {
    conn.execute("UPDATE user_character SET experience = ? WHERE id = ?",
                 new_experience, id);
}


void ORM::update_gold_by_character_name(boost::mysql::tcp_connection& conn, long long new_gold, std::string character_name) {
    conn.execute("UPDATE user_character SET gold = ? WHERE character_name = ?",
                 new_gold, character_name);
}


void ORM::update_gold_by_user_account_id(boost::mysql::tcp_connection& conn, long long new_gold, int user_account_id) {
    conn.execute("UPDATE user_character SET gold = ? WHERE user_account_id = ?",
                 new_gold, user_account_id);
}


void ORM::update_gold_by_id(boost::mysql::tcp_connection& conn, long long new_gold, int id) {
    conn.execute("UPDATE user_character SET gold = ? WHERE id = ?",
                 new_gold, id);
}


void ORM::update_created_at_by_character_name(boost::mysql::tcp_connection& conn, boost::mysql::datetime new_created_at, std::string character_name) {
    conn.execute("UPDATE user_character SET created_at = ? WHERE character_name = ?",
                 new_created_at, character_name);
}


void ORM::update_created_at_by_user_account_id(boost::mysql::tcp_connection& conn, boost::mysql::datetime new_created_at, int user_account_id) {
    conn.execute("UPDATE user_character SET created_at = ? WHERE user_account_id = ?",
                 new_created_at, user_account_id);
}


void ORM::update_created_at_by_id(boost::mysql::tcp_connection& conn, boost::mysql::datetime new_created_at, int id) {
    conn.execute("UPDATE user_character SET created_at = ? WHERE id = ?",
                 new_created_at, id);
}


void ORM::delete_by_character_name(boost::mysql::tcp_connection& conn, std::string character_name) {
    conn.execute("DELETE FROM user_character WHERE character_name = ?",
                 character_name);
}


void ORM::delete_by_user_account_id(boost::mysql::tcp_connection& conn, int user_account_id) {
    conn.execute("DELETE FROM user_character WHERE user_account_id = ?",
                 user_account_id);
}


void ORM::delete_by_id(boost::mysql::tcp_connection& conn, int id) {
    conn.execute("DELETE FROM user_character WHERE id = ?",
                 id);
}


    void ORM::sp_insert(boost::mysql::tcp_connection& conn, const user_character& obj) {
        try {
            auto stmt = conn.prepare_statement("CALL sp_141(?, ?, ?, ?, ?, ?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(obj.user_account_id, obj.character_name, obj.level, obj.experience, obj.gold, obj.created_at), result);
            std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        } catch (const boost::mysql::error_with_diagnostics& e) {
            std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        }
    }
    

    std::vector<user_character> ORM::sp_select_all(boost::mysql::tcp_connection& conn) {
        std::vector<user_character> objects;
        try {
            auto stmt = conn.prepare_statement("CALL sp_142()");
            boost::mysql::results result;
            conn.execute(stmt.bind(), result);
            for (const auto& row : result.rows()) {
                user_character obj;
                obj.id = row[0].as_int64();
            obj.user_account_id = row[1].as_int64();
            obj.character_name = row[2].as_string();
            obj.level = row[3].as_int64();
            obj.experience = row[4].as_int64();
            obj.gold = row[5].as_int64();
            obj.created_at = boost::mysql::datetime(row[6].as_datetime());
            obj.updated_at = boost::mysql::datetime(row[7].as_datetime());
                objects.push_back(obj);
            }
        } catch (const boost::mysql::error_with_diagnostics& e) {
            std::cerr << "Error in sp_select_all: " << e.what() << std::endl;
        }
        return objects;
    }
    

    std::vector<user_character> ORM::sp_select_all_by_character_name(boost::mysql::tcp_connection& conn, std::string character_name) {
        std::vector<user_character> objects;
        try {
            auto stmt = conn.prepare_statement("CALL sp_143(?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(character_name), result);
            for (const auto& row : result.rows()) {
                user_character obj;
                obj.id = row[0].as_int64();
            obj.user_account_id = row[1].as_int64();
            obj.character_name = row[2].as_string();
            obj.level = row[3].as_int64();
            obj.experience = row[4].as_int64();
            obj.gold = row[5].as_int64();
            obj.created_at = boost::mysql::datetime(row[6].as_datetime());
            obj.updated_at = boost::mysql::datetime(row[7].as_datetime());
                objects.push_back(obj);
            }
        } catch (const boost::mysql::error_with_diagnostics& e) {
            std::cerr << "Error in sp_select_all_by_character_name: " << e.what() << std::endl;
        }
        return objects;
    }
    

    std::vector<user_character> ORM::sp_select_all_by_user_account_id(boost::mysql::tcp_connection& conn, int user_account_id) {
        std::vector<user_character> objects;
        try {
            auto stmt = conn.prepare_statement("CALL sp_144(?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(user_account_id), result);
            for (const auto& row : result.rows()) {
                user_character obj;
                obj.id = row[0].as_int64();
            obj.user_account_id = row[1].as_int64();
            obj.character_name = row[2].as_string();
            obj.level = row[3].as_int64();
            obj.experience = row[4].as_int64();
            obj.gold = row[5].as_int64();
            obj.created_at = boost::mysql::datetime(row[6].as_datetime());
            obj.updated_at = boost::mysql::datetime(row[7].as_datetime());
                objects.push_back(obj);
            }
        } catch (const boost::mysql::error_with_diagnostics& e) {
            std::cerr << "Error in sp_select_all_by_user_account_id: " << e.what() << std::endl;
        }
        return objects;
    }
    

    std::vector<user_character> ORM::sp_select_all_by_id(boost::mysql::tcp_connection& conn, int id) {
        std::vector<user_character> objects;
        try {
            auto stmt = conn.prepare_statement("CALL sp_145(?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(id), result);
            for (const auto& row : result.rows()) {
                user_character obj;
                obj.id = row[0].as_int64();
            obj.user_account_id = row[1].as_int64();
            obj.character_name = row[2].as_string();
            obj.level = row[3].as_int64();
            obj.experience = row[4].as_int64();
            obj.gold = row[5].as_int64();
            obj.created_at = boost::mysql::datetime(row[6].as_datetime());
            obj.updated_at = boost::mysql::datetime(row[7].as_datetime());
                objects.push_back(obj);
            }
        } catch (const boost::mysql::error_with_diagnostics& e) {
            std::cerr << "Error in sp_select_all_by_id: " << e.what() << std::endl;
        }
        return objects;
    }
    

    void ORM::sp_set_user_account_id_by_character_name(boost::mysql::tcp_connection& conn, int new_user_account_id, std::string character_name) {
        try {
            auto stmt = conn.prepare_statement("CALL sp_146(?, ?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(new_user_account_id, character_name), result);
            std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        } catch (const boost::mysql::error_with_diagnostics& e) {
            std::cerr << "Error in sp_set_user_account_id_by_character_name: " << e.what() << std::endl;
        }
    }
    

    void ORM::sp_set_user_account_id_by_user_account_id(boost::mysql::tcp_connection& conn, int new_user_account_id, int user_account_id) {
        try {
            auto stmt = conn.prepare_statement("CALL sp_147(?, ?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(new_user_account_id, user_account_id), result);
            std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        } catch (const boost::mysql::error_with_diagnostics& e) {
            std::cerr << "Error in sp_set_user_account_id_by_user_account_id: " << e.what() << std::endl;
        }
    }
    

    void ORM::sp_set_user_account_id_by_id(boost::mysql::tcp_connection& conn, int new_user_account_id, int id) {
        try {
            auto stmt = conn.prepare_statement("CALL sp_148(?, ?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(new_user_account_id, id), result);
            std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        } catch (const boost::mysql::error_with_diagnostics& e) {
            std::cerr << "Error in sp_set_user_account_id_by_id: " << e.what() << std::endl;
        }
    }
    

    void ORM::sp_set_character_name_by_character_name(boost::mysql::tcp_connection& conn, std::string new_character_name, std::string character_name) {
        try {
            auto stmt = conn.prepare_statement("CALL sp_149(?, ?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(new_character_name, character_name), result);
            std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        } catch (const boost::mysql::error_with_diagnostics& e) {
            std::cerr << "Error in sp_set_character_name_by_character_name: " << e.what() << std::endl;
        }
    }
    

    void ORM::sp_set_character_name_by_user_account_id(boost::mysql::tcp_connection& conn, std::string new_character_name, int user_account_id) {
        try {
            auto stmt = conn.prepare_statement("CALL sp_150(?, ?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(new_character_name, user_account_id), result);
            std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        } catch (const boost::mysql::error_with_diagnostics& e) {
            std::cerr << "Error in sp_set_character_name_by_user_account_id: " << e.what() << std::endl;
        }
    }
    

    void ORM::sp_set_character_name_by_id(boost::mysql::tcp_connection& conn, std::string new_character_name, int id) {
        try {
            auto stmt = conn.prepare_statement("CALL sp_151(?, ?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(new_character_name, id), result);
            std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        } catch (const boost::mysql::error_with_diagnostics& e) {
            std::cerr << "Error in sp_set_character_name_by_id: " << e.what() << std::endl;
        }
    }
    

    void ORM::sp_set_level_by_character_name(boost::mysql::tcp_connection& conn, int new_level, std::string character_name) {
        try {
            auto stmt = conn.prepare_statement("CALL sp_152(?, ?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(new_level, character_name), result);
            std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        } catch (const boost::mysql::error_with_diagnostics& e) {
            std::cerr << "Error in sp_set_level_by_character_name: " << e.what() << std::endl;
        }
    }
    

    void ORM::sp_set_level_by_user_account_id(boost::mysql::tcp_connection& conn, int new_level, int user_account_id) {
        try {
            auto stmt = conn.prepare_statement("CALL sp_153(?, ?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(new_level, user_account_id), result);
            std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        } catch (const boost::mysql::error_with_diagnostics& e) {
            std::cerr << "Error in sp_set_level_by_user_account_id: " << e.what() << std::endl;
        }
    }
    

    void ORM::sp_set_level_by_id(boost::mysql::tcp_connection& conn, int new_level, int id) {
        try {
            auto stmt = conn.prepare_statement("CALL sp_154(?, ?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(new_level, id), result);
            std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        } catch (const boost::mysql::error_with_diagnostics& e) {
            std::cerr << "Error in sp_set_level_by_id: " << e.what() << std::endl;
        }
    }
    

    void ORM::sp_set_experience_by_character_name(boost::mysql::tcp_connection& conn, long long new_experience, std::string character_name) {
        try {
            auto stmt = conn.prepare_statement("CALL sp_155(?, ?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(new_experience, character_name), result);
            std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        } catch (const boost::mysql::error_with_diagnostics& e) {
            std::cerr << "Error in sp_set_experience_by_character_name: " << e.what() << std::endl;
        }
    }
    

    void ORM::sp_set_experience_by_user_account_id(boost::mysql::tcp_connection& conn, long long new_experience, int user_account_id) {
        try {
            auto stmt = conn.prepare_statement("CALL sp_156(?, ?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(new_experience, user_account_id), result);
            std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        } catch (const boost::mysql::error_with_diagnostics& e) {
            std::cerr << "Error in sp_set_experience_by_user_account_id: " << e.what() << std::endl;
        }
    }
    

    void ORM::sp_set_experience_by_id(boost::mysql::tcp_connection& conn, long long new_experience, int id) {
        try {
            auto stmt = conn.prepare_statement("CALL sp_157(?, ?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(new_experience, id), result);
            std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        } catch (const boost::mysql::error_with_diagnostics& e) {
            std::cerr << "Error in sp_set_experience_by_id: " << e.what() << std::endl;
        }
    }
    

    void ORM::sp_set_gold_by_character_name(boost::mysql::tcp_connection& conn, long long new_gold, std::string character_name) {
        try {
            auto stmt = conn.prepare_statement("CALL sp_158(?, ?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(new_gold, character_name), result);
            std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        } catch (const boost::mysql::error_with_diagnostics& e) {
            std::cerr << "Error in sp_set_gold_by_character_name: " << e.what() << std::endl;
        }
    }
    

    void ORM::sp_set_gold_by_user_account_id(boost::mysql::tcp_connection& conn, long long new_gold, int user_account_id) {
        try {
            auto stmt = conn.prepare_statement("CALL sp_159(?, ?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(new_gold, user_account_id), result);
            std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        } catch (const boost::mysql::error_with_diagnostics& e) {
            std::cerr << "Error in sp_set_gold_by_user_account_id: " << e.what() << std::endl;
        }
    }
    

    void ORM::sp_set_gold_by_id(boost::mysql::tcp_connection& conn, long long new_gold, int id) {
        try {
            auto stmt = conn.prepare_statement("CALL sp_160(?, ?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(new_gold, id), result);
            std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        } catch (const boost::mysql::error_with_diagnostics& e) {
            std::cerr << "Error in sp_set_gold_by_id: " << e.what() << std::endl;
        }
    }
    

    void ORM::sp_set_created_at_by_character_name(boost::mysql::tcp_connection& conn, boost::mysql::datetime new_created_at, std::string character_name) {
        try {
            auto stmt = conn.prepare_statement("CALL sp_161(?, ?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(new_created_at, character_name), result);
            std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        } catch (const boost::mysql::error_with_diagnostics& e) {
            std::cerr << "Error in sp_set_created_at_by_character_name: " << e.what() << std::endl;
        }
    }
    

    void ORM::sp_set_created_at_by_user_account_id(boost::mysql::tcp_connection& conn, boost::mysql::datetime new_created_at, int user_account_id) {
        try {
            auto stmt = conn.prepare_statement("CALL sp_162(?, ?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(new_created_at, user_account_id), result);
            std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        } catch (const boost::mysql::error_with_diagnostics& e) {
            std::cerr << "Error in sp_set_created_at_by_user_account_id: " << e.what() << std::endl;
        }
    }
    

    void ORM::sp_set_created_at_by_id(boost::mysql::tcp_connection& conn, boost::mysql::datetime new_created_at, int id) {
        try {
            auto stmt = conn.prepare_statement("CALL sp_163(?, ?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(new_created_at, id), result);
            std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        } catch (const boost::mysql::error_with_diagnostics& e) {
            std::cerr << "Error in sp_set_created_at_by_id: " << e.what() << std::endl;
        }
    }
    

    void ORM::sp_delete_by_character_name(boost::mysql::tcp_connection& conn, std::string character_name) {
        try {
            auto stmt = conn.prepare_statement("CALL sp_167(?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(character_name), result);
            std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        } catch (const boost::mysql::error_with_diagnostics& e) {
            std::cerr << "Error in sp_delete_by_character_name: " << e.what() << std::endl;
        }
    }
    

    void ORM::sp_delete_by_user_account_id(boost::mysql::tcp_connection& conn, int user_account_id) {
        try {
            auto stmt = conn.prepare_statement("CALL sp_168(?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(user_account_id), result);
            std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        } catch (const boost::mysql::error_with_diagnostics& e) {
            std::cerr << "Error in sp_delete_by_user_account_id: " << e.what() << std::endl;
        }
    }
    

    void ORM::sp_delete_by_id(boost::mysql::tcp_connection& conn, int id) {
        try {
            auto stmt = conn.prepare_statement("CALL sp_169(?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(id), result);
            std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        } catch (const boost::mysql::error_with_diagnostics& e) {
            std::cerr << "Error in sp_delete_by_id: " << e.what() << std::endl;
        }
    }
    

} // namespace ORM
