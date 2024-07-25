#pragma once

#include <boost/mysql.hpp>
#include <boost/mysql/tcp.hpp>
#include <boost/describe.hpp>
#include <vector>
#include <string>
#include <chrono>

namespace ORM
{
class orm_user_inventory
{
    struct user_inventory
    {
        // 멤버 변수
        int id; // int
        int user_character_id; // int
        int item_id; // int
        int item_quantity; // int
        boost::mysql::datetime created_at; // timestamp
        boost::mysql::datetime updated_at; // timestamp
    };
    BOOST_DESCRIBE_STRUCT(user_inventory, (), (id, user_character_id, item_id, item_quantity, created_at, updated_at));

public:
    // 데이터베이스 연산
    void insert(boost::mysql::tcp_connection& conn, const user_inventory& obj);
    std::vector<user_inventory> select_all(boost::mysql::tcp_connection& conn);
    std::vector<user_inventory> select_all_by_user_character_id(boost::mysql::tcp_connection& conn,
                                                                int user_character_id);
    std::vector<user_inventory> select_all_by_id(boost::mysql::tcp_connection& conn, int id);
    void update_user_character_id_by_user_character_id(boost::mysql::tcp_connection& conn, int new_user_character_id,
                                                       int user_character_id);
    void update_user_character_id_by_id(boost::mysql::tcp_connection& conn, int new_user_character_id, int id);
    void update_item_id_by_user_character_id(boost::mysql::tcp_connection& conn, int new_item_id,
                                             int user_character_id);
    void update_item_id_by_id(boost::mysql::tcp_connection& conn, int new_item_id, int id);
    void update_item_quantity_by_user_character_id(boost::mysql::tcp_connection& conn, int new_item_quantity,
                                                   int user_character_id);
    void update_item_quantity_by_id(boost::mysql::tcp_connection& conn, int new_item_quantity, int id);
    void update_created_at_by_user_character_id(boost::mysql::tcp_connection& conn,
                                                boost::mysql::datetime new_created_at, int user_character_id);
    void update_created_at_by_id(boost::mysql::tcp_connection& conn, boost::mysql::datetime new_created_at, int id);
    void delete_by_user_character_id(boost::mysql::tcp_connection& conn, int user_character_id);
    void delete_by_id(boost::mysql::tcp_connection& conn, int id);

    // 저장 프로시저 호출
    void sp_insert(boost::mysql::tcp_connection& conn, const user_inventory& obj);
    std::vector<user_inventory> sp_select_all(boost::mysql::tcp_connection& conn);
    std::vector<user_inventory> sp_select_all_by_user_character_id(boost::mysql::tcp_connection& conn,
                                                                   int user_character_id);
    std::vector<user_inventory> sp_select_all_by_id(boost::mysql::tcp_connection& conn, int id);
    void sp_set_user_character_id_by_user_character_id(boost::mysql::tcp_connection& conn, int new_user_character_id,
                                                       int user_character_id);
    void sp_set_user_character_id_by_id(boost::mysql::tcp_connection& conn, int new_user_character_id, int id);
    void sp_set_item_id_by_user_character_id(boost::mysql::tcp_connection& conn, int new_item_id,
                                             int user_character_id);
    void sp_set_item_id_by_id(boost::mysql::tcp_connection& conn, int new_item_id, int id);
    void sp_set_item_quantity_by_user_character_id(boost::mysql::tcp_connection& conn, int new_item_quantity,
                                                   int user_character_id);
    void sp_set_item_quantity_by_id(boost::mysql::tcp_connection& conn, int new_item_quantity, int id);
    void sp_set_created_at_by_user_character_id(boost::mysql::tcp_connection& conn,
                                                boost::mysql::datetime new_created_at, int user_character_id);
    void sp_set_created_at_by_id(boost::mysql::tcp_connection& conn, boost::mysql::datetime new_created_at, int id);
    void sp_delete_by_user_character_id(boost::mysql::tcp_connection& conn, int user_character_id);
    void sp_delete_by_id(boost::mysql::tcp_connection& conn, int id);

    // 구현부

    void ORM::insert(boost::mysql::tcp_connection& conn, const user_inventory& obj)
    {
        conn.execute(
            "INSERT INTO user_inventory (user_character_id, item_id, item_quantity, created_at) VALUES (?, ?, ?, ?)",
            obj.user_character_id, obj.item_id, obj.item_quantity, obj.created_at);
    }


