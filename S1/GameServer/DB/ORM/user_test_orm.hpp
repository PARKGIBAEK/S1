
#pragma once

#include <boost/mysql.hpp>
#include <boost/mysql/tcp.hpp>
#include <boost/describe.hpp>
#include <string>
#include <iostream>
#include <format>

using namespace boost::mysql;
using namespace std;

namespace ORM_test {

struct user_test
{
    int32_t id; // int
    string username; // varchar(32)
    string password; // varchar(32)
    string email; // varchar(64)
    datetime created_at; // timestamp
    datetime updated_at; // timestamp
};

BOOST_DESCRIBE_STRUCT(user_test, (), (id, username, password, email, created_at, updated_at));

class user_test_orm
{
public:
    // SP 호출 선언
    static int insert_into_user_test_username_N_password_N_email(tcp_connection* conn, const string& new_username, const string& new_password, const string& new_email);
    static results select_id_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email);
    static results select_id_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_username_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email);
    static results select_username_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_username_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_username_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_username_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_username_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_password_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email);
    static results select_password_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_password_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_password_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_password_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_password_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_email_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email);
    static results select_email_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_email_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_email_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_email_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_email_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_created_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email);
    static results select_created_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_created_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_created_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_created_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_created_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_updated_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email);
    static results select_updated_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_updated_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_updated_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_updated_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_updated_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_username_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email);
    static results select_id_N_username_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_username_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_username_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_username_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_username_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_password_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email);
    static results select_id_N_password_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_password_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_password_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_password_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_password_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_email_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email);
    static results select_id_N_email_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_email_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_email_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_email_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_email_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_created_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email);
    static results select_id_N_created_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_created_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_created_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_created_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_created_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_updated_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email);
    static results select_id_N_updated_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_updated_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_updated_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_updated_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_updated_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_username_N_password_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email);
    static results select_username_N_password_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_username_N_password_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_username_N_password_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_username_N_password_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_username_N_password_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_username_N_email_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email);
    static results select_username_N_email_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_username_N_email_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_username_N_email_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_username_N_email_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_username_N_email_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_username_N_created_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email);
    static results select_username_N_created_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_username_N_created_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_username_N_created_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_username_N_created_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_username_N_created_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_username_N_updated_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email);
    static results select_username_N_updated_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_username_N_updated_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_username_N_updated_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_username_N_updated_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_username_N_updated_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_password_N_email_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email);
    static results select_password_N_email_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_password_N_email_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_password_N_email_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_password_N_email_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_password_N_email_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_password_N_created_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email);
    static results select_password_N_created_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_password_N_created_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_password_N_created_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_password_N_created_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_password_N_created_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_password_N_updated_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email);
    static results select_password_N_updated_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_password_N_updated_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_password_N_updated_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_password_N_updated_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_password_N_updated_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_email_N_created_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email);
    static results select_email_N_created_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_email_N_created_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_email_N_created_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_email_N_created_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_email_N_created_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_email_N_updated_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email);
    static results select_email_N_updated_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_email_N_updated_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_email_N_updated_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_email_N_updated_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_email_N_updated_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_created_at_N_updated_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email);
    static results select_created_at_N_updated_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_created_at_N_updated_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_created_at_N_updated_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_created_at_N_updated_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_created_at_N_updated_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_username_N_password_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email);
    static results select_id_N_username_N_password_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_username_N_password_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_username_N_password_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_username_N_password_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_username_N_password_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_username_N_email_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email);
    static results select_id_N_username_N_email_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_username_N_email_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_username_N_email_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_username_N_email_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_username_N_email_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_username_N_created_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email);
    static results select_id_N_username_N_created_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_username_N_created_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_username_N_created_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_username_N_created_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_username_N_created_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_username_N_updated_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email);
    static results select_id_N_username_N_updated_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_username_N_updated_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_username_N_updated_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_username_N_updated_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_username_N_updated_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_password_N_email_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email);
    static results select_id_N_password_N_email_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_password_N_email_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_password_N_email_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_password_N_email_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_password_N_email_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_password_N_created_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email);
    static results select_id_N_password_N_created_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_password_N_created_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_password_N_created_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_password_N_created_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_password_N_created_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_password_N_updated_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email);
    static results select_id_N_password_N_updated_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_password_N_updated_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_password_N_updated_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_password_N_updated_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_password_N_updated_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_email_N_created_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email);
    static results select_id_N_email_N_created_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_email_N_created_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_email_N_created_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_email_N_created_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_email_N_created_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_email_N_updated_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email);
    static results select_id_N_email_N_updated_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_email_N_updated_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_email_N_updated_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_email_N_updated_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_email_N_updated_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_created_at_N_updated_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email);
    static results select_id_N_created_at_N_updated_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_created_at_N_updated_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_created_at_N_updated_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_created_at_N_updated_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_created_at_N_updated_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_username_N_password_N_email_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email);
    static results select_username_N_password_N_email_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_username_N_password_N_email_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_username_N_password_N_email_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_username_N_password_N_email_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_username_N_password_N_email_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_username_N_password_N_created_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email);
    static results select_username_N_password_N_created_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_username_N_password_N_created_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_username_N_password_N_created_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_username_N_password_N_created_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_username_N_password_N_created_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_username_N_password_N_updated_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email);
    static results select_username_N_password_N_updated_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_username_N_password_N_updated_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_username_N_password_N_updated_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_username_N_password_N_updated_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_username_N_password_N_updated_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_username_N_email_N_created_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email);
    static results select_username_N_email_N_created_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_username_N_email_N_created_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_username_N_email_N_created_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_username_N_email_N_created_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_username_N_email_N_created_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_username_N_email_N_updated_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email);
    static results select_username_N_email_N_updated_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_username_N_email_N_updated_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_username_N_email_N_updated_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_username_N_email_N_updated_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_username_N_email_N_updated_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_username_N_created_at_N_updated_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email);
    static results select_username_N_created_at_N_updated_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_username_N_created_at_N_updated_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_username_N_created_at_N_updated_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_username_N_created_at_N_updated_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_username_N_created_at_N_updated_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_password_N_email_N_created_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email);
    static results select_password_N_email_N_created_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_password_N_email_N_created_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_password_N_email_N_created_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_password_N_email_N_created_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_password_N_email_N_created_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_password_N_email_N_updated_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email);
    static results select_password_N_email_N_updated_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_password_N_email_N_updated_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_password_N_email_N_updated_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_password_N_email_N_updated_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_password_N_email_N_updated_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_password_N_created_at_N_updated_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email);
    static results select_password_N_created_at_N_updated_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_password_N_created_at_N_updated_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_password_N_created_at_N_updated_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_password_N_created_at_N_updated_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_password_N_created_at_N_updated_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_email_N_created_at_N_updated_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email);
    static results select_email_N_created_at_N_updated_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_email_N_created_at_N_updated_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_email_N_created_at_N_updated_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_email_N_created_at_N_updated_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_email_N_created_at_N_updated_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_username_N_password_N_email_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email);
    static results select_id_N_username_N_password_N_email_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_username_N_password_N_email_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_username_N_password_N_email_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_username_N_password_N_email_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_username_N_password_N_email_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_username_N_password_N_created_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email);
    static results select_id_N_username_N_password_N_created_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_username_N_password_N_created_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_username_N_password_N_created_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_username_N_password_N_created_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_username_N_password_N_created_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_username_N_password_N_updated_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email);
    static results select_id_N_username_N_password_N_updated_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_username_N_password_N_updated_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_username_N_password_N_updated_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_username_N_password_N_updated_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_username_N_password_N_updated_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_username_N_email_N_created_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email);
    static results select_id_N_username_N_email_N_created_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_username_N_email_N_created_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_username_N_email_N_created_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_username_N_email_N_created_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_username_N_email_N_created_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_username_N_email_N_updated_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email);
    static results select_id_N_username_N_email_N_updated_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_username_N_email_N_updated_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_username_N_email_N_updated_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_username_N_email_N_updated_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_username_N_email_N_updated_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_username_N_created_at_N_updated_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email);
    static results select_id_N_username_N_created_at_N_updated_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_username_N_created_at_N_updated_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_username_N_created_at_N_updated_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_username_N_created_at_N_updated_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_username_N_created_at_N_updated_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_password_N_email_N_created_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email);
    static results select_id_N_password_N_email_N_created_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_password_N_email_N_created_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_password_N_email_N_created_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_password_N_email_N_created_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_password_N_email_N_created_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_password_N_email_N_updated_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email);
    static results select_id_N_password_N_email_N_updated_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_password_N_email_N_updated_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_password_N_email_N_updated_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_password_N_email_N_updated_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_password_N_email_N_updated_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_password_N_created_at_N_updated_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email);
    static results select_id_N_password_N_created_at_N_updated_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_password_N_created_at_N_updated_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_password_N_created_at_N_updated_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_password_N_created_at_N_updated_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_password_N_created_at_N_updated_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_email_N_created_at_N_updated_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email);
    static results select_id_N_email_N_created_at_N_updated_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_email_N_created_at_N_updated_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_email_N_created_at_N_updated_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_email_N_created_at_N_updated_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_email_N_created_at_N_updated_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_username_N_password_N_email_N_created_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email);
    static results select_username_N_password_N_email_N_created_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_username_N_password_N_email_N_created_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_username_N_password_N_email_N_created_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_username_N_password_N_email_N_created_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_username_N_password_N_email_N_created_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_username_N_password_N_email_N_updated_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email);
    static results select_username_N_password_N_email_N_updated_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_username_N_password_N_email_N_updated_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_username_N_password_N_email_N_updated_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_username_N_password_N_email_N_updated_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_username_N_password_N_email_N_updated_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_username_N_password_N_created_at_N_updated_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email);
    static results select_username_N_password_N_created_at_N_updated_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_username_N_password_N_created_at_N_updated_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_username_N_password_N_created_at_N_updated_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_username_N_password_N_created_at_N_updated_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_username_N_password_N_created_at_N_updated_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_username_N_email_N_created_at_N_updated_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email);
    static results select_username_N_email_N_created_at_N_updated_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_username_N_email_N_created_at_N_updated_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_username_N_email_N_created_at_N_updated_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_username_N_email_N_created_at_N_updated_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_username_N_email_N_created_at_N_updated_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_password_N_email_N_created_at_N_updated_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email);
    static results select_password_N_email_N_created_at_N_updated_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_password_N_email_N_created_at_N_updated_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_password_N_email_N_created_at_N_updated_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_password_N_email_N_created_at_N_updated_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_password_N_email_N_created_at_N_updated_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_username_N_password_N_email_N_created_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email);
    static results select_id_N_username_N_password_N_email_N_created_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_username_N_password_N_email_N_created_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_username_N_password_N_email_N_created_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_username_N_password_N_email_N_created_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_username_N_password_N_email_N_created_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_username_N_password_N_email_N_updated_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email);
    static results select_id_N_username_N_password_N_email_N_updated_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_username_N_password_N_email_N_updated_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_username_N_password_N_email_N_updated_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_username_N_password_N_email_N_updated_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_username_N_password_N_email_N_updated_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_username_N_password_N_created_at_N_updated_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email);
    static results select_id_N_username_N_password_N_created_at_N_updated_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_username_N_password_N_created_at_N_updated_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_username_N_password_N_created_at_N_updated_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_username_N_password_N_created_at_N_updated_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_username_N_password_N_created_at_N_updated_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_username_N_email_N_created_at_N_updated_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email);
    static results select_id_N_username_N_email_N_created_at_N_updated_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_username_N_email_N_created_at_N_updated_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_username_N_email_N_created_at_N_updated_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_username_N_email_N_created_at_N_updated_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_username_N_email_N_created_at_N_updated_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_password_N_email_N_created_at_N_updated_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email);
    static results select_id_N_password_N_email_N_created_at_N_updated_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_password_N_email_N_created_at_N_updated_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_password_N_email_N_created_at_N_updated_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_password_N_email_N_created_at_N_updated_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_password_N_email_N_created_at_N_updated_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_username_N_password_N_email_N_created_at_N_updated_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email);
    static results select_username_N_password_N_email_N_created_at_N_updated_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_username_N_password_N_email_N_created_at_N_updated_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_username_N_password_N_email_N_created_at_N_updated_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_username_N_password_N_email_N_created_at_N_updated_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_username_N_password_N_email_N_created_at_N_updated_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_all_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email);
    static results select_all_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_all_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_all_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_all_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_all_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static int update_user_test_set_id_where_EQ_email(tcp_connection* conn, const int32_t& s_id, const string& w_email);
    static int update_user_test_set_id_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const int32_t& w_id);
    static int update_user_test_set_id_where_LT_id(tcp_connection* conn, const int32_t& s_id, const int32_t& w_id);
    static int update_user_test_set_id_where_LE_id(tcp_connection* conn, const int32_t& s_id, const int32_t& w_id);
    static int update_user_test_set_id_where_GT_id(tcp_connection* conn, const int32_t& s_id, const int32_t& w_id);
    static int update_user_test_set_id_where_GE_id(tcp_connection* conn, const int32_t& s_id, const int32_t& w_id);
    static int update_user_test_set_username_where_EQ_email(tcp_connection* conn, const string& s_username, const string& w_email);
    static int update_user_test_set_username_where_EQ_id(tcp_connection* conn, const string& s_username, const int32_t& w_id);
    static int update_user_test_set_username_where_LT_id(tcp_connection* conn, const string& s_username, const int32_t& w_id);
    static int update_user_test_set_username_where_LE_id(tcp_connection* conn, const string& s_username, const int32_t& w_id);
    static int update_user_test_set_username_where_GT_id(tcp_connection* conn, const string& s_username, const int32_t& w_id);
    static int update_user_test_set_username_where_GE_id(tcp_connection* conn, const string& s_username, const int32_t& w_id);
    static int update_user_test_set_password_where_EQ_email(tcp_connection* conn, const string& s_password, const string& w_email);
    static int update_user_test_set_password_where_EQ_id(tcp_connection* conn, const string& s_password, const int32_t& w_id);
    static int update_user_test_set_password_where_LT_id(tcp_connection* conn, const string& s_password, const int32_t& w_id);
    static int update_user_test_set_password_where_LE_id(tcp_connection* conn, const string& s_password, const int32_t& w_id);
    static int update_user_test_set_password_where_GT_id(tcp_connection* conn, const string& s_password, const int32_t& w_id);
    static int update_user_test_set_password_where_GE_id(tcp_connection* conn, const string& s_password, const int32_t& w_id);
    static int update_user_test_set_email_where_EQ_email(tcp_connection* conn, const string& s_email, const string& w_email);
    static int update_user_test_set_email_where_EQ_id(tcp_connection* conn, const string& s_email, const int32_t& w_id);
    static int update_user_test_set_email_where_LT_id(tcp_connection* conn, const string& s_email, const int32_t& w_id);
    static int update_user_test_set_email_where_LE_id(tcp_connection* conn, const string& s_email, const int32_t& w_id);
    static int update_user_test_set_email_where_GT_id(tcp_connection* conn, const string& s_email, const int32_t& w_id);
    static int update_user_test_set_email_where_GE_id(tcp_connection* conn, const string& s_email, const int32_t& w_id);
    static int update_user_test_set_created_at_where_EQ_email(tcp_connection* conn, const datetime& s_created_at, const string& w_email);
    static int update_user_test_set_created_at_where_EQ_id(tcp_connection* conn, const datetime& s_created_at, const int32_t& w_id);
    static int update_user_test_set_created_at_where_LT_id(tcp_connection* conn, const datetime& s_created_at, const int32_t& w_id);
    static int update_user_test_set_created_at_where_LE_id(tcp_connection* conn, const datetime& s_created_at, const int32_t& w_id);
    static int update_user_test_set_created_at_where_GT_id(tcp_connection* conn, const datetime& s_created_at, const int32_t& w_id);
    static int update_user_test_set_created_at_where_GE_id(tcp_connection* conn, const datetime& s_created_at, const int32_t& w_id);
    static int update_user_test_set_updated_at_where_EQ_email(tcp_connection* conn, const datetime& s_updated_at, const string& w_email);
    static int update_user_test_set_updated_at_where_EQ_id(tcp_connection* conn, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_updated_at_where_LT_id(tcp_connection* conn, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_updated_at_where_LE_id(tcp_connection* conn, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_updated_at_where_GT_id(tcp_connection* conn, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_updated_at_where_GE_id(tcp_connection* conn, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_id_N_username_where_EQ_email(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& w_email);
    static int update_user_test_set_id_N_username_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const int32_t& w_id);
    static int update_user_test_set_id_N_username_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const int32_t& w_id);
    static int update_user_test_set_id_N_username_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const int32_t& w_id);
    static int update_user_test_set_id_N_username_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const int32_t& w_id);
    static int update_user_test_set_id_N_username_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const int32_t& w_id);
    static int update_user_test_set_id_N_password_where_EQ_email(tcp_connection* conn, const int32_t& s_id, const string& s_password, const string& w_email);
    static int update_user_test_set_id_N_password_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_password, const int32_t& w_id);
    static int update_user_test_set_id_N_password_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_password, const int32_t& w_id);
    static int update_user_test_set_id_N_password_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_password, const int32_t& w_id);
    static int update_user_test_set_id_N_password_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_password, const int32_t& w_id);
    static int update_user_test_set_id_N_password_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_password, const int32_t& w_id);
    static int update_user_test_set_id_N_email_where_EQ_email(tcp_connection* conn, const int32_t& s_id, const string& s_email, const string& w_email);
    static int update_user_test_set_id_N_email_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_email, const int32_t& w_id);
    static int update_user_test_set_id_N_email_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_email, const int32_t& w_id);
    static int update_user_test_set_id_N_email_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_email, const int32_t& w_id);
    static int update_user_test_set_id_N_email_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_email, const int32_t& w_id);
    static int update_user_test_set_id_N_email_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_email, const int32_t& w_id);
    static int update_user_test_set_id_N_created_at_where_EQ_email(tcp_connection* conn, const int32_t& s_id, const datetime& s_created_at, const string& w_email);
    static int update_user_test_set_id_N_created_at_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const datetime& s_created_at, const int32_t& w_id);
    static int update_user_test_set_id_N_created_at_where_LT_id(tcp_connection* conn, const int32_t& s_id, const datetime& s_created_at, const int32_t& w_id);
    static int update_user_test_set_id_N_created_at_where_LE_id(tcp_connection* conn, const int32_t& s_id, const datetime& s_created_at, const int32_t& w_id);
    static int update_user_test_set_id_N_created_at_where_GT_id(tcp_connection* conn, const int32_t& s_id, const datetime& s_created_at, const int32_t& w_id);
    static int update_user_test_set_id_N_created_at_where_GE_id(tcp_connection* conn, const int32_t& s_id, const datetime& s_created_at, const int32_t& w_id);
    static int update_user_test_set_id_N_updated_at_where_EQ_email(tcp_connection* conn, const int32_t& s_id, const datetime& s_updated_at, const string& w_email);
    static int update_user_test_set_id_N_updated_at_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_id_N_updated_at_where_LT_id(tcp_connection* conn, const int32_t& s_id, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_id_N_updated_at_where_LE_id(tcp_connection* conn, const int32_t& s_id, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_id_N_updated_at_where_GT_id(tcp_connection* conn, const int32_t& s_id, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_id_N_updated_at_where_GE_id(tcp_connection* conn, const int32_t& s_id, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_username_N_password_where_EQ_email(tcp_connection* conn, const string& s_username, const string& s_password, const string& w_email);
    static int update_user_test_set_username_N_password_where_EQ_id(tcp_connection* conn, const string& s_username, const string& s_password, const int32_t& w_id);
    static int update_user_test_set_username_N_password_where_LT_id(tcp_connection* conn, const string& s_username, const string& s_password, const int32_t& w_id);
    static int update_user_test_set_username_N_password_where_LE_id(tcp_connection* conn, const string& s_username, const string& s_password, const int32_t& w_id);
    static int update_user_test_set_username_N_password_where_GT_id(tcp_connection* conn, const string& s_username, const string& s_password, const int32_t& w_id);
    static int update_user_test_set_username_N_password_where_GE_id(tcp_connection* conn, const string& s_username, const string& s_password, const int32_t& w_id);
    static int update_user_test_set_username_N_email_where_EQ_email(tcp_connection* conn, const string& s_username, const string& s_email, const string& w_email);
    static int update_user_test_set_username_N_email_where_EQ_id(tcp_connection* conn, const string& s_username, const string& s_email, const int32_t& w_id);
    static int update_user_test_set_username_N_email_where_LT_id(tcp_connection* conn, const string& s_username, const string& s_email, const int32_t& w_id);
    static int update_user_test_set_username_N_email_where_LE_id(tcp_connection* conn, const string& s_username, const string& s_email, const int32_t& w_id);
    static int update_user_test_set_username_N_email_where_GT_id(tcp_connection* conn, const string& s_username, const string& s_email, const int32_t& w_id);
    static int update_user_test_set_username_N_email_where_GE_id(tcp_connection* conn, const string& s_username, const string& s_email, const int32_t& w_id);
    static int update_user_test_set_username_N_created_at_where_EQ_email(tcp_connection* conn, const string& s_username, const datetime& s_created_at, const string& w_email);
    static int update_user_test_set_username_N_created_at_where_EQ_id(tcp_connection* conn, const string& s_username, const datetime& s_created_at, const int32_t& w_id);
    static int update_user_test_set_username_N_created_at_where_LT_id(tcp_connection* conn, const string& s_username, const datetime& s_created_at, const int32_t& w_id);
    static int update_user_test_set_username_N_created_at_where_LE_id(tcp_connection* conn, const string& s_username, const datetime& s_created_at, const int32_t& w_id);
    static int update_user_test_set_username_N_created_at_where_GT_id(tcp_connection* conn, const string& s_username, const datetime& s_created_at, const int32_t& w_id);
    static int update_user_test_set_username_N_created_at_where_GE_id(tcp_connection* conn, const string& s_username, const datetime& s_created_at, const int32_t& w_id);
    static int update_user_test_set_username_N_updated_at_where_EQ_email(tcp_connection* conn, const string& s_username, const datetime& s_updated_at, const string& w_email);
    static int update_user_test_set_username_N_updated_at_where_EQ_id(tcp_connection* conn, const string& s_username, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_username_N_updated_at_where_LT_id(tcp_connection* conn, const string& s_username, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_username_N_updated_at_where_LE_id(tcp_connection* conn, const string& s_username, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_username_N_updated_at_where_GT_id(tcp_connection* conn, const string& s_username, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_username_N_updated_at_where_GE_id(tcp_connection* conn, const string& s_username, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_password_N_email_where_EQ_email(tcp_connection* conn, const string& s_password, const string& s_email, const string& w_email);
    static int update_user_test_set_password_N_email_where_EQ_id(tcp_connection* conn, const string& s_password, const string& s_email, const int32_t& w_id);
    static int update_user_test_set_password_N_email_where_LT_id(tcp_connection* conn, const string& s_password, const string& s_email, const int32_t& w_id);
    static int update_user_test_set_password_N_email_where_LE_id(tcp_connection* conn, const string& s_password, const string& s_email, const int32_t& w_id);
    static int update_user_test_set_password_N_email_where_GT_id(tcp_connection* conn, const string& s_password, const string& s_email, const int32_t& w_id);
    static int update_user_test_set_password_N_email_where_GE_id(tcp_connection* conn, const string& s_password, const string& s_email, const int32_t& w_id);
    static int update_user_test_set_password_N_created_at_where_EQ_email(tcp_connection* conn, const string& s_password, const datetime& s_created_at, const string& w_email);
    static int update_user_test_set_password_N_created_at_where_EQ_id(tcp_connection* conn, const string& s_password, const datetime& s_created_at, const int32_t& w_id);
    static int update_user_test_set_password_N_created_at_where_LT_id(tcp_connection* conn, const string& s_password, const datetime& s_created_at, const int32_t& w_id);
    static int update_user_test_set_password_N_created_at_where_LE_id(tcp_connection* conn, const string& s_password, const datetime& s_created_at, const int32_t& w_id);
    static int update_user_test_set_password_N_created_at_where_GT_id(tcp_connection* conn, const string& s_password, const datetime& s_created_at, const int32_t& w_id);
    static int update_user_test_set_password_N_created_at_where_GE_id(tcp_connection* conn, const string& s_password, const datetime& s_created_at, const int32_t& w_id);
    static int update_user_test_set_password_N_updated_at_where_EQ_email(tcp_connection* conn, const string& s_password, const datetime& s_updated_at, const string& w_email);
    static int update_user_test_set_password_N_updated_at_where_EQ_id(tcp_connection* conn, const string& s_password, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_password_N_updated_at_where_LT_id(tcp_connection* conn, const string& s_password, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_password_N_updated_at_where_LE_id(tcp_connection* conn, const string& s_password, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_password_N_updated_at_where_GT_id(tcp_connection* conn, const string& s_password, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_password_N_updated_at_where_GE_id(tcp_connection* conn, const string& s_password, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_email_N_created_at_where_EQ_email(tcp_connection* conn, const string& s_email, const datetime& s_created_at, const string& w_email);
    static int update_user_test_set_email_N_created_at_where_EQ_id(tcp_connection* conn, const string& s_email, const datetime& s_created_at, const int32_t& w_id);
    static int update_user_test_set_email_N_created_at_where_LT_id(tcp_connection* conn, const string& s_email, const datetime& s_created_at, const int32_t& w_id);
    static int update_user_test_set_email_N_created_at_where_LE_id(tcp_connection* conn, const string& s_email, const datetime& s_created_at, const int32_t& w_id);
    static int update_user_test_set_email_N_created_at_where_GT_id(tcp_connection* conn, const string& s_email, const datetime& s_created_at, const int32_t& w_id);
    static int update_user_test_set_email_N_created_at_where_GE_id(tcp_connection* conn, const string& s_email, const datetime& s_created_at, const int32_t& w_id);
    static int update_user_test_set_email_N_updated_at_where_EQ_email(tcp_connection* conn, const string& s_email, const datetime& s_updated_at, const string& w_email);
    static int update_user_test_set_email_N_updated_at_where_EQ_id(tcp_connection* conn, const string& s_email, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_email_N_updated_at_where_LT_id(tcp_connection* conn, const string& s_email, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_email_N_updated_at_where_LE_id(tcp_connection* conn, const string& s_email, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_email_N_updated_at_where_GT_id(tcp_connection* conn, const string& s_email, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_email_N_updated_at_where_GE_id(tcp_connection* conn, const string& s_email, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_created_at_N_updated_at_where_EQ_email(tcp_connection* conn, const datetime& s_created_at, const datetime& s_updated_at, const string& w_email);
    static int update_user_test_set_created_at_N_updated_at_where_EQ_id(tcp_connection* conn, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_created_at_N_updated_at_where_LT_id(tcp_connection* conn, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_created_at_N_updated_at_where_LE_id(tcp_connection* conn, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_created_at_N_updated_at_where_GT_id(tcp_connection* conn, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_created_at_N_updated_at_where_GE_id(tcp_connection* conn, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_id_N_username_N_password_where_EQ_email(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const string& w_email);
    static int update_user_test_set_id_N_username_N_password_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const int32_t& w_id);
    static int update_user_test_set_id_N_username_N_password_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const int32_t& w_id);
    static int update_user_test_set_id_N_username_N_password_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const int32_t& w_id);
    static int update_user_test_set_id_N_username_N_password_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const int32_t& w_id);
    static int update_user_test_set_id_N_username_N_password_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const int32_t& w_id);
    static int update_user_test_set_id_N_username_N_email_where_EQ_email(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_email, const string& w_email);
    static int update_user_test_set_id_N_username_N_email_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_email, const int32_t& w_id);
    static int update_user_test_set_id_N_username_N_email_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_email, const int32_t& w_id);
    static int update_user_test_set_id_N_username_N_email_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_email, const int32_t& w_id);
    static int update_user_test_set_id_N_username_N_email_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_email, const int32_t& w_id);
    static int update_user_test_set_id_N_username_N_email_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_email, const int32_t& w_id);
    static int update_user_test_set_id_N_username_N_created_at_where_EQ_email(tcp_connection* conn, const int32_t& s_id, const string& s_username, const datetime& s_created_at, const string& w_email);
    static int update_user_test_set_id_N_username_N_created_at_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const datetime& s_created_at, const int32_t& w_id);
    static int update_user_test_set_id_N_username_N_created_at_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const datetime& s_created_at, const int32_t& w_id);
    static int update_user_test_set_id_N_username_N_created_at_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const datetime& s_created_at, const int32_t& w_id);
    static int update_user_test_set_id_N_username_N_created_at_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const datetime& s_created_at, const int32_t& w_id);
    static int update_user_test_set_id_N_username_N_created_at_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const datetime& s_created_at, const int32_t& w_id);
    static int update_user_test_set_id_N_username_N_updated_at_where_EQ_email(tcp_connection* conn, const int32_t& s_id, const string& s_username, const datetime& s_updated_at, const string& w_email);
    static int update_user_test_set_id_N_username_N_updated_at_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_id_N_username_N_updated_at_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_id_N_username_N_updated_at_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_id_N_username_N_updated_at_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_id_N_username_N_updated_at_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_id_N_password_N_email_where_EQ_email(tcp_connection* conn, const int32_t& s_id, const string& s_password, const string& s_email, const string& w_email);
    static int update_user_test_set_id_N_password_N_email_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_password, const string& s_email, const int32_t& w_id);
    static int update_user_test_set_id_N_password_N_email_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_password, const string& s_email, const int32_t& w_id);
    static int update_user_test_set_id_N_password_N_email_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_password, const string& s_email, const int32_t& w_id);
    static int update_user_test_set_id_N_password_N_email_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_password, const string& s_email, const int32_t& w_id);
    static int update_user_test_set_id_N_password_N_email_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_password, const string& s_email, const int32_t& w_id);
    static int update_user_test_set_id_N_password_N_created_at_where_EQ_email(tcp_connection* conn, const int32_t& s_id, const string& s_password, const datetime& s_created_at, const string& w_email);
    static int update_user_test_set_id_N_password_N_created_at_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_password, const datetime& s_created_at, const int32_t& w_id);
    static int update_user_test_set_id_N_password_N_created_at_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_password, const datetime& s_created_at, const int32_t& w_id);
    static int update_user_test_set_id_N_password_N_created_at_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_password, const datetime& s_created_at, const int32_t& w_id);
    static int update_user_test_set_id_N_password_N_created_at_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_password, const datetime& s_created_at, const int32_t& w_id);
    static int update_user_test_set_id_N_password_N_created_at_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_password, const datetime& s_created_at, const int32_t& w_id);
    static int update_user_test_set_id_N_password_N_updated_at_where_EQ_email(tcp_connection* conn, const int32_t& s_id, const string& s_password, const datetime& s_updated_at, const string& w_email);
    static int update_user_test_set_id_N_password_N_updated_at_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_password, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_id_N_password_N_updated_at_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_password, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_id_N_password_N_updated_at_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_password, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_id_N_password_N_updated_at_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_password, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_id_N_password_N_updated_at_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_password, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_id_N_email_N_created_at_where_EQ_email(tcp_connection* conn, const int32_t& s_id, const string& s_email, const datetime& s_created_at, const string& w_email);
    static int update_user_test_set_id_N_email_N_created_at_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_email, const datetime& s_created_at, const int32_t& w_id);
    static int update_user_test_set_id_N_email_N_created_at_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_email, const datetime& s_created_at, const int32_t& w_id);
    static int update_user_test_set_id_N_email_N_created_at_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_email, const datetime& s_created_at, const int32_t& w_id);
    static int update_user_test_set_id_N_email_N_created_at_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_email, const datetime& s_created_at, const int32_t& w_id);
    static int update_user_test_set_id_N_email_N_created_at_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_email, const datetime& s_created_at, const int32_t& w_id);
    static int update_user_test_set_id_N_email_N_updated_at_where_EQ_email(tcp_connection* conn, const int32_t& s_id, const string& s_email, const datetime& s_updated_at, const string& w_email);
    static int update_user_test_set_id_N_email_N_updated_at_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_email, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_id_N_email_N_updated_at_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_email, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_id_N_email_N_updated_at_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_email, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_id_N_email_N_updated_at_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_email, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_id_N_email_N_updated_at_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_email, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_id_N_created_at_N_updated_at_where_EQ_email(tcp_connection* conn, const int32_t& s_id, const datetime& s_created_at, const datetime& s_updated_at, const string& w_email);
    static int update_user_test_set_id_N_created_at_N_updated_at_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_id_N_created_at_N_updated_at_where_LT_id(tcp_connection* conn, const int32_t& s_id, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_id_N_created_at_N_updated_at_where_LE_id(tcp_connection* conn, const int32_t& s_id, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_id_N_created_at_N_updated_at_where_GT_id(tcp_connection* conn, const int32_t& s_id, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_id_N_created_at_N_updated_at_where_GE_id(tcp_connection* conn, const int32_t& s_id, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_username_N_password_N_email_where_EQ_email(tcp_connection* conn, const string& s_username, const string& s_password, const string& s_email, const string& w_email);
    static int update_user_test_set_username_N_password_N_email_where_EQ_id(tcp_connection* conn, const string& s_username, const string& s_password, const string& s_email, const int32_t& w_id);
    static int update_user_test_set_username_N_password_N_email_where_LT_id(tcp_connection* conn, const string& s_username, const string& s_password, const string& s_email, const int32_t& w_id);
    static int update_user_test_set_username_N_password_N_email_where_LE_id(tcp_connection* conn, const string& s_username, const string& s_password, const string& s_email, const int32_t& w_id);
    static int update_user_test_set_username_N_password_N_email_where_GT_id(tcp_connection* conn, const string& s_username, const string& s_password, const string& s_email, const int32_t& w_id);
    static int update_user_test_set_username_N_password_N_email_where_GE_id(tcp_connection* conn, const string& s_username, const string& s_password, const string& s_email, const int32_t& w_id);
    static int update_user_test_set_username_N_password_N_created_at_where_EQ_email(tcp_connection* conn, const string& s_username, const string& s_password, const datetime& s_created_at, const string& w_email);
    static int update_user_test_set_username_N_password_N_created_at_where_EQ_id(tcp_connection* conn, const string& s_username, const string& s_password, const datetime& s_created_at, const int32_t& w_id);
    static int update_user_test_set_username_N_password_N_created_at_where_LT_id(tcp_connection* conn, const string& s_username, const string& s_password, const datetime& s_created_at, const int32_t& w_id);
    static int update_user_test_set_username_N_password_N_created_at_where_LE_id(tcp_connection* conn, const string& s_username, const string& s_password, const datetime& s_created_at, const int32_t& w_id);
    static int update_user_test_set_username_N_password_N_created_at_where_GT_id(tcp_connection* conn, const string& s_username, const string& s_password, const datetime& s_created_at, const int32_t& w_id);
    static int update_user_test_set_username_N_password_N_created_at_where_GE_id(tcp_connection* conn, const string& s_username, const string& s_password, const datetime& s_created_at, const int32_t& w_id);
    static int update_user_test_set_username_N_password_N_updated_at_where_EQ_email(tcp_connection* conn, const string& s_username, const string& s_password, const datetime& s_updated_at, const string& w_email);
    static int update_user_test_set_username_N_password_N_updated_at_where_EQ_id(tcp_connection* conn, const string& s_username, const string& s_password, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_username_N_password_N_updated_at_where_LT_id(tcp_connection* conn, const string& s_username, const string& s_password, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_username_N_password_N_updated_at_where_LE_id(tcp_connection* conn, const string& s_username, const string& s_password, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_username_N_password_N_updated_at_where_GT_id(tcp_connection* conn, const string& s_username, const string& s_password, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_username_N_password_N_updated_at_where_GE_id(tcp_connection* conn, const string& s_username, const string& s_password, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_username_N_email_N_created_at_where_EQ_email(tcp_connection* conn, const string& s_username, const string& s_email, const datetime& s_created_at, const string& w_email);
    static int update_user_test_set_username_N_email_N_created_at_where_EQ_id(tcp_connection* conn, const string& s_username, const string& s_email, const datetime& s_created_at, const int32_t& w_id);
    static int update_user_test_set_username_N_email_N_created_at_where_LT_id(tcp_connection* conn, const string& s_username, const string& s_email, const datetime& s_created_at, const int32_t& w_id);
    static int update_user_test_set_username_N_email_N_created_at_where_LE_id(tcp_connection* conn, const string& s_username, const string& s_email, const datetime& s_created_at, const int32_t& w_id);
    static int update_user_test_set_username_N_email_N_created_at_where_GT_id(tcp_connection* conn, const string& s_username, const string& s_email, const datetime& s_created_at, const int32_t& w_id);
    static int update_user_test_set_username_N_email_N_created_at_where_GE_id(tcp_connection* conn, const string& s_username, const string& s_email, const datetime& s_created_at, const int32_t& w_id);
    static int update_user_test_set_username_N_email_N_updated_at_where_EQ_email(tcp_connection* conn, const string& s_username, const string& s_email, const datetime& s_updated_at, const string& w_email);
    static int update_user_test_set_username_N_email_N_updated_at_where_EQ_id(tcp_connection* conn, const string& s_username, const string& s_email, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_username_N_email_N_updated_at_where_LT_id(tcp_connection* conn, const string& s_username, const string& s_email, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_username_N_email_N_updated_at_where_LE_id(tcp_connection* conn, const string& s_username, const string& s_email, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_username_N_email_N_updated_at_where_GT_id(tcp_connection* conn, const string& s_username, const string& s_email, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_username_N_email_N_updated_at_where_GE_id(tcp_connection* conn, const string& s_username, const string& s_email, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_username_N_created_at_N_updated_at_where_EQ_email(tcp_connection* conn, const string& s_username, const datetime& s_created_at, const datetime& s_updated_at, const string& w_email);
    static int update_user_test_set_username_N_created_at_N_updated_at_where_EQ_id(tcp_connection* conn, const string& s_username, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_username_N_created_at_N_updated_at_where_LT_id(tcp_connection* conn, const string& s_username, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_username_N_created_at_N_updated_at_where_LE_id(tcp_connection* conn, const string& s_username, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_username_N_created_at_N_updated_at_where_GT_id(tcp_connection* conn, const string& s_username, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_username_N_created_at_N_updated_at_where_GE_id(tcp_connection* conn, const string& s_username, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_password_N_email_N_created_at_where_EQ_email(tcp_connection* conn, const string& s_password, const string& s_email, const datetime& s_created_at, const string& w_email);
    static int update_user_test_set_password_N_email_N_created_at_where_EQ_id(tcp_connection* conn, const string& s_password, const string& s_email, const datetime& s_created_at, const int32_t& w_id);
    static int update_user_test_set_password_N_email_N_created_at_where_LT_id(tcp_connection* conn, const string& s_password, const string& s_email, const datetime& s_created_at, const int32_t& w_id);
    static int update_user_test_set_password_N_email_N_created_at_where_LE_id(tcp_connection* conn, const string& s_password, const string& s_email, const datetime& s_created_at, const int32_t& w_id);
    static int update_user_test_set_password_N_email_N_created_at_where_GT_id(tcp_connection* conn, const string& s_password, const string& s_email, const datetime& s_created_at, const int32_t& w_id);
    static int update_user_test_set_password_N_email_N_created_at_where_GE_id(tcp_connection* conn, const string& s_password, const string& s_email, const datetime& s_created_at, const int32_t& w_id);
    static int update_user_test_set_password_N_email_N_updated_at_where_EQ_email(tcp_connection* conn, const string& s_password, const string& s_email, const datetime& s_updated_at, const string& w_email);
    static int update_user_test_set_password_N_email_N_updated_at_where_EQ_id(tcp_connection* conn, const string& s_password, const string& s_email, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_password_N_email_N_updated_at_where_LT_id(tcp_connection* conn, const string& s_password, const string& s_email, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_password_N_email_N_updated_at_where_LE_id(tcp_connection* conn, const string& s_password, const string& s_email, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_password_N_email_N_updated_at_where_GT_id(tcp_connection* conn, const string& s_password, const string& s_email, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_password_N_email_N_updated_at_where_GE_id(tcp_connection* conn, const string& s_password, const string& s_email, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_password_N_created_at_N_updated_at_where_EQ_email(tcp_connection* conn, const string& s_password, const datetime& s_created_at, const datetime& s_updated_at, const string& w_email);
    static int update_user_test_set_password_N_created_at_N_updated_at_where_EQ_id(tcp_connection* conn, const string& s_password, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_password_N_created_at_N_updated_at_where_LT_id(tcp_connection* conn, const string& s_password, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_password_N_created_at_N_updated_at_where_LE_id(tcp_connection* conn, const string& s_password, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_password_N_created_at_N_updated_at_where_GT_id(tcp_connection* conn, const string& s_password, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_password_N_created_at_N_updated_at_where_GE_id(tcp_connection* conn, const string& s_password, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_email_N_created_at_N_updated_at_where_EQ_email(tcp_connection* conn, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const string& w_email);
    static int update_user_test_set_email_N_created_at_N_updated_at_where_EQ_id(tcp_connection* conn, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_email_N_created_at_N_updated_at_where_LT_id(tcp_connection* conn, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_email_N_created_at_N_updated_at_where_LE_id(tcp_connection* conn, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_email_N_created_at_N_updated_at_where_GT_id(tcp_connection* conn, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_email_N_created_at_N_updated_at_where_GE_id(tcp_connection* conn, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_id_N_username_N_password_N_email_where_EQ_email(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const string& s_email, const string& w_email);
    static int update_user_test_set_id_N_username_N_password_N_email_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const string& s_email, const int32_t& w_id);
    static int update_user_test_set_id_N_username_N_password_N_email_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const string& s_email, const int32_t& w_id);
    static int update_user_test_set_id_N_username_N_password_N_email_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const string& s_email, const int32_t& w_id);
    static int update_user_test_set_id_N_username_N_password_N_email_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const string& s_email, const int32_t& w_id);
    static int update_user_test_set_id_N_username_N_password_N_email_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const string& s_email, const int32_t& w_id);
    static int update_user_test_set_id_N_username_N_password_N_created_at_where_EQ_email(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const datetime& s_created_at, const string& w_email);
    static int update_user_test_set_id_N_username_N_password_N_created_at_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const datetime& s_created_at, const int32_t& w_id);
    static int update_user_test_set_id_N_username_N_password_N_created_at_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const datetime& s_created_at, const int32_t& w_id);
    static int update_user_test_set_id_N_username_N_password_N_created_at_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const datetime& s_created_at, const int32_t& w_id);
    static int update_user_test_set_id_N_username_N_password_N_created_at_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const datetime& s_created_at, const int32_t& w_id);
    static int update_user_test_set_id_N_username_N_password_N_created_at_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const datetime& s_created_at, const int32_t& w_id);
    static int update_user_test_set_id_N_username_N_password_N_updated_at_where_EQ_email(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const datetime& s_updated_at, const string& w_email);
    static int update_user_test_set_id_N_username_N_password_N_updated_at_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_id_N_username_N_password_N_updated_at_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_id_N_username_N_password_N_updated_at_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_id_N_username_N_password_N_updated_at_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_id_N_username_N_password_N_updated_at_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_id_N_username_N_email_N_created_at_where_EQ_email(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_email, const datetime& s_created_at, const string& w_email);
    static int update_user_test_set_id_N_username_N_email_N_created_at_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_email, const datetime& s_created_at, const int32_t& w_id);
    static int update_user_test_set_id_N_username_N_email_N_created_at_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_email, const datetime& s_created_at, const int32_t& w_id);
    static int update_user_test_set_id_N_username_N_email_N_created_at_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_email, const datetime& s_created_at, const int32_t& w_id);
    static int update_user_test_set_id_N_username_N_email_N_created_at_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_email, const datetime& s_created_at, const int32_t& w_id);
    static int update_user_test_set_id_N_username_N_email_N_created_at_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_email, const datetime& s_created_at, const int32_t& w_id);
    static int update_user_test_set_id_N_username_N_email_N_updated_at_where_EQ_email(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_email, const datetime& s_updated_at, const string& w_email);
    static int update_user_test_set_id_N_username_N_email_N_updated_at_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_email, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_id_N_username_N_email_N_updated_at_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_email, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_id_N_username_N_email_N_updated_at_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_email, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_id_N_username_N_email_N_updated_at_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_email, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_id_N_username_N_email_N_updated_at_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_email, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_id_N_username_N_created_at_N_updated_at_where_EQ_email(tcp_connection* conn, const int32_t& s_id, const string& s_username, const datetime& s_created_at, const datetime& s_updated_at, const string& w_email);
    static int update_user_test_set_id_N_username_N_created_at_N_updated_at_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_id_N_username_N_created_at_N_updated_at_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_id_N_username_N_created_at_N_updated_at_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_id_N_username_N_created_at_N_updated_at_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_id_N_username_N_created_at_N_updated_at_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_id_N_password_N_email_N_created_at_where_EQ_email(tcp_connection* conn, const int32_t& s_id, const string& s_password, const string& s_email, const datetime& s_created_at, const string& w_email);
    static int update_user_test_set_id_N_password_N_email_N_created_at_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_password, const string& s_email, const datetime& s_created_at, const int32_t& w_id);
    static int update_user_test_set_id_N_password_N_email_N_created_at_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_password, const string& s_email, const datetime& s_created_at, const int32_t& w_id);
    static int update_user_test_set_id_N_password_N_email_N_created_at_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_password, const string& s_email, const datetime& s_created_at, const int32_t& w_id);
    static int update_user_test_set_id_N_password_N_email_N_created_at_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_password, const string& s_email, const datetime& s_created_at, const int32_t& w_id);
    static int update_user_test_set_id_N_password_N_email_N_created_at_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_password, const string& s_email, const datetime& s_created_at, const int32_t& w_id);
    static int update_user_test_set_id_N_password_N_email_N_updated_at_where_EQ_email(tcp_connection* conn, const int32_t& s_id, const string& s_password, const string& s_email, const datetime& s_updated_at, const string& w_email);
    static int update_user_test_set_id_N_password_N_email_N_updated_at_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_password, const string& s_email, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_id_N_password_N_email_N_updated_at_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_password, const string& s_email, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_id_N_password_N_email_N_updated_at_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_password, const string& s_email, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_id_N_password_N_email_N_updated_at_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_password, const string& s_email, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_id_N_password_N_email_N_updated_at_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_password, const string& s_email, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_id_N_password_N_created_at_N_updated_at_where_EQ_email(tcp_connection* conn, const int32_t& s_id, const string& s_password, const datetime& s_created_at, const datetime& s_updated_at, const string& w_email);
    static int update_user_test_set_id_N_password_N_created_at_N_updated_at_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_password, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_id_N_password_N_created_at_N_updated_at_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_password, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_id_N_password_N_created_at_N_updated_at_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_password, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_id_N_password_N_created_at_N_updated_at_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_password, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_id_N_password_N_created_at_N_updated_at_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_password, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_id_N_email_N_created_at_N_updated_at_where_EQ_email(tcp_connection* conn, const int32_t& s_id, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const string& w_email);
    static int update_user_test_set_id_N_email_N_created_at_N_updated_at_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_id_N_email_N_created_at_N_updated_at_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_id_N_email_N_created_at_N_updated_at_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_id_N_email_N_created_at_N_updated_at_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_id_N_email_N_created_at_N_updated_at_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_username_N_password_N_email_N_created_at_where_EQ_email(tcp_connection* conn, const string& s_username, const string& s_password, const string& s_email, const datetime& s_created_at, const string& w_email);
    static int update_user_test_set_username_N_password_N_email_N_created_at_where_EQ_id(tcp_connection* conn, const string& s_username, const string& s_password, const string& s_email, const datetime& s_created_at, const int32_t& w_id);
    static int update_user_test_set_username_N_password_N_email_N_created_at_where_LT_id(tcp_connection* conn, const string& s_username, const string& s_password, const string& s_email, const datetime& s_created_at, const int32_t& w_id);
    static int update_user_test_set_username_N_password_N_email_N_created_at_where_LE_id(tcp_connection* conn, const string& s_username, const string& s_password, const string& s_email, const datetime& s_created_at, const int32_t& w_id);
    static int update_user_test_set_username_N_password_N_email_N_created_at_where_GT_id(tcp_connection* conn, const string& s_username, const string& s_password, const string& s_email, const datetime& s_created_at, const int32_t& w_id);
    static int update_user_test_set_username_N_password_N_email_N_created_at_where_GE_id(tcp_connection* conn, const string& s_username, const string& s_password, const string& s_email, const datetime& s_created_at, const int32_t& w_id);
    static int update_user_test_set_username_N_password_N_email_N_updated_at_where_EQ_email(tcp_connection* conn, const string& s_username, const string& s_password, const string& s_email, const datetime& s_updated_at, const string& w_email);
    static int update_user_test_set_username_N_password_N_email_N_updated_at_where_EQ_id(tcp_connection* conn, const string& s_username, const string& s_password, const string& s_email, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_username_N_password_N_email_N_updated_at_where_LT_id(tcp_connection* conn, const string& s_username, const string& s_password, const string& s_email, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_username_N_password_N_email_N_updated_at_where_LE_id(tcp_connection* conn, const string& s_username, const string& s_password, const string& s_email, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_username_N_password_N_email_N_updated_at_where_GT_id(tcp_connection* conn, const string& s_username, const string& s_password, const string& s_email, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_username_N_password_N_email_N_updated_at_where_GE_id(tcp_connection* conn, const string& s_username, const string& s_password, const string& s_email, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_username_N_password_N_created_at_N_updated_at_where_EQ_email(tcp_connection* conn, const string& s_username, const string& s_password, const datetime& s_created_at, const datetime& s_updated_at, const string& w_email);
    static int update_user_test_set_username_N_password_N_created_at_N_updated_at_where_EQ_id(tcp_connection* conn, const string& s_username, const string& s_password, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_username_N_password_N_created_at_N_updated_at_where_LT_id(tcp_connection* conn, const string& s_username, const string& s_password, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_username_N_password_N_created_at_N_updated_at_where_LE_id(tcp_connection* conn, const string& s_username, const string& s_password, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_username_N_password_N_created_at_N_updated_at_where_GT_id(tcp_connection* conn, const string& s_username, const string& s_password, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_username_N_password_N_created_at_N_updated_at_where_GE_id(tcp_connection* conn, const string& s_username, const string& s_password, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_username_N_email_N_created_at_N_updated_at_where_EQ_email(tcp_connection* conn, const string& s_username, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const string& w_email);
    static int update_user_test_set_username_N_email_N_created_at_N_updated_at_where_EQ_id(tcp_connection* conn, const string& s_username, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_username_N_email_N_created_at_N_updated_at_where_LT_id(tcp_connection* conn, const string& s_username, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_username_N_email_N_created_at_N_updated_at_where_LE_id(tcp_connection* conn, const string& s_username, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_username_N_email_N_created_at_N_updated_at_where_GT_id(tcp_connection* conn, const string& s_username, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_username_N_email_N_created_at_N_updated_at_where_GE_id(tcp_connection* conn, const string& s_username, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_password_N_email_N_created_at_N_updated_at_where_EQ_email(tcp_connection* conn, const string& s_password, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const string& w_email);
    static int update_user_test_set_password_N_email_N_created_at_N_updated_at_where_EQ_id(tcp_connection* conn, const string& s_password, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_password_N_email_N_created_at_N_updated_at_where_LT_id(tcp_connection* conn, const string& s_password, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_password_N_email_N_created_at_N_updated_at_where_LE_id(tcp_connection* conn, const string& s_password, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_password_N_email_N_created_at_N_updated_at_where_GT_id(tcp_connection* conn, const string& s_password, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_password_N_email_N_created_at_N_updated_at_where_GE_id(tcp_connection* conn, const string& s_password, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_id_N_username_N_password_N_email_N_created_at_where_EQ_email(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const string& s_email, const datetime& s_created_at, const string& w_email);
    static int update_user_test_set_id_N_username_N_password_N_email_N_created_at_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const string& s_email, const datetime& s_created_at, const int32_t& w_id);
    static int update_user_test_set_id_N_username_N_password_N_email_N_created_at_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const string& s_email, const datetime& s_created_at, const int32_t& w_id);
    static int update_user_test_set_id_N_username_N_password_N_email_N_created_at_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const string& s_email, const datetime& s_created_at, const int32_t& w_id);
    static int update_user_test_set_id_N_username_N_password_N_email_N_created_at_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const string& s_email, const datetime& s_created_at, const int32_t& w_id);
    static int update_user_test_set_id_N_username_N_password_N_email_N_created_at_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const string& s_email, const datetime& s_created_at, const int32_t& w_id);
    static int update_user_test_set_id_N_username_N_password_N_email_N_updated_at_where_EQ_email(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const string& s_email, const datetime& s_updated_at, const string& w_email);
    static int update_user_test_set_id_N_username_N_password_N_email_N_updated_at_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const string& s_email, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_id_N_username_N_password_N_email_N_updated_at_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const string& s_email, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_id_N_username_N_password_N_email_N_updated_at_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const string& s_email, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_id_N_username_N_password_N_email_N_updated_at_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const string& s_email, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_id_N_username_N_password_N_email_N_updated_at_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const string& s_email, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_id_N_username_N_password_N_created_at_N_updated_at_where_EQ_email(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const datetime& s_created_at, const datetime& s_updated_at, const string& w_email);
    static int update_user_test_set_id_N_username_N_password_N_created_at_N_updated_at_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_id_N_username_N_password_N_created_at_N_updated_at_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_id_N_username_N_password_N_created_at_N_updated_at_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_id_N_username_N_password_N_created_at_N_updated_at_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_id_N_username_N_password_N_created_at_N_updated_at_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_id_N_username_N_email_N_created_at_N_updated_at_where_EQ_email(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const string& w_email);
    static int update_user_test_set_id_N_username_N_email_N_created_at_N_updated_at_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_id_N_username_N_email_N_created_at_N_updated_at_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_id_N_username_N_email_N_created_at_N_updated_at_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_id_N_username_N_email_N_created_at_N_updated_at_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_id_N_username_N_email_N_created_at_N_updated_at_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_id_N_password_N_email_N_created_at_N_updated_at_where_EQ_email(tcp_connection* conn, const int32_t& s_id, const string& s_password, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const string& w_email);
    static int update_user_test_set_id_N_password_N_email_N_created_at_N_updated_at_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_password, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_id_N_password_N_email_N_created_at_N_updated_at_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_password, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_id_N_password_N_email_N_created_at_N_updated_at_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_password, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_id_N_password_N_email_N_created_at_N_updated_at_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_password, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_id_N_password_N_email_N_created_at_N_updated_at_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_password, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_username_N_password_N_email_N_created_at_N_updated_at_where_EQ_email(tcp_connection* conn, const string& s_username, const string& s_password, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const string& w_email);
    static int update_user_test_set_username_N_password_N_email_N_created_at_N_updated_at_where_EQ_id(tcp_connection* conn, const string& s_username, const string& s_password, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_username_N_password_N_email_N_created_at_N_updated_at_where_LT_id(tcp_connection* conn, const string& s_username, const string& s_password, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_username_N_password_N_email_N_created_at_N_updated_at_where_LE_id(tcp_connection* conn, const string& s_username, const string& s_password, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_username_N_password_N_email_N_created_at_N_updated_at_where_GT_id(tcp_connection* conn, const string& s_username, const string& s_password, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_username_N_password_N_email_N_created_at_N_updated_at_where_GE_id(tcp_connection* conn, const string& s_username, const string& s_password, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_id_N_username_N_password_N_email_N_created_at_N_updated_at_where_EQ_email(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const string& w_email);
    static int update_user_test_set_id_N_username_N_password_N_email_N_created_at_N_updated_at_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_id_N_username_N_password_N_email_N_created_at_N_updated_at_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_id_N_username_N_password_N_email_N_created_at_N_updated_at_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_id_N_username_N_password_N_email_N_created_at_N_updated_at_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id);
    static int update_user_test_set_id_N_username_N_password_N_email_N_created_at_N_updated_at_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id);
    static int delete_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email);
    static int delete_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static int delete_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static int delete_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static int delete_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static int delete_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id);
};

// SP 호출 구현

inline int user_test_orm::insert_into_user_test_username_N_password_N_email(tcp_connection* conn, const string& new_username, const string& new_password, const string& new_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10160(?, ?, ?)");
        conn->execute(stmt.bind(new_username, new_password, new_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return -1;
    }

    return result.affected_rows();
}

    
inline results user_test_orm::select_id_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10161(?)");
        conn->execute(stmt.bind(w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10162(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10163(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10164(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10165(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10166(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10167(?)");
        conn->execute(stmt.bind(w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10168(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10169(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10170(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10171(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10172(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_password_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10173(?)");
        conn->execute(stmt.bind(w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_password_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10174(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_password_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10175(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_password_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10176(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_password_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10177(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_password_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10178(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_email_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10179(?)");
        conn->execute(stmt.bind(w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_email_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10180(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_email_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10181(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_email_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10182(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_email_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10183(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_email_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10184(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_created_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10185(?)");
        conn->execute(stmt.bind(w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_created_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10186(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_created_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10187(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_created_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10188(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_created_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10189(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_created_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10190(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_updated_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10191(?)");
        conn->execute(stmt.bind(w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_updated_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10192(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_updated_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10193(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_updated_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10194(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_updated_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10195(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_updated_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10196(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10197(?)");
        conn->execute(stmt.bind(w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10198(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10199(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10200(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10201(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10202(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_password_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10203(?)");
        conn->execute(stmt.bind(w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_password_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10204(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_password_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10205(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_password_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10206(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_password_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10207(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_password_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10208(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_email_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10209(?)");
        conn->execute(stmt.bind(w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_email_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10210(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_email_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10211(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_email_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10212(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_email_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10213(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_email_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10214(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_created_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10215(?)");
        conn->execute(stmt.bind(w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_created_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10216(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_created_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10217(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_created_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10218(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_created_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10219(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_created_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10220(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_updated_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10221(?)");
        conn->execute(stmt.bind(w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_updated_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10222(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_updated_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10223(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_updated_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10224(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_updated_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10225(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_updated_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10226(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_password_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10227(?)");
        conn->execute(stmt.bind(w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_password_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10228(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_password_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10229(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_password_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10230(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_password_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10231(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_password_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10232(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_email_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10233(?)");
        conn->execute(stmt.bind(w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_email_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10234(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_email_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10235(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_email_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10236(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_email_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10237(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_email_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10238(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_created_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10239(?)");
        conn->execute(stmt.bind(w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_created_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10240(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_created_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10241(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_created_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10242(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_created_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10243(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_created_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10244(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_updated_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10245(?)");
        conn->execute(stmt.bind(w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_updated_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10246(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_updated_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10247(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_updated_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10248(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_updated_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10249(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_updated_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10250(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_password_N_email_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10251(?)");
        conn->execute(stmt.bind(w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_password_N_email_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10252(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_password_N_email_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10253(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_password_N_email_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10254(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_password_N_email_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10255(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_password_N_email_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10256(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_password_N_created_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10257(?)");
        conn->execute(stmt.bind(w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_password_N_created_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10258(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_password_N_created_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10259(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_password_N_created_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10260(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_password_N_created_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10261(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_password_N_created_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10262(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_password_N_updated_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10263(?)");
        conn->execute(stmt.bind(w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_password_N_updated_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10264(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_password_N_updated_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10265(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_password_N_updated_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10266(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_password_N_updated_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10267(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_password_N_updated_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10268(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_email_N_created_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10269(?)");
        conn->execute(stmt.bind(w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_email_N_created_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10270(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_email_N_created_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10271(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_email_N_created_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10272(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_email_N_created_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10273(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_email_N_created_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10274(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_email_N_updated_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10275(?)");
        conn->execute(stmt.bind(w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_email_N_updated_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10276(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_email_N_updated_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10277(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_email_N_updated_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10278(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_email_N_updated_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10279(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_email_N_updated_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10280(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_created_at_N_updated_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10281(?)");
        conn->execute(stmt.bind(w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_created_at_N_updated_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10282(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_created_at_N_updated_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10283(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_created_at_N_updated_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10284(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_created_at_N_updated_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10285(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_created_at_N_updated_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10286(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_N_password_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10287(?)");
        conn->execute(stmt.bind(w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_N_password_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10288(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_N_password_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10289(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_N_password_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10290(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_N_password_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10291(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_N_password_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10292(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_N_email_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10293(?)");
        conn->execute(stmt.bind(w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_N_email_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10294(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_N_email_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10295(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_N_email_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10296(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_N_email_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10297(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_N_email_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10298(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_N_created_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10299(?)");
        conn->execute(stmt.bind(w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_N_created_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10300(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_N_created_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10301(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_N_created_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10302(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_N_created_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10303(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_N_created_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10304(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_N_updated_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10305(?)");
        conn->execute(stmt.bind(w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_N_updated_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10306(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_N_updated_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10307(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_N_updated_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10308(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_N_updated_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10309(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_N_updated_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10310(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_password_N_email_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10311(?)");
        conn->execute(stmt.bind(w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_password_N_email_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10312(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_password_N_email_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10313(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_password_N_email_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10314(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_password_N_email_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10315(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_password_N_email_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10316(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_password_N_created_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10317(?)");
        conn->execute(stmt.bind(w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_password_N_created_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10318(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_password_N_created_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10319(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_password_N_created_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10320(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_password_N_created_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10321(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_password_N_created_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10322(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_password_N_updated_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10323(?)");
        conn->execute(stmt.bind(w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_password_N_updated_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10324(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_password_N_updated_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10325(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_password_N_updated_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10326(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_password_N_updated_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10327(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_password_N_updated_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10328(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_email_N_created_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10329(?)");
        conn->execute(stmt.bind(w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_email_N_created_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10330(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_email_N_created_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10331(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_email_N_created_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10332(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_email_N_created_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10333(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_email_N_created_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10334(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_email_N_updated_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10335(?)");
        conn->execute(stmt.bind(w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_email_N_updated_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10336(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_email_N_updated_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10337(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_email_N_updated_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10338(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_email_N_updated_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10339(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_email_N_updated_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10340(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_created_at_N_updated_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10341(?)");
        conn->execute(stmt.bind(w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_created_at_N_updated_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10342(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_created_at_N_updated_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10343(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_created_at_N_updated_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10344(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_created_at_N_updated_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10345(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_created_at_N_updated_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10346(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_password_N_email_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10347(?)");
        conn->execute(stmt.bind(w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_password_N_email_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10348(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_password_N_email_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10349(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_password_N_email_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10350(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_password_N_email_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10351(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_password_N_email_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10352(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_password_N_created_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10353(?)");
        conn->execute(stmt.bind(w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_password_N_created_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10354(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_password_N_created_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10355(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_password_N_created_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10356(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_password_N_created_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10357(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_password_N_created_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10358(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_password_N_updated_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10359(?)");
        conn->execute(stmt.bind(w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_password_N_updated_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10360(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_password_N_updated_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10361(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_password_N_updated_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10362(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_password_N_updated_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10363(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_password_N_updated_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10364(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_email_N_created_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10365(?)");
        conn->execute(stmt.bind(w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_email_N_created_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10366(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_email_N_created_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10367(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_email_N_created_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10368(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_email_N_created_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10369(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_email_N_created_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10370(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_email_N_updated_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10371(?)");
        conn->execute(stmt.bind(w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_email_N_updated_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10372(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_email_N_updated_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10373(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_email_N_updated_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10374(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_email_N_updated_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10375(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_email_N_updated_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10376(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_created_at_N_updated_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10377(?)");
        conn->execute(stmt.bind(w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_created_at_N_updated_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10378(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_created_at_N_updated_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10379(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_created_at_N_updated_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10380(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_created_at_N_updated_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10381(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_created_at_N_updated_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10382(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_password_N_email_N_created_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10383(?)");
        conn->execute(stmt.bind(w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_password_N_email_N_created_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10384(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_password_N_email_N_created_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10385(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_password_N_email_N_created_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10386(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_password_N_email_N_created_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10387(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_password_N_email_N_created_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10388(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_password_N_email_N_updated_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10389(?)");
        conn->execute(stmt.bind(w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_password_N_email_N_updated_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10390(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_password_N_email_N_updated_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10391(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_password_N_email_N_updated_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10392(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_password_N_email_N_updated_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10393(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_password_N_email_N_updated_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10394(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_password_N_created_at_N_updated_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10395(?)");
        conn->execute(stmt.bind(w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_password_N_created_at_N_updated_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10396(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_password_N_created_at_N_updated_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10397(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_password_N_created_at_N_updated_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10398(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_password_N_created_at_N_updated_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10399(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_password_N_created_at_N_updated_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10400(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_email_N_created_at_N_updated_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10401(?)");
        conn->execute(stmt.bind(w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_email_N_created_at_N_updated_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10402(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_email_N_created_at_N_updated_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10403(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_email_N_created_at_N_updated_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10404(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_email_N_created_at_N_updated_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10405(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_email_N_created_at_N_updated_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10406(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_N_password_N_email_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10407(?)");
        conn->execute(stmt.bind(w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_N_password_N_email_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10408(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_N_password_N_email_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10409(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_N_password_N_email_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10410(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_N_password_N_email_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10411(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_N_password_N_email_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10412(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_N_password_N_created_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10413(?)");
        conn->execute(stmt.bind(w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_N_password_N_created_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10414(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_N_password_N_created_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10415(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_N_password_N_created_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10416(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_N_password_N_created_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10417(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_N_password_N_created_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10418(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_N_password_N_updated_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10419(?)");
        conn->execute(stmt.bind(w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_N_password_N_updated_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10420(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_N_password_N_updated_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10421(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_N_password_N_updated_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10422(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_N_password_N_updated_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10423(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_N_password_N_updated_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10424(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_N_email_N_created_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10425(?)");
        conn->execute(stmt.bind(w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_N_email_N_created_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10426(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_N_email_N_created_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10427(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_N_email_N_created_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10428(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_N_email_N_created_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10429(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_N_email_N_created_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10430(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_N_email_N_updated_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10431(?)");
        conn->execute(stmt.bind(w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_N_email_N_updated_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10432(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_N_email_N_updated_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10433(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_N_email_N_updated_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10434(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_N_email_N_updated_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10435(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_N_email_N_updated_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10436(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_N_created_at_N_updated_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10437(?)");
        conn->execute(stmt.bind(w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_N_created_at_N_updated_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10438(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_N_created_at_N_updated_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10439(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_N_created_at_N_updated_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10440(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_N_created_at_N_updated_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10441(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_N_created_at_N_updated_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10442(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_password_N_email_N_created_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10443(?)");
        conn->execute(stmt.bind(w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_password_N_email_N_created_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10444(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_password_N_email_N_created_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10445(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_password_N_email_N_created_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10446(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_password_N_email_N_created_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10447(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_password_N_email_N_created_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10448(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_password_N_email_N_updated_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10449(?)");
        conn->execute(stmt.bind(w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_password_N_email_N_updated_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10450(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_password_N_email_N_updated_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10451(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_password_N_email_N_updated_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10452(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_password_N_email_N_updated_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10453(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_password_N_email_N_updated_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10454(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_password_N_created_at_N_updated_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10455(?)");
        conn->execute(stmt.bind(w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_password_N_created_at_N_updated_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10456(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_password_N_created_at_N_updated_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10457(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_password_N_created_at_N_updated_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10458(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_password_N_created_at_N_updated_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10459(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_password_N_created_at_N_updated_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10460(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_email_N_created_at_N_updated_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10461(?)");
        conn->execute(stmt.bind(w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_email_N_created_at_N_updated_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10462(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_email_N_created_at_N_updated_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10463(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_email_N_created_at_N_updated_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10464(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_email_N_created_at_N_updated_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10465(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_email_N_created_at_N_updated_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10466(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_password_N_email_N_created_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10467(?)");
        conn->execute(stmt.bind(w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_password_N_email_N_created_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10468(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_password_N_email_N_created_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10469(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_password_N_email_N_created_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10470(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_password_N_email_N_created_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10471(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_password_N_email_N_created_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10472(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_password_N_email_N_updated_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10473(?)");
        conn->execute(stmt.bind(w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_password_N_email_N_updated_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10474(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_password_N_email_N_updated_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10475(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_password_N_email_N_updated_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10476(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_password_N_email_N_updated_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10477(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_password_N_email_N_updated_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10478(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_password_N_created_at_N_updated_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10479(?)");
        conn->execute(stmt.bind(w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_password_N_created_at_N_updated_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10480(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_password_N_created_at_N_updated_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10481(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_password_N_created_at_N_updated_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10482(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_password_N_created_at_N_updated_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10483(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_password_N_created_at_N_updated_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10484(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_email_N_created_at_N_updated_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10485(?)");
        conn->execute(stmt.bind(w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_email_N_created_at_N_updated_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10486(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_email_N_created_at_N_updated_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10487(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_email_N_created_at_N_updated_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10488(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_email_N_created_at_N_updated_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10489(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_email_N_created_at_N_updated_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10490(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_password_N_email_N_created_at_N_updated_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10491(?)");
        conn->execute(stmt.bind(w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_password_N_email_N_created_at_N_updated_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10492(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_password_N_email_N_created_at_N_updated_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10493(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_password_N_email_N_created_at_N_updated_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10494(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_password_N_email_N_created_at_N_updated_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10495(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_password_N_email_N_created_at_N_updated_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10496(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_N_password_N_email_N_created_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10497(?)");
        conn->execute(stmt.bind(w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_N_password_N_email_N_created_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10498(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_N_password_N_email_N_created_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10499(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_N_password_N_email_N_created_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10500(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_N_password_N_email_N_created_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10501(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_N_password_N_email_N_created_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10502(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_N_password_N_email_N_updated_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10503(?)");
        conn->execute(stmt.bind(w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_N_password_N_email_N_updated_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10504(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_N_password_N_email_N_updated_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10505(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_N_password_N_email_N_updated_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10506(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_N_password_N_email_N_updated_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10507(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_N_password_N_email_N_updated_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10508(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_N_password_N_created_at_N_updated_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10509(?)");
        conn->execute(stmt.bind(w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_N_password_N_created_at_N_updated_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10510(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_N_password_N_created_at_N_updated_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10511(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_N_password_N_created_at_N_updated_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10512(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_N_password_N_created_at_N_updated_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10513(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_N_password_N_created_at_N_updated_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10514(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_N_email_N_created_at_N_updated_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10515(?)");
        conn->execute(stmt.bind(w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_N_email_N_created_at_N_updated_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10516(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_N_email_N_created_at_N_updated_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10517(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_N_email_N_created_at_N_updated_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10518(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_N_email_N_created_at_N_updated_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10519(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_username_N_email_N_created_at_N_updated_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10520(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_password_N_email_N_created_at_N_updated_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10521(?)");
        conn->execute(stmt.bind(w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_password_N_email_N_created_at_N_updated_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10522(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_password_N_email_N_created_at_N_updated_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10523(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_password_N_email_N_created_at_N_updated_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10524(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_password_N_email_N_created_at_N_updated_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10525(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_id_N_password_N_email_N_created_at_N_updated_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10526(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_password_N_email_N_created_at_N_updated_at_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10527(?)");
        conn->execute(stmt.bind(w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_password_N_email_N_created_at_N_updated_at_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10528(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_password_N_email_N_created_at_N_updated_at_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10529(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_password_N_email_N_created_at_N_updated_at_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10530(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_password_N_email_N_created_at_N_updated_at_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10531(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_username_N_password_N_email_N_created_at_N_updated_at_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10532(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_all_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10533(?)");
        conn->execute(stmt.bind(w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_all_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10534(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_all_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10535(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_all_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10536(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_all_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10537(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results user_test_orm::select_all_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10538(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline int user_test_orm::update_user_test_set_id_where_EQ_email(tcp_connection* conn, const int32_t& s_id, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10539(?, ?)");
        conn->execute(stmt.bind(s_id, w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10540(?, ?)");
        conn->execute(stmt.bind(s_id, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_where_LT_id(tcp_connection* conn, const int32_t& s_id, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10541(?, ?)");
        conn->execute(stmt.bind(s_id, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_where_LE_id(tcp_connection* conn, const int32_t& s_id, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10542(?, ?)");
        conn->execute(stmt.bind(s_id, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_where_GT_id(tcp_connection* conn, const int32_t& s_id, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10543(?, ?)");
        conn->execute(stmt.bind(s_id, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_where_GE_id(tcp_connection* conn, const int32_t& s_id, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10544(?, ?)");
        conn->execute(stmt.bind(s_id, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_where_EQ_email(tcp_connection* conn, const string& s_username, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10545(?, ?)");
        conn->execute(stmt.bind(s_username, w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_where_EQ_id(tcp_connection* conn, const string& s_username, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10546(?, ?)");
        conn->execute(stmt.bind(s_username, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_where_LT_id(tcp_connection* conn, const string& s_username, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10547(?, ?)");
        conn->execute(stmt.bind(s_username, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_where_LE_id(tcp_connection* conn, const string& s_username, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10548(?, ?)");
        conn->execute(stmt.bind(s_username, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_where_GT_id(tcp_connection* conn, const string& s_username, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10549(?, ?)");
        conn->execute(stmt.bind(s_username, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_where_GE_id(tcp_connection* conn, const string& s_username, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10550(?, ?)");
        conn->execute(stmt.bind(s_username, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_password_where_EQ_email(tcp_connection* conn, const string& s_password, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10551(?, ?)");
        conn->execute(stmt.bind(s_password, w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_password_where_EQ_id(tcp_connection* conn, const string& s_password, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10552(?, ?)");
        conn->execute(stmt.bind(s_password, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_password_where_LT_id(tcp_connection* conn, const string& s_password, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10553(?, ?)");
        conn->execute(stmt.bind(s_password, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_password_where_LE_id(tcp_connection* conn, const string& s_password, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10554(?, ?)");
        conn->execute(stmt.bind(s_password, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_password_where_GT_id(tcp_connection* conn, const string& s_password, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10555(?, ?)");
        conn->execute(stmt.bind(s_password, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_password_where_GE_id(tcp_connection* conn, const string& s_password, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10556(?, ?)");
        conn->execute(stmt.bind(s_password, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_email_where_EQ_email(tcp_connection* conn, const string& s_email, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10557(?, ?)");
        conn->execute(stmt.bind(s_email, w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_email_where_EQ_id(tcp_connection* conn, const string& s_email, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10558(?, ?)");
        conn->execute(stmt.bind(s_email, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_email_where_LT_id(tcp_connection* conn, const string& s_email, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10559(?, ?)");
        conn->execute(stmt.bind(s_email, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_email_where_LE_id(tcp_connection* conn, const string& s_email, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10560(?, ?)");
        conn->execute(stmt.bind(s_email, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_email_where_GT_id(tcp_connection* conn, const string& s_email, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10561(?, ?)");
        conn->execute(stmt.bind(s_email, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_email_where_GE_id(tcp_connection* conn, const string& s_email, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10562(?, ?)");
        conn->execute(stmt.bind(s_email, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_created_at_where_EQ_email(tcp_connection* conn, const datetime& s_created_at, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10563(?, ?)");
        conn->execute(stmt.bind(s_created_at, w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_created_at_where_EQ_id(tcp_connection* conn, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10564(?, ?)");
        conn->execute(stmt.bind(s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_created_at_where_LT_id(tcp_connection* conn, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10565(?, ?)");
        conn->execute(stmt.bind(s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_created_at_where_LE_id(tcp_connection* conn, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10566(?, ?)");
        conn->execute(stmt.bind(s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_created_at_where_GT_id(tcp_connection* conn, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10567(?, ?)");
        conn->execute(stmt.bind(s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_created_at_where_GE_id(tcp_connection* conn, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10568(?, ?)");
        conn->execute(stmt.bind(s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_updated_at_where_EQ_email(tcp_connection* conn, const datetime& s_updated_at, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10569(?, ?)");
        conn->execute(stmt.bind(s_updated_at, w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_updated_at_where_EQ_id(tcp_connection* conn, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10570(?, ?)");
        conn->execute(stmt.bind(s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_updated_at_where_LT_id(tcp_connection* conn, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10571(?, ?)");
        conn->execute(stmt.bind(s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_updated_at_where_LE_id(tcp_connection* conn, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10572(?, ?)");
        conn->execute(stmt.bind(s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_updated_at_where_GT_id(tcp_connection* conn, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10573(?, ?)");
        conn->execute(stmt.bind(s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_updated_at_where_GE_id(tcp_connection* conn, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10574(?, ?)");
        conn->execute(stmt.bind(s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_where_EQ_email(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10575(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10576(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10577(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10578(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10579(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10580(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_password_where_EQ_email(tcp_connection* conn, const int32_t& s_id, const string& s_password, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10581(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_password, w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_password_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_password, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10582(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_password, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_password_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_password, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10583(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_password, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_password_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_password, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10584(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_password, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_password_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_password, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10585(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_password, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_password_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_password, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10586(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_password, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_email_where_EQ_email(tcp_connection* conn, const int32_t& s_id, const string& s_email, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10587(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_email, w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_email_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_email, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10588(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_email, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_email_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_email, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10589(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_email, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_email_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_email, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10590(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_email, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_email_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_email, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10591(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_email, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_email_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_email, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10592(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_email, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_created_at_where_EQ_email(tcp_connection* conn, const int32_t& s_id, const datetime& s_created_at, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10593(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_created_at, w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_created_at_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10594(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_created_at_where_LT_id(tcp_connection* conn, const int32_t& s_id, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10595(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_created_at_where_LE_id(tcp_connection* conn, const int32_t& s_id, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10596(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_created_at_where_GT_id(tcp_connection* conn, const int32_t& s_id, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10597(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_created_at_where_GE_id(tcp_connection* conn, const int32_t& s_id, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10598(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_updated_at_where_EQ_email(tcp_connection* conn, const int32_t& s_id, const datetime& s_updated_at, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10599(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_updated_at, w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_updated_at_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10600(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_updated_at_where_LT_id(tcp_connection* conn, const int32_t& s_id, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10601(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_updated_at_where_LE_id(tcp_connection* conn, const int32_t& s_id, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10602(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_updated_at_where_GT_id(tcp_connection* conn, const int32_t& s_id, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10603(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_updated_at_where_GE_id(tcp_connection* conn, const int32_t& s_id, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10604(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_password_where_EQ_email(tcp_connection* conn, const string& s_username, const string& s_password, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10605(?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_password, w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_password_where_EQ_id(tcp_connection* conn, const string& s_username, const string& s_password, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10606(?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_password, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_password_where_LT_id(tcp_connection* conn, const string& s_username, const string& s_password, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10607(?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_password, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_password_where_LE_id(tcp_connection* conn, const string& s_username, const string& s_password, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10608(?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_password, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_password_where_GT_id(tcp_connection* conn, const string& s_username, const string& s_password, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10609(?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_password, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_password_where_GE_id(tcp_connection* conn, const string& s_username, const string& s_password, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10610(?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_password, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_email_where_EQ_email(tcp_connection* conn, const string& s_username, const string& s_email, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10611(?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_email, w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_email_where_EQ_id(tcp_connection* conn, const string& s_username, const string& s_email, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10612(?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_email, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_email_where_LT_id(tcp_connection* conn, const string& s_username, const string& s_email, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10613(?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_email, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_email_where_LE_id(tcp_connection* conn, const string& s_username, const string& s_email, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10614(?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_email, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_email_where_GT_id(tcp_connection* conn, const string& s_username, const string& s_email, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10615(?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_email, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_email_where_GE_id(tcp_connection* conn, const string& s_username, const string& s_email, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10616(?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_email, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_created_at_where_EQ_email(tcp_connection* conn, const string& s_username, const datetime& s_created_at, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10617(?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_created_at, w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_created_at_where_EQ_id(tcp_connection* conn, const string& s_username, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10618(?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_created_at_where_LT_id(tcp_connection* conn, const string& s_username, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10619(?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_created_at_where_LE_id(tcp_connection* conn, const string& s_username, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10620(?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_created_at_where_GT_id(tcp_connection* conn, const string& s_username, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10621(?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_created_at_where_GE_id(tcp_connection* conn, const string& s_username, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10622(?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_updated_at_where_EQ_email(tcp_connection* conn, const string& s_username, const datetime& s_updated_at, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10623(?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_updated_at, w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_updated_at_where_EQ_id(tcp_connection* conn, const string& s_username, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10624(?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_updated_at_where_LT_id(tcp_connection* conn, const string& s_username, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10625(?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_updated_at_where_LE_id(tcp_connection* conn, const string& s_username, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10626(?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_updated_at_where_GT_id(tcp_connection* conn, const string& s_username, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10627(?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_updated_at_where_GE_id(tcp_connection* conn, const string& s_username, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10628(?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_password_N_email_where_EQ_email(tcp_connection* conn, const string& s_password, const string& s_email, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10629(?, ?, ?)");
        conn->execute(stmt.bind(s_password, s_email, w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_password_N_email_where_EQ_id(tcp_connection* conn, const string& s_password, const string& s_email, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10630(?, ?, ?)");
        conn->execute(stmt.bind(s_password, s_email, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_password_N_email_where_LT_id(tcp_connection* conn, const string& s_password, const string& s_email, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10631(?, ?, ?)");
        conn->execute(stmt.bind(s_password, s_email, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_password_N_email_where_LE_id(tcp_connection* conn, const string& s_password, const string& s_email, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10632(?, ?, ?)");
        conn->execute(stmt.bind(s_password, s_email, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_password_N_email_where_GT_id(tcp_connection* conn, const string& s_password, const string& s_email, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10633(?, ?, ?)");
        conn->execute(stmt.bind(s_password, s_email, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_password_N_email_where_GE_id(tcp_connection* conn, const string& s_password, const string& s_email, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10634(?, ?, ?)");
        conn->execute(stmt.bind(s_password, s_email, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_password_N_created_at_where_EQ_email(tcp_connection* conn, const string& s_password, const datetime& s_created_at, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10635(?, ?, ?)");
        conn->execute(stmt.bind(s_password, s_created_at, w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_password_N_created_at_where_EQ_id(tcp_connection* conn, const string& s_password, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10636(?, ?, ?)");
        conn->execute(stmt.bind(s_password, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_password_N_created_at_where_LT_id(tcp_connection* conn, const string& s_password, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10637(?, ?, ?)");
        conn->execute(stmt.bind(s_password, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_password_N_created_at_where_LE_id(tcp_connection* conn, const string& s_password, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10638(?, ?, ?)");
        conn->execute(stmt.bind(s_password, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_password_N_created_at_where_GT_id(tcp_connection* conn, const string& s_password, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10639(?, ?, ?)");
        conn->execute(stmt.bind(s_password, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_password_N_created_at_where_GE_id(tcp_connection* conn, const string& s_password, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10640(?, ?, ?)");
        conn->execute(stmt.bind(s_password, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_password_N_updated_at_where_EQ_email(tcp_connection* conn, const string& s_password, const datetime& s_updated_at, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10641(?, ?, ?)");
        conn->execute(stmt.bind(s_password, s_updated_at, w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_password_N_updated_at_where_EQ_id(tcp_connection* conn, const string& s_password, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10642(?, ?, ?)");
        conn->execute(stmt.bind(s_password, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_password_N_updated_at_where_LT_id(tcp_connection* conn, const string& s_password, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10643(?, ?, ?)");
        conn->execute(stmt.bind(s_password, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_password_N_updated_at_where_LE_id(tcp_connection* conn, const string& s_password, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10644(?, ?, ?)");
        conn->execute(stmt.bind(s_password, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_password_N_updated_at_where_GT_id(tcp_connection* conn, const string& s_password, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10645(?, ?, ?)");
        conn->execute(stmt.bind(s_password, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_password_N_updated_at_where_GE_id(tcp_connection* conn, const string& s_password, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10646(?, ?, ?)");
        conn->execute(stmt.bind(s_password, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_email_N_created_at_where_EQ_email(tcp_connection* conn, const string& s_email, const datetime& s_created_at, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10647(?, ?, ?)");
        conn->execute(stmt.bind(s_email, s_created_at, w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_email_N_created_at_where_EQ_id(tcp_connection* conn, const string& s_email, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10648(?, ?, ?)");
        conn->execute(stmt.bind(s_email, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_email_N_created_at_where_LT_id(tcp_connection* conn, const string& s_email, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10649(?, ?, ?)");
        conn->execute(stmt.bind(s_email, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_email_N_created_at_where_LE_id(tcp_connection* conn, const string& s_email, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10650(?, ?, ?)");
        conn->execute(stmt.bind(s_email, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_email_N_created_at_where_GT_id(tcp_connection* conn, const string& s_email, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10651(?, ?, ?)");
        conn->execute(stmt.bind(s_email, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_email_N_created_at_where_GE_id(tcp_connection* conn, const string& s_email, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10652(?, ?, ?)");
        conn->execute(stmt.bind(s_email, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_email_N_updated_at_where_EQ_email(tcp_connection* conn, const string& s_email, const datetime& s_updated_at, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10653(?, ?, ?)");
        conn->execute(stmt.bind(s_email, s_updated_at, w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_email_N_updated_at_where_EQ_id(tcp_connection* conn, const string& s_email, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10654(?, ?, ?)");
        conn->execute(stmt.bind(s_email, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_email_N_updated_at_where_LT_id(tcp_connection* conn, const string& s_email, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10655(?, ?, ?)");
        conn->execute(stmt.bind(s_email, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_email_N_updated_at_where_LE_id(tcp_connection* conn, const string& s_email, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10656(?, ?, ?)");
        conn->execute(stmt.bind(s_email, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_email_N_updated_at_where_GT_id(tcp_connection* conn, const string& s_email, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10657(?, ?, ?)");
        conn->execute(stmt.bind(s_email, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_email_N_updated_at_where_GE_id(tcp_connection* conn, const string& s_email, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10658(?, ?, ?)");
        conn->execute(stmt.bind(s_email, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_created_at_N_updated_at_where_EQ_email(tcp_connection* conn, const datetime& s_created_at, const datetime& s_updated_at, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10659(?, ?, ?)");
        conn->execute(stmt.bind(s_created_at, s_updated_at, w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_created_at_N_updated_at_where_EQ_id(tcp_connection* conn, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10660(?, ?, ?)");
        conn->execute(stmt.bind(s_created_at, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_created_at_N_updated_at_where_LT_id(tcp_connection* conn, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10661(?, ?, ?)");
        conn->execute(stmt.bind(s_created_at, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_created_at_N_updated_at_where_LE_id(tcp_connection* conn, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10662(?, ?, ?)");
        conn->execute(stmt.bind(s_created_at, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_created_at_N_updated_at_where_GT_id(tcp_connection* conn, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10663(?, ?, ?)");
        conn->execute(stmt.bind(s_created_at, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_created_at_N_updated_at_where_GE_id(tcp_connection* conn, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10664(?, ?, ?)");
        conn->execute(stmt.bind(s_created_at, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_password_where_EQ_email(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10665(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_password, w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_password_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10666(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_password, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_password_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10667(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_password, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_password_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10668(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_password, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_password_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10669(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_password, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_password_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10670(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_password, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_email_where_EQ_email(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_email, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10671(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_email, w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_email_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_email, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10672(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_email, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_email_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_email, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10673(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_email, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_email_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_email, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10674(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_email, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_email_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_email, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10675(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_email, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_email_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_email, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10676(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_email, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_created_at_where_EQ_email(tcp_connection* conn, const int32_t& s_id, const string& s_username, const datetime& s_created_at, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10677(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_created_at, w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_created_at_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10678(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_created_at_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10679(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_created_at_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10680(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_created_at_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10681(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_created_at_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10682(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_updated_at_where_EQ_email(tcp_connection* conn, const int32_t& s_id, const string& s_username, const datetime& s_updated_at, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10683(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_updated_at, w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_updated_at_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10684(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_updated_at_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10685(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_updated_at_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10686(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_updated_at_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10687(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_updated_at_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10688(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_password_N_email_where_EQ_email(tcp_connection* conn, const int32_t& s_id, const string& s_password, const string& s_email, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10689(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_password, s_email, w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_password_N_email_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_password, const string& s_email, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10690(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_password, s_email, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_password_N_email_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_password, const string& s_email, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10691(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_password, s_email, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_password_N_email_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_password, const string& s_email, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10692(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_password, s_email, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_password_N_email_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_password, const string& s_email, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10693(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_password, s_email, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_password_N_email_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_password, const string& s_email, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10694(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_password, s_email, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_password_N_created_at_where_EQ_email(tcp_connection* conn, const int32_t& s_id, const string& s_password, const datetime& s_created_at, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10695(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_password, s_created_at, w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_password_N_created_at_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_password, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10696(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_password, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_password_N_created_at_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_password, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10697(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_password, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_password_N_created_at_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_password, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10698(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_password, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_password_N_created_at_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_password, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10699(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_password, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_password_N_created_at_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_password, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10700(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_password, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_password_N_updated_at_where_EQ_email(tcp_connection* conn, const int32_t& s_id, const string& s_password, const datetime& s_updated_at, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10701(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_password, s_updated_at, w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_password_N_updated_at_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_password, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10702(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_password, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_password_N_updated_at_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_password, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10703(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_password, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_password_N_updated_at_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_password, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10704(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_password, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_password_N_updated_at_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_password, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10705(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_password, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_password_N_updated_at_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_password, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10706(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_password, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_email_N_created_at_where_EQ_email(tcp_connection* conn, const int32_t& s_id, const string& s_email, const datetime& s_created_at, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10707(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_email, s_created_at, w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_email_N_created_at_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_email, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10708(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_email, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_email_N_created_at_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_email, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10709(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_email, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_email_N_created_at_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_email, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10710(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_email, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_email_N_created_at_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_email, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10711(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_email, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_email_N_created_at_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_email, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10712(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_email, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_email_N_updated_at_where_EQ_email(tcp_connection* conn, const int32_t& s_id, const string& s_email, const datetime& s_updated_at, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10713(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_email, s_updated_at, w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_email_N_updated_at_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_email, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10714(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_email, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_email_N_updated_at_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_email, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10715(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_email, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_email_N_updated_at_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_email, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10716(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_email, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_email_N_updated_at_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_email, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10717(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_email, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_email_N_updated_at_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_email, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10718(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_email, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_created_at_N_updated_at_where_EQ_email(tcp_connection* conn, const int32_t& s_id, const datetime& s_created_at, const datetime& s_updated_at, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10719(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_created_at, s_updated_at, w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_created_at_N_updated_at_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10720(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_created_at, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_created_at_N_updated_at_where_LT_id(tcp_connection* conn, const int32_t& s_id, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10721(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_created_at, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_created_at_N_updated_at_where_LE_id(tcp_connection* conn, const int32_t& s_id, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10722(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_created_at, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_created_at_N_updated_at_where_GT_id(tcp_connection* conn, const int32_t& s_id, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10723(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_created_at, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_created_at_N_updated_at_where_GE_id(tcp_connection* conn, const int32_t& s_id, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10724(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_created_at, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_password_N_email_where_EQ_email(tcp_connection* conn, const string& s_username, const string& s_password, const string& s_email, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10725(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_password, s_email, w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_password_N_email_where_EQ_id(tcp_connection* conn, const string& s_username, const string& s_password, const string& s_email, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10726(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_password, s_email, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_password_N_email_where_LT_id(tcp_connection* conn, const string& s_username, const string& s_password, const string& s_email, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10727(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_password, s_email, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_password_N_email_where_LE_id(tcp_connection* conn, const string& s_username, const string& s_password, const string& s_email, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10728(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_password, s_email, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_password_N_email_where_GT_id(tcp_connection* conn, const string& s_username, const string& s_password, const string& s_email, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10729(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_password, s_email, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_password_N_email_where_GE_id(tcp_connection* conn, const string& s_username, const string& s_password, const string& s_email, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10730(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_password, s_email, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_password_N_created_at_where_EQ_email(tcp_connection* conn, const string& s_username, const string& s_password, const datetime& s_created_at, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10731(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_password, s_created_at, w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_password_N_created_at_where_EQ_id(tcp_connection* conn, const string& s_username, const string& s_password, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10732(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_password, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_password_N_created_at_where_LT_id(tcp_connection* conn, const string& s_username, const string& s_password, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10733(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_password, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_password_N_created_at_where_LE_id(tcp_connection* conn, const string& s_username, const string& s_password, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10734(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_password, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_password_N_created_at_where_GT_id(tcp_connection* conn, const string& s_username, const string& s_password, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10735(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_password, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_password_N_created_at_where_GE_id(tcp_connection* conn, const string& s_username, const string& s_password, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10736(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_password, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_password_N_updated_at_where_EQ_email(tcp_connection* conn, const string& s_username, const string& s_password, const datetime& s_updated_at, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10737(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_password, s_updated_at, w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_password_N_updated_at_where_EQ_id(tcp_connection* conn, const string& s_username, const string& s_password, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10738(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_password, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_password_N_updated_at_where_LT_id(tcp_connection* conn, const string& s_username, const string& s_password, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10739(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_password, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_password_N_updated_at_where_LE_id(tcp_connection* conn, const string& s_username, const string& s_password, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10740(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_password, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_password_N_updated_at_where_GT_id(tcp_connection* conn, const string& s_username, const string& s_password, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10741(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_password, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_password_N_updated_at_where_GE_id(tcp_connection* conn, const string& s_username, const string& s_password, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10742(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_password, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_email_N_created_at_where_EQ_email(tcp_connection* conn, const string& s_username, const string& s_email, const datetime& s_created_at, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10743(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_email, s_created_at, w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_email_N_created_at_where_EQ_id(tcp_connection* conn, const string& s_username, const string& s_email, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10744(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_email, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_email_N_created_at_where_LT_id(tcp_connection* conn, const string& s_username, const string& s_email, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10745(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_email, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_email_N_created_at_where_LE_id(tcp_connection* conn, const string& s_username, const string& s_email, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10746(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_email, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_email_N_created_at_where_GT_id(tcp_connection* conn, const string& s_username, const string& s_email, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10747(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_email, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_email_N_created_at_where_GE_id(tcp_connection* conn, const string& s_username, const string& s_email, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10748(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_email, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_email_N_updated_at_where_EQ_email(tcp_connection* conn, const string& s_username, const string& s_email, const datetime& s_updated_at, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10749(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_email, s_updated_at, w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_email_N_updated_at_where_EQ_id(tcp_connection* conn, const string& s_username, const string& s_email, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10750(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_email, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_email_N_updated_at_where_LT_id(tcp_connection* conn, const string& s_username, const string& s_email, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10751(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_email, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_email_N_updated_at_where_LE_id(tcp_connection* conn, const string& s_username, const string& s_email, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10752(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_email, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_email_N_updated_at_where_GT_id(tcp_connection* conn, const string& s_username, const string& s_email, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10753(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_email, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_email_N_updated_at_where_GE_id(tcp_connection* conn, const string& s_username, const string& s_email, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10754(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_email, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_created_at_N_updated_at_where_EQ_email(tcp_connection* conn, const string& s_username, const datetime& s_created_at, const datetime& s_updated_at, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10755(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_created_at, s_updated_at, w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_created_at_N_updated_at_where_EQ_id(tcp_connection* conn, const string& s_username, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10756(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_created_at, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_created_at_N_updated_at_where_LT_id(tcp_connection* conn, const string& s_username, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10757(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_created_at, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_created_at_N_updated_at_where_LE_id(tcp_connection* conn, const string& s_username, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10758(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_created_at, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_created_at_N_updated_at_where_GT_id(tcp_connection* conn, const string& s_username, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10759(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_created_at, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_created_at_N_updated_at_where_GE_id(tcp_connection* conn, const string& s_username, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10760(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_created_at, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_password_N_email_N_created_at_where_EQ_email(tcp_connection* conn, const string& s_password, const string& s_email, const datetime& s_created_at, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10761(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_password, s_email, s_created_at, w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_password_N_email_N_created_at_where_EQ_id(tcp_connection* conn, const string& s_password, const string& s_email, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10762(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_password, s_email, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_password_N_email_N_created_at_where_LT_id(tcp_connection* conn, const string& s_password, const string& s_email, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10763(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_password, s_email, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_password_N_email_N_created_at_where_LE_id(tcp_connection* conn, const string& s_password, const string& s_email, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10764(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_password, s_email, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_password_N_email_N_created_at_where_GT_id(tcp_connection* conn, const string& s_password, const string& s_email, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10765(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_password, s_email, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_password_N_email_N_created_at_where_GE_id(tcp_connection* conn, const string& s_password, const string& s_email, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10766(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_password, s_email, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_password_N_email_N_updated_at_where_EQ_email(tcp_connection* conn, const string& s_password, const string& s_email, const datetime& s_updated_at, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10767(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_password, s_email, s_updated_at, w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_password_N_email_N_updated_at_where_EQ_id(tcp_connection* conn, const string& s_password, const string& s_email, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10768(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_password, s_email, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_password_N_email_N_updated_at_where_LT_id(tcp_connection* conn, const string& s_password, const string& s_email, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10769(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_password, s_email, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_password_N_email_N_updated_at_where_LE_id(tcp_connection* conn, const string& s_password, const string& s_email, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10770(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_password, s_email, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_password_N_email_N_updated_at_where_GT_id(tcp_connection* conn, const string& s_password, const string& s_email, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10771(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_password, s_email, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_password_N_email_N_updated_at_where_GE_id(tcp_connection* conn, const string& s_password, const string& s_email, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10772(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_password, s_email, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_password_N_created_at_N_updated_at_where_EQ_email(tcp_connection* conn, const string& s_password, const datetime& s_created_at, const datetime& s_updated_at, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10773(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_password, s_created_at, s_updated_at, w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_password_N_created_at_N_updated_at_where_EQ_id(tcp_connection* conn, const string& s_password, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10774(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_password, s_created_at, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_password_N_created_at_N_updated_at_where_LT_id(tcp_connection* conn, const string& s_password, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10775(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_password, s_created_at, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_password_N_created_at_N_updated_at_where_LE_id(tcp_connection* conn, const string& s_password, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10776(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_password, s_created_at, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_password_N_created_at_N_updated_at_where_GT_id(tcp_connection* conn, const string& s_password, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10777(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_password, s_created_at, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_password_N_created_at_N_updated_at_where_GE_id(tcp_connection* conn, const string& s_password, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10778(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_password, s_created_at, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_email_N_created_at_N_updated_at_where_EQ_email(tcp_connection* conn, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10779(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_email, s_created_at, s_updated_at, w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_email_N_created_at_N_updated_at_where_EQ_id(tcp_connection* conn, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10780(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_email, s_created_at, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_email_N_created_at_N_updated_at_where_LT_id(tcp_connection* conn, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10781(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_email, s_created_at, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_email_N_created_at_N_updated_at_where_LE_id(tcp_connection* conn, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10782(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_email, s_created_at, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_email_N_created_at_N_updated_at_where_GT_id(tcp_connection* conn, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10783(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_email, s_created_at, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_email_N_created_at_N_updated_at_where_GE_id(tcp_connection* conn, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10784(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_email, s_created_at, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_password_N_email_where_EQ_email(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const string& s_email, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10785(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_password, s_email, w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_password_N_email_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const string& s_email, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10786(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_password, s_email, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_password_N_email_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const string& s_email, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10787(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_password, s_email, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_password_N_email_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const string& s_email, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10788(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_password, s_email, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_password_N_email_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const string& s_email, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10789(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_password, s_email, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_password_N_email_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const string& s_email, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10790(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_password, s_email, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_password_N_created_at_where_EQ_email(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const datetime& s_created_at, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10791(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_password, s_created_at, w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_password_N_created_at_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10792(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_password, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_password_N_created_at_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10793(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_password, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_password_N_created_at_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10794(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_password, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_password_N_created_at_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10795(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_password, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_password_N_created_at_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10796(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_password, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_password_N_updated_at_where_EQ_email(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const datetime& s_updated_at, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10797(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_password, s_updated_at, w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_password_N_updated_at_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10798(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_password, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_password_N_updated_at_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10799(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_password, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_password_N_updated_at_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10800(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_password, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_password_N_updated_at_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10801(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_password, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_password_N_updated_at_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10802(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_password, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_email_N_created_at_where_EQ_email(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_email, const datetime& s_created_at, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10803(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_email, s_created_at, w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_email_N_created_at_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_email, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10804(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_email, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_email_N_created_at_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_email, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10805(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_email, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_email_N_created_at_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_email, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10806(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_email, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_email_N_created_at_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_email, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10807(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_email, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_email_N_created_at_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_email, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10808(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_email, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_email_N_updated_at_where_EQ_email(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_email, const datetime& s_updated_at, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10809(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_email, s_updated_at, w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_email_N_updated_at_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_email, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10810(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_email, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_email_N_updated_at_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_email, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10811(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_email, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_email_N_updated_at_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_email, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10812(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_email, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_email_N_updated_at_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_email, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10813(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_email, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_email_N_updated_at_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_email, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10814(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_email, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_created_at_N_updated_at_where_EQ_email(tcp_connection* conn, const int32_t& s_id, const string& s_username, const datetime& s_created_at, const datetime& s_updated_at, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10815(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_created_at, s_updated_at, w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_created_at_N_updated_at_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10816(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_created_at, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_created_at_N_updated_at_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10817(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_created_at, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_created_at_N_updated_at_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10818(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_created_at, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_created_at_N_updated_at_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10819(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_created_at, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_created_at_N_updated_at_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10820(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_created_at, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_password_N_email_N_created_at_where_EQ_email(tcp_connection* conn, const int32_t& s_id, const string& s_password, const string& s_email, const datetime& s_created_at, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10821(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_password, s_email, s_created_at, w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_password_N_email_N_created_at_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_password, const string& s_email, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10822(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_password, s_email, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_password_N_email_N_created_at_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_password, const string& s_email, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10823(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_password, s_email, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_password_N_email_N_created_at_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_password, const string& s_email, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10824(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_password, s_email, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_password_N_email_N_created_at_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_password, const string& s_email, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10825(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_password, s_email, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_password_N_email_N_created_at_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_password, const string& s_email, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10826(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_password, s_email, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_password_N_email_N_updated_at_where_EQ_email(tcp_connection* conn, const int32_t& s_id, const string& s_password, const string& s_email, const datetime& s_updated_at, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10827(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_password, s_email, s_updated_at, w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_password_N_email_N_updated_at_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_password, const string& s_email, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10828(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_password, s_email, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_password_N_email_N_updated_at_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_password, const string& s_email, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10829(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_password, s_email, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_password_N_email_N_updated_at_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_password, const string& s_email, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10830(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_password, s_email, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_password_N_email_N_updated_at_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_password, const string& s_email, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10831(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_password, s_email, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_password_N_email_N_updated_at_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_password, const string& s_email, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10832(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_password, s_email, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_password_N_created_at_N_updated_at_where_EQ_email(tcp_connection* conn, const int32_t& s_id, const string& s_password, const datetime& s_created_at, const datetime& s_updated_at, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10833(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_password, s_created_at, s_updated_at, w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_password_N_created_at_N_updated_at_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_password, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10834(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_password, s_created_at, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_password_N_created_at_N_updated_at_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_password, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10835(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_password, s_created_at, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_password_N_created_at_N_updated_at_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_password, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10836(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_password, s_created_at, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_password_N_created_at_N_updated_at_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_password, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10837(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_password, s_created_at, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_password_N_created_at_N_updated_at_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_password, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10838(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_password, s_created_at, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_email_N_created_at_N_updated_at_where_EQ_email(tcp_connection* conn, const int32_t& s_id, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10839(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_email, s_created_at, s_updated_at, w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_email_N_created_at_N_updated_at_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10840(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_email, s_created_at, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_email_N_created_at_N_updated_at_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10841(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_email, s_created_at, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_email_N_created_at_N_updated_at_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10842(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_email, s_created_at, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_email_N_created_at_N_updated_at_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10843(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_email, s_created_at, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_email_N_created_at_N_updated_at_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10844(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_email, s_created_at, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_password_N_email_N_created_at_where_EQ_email(tcp_connection* conn, const string& s_username, const string& s_password, const string& s_email, const datetime& s_created_at, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10845(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_password, s_email, s_created_at, w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_password_N_email_N_created_at_where_EQ_id(tcp_connection* conn, const string& s_username, const string& s_password, const string& s_email, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10846(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_password, s_email, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_password_N_email_N_created_at_where_LT_id(tcp_connection* conn, const string& s_username, const string& s_password, const string& s_email, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10847(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_password, s_email, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_password_N_email_N_created_at_where_LE_id(tcp_connection* conn, const string& s_username, const string& s_password, const string& s_email, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10848(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_password, s_email, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_password_N_email_N_created_at_where_GT_id(tcp_connection* conn, const string& s_username, const string& s_password, const string& s_email, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10849(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_password, s_email, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_password_N_email_N_created_at_where_GE_id(tcp_connection* conn, const string& s_username, const string& s_password, const string& s_email, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10850(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_password, s_email, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_password_N_email_N_updated_at_where_EQ_email(tcp_connection* conn, const string& s_username, const string& s_password, const string& s_email, const datetime& s_updated_at, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10851(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_password, s_email, s_updated_at, w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_password_N_email_N_updated_at_where_EQ_id(tcp_connection* conn, const string& s_username, const string& s_password, const string& s_email, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10852(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_password, s_email, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_password_N_email_N_updated_at_where_LT_id(tcp_connection* conn, const string& s_username, const string& s_password, const string& s_email, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10853(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_password, s_email, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_password_N_email_N_updated_at_where_LE_id(tcp_connection* conn, const string& s_username, const string& s_password, const string& s_email, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10854(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_password, s_email, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_password_N_email_N_updated_at_where_GT_id(tcp_connection* conn, const string& s_username, const string& s_password, const string& s_email, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10855(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_password, s_email, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_password_N_email_N_updated_at_where_GE_id(tcp_connection* conn, const string& s_username, const string& s_password, const string& s_email, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10856(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_password, s_email, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_password_N_created_at_N_updated_at_where_EQ_email(tcp_connection* conn, const string& s_username, const string& s_password, const datetime& s_created_at, const datetime& s_updated_at, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10857(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_password, s_created_at, s_updated_at, w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_password_N_created_at_N_updated_at_where_EQ_id(tcp_connection* conn, const string& s_username, const string& s_password, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10858(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_password, s_created_at, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_password_N_created_at_N_updated_at_where_LT_id(tcp_connection* conn, const string& s_username, const string& s_password, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10859(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_password, s_created_at, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_password_N_created_at_N_updated_at_where_LE_id(tcp_connection* conn, const string& s_username, const string& s_password, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10860(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_password, s_created_at, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_password_N_created_at_N_updated_at_where_GT_id(tcp_connection* conn, const string& s_username, const string& s_password, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10861(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_password, s_created_at, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_password_N_created_at_N_updated_at_where_GE_id(tcp_connection* conn, const string& s_username, const string& s_password, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10862(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_password, s_created_at, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_email_N_created_at_N_updated_at_where_EQ_email(tcp_connection* conn, const string& s_username, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10863(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_email, s_created_at, s_updated_at, w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_email_N_created_at_N_updated_at_where_EQ_id(tcp_connection* conn, const string& s_username, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10864(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_email, s_created_at, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_email_N_created_at_N_updated_at_where_LT_id(tcp_connection* conn, const string& s_username, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10865(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_email, s_created_at, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_email_N_created_at_N_updated_at_where_LE_id(tcp_connection* conn, const string& s_username, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10866(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_email, s_created_at, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_email_N_created_at_N_updated_at_where_GT_id(tcp_connection* conn, const string& s_username, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10867(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_email, s_created_at, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_email_N_created_at_N_updated_at_where_GE_id(tcp_connection* conn, const string& s_username, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10868(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_email, s_created_at, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_password_N_email_N_created_at_N_updated_at_where_EQ_email(tcp_connection* conn, const string& s_password, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10869(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_password, s_email, s_created_at, s_updated_at, w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_password_N_email_N_created_at_N_updated_at_where_EQ_id(tcp_connection* conn, const string& s_password, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10870(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_password, s_email, s_created_at, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_password_N_email_N_created_at_N_updated_at_where_LT_id(tcp_connection* conn, const string& s_password, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10871(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_password, s_email, s_created_at, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_password_N_email_N_created_at_N_updated_at_where_LE_id(tcp_connection* conn, const string& s_password, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10872(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_password, s_email, s_created_at, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_password_N_email_N_created_at_N_updated_at_where_GT_id(tcp_connection* conn, const string& s_password, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10873(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_password, s_email, s_created_at, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_password_N_email_N_created_at_N_updated_at_where_GE_id(tcp_connection* conn, const string& s_password, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10874(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_password, s_email, s_created_at, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_password_N_email_N_created_at_where_EQ_email(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const string& s_email, const datetime& s_created_at, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10875(?, ?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_password, s_email, s_created_at, w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_password_N_email_N_created_at_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const string& s_email, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10876(?, ?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_password, s_email, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_password_N_email_N_created_at_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const string& s_email, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10877(?, ?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_password, s_email, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_password_N_email_N_created_at_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const string& s_email, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10878(?, ?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_password, s_email, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_password_N_email_N_created_at_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const string& s_email, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10879(?, ?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_password, s_email, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_password_N_email_N_created_at_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const string& s_email, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10880(?, ?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_password, s_email, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_password_N_email_N_updated_at_where_EQ_email(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const string& s_email, const datetime& s_updated_at, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10881(?, ?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_password, s_email, s_updated_at, w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_password_N_email_N_updated_at_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const string& s_email, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10882(?, ?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_password, s_email, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_password_N_email_N_updated_at_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const string& s_email, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10883(?, ?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_password, s_email, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_password_N_email_N_updated_at_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const string& s_email, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10884(?, ?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_password, s_email, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_password_N_email_N_updated_at_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const string& s_email, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10885(?, ?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_password, s_email, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_password_N_email_N_updated_at_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const string& s_email, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10886(?, ?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_password, s_email, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_password_N_created_at_N_updated_at_where_EQ_email(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const datetime& s_created_at, const datetime& s_updated_at, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10887(?, ?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_password, s_created_at, s_updated_at, w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_password_N_created_at_N_updated_at_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10888(?, ?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_password, s_created_at, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_password_N_created_at_N_updated_at_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10889(?, ?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_password, s_created_at, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_password_N_created_at_N_updated_at_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10890(?, ?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_password, s_created_at, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_password_N_created_at_N_updated_at_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10891(?, ?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_password, s_created_at, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_password_N_created_at_N_updated_at_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10892(?, ?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_password, s_created_at, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_email_N_created_at_N_updated_at_where_EQ_email(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10893(?, ?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_email, s_created_at, s_updated_at, w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_email_N_created_at_N_updated_at_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10894(?, ?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_email, s_created_at, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_email_N_created_at_N_updated_at_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10895(?, ?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_email, s_created_at, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_email_N_created_at_N_updated_at_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10896(?, ?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_email, s_created_at, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_email_N_created_at_N_updated_at_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10897(?, ?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_email, s_created_at, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_email_N_created_at_N_updated_at_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10898(?, ?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_email, s_created_at, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_password_N_email_N_created_at_N_updated_at_where_EQ_email(tcp_connection* conn, const int32_t& s_id, const string& s_password, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10899(?, ?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_password, s_email, s_created_at, s_updated_at, w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_password_N_email_N_created_at_N_updated_at_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_password, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10900(?, ?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_password, s_email, s_created_at, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_password_N_email_N_created_at_N_updated_at_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_password, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10901(?, ?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_password, s_email, s_created_at, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_password_N_email_N_created_at_N_updated_at_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_password, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10902(?, ?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_password, s_email, s_created_at, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_password_N_email_N_created_at_N_updated_at_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_password, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10903(?, ?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_password, s_email, s_created_at, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_password_N_email_N_created_at_N_updated_at_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_password, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10904(?, ?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_password, s_email, s_created_at, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_password_N_email_N_created_at_N_updated_at_where_EQ_email(tcp_connection* conn, const string& s_username, const string& s_password, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10905(?, ?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_password, s_email, s_created_at, s_updated_at, w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_password_N_email_N_created_at_N_updated_at_where_EQ_id(tcp_connection* conn, const string& s_username, const string& s_password, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10906(?, ?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_password, s_email, s_created_at, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_password_N_email_N_created_at_N_updated_at_where_LT_id(tcp_connection* conn, const string& s_username, const string& s_password, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10907(?, ?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_password, s_email, s_created_at, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_password_N_email_N_created_at_N_updated_at_where_LE_id(tcp_connection* conn, const string& s_username, const string& s_password, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10908(?, ?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_password, s_email, s_created_at, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_password_N_email_N_created_at_N_updated_at_where_GT_id(tcp_connection* conn, const string& s_username, const string& s_password, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10909(?, ?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_password, s_email, s_created_at, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_username_N_password_N_email_N_created_at_N_updated_at_where_GE_id(tcp_connection* conn, const string& s_username, const string& s_password, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10910(?, ?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_username, s_password, s_email, s_created_at, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_password_N_email_N_created_at_N_updated_at_where_EQ_email(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10911(?, ?, ?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_password, s_email, s_created_at, s_updated_at, w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_password_N_email_N_created_at_N_updated_at_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10912(?, ?, ?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_password, s_email, s_created_at, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_password_N_email_N_created_at_N_updated_at_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10913(?, ?, ?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_password, s_email, s_created_at, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_password_N_email_N_created_at_N_updated_at_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10914(?, ?, ?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_password, s_email, s_created_at, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_password_N_email_N_created_at_N_updated_at_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10915(?, ?, ?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_password, s_email, s_created_at, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::update_user_test_set_id_N_username_N_password_N_email_N_created_at_N_updated_at_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_username, const string& s_password, const string& s_email, const datetime& s_created_at, const datetime& s_updated_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10916(?, ?, ?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_username, s_password, s_email, s_created_at, s_updated_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::delete_from_user_test_where_EQ_email(tcp_connection* conn, const string& w_email)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10917(?)");
        conn->execute(stmt.bind(w_email), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::delete_from_user_test_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10918(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::delete_from_user_test_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10919(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::delete_from_user_test_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10920(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::delete_from_user_test_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10921(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int user_test_orm::delete_from_user_test_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10922(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}



} // namespace ORM
