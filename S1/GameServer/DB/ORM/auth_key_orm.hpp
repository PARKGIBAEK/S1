
#pragma once

#include <boost/mysql.hpp>
#include <boost/mysql/tcp.hpp>
#include <boost/describe.hpp>
#include <string>
#include <iostream>
#include <format>
#include "Macros/WanringSuppression.h"
DISABLE_WARNING(4244)

using namespace boost::mysql;
using namespace std;

namespace ORM_test {

struct auth_key
{
    int32_t id; // int
    string key_value; // varchar(256)
    datetime created_at; // timestamp
};

BOOST_DESCRIBE_STRUCT(auth_key, (), (id, key_value, created_at));

class auth_key_orm
{
public:
    // SP 호출 선언
    static int insert_into_auth_key_key_value(tcp_connection* conn, const string& new_key_value);
    static results select_id_from_auth_key_where_EQ_created_at(tcp_connection* conn, const datetime& w_created_at);
    static results select_id_from_auth_key_where_LT_created_at(tcp_connection* conn, const datetime& w_created_at);
    static results select_id_from_auth_key_where_LE_created_at(tcp_connection* conn, const datetime& w_created_at);
    static results select_id_from_auth_key_where_GT_created_at(tcp_connection* conn, const datetime& w_created_at);
    static results select_id_from_auth_key_where_GE_created_at(tcp_connection* conn, const datetime& w_created_at);
    static results select_id_from_auth_key_where_EQ_key_value(tcp_connection* conn, const string& w_key_value);
    static results select_id_from_auth_key_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_from_auth_key_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_from_auth_key_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_from_auth_key_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_from_auth_key_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_key_value_from_auth_key_where_EQ_created_at(tcp_connection* conn, const datetime& w_created_at);
    static results select_key_value_from_auth_key_where_LT_created_at(tcp_connection* conn, const datetime& w_created_at);
    static results select_key_value_from_auth_key_where_LE_created_at(tcp_connection* conn, const datetime& w_created_at);
    static results select_key_value_from_auth_key_where_GT_created_at(tcp_connection* conn, const datetime& w_created_at);
    static results select_key_value_from_auth_key_where_GE_created_at(tcp_connection* conn, const datetime& w_created_at);
    static results select_key_value_from_auth_key_where_EQ_key_value(tcp_connection* conn, const string& w_key_value);
    static results select_key_value_from_auth_key_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_key_value_from_auth_key_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_key_value_from_auth_key_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_key_value_from_auth_key_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_key_value_from_auth_key_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_created_at_from_auth_key_where_EQ_created_at(tcp_connection* conn, const datetime& w_created_at);
    static results select_created_at_from_auth_key_where_LT_created_at(tcp_connection* conn, const datetime& w_created_at);
    static results select_created_at_from_auth_key_where_LE_created_at(tcp_connection* conn, const datetime& w_created_at);
    static results select_created_at_from_auth_key_where_GT_created_at(tcp_connection* conn, const datetime& w_created_at);
    static results select_created_at_from_auth_key_where_GE_created_at(tcp_connection* conn, const datetime& w_created_at);
    static results select_created_at_from_auth_key_where_EQ_key_value(tcp_connection* conn, const string& w_key_value);
    static results select_created_at_from_auth_key_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_created_at_from_auth_key_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_created_at_from_auth_key_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_created_at_from_auth_key_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_created_at_from_auth_key_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_key_value_from_auth_key_where_EQ_created_at(tcp_connection* conn, const datetime& w_created_at);
    static results select_id_N_key_value_from_auth_key_where_LT_created_at(tcp_connection* conn, const datetime& w_created_at);
    static results select_id_N_key_value_from_auth_key_where_LE_created_at(tcp_connection* conn, const datetime& w_created_at);
    static results select_id_N_key_value_from_auth_key_where_GT_created_at(tcp_connection* conn, const datetime& w_created_at);
    static results select_id_N_key_value_from_auth_key_where_GE_created_at(tcp_connection* conn, const datetime& w_created_at);
    static results select_id_N_key_value_from_auth_key_where_EQ_key_value(tcp_connection* conn, const string& w_key_value);
    static results select_id_N_key_value_from_auth_key_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_key_value_from_auth_key_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_key_value_from_auth_key_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_key_value_from_auth_key_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_key_value_from_auth_key_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_created_at_from_auth_key_where_EQ_created_at(tcp_connection* conn, const datetime& w_created_at);
    static results select_id_N_created_at_from_auth_key_where_LT_created_at(tcp_connection* conn, const datetime& w_created_at);
    static results select_id_N_created_at_from_auth_key_where_LE_created_at(tcp_connection* conn, const datetime& w_created_at);
    static results select_id_N_created_at_from_auth_key_where_GT_created_at(tcp_connection* conn, const datetime& w_created_at);
    static results select_id_N_created_at_from_auth_key_where_GE_created_at(tcp_connection* conn, const datetime& w_created_at);
    static results select_id_N_created_at_from_auth_key_where_EQ_key_value(tcp_connection* conn, const string& w_key_value);
    static results select_id_N_created_at_from_auth_key_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_created_at_from_auth_key_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_created_at_from_auth_key_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_created_at_from_auth_key_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_created_at_from_auth_key_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_key_value_N_created_at_from_auth_key_where_EQ_created_at(tcp_connection* conn, const datetime& w_created_at);
    static results select_key_value_N_created_at_from_auth_key_where_LT_created_at(tcp_connection* conn, const datetime& w_created_at);
    static results select_key_value_N_created_at_from_auth_key_where_LE_created_at(tcp_connection* conn, const datetime& w_created_at);
    static results select_key_value_N_created_at_from_auth_key_where_GT_created_at(tcp_connection* conn, const datetime& w_created_at);
    static results select_key_value_N_created_at_from_auth_key_where_GE_created_at(tcp_connection* conn, const datetime& w_created_at);
    static results select_key_value_N_created_at_from_auth_key_where_EQ_key_value(tcp_connection* conn, const string& w_key_value);
    static results select_key_value_N_created_at_from_auth_key_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_key_value_N_created_at_from_auth_key_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_key_value_N_created_at_from_auth_key_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_key_value_N_created_at_from_auth_key_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_key_value_N_created_at_from_auth_key_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_all_from_auth_key_where_EQ_created_at(tcp_connection* conn, const datetime& w_created_at);
    static results select_all_from_auth_key_where_LT_created_at(tcp_connection* conn, const datetime& w_created_at);
    static results select_all_from_auth_key_where_LE_created_at(tcp_connection* conn, const datetime& w_created_at);
    static results select_all_from_auth_key_where_GT_created_at(tcp_connection* conn, const datetime& w_created_at);
    static results select_all_from_auth_key_where_GE_created_at(tcp_connection* conn, const datetime& w_created_at);
    static results select_all_from_auth_key_where_EQ_key_value(tcp_connection* conn, const string& w_key_value);
    static results select_all_from_auth_key_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_all_from_auth_key_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_all_from_auth_key_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_all_from_auth_key_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_all_from_auth_key_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static int update_auth_key_set_id_where_EQ_created_at(tcp_connection* conn, const int32_t& s_id, const datetime& w_created_at);
    static int update_auth_key_set_id_where_LT_created_at(tcp_connection* conn, const int32_t& s_id, const datetime& w_created_at);
    static int update_auth_key_set_id_where_LE_created_at(tcp_connection* conn, const int32_t& s_id, const datetime& w_created_at);
    static int update_auth_key_set_id_where_GT_created_at(tcp_connection* conn, const int32_t& s_id, const datetime& w_created_at);
    static int update_auth_key_set_id_where_GE_created_at(tcp_connection* conn, const int32_t& s_id, const datetime& w_created_at);
    static int update_auth_key_set_id_where_EQ_key_value(tcp_connection* conn, const int32_t& s_id, const string& w_key_value);
    static int update_auth_key_set_id_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const int32_t& w_id);
    static int update_auth_key_set_id_where_LT_id(tcp_connection* conn, const int32_t& s_id, const int32_t& w_id);
    static int update_auth_key_set_id_where_LE_id(tcp_connection* conn, const int32_t& s_id, const int32_t& w_id);
    static int update_auth_key_set_id_where_GT_id(tcp_connection* conn, const int32_t& s_id, const int32_t& w_id);
    static int update_auth_key_set_id_where_GE_id(tcp_connection* conn, const int32_t& s_id, const int32_t& w_id);
    static int update_auth_key_set_key_value_where_EQ_created_at(tcp_connection* conn, const string& s_key_value, const datetime& w_created_at);
    static int update_auth_key_set_key_value_where_LT_created_at(tcp_connection* conn, const string& s_key_value, const datetime& w_created_at);
    static int update_auth_key_set_key_value_where_LE_created_at(tcp_connection* conn, const string& s_key_value, const datetime& w_created_at);
    static int update_auth_key_set_key_value_where_GT_created_at(tcp_connection* conn, const string& s_key_value, const datetime& w_created_at);
    static int update_auth_key_set_key_value_where_GE_created_at(tcp_connection* conn, const string& s_key_value, const datetime& w_created_at);
    static int update_auth_key_set_key_value_where_EQ_key_value(tcp_connection* conn, const string& s_key_value, const string& w_key_value);
    static int update_auth_key_set_key_value_where_EQ_id(tcp_connection* conn, const string& s_key_value, const int32_t& w_id);
    static int update_auth_key_set_key_value_where_LT_id(tcp_connection* conn, const string& s_key_value, const int32_t& w_id);
    static int update_auth_key_set_key_value_where_LE_id(tcp_connection* conn, const string& s_key_value, const int32_t& w_id);
    static int update_auth_key_set_key_value_where_GT_id(tcp_connection* conn, const string& s_key_value, const int32_t& w_id);
    static int update_auth_key_set_key_value_where_GE_id(tcp_connection* conn, const string& s_key_value, const int32_t& w_id);
    static int update_auth_key_set_created_at_where_EQ_created_at(tcp_connection* conn, const datetime& s_created_at, const datetime& w_created_at);
    static int update_auth_key_set_created_at_where_LT_created_at(tcp_connection* conn, const datetime& s_created_at, const datetime& w_created_at);
    static int update_auth_key_set_created_at_where_LE_created_at(tcp_connection* conn, const datetime& s_created_at, const datetime& w_created_at);
    static int update_auth_key_set_created_at_where_GT_created_at(tcp_connection* conn, const datetime& s_created_at, const datetime& w_created_at);
    static int update_auth_key_set_created_at_where_GE_created_at(tcp_connection* conn, const datetime& s_created_at, const datetime& w_created_at);
    static int update_auth_key_set_created_at_where_EQ_key_value(tcp_connection* conn, const datetime& s_created_at, const string& w_key_value);
    static int update_auth_key_set_created_at_where_EQ_id(tcp_connection* conn, const datetime& s_created_at, const int32_t& w_id);
    static int update_auth_key_set_created_at_where_LT_id(tcp_connection* conn, const datetime& s_created_at, const int32_t& w_id);
    static int update_auth_key_set_created_at_where_LE_id(tcp_connection* conn, const datetime& s_created_at, const int32_t& w_id);
    static int update_auth_key_set_created_at_where_GT_id(tcp_connection* conn, const datetime& s_created_at, const int32_t& w_id);
    static int update_auth_key_set_created_at_where_GE_id(tcp_connection* conn, const datetime& s_created_at, const int32_t& w_id);
    static int update_auth_key_set_id_N_key_value_where_EQ_created_at(tcp_connection* conn, const int32_t& s_id, const string& s_key_value, const datetime& w_created_at);
    static int update_auth_key_set_id_N_key_value_where_LT_created_at(tcp_connection* conn, const int32_t& s_id, const string& s_key_value, const datetime& w_created_at);
    static int update_auth_key_set_id_N_key_value_where_LE_created_at(tcp_connection* conn, const int32_t& s_id, const string& s_key_value, const datetime& w_created_at);
    static int update_auth_key_set_id_N_key_value_where_GT_created_at(tcp_connection* conn, const int32_t& s_id, const string& s_key_value, const datetime& w_created_at);
    static int update_auth_key_set_id_N_key_value_where_GE_created_at(tcp_connection* conn, const int32_t& s_id, const string& s_key_value, const datetime& w_created_at);
    static int update_auth_key_set_id_N_key_value_where_EQ_key_value(tcp_connection* conn, const int32_t& s_id, const string& s_key_value, const string& w_key_value);
    static int update_auth_key_set_id_N_key_value_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_key_value, const int32_t& w_id);
    static int update_auth_key_set_id_N_key_value_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_key_value, const int32_t& w_id);
    static int update_auth_key_set_id_N_key_value_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_key_value, const int32_t& w_id);
    static int update_auth_key_set_id_N_key_value_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_key_value, const int32_t& w_id);
    static int update_auth_key_set_id_N_key_value_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_key_value, const int32_t& w_id);
    static int update_auth_key_set_id_N_created_at_where_EQ_created_at(tcp_connection* conn, const int32_t& s_id, const datetime& s_created_at, const datetime& w_created_at);
    static int update_auth_key_set_id_N_created_at_where_LT_created_at(tcp_connection* conn, const int32_t& s_id, const datetime& s_created_at, const datetime& w_created_at);
    static int update_auth_key_set_id_N_created_at_where_LE_created_at(tcp_connection* conn, const int32_t& s_id, const datetime& s_created_at, const datetime& w_created_at);
    static int update_auth_key_set_id_N_created_at_where_GT_created_at(tcp_connection* conn, const int32_t& s_id, const datetime& s_created_at, const datetime& w_created_at);
    static int update_auth_key_set_id_N_created_at_where_GE_created_at(tcp_connection* conn, const int32_t& s_id, const datetime& s_created_at, const datetime& w_created_at);
    static int update_auth_key_set_id_N_created_at_where_EQ_key_value(tcp_connection* conn, const int32_t& s_id, const datetime& s_created_at, const string& w_key_value);
    static int update_auth_key_set_id_N_created_at_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const datetime& s_created_at, const int32_t& w_id);
    static int update_auth_key_set_id_N_created_at_where_LT_id(tcp_connection* conn, const int32_t& s_id, const datetime& s_created_at, const int32_t& w_id);
    static int update_auth_key_set_id_N_created_at_where_LE_id(tcp_connection* conn, const int32_t& s_id, const datetime& s_created_at, const int32_t& w_id);
    static int update_auth_key_set_id_N_created_at_where_GT_id(tcp_connection* conn, const int32_t& s_id, const datetime& s_created_at, const int32_t& w_id);
    static int update_auth_key_set_id_N_created_at_where_GE_id(tcp_connection* conn, const int32_t& s_id, const datetime& s_created_at, const int32_t& w_id);
    static int update_auth_key_set_key_value_N_created_at_where_EQ_created_at(tcp_connection* conn, const string& s_key_value, const datetime& s_created_at, const datetime& w_created_at);
    static int update_auth_key_set_key_value_N_created_at_where_LT_created_at(tcp_connection* conn, const string& s_key_value, const datetime& s_created_at, const datetime& w_created_at);
    static int update_auth_key_set_key_value_N_created_at_where_LE_created_at(tcp_connection* conn, const string& s_key_value, const datetime& s_created_at, const datetime& w_created_at);
    static int update_auth_key_set_key_value_N_created_at_where_GT_created_at(tcp_connection* conn, const string& s_key_value, const datetime& s_created_at, const datetime& w_created_at);
    static int update_auth_key_set_key_value_N_created_at_where_GE_created_at(tcp_connection* conn, const string& s_key_value, const datetime& s_created_at, const datetime& w_created_at);
    static int update_auth_key_set_key_value_N_created_at_where_EQ_key_value(tcp_connection* conn, const string& s_key_value, const datetime& s_created_at, const string& w_key_value);
    static int update_auth_key_set_key_value_N_created_at_where_EQ_id(tcp_connection* conn, const string& s_key_value, const datetime& s_created_at, const int32_t& w_id);
    static int update_auth_key_set_key_value_N_created_at_where_LT_id(tcp_connection* conn, const string& s_key_value, const datetime& s_created_at, const int32_t& w_id);
    static int update_auth_key_set_key_value_N_created_at_where_LE_id(tcp_connection* conn, const string& s_key_value, const datetime& s_created_at, const int32_t& w_id);
    static int update_auth_key_set_key_value_N_created_at_where_GT_id(tcp_connection* conn, const string& s_key_value, const datetime& s_created_at, const int32_t& w_id);
    static int update_auth_key_set_key_value_N_created_at_where_GE_id(tcp_connection* conn, const string& s_key_value, const datetime& s_created_at, const int32_t& w_id);
    static int update_auth_key_set_id_N_key_value_N_created_at_where_EQ_created_at(tcp_connection* conn, const int32_t& s_id, const string& s_key_value, const datetime& s_created_at, const datetime& w_created_at);
    static int update_auth_key_set_id_N_key_value_N_created_at_where_LT_created_at(tcp_connection* conn, const int32_t& s_id, const string& s_key_value, const datetime& s_created_at, const datetime& w_created_at);
    static int update_auth_key_set_id_N_key_value_N_created_at_where_LE_created_at(tcp_connection* conn, const int32_t& s_id, const string& s_key_value, const datetime& s_created_at, const datetime& w_created_at);
    static int update_auth_key_set_id_N_key_value_N_created_at_where_GT_created_at(tcp_connection* conn, const int32_t& s_id, const string& s_key_value, const datetime& s_created_at, const datetime& w_created_at);
    static int update_auth_key_set_id_N_key_value_N_created_at_where_GE_created_at(tcp_connection* conn, const int32_t& s_id, const string& s_key_value, const datetime& s_created_at, const datetime& w_created_at);
    static int update_auth_key_set_id_N_key_value_N_created_at_where_EQ_key_value(tcp_connection* conn, const int32_t& s_id, const string& s_key_value, const datetime& s_created_at, const string& w_key_value);
    static int update_auth_key_set_id_N_key_value_N_created_at_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_key_value, const datetime& s_created_at, const int32_t& w_id);
    static int update_auth_key_set_id_N_key_value_N_created_at_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_key_value, const datetime& s_created_at, const int32_t& w_id);
    static int update_auth_key_set_id_N_key_value_N_created_at_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_key_value, const datetime& s_created_at, const int32_t& w_id);
    static int update_auth_key_set_id_N_key_value_N_created_at_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_key_value, const datetime& s_created_at, const int32_t& w_id);
    static int update_auth_key_set_id_N_key_value_N_created_at_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_key_value, const datetime& s_created_at, const int32_t& w_id);
    static int delete_from_auth_key_where_EQ_created_at(tcp_connection* conn, const datetime& w_created_at);
    static int delete_from_auth_key_where_LT_created_at(tcp_connection* conn, const datetime& w_created_at);
    static int delete_from_auth_key_where_LE_created_at(tcp_connection* conn, const datetime& w_created_at);
    static int delete_from_auth_key_where_GT_created_at(tcp_connection* conn, const datetime& w_created_at);
    static int delete_from_auth_key_where_GE_created_at(tcp_connection* conn, const datetime& w_created_at);
    static int delete_from_auth_key_where_EQ_key_value(tcp_connection* conn, const string& w_key_value);
    static int delete_from_auth_key_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static int delete_from_auth_key_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static int delete_from_auth_key_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static int delete_from_auth_key_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static int delete_from_auth_key_where_GE_id(tcp_connection* conn, const int32_t& w_id);
};