    std::vector<user_inventory> ORM::select_all(boost::mysql::tcp_connection& conn)
    {
        boost::mysql::results result;
        conn.execute("SELECT * FROM user_inventory", result);
        std::vector<user_inventory> objects;
        for (const auto& row : result.rows())
        {
            user_inventory obj;
            obj.id = row[0].as_int64();
            obj.user_character_id = row[1].as_int64();
            obj.item_id = row[2].as_int64();
            obj.item_quantity = row[3].as_int64();
            obj.created_at = boost::mysql::datetime(row[4].as_datetime());
            obj.updated_at = boost::mysql::datetime(row[5].as_datetime());
            objects.push_back(obj);
        }
        return objects;
    }


    std::vector<user_inventory> ORM::select_all_by_user_character_id(boost::mysql::tcp_connection& conn,
                                                                     int user_character_id)
    {
        boost::mysql::results result;
        conn.execute("SELECT * FROM user_inventory WHERE user_character_id = ?",
                     user_character_id);
        std::vector<user_inventory> objects;
        for (const auto& row : result.rows())
        {
            user_inventory obj;
            obj.id = row[0].as_int64();
            obj.user_character_id = row[1].as_int64();
            obj.item_id = row[2].as_int64();
            obj.item_quantity = row[3].as_int64();
            obj.created_at = boost::mysql::datetime(row[4].as_datetime());
            obj.updated_at = boost::mysql::datetime(row[5].as_datetime());
            objects.push_back(obj);
        }
        return objects;
    }


    std::vector<user_inventory> ORM::select_all_by_id(boost::mysql::tcp_connection& conn, int id)
    {
        boost::mysql::results result;
        conn.execute("SELECT * FROM user_inventory WHERE id = ?",
                     id);
        std::vector<user_inventory> objects;
        for (const auto& row : result.rows())
        {
            user_inventory obj;
            obj.id = row[0].as_int64();
            obj.user_character_id = row[1].as_int64();
            obj.item_id = row[2].as_int64();
            obj.item_quantity = row[3].as_int64();
            obj.created_at = boost::mysql::datetime(row[4].as_datetime());
            obj.updated_at = boost::mysql::datetime(row[5].as_datetime());
            objects.push_back(obj);
        }
        return objects;
    }


    void ORM::update_user_character_id_by_user_character_id(boost::mysql::tcp_connection& conn,
                                                            int new_user_character_id, int user_character_id)
    {
        conn.execute("UPDATE user_inventory SET user_character_id = ? WHERE user_character_id = ?",
                     new_user_character_id, user_character_id);
    }


    void ORM::update_user_character_id_by_id(boost::mysql::tcp_connection& conn, int new_user_character_id, int id)
    {
        conn.execute("UPDATE user_inventory SET user_character_id = ? WHERE id = ?",
                     new_user_character_id, id);
    }


    void ORM::update_item_id_by_user_character_id(boost::mysql::tcp_connection& conn, int new_item_id,
                                                  int user_character_id)
    {
        conn.execute("UPDATE user_inventory SET item_id = ? WHERE user_character_id = ?",
                     new_item_id, user_character_id);
    }


    void ORM::update_item_id_by_id(boost::mysql::tcp_connection& conn, int new_item_id, int id)
    {
        conn.execute("UPDATE user_inventory SET item_id = ? WHERE id = ?",
                     new_item_id, id);
    }


    void ORM::update_item_quantity_by_user_character_id(boost::mysql::tcp_connection& conn, int new_item_quantity,
                                                        int user_character_id)
    {
        conn.execute("UPDATE user_inventory SET item_quantity = ? WHERE user_character_id = ?",
                     new_item_quantity, user_character_id);
    }


    void ORM::update_item_quantity_by_id(boost::mysql::tcp_connection& conn, int new_item_quantity, int id)
    {
        conn.execute("UPDATE user_inventory SET item_quantity = ? WHERE id = ?",
                     new_item_quantity, id);
    }


    void ORM::update_created_at_by_user_character_id(boost::mysql::tcp_connection& conn,
                                                     boost::mysql::datetime new_created_at, int user_character_id)
    {
        conn.execute("UPDATE user_inventory SET created_at = ? WHERE user_character_id = ?",
                     new_created_at, user_character_id);
    }


