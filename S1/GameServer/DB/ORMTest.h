#pragma once
#include <iostream>
#include <boost/asio/io_context.hpp>
#include <boost/describe/class.hpp>
#include <boost/mysql/static_results.hpp>
#include <coroutine>
#include <boost/asio/spawn.hpp>
#include <boost/mysql/throw_on_error.hpp>

#include "DB/MySqlConnectionPool.h"

using namespace ServerCore;
using namespace DB;
/*
-- 테스트 용 테이블 생성
CREATE TABLE user_test
(
    id         INT AUTO_INCREMENT PRIMARY KEY,
    username   VARCHAR(32) NOT NULL,
    password   VARCHAR(32) NOT NULL,
    email      VARCHAR(64) NOT NULL UNIQUE,
    created_at TIMESTAMP   NOT NULL DEFAULT CURRENT_TIMESTAMP,
    updated_at TIMESTAMP   NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP
);


-- 테스트 용 테이블 데이터 삽입
INSERT INTO user_test (username, password, email)
VALUES ('user1', 'password1', 'user1@example.com'),
       ('user2', 'password2', 'user2@example.com'),
       ('user3', 'password3', 'user3@example.com'),
       ('user4', 'password4', 'user4@example.com'),
       ('user5', 'password5', 'user5@example.com'),
       ('user6', 'password6', 'user6@example.com'),
       ('user7', 'password7', 'user7@example.com'),
       ('user8', 'password8', 'user8@example.com');
 */


using namespace boost::mysql;
using namespace boost::asio;

struct user_test
{
    int32_t id; // int
    std::string username; // varchar(32)
    std::string password; // varchar(32)
    std::string email; // varchar(64)
    datetime created_at; // timestamp
    datetime updated_at; // timestamp
};

BOOST_DESCRIBE_STRUCT(user_test, (), (id, username, password, email, created_at, updated_at));


class ORMTest
{
    /*
-- 유저 아이템 테이블 생성
CREATE TABLE user_inventory
(
    id                INT AUTO_INCREMENT PRIMARY KEY,
    user_character_id INT NOT NULL,
    item_id           INT NOT NULL,
    item_quantity     INT       DEFAULT 1,
    created_at        TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    updated_at        TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
    INDEX idx_user_character_id (user_character_id)
);
*/

    using empty = std::tuple<>;

private:
    boost::asio::io_context* m_ioContext;
    std::shared_ptr<MySqlConnectionPool> m_mysqlConnectionPool;

public:
    ORMTest()
    {
        m_ioContext = new asio::io_context;
        m_mysqlConnectionPool = std::make_shared<MySqlConnectionPool>("..\\..\\..\\DB\\config.txt", *m_ioContext, 100);
    }

    ORMTest(boost::asio::io_context* ioContext, std::shared_ptr<MySqlConnectionPool> mysqlConnectionPool): m_ioContext(ioContext),
        m_mysqlConnectionPool(mysqlConnectionPool)
    {

    }

    ~ORMTest()
    {
        m_mysqlConnectionPool->CleanupConnectionPool();
    }

    void start_dynamic_interface_test()
    {
        int user_character_id = 1;
        int item_id = 10100001;
        int item_quantity = 1;
        mysql::datetime created_at{2024, 7, 25, 13, 27, 0};
        mysql::datetime updated_at{2024, 7, 25, 13, 28, 23};

        mysql::tcp_connection* conn = m_mysqlConnectionPool->GetPooledConnection();
        bool success = insert_into_user_inventory(conn, user_character_id, 10100001, 1, created_at, updated_at);
        mysql::results result = select_all_from_user_inventory(conn);
        PrintResult(result); // return value validation
        result = select_all_by_user_character_id_from_user_inventory(conn, user_character_id);
        PrintResult(result); // return value validation
        int updated = update_user_character_id_by_user_character_id_from_user_inventory(conn, user_character_id);
        success = delete_by_user_character_id_from_user_inventory(conn, user_character_id);

        m_mysqlConnectionPool->ReturnConnection(conn);
    }


    void start_static_interface_test() const
    {
        // We can use a plain struct with ints and strings to describe our rows.
        // This must be placed at the namespace level


        //
        // This must be placed inside your function or method:
        //

        // Passing a static_results to execute() selects the static interface
        mysql::tcp_connection* conn = m_mysqlConnectionPool->GetPooledConnection();
        mysql::static_results<user_test> result;
        conn->execute("SELECT * FROM user_test", result);

        // Query results are parsed directly into your own type
        for (const user_test& p : result.rows())
        {
            std::cout << "id : " << p.id << "username: " << p.username << "password : " << p.password << "email : " << p
                .email << "created_at : " << p.created_at << "updated_at : " << p.updated_at << std::endl;
        }

        m_mysqlConnectionPool->ReturnConnection(conn);
    }

