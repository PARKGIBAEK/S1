
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

struct item_accessory
{
    int32_t id; // int
    string item_name; // varchar(64)
    string item_description; // text(65535)
    int32_t item_effect; // int
};

BOOST_DESCRIBE_STRUCT(item_accessory, (), (id, item_name, item_description, item_effect));

class item_accessory_orm
{
public:
    // SP 호출 선언
    static int insert_into_item_accessory_id_N_item_name(tcp_connection* conn, const int32_t& new_id, const string& new_item_name);
    static int insert_into_item_accessory_id_N_item_name_N_item_description(tcp_connection* conn, const int32_t& new_id, const string& new_item_name, const string& new_item_description);
    static int insert_into_item_accessory_id_N_item_name_N_item_effect(tcp_connection* conn, const int32_t& new_id, const string& new_item_name, const int32_t& new_item_effect);
    static int insert_into_item_accessory_id_N_item_name_N_item_description_N_item_effect(tcp_connection* conn, const int32_t& new_id, const string& new_item_name, const string& new_item_description, const int32_t& new_item_effect);
    static results select_id_from_item_accessory_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_from_item_accessory_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_from_item_accessory_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_from_item_accessory_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_from_item_accessory_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_from_item_accessory_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_from_item_accessory_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_from_item_accessory_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_from_item_accessory_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_from_item_accessory_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_description_from_item_accessory_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_description_from_item_accessory_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_description_from_item_accessory_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_description_from_item_accessory_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_description_from_item_accessory_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_effect_from_item_accessory_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_effect_from_item_accessory_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_effect_from_item_accessory_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_effect_from_item_accessory_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_effect_from_item_accessory_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_name_from_item_accessory_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_name_from_item_accessory_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_name_from_item_accessory_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_name_from_item_accessory_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_name_from_item_accessory_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_description_from_item_accessory_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_description_from_item_accessory_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_description_from_item_accessory_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_description_from_item_accessory_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_description_from_item_accessory_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_effect_from_item_accessory_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_effect_from_item_accessory_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_effect_from_item_accessory_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_effect_from_item_accessory_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_effect_from_item_accessory_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_N_item_description_from_item_accessory_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_N_item_description_from_item_accessory_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_N_item_description_from_item_accessory_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_N_item_description_from_item_accessory_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_N_item_description_from_item_accessory_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_N_item_effect_from_item_accessory_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_N_item_effect_from_item_accessory_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_N_item_effect_from_item_accessory_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_N_item_effect_from_item_accessory_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_N_item_effect_from_item_accessory_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_description_N_item_effect_from_item_accessory_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_description_N_item_effect_from_item_accessory_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_description_N_item_effect_from_item_accessory_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_description_N_item_effect_from_item_accessory_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_description_N_item_effect_from_item_accessory_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_name_N_item_description_from_item_accessory_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_name_N_item_description_from_item_accessory_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_name_N_item_description_from_item_accessory_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_name_N_item_description_from_item_accessory_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_name_N_item_description_from_item_accessory_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_name_N_item_effect_from_item_accessory_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_name_N_item_effect_from_item_accessory_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_name_N_item_effect_from_item_accessory_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_name_N_item_effect_from_item_accessory_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_name_N_item_effect_from_item_accessory_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_description_N_item_effect_from_item_accessory_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_description_N_item_effect_from_item_accessory_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_description_N_item_effect_from_item_accessory_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_description_N_item_effect_from_item_accessory_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_description_N_item_effect_from_item_accessory_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_N_item_description_N_item_effect_from_item_accessory_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_N_item_description_N_item_effect_from_item_accessory_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_N_item_description_N_item_effect_from_item_accessory_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_N_item_description_N_item_effect_from_item_accessory_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_N_item_description_N_item_effect_from_item_accessory_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_all_from_item_accessory_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_all_from_item_accessory_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_all_from_item_accessory_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_all_from_item_accessory_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_all_from_item_accessory_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static int update_item_accessory_set_id_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const int32_t& w_id);
    static int update_item_accessory_set_id_where_LT_id(tcp_connection* conn, const int32_t& s_id, const int32_t& w_id);
    static int update_item_accessory_set_id_where_LE_id(tcp_connection* conn, const int32_t& s_id, const int32_t& w_id);
    static int update_item_accessory_set_id_where_GT_id(tcp_connection* conn, const int32_t& s_id, const int32_t& w_id);
    static int update_item_accessory_set_id_where_GE_id(tcp_connection* conn, const int32_t& s_id, const int32_t& w_id);
    static int update_item_accessory_set_item_name_where_EQ_id(tcp_connection* conn, const string& s_item_name, const int32_t& w_id);
    static int update_item_accessory_set_item_name_where_LT_id(tcp_connection* conn, const string& s_item_name, const int32_t& w_id);
    static int update_item_accessory_set_item_name_where_LE_id(tcp_connection* conn, const string& s_item_name, const int32_t& w_id);
    static int update_item_accessory_set_item_name_where_GT_id(tcp_connection* conn, const string& s_item_name, const int32_t& w_id);
    static int update_item_accessory_set_item_name_where_GE_id(tcp_connection* conn, const string& s_item_name, const int32_t& w_id);
    static int update_item_accessory_set_item_description_where_EQ_id(tcp_connection* conn, const string& s_item_description, const int32_t& w_id);
    static int update_item_accessory_set_item_description_where_LT_id(tcp_connection* conn, const string& s_item_description, const int32_t& w_id);
    static int update_item_accessory_set_item_description_where_LE_id(tcp_connection* conn, const string& s_item_description, const int32_t& w_id);
    static int update_item_accessory_set_item_description_where_GT_id(tcp_connection* conn, const string& s_item_description, const int32_t& w_id);
    static int update_item_accessory_set_item_description_where_GE_id(tcp_connection* conn, const string& s_item_description, const int32_t& w_id);
    static int update_item_accessory_set_item_effect_where_EQ_id(tcp_connection* conn, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_accessory_set_item_effect_where_LT_id(tcp_connection* conn, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_accessory_set_item_effect_where_LE_id(tcp_connection* conn, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_accessory_set_item_effect_where_GT_id(tcp_connection* conn, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_accessory_set_item_effect_where_GE_id(tcp_connection* conn, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_accessory_set_id_N_item_name_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& w_id);
    static int update_item_accessory_set_id_N_item_name_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& w_id);
    static int update_item_accessory_set_id_N_item_name_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& w_id);
    static int update_item_accessory_set_id_N_item_name_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& w_id);
    static int update_item_accessory_set_id_N_item_name_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& w_id);
    static int update_item_accessory_set_id_N_item_description_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& w_id);
    static int update_item_accessory_set_id_N_item_description_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& w_id);
    static int update_item_accessory_set_id_N_item_description_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& w_id);
    static int update_item_accessory_set_id_N_item_description_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& w_id);
    static int update_item_accessory_set_id_N_item_description_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& w_id);
    static int update_item_accessory_set_id_N_item_effect_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_accessory_set_id_N_item_effect_where_LT_id(tcp_connection* conn, const int32_t& s_id, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_accessory_set_id_N_item_effect_where_LE_id(tcp_connection* conn, const int32_t& s_id, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_accessory_set_id_N_item_effect_where_GT_id(tcp_connection* conn, const int32_t& s_id, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_accessory_set_id_N_item_effect_where_GE_id(tcp_connection* conn, const int32_t& s_id, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_accessory_set_item_name_N_item_description_where_EQ_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& w_id);
    static int update_item_accessory_set_item_name_N_item_description_where_LT_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& w_id);
    static int update_item_accessory_set_item_name_N_item_description_where_LE_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& w_id);
    static int update_item_accessory_set_item_name_N_item_description_where_GT_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& w_id);
    static int update_item_accessory_set_item_name_N_item_description_where_GE_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& w_id);
    static int update_item_accessory_set_item_name_N_item_effect_where_EQ_id(tcp_connection* conn, const string& s_item_name, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_accessory_set_item_name_N_item_effect_where_LT_id(tcp_connection* conn, const string& s_item_name, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_accessory_set_item_name_N_item_effect_where_LE_id(tcp_connection* conn, const string& s_item_name, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_accessory_set_item_name_N_item_effect_where_GT_id(tcp_connection* conn, const string& s_item_name, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_accessory_set_item_name_N_item_effect_where_GE_id(tcp_connection* conn, const string& s_item_name, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_accessory_set_item_description_N_item_effect_where_EQ_id(tcp_connection* conn, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_accessory_set_item_description_N_item_effect_where_LT_id(tcp_connection* conn, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_accessory_set_item_description_N_item_effect_where_LE_id(tcp_connection* conn, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_accessory_set_item_description_N_item_effect_where_GT_id(tcp_connection* conn, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_accessory_set_item_description_N_item_effect_where_GE_id(tcp_connection* conn, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_accessory_set_id_N_item_name_N_item_description_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& w_id);
    static int update_item_accessory_set_id_N_item_name_N_item_description_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& w_id);
    static int update_item_accessory_set_id_N_item_name_N_item_description_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& w_id);
    static int update_item_accessory_set_id_N_item_name_N_item_description_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& w_id);
    static int update_item_accessory_set_id_N_item_name_N_item_description_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& w_id);
    static int update_item_accessory_set_id_N_item_name_N_item_effect_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_accessory_set_id_N_item_name_N_item_effect_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_accessory_set_id_N_item_name_N_item_effect_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_accessory_set_id_N_item_name_N_item_effect_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_accessory_set_id_N_item_name_N_item_effect_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_accessory_set_id_N_item_description_N_item_effect_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_accessory_set_id_N_item_description_N_item_effect_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_accessory_set_id_N_item_description_N_item_effect_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_accessory_set_id_N_item_description_N_item_effect_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_accessory_set_id_N_item_description_N_item_effect_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_accessory_set_item_name_N_item_description_N_item_effect_where_EQ_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_accessory_set_item_name_N_item_description_N_item_effect_where_LT_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_accessory_set_item_name_N_item_description_N_item_effect_where_LE_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_accessory_set_item_name_N_item_description_N_item_effect_where_GT_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_accessory_set_item_name_N_item_description_N_item_effect_where_GE_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_accessory_set_id_N_item_name_N_item_description_N_item_effect_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_accessory_set_id_N_item_name_N_item_description_N_item_effect_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_accessory_set_id_N_item_name_N_item_description_N_item_effect_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_accessory_set_id_N_item_name_N_item_description_N_item_effect_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_accessory_set_id_N_item_name_N_item_description_N_item_effect_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id);
    static int delete_from_item_accessory_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static int delete_from_item_accessory_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static int delete_from_item_accessory_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static int delete_from_item_accessory_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static int delete_from_item_accessory_where_GE_id(tcp_connection* conn, const int32_t& w_id);
};

// SP 호출 구현

inline int item_accessory_orm::insert_into_item_accessory_id_N_item_name(tcp_connection* conn, const int32_t& new_id, const string& new_item_name)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_167(?, ?)");
        conn->execute(stmt.bind(new_id, new_item_name), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return -1;
    }

    return result.affected_rows();
}

    
inline int item_accessory_orm::insert_into_item_accessory_id_N_item_name_N_item_description(tcp_connection* conn, const int32_t& new_id, const string& new_item_name, const string& new_item_description)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_168(?, ?, ?)");
        conn->execute(stmt.bind(new_id, new_item_name, new_item_description), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return -1;
    }

    return result.affected_rows();
}

    
inline int item_accessory_orm::insert_into_item_accessory_id_N_item_name_N_item_effect(tcp_connection* conn, const int32_t& new_id, const string& new_item_name, const int32_t& new_item_effect)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_169(?, ?, ?)");
        conn->execute(stmt.bind(new_id, new_item_name, new_item_effect), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return -1;
    }

    return result.affected_rows();
}

    
inline int item_accessory_orm::insert_into_item_accessory_id_N_item_name_N_item_description_N_item_effect(tcp_connection* conn, const int32_t& new_id, const string& new_item_name, const string& new_item_description, const int32_t& new_item_effect)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_170(?, ?, ?, ?)");
        conn->execute(stmt.bind(new_id, new_item_name, new_item_description, new_item_effect), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return -1;
    }

    return result.affected_rows();
}

    
inline results item_accessory_orm::select_id_from_item_accessory_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_171(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_accessory_orm::select_id_from_item_accessory_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_172(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_accessory_orm::select_id_from_item_accessory_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_173(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_accessory_orm::select_id_from_item_accessory_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_174(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_accessory_orm::select_id_from_item_accessory_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_175(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_accessory_orm::select_item_name_from_item_accessory_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_176(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_accessory_orm::select_item_name_from_item_accessory_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_177(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_accessory_orm::select_item_name_from_item_accessory_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_178(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_accessory_orm::select_item_name_from_item_accessory_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_179(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_accessory_orm::select_item_name_from_item_accessory_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_180(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_accessory_orm::select_item_description_from_item_accessory_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_181(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_accessory_orm::select_item_description_from_item_accessory_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_182(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_accessory_orm::select_item_description_from_item_accessory_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_183(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_accessory_orm::select_item_description_from_item_accessory_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_184(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_accessory_orm::select_item_description_from_item_accessory_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_185(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_accessory_orm::select_item_effect_from_item_accessory_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_186(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_accessory_orm::select_item_effect_from_item_accessory_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_187(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_accessory_orm::select_item_effect_from_item_accessory_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_188(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_accessory_orm::select_item_effect_from_item_accessory_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_189(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_accessory_orm::select_item_effect_from_item_accessory_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_190(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_accessory_orm::select_id_N_item_name_from_item_accessory_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_191(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_accessory_orm::select_id_N_item_name_from_item_accessory_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_192(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_accessory_orm::select_id_N_item_name_from_item_accessory_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_193(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_accessory_orm::select_id_N_item_name_from_item_accessory_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_194(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_accessory_orm::select_id_N_item_name_from_item_accessory_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_195(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_accessory_orm::select_id_N_item_description_from_item_accessory_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_196(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_accessory_orm::select_id_N_item_description_from_item_accessory_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_197(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_accessory_orm::select_id_N_item_description_from_item_accessory_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_198(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_accessory_orm::select_id_N_item_description_from_item_accessory_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_199(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_accessory_orm::select_id_N_item_description_from_item_accessory_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_200(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_accessory_orm::select_id_N_item_effect_from_item_accessory_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_201(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_accessory_orm::select_id_N_item_effect_from_item_accessory_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_202(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_accessory_orm::select_id_N_item_effect_from_item_accessory_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_203(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_accessory_orm::select_id_N_item_effect_from_item_accessory_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_204(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_accessory_orm::select_id_N_item_effect_from_item_accessory_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_205(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_accessory_orm::select_item_name_N_item_description_from_item_accessory_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_206(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_accessory_orm::select_item_name_N_item_description_from_item_accessory_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_207(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_accessory_orm::select_item_name_N_item_description_from_item_accessory_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_208(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_accessory_orm::select_item_name_N_item_description_from_item_accessory_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_209(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_accessory_orm::select_item_name_N_item_description_from_item_accessory_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_210(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_accessory_orm::select_item_name_N_item_effect_from_item_accessory_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_211(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_accessory_orm::select_item_name_N_item_effect_from_item_accessory_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_212(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_accessory_orm::select_item_name_N_item_effect_from_item_accessory_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_213(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_accessory_orm::select_item_name_N_item_effect_from_item_accessory_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_214(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_accessory_orm::select_item_name_N_item_effect_from_item_accessory_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_215(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_accessory_orm::select_item_description_N_item_effect_from_item_accessory_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_216(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_accessory_orm::select_item_description_N_item_effect_from_item_accessory_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_217(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_accessory_orm::select_item_description_N_item_effect_from_item_accessory_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_218(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_accessory_orm::select_item_description_N_item_effect_from_item_accessory_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_219(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_accessory_orm::select_item_description_N_item_effect_from_item_accessory_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_220(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_accessory_orm::select_id_N_item_name_N_item_description_from_item_accessory_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_221(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_accessory_orm::select_id_N_item_name_N_item_description_from_item_accessory_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_222(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_accessory_orm::select_id_N_item_name_N_item_description_from_item_accessory_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_223(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_accessory_orm::select_id_N_item_name_N_item_description_from_item_accessory_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_224(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_accessory_orm::select_id_N_item_name_N_item_description_from_item_accessory_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_225(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_accessory_orm::select_id_N_item_name_N_item_effect_from_item_accessory_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_226(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_accessory_orm::select_id_N_item_name_N_item_effect_from_item_accessory_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_227(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_accessory_orm::select_id_N_item_name_N_item_effect_from_item_accessory_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_228(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_accessory_orm::select_id_N_item_name_N_item_effect_from_item_accessory_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_229(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_accessory_orm::select_id_N_item_name_N_item_effect_from_item_accessory_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_230(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_accessory_orm::select_id_N_item_description_N_item_effect_from_item_accessory_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_231(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_accessory_orm::select_id_N_item_description_N_item_effect_from_item_accessory_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_232(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_accessory_orm::select_id_N_item_description_N_item_effect_from_item_accessory_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_233(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_accessory_orm::select_id_N_item_description_N_item_effect_from_item_accessory_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_234(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_accessory_orm::select_id_N_item_description_N_item_effect_from_item_accessory_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_235(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_accessory_orm::select_item_name_N_item_description_N_item_effect_from_item_accessory_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_236(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_accessory_orm::select_item_name_N_item_description_N_item_effect_from_item_accessory_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_237(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_accessory_orm::select_item_name_N_item_description_N_item_effect_from_item_accessory_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_238(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_accessory_orm::select_item_name_N_item_description_N_item_effect_from_item_accessory_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_239(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_accessory_orm::select_item_name_N_item_description_N_item_effect_from_item_accessory_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_240(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_accessory_orm::select_all_from_item_accessory_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_241(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_accessory_orm::select_all_from_item_accessory_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_242(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_accessory_orm::select_all_from_item_accessory_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_243(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_accessory_orm::select_all_from_item_accessory_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_244(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_accessory_orm::select_all_from_item_accessory_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_245(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline int item_accessory_orm::update_item_accessory_set_id_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_246(?, ?)");
        conn->execute(stmt.bind(s_id, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_accessory_orm::update_item_accessory_set_id_where_LT_id(tcp_connection* conn, const int32_t& s_id, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_247(?, ?)");
        conn->execute(stmt.bind(s_id, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_accessory_orm::update_item_accessory_set_id_where_LE_id(tcp_connection* conn, const int32_t& s_id, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_248(?, ?)");
        conn->execute(stmt.bind(s_id, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_accessory_orm::update_item_accessory_set_id_where_GT_id(tcp_connection* conn, const int32_t& s_id, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_249(?, ?)");
        conn->execute(stmt.bind(s_id, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_accessory_orm::update_item_accessory_set_id_where_GE_id(tcp_connection* conn, const int32_t& s_id, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_250(?, ?)");
        conn->execute(stmt.bind(s_id, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_accessory_orm::update_item_accessory_set_item_name_where_EQ_id(tcp_connection* conn, const string& s_item_name, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_251(?, ?)");
        conn->execute(stmt.bind(s_item_name, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_accessory_orm::update_item_accessory_set_item_name_where_LT_id(tcp_connection* conn, const string& s_item_name, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_252(?, ?)");
        conn->execute(stmt.bind(s_item_name, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_accessory_orm::update_item_accessory_set_item_name_where_LE_id(tcp_connection* conn, const string& s_item_name, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_253(?, ?)");
        conn->execute(stmt.bind(s_item_name, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_accessory_orm::update_item_accessory_set_item_name_where_GT_id(tcp_connection* conn, const string& s_item_name, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_254(?, ?)");
        conn->execute(stmt.bind(s_item_name, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_accessory_orm::update_item_accessory_set_item_name_where_GE_id(tcp_connection* conn, const string& s_item_name, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_255(?, ?)");
        conn->execute(stmt.bind(s_item_name, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_accessory_orm::update_item_accessory_set_item_description_where_EQ_id(tcp_connection* conn, const string& s_item_description, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_256(?, ?)");
        conn->execute(stmt.bind(s_item_description, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_accessory_orm::update_item_accessory_set_item_description_where_LT_id(tcp_connection* conn, const string& s_item_description, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_257(?, ?)");
        conn->execute(stmt.bind(s_item_description, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_accessory_orm::update_item_accessory_set_item_description_where_LE_id(tcp_connection* conn, const string& s_item_description, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_258(?, ?)");
        conn->execute(stmt.bind(s_item_description, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_accessory_orm::update_item_accessory_set_item_description_where_GT_id(tcp_connection* conn, const string& s_item_description, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_259(?, ?)");
        conn->execute(stmt.bind(s_item_description, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_accessory_orm::update_item_accessory_set_item_description_where_GE_id(tcp_connection* conn, const string& s_item_description, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_260(?, ?)");
        conn->execute(stmt.bind(s_item_description, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_accessory_orm::update_item_accessory_set_item_effect_where_EQ_id(tcp_connection* conn, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_261(?, ?)");
        conn->execute(stmt.bind(s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_accessory_orm::update_item_accessory_set_item_effect_where_LT_id(tcp_connection* conn, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_262(?, ?)");
        conn->execute(stmt.bind(s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_accessory_orm::update_item_accessory_set_item_effect_where_LE_id(tcp_connection* conn, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_263(?, ?)");
        conn->execute(stmt.bind(s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_accessory_orm::update_item_accessory_set_item_effect_where_GT_id(tcp_connection* conn, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_264(?, ?)");
        conn->execute(stmt.bind(s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_accessory_orm::update_item_accessory_set_item_effect_where_GE_id(tcp_connection* conn, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_265(?, ?)");
        conn->execute(stmt.bind(s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_accessory_orm::update_item_accessory_set_id_N_item_name_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_266(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_accessory_orm::update_item_accessory_set_id_N_item_name_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_267(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_accessory_orm::update_item_accessory_set_id_N_item_name_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_268(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_accessory_orm::update_item_accessory_set_id_N_item_name_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_269(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_accessory_orm::update_item_accessory_set_id_N_item_name_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_270(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_accessory_orm::update_item_accessory_set_id_N_item_description_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_271(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_description, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_accessory_orm::update_item_accessory_set_id_N_item_description_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_272(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_description, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_accessory_orm::update_item_accessory_set_id_N_item_description_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_273(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_description, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_accessory_orm::update_item_accessory_set_id_N_item_description_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_274(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_description, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_accessory_orm::update_item_accessory_set_id_N_item_description_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_275(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_description, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_accessory_orm::update_item_accessory_set_id_N_item_effect_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_276(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_accessory_orm::update_item_accessory_set_id_N_item_effect_where_LT_id(tcp_connection* conn, const int32_t& s_id, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_277(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_accessory_orm::update_item_accessory_set_id_N_item_effect_where_LE_id(tcp_connection* conn, const int32_t& s_id, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_278(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_accessory_orm::update_item_accessory_set_id_N_item_effect_where_GT_id(tcp_connection* conn, const int32_t& s_id, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_279(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_accessory_orm::update_item_accessory_set_id_N_item_effect_where_GE_id(tcp_connection* conn, const int32_t& s_id, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_280(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_accessory_orm::update_item_accessory_set_item_name_N_item_description_where_EQ_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_281(?, ?, ?)");
        conn->execute(stmt.bind(s_item_name, s_item_description, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_accessory_orm::update_item_accessory_set_item_name_N_item_description_where_LT_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_282(?, ?, ?)");
        conn->execute(stmt.bind(s_item_name, s_item_description, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_accessory_orm::update_item_accessory_set_item_name_N_item_description_where_LE_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_283(?, ?, ?)");
        conn->execute(stmt.bind(s_item_name, s_item_description, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_accessory_orm::update_item_accessory_set_item_name_N_item_description_where_GT_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_284(?, ?, ?)");
        conn->execute(stmt.bind(s_item_name, s_item_description, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_accessory_orm::update_item_accessory_set_item_name_N_item_description_where_GE_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_285(?, ?, ?)");
        conn->execute(stmt.bind(s_item_name, s_item_description, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_accessory_orm::update_item_accessory_set_item_name_N_item_effect_where_EQ_id(tcp_connection* conn, const string& s_item_name, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_286(?, ?, ?)");
        conn->execute(stmt.bind(s_item_name, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_accessory_orm::update_item_accessory_set_item_name_N_item_effect_where_LT_id(tcp_connection* conn, const string& s_item_name, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_287(?, ?, ?)");
        conn->execute(stmt.bind(s_item_name, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_accessory_orm::update_item_accessory_set_item_name_N_item_effect_where_LE_id(tcp_connection* conn, const string& s_item_name, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_288(?, ?, ?)");
        conn->execute(stmt.bind(s_item_name, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_accessory_orm::update_item_accessory_set_item_name_N_item_effect_where_GT_id(tcp_connection* conn, const string& s_item_name, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_289(?, ?, ?)");
        conn->execute(stmt.bind(s_item_name, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_accessory_orm::update_item_accessory_set_item_name_N_item_effect_where_GE_id(tcp_connection* conn, const string& s_item_name, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_290(?, ?, ?)");
        conn->execute(stmt.bind(s_item_name, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_accessory_orm::update_item_accessory_set_item_description_N_item_effect_where_EQ_id(tcp_connection* conn, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_291(?, ?, ?)");
        conn->execute(stmt.bind(s_item_description, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_accessory_orm::update_item_accessory_set_item_description_N_item_effect_where_LT_id(tcp_connection* conn, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_292(?, ?, ?)");
        conn->execute(stmt.bind(s_item_description, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_accessory_orm::update_item_accessory_set_item_description_N_item_effect_where_LE_id(tcp_connection* conn, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_293(?, ?, ?)");
        conn->execute(stmt.bind(s_item_description, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_accessory_orm::update_item_accessory_set_item_description_N_item_effect_where_GT_id(tcp_connection* conn, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_294(?, ?, ?)");
        conn->execute(stmt.bind(s_item_description, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_accessory_orm::update_item_accessory_set_item_description_N_item_effect_where_GE_id(tcp_connection* conn, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_295(?, ?, ?)");
        conn->execute(stmt.bind(s_item_description, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_accessory_orm::update_item_accessory_set_id_N_item_name_N_item_description_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_296(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, s_item_description, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_accessory_orm::update_item_accessory_set_id_N_item_name_N_item_description_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_297(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, s_item_description, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_accessory_orm::update_item_accessory_set_id_N_item_name_N_item_description_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_298(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, s_item_description, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_accessory_orm::update_item_accessory_set_id_N_item_name_N_item_description_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_299(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, s_item_description, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_accessory_orm::update_item_accessory_set_id_N_item_name_N_item_description_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_300(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, s_item_description, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_accessory_orm::update_item_accessory_set_id_N_item_name_N_item_effect_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_301(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_accessory_orm::update_item_accessory_set_id_N_item_name_N_item_effect_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_302(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_accessory_orm::update_item_accessory_set_id_N_item_name_N_item_effect_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_303(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_accessory_orm::update_item_accessory_set_id_N_item_name_N_item_effect_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_304(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_accessory_orm::update_item_accessory_set_id_N_item_name_N_item_effect_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_305(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_accessory_orm::update_item_accessory_set_id_N_item_description_N_item_effect_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_306(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_description, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_accessory_orm::update_item_accessory_set_id_N_item_description_N_item_effect_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_307(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_description, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_accessory_orm::update_item_accessory_set_id_N_item_description_N_item_effect_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_308(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_description, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_accessory_orm::update_item_accessory_set_id_N_item_description_N_item_effect_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_309(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_description, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_accessory_orm::update_item_accessory_set_id_N_item_description_N_item_effect_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_310(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_description, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_accessory_orm::update_item_accessory_set_item_name_N_item_description_N_item_effect_where_EQ_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_311(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_item_name, s_item_description, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_accessory_orm::update_item_accessory_set_item_name_N_item_description_N_item_effect_where_LT_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_312(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_item_name, s_item_description, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_accessory_orm::update_item_accessory_set_item_name_N_item_description_N_item_effect_where_LE_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_313(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_item_name, s_item_description, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_accessory_orm::update_item_accessory_set_item_name_N_item_description_N_item_effect_where_GT_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_314(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_item_name, s_item_description, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_accessory_orm::update_item_accessory_set_item_name_N_item_description_N_item_effect_where_GE_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_315(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_item_name, s_item_description, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_accessory_orm::update_item_accessory_set_id_N_item_name_N_item_description_N_item_effect_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_316(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, s_item_description, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_accessory_orm::update_item_accessory_set_id_N_item_name_N_item_description_N_item_effect_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_317(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, s_item_description, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_accessory_orm::update_item_accessory_set_id_N_item_name_N_item_description_N_item_effect_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_318(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, s_item_description, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_accessory_orm::update_item_accessory_set_id_N_item_name_N_item_description_N_item_effect_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_319(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, s_item_description, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_accessory_orm::update_item_accessory_set_id_N_item_name_N_item_description_N_item_effect_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_320(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, s_item_description, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_accessory_orm::delete_from_item_accessory_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_321(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_accessory_orm::delete_from_item_accessory_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_322(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_accessory_orm::delete_from_item_accessory_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_323(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_accessory_orm::delete_from_item_accessory_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_324(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_accessory_orm::delete_from_item_accessory_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_325(?)");
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