    void ORM::update_created_at_by_id(boost::mysql::tcp_connection& conn, boost::mysql::datetime new_created_at, int id)
    {
        conn.execute("UPDATE user_inventory SET created_at = ? WHERE id = ?",
                     new_created_at, id);
    }


    void ORM::delete_by_user_character_id(boost::mysql::tcp_connection& conn, int user_character_id)
    {
        conn.execute("DELETE FROM user_inventory WHERE user_character_id = ?",
                     user_character_id);
    }


    void ORM::delete_by_id(boost::mysql::tcp_connection& conn, int id)
    {
        conn.execute("DELETE FROM user_inventory WHERE id = ?",
                     id);
    }


    void ORM::sp_insert(boost::mysql::tcp_connection& conn, const user_inventory& obj)
    {
        try
        {
            auto stmt = conn.prepare_statement("CALL sp_199(?, ?, ?, ?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(obj.user_character_id, obj.item_id, obj.item_quantity, obj.created_at), result);
            std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        }
        catch (const boost::mysql::error_with_diagnostics& e)
        {
            std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        }
    }


    std::vector<user_inventory> ORM::sp_select_all(boost::mysql::tcp_connection& conn)
    {
        std::vector<user_inventory> objects;
        try
        {
            auto stmt = conn.prepare_statement("CALL sp_200()");
            boost::mysql::results result;
            conn.execute(stmt.bind(), result);
            for (const auto& row : result.rows())
            {
                user_inventory obj;
                obj.id = row[0].as_int64();
                obj.user_character_id = row[1].as_int64();
                obj.item_id = row[2].as_int64();
                obj.item_quantity = row[3].as_int64();
                obj.created_at = boost::mysql::datetime(row[4].as_datetime());
                obj.updated_at = boost::mysql::datetime(row[5].as_datetime());
                objects.push_back(obj);
            }
        }
        catch (const boost::mysql::error_with_diagnostics& e)
        {
            std::cerr << "Error in sp_select_all: " << e.what() << std::endl;
        }
        return objects;
    }


    std::vector<user_inventory> ORM::sp_select_all_by_user_character_id(boost::mysql::tcp_connection& conn,
                                                                        int user_character_id)
    {
        std::vector<user_inventory> objects;
        try
        {
            auto stmt = conn.prepare_statement("CALL sp_201(?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(user_character_id), result);
            for (const auto& row : result.rows())
            {
                user_inventory obj;
                obj.id = row[0].as_int64();
                obj.user_character_id = row[1].as_int64();
                obj.item_id = row[2].as_int64();
                obj.item_quantity = row[3].as_int64();
                obj.created_at = boost::mysql::datetime(row[4].as_datetime());
                obj.updated_at = boost::mysql::datetime(row[5].as_datetime());
                objects.push_back(obj);
            }
        }
        catch (const boost::mysql::error_with_diagnostics& e)
        {
            std::cerr << "Error in sp_select_all_by_user_character_id: " << e.what() << std::endl;
        }
        return objects;
    }


    std::vector<user_inventory> ORM::sp_select_all_by_id(boost::mysql::tcp_connection& conn, int id)
    {
        std::vector<user_inventory> objects;
        try
        {
            auto stmt = conn.prepare_statement("CALL sp_202(?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(id), result);
            for (const auto& row : result.rows())
            {
                user_inventory obj;
                obj.id = row[0].as_int64();
                obj.user_character_id = row[1].as_int64();
                obj.item_id = row[2].as_int64();
                obj.item_quantity = row[3].as_int64();
                obj.created_at = boost::mysql::datetime(row[4].as_datetime());
                obj.updated_at = boost::mysql::datetime(row[5].as_datetime());
                objects.push_back(obj);
            }
        }
        catch (const boost::mysql::error_with_diagnostics& e)
        {
            std::cerr << "Error in sp_select_all_by_id: " << e.what() << std::endl;
        }
        return objects;
    }


    void ORM::sp_set_user_character_id_by_user_character_id(boost::mysql::tcp_connection& conn,
                                                            int new_user_character_id, int user_character_id)
    {
        try
        {
            auto stmt = conn.prepare_statement("CALL sp_203(?, ?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(new_user_character_id, user_character_id), result);
            std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        }
        catch (const boost::mysql::error_with_diagnostics& e)
        {
            std::cerr << "Error in sp_set_user_character_id_by_user_character_id: " << e.what() << std::endl;
        }
    }


    void ORM::sp_set_user_character_id_by_id(boost::mysql::tcp_connection& conn, int new_user_character_id, int id)
    {
        try
        {
            auto stmt = conn.prepare_statement("CALL sp_204(?, ?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(new_user_character_id, id), result);
            std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        }
        catch (const boost::mysql::error_with_diagnostics& e)
        {
            std::cerr << "Error in sp_set_user_character_id_by_id: " << e.what() << std::endl;
        }
    }


    void ORM::sp_set_item_id_by_user_character_id(boost::mysql::tcp_connection& conn, int new_item_id,
                                                  int user_character_id)
    {
        try
        {
            auto stmt = conn.prepare_statement("CALL sp_205(?, ?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(new_item_id, user_character_id), result);
            std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        }
        catch (const boost::mysql::error_with_diagnostics& e)
        {
            std::cerr << "Error in sp_set_item_id_by_user_character_id: " << e.what() << std::endl;
        }
    }


    void ORM::sp_set_item_id_by_id(boost::mysql::tcp_connection& conn, int new_item_id, int id)
    {
        try
        {
            auto stmt = conn.prepare_statement("CALL sp_206(?, ?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(new_item_id, id), result);
            std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        }
        catch (const boost::mysql::error_with_diagnostics& e)
        {
            std::cerr << "Error in sp_set_item_id_by_id: " << e.what() << std::endl;
        }
    }


    void ORM::sp_set_item_quantity_by_user_character_id(boost::mysql::tcp_connection& conn, int new_item_quantity,
                                                        int user_character_id)
    {
        try
        {
            auto stmt = conn.prepare_statement("CALL sp_207(?, ?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(new_item_quantity, user_character_id), result);
            std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        }
        catch (const boost::mysql::error_with_diagnostics& e)
        {
            std::cerr << "Error in sp_set_item_quantity_by_user_character_id: " << e.what() << std::endl;
        }
    }


    void ORM::sp_set_item_quantity_by_id(boost::mysql::tcp_connection& conn, int new_item_quantity, int id)
    {
        try
        {
            auto stmt = conn.prepare_statement("CALL sp_208(?, ?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(new_item_quantity, id), result);
            std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        }
        catch (const boost::mysql::error_with_diagnostics& e)
        {
            std::cerr << "Error in sp_set_item_quantity_by_id: " << e.what() << std::endl;
        }
    }


    void ORM::sp_set_created_at_by_user_character_id(boost::mysql::tcp_connection& conn,
                                                     boost::mysql::datetime new_created_at, int user_character_id)
    {
        try
        {
            auto stmt = conn.prepare_statement("CALL sp_209(?, ?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(new_created_at, user_character_id), result);
            std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        }
        catch (const boost::mysql::error_with_diagnostics& e)
        {
            std::cerr << "Error in sp_set_created_at_by_user_character_id: " << e.what() << std::endl;
        }
    }


    void ORM::sp_set_created_at_by_id(boost::mysql::tcp_connection& conn, boost::mysql::datetime new_created_at, int id)
    {
        try
        {
            auto stmt = conn.prepare_statement("CALL sp_210(?, ?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(new_created_at, id), result);
            std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        }
        catch (const boost::mysql::error_with_diagnostics& e)
        {
            std::cerr << "Error in sp_set_created_at_by_id: " << e.what() << std::endl;
        }
    }


    void ORM::sp_delete_by_user_character_id(boost::mysql::tcp_connection& conn, int user_character_id)
    {
        try
        {
            auto stmt = conn.prepare_statement("CALL sp_213(?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(user_character_id), result);
            std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        }
        catch (const boost::mysql::error_with_diagnostics& e)
        {
            std::cerr << "Error in sp_delete_by_user_character_id: " << e.what() << std::endl;
        }
    }


    void ORM::sp_delete_by_id(boost::mysql::tcp_connection& conn, int id)
    {
        try
        {
            auto stmt = conn.prepare_statement("CALL sp_214(?)");
            boost::mysql::results result;
            conn.execute(stmt.bind(id), result);
            std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        }
        catch (const boost::mysql::error_with_diagnostics& e)
        {
            std::cerr << "Error in sp_delete_by_id: " << e.what() << std::endl;
        }
    }
};
} // namespace ORM
