
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

struct item_armor
{
    int32_t id; // int
    string item_name; // varchar(64)
    string item_description; // text(65535)
    int32_t defense_power; // int
    int32_t item_effect; // int
};

BOOST_DESCRIBE_STRUCT(item_armor, (), (id, item_name, item_description, defense_power, item_effect));

class item_armor_orm
{
public:
    // SP 호출 선언
    static int insert_into_item_armor_id_N_item_name(tcp_connection* conn, const int32_t& new_id, const string& new_item_name);
    static int insert_into_item_armor_id_N_item_name_N_item_description(tcp_connection* conn, const int32_t& new_id, const string& new_item_name, const string& new_item_description);
    static int insert_into_item_armor_id_N_item_name_N_defense_power(tcp_connection* conn, const int32_t& new_id, const string& new_item_name, const int32_t& new_defense_power);
    static int insert_into_item_armor_id_N_item_name_N_item_effect(tcp_connection* conn, const int32_t& new_id, const string& new_item_name, const int32_t& new_item_effect);
    static int insert_into_item_armor_id_N_item_name_N_item_description_N_defense_power(tcp_connection* conn, const int32_t& new_id, const string& new_item_name, const string& new_item_description, const int32_t& new_defense_power);
    static int insert_into_item_armor_id_N_item_name_N_item_description_N_item_effect(tcp_connection* conn, const int32_t& new_id, const string& new_item_name, const string& new_item_description, const int32_t& new_item_effect);
    static int insert_into_item_armor_id_N_item_name_N_defense_power_N_item_effect(tcp_connection* conn, const int32_t& new_id, const string& new_item_name, const int32_t& new_defense_power, const int32_t& new_item_effect);
    static int insert_into_item_armor_id_N_item_name_N_item_description_N_defense_power_N_item_effect(tcp_connection* conn, const int32_t& new_id, const string& new_item_name, const string& new_item_description, const int32_t& new_defense_power, const int32_t& new_item_effect);
    static results select_id_from_item_armor_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_from_item_armor_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_from_item_armor_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_from_item_armor_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_from_item_armor_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_from_item_armor_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_from_item_armor_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_from_item_armor_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_from_item_armor_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_from_item_armor_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_description_from_item_armor_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_description_from_item_armor_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_description_from_item_armor_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_description_from_item_armor_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_description_from_item_armor_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_defense_power_from_item_armor_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_defense_power_from_item_armor_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_defense_power_from_item_armor_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_defense_power_from_item_armor_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_defense_power_from_item_armor_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_effect_from_item_armor_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_effect_from_item_armor_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_effect_from_item_armor_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_effect_from_item_armor_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_effect_from_item_armor_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_name_from_item_armor_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_name_from_item_armor_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_name_from_item_armor_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_name_from_item_armor_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_name_from_item_armor_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_description_from_item_armor_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_description_from_item_armor_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_description_from_item_armor_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_description_from_item_armor_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_description_from_item_armor_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_defense_power_from_item_armor_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_defense_power_from_item_armor_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_defense_power_from_item_armor_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_defense_power_from_item_armor_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_defense_power_from_item_armor_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_effect_from_item_armor_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_effect_from_item_armor_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_effect_from_item_armor_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_effect_from_item_armor_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_effect_from_item_armor_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_N_item_description_from_item_armor_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_N_item_description_from_item_armor_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_N_item_description_from_item_armor_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_N_item_description_from_item_armor_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_N_item_description_from_item_armor_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_N_defense_power_from_item_armor_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_N_defense_power_from_item_armor_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_N_defense_power_from_item_armor_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_N_defense_power_from_item_armor_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_N_defense_power_from_item_armor_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_N_item_effect_from_item_armor_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_N_item_effect_from_item_armor_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_N_item_effect_from_item_armor_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_N_item_effect_from_item_armor_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_N_item_effect_from_item_armor_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_description_N_defense_power_from_item_armor_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_description_N_defense_power_from_item_armor_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_description_N_defense_power_from_item_armor_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_description_N_defense_power_from_item_armor_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_description_N_defense_power_from_item_armor_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_description_N_item_effect_from_item_armor_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_description_N_item_effect_from_item_armor_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_description_N_item_effect_from_item_armor_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_description_N_item_effect_from_item_armor_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_description_N_item_effect_from_item_armor_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_defense_power_N_item_effect_from_item_armor_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_defense_power_N_item_effect_from_item_armor_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_defense_power_N_item_effect_from_item_armor_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_defense_power_N_item_effect_from_item_armor_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_defense_power_N_item_effect_from_item_armor_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_name_N_item_description_from_item_armor_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_name_N_item_description_from_item_armor_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_name_N_item_description_from_item_armor_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_name_N_item_description_from_item_armor_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_name_N_item_description_from_item_armor_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_name_N_defense_power_from_item_armor_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_name_N_defense_power_from_item_armor_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_name_N_defense_power_from_item_armor_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_name_N_defense_power_from_item_armor_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_name_N_defense_power_from_item_armor_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_name_N_item_effect_from_item_armor_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_name_N_item_effect_from_item_armor_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_name_N_item_effect_from_item_armor_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_name_N_item_effect_from_item_armor_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_name_N_item_effect_from_item_armor_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_description_N_defense_power_from_item_armor_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_description_N_defense_power_from_item_armor_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_description_N_defense_power_from_item_armor_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_description_N_defense_power_from_item_armor_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_description_N_defense_power_from_item_armor_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_description_N_item_effect_from_item_armor_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_description_N_item_effect_from_item_armor_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_description_N_item_effect_from_item_armor_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_description_N_item_effect_from_item_armor_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_description_N_item_effect_from_item_armor_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_defense_power_N_item_effect_from_item_armor_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_defense_power_N_item_effect_from_item_armor_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_defense_power_N_item_effect_from_item_armor_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_defense_power_N_item_effect_from_item_armor_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_defense_power_N_item_effect_from_item_armor_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_N_item_description_N_defense_power_from_item_armor_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_N_item_description_N_defense_power_from_item_armor_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_N_item_description_N_defense_power_from_item_armor_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_N_item_description_N_defense_power_from_item_armor_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_N_item_description_N_defense_power_from_item_armor_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_N_item_description_N_item_effect_from_item_armor_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_N_item_description_N_item_effect_from_item_armor_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_N_item_description_N_item_effect_from_item_armor_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_N_item_description_N_item_effect_from_item_armor_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_N_item_description_N_item_effect_from_item_armor_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_N_defense_power_N_item_effect_from_item_armor_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_N_defense_power_N_item_effect_from_item_armor_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_N_defense_power_N_item_effect_from_item_armor_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_N_defense_power_N_item_effect_from_item_armor_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_N_defense_power_N_item_effect_from_item_armor_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_description_N_defense_power_N_item_effect_from_item_armor_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_description_N_defense_power_N_item_effect_from_item_armor_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_description_N_defense_power_N_item_effect_from_item_armor_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_description_N_defense_power_N_item_effect_from_item_armor_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_description_N_defense_power_N_item_effect_from_item_armor_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_name_N_item_description_N_defense_power_from_item_armor_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_name_N_item_description_N_defense_power_from_item_armor_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_name_N_item_description_N_defense_power_from_item_armor_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_name_N_item_description_N_defense_power_from_item_armor_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_name_N_item_description_N_defense_power_from_item_armor_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_name_N_item_description_N_item_effect_from_item_armor_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_name_N_item_description_N_item_effect_from_item_armor_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_name_N_item_description_N_item_effect_from_item_armor_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_name_N_item_description_N_item_effect_from_item_armor_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_name_N_item_description_N_item_effect_from_item_armor_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_name_N_defense_power_N_item_effect_from_item_armor_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_name_N_defense_power_N_item_effect_from_item_armor_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_name_N_defense_power_N_item_effect_from_item_armor_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_name_N_defense_power_N_item_effect_from_item_armor_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_name_N_defense_power_N_item_effect_from_item_armor_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_description_N_defense_power_N_item_effect_from_item_armor_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_description_N_defense_power_N_item_effect_from_item_armor_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_description_N_defense_power_N_item_effect_from_item_armor_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_description_N_defense_power_N_item_effect_from_item_armor_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_description_N_defense_power_N_item_effect_from_item_armor_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_N_item_description_N_defense_power_N_item_effect_from_item_armor_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_N_item_description_N_defense_power_N_item_effect_from_item_armor_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_N_item_description_N_defense_power_N_item_effect_from_item_armor_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_N_item_description_N_defense_power_N_item_effect_from_item_armor_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_N_item_description_N_defense_power_N_item_effect_from_item_armor_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_all_from_item_armor_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_all_from_item_armor_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_all_from_item_armor_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_all_from_item_armor_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_all_from_item_armor_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static int update_item_armor_set_id_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const int32_t& w_id);
    static int update_item_armor_set_id_where_LT_id(tcp_connection* conn, const int32_t& s_id, const int32_t& w_id);
    static int update_item_armor_set_id_where_LE_id(tcp_connection* conn, const int32_t& s_id, const int32_t& w_id);
    static int update_item_armor_set_id_where_GT_id(tcp_connection* conn, const int32_t& s_id, const int32_t& w_id);
    static int update_item_armor_set_id_where_GE_id(tcp_connection* conn, const int32_t& s_id, const int32_t& w_id);
    static int update_item_armor_set_item_name_where_EQ_id(tcp_connection* conn, const string& s_item_name, const int32_t& w_id);
    static int update_item_armor_set_item_name_where_LT_id(tcp_connection* conn, const string& s_item_name, const int32_t& w_id);
    static int update_item_armor_set_item_name_where_LE_id(tcp_connection* conn, const string& s_item_name, const int32_t& w_id);
    static int update_item_armor_set_item_name_where_GT_id(tcp_connection* conn, const string& s_item_name, const int32_t& w_id);
    static int update_item_armor_set_item_name_where_GE_id(tcp_connection* conn, const string& s_item_name, const int32_t& w_id);
    static int update_item_armor_set_item_description_where_EQ_id(tcp_connection* conn, const string& s_item_description, const int32_t& w_id);
    static int update_item_armor_set_item_description_where_LT_id(tcp_connection* conn, const string& s_item_description, const int32_t& w_id);
    static int update_item_armor_set_item_description_where_LE_id(tcp_connection* conn, const string& s_item_description, const int32_t& w_id);
    static int update_item_armor_set_item_description_where_GT_id(tcp_connection* conn, const string& s_item_description, const int32_t& w_id);
    static int update_item_armor_set_item_description_where_GE_id(tcp_connection* conn, const string& s_item_description, const int32_t& w_id);
    static int update_item_armor_set_defense_power_where_EQ_id(tcp_connection* conn, const int32_t& s_defense_power, const int32_t& w_id);
    static int update_item_armor_set_defense_power_where_LT_id(tcp_connection* conn, const int32_t& s_defense_power, const int32_t& w_id);
    static int update_item_armor_set_defense_power_where_LE_id(tcp_connection* conn, const int32_t& s_defense_power, const int32_t& w_id);
    static int update_item_armor_set_defense_power_where_GT_id(tcp_connection* conn, const int32_t& s_defense_power, const int32_t& w_id);
    static int update_item_armor_set_defense_power_where_GE_id(tcp_connection* conn, const int32_t& s_defense_power, const int32_t& w_id);
    static int update_item_armor_set_item_effect_where_EQ_id(tcp_connection* conn, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_armor_set_item_effect_where_LT_id(tcp_connection* conn, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_armor_set_item_effect_where_LE_id(tcp_connection* conn, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_armor_set_item_effect_where_GT_id(tcp_connection* conn, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_armor_set_item_effect_where_GE_id(tcp_connection* conn, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_armor_set_id_N_item_name_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& w_id);
    static int update_item_armor_set_id_N_item_name_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& w_id);
    static int update_item_armor_set_id_N_item_name_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& w_id);
    static int update_item_armor_set_id_N_item_name_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& w_id);
    static int update_item_armor_set_id_N_item_name_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& w_id);
    static int update_item_armor_set_id_N_item_description_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& w_id);
    static int update_item_armor_set_id_N_item_description_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& w_id);
    static int update_item_armor_set_id_N_item_description_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& w_id);
    static int update_item_armor_set_id_N_item_description_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& w_id);
    static int update_item_armor_set_id_N_item_description_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& w_id);
    static int update_item_armor_set_id_N_defense_power_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const int32_t& s_defense_power, const int32_t& w_id);
    static int update_item_armor_set_id_N_defense_power_where_LT_id(tcp_connection* conn, const int32_t& s_id, const int32_t& s_defense_power, const int32_t& w_id);
    static int update_item_armor_set_id_N_defense_power_where_LE_id(tcp_connection* conn, const int32_t& s_id, const int32_t& s_defense_power, const int32_t& w_id);
    static int update_item_armor_set_id_N_defense_power_where_GT_id(tcp_connection* conn, const int32_t& s_id, const int32_t& s_defense_power, const int32_t& w_id);
    static int update_item_armor_set_id_N_defense_power_where_GE_id(tcp_connection* conn, const int32_t& s_id, const int32_t& s_defense_power, const int32_t& w_id);
    static int update_item_armor_set_id_N_item_effect_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_armor_set_id_N_item_effect_where_LT_id(tcp_connection* conn, const int32_t& s_id, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_armor_set_id_N_item_effect_where_LE_id(tcp_connection* conn, const int32_t& s_id, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_armor_set_id_N_item_effect_where_GT_id(tcp_connection* conn, const int32_t& s_id, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_armor_set_id_N_item_effect_where_GE_id(tcp_connection* conn, const int32_t& s_id, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_armor_set_item_name_N_item_description_where_EQ_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& w_id);
    static int update_item_armor_set_item_name_N_item_description_where_LT_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& w_id);
    static int update_item_armor_set_item_name_N_item_description_where_LE_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& w_id);
    static int update_item_armor_set_item_name_N_item_description_where_GT_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& w_id);
    static int update_item_armor_set_item_name_N_item_description_where_GE_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& w_id);
    static int update_item_armor_set_item_name_N_defense_power_where_EQ_id(tcp_connection* conn, const string& s_item_name, const int32_t& s_defense_power, const int32_t& w_id);
    static int update_item_armor_set_item_name_N_defense_power_where_LT_id(tcp_connection* conn, const string& s_item_name, const int32_t& s_defense_power, const int32_t& w_id);
    static int update_item_armor_set_item_name_N_defense_power_where_LE_id(tcp_connection* conn, const string& s_item_name, const int32_t& s_defense_power, const int32_t& w_id);
    static int update_item_armor_set_item_name_N_defense_power_where_GT_id(tcp_connection* conn, const string& s_item_name, const int32_t& s_defense_power, const int32_t& w_id);
    static int update_item_armor_set_item_name_N_defense_power_where_GE_id(tcp_connection* conn, const string& s_item_name, const int32_t& s_defense_power, const int32_t& w_id);
    static int update_item_armor_set_item_name_N_item_effect_where_EQ_id(tcp_connection* conn, const string& s_item_name, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_armor_set_item_name_N_item_effect_where_LT_id(tcp_connection* conn, const string& s_item_name, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_armor_set_item_name_N_item_effect_where_LE_id(tcp_connection* conn, const string& s_item_name, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_armor_set_item_name_N_item_effect_where_GT_id(tcp_connection* conn, const string& s_item_name, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_armor_set_item_name_N_item_effect_where_GE_id(tcp_connection* conn, const string& s_item_name, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_armor_set_item_description_N_defense_power_where_EQ_id(tcp_connection* conn, const string& s_item_description, const int32_t& s_defense_power, const int32_t& w_id);
    static int update_item_armor_set_item_description_N_defense_power_where_LT_id(tcp_connection* conn, const string& s_item_description, const int32_t& s_defense_power, const int32_t& w_id);
    static int update_item_armor_set_item_description_N_defense_power_where_LE_id(tcp_connection* conn, const string& s_item_description, const int32_t& s_defense_power, const int32_t& w_id);
    static int update_item_armor_set_item_description_N_defense_power_where_GT_id(tcp_connection* conn, const string& s_item_description, const int32_t& s_defense_power, const int32_t& w_id);
    static int update_item_armor_set_item_description_N_defense_power_where_GE_id(tcp_connection* conn, const string& s_item_description, const int32_t& s_defense_power, const int32_t& w_id);
    static int update_item_armor_set_item_description_N_item_effect_where_EQ_id(tcp_connection* conn, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_armor_set_item_description_N_item_effect_where_LT_id(tcp_connection* conn, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_armor_set_item_description_N_item_effect_where_LE_id(tcp_connection* conn, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_armor_set_item_description_N_item_effect_where_GT_id(tcp_connection* conn, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_armor_set_item_description_N_item_effect_where_GE_id(tcp_connection* conn, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_armor_set_defense_power_N_item_effect_where_EQ_id(tcp_connection* conn, const int32_t& s_defense_power, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_armor_set_defense_power_N_item_effect_where_LT_id(tcp_connection* conn, const int32_t& s_defense_power, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_armor_set_defense_power_N_item_effect_where_LE_id(tcp_connection* conn, const int32_t& s_defense_power, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_armor_set_defense_power_N_item_effect_where_GT_id(tcp_connection* conn, const int32_t& s_defense_power, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_armor_set_defense_power_N_item_effect_where_GE_id(tcp_connection* conn, const int32_t& s_defense_power, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_armor_set_id_N_item_name_N_item_description_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& w_id);
    static int update_item_armor_set_id_N_item_name_N_item_description_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& w_id);
    static int update_item_armor_set_id_N_item_name_N_item_description_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& w_id);
    static int update_item_armor_set_id_N_item_name_N_item_description_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& w_id);
    static int update_item_armor_set_id_N_item_name_N_item_description_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& w_id);
    static int update_item_armor_set_id_N_item_name_N_defense_power_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& s_defense_power, const int32_t& w_id);
    static int update_item_armor_set_id_N_item_name_N_defense_power_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& s_defense_power, const int32_t& w_id);
    static int update_item_armor_set_id_N_item_name_N_defense_power_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& s_defense_power, const int32_t& w_id);
    static int update_item_armor_set_id_N_item_name_N_defense_power_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& s_defense_power, const int32_t& w_id);
    static int update_item_armor_set_id_N_item_name_N_defense_power_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& s_defense_power, const int32_t& w_id);
    static int update_item_armor_set_id_N_item_name_N_item_effect_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_armor_set_id_N_item_name_N_item_effect_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_armor_set_id_N_item_name_N_item_effect_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_armor_set_id_N_item_name_N_item_effect_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_armor_set_id_N_item_name_N_item_effect_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_armor_set_id_N_item_description_N_defense_power_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& s_defense_power, const int32_t& w_id);
    static int update_item_armor_set_id_N_item_description_N_defense_power_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& s_defense_power, const int32_t& w_id);
    static int update_item_armor_set_id_N_item_description_N_defense_power_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& s_defense_power, const int32_t& w_id);
    static int update_item_armor_set_id_N_item_description_N_defense_power_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& s_defense_power, const int32_t& w_id);
    static int update_item_armor_set_id_N_item_description_N_defense_power_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& s_defense_power, const int32_t& w_id);
    static int update_item_armor_set_id_N_item_description_N_item_effect_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_armor_set_id_N_item_description_N_item_effect_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_armor_set_id_N_item_description_N_item_effect_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_armor_set_id_N_item_description_N_item_effect_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_armor_set_id_N_item_description_N_item_effect_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_armor_set_id_N_defense_power_N_item_effect_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const int32_t& s_defense_power, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_armor_set_id_N_defense_power_N_item_effect_where_LT_id(tcp_connection* conn, const int32_t& s_id, const int32_t& s_defense_power, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_armor_set_id_N_defense_power_N_item_effect_where_LE_id(tcp_connection* conn, const int32_t& s_id, const int32_t& s_defense_power, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_armor_set_id_N_defense_power_N_item_effect_where_GT_id(tcp_connection* conn, const int32_t& s_id, const int32_t& s_defense_power, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_armor_set_id_N_defense_power_N_item_effect_where_GE_id(tcp_connection* conn, const int32_t& s_id, const int32_t& s_defense_power, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_armor_set_item_name_N_item_description_N_defense_power_where_EQ_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& s_defense_power, const int32_t& w_id);
    static int update_item_armor_set_item_name_N_item_description_N_defense_power_where_LT_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& s_defense_power, const int32_t& w_id);
    static int update_item_armor_set_item_name_N_item_description_N_defense_power_where_LE_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& s_defense_power, const int32_t& w_id);
    static int update_item_armor_set_item_name_N_item_description_N_defense_power_where_GT_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& s_defense_power, const int32_t& w_id);
    static int update_item_armor_set_item_name_N_item_description_N_defense_power_where_GE_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& s_defense_power, const int32_t& w_id);
    static int update_item_armor_set_item_name_N_item_description_N_item_effect_where_EQ_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_armor_set_item_name_N_item_description_N_item_effect_where_LT_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_armor_set_item_name_N_item_description_N_item_effect_where_LE_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_armor_set_item_name_N_item_description_N_item_effect_where_GT_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_armor_set_item_name_N_item_description_N_item_effect_where_GE_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_armor_set_item_name_N_defense_power_N_item_effect_where_EQ_id(tcp_connection* conn, const string& s_item_name, const int32_t& s_defense_power, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_armor_set_item_name_N_defense_power_N_item_effect_where_LT_id(tcp_connection* conn, const string& s_item_name, const int32_t& s_defense_power, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_armor_set_item_name_N_defense_power_N_item_effect_where_LE_id(tcp_connection* conn, const string& s_item_name, const int32_t& s_defense_power, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_armor_set_item_name_N_defense_power_N_item_effect_where_GT_id(tcp_connection* conn, const string& s_item_name, const int32_t& s_defense_power, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_armor_set_item_name_N_defense_power_N_item_effect_where_GE_id(tcp_connection* conn, const string& s_item_name, const int32_t& s_defense_power, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_armor_set_item_description_N_defense_power_N_item_effect_where_EQ_id(tcp_connection* conn, const string& s_item_description, const int32_t& s_defense_power, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_armor_set_item_description_N_defense_power_N_item_effect_where_LT_id(tcp_connection* conn, const string& s_item_description, const int32_t& s_defense_power, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_armor_set_item_description_N_defense_power_N_item_effect_where_LE_id(tcp_connection* conn, const string& s_item_description, const int32_t& s_defense_power, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_armor_set_item_description_N_defense_power_N_item_effect_where_GT_id(tcp_connection* conn, const string& s_item_description, const int32_t& s_defense_power, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_armor_set_item_description_N_defense_power_N_item_effect_where_GE_id(tcp_connection* conn, const string& s_item_description, const int32_t& s_defense_power, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_armor_set_id_N_item_name_N_item_description_N_defense_power_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& s_defense_power, const int32_t& w_id);
    static int update_item_armor_set_id_N_item_name_N_item_description_N_defense_power_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& s_defense_power, const int32_t& w_id);
    static int update_item_armor_set_id_N_item_name_N_item_description_N_defense_power_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& s_defense_power, const int32_t& w_id);
    static int update_item_armor_set_id_N_item_name_N_item_description_N_defense_power_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& s_defense_power, const int32_t& w_id);
    static int update_item_armor_set_id_N_item_name_N_item_description_N_defense_power_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& s_defense_power, const int32_t& w_id);
    static int update_item_armor_set_id_N_item_name_N_item_description_N_item_effect_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_armor_set_id_N_item_name_N_item_description_N_item_effect_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_armor_set_id_N_item_name_N_item_description_N_item_effect_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_armor_set_id_N_item_name_N_item_description_N_item_effect_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_armor_set_id_N_item_name_N_item_description_N_item_effect_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_armor_set_id_N_item_name_N_defense_power_N_item_effect_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& s_defense_power, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_armor_set_id_N_item_name_N_defense_power_N_item_effect_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& s_defense_power, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_armor_set_id_N_item_name_N_defense_power_N_item_effect_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& s_defense_power, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_armor_set_id_N_item_name_N_defense_power_N_item_effect_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& s_defense_power, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_armor_set_id_N_item_name_N_defense_power_N_item_effect_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& s_defense_power, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_armor_set_id_N_item_description_N_defense_power_N_item_effect_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& s_defense_power, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_armor_set_id_N_item_description_N_defense_power_N_item_effect_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& s_defense_power, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_armor_set_id_N_item_description_N_defense_power_N_item_effect_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& s_defense_power, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_armor_set_id_N_item_description_N_defense_power_N_item_effect_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& s_defense_power, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_armor_set_id_N_item_description_N_defense_power_N_item_effect_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& s_defense_power, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_armor_set_item_name_N_item_description_N_defense_power_N_item_effect_where_EQ_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& s_defense_power, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_armor_set_item_name_N_item_description_N_defense_power_N_item_effect_where_LT_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& s_defense_power, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_armor_set_item_name_N_item_description_N_defense_power_N_item_effect_where_LE_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& s_defense_power, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_armor_set_item_name_N_item_description_N_defense_power_N_item_effect_where_GT_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& s_defense_power, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_armor_set_item_name_N_item_description_N_defense_power_N_item_effect_where_GE_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& s_defense_power, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_armor_set_id_N_item_name_N_item_description_N_defense_power_N_item_effect_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& s_defense_power, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_armor_set_id_N_item_name_N_item_description_N_defense_power_N_item_effect_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& s_defense_power, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_armor_set_id_N_item_name_N_item_description_N_defense_power_N_item_effect_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& s_defense_power, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_armor_set_id_N_item_name_N_item_description_N_defense_power_N_item_effect_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& s_defense_power, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_armor_set_id_N_item_name_N_item_description_N_defense_power_N_item_effect_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& s_defense_power, const int32_t& s_item_effect, const int32_t& w_id);
    static int delete_from_item_armor_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static int delete_from_item_armor_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static int delete_from_item_armor_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static int delete_from_item_armor_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static int delete_from_item_armor_where_GE_id(tcp_connection* conn, const int32_t& w_id);
};

// SP 호출 구현

inline int item_armor_orm::insert_into_item_armor_id_N_item_name(tcp_connection* conn, const int32_t& new_id, const string& new_item_name)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_326(?, ?)");
        conn->execute(stmt.bind(new_id, new_item_name), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return -1;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::insert_into_item_armor_id_N_item_name_N_item_description(tcp_connection* conn, const int32_t& new_id, const string& new_item_name, const string& new_item_description)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_327(?, ?, ?)");
        conn->execute(stmt.bind(new_id, new_item_name, new_item_description), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return -1;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::insert_into_item_armor_id_N_item_name_N_defense_power(tcp_connection* conn, const int32_t& new_id, const string& new_item_name, const int32_t& new_defense_power)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_328(?, ?, ?)");
        conn->execute(stmt.bind(new_id, new_item_name, new_defense_power), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return -1;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::insert_into_item_armor_id_N_item_name_N_item_effect(tcp_connection* conn, const int32_t& new_id, const string& new_item_name, const int32_t& new_item_effect)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_329(?, ?, ?)");
        conn->execute(stmt.bind(new_id, new_item_name, new_item_effect), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return -1;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::insert_into_item_armor_id_N_item_name_N_item_description_N_defense_power(tcp_connection* conn, const int32_t& new_id, const string& new_item_name, const string& new_item_description, const int32_t& new_defense_power)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_330(?, ?, ?, ?)");
        conn->execute(stmt.bind(new_id, new_item_name, new_item_description, new_defense_power), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return -1;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::insert_into_item_armor_id_N_item_name_N_item_description_N_item_effect(tcp_connection* conn, const int32_t& new_id, const string& new_item_name, const string& new_item_description, const int32_t& new_item_effect)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_331(?, ?, ?, ?)");
        conn->execute(stmt.bind(new_id, new_item_name, new_item_description, new_item_effect), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return -1;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::insert_into_item_armor_id_N_item_name_N_defense_power_N_item_effect(tcp_connection* conn, const int32_t& new_id, const string& new_item_name, const int32_t& new_defense_power, const int32_t& new_item_effect)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_332(?, ?, ?, ?)");
        conn->execute(stmt.bind(new_id, new_item_name, new_defense_power, new_item_effect), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return -1;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::insert_into_item_armor_id_N_item_name_N_item_description_N_defense_power_N_item_effect(tcp_connection* conn, const int32_t& new_id, const string& new_item_name, const string& new_item_description, const int32_t& new_defense_power, const int32_t& new_item_effect)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_333(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(new_id, new_item_name, new_item_description, new_defense_power, new_item_effect), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return -1;
    }

    return result.affected_rows();
}

    
inline results item_armor_orm::select_id_from_item_armor_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_334(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_id_from_item_armor_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_335(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_id_from_item_armor_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_336(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_id_from_item_armor_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_337(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_id_from_item_armor_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_338(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_item_name_from_item_armor_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_339(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_item_name_from_item_armor_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_340(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_item_name_from_item_armor_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_341(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_item_name_from_item_armor_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_342(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_item_name_from_item_armor_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_343(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_item_description_from_item_armor_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_344(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_item_description_from_item_armor_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_345(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_item_description_from_item_armor_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_346(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_item_description_from_item_armor_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_347(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_item_description_from_item_armor_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_348(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_defense_power_from_item_armor_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_349(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_defense_power_from_item_armor_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_350(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_defense_power_from_item_armor_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_351(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_defense_power_from_item_armor_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_352(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_defense_power_from_item_armor_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_353(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_item_effect_from_item_armor_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_354(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_item_effect_from_item_armor_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_355(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_item_effect_from_item_armor_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_356(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_item_effect_from_item_armor_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_357(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_item_effect_from_item_armor_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_358(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_id_N_item_name_from_item_armor_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_359(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_id_N_item_name_from_item_armor_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_360(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_id_N_item_name_from_item_armor_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_361(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_id_N_item_name_from_item_armor_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_362(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_id_N_item_name_from_item_armor_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_363(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_id_N_item_description_from_item_armor_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_364(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_id_N_item_description_from_item_armor_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_365(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_id_N_item_description_from_item_armor_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_366(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_id_N_item_description_from_item_armor_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_367(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_id_N_item_description_from_item_armor_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_368(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_id_N_defense_power_from_item_armor_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_369(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_id_N_defense_power_from_item_armor_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_370(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_id_N_defense_power_from_item_armor_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_371(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_id_N_defense_power_from_item_armor_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_372(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_id_N_defense_power_from_item_armor_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_373(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_id_N_item_effect_from_item_armor_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_374(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_id_N_item_effect_from_item_armor_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_375(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_id_N_item_effect_from_item_armor_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_376(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_id_N_item_effect_from_item_armor_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_377(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_id_N_item_effect_from_item_armor_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_378(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_item_name_N_item_description_from_item_armor_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_379(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_item_name_N_item_description_from_item_armor_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_380(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_item_name_N_item_description_from_item_armor_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_381(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_item_name_N_item_description_from_item_armor_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_382(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_item_name_N_item_description_from_item_armor_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_383(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_item_name_N_defense_power_from_item_armor_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_384(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_item_name_N_defense_power_from_item_armor_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_385(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_item_name_N_defense_power_from_item_armor_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_386(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_item_name_N_defense_power_from_item_armor_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_387(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_item_name_N_defense_power_from_item_armor_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_388(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_item_name_N_item_effect_from_item_armor_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_389(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_item_name_N_item_effect_from_item_armor_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_390(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_item_name_N_item_effect_from_item_armor_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_391(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_item_name_N_item_effect_from_item_armor_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_392(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_item_name_N_item_effect_from_item_armor_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_393(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_item_description_N_defense_power_from_item_armor_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_394(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_item_description_N_defense_power_from_item_armor_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_395(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_item_description_N_defense_power_from_item_armor_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_396(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_item_description_N_defense_power_from_item_armor_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_397(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_item_description_N_defense_power_from_item_armor_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_398(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_item_description_N_item_effect_from_item_armor_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_399(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_item_description_N_item_effect_from_item_armor_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_400(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_item_description_N_item_effect_from_item_armor_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_401(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_item_description_N_item_effect_from_item_armor_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_402(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_item_description_N_item_effect_from_item_armor_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_403(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_defense_power_N_item_effect_from_item_armor_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_404(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_defense_power_N_item_effect_from_item_armor_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_405(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_defense_power_N_item_effect_from_item_armor_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_406(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_defense_power_N_item_effect_from_item_armor_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_407(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_defense_power_N_item_effect_from_item_armor_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_408(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_id_N_item_name_N_item_description_from_item_armor_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_409(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_id_N_item_name_N_item_description_from_item_armor_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_410(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_id_N_item_name_N_item_description_from_item_armor_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_411(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_id_N_item_name_N_item_description_from_item_armor_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_412(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_id_N_item_name_N_item_description_from_item_armor_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_413(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_id_N_item_name_N_defense_power_from_item_armor_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_414(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_id_N_item_name_N_defense_power_from_item_armor_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_415(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_id_N_item_name_N_defense_power_from_item_armor_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_416(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_id_N_item_name_N_defense_power_from_item_armor_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_417(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_id_N_item_name_N_defense_power_from_item_armor_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_418(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_id_N_item_name_N_item_effect_from_item_armor_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_419(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_id_N_item_name_N_item_effect_from_item_armor_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_420(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_id_N_item_name_N_item_effect_from_item_armor_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_421(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_id_N_item_name_N_item_effect_from_item_armor_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_422(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_id_N_item_name_N_item_effect_from_item_armor_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_423(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_id_N_item_description_N_defense_power_from_item_armor_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_424(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_id_N_item_description_N_defense_power_from_item_armor_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_425(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_id_N_item_description_N_defense_power_from_item_armor_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_426(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_id_N_item_description_N_defense_power_from_item_armor_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_427(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_id_N_item_description_N_defense_power_from_item_armor_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_428(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_id_N_item_description_N_item_effect_from_item_armor_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_429(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_id_N_item_description_N_item_effect_from_item_armor_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_430(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_id_N_item_description_N_item_effect_from_item_armor_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_431(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_id_N_item_description_N_item_effect_from_item_armor_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_432(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_id_N_item_description_N_item_effect_from_item_armor_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_433(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_id_N_defense_power_N_item_effect_from_item_armor_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_434(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_id_N_defense_power_N_item_effect_from_item_armor_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_435(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_id_N_defense_power_N_item_effect_from_item_armor_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_436(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_id_N_defense_power_N_item_effect_from_item_armor_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_437(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_id_N_defense_power_N_item_effect_from_item_armor_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_438(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_item_name_N_item_description_N_defense_power_from_item_armor_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_439(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_item_name_N_item_description_N_defense_power_from_item_armor_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_440(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_item_name_N_item_description_N_defense_power_from_item_armor_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_441(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_item_name_N_item_description_N_defense_power_from_item_armor_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_442(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_item_name_N_item_description_N_defense_power_from_item_armor_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_443(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_item_name_N_item_description_N_item_effect_from_item_armor_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_444(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_item_name_N_item_description_N_item_effect_from_item_armor_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_445(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_item_name_N_item_description_N_item_effect_from_item_armor_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_446(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_item_name_N_item_description_N_item_effect_from_item_armor_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_447(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_item_name_N_item_description_N_item_effect_from_item_armor_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_448(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_item_name_N_defense_power_N_item_effect_from_item_armor_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_449(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_item_name_N_defense_power_N_item_effect_from_item_armor_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_450(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_item_name_N_defense_power_N_item_effect_from_item_armor_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_451(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_item_name_N_defense_power_N_item_effect_from_item_armor_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_452(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_item_name_N_defense_power_N_item_effect_from_item_armor_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_453(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_item_description_N_defense_power_N_item_effect_from_item_armor_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_454(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_item_description_N_defense_power_N_item_effect_from_item_armor_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_455(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_item_description_N_defense_power_N_item_effect_from_item_armor_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_456(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_item_description_N_defense_power_N_item_effect_from_item_armor_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_457(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_item_description_N_defense_power_N_item_effect_from_item_armor_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_458(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_id_N_item_name_N_item_description_N_defense_power_from_item_armor_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_459(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_id_N_item_name_N_item_description_N_defense_power_from_item_armor_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_460(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_id_N_item_name_N_item_description_N_defense_power_from_item_armor_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_461(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_id_N_item_name_N_item_description_N_defense_power_from_item_armor_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_462(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_id_N_item_name_N_item_description_N_defense_power_from_item_armor_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_463(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_id_N_item_name_N_item_description_N_item_effect_from_item_armor_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_464(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_id_N_item_name_N_item_description_N_item_effect_from_item_armor_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_465(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_id_N_item_name_N_item_description_N_item_effect_from_item_armor_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_466(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_id_N_item_name_N_item_description_N_item_effect_from_item_armor_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_467(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_id_N_item_name_N_item_description_N_item_effect_from_item_armor_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_468(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_id_N_item_name_N_defense_power_N_item_effect_from_item_armor_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_469(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_id_N_item_name_N_defense_power_N_item_effect_from_item_armor_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_470(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_id_N_item_name_N_defense_power_N_item_effect_from_item_armor_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_471(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_id_N_item_name_N_defense_power_N_item_effect_from_item_armor_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_472(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_id_N_item_name_N_defense_power_N_item_effect_from_item_armor_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_473(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_id_N_item_description_N_defense_power_N_item_effect_from_item_armor_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_474(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_id_N_item_description_N_defense_power_N_item_effect_from_item_armor_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_475(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_id_N_item_description_N_defense_power_N_item_effect_from_item_armor_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_476(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_id_N_item_description_N_defense_power_N_item_effect_from_item_armor_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_477(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_id_N_item_description_N_defense_power_N_item_effect_from_item_armor_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_478(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_item_name_N_item_description_N_defense_power_N_item_effect_from_item_armor_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_479(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_item_name_N_item_description_N_defense_power_N_item_effect_from_item_armor_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_480(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_item_name_N_item_description_N_defense_power_N_item_effect_from_item_armor_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_481(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_item_name_N_item_description_N_defense_power_N_item_effect_from_item_armor_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_482(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_item_name_N_item_description_N_defense_power_N_item_effect_from_item_armor_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_483(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_all_from_item_armor_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_484(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_all_from_item_armor_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_485(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_all_from_item_armor_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_486(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_all_from_item_armor_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_487(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_armor_orm::select_all_from_item_armor_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_488(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline int item_armor_orm::update_item_armor_set_id_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_489(?, ?)");
        conn->execute(stmt.bind(s_id, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_id_where_LT_id(tcp_connection* conn, const int32_t& s_id, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_490(?, ?)");
        conn->execute(stmt.bind(s_id, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_id_where_LE_id(tcp_connection* conn, const int32_t& s_id, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_491(?, ?)");
        conn->execute(stmt.bind(s_id, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_id_where_GT_id(tcp_connection* conn, const int32_t& s_id, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_492(?, ?)");
        conn->execute(stmt.bind(s_id, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_id_where_GE_id(tcp_connection* conn, const int32_t& s_id, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_493(?, ?)");
        conn->execute(stmt.bind(s_id, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_item_name_where_EQ_id(tcp_connection* conn, const string& s_item_name, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_494(?, ?)");
        conn->execute(stmt.bind(s_item_name, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_item_name_where_LT_id(tcp_connection* conn, const string& s_item_name, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_495(?, ?)");
        conn->execute(stmt.bind(s_item_name, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_item_name_where_LE_id(tcp_connection* conn, const string& s_item_name, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_496(?, ?)");
        conn->execute(stmt.bind(s_item_name, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_item_name_where_GT_id(tcp_connection* conn, const string& s_item_name, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_497(?, ?)");
        conn->execute(stmt.bind(s_item_name, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_item_name_where_GE_id(tcp_connection* conn, const string& s_item_name, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_498(?, ?)");
        conn->execute(stmt.bind(s_item_name, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_item_description_where_EQ_id(tcp_connection* conn, const string& s_item_description, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_499(?, ?)");
        conn->execute(stmt.bind(s_item_description, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_item_description_where_LT_id(tcp_connection* conn, const string& s_item_description, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_500(?, ?)");
        conn->execute(stmt.bind(s_item_description, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_item_description_where_LE_id(tcp_connection* conn, const string& s_item_description, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_501(?, ?)");
        conn->execute(stmt.bind(s_item_description, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_item_description_where_GT_id(tcp_connection* conn, const string& s_item_description, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_502(?, ?)");
        conn->execute(stmt.bind(s_item_description, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_item_description_where_GE_id(tcp_connection* conn, const string& s_item_description, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_503(?, ?)");
        conn->execute(stmt.bind(s_item_description, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_defense_power_where_EQ_id(tcp_connection* conn, const int32_t& s_defense_power, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_504(?, ?)");
        conn->execute(stmt.bind(s_defense_power, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_defense_power_where_LT_id(tcp_connection* conn, const int32_t& s_defense_power, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_505(?, ?)");
        conn->execute(stmt.bind(s_defense_power, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_defense_power_where_LE_id(tcp_connection* conn, const int32_t& s_defense_power, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_506(?, ?)");
        conn->execute(stmt.bind(s_defense_power, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_defense_power_where_GT_id(tcp_connection* conn, const int32_t& s_defense_power, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_507(?, ?)");
        conn->execute(stmt.bind(s_defense_power, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_defense_power_where_GE_id(tcp_connection* conn, const int32_t& s_defense_power, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_508(?, ?)");
        conn->execute(stmt.bind(s_defense_power, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_item_effect_where_EQ_id(tcp_connection* conn, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_509(?, ?)");
        conn->execute(stmt.bind(s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_item_effect_where_LT_id(tcp_connection* conn, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_510(?, ?)");
        conn->execute(stmt.bind(s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_item_effect_where_LE_id(tcp_connection* conn, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_511(?, ?)");
        conn->execute(stmt.bind(s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_item_effect_where_GT_id(tcp_connection* conn, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_512(?, ?)");
        conn->execute(stmt.bind(s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_item_effect_where_GE_id(tcp_connection* conn, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_513(?, ?)");
        conn->execute(stmt.bind(s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_id_N_item_name_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_514(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_id_N_item_name_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_515(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_id_N_item_name_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_516(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_id_N_item_name_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_517(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_id_N_item_name_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_518(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_id_N_item_description_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_519(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_description, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_id_N_item_description_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_520(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_description, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_id_N_item_description_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_521(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_description, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_id_N_item_description_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_522(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_description, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_id_N_item_description_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_523(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_description, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_id_N_defense_power_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const int32_t& s_defense_power, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_524(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_defense_power, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_id_N_defense_power_where_LT_id(tcp_connection* conn, const int32_t& s_id, const int32_t& s_defense_power, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_525(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_defense_power, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_id_N_defense_power_where_LE_id(tcp_connection* conn, const int32_t& s_id, const int32_t& s_defense_power, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_526(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_defense_power, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_id_N_defense_power_where_GT_id(tcp_connection* conn, const int32_t& s_id, const int32_t& s_defense_power, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_527(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_defense_power, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_id_N_defense_power_where_GE_id(tcp_connection* conn, const int32_t& s_id, const int32_t& s_defense_power, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_528(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_defense_power, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_id_N_item_effect_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_529(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_id_N_item_effect_where_LT_id(tcp_connection* conn, const int32_t& s_id, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_530(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_id_N_item_effect_where_LE_id(tcp_connection* conn, const int32_t& s_id, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_531(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_id_N_item_effect_where_GT_id(tcp_connection* conn, const int32_t& s_id, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_532(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_id_N_item_effect_where_GE_id(tcp_connection* conn, const int32_t& s_id, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_533(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_item_name_N_item_description_where_EQ_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_534(?, ?, ?)");
        conn->execute(stmt.bind(s_item_name, s_item_description, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_item_name_N_item_description_where_LT_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_535(?, ?, ?)");
        conn->execute(stmt.bind(s_item_name, s_item_description, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_item_name_N_item_description_where_LE_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_536(?, ?, ?)");
        conn->execute(stmt.bind(s_item_name, s_item_description, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_item_name_N_item_description_where_GT_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_537(?, ?, ?)");
        conn->execute(stmt.bind(s_item_name, s_item_description, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_item_name_N_item_description_where_GE_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_538(?, ?, ?)");
        conn->execute(stmt.bind(s_item_name, s_item_description, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_item_name_N_defense_power_where_EQ_id(tcp_connection* conn, const string& s_item_name, const int32_t& s_defense_power, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_539(?, ?, ?)");
        conn->execute(stmt.bind(s_item_name, s_defense_power, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_item_name_N_defense_power_where_LT_id(tcp_connection* conn, const string& s_item_name, const int32_t& s_defense_power, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_540(?, ?, ?)");
        conn->execute(stmt.bind(s_item_name, s_defense_power, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_item_name_N_defense_power_where_LE_id(tcp_connection* conn, const string& s_item_name, const int32_t& s_defense_power, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_541(?, ?, ?)");
        conn->execute(stmt.bind(s_item_name, s_defense_power, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_item_name_N_defense_power_where_GT_id(tcp_connection* conn, const string& s_item_name, const int32_t& s_defense_power, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_542(?, ?, ?)");
        conn->execute(stmt.bind(s_item_name, s_defense_power, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_item_name_N_defense_power_where_GE_id(tcp_connection* conn, const string& s_item_name, const int32_t& s_defense_power, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_543(?, ?, ?)");
        conn->execute(stmt.bind(s_item_name, s_defense_power, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_item_name_N_item_effect_where_EQ_id(tcp_connection* conn, const string& s_item_name, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_544(?, ?, ?)");
        conn->execute(stmt.bind(s_item_name, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_item_name_N_item_effect_where_LT_id(tcp_connection* conn, const string& s_item_name, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_545(?, ?, ?)");
        conn->execute(stmt.bind(s_item_name, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_item_name_N_item_effect_where_LE_id(tcp_connection* conn, const string& s_item_name, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_546(?, ?, ?)");
        conn->execute(stmt.bind(s_item_name, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_item_name_N_item_effect_where_GT_id(tcp_connection* conn, const string& s_item_name, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_547(?, ?, ?)");
        conn->execute(stmt.bind(s_item_name, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_item_name_N_item_effect_where_GE_id(tcp_connection* conn, const string& s_item_name, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_548(?, ?, ?)");
        conn->execute(stmt.bind(s_item_name, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_item_description_N_defense_power_where_EQ_id(tcp_connection* conn, const string& s_item_description, const int32_t& s_defense_power, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_549(?, ?, ?)");
        conn->execute(stmt.bind(s_item_description, s_defense_power, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_item_description_N_defense_power_where_LT_id(tcp_connection* conn, const string& s_item_description, const int32_t& s_defense_power, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_550(?, ?, ?)");
        conn->execute(stmt.bind(s_item_description, s_defense_power, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_item_description_N_defense_power_where_LE_id(tcp_connection* conn, const string& s_item_description, const int32_t& s_defense_power, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_551(?, ?, ?)");
        conn->execute(stmt.bind(s_item_description, s_defense_power, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_item_description_N_defense_power_where_GT_id(tcp_connection* conn, const string& s_item_description, const int32_t& s_defense_power, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_552(?, ?, ?)");
        conn->execute(stmt.bind(s_item_description, s_defense_power, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_item_description_N_defense_power_where_GE_id(tcp_connection* conn, const string& s_item_description, const int32_t& s_defense_power, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_553(?, ?, ?)");
        conn->execute(stmt.bind(s_item_description, s_defense_power, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_item_description_N_item_effect_where_EQ_id(tcp_connection* conn, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_554(?, ?, ?)");
        conn->execute(stmt.bind(s_item_description, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_item_description_N_item_effect_where_LT_id(tcp_connection* conn, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_555(?, ?, ?)");
        conn->execute(stmt.bind(s_item_description, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_item_description_N_item_effect_where_LE_id(tcp_connection* conn, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_556(?, ?, ?)");
        conn->execute(stmt.bind(s_item_description, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_item_description_N_item_effect_where_GT_id(tcp_connection* conn, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_557(?, ?, ?)");
        conn->execute(stmt.bind(s_item_description, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_item_description_N_item_effect_where_GE_id(tcp_connection* conn, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_558(?, ?, ?)");
        conn->execute(stmt.bind(s_item_description, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_defense_power_N_item_effect_where_EQ_id(tcp_connection* conn, const int32_t& s_defense_power, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_559(?, ?, ?)");
        conn->execute(stmt.bind(s_defense_power, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_defense_power_N_item_effect_where_LT_id(tcp_connection* conn, const int32_t& s_defense_power, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_560(?, ?, ?)");
        conn->execute(stmt.bind(s_defense_power, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_defense_power_N_item_effect_where_LE_id(tcp_connection* conn, const int32_t& s_defense_power, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_561(?, ?, ?)");
        conn->execute(stmt.bind(s_defense_power, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_defense_power_N_item_effect_where_GT_id(tcp_connection* conn, const int32_t& s_defense_power, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_562(?, ?, ?)");
        conn->execute(stmt.bind(s_defense_power, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_defense_power_N_item_effect_where_GE_id(tcp_connection* conn, const int32_t& s_defense_power, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_563(?, ?, ?)");
        conn->execute(stmt.bind(s_defense_power, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_id_N_item_name_N_item_description_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_564(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, s_item_description, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_id_N_item_name_N_item_description_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_565(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, s_item_description, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_id_N_item_name_N_item_description_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_566(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, s_item_description, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_id_N_item_name_N_item_description_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_567(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, s_item_description, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_id_N_item_name_N_item_description_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_568(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, s_item_description, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_id_N_item_name_N_defense_power_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& s_defense_power, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_569(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, s_defense_power, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_id_N_item_name_N_defense_power_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& s_defense_power, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_570(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, s_defense_power, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_id_N_item_name_N_defense_power_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& s_defense_power, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_571(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, s_defense_power, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_id_N_item_name_N_defense_power_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& s_defense_power, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_572(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, s_defense_power, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_id_N_item_name_N_defense_power_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& s_defense_power, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_573(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, s_defense_power, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_id_N_item_name_N_item_effect_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_574(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_id_N_item_name_N_item_effect_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_575(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_id_N_item_name_N_item_effect_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_576(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_id_N_item_name_N_item_effect_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_577(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_id_N_item_name_N_item_effect_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_578(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_id_N_item_description_N_defense_power_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& s_defense_power, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_579(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_description, s_defense_power, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_id_N_item_description_N_defense_power_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& s_defense_power, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_580(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_description, s_defense_power, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_id_N_item_description_N_defense_power_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& s_defense_power, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_581(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_description, s_defense_power, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_id_N_item_description_N_defense_power_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& s_defense_power, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_582(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_description, s_defense_power, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_id_N_item_description_N_defense_power_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& s_defense_power, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_583(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_description, s_defense_power, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_id_N_item_description_N_item_effect_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_584(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_description, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_id_N_item_description_N_item_effect_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_585(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_description, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_id_N_item_description_N_item_effect_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_586(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_description, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_id_N_item_description_N_item_effect_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_587(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_description, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_id_N_item_description_N_item_effect_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_588(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_description, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_id_N_defense_power_N_item_effect_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const int32_t& s_defense_power, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_589(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_defense_power, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_id_N_defense_power_N_item_effect_where_LT_id(tcp_connection* conn, const int32_t& s_id, const int32_t& s_defense_power, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_590(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_defense_power, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_id_N_defense_power_N_item_effect_where_LE_id(tcp_connection* conn, const int32_t& s_id, const int32_t& s_defense_power, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_591(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_defense_power, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_id_N_defense_power_N_item_effect_where_GT_id(tcp_connection* conn, const int32_t& s_id, const int32_t& s_defense_power, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_592(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_defense_power, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_id_N_defense_power_N_item_effect_where_GE_id(tcp_connection* conn, const int32_t& s_id, const int32_t& s_defense_power, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_593(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_defense_power, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_item_name_N_item_description_N_defense_power_where_EQ_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& s_defense_power, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_594(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_item_name, s_item_description, s_defense_power, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_item_name_N_item_description_N_defense_power_where_LT_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& s_defense_power, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_595(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_item_name, s_item_description, s_defense_power, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_item_name_N_item_description_N_defense_power_where_LE_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& s_defense_power, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_596(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_item_name, s_item_description, s_defense_power, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_item_name_N_item_description_N_defense_power_where_GT_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& s_defense_power, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_597(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_item_name, s_item_description, s_defense_power, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_item_name_N_item_description_N_defense_power_where_GE_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& s_defense_power, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_598(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_item_name, s_item_description, s_defense_power, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_item_name_N_item_description_N_item_effect_where_EQ_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_599(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_item_name, s_item_description, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_item_name_N_item_description_N_item_effect_where_LT_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_600(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_item_name, s_item_description, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_item_name_N_item_description_N_item_effect_where_LE_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_601(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_item_name, s_item_description, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_item_name_N_item_description_N_item_effect_where_GT_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_602(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_item_name, s_item_description, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_item_name_N_item_description_N_item_effect_where_GE_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_603(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_item_name, s_item_description, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_item_name_N_defense_power_N_item_effect_where_EQ_id(tcp_connection* conn, const string& s_item_name, const int32_t& s_defense_power, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_604(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_item_name, s_defense_power, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_item_name_N_defense_power_N_item_effect_where_LT_id(tcp_connection* conn, const string& s_item_name, const int32_t& s_defense_power, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_605(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_item_name, s_defense_power, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_item_name_N_defense_power_N_item_effect_where_LE_id(tcp_connection* conn, const string& s_item_name, const int32_t& s_defense_power, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_606(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_item_name, s_defense_power, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_item_name_N_defense_power_N_item_effect_where_GT_id(tcp_connection* conn, const string& s_item_name, const int32_t& s_defense_power, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_607(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_item_name, s_defense_power, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_item_name_N_defense_power_N_item_effect_where_GE_id(tcp_connection* conn, const string& s_item_name, const int32_t& s_defense_power, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_608(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_item_name, s_defense_power, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_item_description_N_defense_power_N_item_effect_where_EQ_id(tcp_connection* conn, const string& s_item_description, const int32_t& s_defense_power, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_609(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_item_description, s_defense_power, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_item_description_N_defense_power_N_item_effect_where_LT_id(tcp_connection* conn, const string& s_item_description, const int32_t& s_defense_power, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_610(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_item_description, s_defense_power, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_item_description_N_defense_power_N_item_effect_where_LE_id(tcp_connection* conn, const string& s_item_description, const int32_t& s_defense_power, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_611(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_item_description, s_defense_power, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_item_description_N_defense_power_N_item_effect_where_GT_id(tcp_connection* conn, const string& s_item_description, const int32_t& s_defense_power, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_612(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_item_description, s_defense_power, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_item_description_N_defense_power_N_item_effect_where_GE_id(tcp_connection* conn, const string& s_item_description, const int32_t& s_defense_power, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_613(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_item_description, s_defense_power, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_id_N_item_name_N_item_description_N_defense_power_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& s_defense_power, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_614(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, s_item_description, s_defense_power, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_id_N_item_name_N_item_description_N_defense_power_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& s_defense_power, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_615(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, s_item_description, s_defense_power, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_id_N_item_name_N_item_description_N_defense_power_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& s_defense_power, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_616(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, s_item_description, s_defense_power, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_id_N_item_name_N_item_description_N_defense_power_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& s_defense_power, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_617(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, s_item_description, s_defense_power, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_id_N_item_name_N_item_description_N_defense_power_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& s_defense_power, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_618(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, s_item_description, s_defense_power, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_id_N_item_name_N_item_description_N_item_effect_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_619(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, s_item_description, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_id_N_item_name_N_item_description_N_item_effect_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_620(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, s_item_description, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_id_N_item_name_N_item_description_N_item_effect_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_621(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, s_item_description, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_id_N_item_name_N_item_description_N_item_effect_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_622(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, s_item_description, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_id_N_item_name_N_item_description_N_item_effect_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_623(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, s_item_description, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_id_N_item_name_N_defense_power_N_item_effect_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& s_defense_power, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_624(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, s_defense_power, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_id_N_item_name_N_defense_power_N_item_effect_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& s_defense_power, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_625(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, s_defense_power, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_id_N_item_name_N_defense_power_N_item_effect_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& s_defense_power, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_626(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, s_defense_power, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_id_N_item_name_N_defense_power_N_item_effect_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& s_defense_power, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_627(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, s_defense_power, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_id_N_item_name_N_defense_power_N_item_effect_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& s_defense_power, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_628(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, s_defense_power, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_id_N_item_description_N_defense_power_N_item_effect_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& s_defense_power, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_629(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_description, s_defense_power, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_id_N_item_description_N_defense_power_N_item_effect_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& s_defense_power, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_630(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_description, s_defense_power, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_id_N_item_description_N_defense_power_N_item_effect_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& s_defense_power, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_631(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_description, s_defense_power, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_id_N_item_description_N_defense_power_N_item_effect_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& s_defense_power, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_632(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_description, s_defense_power, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_id_N_item_description_N_defense_power_N_item_effect_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& s_defense_power, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_633(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_description, s_defense_power, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_item_name_N_item_description_N_defense_power_N_item_effect_where_EQ_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& s_defense_power, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_634(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_item_name, s_item_description, s_defense_power, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_item_name_N_item_description_N_defense_power_N_item_effect_where_LT_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& s_defense_power, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_635(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_item_name, s_item_description, s_defense_power, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_item_name_N_item_description_N_defense_power_N_item_effect_where_LE_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& s_defense_power, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_636(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_item_name, s_item_description, s_defense_power, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_item_name_N_item_description_N_defense_power_N_item_effect_where_GT_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& s_defense_power, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_637(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_item_name, s_item_description, s_defense_power, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_item_name_N_item_description_N_defense_power_N_item_effect_where_GE_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& s_defense_power, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_638(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_item_name, s_item_description, s_defense_power, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_id_N_item_name_N_item_description_N_defense_power_N_item_effect_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& s_defense_power, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_639(?, ?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, s_item_description, s_defense_power, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_id_N_item_name_N_item_description_N_defense_power_N_item_effect_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& s_defense_power, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_640(?, ?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, s_item_description, s_defense_power, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_id_N_item_name_N_item_description_N_defense_power_N_item_effect_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& s_defense_power, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_641(?, ?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, s_item_description, s_defense_power, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_id_N_item_name_N_item_description_N_defense_power_N_item_effect_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& s_defense_power, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_642(?, ?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, s_item_description, s_defense_power, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::update_item_armor_set_id_N_item_name_N_item_description_N_defense_power_N_item_effect_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& s_defense_power, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_643(?, ?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, s_item_description, s_defense_power, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::delete_from_item_armor_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_644(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::delete_from_item_armor_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_645(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::delete_from_item_armor_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_646(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::delete_from_item_armor_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_647(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_armor_orm::delete_from_item_armor_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_648(?)");
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