    void start_coroutine()
    {
        spawn(m_ioContext->get_executor(),
              [this](boost::asio::yield_context yield)
              {
                  boost::mysql::error_code ec;
                  boost::mysql::diagnostics diag;
                  auto conn = m_mysqlConnectionPool->GetPooledConnection();
                  boost::mysql::statement stmt = conn->async_prepare_statement(
                      "CALL sp_10535(?)", diag, yield[ec]);
                  boost::mysql::throw_on_error(ec, diag);

                  static_results<user_test> result;
                  conn->async_execute(stmt.bind(10), result, diag, yield[ec]);
                  boost::mysql::throw_on_error(ec, diag);

                  for (const user_test& p : result.rows())
                  {
                      std::cout << "id : " << p.id << "username: " << p.username << "password : " << p.
                          password << "email : " << p
                          .email << "created_at : " << p.created_at << "updated_at : " << p.updated_at <<
                          std::endl;
                  }


                  // This will throw an error_with_diagnostics in case of failure
                  m_mysqlConnectionPool->ReturnConnection(conn);
              },
              // If any exception is thrown in the coroutine body, rethrow it.
              [](std::exception_ptr ptr)
              {
                  if (ptr)
                  {
                      std::rethrow_exception(ptr);
                  }
              }
        );
    }

    asio::awaitable<void> start_async_interface_test() const
    {
        // We can use a plain struct with ints and strings to describe our rows.
        // This must be placed at the namespace level


        //
        // This must be placed inside your function or method:
        //

        // Passing a static_results to execute() selects the static interface
        mysql::tcp_connection* conn = m_mysqlConnectionPool->GetPooledConnection();

        // Using this CompletionToken, you get C++20 coroutines that communicate
        // errors with error_codes. This way, you can access the diagnostics object.
        constexpr auto token = boost::asio::as_tuple(boost::asio::use_awaitable);
        // Run our query as a coroutine
        mysql::diagnostics diag;
        mysql::static_results<user_test> static_result;
        auto [ec] = co_await conn->async_execute("SELECT * FROM user_test", static_result, diag, token);
        boost::mysql::throw_on_error(ec, diag);

        // Query results are parsed directly into your own type
        for (const user_test& p : static_result.rows())
        {
            std::cout << "id : " << p.id << "username: " << p.username << "password : " << p.password << "email : " << p
                .email << "created_at : " << p.created_at << "updated_at : " << p.updated_at << std::endl;
        }

        // This will throw an error_with_diagnostics in case of failure
        m_mysqlConnectionPool->ReturnConnection(conn);
    }

    void PrintResult(const mysql::results& result)
    {
        // for debugging
        if (!result.rows().empty())
        {
            auto sz = result.size();
            for (int i = 0; i < result.size(); i++)
            {
                for (const mysql::row_view& row : result.at(i).rows())
                {
                    auto new_id = row[0].as_int64();
                    auto new_user_character_id = row[1].as_int64();
                    auto new_item_id = row[2].as_int64();
                    auto new_item_quantity = row[3].as_int64();
                    auto created_at = row[4].as_datetime();
                    auto updated_at = row[5].as_datetime();
                    std::cout << new_id << ", " << new_user_character_id << ", " << new_item_id << ", " <<
                        new_item_quantity << ", " << created_at << ", " << updated_at << std::endl;
                }
            }
        }
        else
        {
            std::cout << "No result set" << std::endl;
        }
    }

private:
    bool insert_into_user_inventory(mysql::tcp_connection* conn, int user_character_id, int item_id, int item_quantity,
                                    mysql::datetime created_at, mysql::datetime updated_at)
    {
        std::cout << "[Test] insert_into_user_inventory - [Start]" << std::endl;
        try
        {
            // INSERT로 새 아이템 추가하는 SP(반환 값 없음)
            {
                auto stmt = conn->prepare_statement("CALL sp_100(?, ?, ?, ?, ?)");

                // result는 sp_100은 반환 값이 없기 때문에 std::tuple<>를 의미하는 empty를 넣는다
                // mysql::static_results<empty> result;
                mysql::results result;

                // user_inventory user_item;
                // user_item.user_character_id = 1;
                // user_item.item_id = 10100001;
                // user_item.item_quantity = 1;
                // user_item.created_at = created_at;
                // user_item.updated_at = updated_at;

                // sp에 필요한 인자 바인딩
                conn->execute(stmt.bind(
                                  user_character_id,
                                  item_id,
                                  item_quantity,
                                  created_at,
                                  updated_at
                              ), result);
                // for debugging
                std::cout << "affected rows - " << result.affected_rows() << std::endl;
                if (!result.rows().empty())
                {
                    std::cout << "New item added" << std::endl;
                    std::cout << "Affected rows: " << result.affected_rows() << std::endl;
                }
                else
                {
                    std::cout << "No result set" << std::endl;
                }
            }
        }
        catch (boost::mysql::error_code& ec)
        {
            std::cerr << ec.what() << std::endl;
            return false;
        }
        catch (std::exception& ex)
        {
            std::cerr << ex.what() << std::endl;
            return false;
        }

        std::cout << "[Test] insert_into_user_inventory - [done]" << std::endl;
        return true;
    }