// SP 호출 구현

inline int auth_key_orm::insert_into_auth_key_key_value(tcp_connection* conn, const string& new_key_value)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_1(?)");
        conn->execute(stmt.bind(new_key_value), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return -1;
    }

    return result.affected_rows();
}

    
inline results auth_key_orm::select_id_from_auth_key_where_EQ_created_at(tcp_connection* conn, const datetime& w_created_at)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_2(?)");
        conn->execute(stmt.bind(w_created_at), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results auth_key_orm::select_id_from_auth_key_where_LT_created_at(tcp_connection* conn, const datetime& w_created_at)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_3(?)");
        conn->execute(stmt.bind(w_created_at), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results auth_key_orm::select_id_from_auth_key_where_LE_created_at(tcp_connection* conn, const datetime& w_created_at)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_4(?)");
        conn->execute(stmt.bind(w_created_at), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results auth_key_orm::select_id_from_auth_key_where_GT_created_at(tcp_connection* conn, const datetime& w_created_at)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_5(?)");
        conn->execute(stmt.bind(w_created_at), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results auth_key_orm::select_id_from_auth_key_where_GE_created_at(tcp_connection* conn, const datetime& w_created_at)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_6(?)");
        conn->execute(stmt.bind(w_created_at), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results auth_key_orm::select_id_from_auth_key_where_EQ_key_value(tcp_connection* conn, const string& w_key_value)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_7(?)");
        conn->execute(stmt.bind(w_key_value), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results auth_key_orm::select_id_from_auth_key_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_8(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results auth_key_orm::select_id_from_auth_key_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_9(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results auth_key_orm::select_id_from_auth_key_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_10(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results auth_key_orm::select_id_from_auth_key_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_11(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results auth_key_orm::select_id_from_auth_key_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_12(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results auth_key_orm::select_key_value_from_auth_key_where_EQ_created_at(tcp_connection* conn, const datetime& w_created_at)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_13(?)");
        conn->execute(stmt.bind(w_created_at), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results auth_key_orm::select_key_value_from_auth_key_where_LT_created_at(tcp_connection* conn, const datetime& w_created_at)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_14(?)");
        conn->execute(stmt.bind(w_created_at), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results auth_key_orm::select_key_value_from_auth_key_where_LE_created_at(tcp_connection* conn, const datetime& w_created_at)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_15(?)");
        conn->execute(stmt.bind(w_created_at), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results auth_key_orm::select_key_value_from_auth_key_where_GT_created_at(tcp_connection* conn, const datetime& w_created_at)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_16(?)");
        conn->execute(stmt.bind(w_created_at), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results auth_key_orm::select_key_value_from_auth_key_where_GE_created_at(tcp_connection* conn, const datetime& w_created_at)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_17(?)");
        conn->execute(stmt.bind(w_created_at), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results auth_key_orm::select_key_value_from_auth_key_where_EQ_key_value(tcp_connection* conn, const string& w_key_value)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_18(?)");
        conn->execute(stmt.bind(w_key_value), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results auth_key_orm::select_key_value_from_auth_key_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_19(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results auth_key_orm::select_key_value_from_auth_key_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_20(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results auth_key_orm::select_key_value_from_auth_key_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_21(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results auth_key_orm::select_key_value_from_auth_key_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_22(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results auth_key_orm::select_key_value_from_auth_key_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_23(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results auth_key_orm::select_created_at_from_auth_key_where_EQ_created_at(tcp_connection* conn, const datetime& w_created_at)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_24(?)");
        conn->execute(stmt.bind(w_created_at), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results auth_key_orm::select_created_at_from_auth_key_where_LT_created_at(tcp_connection* conn, const datetime& w_created_at)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_25(?)");
        conn->execute(stmt.bind(w_created_at), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results auth_key_orm::select_created_at_from_auth_key_where_LE_created_at(tcp_connection* conn, const datetime& w_created_at)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_26(?)");
        conn->execute(stmt.bind(w_created_at), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results auth_key_orm::select_created_at_from_auth_key_where_GT_created_at(tcp_connection* conn, const datetime& w_created_at)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_27(?)");
        conn->execute(stmt.bind(w_created_at), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results auth_key_orm::select_created_at_from_auth_key_where_GE_created_at(tcp_connection* conn, const datetime& w_created_at)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_28(?)");
        conn->execute(stmt.bind(w_created_at), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results auth_key_orm::select_created_at_from_auth_key_where_EQ_key_value(tcp_connection* conn, const string& w_key_value)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_29(?)");
        conn->execute(stmt.bind(w_key_value), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results auth_key_orm::select_created_at_from_auth_key_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_30(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results auth_key_orm::select_created_at_from_auth_key_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_31(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results auth_key_orm::select_created_at_from_auth_key_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_32(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results auth_key_orm::select_created_at_from_auth_key_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_33(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results auth_key_orm::select_created_at_from_auth_key_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_34(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results auth_key_orm::select_id_N_key_value_from_auth_key_where_EQ_created_at(tcp_connection* conn, const datetime& w_created_at)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_35(?)");
        conn->execute(stmt.bind(w_created_at), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results auth_key_orm::select_id_N_key_value_from_auth_key_where_LT_created_at(tcp_connection* conn, const datetime& w_created_at)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_36(?)");
        conn->execute(stmt.bind(w_created_at), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results auth_key_orm::select_id_N_key_value_from_auth_key_where_LE_created_at(tcp_connection* conn, const datetime& w_created_at)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_37(?)");
        conn->execute(stmt.bind(w_created_at), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results auth_key_orm::select_id_N_key_value_from_auth_key_where_GT_created_at(tcp_connection* conn, const datetime& w_created_at)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_38(?)");
        conn->execute(stmt.bind(w_created_at), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results auth_key_orm::select_id_N_key_value_from_auth_key_where_GE_created_at(tcp_connection* conn, const datetime& w_created_at)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_39(?)");
        conn->execute(stmt.bind(w_created_at), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results auth_key_orm::select_id_N_key_value_from_auth_key_where_EQ_key_value(tcp_connection* conn, const string& w_key_value)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_40(?)");
        conn->execute(stmt.bind(w_key_value), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results auth_key_orm::select_id_N_key_value_from_auth_key_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_41(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results auth_key_orm::select_id_N_key_value_from_auth_key_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_42(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results auth_key_orm::select_id_N_key_value_from_auth_key_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_43(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results auth_key_orm::select_id_N_key_value_from_auth_key_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_44(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results auth_key_orm::select_id_N_key_value_from_auth_key_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_45(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results auth_key_orm::select_id_N_created_at_from_auth_key_where_EQ_created_at(tcp_connection* conn, const datetime& w_created_at)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_46(?)");
        conn->execute(stmt.bind(w_created_at), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results auth_key_orm::select_id_N_created_at_from_auth_key_where_LT_created_at(tcp_connection* conn, const datetime& w_created_at)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_47(?)");
        conn->execute(stmt.bind(w_created_at), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results auth_key_orm::select_id_N_created_at_from_auth_key_where_LE_created_at(tcp_connection* conn, const datetime& w_created_at)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_48(?)");
        conn->execute(stmt.bind(w_created_at), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results auth_key_orm::select_id_N_created_at_from_auth_key_where_GT_created_at(tcp_connection* conn, const datetime& w_created_at)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_49(?)");
        conn->execute(stmt.bind(w_created_at), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results auth_key_orm::select_id_N_created_at_from_auth_key_where_GE_created_at(tcp_connection* conn, const datetime& w_created_at)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_50(?)");
        conn->execute(stmt.bind(w_created_at), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results auth_key_orm::select_id_N_created_at_from_auth_key_where_EQ_key_value(tcp_connection* conn, const string& w_key_value)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_51(?)");
        conn->execute(stmt.bind(w_key_value), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results auth_key_orm::select_id_N_created_at_from_auth_key_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_52(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results auth_key_orm::select_id_N_created_at_from_auth_key_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_53(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results auth_key_orm::select_id_N_created_at_from_auth_key_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_54(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results auth_key_orm::select_id_N_created_at_from_auth_key_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_55(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results auth_key_orm::select_id_N_created_at_from_auth_key_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_56(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results auth_key_orm::select_key_value_N_created_at_from_auth_key_where_EQ_created_at(tcp_connection* conn, const datetime& w_created_at)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_57(?)");
        conn->execute(stmt.bind(w_created_at), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results auth_key_orm::select_key_value_N_created_at_from_auth_key_where_LT_created_at(tcp_connection* conn, const datetime& w_created_at)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_58(?)");
        conn->execute(stmt.bind(w_created_at), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results auth_key_orm::select_key_value_N_created_at_from_auth_key_where_LE_created_at(tcp_connection* conn, const datetime& w_created_at)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_59(?)");
        conn->execute(stmt.bind(w_created_at), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results auth_key_orm::select_key_value_N_created_at_from_auth_key_where_GT_created_at(tcp_connection* conn, const datetime& w_created_at)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_60(?)");
        conn->execute(stmt.bind(w_created_at), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results auth_key_orm::select_key_value_N_created_at_from_auth_key_where_GE_created_at(tcp_connection* conn, const datetime& w_created_at)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_61(?)");
        conn->execute(stmt.bind(w_created_at), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results auth_key_orm::select_key_value_N_created_at_from_auth_key_where_EQ_key_value(tcp_connection* conn, const string& w_key_value)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_62(?)");
        conn->execute(stmt.bind(w_key_value), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results auth_key_orm::select_key_value_N_created_at_from_auth_key_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_63(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results auth_key_orm::select_key_value_N_created_at_from_auth_key_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_64(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results auth_key_orm::select_key_value_N_created_at_from_auth_key_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_65(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results auth_key_orm::select_key_value_N_created_at_from_auth_key_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_66(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results auth_key_orm::select_key_value_N_created_at_from_auth_key_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_67(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results auth_key_orm::select_all_from_auth_key_where_EQ_created_at(tcp_connection* conn, const datetime& w_created_at)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_68(?)");
        conn->execute(stmt.bind(w_created_at), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results auth_key_orm::select_all_from_auth_key_where_LT_created_at(tcp_connection* conn, const datetime& w_created_at)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_69(?)");
        conn->execute(stmt.bind(w_created_at), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results auth_key_orm::select_all_from_auth_key_where_LE_created_at(tcp_connection* conn, const datetime& w_created_at)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_70(?)");
        conn->execute(stmt.bind(w_created_at), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results auth_key_orm::select_all_from_auth_key_where_GT_created_at(tcp_connection* conn, const datetime& w_created_at)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_71(?)");
        conn->execute(stmt.bind(w_created_at), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results auth_key_orm::select_all_from_auth_key_where_GE_created_at(tcp_connection* conn, const datetime& w_created_at)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_72(?)");
        conn->execute(stmt.bind(w_created_at), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results auth_key_orm::select_all_from_auth_key_where_EQ_key_value(tcp_connection* conn, const string& w_key_value)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_73(?)");
        conn->execute(stmt.bind(w_key_value), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results auth_key_orm::select_all_from_auth_key_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_74(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results auth_key_orm::select_all_from_auth_key_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_75(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results auth_key_orm::select_all_from_auth_key_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_76(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results auth_key_orm::select_all_from_auth_key_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_77(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results auth_key_orm::select_all_from_auth_key_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_78(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline int auth_key_orm::update_auth_key_set_id_where_EQ_created_at(tcp_connection* conn, const int32_t& s_id, const datetime& w_created_at)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_79(?, ?)");
        conn->execute(stmt.bind(s_id, w_created_at), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int auth_key_orm::update_auth_key_set_id_where_LT_created_at(tcp_connection* conn, const int32_t& s_id, const datetime& w_created_at)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_80(?, ?)");
        conn->execute(stmt.bind(s_id, w_created_at), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int auth_key_orm::update_auth_key_set_id_where_LE_created_at(tcp_connection* conn, const int32_t& s_id, const datetime& w_created_at)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_81(?, ?)");
        conn->execute(stmt.bind(s_id, w_created_at), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int auth_key_orm::update_auth_key_set_id_where_GT_created_at(tcp_connection* conn, const int32_t& s_id, const datetime& w_created_at)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_82(?, ?)");
        conn->execute(stmt.bind(s_id, w_created_at), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int auth_key_orm::update_auth_key_set_id_where_GE_created_at(tcp_connection* conn, const int32_t& s_id, const datetime& w_created_at)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_83(?, ?)");
        conn->execute(stmt.bind(s_id, w_created_at), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int auth_key_orm::update_auth_key_set_id_where_EQ_key_value(tcp_connection* conn, const int32_t& s_id, const string& w_key_value)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_84(?, ?)");
        conn->execute(stmt.bind(s_id, w_key_value), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int auth_key_orm::update_auth_key_set_id_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_85(?, ?)");
        conn->execute(stmt.bind(s_id, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int auth_key_orm::update_auth_key_set_id_where_LT_id(tcp_connection* conn, const int32_t& s_id, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_86(?, ?)");
        conn->execute(stmt.bind(s_id, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int auth_key_orm::update_auth_key_set_id_where_LE_id(tcp_connection* conn, const int32_t& s_id, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_87(?, ?)");
        conn->execute(stmt.bind(s_id, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int auth_key_orm::update_auth_key_set_id_where_GT_id(tcp_connection* conn, const int32_t& s_id, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_88(?, ?)");
        conn->execute(stmt.bind(s_id, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int auth_key_orm::update_auth_key_set_id_where_GE_id(tcp_connection* conn, const int32_t& s_id, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_89(?, ?)");
        conn->execute(stmt.bind(s_id, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int auth_key_orm::update_auth_key_set_key_value_where_EQ_created_at(tcp_connection* conn, const string& s_key_value, const datetime& w_created_at)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_90(?, ?)");
        conn->execute(stmt.bind(s_key_value, w_created_at), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int auth_key_orm::update_auth_key_set_key_value_where_LT_created_at(tcp_connection* conn, const string& s_key_value, const datetime& w_created_at)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_91(?, ?)");
        conn->execute(stmt.bind(s_key_value, w_created_at), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int auth_key_orm::update_auth_key_set_key_value_where_LE_created_at(tcp_connection* conn, const string& s_key_value, const datetime& w_created_at)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_92(?, ?)");
        conn->execute(stmt.bind(s_key_value, w_created_at), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int auth_key_orm::update_auth_key_set_key_value_where_GT_created_at(tcp_connection* conn, const string& s_key_value, const datetime& w_created_at)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_93(?, ?)");
        conn->execute(stmt.bind(s_key_value, w_created_at), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int auth_key_orm::update_auth_key_set_key_value_where_GE_created_at(tcp_connection* conn, const string& s_key_value, const datetime& w_created_at)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_94(?, ?)");
        conn->execute(stmt.bind(s_key_value, w_created_at), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int auth_key_orm::update_auth_key_set_key_value_where_EQ_key_value(tcp_connection* conn, const string& s_key_value, const string& w_key_value)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_95(?, ?)");
        conn->execute(stmt.bind(s_key_value, w_key_value), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int auth_key_orm::update_auth_key_set_key_value_where_EQ_id(tcp_connection* conn, const string& s_key_value, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_96(?, ?)");
        conn->execute(stmt.bind(s_key_value, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int auth_key_orm::update_auth_key_set_key_value_where_LT_id(tcp_connection* conn, const string& s_key_value, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_97(?, ?)");
        conn->execute(stmt.bind(s_key_value, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int auth_key_orm::update_auth_key_set_key_value_where_LE_id(tcp_connection* conn, const string& s_key_value, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_98(?, ?)");
        conn->execute(stmt.bind(s_key_value, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int auth_key_orm::update_auth_key_set_key_value_where_GT_id(tcp_connection* conn, const string& s_key_value, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_99(?, ?)");
        conn->execute(stmt.bind(s_key_value, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int auth_key_orm::update_auth_key_set_key_value_where_GE_id(tcp_connection* conn, const string& s_key_value, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_100(?, ?)");
        conn->execute(stmt.bind(s_key_value, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int auth_key_orm::update_auth_key_set_created_at_where_EQ_created_at(tcp_connection* conn, const datetime& s_created_at, const datetime& w_created_at)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_101(?, ?)");
        conn->execute(stmt.bind(s_created_at, w_created_at), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int auth_key_orm::update_auth_key_set_created_at_where_LT_created_at(tcp_connection* conn, const datetime& s_created_at, const datetime& w_created_at)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_102(?, ?)");
        conn->execute(stmt.bind(s_created_at, w_created_at), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int auth_key_orm::update_auth_key_set_created_at_where_LE_created_at(tcp_connection* conn, const datetime& s_created_at, const datetime& w_created_at)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_103(?, ?)");
        conn->execute(stmt.bind(s_created_at, w_created_at), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int auth_key_orm::update_auth_key_set_created_at_where_GT_created_at(tcp_connection* conn, const datetime& s_created_at, const datetime& w_created_at)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_104(?, ?)");
        conn->execute(stmt.bind(s_created_at, w_created_at), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int auth_key_orm::update_auth_key_set_created_at_where_GE_created_at(tcp_connection* conn, const datetime& s_created_at, const datetime& w_created_at)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_105(?, ?)");
        conn->execute(stmt.bind(s_created_at, w_created_at), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int auth_key_orm::update_auth_key_set_created_at_where_EQ_key_value(tcp_connection* conn, const datetime& s_created_at, const string& w_key_value)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_106(?, ?)");
        conn->execute(stmt.bind(s_created_at, w_key_value), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int auth_key_orm::update_auth_key_set_created_at_where_EQ_id(tcp_connection* conn, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_107(?, ?)");
        conn->execute(stmt.bind(s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int auth_key_orm::update_auth_key_set_created_at_where_LT_id(tcp_connection* conn, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_108(?, ?)");
        conn->execute(stmt.bind(s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int auth_key_orm::update_auth_key_set_created_at_where_LE_id(tcp_connection* conn, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_109(?, ?)");
        conn->execute(stmt.bind(s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int auth_key_orm::update_auth_key_set_created_at_where_GT_id(tcp_connection* conn, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_110(?, ?)");
        conn->execute(stmt.bind(s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int auth_key_orm::update_auth_key_set_created_at_where_GE_id(tcp_connection* conn, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_111(?, ?)");
        conn->execute(stmt.bind(s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int auth_key_orm::update_auth_key_set_id_N_key_value_where_EQ_created_at(tcp_connection* conn, const int32_t& s_id, const string& s_key_value, const datetime& w_created_at)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_112(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_key_value, w_created_at), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int auth_key_orm::update_auth_key_set_id_N_key_value_where_LT_created_at(tcp_connection* conn, const int32_t& s_id, const string& s_key_value, const datetime& w_created_at)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_113(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_key_value, w_created_at), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int auth_key_orm::update_auth_key_set_id_N_key_value_where_LE_created_at(tcp_connection* conn, const int32_t& s_id, const string& s_key_value, const datetime& w_created_at)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_114(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_key_value, w_created_at), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int auth_key_orm::update_auth_key_set_id_N_key_value_where_GT_created_at(tcp_connection* conn, const int32_t& s_id, const string& s_key_value, const datetime& w_created_at)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_115(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_key_value, w_created_at), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int auth_key_orm::update_auth_key_set_id_N_key_value_where_GE_created_at(tcp_connection* conn, const int32_t& s_id, const string& s_key_value, const datetime& w_created_at)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_116(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_key_value, w_created_at), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int auth_key_orm::update_auth_key_set_id_N_key_value_where_EQ_key_value(tcp_connection* conn, const int32_t& s_id, const string& s_key_value, const string& w_key_value)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_117(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_key_value, w_key_value), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int auth_key_orm::update_auth_key_set_id_N_key_value_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_key_value, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_118(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_key_value, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int auth_key_orm::update_auth_key_set_id_N_key_value_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_key_value, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_119(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_key_value, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int auth_key_orm::update_auth_key_set_id_N_key_value_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_key_value, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_120(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_key_value, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int auth_key_orm::update_auth_key_set_id_N_key_value_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_key_value, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_121(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_key_value, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int auth_key_orm::update_auth_key_set_id_N_key_value_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_key_value, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_122(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_key_value, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int auth_key_orm::update_auth_key_set_id_N_created_at_where_EQ_created_at(tcp_connection* conn, const int32_t& s_id, const datetime& s_created_at, const datetime& w_created_at)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_123(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_created_at, w_created_at), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int auth_key_orm::update_auth_key_set_id_N_created_at_where_LT_created_at(tcp_connection* conn, const int32_t& s_id, const datetime& s_created_at, const datetime& w_created_at)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_124(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_created_at, w_created_at), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int auth_key_orm::update_auth_key_set_id_N_created_at_where_LE_created_at(tcp_connection* conn, const int32_t& s_id, const datetime& s_created_at, const datetime& w_created_at)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_125(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_created_at, w_created_at), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int auth_key_orm::update_auth_key_set_id_N_created_at_where_GT_created_at(tcp_connection* conn, const int32_t& s_id, const datetime& s_created_at, const datetime& w_created_at)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_126(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_created_at, w_created_at), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int auth_key_orm::update_auth_key_set_id_N_created_at_where_GE_created_at(tcp_connection* conn, const int32_t& s_id, const datetime& s_created_at, const datetime& w_created_at)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_127(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_created_at, w_created_at), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int auth_key_orm::update_auth_key_set_id_N_created_at_where_EQ_key_value(tcp_connection* conn, const int32_t& s_id, const datetime& s_created_at, const string& w_key_value)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_128(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_created_at, w_key_value), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int auth_key_orm::update_auth_key_set_id_N_created_at_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_129(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int auth_key_orm::update_auth_key_set_id_N_created_at_where_LT_id(tcp_connection* conn, const int32_t& s_id, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_130(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int auth_key_orm::update_auth_key_set_id_N_created_at_where_LE_id(tcp_connection* conn, const int32_t& s_id, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_131(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int auth_key_orm::update_auth_key_set_id_N_created_at_where_GT_id(tcp_connection* conn, const int32_t& s_id, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_132(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int auth_key_orm::update_auth_key_set_id_N_created_at_where_GE_id(tcp_connection* conn, const int32_t& s_id, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_133(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int auth_key_orm::update_auth_key_set_key_value_N_created_at_where_EQ_created_at(tcp_connection* conn, const string& s_key_value, const datetime& s_created_at, const datetime& w_created_at)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_134(?, ?, ?)");
        conn->execute(stmt.bind(s_key_value, s_created_at, w_created_at), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int auth_key_orm::update_auth_key_set_key_value_N_created_at_where_LT_created_at(tcp_connection* conn, const string& s_key_value, const datetime& s_created_at, const datetime& w_created_at)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_135(?, ?, ?)");
        conn->execute(stmt.bind(s_key_value, s_created_at, w_created_at), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int auth_key_orm::update_auth_key_set_key_value_N_created_at_where_LE_created_at(tcp_connection* conn, const string& s_key_value, const datetime& s_created_at, const datetime& w_created_at)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_136(?, ?, ?)");
        conn->execute(stmt.bind(s_key_value, s_created_at, w_created_at), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int auth_key_orm::update_auth_key_set_key_value_N_created_at_where_GT_created_at(tcp_connection* conn, const string& s_key_value, const datetime& s_created_at, const datetime& w_created_at)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_137(?, ?, ?)");
        conn->execute(stmt.bind(s_key_value, s_created_at, w_created_at), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int auth_key_orm::update_auth_key_set_key_value_N_created_at_where_GE_created_at(tcp_connection* conn, const string& s_key_value, const datetime& s_created_at, const datetime& w_created_at)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_138(?, ?, ?)");
        conn->execute(stmt.bind(s_key_value, s_created_at, w_created_at), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int auth_key_orm::update_auth_key_set_key_value_N_created_at_where_EQ_key_value(tcp_connection* conn, const string& s_key_value, const datetime& s_created_at, const string& w_key_value)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_139(?, ?, ?)");
        conn->execute(stmt.bind(s_key_value, s_created_at, w_key_value), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int auth_key_orm::update_auth_key_set_key_value_N_created_at_where_EQ_id(tcp_connection* conn, const string& s_key_value, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_140(?, ?, ?)");
        conn->execute(stmt.bind(s_key_value, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int auth_key_orm::update_auth_key_set_key_value_N_created_at_where_LT_id(tcp_connection* conn, const string& s_key_value, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_141(?, ?, ?)");
        conn->execute(stmt.bind(s_key_value, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int auth_key_orm::update_auth_key_set_key_value_N_created_at_where_LE_id(tcp_connection* conn, const string& s_key_value, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_142(?, ?, ?)");
        conn->execute(stmt.bind(s_key_value, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int auth_key_orm::update_auth_key_set_key_value_N_created_at_where_GT_id(tcp_connection* conn, const string& s_key_value, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_143(?, ?, ?)");
        conn->execute(stmt.bind(s_key_value, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int auth_key_orm::update_auth_key_set_key_value_N_created_at_where_GE_id(tcp_connection* conn, const string& s_key_value, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_144(?, ?, ?)");
        conn->execute(stmt.bind(s_key_value, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int auth_key_orm::update_auth_key_set_id_N_key_value_N_created_at_where_EQ_created_at(tcp_connection* conn, const int32_t& s_id, const string& s_key_value, const datetime& s_created_at, const datetime& w_created_at)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_145(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_key_value, s_created_at, w_created_at), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int auth_key_orm::update_auth_key_set_id_N_key_value_N_created_at_where_LT_created_at(tcp_connection* conn, const int32_t& s_id, const string& s_key_value, const datetime& s_created_at, const datetime& w_created_at)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_146(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_key_value, s_created_at, w_created_at), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int auth_key_orm::update_auth_key_set_id_N_key_value_N_created_at_where_LE_created_at(tcp_connection* conn, const int32_t& s_id, const string& s_key_value, const datetime& s_created_at, const datetime& w_created_at)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_147(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_key_value, s_created_at, w_created_at), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int auth_key_orm::update_auth_key_set_id_N_key_value_N_created_at_where_GT_created_at(tcp_connection* conn, const int32_t& s_id, const string& s_key_value, const datetime& s_created_at, const datetime& w_created_at)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_148(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_key_value, s_created_at, w_created_at), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int auth_key_orm::update_auth_key_set_id_N_key_value_N_created_at_where_GE_created_at(tcp_connection* conn, const int32_t& s_id, const string& s_key_value, const datetime& s_created_at, const datetime& w_created_at)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_149(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_key_value, s_created_at, w_created_at), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int auth_key_orm::update_auth_key_set_id_N_key_value_N_created_at_where_EQ_key_value(tcp_connection* conn, const int32_t& s_id, const string& s_key_value, const datetime& s_created_at, const string& w_key_value)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_150(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_key_value, s_created_at, w_key_value), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int auth_key_orm::update_auth_key_set_id_N_key_value_N_created_at_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_key_value, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_151(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_key_value, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int auth_key_orm::update_auth_key_set_id_N_key_value_N_created_at_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_key_value, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_152(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_key_value, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int auth_key_orm::update_auth_key_set_id_N_key_value_N_created_at_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_key_value, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_153(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_key_value, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int auth_key_orm::update_auth_key_set_id_N_key_value_N_created_at_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_key_value, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_154(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_key_value, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int auth_key_orm::update_auth_key_set_id_N_key_value_N_created_at_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_key_value, const datetime& s_created_at, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_155(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_key_value, s_created_at, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int auth_key_orm::delete_from_auth_key_where_EQ_created_at(tcp_connection* conn, const datetime& w_created_at)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_156(?)");
        conn->execute(stmt.bind(w_created_at), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int auth_key_orm::delete_from_auth_key_where_LT_created_at(tcp_connection* conn, const datetime& w_created_at)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_157(?)");
        conn->execute(stmt.bind(w_created_at), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int auth_key_orm::delete_from_auth_key_where_LE_created_at(tcp_connection* conn, const datetime& w_created_at)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_158(?)");
        conn->execute(stmt.bind(w_created_at), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int auth_key_orm::delete_from_auth_key_where_GT_created_at(tcp_connection* conn, const datetime& w_created_at)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_159(?)");
        conn->execute(stmt.bind(w_created_at), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int auth_key_orm::delete_from_auth_key_where_GE_created_at(tcp_connection* conn, const datetime& w_created_at)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_160(?)");
        conn->execute(stmt.bind(w_created_at), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int auth_key_orm::delete_from_auth_key_where_EQ_key_value(tcp_connection* conn, const string& w_key_value)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_161(?)");
        conn->execute(stmt.bind(w_key_value), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int auth_key_orm::delete_from_auth_key_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_162(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int auth_key_orm::delete_from_auth_key_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_163(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int auth_key_orm::delete_from_auth_key_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_164(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int auth_key_orm::delete_from_auth_key_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_165(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int auth_key_orm::delete_from_auth_key_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_166(?)");
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

DISABLE_WARNING_POP