    mysql::results select_all_from_user_inventory(mysql::tcp_connection* conn)
    {
        std::cout << "[Test] select_all_from_user_inventory - [start]" << std::endl;
        mysql::results result;
        try
        {
            // user_inventory 테이블 전체 조회 SP(반환 값 : 테이블 전체)
            {
                auto stmt = conn->prepare_statement("CALL sp_101()");

                // static interface방식인 mysql::static_results는 불완전해서 오류가 있는 것 같음.
                // dynamic interface방식인 mysql::results를 사용하는 것을 추천
                // mysql::static_results<user_inventory> result;
                conn->execute(stmt.bind(), result); // sp에 입력할 인자가 없음

                // for debugging
                PrintResult(result);
            }
        }
        catch (boost::mysql::error_code& ec)
        {
            std::cerr << ec.what() << std::endl;
            return result;
        }
        catch (std::exception& ex)
        {
            std::cerr << ex.what() << std::endl;
            return result;
        }

        std::cout << "[Test] select_all_from_user_inventory - [done]" << std::endl;
        return result;
    }

    mysql::results select_all_by_user_character_id_from_user_inventory(mysql::tcp_connection* conn,
                                                                       int user_character_id)
    {
        std::cout << "[Test] select_all_by_user_character_id_from_user_inventory - [start]\n";
        mysql::results result;
        try
        {
            // user_inventory 테이블 전체 조회 SP(반환 값 : 테이블 전체)
            {
                auto stmt = conn->prepare_statement("CALL sp_102(?)");
                conn->execute(stmt.bind(user_character_id), result); // user_character_id와 일치하는 데이터 조회
                // for debugging
                PrintResult(result);
            }
        }
        catch (boost::mysql::error_code& ec)
        {
            std::cerr << ec.what() << std::endl;
        }
        catch (std::exception& ex)
        {
            std::cerr << ex.what() << std::endl;
        }

        std::cout << "[Test] select_all_by_user_character_id_from_user_inventory - [done]" << std::endl;
        return result;
    }

    int update_user_character_id_by_user_character_id_from_user_inventory(
        mysql::tcp_connection* conn, int user_character_id)
    {
        std::cout << "[Test] update_user_character_id_by_user_character_id_from_user_inventory - [start]" << std::endl;
        mysql::results result;
        try
        {
            auto stmt = conn->prepare_statement("CALL sp_104(?, ?)");
            conn->execute(stmt.bind(2, 1), result); // user_character_id가 1이면 2로 변경
            std::cout << "affected rows - " << result.affected_rows() << std::endl; // 디버깅 용 코드
        }
        catch
        (boost::mysql::error_code& ec)
        {
            std::cerr << ec.what() << std::endl;
            return -1;
        }
        catch
        (std::exception& ex)
        {
            std::cerr << ex.what() << std::endl;
            return -1;
        }

        std::cout << "[Test] update_user_character_id_by_user_character_id_from_user_inventory - [done]" << std::endl;
        return result.affected_rows();
    }

    int delete_by_user_character_id_from_user_inventory(mysql::tcp_connection* conn, int user_character_id)
    {
        std::cout << "delete_by_user_character_id_from_user_inventory Test" << std::endl;
        mysql::results result;
        try
        {
            // user_inventory 테이블 전체 조회 SP(반환 값 : 테이블 전체)
            auto stmt = conn->prepare_statement("CALL sp_114(?)");
            conn->execute(stmt.bind(1), result); // user_character_id가 1이면 삭제
            std::cout << "affected rows - " << result.affected_rows() << std::endl;
        }
        catch (boost::mysql::error_code& ec)
        {
            std::cerr << ec.what();
            return -1;
        }
        catch (std::exception& ex)
        {
            std::cerr << ex.what();
            return -1;
        }

        std::cout << "[Test] delete_by_user_character_id_from_user_inventory Test - [done]" << std::endl;
        return result.affected_rows();
    }
};
