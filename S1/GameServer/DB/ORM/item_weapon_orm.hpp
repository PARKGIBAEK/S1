
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

struct item_weapon
{
    int32_t id; // int
    string item_name; // varchar(64)
    string item_description; // text(65535)
    int32_t attack_power; // int
    int32_t item_effect; // int
};

BOOST_DESCRIBE_STRUCT(item_weapon, (), (id, item_name, item_description, attack_power, item_effect));

class item_weapon_orm
{
public:
    // SP 호출 선언
    static int insert_into_item_weapon_id_N_item_name(tcp_connection* conn, const int32_t& new_id, const string& new_item_name);
    static int insert_into_item_weapon_id_N_item_name_N_item_description(tcp_connection* conn, const int32_t& new_id, const string& new_item_name, const string& new_item_description);
    static int insert_into_item_weapon_id_N_item_name_N_attack_power(tcp_connection* conn, const int32_t& new_id, const string& new_item_name, const int32_t& new_attack_power);
    static int insert_into_item_weapon_id_N_item_name_N_item_effect(tcp_connection* conn, const int32_t& new_id, const string& new_item_name, const int32_t& new_item_effect);
    static int insert_into_item_weapon_id_N_item_name_N_item_description_N_attack_power(tcp_connection* conn, const int32_t& new_id, const string& new_item_name, const string& new_item_description, const int32_t& new_attack_power);
    static int insert_into_item_weapon_id_N_item_name_N_item_description_N_item_effect(tcp_connection* conn, const int32_t& new_id, const string& new_item_name, const string& new_item_description, const int32_t& new_item_effect);
    static int insert_into_item_weapon_id_N_item_name_N_attack_power_N_item_effect(tcp_connection* conn, const int32_t& new_id, const string& new_item_name, const int32_t& new_attack_power, const int32_t& new_item_effect);
    static int insert_into_item_weapon_id_N_item_name_N_item_description_N_attack_power_N_item_effect(tcp_connection* conn, const int32_t& new_id, const string& new_item_name, const string& new_item_description, const int32_t& new_attack_power, const int32_t& new_item_effect);
    static results select_id_from_item_weapon_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_from_item_weapon_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_from_item_weapon_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_from_item_weapon_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_from_item_weapon_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_from_item_weapon_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_from_item_weapon_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_from_item_weapon_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_from_item_weapon_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_from_item_weapon_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_description_from_item_weapon_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_description_from_item_weapon_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_description_from_item_weapon_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_description_from_item_weapon_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_description_from_item_weapon_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_attack_power_from_item_weapon_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_attack_power_from_item_weapon_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_attack_power_from_item_weapon_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_attack_power_from_item_weapon_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_attack_power_from_item_weapon_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_effect_from_item_weapon_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_effect_from_item_weapon_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_effect_from_item_weapon_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_effect_from_item_weapon_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_effect_from_item_weapon_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_name_from_item_weapon_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_name_from_item_weapon_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_name_from_item_weapon_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_name_from_item_weapon_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_name_from_item_weapon_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_description_from_item_weapon_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_description_from_item_weapon_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_description_from_item_weapon_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_description_from_item_weapon_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_description_from_item_weapon_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_attack_power_from_item_weapon_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_attack_power_from_item_weapon_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_attack_power_from_item_weapon_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_attack_power_from_item_weapon_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_attack_power_from_item_weapon_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_effect_from_item_weapon_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_effect_from_item_weapon_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_effect_from_item_weapon_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_effect_from_item_weapon_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_effect_from_item_weapon_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_N_item_description_from_item_weapon_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_N_item_description_from_item_weapon_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_N_item_description_from_item_weapon_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_N_item_description_from_item_weapon_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_N_item_description_from_item_weapon_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_N_attack_power_from_item_weapon_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_N_attack_power_from_item_weapon_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_N_attack_power_from_item_weapon_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_N_attack_power_from_item_weapon_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_N_attack_power_from_item_weapon_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_N_item_effect_from_item_weapon_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_N_item_effect_from_item_weapon_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_N_item_effect_from_item_weapon_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_N_item_effect_from_item_weapon_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_N_item_effect_from_item_weapon_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_description_N_attack_power_from_item_weapon_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_description_N_attack_power_from_item_weapon_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_description_N_attack_power_from_item_weapon_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_description_N_attack_power_from_item_weapon_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_description_N_attack_power_from_item_weapon_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_description_N_item_effect_from_item_weapon_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_description_N_item_effect_from_item_weapon_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_description_N_item_effect_from_item_weapon_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_description_N_item_effect_from_item_weapon_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_description_N_item_effect_from_item_weapon_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_attack_power_N_item_effect_from_item_weapon_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_attack_power_N_item_effect_from_item_weapon_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_attack_power_N_item_effect_from_item_weapon_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_attack_power_N_item_effect_from_item_weapon_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_attack_power_N_item_effect_from_item_weapon_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_name_N_item_description_from_item_weapon_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_name_N_item_description_from_item_weapon_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_name_N_item_description_from_item_weapon_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_name_N_item_description_from_item_weapon_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_name_N_item_description_from_item_weapon_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_name_N_attack_power_from_item_weapon_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_name_N_attack_power_from_item_weapon_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_name_N_attack_power_from_item_weapon_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_name_N_attack_power_from_item_weapon_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_name_N_attack_power_from_item_weapon_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_name_N_item_effect_from_item_weapon_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_name_N_item_effect_from_item_weapon_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_name_N_item_effect_from_item_weapon_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_name_N_item_effect_from_item_weapon_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_name_N_item_effect_from_item_weapon_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_description_N_attack_power_from_item_weapon_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_description_N_attack_power_from_item_weapon_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_description_N_attack_power_from_item_weapon_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_description_N_attack_power_from_item_weapon_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_description_N_attack_power_from_item_weapon_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_description_N_item_effect_from_item_weapon_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_description_N_item_effect_from_item_weapon_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_description_N_item_effect_from_item_weapon_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_description_N_item_effect_from_item_weapon_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_description_N_item_effect_from_item_weapon_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_attack_power_N_item_effect_from_item_weapon_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_attack_power_N_item_effect_from_item_weapon_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_attack_power_N_item_effect_from_item_weapon_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_attack_power_N_item_effect_from_item_weapon_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_attack_power_N_item_effect_from_item_weapon_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_N_item_description_N_attack_power_from_item_weapon_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_N_item_description_N_attack_power_from_item_weapon_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_N_item_description_N_attack_power_from_item_weapon_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_N_item_description_N_attack_power_from_item_weapon_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_N_item_description_N_attack_power_from_item_weapon_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_N_item_description_N_item_effect_from_item_weapon_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_N_item_description_N_item_effect_from_item_weapon_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_N_item_description_N_item_effect_from_item_weapon_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_N_item_description_N_item_effect_from_item_weapon_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_N_item_description_N_item_effect_from_item_weapon_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_N_attack_power_N_item_effect_from_item_weapon_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_N_attack_power_N_item_effect_from_item_weapon_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_N_attack_power_N_item_effect_from_item_weapon_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_N_attack_power_N_item_effect_from_item_weapon_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_N_attack_power_N_item_effect_from_item_weapon_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_description_N_attack_power_N_item_effect_from_item_weapon_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_description_N_attack_power_N_item_effect_from_item_weapon_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_description_N_attack_power_N_item_effect_from_item_weapon_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_description_N_attack_power_N_item_effect_from_item_weapon_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_description_N_attack_power_N_item_effect_from_item_weapon_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_name_N_item_description_N_attack_power_from_item_weapon_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_name_N_item_description_N_attack_power_from_item_weapon_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_name_N_item_description_N_attack_power_from_item_weapon_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_name_N_item_description_N_attack_power_from_item_weapon_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_name_N_item_description_N_attack_power_from_item_weapon_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_name_N_item_description_N_item_effect_from_item_weapon_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_name_N_item_description_N_item_effect_from_item_weapon_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_name_N_item_description_N_item_effect_from_item_weapon_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_name_N_item_description_N_item_effect_from_item_weapon_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_name_N_item_description_N_item_effect_from_item_weapon_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_name_N_attack_power_N_item_effect_from_item_weapon_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_name_N_attack_power_N_item_effect_from_item_weapon_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_name_N_attack_power_N_item_effect_from_item_weapon_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_name_N_attack_power_N_item_effect_from_item_weapon_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_name_N_attack_power_N_item_effect_from_item_weapon_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_description_N_attack_power_N_item_effect_from_item_weapon_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_description_N_attack_power_N_item_effect_from_item_weapon_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_description_N_attack_power_N_item_effect_from_item_weapon_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_description_N_attack_power_N_item_effect_from_item_weapon_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_id_N_item_description_N_attack_power_N_item_effect_from_item_weapon_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_N_item_description_N_attack_power_N_item_effect_from_item_weapon_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_N_item_description_N_attack_power_N_item_effect_from_item_weapon_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_N_item_description_N_attack_power_N_item_effect_from_item_weapon_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_N_item_description_N_attack_power_N_item_effect_from_item_weapon_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_item_name_N_item_description_N_attack_power_N_item_effect_from_item_weapon_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_all_from_item_weapon_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static results select_all_from_item_weapon_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_all_from_item_weapon_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static results select_all_from_item_weapon_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static results select_all_from_item_weapon_where_GE_id(tcp_connection* conn, const int32_t& w_id);
    static int update_item_weapon_set_id_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const int32_t& w_id);
    static int update_item_weapon_set_id_where_LT_id(tcp_connection* conn, const int32_t& s_id, const int32_t& w_id);
    static int update_item_weapon_set_id_where_LE_id(tcp_connection* conn, const int32_t& s_id, const int32_t& w_id);
    static int update_item_weapon_set_id_where_GT_id(tcp_connection* conn, const int32_t& s_id, const int32_t& w_id);
    static int update_item_weapon_set_id_where_GE_id(tcp_connection* conn, const int32_t& s_id, const int32_t& w_id);
    static int update_item_weapon_set_item_name_where_EQ_id(tcp_connection* conn, const string& s_item_name, const int32_t& w_id);
    static int update_item_weapon_set_item_name_where_LT_id(tcp_connection* conn, const string& s_item_name, const int32_t& w_id);
    static int update_item_weapon_set_item_name_where_LE_id(tcp_connection* conn, const string& s_item_name, const int32_t& w_id);
    static int update_item_weapon_set_item_name_where_GT_id(tcp_connection* conn, const string& s_item_name, const int32_t& w_id);
    static int update_item_weapon_set_item_name_where_GE_id(tcp_connection* conn, const string& s_item_name, const int32_t& w_id);
    static int update_item_weapon_set_item_description_where_EQ_id(tcp_connection* conn, const string& s_item_description, const int32_t& w_id);
    static int update_item_weapon_set_item_description_where_LT_id(tcp_connection* conn, const string& s_item_description, const int32_t& w_id);
    static int update_item_weapon_set_item_description_where_LE_id(tcp_connection* conn, const string& s_item_description, const int32_t& w_id);
    static int update_item_weapon_set_item_description_where_GT_id(tcp_connection* conn, const string& s_item_description, const int32_t& w_id);
    static int update_item_weapon_set_item_description_where_GE_id(tcp_connection* conn, const string& s_item_description, const int32_t& w_id);
    static int update_item_weapon_set_attack_power_where_EQ_id(tcp_connection* conn, const int32_t& s_attack_power, const int32_t& w_id);
    static int update_item_weapon_set_attack_power_where_LT_id(tcp_connection* conn, const int32_t& s_attack_power, const int32_t& w_id);
    static int update_item_weapon_set_attack_power_where_LE_id(tcp_connection* conn, const int32_t& s_attack_power, const int32_t& w_id);
    static int update_item_weapon_set_attack_power_where_GT_id(tcp_connection* conn, const int32_t& s_attack_power, const int32_t& w_id);
    static int update_item_weapon_set_attack_power_where_GE_id(tcp_connection* conn, const int32_t& s_attack_power, const int32_t& w_id);
    static int update_item_weapon_set_item_effect_where_EQ_id(tcp_connection* conn, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_weapon_set_item_effect_where_LT_id(tcp_connection* conn, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_weapon_set_item_effect_where_LE_id(tcp_connection* conn, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_weapon_set_item_effect_where_GT_id(tcp_connection* conn, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_weapon_set_item_effect_where_GE_id(tcp_connection* conn, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_weapon_set_id_N_item_name_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& w_id);
    static int update_item_weapon_set_id_N_item_name_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& w_id);
    static int update_item_weapon_set_id_N_item_name_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& w_id);
    static int update_item_weapon_set_id_N_item_name_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& w_id);
    static int update_item_weapon_set_id_N_item_name_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& w_id);
    static int update_item_weapon_set_id_N_item_description_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& w_id);
    static int update_item_weapon_set_id_N_item_description_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& w_id);
    static int update_item_weapon_set_id_N_item_description_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& w_id);
    static int update_item_weapon_set_id_N_item_description_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& w_id);
    static int update_item_weapon_set_id_N_item_description_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& w_id);
    static int update_item_weapon_set_id_N_attack_power_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const int32_t& s_attack_power, const int32_t& w_id);
    static int update_item_weapon_set_id_N_attack_power_where_LT_id(tcp_connection* conn, const int32_t& s_id, const int32_t& s_attack_power, const int32_t& w_id);
    static int update_item_weapon_set_id_N_attack_power_where_LE_id(tcp_connection* conn, const int32_t& s_id, const int32_t& s_attack_power, const int32_t& w_id);
    static int update_item_weapon_set_id_N_attack_power_where_GT_id(tcp_connection* conn, const int32_t& s_id, const int32_t& s_attack_power, const int32_t& w_id);
    static int update_item_weapon_set_id_N_attack_power_where_GE_id(tcp_connection* conn, const int32_t& s_id, const int32_t& s_attack_power, const int32_t& w_id);
    static int update_item_weapon_set_id_N_item_effect_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_weapon_set_id_N_item_effect_where_LT_id(tcp_connection* conn, const int32_t& s_id, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_weapon_set_id_N_item_effect_where_LE_id(tcp_connection* conn, const int32_t& s_id, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_weapon_set_id_N_item_effect_where_GT_id(tcp_connection* conn, const int32_t& s_id, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_weapon_set_id_N_item_effect_where_GE_id(tcp_connection* conn, const int32_t& s_id, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_weapon_set_item_name_N_item_description_where_EQ_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& w_id);
    static int update_item_weapon_set_item_name_N_item_description_where_LT_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& w_id);
    static int update_item_weapon_set_item_name_N_item_description_where_LE_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& w_id);
    static int update_item_weapon_set_item_name_N_item_description_where_GT_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& w_id);
    static int update_item_weapon_set_item_name_N_item_description_where_GE_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& w_id);
    static int update_item_weapon_set_item_name_N_attack_power_where_EQ_id(tcp_connection* conn, const string& s_item_name, const int32_t& s_attack_power, const int32_t& w_id);
    static int update_item_weapon_set_item_name_N_attack_power_where_LT_id(tcp_connection* conn, const string& s_item_name, const int32_t& s_attack_power, const int32_t& w_id);
    static int update_item_weapon_set_item_name_N_attack_power_where_LE_id(tcp_connection* conn, const string& s_item_name, const int32_t& s_attack_power, const int32_t& w_id);
    static int update_item_weapon_set_item_name_N_attack_power_where_GT_id(tcp_connection* conn, const string& s_item_name, const int32_t& s_attack_power, const int32_t& w_id);
    static int update_item_weapon_set_item_name_N_attack_power_where_GE_id(tcp_connection* conn, const string& s_item_name, const int32_t& s_attack_power, const int32_t& w_id);
    static int update_item_weapon_set_item_name_N_item_effect_where_EQ_id(tcp_connection* conn, const string& s_item_name, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_weapon_set_item_name_N_item_effect_where_LT_id(tcp_connection* conn, const string& s_item_name, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_weapon_set_item_name_N_item_effect_where_LE_id(tcp_connection* conn, const string& s_item_name, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_weapon_set_item_name_N_item_effect_where_GT_id(tcp_connection* conn, const string& s_item_name, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_weapon_set_item_name_N_item_effect_where_GE_id(tcp_connection* conn, const string& s_item_name, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_weapon_set_item_description_N_attack_power_where_EQ_id(tcp_connection* conn, const string& s_item_description, const int32_t& s_attack_power, const int32_t& w_id);
    static int update_item_weapon_set_item_description_N_attack_power_where_LT_id(tcp_connection* conn, const string& s_item_description, const int32_t& s_attack_power, const int32_t& w_id);
    static int update_item_weapon_set_item_description_N_attack_power_where_LE_id(tcp_connection* conn, const string& s_item_description, const int32_t& s_attack_power, const int32_t& w_id);
    static int update_item_weapon_set_item_description_N_attack_power_where_GT_id(tcp_connection* conn, const string& s_item_description, const int32_t& s_attack_power, const int32_t& w_id);
    static int update_item_weapon_set_item_description_N_attack_power_where_GE_id(tcp_connection* conn, const string& s_item_description, const int32_t& s_attack_power, const int32_t& w_id);
    static int update_item_weapon_set_item_description_N_item_effect_where_EQ_id(tcp_connection* conn, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_weapon_set_item_description_N_item_effect_where_LT_id(tcp_connection* conn, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_weapon_set_item_description_N_item_effect_where_LE_id(tcp_connection* conn, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_weapon_set_item_description_N_item_effect_where_GT_id(tcp_connection* conn, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_weapon_set_item_description_N_item_effect_where_GE_id(tcp_connection* conn, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_weapon_set_attack_power_N_item_effect_where_EQ_id(tcp_connection* conn, const int32_t& s_attack_power, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_weapon_set_attack_power_N_item_effect_where_LT_id(tcp_connection* conn, const int32_t& s_attack_power, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_weapon_set_attack_power_N_item_effect_where_LE_id(tcp_connection* conn, const int32_t& s_attack_power, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_weapon_set_attack_power_N_item_effect_where_GT_id(tcp_connection* conn, const int32_t& s_attack_power, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_weapon_set_attack_power_N_item_effect_where_GE_id(tcp_connection* conn, const int32_t& s_attack_power, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_weapon_set_id_N_item_name_N_item_description_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& w_id);
    static int update_item_weapon_set_id_N_item_name_N_item_description_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& w_id);
    static int update_item_weapon_set_id_N_item_name_N_item_description_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& w_id);
    static int update_item_weapon_set_id_N_item_name_N_item_description_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& w_id);
    static int update_item_weapon_set_id_N_item_name_N_item_description_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& w_id);
    static int update_item_weapon_set_id_N_item_name_N_attack_power_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& s_attack_power, const int32_t& w_id);
    static int update_item_weapon_set_id_N_item_name_N_attack_power_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& s_attack_power, const int32_t& w_id);
    static int update_item_weapon_set_id_N_item_name_N_attack_power_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& s_attack_power, const int32_t& w_id);
    static int update_item_weapon_set_id_N_item_name_N_attack_power_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& s_attack_power, const int32_t& w_id);
    static int update_item_weapon_set_id_N_item_name_N_attack_power_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& s_attack_power, const int32_t& w_id);
    static int update_item_weapon_set_id_N_item_name_N_item_effect_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_weapon_set_id_N_item_name_N_item_effect_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_weapon_set_id_N_item_name_N_item_effect_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_weapon_set_id_N_item_name_N_item_effect_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_weapon_set_id_N_item_name_N_item_effect_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_weapon_set_id_N_item_description_N_attack_power_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& s_attack_power, const int32_t& w_id);
    static int update_item_weapon_set_id_N_item_description_N_attack_power_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& s_attack_power, const int32_t& w_id);
    static int update_item_weapon_set_id_N_item_description_N_attack_power_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& s_attack_power, const int32_t& w_id);
    static int update_item_weapon_set_id_N_item_description_N_attack_power_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& s_attack_power, const int32_t& w_id);
    static int update_item_weapon_set_id_N_item_description_N_attack_power_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& s_attack_power, const int32_t& w_id);
    static int update_item_weapon_set_id_N_item_description_N_item_effect_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_weapon_set_id_N_item_description_N_item_effect_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_weapon_set_id_N_item_description_N_item_effect_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_weapon_set_id_N_item_description_N_item_effect_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_weapon_set_id_N_item_description_N_item_effect_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_weapon_set_id_N_attack_power_N_item_effect_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const int32_t& s_attack_power, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_weapon_set_id_N_attack_power_N_item_effect_where_LT_id(tcp_connection* conn, const int32_t& s_id, const int32_t& s_attack_power, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_weapon_set_id_N_attack_power_N_item_effect_where_LE_id(tcp_connection* conn, const int32_t& s_id, const int32_t& s_attack_power, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_weapon_set_id_N_attack_power_N_item_effect_where_GT_id(tcp_connection* conn, const int32_t& s_id, const int32_t& s_attack_power, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_weapon_set_id_N_attack_power_N_item_effect_where_GE_id(tcp_connection* conn, const int32_t& s_id, const int32_t& s_attack_power, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_weapon_set_item_name_N_item_description_N_attack_power_where_EQ_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& s_attack_power, const int32_t& w_id);
    static int update_item_weapon_set_item_name_N_item_description_N_attack_power_where_LT_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& s_attack_power, const int32_t& w_id);
    static int update_item_weapon_set_item_name_N_item_description_N_attack_power_where_LE_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& s_attack_power, const int32_t& w_id);
    static int update_item_weapon_set_item_name_N_item_description_N_attack_power_where_GT_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& s_attack_power, const int32_t& w_id);
    static int update_item_weapon_set_item_name_N_item_description_N_attack_power_where_GE_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& s_attack_power, const int32_t& w_id);
    static int update_item_weapon_set_item_name_N_item_description_N_item_effect_where_EQ_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_weapon_set_item_name_N_item_description_N_item_effect_where_LT_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_weapon_set_item_name_N_item_description_N_item_effect_where_LE_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_weapon_set_item_name_N_item_description_N_item_effect_where_GT_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_weapon_set_item_name_N_item_description_N_item_effect_where_GE_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_weapon_set_item_name_N_attack_power_N_item_effect_where_EQ_id(tcp_connection* conn, const string& s_item_name, const int32_t& s_attack_power, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_weapon_set_item_name_N_attack_power_N_item_effect_where_LT_id(tcp_connection* conn, const string& s_item_name, const int32_t& s_attack_power, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_weapon_set_item_name_N_attack_power_N_item_effect_where_LE_id(tcp_connection* conn, const string& s_item_name, const int32_t& s_attack_power, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_weapon_set_item_name_N_attack_power_N_item_effect_where_GT_id(tcp_connection* conn, const string& s_item_name, const int32_t& s_attack_power, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_weapon_set_item_name_N_attack_power_N_item_effect_where_GE_id(tcp_connection* conn, const string& s_item_name, const int32_t& s_attack_power, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_weapon_set_item_description_N_attack_power_N_item_effect_where_EQ_id(tcp_connection* conn, const string& s_item_description, const int32_t& s_attack_power, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_weapon_set_item_description_N_attack_power_N_item_effect_where_LT_id(tcp_connection* conn, const string& s_item_description, const int32_t& s_attack_power, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_weapon_set_item_description_N_attack_power_N_item_effect_where_LE_id(tcp_connection* conn, const string& s_item_description, const int32_t& s_attack_power, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_weapon_set_item_description_N_attack_power_N_item_effect_where_GT_id(tcp_connection* conn, const string& s_item_description, const int32_t& s_attack_power, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_weapon_set_item_description_N_attack_power_N_item_effect_where_GE_id(tcp_connection* conn, const string& s_item_description, const int32_t& s_attack_power, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_weapon_set_id_N_item_name_N_item_description_N_attack_power_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& s_attack_power, const int32_t& w_id);
    static int update_item_weapon_set_id_N_item_name_N_item_description_N_attack_power_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& s_attack_power, const int32_t& w_id);
    static int update_item_weapon_set_id_N_item_name_N_item_description_N_attack_power_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& s_attack_power, const int32_t& w_id);
    static int update_item_weapon_set_id_N_item_name_N_item_description_N_attack_power_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& s_attack_power, const int32_t& w_id);
    static int update_item_weapon_set_id_N_item_name_N_item_description_N_attack_power_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& s_attack_power, const int32_t& w_id);
    static int update_item_weapon_set_id_N_item_name_N_item_description_N_item_effect_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_weapon_set_id_N_item_name_N_item_description_N_item_effect_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_weapon_set_id_N_item_name_N_item_description_N_item_effect_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_weapon_set_id_N_item_name_N_item_description_N_item_effect_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_weapon_set_id_N_item_name_N_item_description_N_item_effect_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_weapon_set_id_N_item_name_N_attack_power_N_item_effect_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& s_attack_power, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_weapon_set_id_N_item_name_N_attack_power_N_item_effect_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& s_attack_power, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_weapon_set_id_N_item_name_N_attack_power_N_item_effect_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& s_attack_power, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_weapon_set_id_N_item_name_N_attack_power_N_item_effect_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& s_attack_power, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_weapon_set_id_N_item_name_N_attack_power_N_item_effect_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& s_attack_power, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_weapon_set_id_N_item_description_N_attack_power_N_item_effect_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& s_attack_power, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_weapon_set_id_N_item_description_N_attack_power_N_item_effect_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& s_attack_power, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_weapon_set_id_N_item_description_N_attack_power_N_item_effect_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& s_attack_power, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_weapon_set_id_N_item_description_N_attack_power_N_item_effect_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& s_attack_power, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_weapon_set_id_N_item_description_N_attack_power_N_item_effect_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& s_attack_power, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_weapon_set_item_name_N_item_description_N_attack_power_N_item_effect_where_EQ_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& s_attack_power, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_weapon_set_item_name_N_item_description_N_attack_power_N_item_effect_where_LT_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& s_attack_power, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_weapon_set_item_name_N_item_description_N_attack_power_N_item_effect_where_LE_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& s_attack_power, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_weapon_set_item_name_N_item_description_N_attack_power_N_item_effect_where_GT_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& s_attack_power, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_weapon_set_item_name_N_item_description_N_attack_power_N_item_effect_where_GE_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& s_attack_power, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_weapon_set_id_N_item_name_N_item_description_N_attack_power_N_item_effect_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& s_attack_power, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_weapon_set_id_N_item_name_N_item_description_N_attack_power_N_item_effect_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& s_attack_power, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_weapon_set_id_N_item_name_N_item_description_N_attack_power_N_item_effect_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& s_attack_power, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_weapon_set_id_N_item_name_N_item_description_N_attack_power_N_item_effect_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& s_attack_power, const int32_t& s_item_effect, const int32_t& w_id);
    static int update_item_weapon_set_id_N_item_name_N_item_description_N_attack_power_N_item_effect_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& s_attack_power, const int32_t& s_item_effect, const int32_t& w_id);
    static int delete_from_item_weapon_where_EQ_id(tcp_connection* conn, const int32_t& w_id);
    static int delete_from_item_weapon_where_LT_id(tcp_connection* conn, const int32_t& w_id);
    static int delete_from_item_weapon_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static int delete_from_item_weapon_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static int delete_from_item_weapon_where_GE_id(tcp_connection* conn, const int32_t& w_id);
};

// SP 호출 구현

inline int item_weapon_orm::insert_into_item_weapon_id_N_item_name(tcp_connection* conn, const int32_t& new_id, const string& new_item_name)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_649(?, ?)");
        conn->execute(stmt.bind(new_id, new_item_name), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return -1;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::insert_into_item_weapon_id_N_item_name_N_item_description(tcp_connection* conn, const int32_t& new_id, const string& new_item_name, const string& new_item_description)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_650(?, ?, ?)");
        conn->execute(stmt.bind(new_id, new_item_name, new_item_description), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return -1;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::insert_into_item_weapon_id_N_item_name_N_attack_power(tcp_connection* conn, const int32_t& new_id, const string& new_item_name, const int32_t& new_attack_power)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_651(?, ?, ?)");
        conn->execute(stmt.bind(new_id, new_item_name, new_attack_power), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return -1;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::insert_into_item_weapon_id_N_item_name_N_item_effect(tcp_connection* conn, const int32_t& new_id, const string& new_item_name, const int32_t& new_item_effect)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_652(?, ?, ?)");
        conn->execute(stmt.bind(new_id, new_item_name, new_item_effect), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return -1;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::insert_into_item_weapon_id_N_item_name_N_item_description_N_attack_power(tcp_connection* conn, const int32_t& new_id, const string& new_item_name, const string& new_item_description, const int32_t& new_attack_power)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_653(?, ?, ?, ?)");
        conn->execute(stmt.bind(new_id, new_item_name, new_item_description, new_attack_power), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return -1;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::insert_into_item_weapon_id_N_item_name_N_item_description_N_item_effect(tcp_connection* conn, const int32_t& new_id, const string& new_item_name, const string& new_item_description, const int32_t& new_item_effect)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_654(?, ?, ?, ?)");
        conn->execute(stmt.bind(new_id, new_item_name, new_item_description, new_item_effect), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return -1;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::insert_into_item_weapon_id_N_item_name_N_attack_power_N_item_effect(tcp_connection* conn, const int32_t& new_id, const string& new_item_name, const int32_t& new_attack_power, const int32_t& new_item_effect)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_655(?, ?, ?, ?)");
        conn->execute(stmt.bind(new_id, new_item_name, new_attack_power, new_item_effect), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return -1;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::insert_into_item_weapon_id_N_item_name_N_item_description_N_attack_power_N_item_effect(tcp_connection* conn, const int32_t& new_id, const string& new_item_name, const string& new_item_description, const int32_t& new_attack_power, const int32_t& new_item_effect)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_656(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(new_id, new_item_name, new_item_description, new_attack_power, new_item_effect), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return -1;
    }

    return result.affected_rows();
}

    
inline results item_weapon_orm::select_id_from_item_weapon_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_657(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_id_from_item_weapon_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_658(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_id_from_item_weapon_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_659(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_id_from_item_weapon_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_660(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_id_from_item_weapon_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_661(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_item_name_from_item_weapon_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_662(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_item_name_from_item_weapon_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_663(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_item_name_from_item_weapon_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_664(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_item_name_from_item_weapon_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_665(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_item_name_from_item_weapon_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_666(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_item_description_from_item_weapon_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_667(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_item_description_from_item_weapon_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_668(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_item_description_from_item_weapon_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_669(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_item_description_from_item_weapon_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_670(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_item_description_from_item_weapon_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_671(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_attack_power_from_item_weapon_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_672(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_attack_power_from_item_weapon_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_673(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_attack_power_from_item_weapon_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_674(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_attack_power_from_item_weapon_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_675(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_attack_power_from_item_weapon_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_676(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_item_effect_from_item_weapon_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_677(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_item_effect_from_item_weapon_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_678(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_item_effect_from_item_weapon_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_679(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_item_effect_from_item_weapon_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_680(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_item_effect_from_item_weapon_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_681(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_id_N_item_name_from_item_weapon_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_682(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_id_N_item_name_from_item_weapon_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_683(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_id_N_item_name_from_item_weapon_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_684(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_id_N_item_name_from_item_weapon_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_685(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_id_N_item_name_from_item_weapon_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_686(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_id_N_item_description_from_item_weapon_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_687(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_id_N_item_description_from_item_weapon_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_688(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_id_N_item_description_from_item_weapon_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_689(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_id_N_item_description_from_item_weapon_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_690(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_id_N_item_description_from_item_weapon_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_691(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_id_N_attack_power_from_item_weapon_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_692(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_id_N_attack_power_from_item_weapon_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_693(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_id_N_attack_power_from_item_weapon_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_694(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_id_N_attack_power_from_item_weapon_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_695(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_id_N_attack_power_from_item_weapon_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_696(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_id_N_item_effect_from_item_weapon_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_697(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_id_N_item_effect_from_item_weapon_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_698(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_id_N_item_effect_from_item_weapon_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_699(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_id_N_item_effect_from_item_weapon_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_700(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_id_N_item_effect_from_item_weapon_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_701(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_item_name_N_item_description_from_item_weapon_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_702(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_item_name_N_item_description_from_item_weapon_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_703(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_item_name_N_item_description_from_item_weapon_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_704(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_item_name_N_item_description_from_item_weapon_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_705(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_item_name_N_item_description_from_item_weapon_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_706(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_item_name_N_attack_power_from_item_weapon_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_707(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_item_name_N_attack_power_from_item_weapon_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_708(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_item_name_N_attack_power_from_item_weapon_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_709(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_item_name_N_attack_power_from_item_weapon_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_710(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_item_name_N_attack_power_from_item_weapon_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_711(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_item_name_N_item_effect_from_item_weapon_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_712(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_item_name_N_item_effect_from_item_weapon_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_713(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_item_name_N_item_effect_from_item_weapon_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_714(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_item_name_N_item_effect_from_item_weapon_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_715(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_item_name_N_item_effect_from_item_weapon_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_716(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_item_description_N_attack_power_from_item_weapon_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_717(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_item_description_N_attack_power_from_item_weapon_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_718(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_item_description_N_attack_power_from_item_weapon_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_719(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_item_description_N_attack_power_from_item_weapon_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_720(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_item_description_N_attack_power_from_item_weapon_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_721(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_item_description_N_item_effect_from_item_weapon_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_722(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_item_description_N_item_effect_from_item_weapon_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_723(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_item_description_N_item_effect_from_item_weapon_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_724(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_item_description_N_item_effect_from_item_weapon_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_725(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_item_description_N_item_effect_from_item_weapon_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_726(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_attack_power_N_item_effect_from_item_weapon_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_727(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_attack_power_N_item_effect_from_item_weapon_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_728(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_attack_power_N_item_effect_from_item_weapon_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_729(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_attack_power_N_item_effect_from_item_weapon_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_730(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_attack_power_N_item_effect_from_item_weapon_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_731(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_id_N_item_name_N_item_description_from_item_weapon_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_732(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_id_N_item_name_N_item_description_from_item_weapon_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_733(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_id_N_item_name_N_item_description_from_item_weapon_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_734(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_id_N_item_name_N_item_description_from_item_weapon_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_735(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_id_N_item_name_N_item_description_from_item_weapon_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_736(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_id_N_item_name_N_attack_power_from_item_weapon_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_737(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_id_N_item_name_N_attack_power_from_item_weapon_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_738(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_id_N_item_name_N_attack_power_from_item_weapon_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_739(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_id_N_item_name_N_attack_power_from_item_weapon_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_740(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_id_N_item_name_N_attack_power_from_item_weapon_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_741(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_id_N_item_name_N_item_effect_from_item_weapon_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_742(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_id_N_item_name_N_item_effect_from_item_weapon_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_743(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_id_N_item_name_N_item_effect_from_item_weapon_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_744(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_id_N_item_name_N_item_effect_from_item_weapon_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_745(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_id_N_item_name_N_item_effect_from_item_weapon_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_746(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_id_N_item_description_N_attack_power_from_item_weapon_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_747(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_id_N_item_description_N_attack_power_from_item_weapon_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_748(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_id_N_item_description_N_attack_power_from_item_weapon_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_749(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_id_N_item_description_N_attack_power_from_item_weapon_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_750(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_id_N_item_description_N_attack_power_from_item_weapon_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_751(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_id_N_item_description_N_item_effect_from_item_weapon_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_752(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_id_N_item_description_N_item_effect_from_item_weapon_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_753(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_id_N_item_description_N_item_effect_from_item_weapon_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_754(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_id_N_item_description_N_item_effect_from_item_weapon_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_755(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_id_N_item_description_N_item_effect_from_item_weapon_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_756(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_id_N_attack_power_N_item_effect_from_item_weapon_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_757(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_id_N_attack_power_N_item_effect_from_item_weapon_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_758(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_id_N_attack_power_N_item_effect_from_item_weapon_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_759(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_id_N_attack_power_N_item_effect_from_item_weapon_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_760(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_id_N_attack_power_N_item_effect_from_item_weapon_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_761(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_item_name_N_item_description_N_attack_power_from_item_weapon_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_762(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_item_name_N_item_description_N_attack_power_from_item_weapon_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_763(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_item_name_N_item_description_N_attack_power_from_item_weapon_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_764(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_item_name_N_item_description_N_attack_power_from_item_weapon_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_765(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_item_name_N_item_description_N_attack_power_from_item_weapon_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_766(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_item_name_N_item_description_N_item_effect_from_item_weapon_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_767(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_item_name_N_item_description_N_item_effect_from_item_weapon_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_768(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_item_name_N_item_description_N_item_effect_from_item_weapon_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_769(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_item_name_N_item_description_N_item_effect_from_item_weapon_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_770(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_item_name_N_item_description_N_item_effect_from_item_weapon_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_771(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_item_name_N_attack_power_N_item_effect_from_item_weapon_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_772(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_item_name_N_attack_power_N_item_effect_from_item_weapon_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_773(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_item_name_N_attack_power_N_item_effect_from_item_weapon_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_774(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_item_name_N_attack_power_N_item_effect_from_item_weapon_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_775(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_item_name_N_attack_power_N_item_effect_from_item_weapon_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_776(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_item_description_N_attack_power_N_item_effect_from_item_weapon_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_777(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_item_description_N_attack_power_N_item_effect_from_item_weapon_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_778(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_item_description_N_attack_power_N_item_effect_from_item_weapon_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_779(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_item_description_N_attack_power_N_item_effect_from_item_weapon_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_780(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_item_description_N_attack_power_N_item_effect_from_item_weapon_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_781(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_id_N_item_name_N_item_description_N_attack_power_from_item_weapon_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_782(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_id_N_item_name_N_item_description_N_attack_power_from_item_weapon_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_783(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_id_N_item_name_N_item_description_N_attack_power_from_item_weapon_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_784(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_id_N_item_name_N_item_description_N_attack_power_from_item_weapon_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_785(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_id_N_item_name_N_item_description_N_attack_power_from_item_weapon_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_786(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_id_N_item_name_N_item_description_N_item_effect_from_item_weapon_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_787(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_id_N_item_name_N_item_description_N_item_effect_from_item_weapon_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_788(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_id_N_item_name_N_item_description_N_item_effect_from_item_weapon_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_789(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_id_N_item_name_N_item_description_N_item_effect_from_item_weapon_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_790(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_id_N_item_name_N_item_description_N_item_effect_from_item_weapon_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_791(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_id_N_item_name_N_attack_power_N_item_effect_from_item_weapon_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_792(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_id_N_item_name_N_attack_power_N_item_effect_from_item_weapon_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_793(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_id_N_item_name_N_attack_power_N_item_effect_from_item_weapon_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_794(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_id_N_item_name_N_attack_power_N_item_effect_from_item_weapon_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_795(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_id_N_item_name_N_attack_power_N_item_effect_from_item_weapon_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_796(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_id_N_item_description_N_attack_power_N_item_effect_from_item_weapon_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_797(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_id_N_item_description_N_attack_power_N_item_effect_from_item_weapon_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_798(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_id_N_item_description_N_attack_power_N_item_effect_from_item_weapon_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_799(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_id_N_item_description_N_attack_power_N_item_effect_from_item_weapon_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_800(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_id_N_item_description_N_attack_power_N_item_effect_from_item_weapon_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_801(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_item_name_N_item_description_N_attack_power_N_item_effect_from_item_weapon_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_802(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_item_name_N_item_description_N_attack_power_N_item_effect_from_item_weapon_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_803(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_item_name_N_item_description_N_attack_power_N_item_effect_from_item_weapon_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_804(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_item_name_N_item_description_N_attack_power_N_item_effect_from_item_weapon_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_805(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_item_name_N_item_description_N_attack_power_N_item_effect_from_item_weapon_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_806(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_all_from_item_weapon_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_807(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_all_from_item_weapon_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_808(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_all_from_item_weapon_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_809(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_all_from_item_weapon_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_810(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline results item_weapon_orm::select_all_from_item_weapon_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_811(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }

    return result;
}

    
inline int item_weapon_orm::update_item_weapon_set_id_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_812(?, ?)");
        conn->execute(stmt.bind(s_id, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_id_where_LT_id(tcp_connection* conn, const int32_t& s_id, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_813(?, ?)");
        conn->execute(stmt.bind(s_id, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_id_where_LE_id(tcp_connection* conn, const int32_t& s_id, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_814(?, ?)");
        conn->execute(stmt.bind(s_id, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_id_where_GT_id(tcp_connection* conn, const int32_t& s_id, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_815(?, ?)");
        conn->execute(stmt.bind(s_id, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_id_where_GE_id(tcp_connection* conn, const int32_t& s_id, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_816(?, ?)");
        conn->execute(stmt.bind(s_id, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_item_name_where_EQ_id(tcp_connection* conn, const string& s_item_name, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_817(?, ?)");
        conn->execute(stmt.bind(s_item_name, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_item_name_where_LT_id(tcp_connection* conn, const string& s_item_name, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_818(?, ?)");
        conn->execute(stmt.bind(s_item_name, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_item_name_where_LE_id(tcp_connection* conn, const string& s_item_name, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_819(?, ?)");
        conn->execute(stmt.bind(s_item_name, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_item_name_where_GT_id(tcp_connection* conn, const string& s_item_name, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_820(?, ?)");
        conn->execute(stmt.bind(s_item_name, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_item_name_where_GE_id(tcp_connection* conn, const string& s_item_name, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_821(?, ?)");
        conn->execute(stmt.bind(s_item_name, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_item_description_where_EQ_id(tcp_connection* conn, const string& s_item_description, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_822(?, ?)");
        conn->execute(stmt.bind(s_item_description, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_item_description_where_LT_id(tcp_connection* conn, const string& s_item_description, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_823(?, ?)");
        conn->execute(stmt.bind(s_item_description, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_item_description_where_LE_id(tcp_connection* conn, const string& s_item_description, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_824(?, ?)");
        conn->execute(stmt.bind(s_item_description, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_item_description_where_GT_id(tcp_connection* conn, const string& s_item_description, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_825(?, ?)");
        conn->execute(stmt.bind(s_item_description, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_item_description_where_GE_id(tcp_connection* conn, const string& s_item_description, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_826(?, ?)");
        conn->execute(stmt.bind(s_item_description, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_attack_power_where_EQ_id(tcp_connection* conn, const int32_t& s_attack_power, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_827(?, ?)");
        conn->execute(stmt.bind(s_attack_power, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_attack_power_where_LT_id(tcp_connection* conn, const int32_t& s_attack_power, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_828(?, ?)");
        conn->execute(stmt.bind(s_attack_power, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_attack_power_where_LE_id(tcp_connection* conn, const int32_t& s_attack_power, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_829(?, ?)");
        conn->execute(stmt.bind(s_attack_power, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_attack_power_where_GT_id(tcp_connection* conn, const int32_t& s_attack_power, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_830(?, ?)");
        conn->execute(stmt.bind(s_attack_power, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_attack_power_where_GE_id(tcp_connection* conn, const int32_t& s_attack_power, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_831(?, ?)");
        conn->execute(stmt.bind(s_attack_power, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_item_effect_where_EQ_id(tcp_connection* conn, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_832(?, ?)");
        conn->execute(stmt.bind(s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_item_effect_where_LT_id(tcp_connection* conn, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_833(?, ?)");
        conn->execute(stmt.bind(s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_item_effect_where_LE_id(tcp_connection* conn, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_834(?, ?)");
        conn->execute(stmt.bind(s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_item_effect_where_GT_id(tcp_connection* conn, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_835(?, ?)");
        conn->execute(stmt.bind(s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_item_effect_where_GE_id(tcp_connection* conn, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_836(?, ?)");
        conn->execute(stmt.bind(s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_id_N_item_name_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_837(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_id_N_item_name_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_838(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_id_N_item_name_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_839(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_id_N_item_name_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_840(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_id_N_item_name_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_841(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_id_N_item_description_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_842(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_description, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_id_N_item_description_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_843(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_description, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_id_N_item_description_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_844(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_description, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_id_N_item_description_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_845(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_description, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_id_N_item_description_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_846(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_description, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_id_N_attack_power_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const int32_t& s_attack_power, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_847(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_attack_power, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_id_N_attack_power_where_LT_id(tcp_connection* conn, const int32_t& s_id, const int32_t& s_attack_power, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_848(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_attack_power, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_id_N_attack_power_where_LE_id(tcp_connection* conn, const int32_t& s_id, const int32_t& s_attack_power, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_849(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_attack_power, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_id_N_attack_power_where_GT_id(tcp_connection* conn, const int32_t& s_id, const int32_t& s_attack_power, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_850(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_attack_power, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_id_N_attack_power_where_GE_id(tcp_connection* conn, const int32_t& s_id, const int32_t& s_attack_power, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_851(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_attack_power, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_id_N_item_effect_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_852(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_id_N_item_effect_where_LT_id(tcp_connection* conn, const int32_t& s_id, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_853(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_id_N_item_effect_where_LE_id(tcp_connection* conn, const int32_t& s_id, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_854(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_id_N_item_effect_where_GT_id(tcp_connection* conn, const int32_t& s_id, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_855(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_id_N_item_effect_where_GE_id(tcp_connection* conn, const int32_t& s_id, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_856(?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_item_name_N_item_description_where_EQ_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_857(?, ?, ?)");
        conn->execute(stmt.bind(s_item_name, s_item_description, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_item_name_N_item_description_where_LT_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_858(?, ?, ?)");
        conn->execute(stmt.bind(s_item_name, s_item_description, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_item_name_N_item_description_where_LE_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_859(?, ?, ?)");
        conn->execute(stmt.bind(s_item_name, s_item_description, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_item_name_N_item_description_where_GT_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_860(?, ?, ?)");
        conn->execute(stmt.bind(s_item_name, s_item_description, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_item_name_N_item_description_where_GE_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_861(?, ?, ?)");
        conn->execute(stmt.bind(s_item_name, s_item_description, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_item_name_N_attack_power_where_EQ_id(tcp_connection* conn, const string& s_item_name, const int32_t& s_attack_power, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_862(?, ?, ?)");
        conn->execute(stmt.bind(s_item_name, s_attack_power, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_item_name_N_attack_power_where_LT_id(tcp_connection* conn, const string& s_item_name, const int32_t& s_attack_power, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_863(?, ?, ?)");
        conn->execute(stmt.bind(s_item_name, s_attack_power, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_item_name_N_attack_power_where_LE_id(tcp_connection* conn, const string& s_item_name, const int32_t& s_attack_power, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_864(?, ?, ?)");
        conn->execute(stmt.bind(s_item_name, s_attack_power, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_item_name_N_attack_power_where_GT_id(tcp_connection* conn, const string& s_item_name, const int32_t& s_attack_power, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_865(?, ?, ?)");
        conn->execute(stmt.bind(s_item_name, s_attack_power, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_item_name_N_attack_power_where_GE_id(tcp_connection* conn, const string& s_item_name, const int32_t& s_attack_power, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_866(?, ?, ?)");
        conn->execute(stmt.bind(s_item_name, s_attack_power, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_item_name_N_item_effect_where_EQ_id(tcp_connection* conn, const string& s_item_name, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_867(?, ?, ?)");
        conn->execute(stmt.bind(s_item_name, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_item_name_N_item_effect_where_LT_id(tcp_connection* conn, const string& s_item_name, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_868(?, ?, ?)");
        conn->execute(stmt.bind(s_item_name, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_item_name_N_item_effect_where_LE_id(tcp_connection* conn, const string& s_item_name, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_869(?, ?, ?)");
        conn->execute(stmt.bind(s_item_name, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_item_name_N_item_effect_where_GT_id(tcp_connection* conn, const string& s_item_name, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_870(?, ?, ?)");
        conn->execute(stmt.bind(s_item_name, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_item_name_N_item_effect_where_GE_id(tcp_connection* conn, const string& s_item_name, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_871(?, ?, ?)");
        conn->execute(stmt.bind(s_item_name, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_item_description_N_attack_power_where_EQ_id(tcp_connection* conn, const string& s_item_description, const int32_t& s_attack_power, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_872(?, ?, ?)");
        conn->execute(stmt.bind(s_item_description, s_attack_power, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_item_description_N_attack_power_where_LT_id(tcp_connection* conn, const string& s_item_description, const int32_t& s_attack_power, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_873(?, ?, ?)");
        conn->execute(stmt.bind(s_item_description, s_attack_power, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_item_description_N_attack_power_where_LE_id(tcp_connection* conn, const string& s_item_description, const int32_t& s_attack_power, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_874(?, ?, ?)");
        conn->execute(stmt.bind(s_item_description, s_attack_power, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_item_description_N_attack_power_where_GT_id(tcp_connection* conn, const string& s_item_description, const int32_t& s_attack_power, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_875(?, ?, ?)");
        conn->execute(stmt.bind(s_item_description, s_attack_power, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_item_description_N_attack_power_where_GE_id(tcp_connection* conn, const string& s_item_description, const int32_t& s_attack_power, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_876(?, ?, ?)");
        conn->execute(stmt.bind(s_item_description, s_attack_power, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_item_description_N_item_effect_where_EQ_id(tcp_connection* conn, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_877(?, ?, ?)");
        conn->execute(stmt.bind(s_item_description, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_item_description_N_item_effect_where_LT_id(tcp_connection* conn, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_878(?, ?, ?)");
        conn->execute(stmt.bind(s_item_description, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_item_description_N_item_effect_where_LE_id(tcp_connection* conn, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_879(?, ?, ?)");
        conn->execute(stmt.bind(s_item_description, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_item_description_N_item_effect_where_GT_id(tcp_connection* conn, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_880(?, ?, ?)");
        conn->execute(stmt.bind(s_item_description, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_item_description_N_item_effect_where_GE_id(tcp_connection* conn, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_881(?, ?, ?)");
        conn->execute(stmt.bind(s_item_description, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_attack_power_N_item_effect_where_EQ_id(tcp_connection* conn, const int32_t& s_attack_power, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_882(?, ?, ?)");
        conn->execute(stmt.bind(s_attack_power, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_attack_power_N_item_effect_where_LT_id(tcp_connection* conn, const int32_t& s_attack_power, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_883(?, ?, ?)");
        conn->execute(stmt.bind(s_attack_power, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_attack_power_N_item_effect_where_LE_id(tcp_connection* conn, const int32_t& s_attack_power, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_884(?, ?, ?)");
        conn->execute(stmt.bind(s_attack_power, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_attack_power_N_item_effect_where_GT_id(tcp_connection* conn, const int32_t& s_attack_power, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_885(?, ?, ?)");
        conn->execute(stmt.bind(s_attack_power, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_attack_power_N_item_effect_where_GE_id(tcp_connection* conn, const int32_t& s_attack_power, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_886(?, ?, ?)");
        conn->execute(stmt.bind(s_attack_power, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_id_N_item_name_N_item_description_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_887(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, s_item_description, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_id_N_item_name_N_item_description_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_888(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, s_item_description, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_id_N_item_name_N_item_description_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_889(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, s_item_description, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_id_N_item_name_N_item_description_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_890(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, s_item_description, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_id_N_item_name_N_item_description_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_891(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, s_item_description, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_id_N_item_name_N_attack_power_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& s_attack_power, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_892(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, s_attack_power, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_id_N_item_name_N_attack_power_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& s_attack_power, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_893(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, s_attack_power, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_id_N_item_name_N_attack_power_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& s_attack_power, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_894(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, s_attack_power, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_id_N_item_name_N_attack_power_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& s_attack_power, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_895(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, s_attack_power, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_id_N_item_name_N_attack_power_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& s_attack_power, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_896(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, s_attack_power, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_id_N_item_name_N_item_effect_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_897(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_id_N_item_name_N_item_effect_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_898(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_id_N_item_name_N_item_effect_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_899(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_id_N_item_name_N_item_effect_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_900(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_id_N_item_name_N_item_effect_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_901(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_id_N_item_description_N_attack_power_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& s_attack_power, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_902(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_description, s_attack_power, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_id_N_item_description_N_attack_power_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& s_attack_power, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_903(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_description, s_attack_power, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_id_N_item_description_N_attack_power_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& s_attack_power, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_904(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_description, s_attack_power, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_id_N_item_description_N_attack_power_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& s_attack_power, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_905(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_description, s_attack_power, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_id_N_item_description_N_attack_power_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& s_attack_power, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_906(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_description, s_attack_power, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_id_N_item_description_N_item_effect_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_907(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_description, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_id_N_item_description_N_item_effect_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_908(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_description, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_id_N_item_description_N_item_effect_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_909(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_description, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_id_N_item_description_N_item_effect_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_910(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_description, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_id_N_item_description_N_item_effect_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_911(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_description, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_id_N_attack_power_N_item_effect_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const int32_t& s_attack_power, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_912(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_attack_power, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_id_N_attack_power_N_item_effect_where_LT_id(tcp_connection* conn, const int32_t& s_id, const int32_t& s_attack_power, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_913(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_attack_power, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_id_N_attack_power_N_item_effect_where_LE_id(tcp_connection* conn, const int32_t& s_id, const int32_t& s_attack_power, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_914(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_attack_power, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_id_N_attack_power_N_item_effect_where_GT_id(tcp_connection* conn, const int32_t& s_id, const int32_t& s_attack_power, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_915(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_attack_power, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_id_N_attack_power_N_item_effect_where_GE_id(tcp_connection* conn, const int32_t& s_id, const int32_t& s_attack_power, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_916(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_attack_power, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_item_name_N_item_description_N_attack_power_where_EQ_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& s_attack_power, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_917(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_item_name, s_item_description, s_attack_power, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_item_name_N_item_description_N_attack_power_where_LT_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& s_attack_power, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_918(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_item_name, s_item_description, s_attack_power, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_item_name_N_item_description_N_attack_power_where_LE_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& s_attack_power, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_919(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_item_name, s_item_description, s_attack_power, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_item_name_N_item_description_N_attack_power_where_GT_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& s_attack_power, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_920(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_item_name, s_item_description, s_attack_power, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_item_name_N_item_description_N_attack_power_where_GE_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& s_attack_power, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_921(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_item_name, s_item_description, s_attack_power, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_item_name_N_item_description_N_item_effect_where_EQ_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_922(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_item_name, s_item_description, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_item_name_N_item_description_N_item_effect_where_LT_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_923(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_item_name, s_item_description, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_item_name_N_item_description_N_item_effect_where_LE_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_924(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_item_name, s_item_description, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_item_name_N_item_description_N_item_effect_where_GT_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_925(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_item_name, s_item_description, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_item_name_N_item_description_N_item_effect_where_GE_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_926(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_item_name, s_item_description, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_item_name_N_attack_power_N_item_effect_where_EQ_id(tcp_connection* conn, const string& s_item_name, const int32_t& s_attack_power, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_927(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_item_name, s_attack_power, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_item_name_N_attack_power_N_item_effect_where_LT_id(tcp_connection* conn, const string& s_item_name, const int32_t& s_attack_power, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_928(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_item_name, s_attack_power, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_item_name_N_attack_power_N_item_effect_where_LE_id(tcp_connection* conn, const string& s_item_name, const int32_t& s_attack_power, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_929(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_item_name, s_attack_power, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_item_name_N_attack_power_N_item_effect_where_GT_id(tcp_connection* conn, const string& s_item_name, const int32_t& s_attack_power, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_930(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_item_name, s_attack_power, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_item_name_N_attack_power_N_item_effect_where_GE_id(tcp_connection* conn, const string& s_item_name, const int32_t& s_attack_power, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_931(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_item_name, s_attack_power, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_item_description_N_attack_power_N_item_effect_where_EQ_id(tcp_connection* conn, const string& s_item_description, const int32_t& s_attack_power, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_932(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_item_description, s_attack_power, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_item_description_N_attack_power_N_item_effect_where_LT_id(tcp_connection* conn, const string& s_item_description, const int32_t& s_attack_power, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_933(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_item_description, s_attack_power, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_item_description_N_attack_power_N_item_effect_where_LE_id(tcp_connection* conn, const string& s_item_description, const int32_t& s_attack_power, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_934(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_item_description, s_attack_power, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_item_description_N_attack_power_N_item_effect_where_GT_id(tcp_connection* conn, const string& s_item_description, const int32_t& s_attack_power, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_935(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_item_description, s_attack_power, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_item_description_N_attack_power_N_item_effect_where_GE_id(tcp_connection* conn, const string& s_item_description, const int32_t& s_attack_power, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_936(?, ?, ?, ?)");
        conn->execute(stmt.bind(s_item_description, s_attack_power, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_id_N_item_name_N_item_description_N_attack_power_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& s_attack_power, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_937(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, s_item_description, s_attack_power, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_id_N_item_name_N_item_description_N_attack_power_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& s_attack_power, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_938(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, s_item_description, s_attack_power, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_id_N_item_name_N_item_description_N_attack_power_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& s_attack_power, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_939(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, s_item_description, s_attack_power, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_id_N_item_name_N_item_description_N_attack_power_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& s_attack_power, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_940(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, s_item_description, s_attack_power, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_id_N_item_name_N_item_description_N_attack_power_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& s_attack_power, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_941(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, s_item_description, s_attack_power, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_id_N_item_name_N_item_description_N_item_effect_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_942(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, s_item_description, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_id_N_item_name_N_item_description_N_item_effect_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_943(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, s_item_description, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_id_N_item_name_N_item_description_N_item_effect_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_944(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, s_item_description, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_id_N_item_name_N_item_description_N_item_effect_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_945(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, s_item_description, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_id_N_item_name_N_item_description_N_item_effect_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_946(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, s_item_description, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_id_N_item_name_N_attack_power_N_item_effect_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& s_attack_power, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_947(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, s_attack_power, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_id_N_item_name_N_attack_power_N_item_effect_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& s_attack_power, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_948(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, s_attack_power, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_id_N_item_name_N_attack_power_N_item_effect_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& s_attack_power, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_949(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, s_attack_power, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_id_N_item_name_N_attack_power_N_item_effect_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& s_attack_power, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_950(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, s_attack_power, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_id_N_item_name_N_attack_power_N_item_effect_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const int32_t& s_attack_power, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_951(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, s_attack_power, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_id_N_item_description_N_attack_power_N_item_effect_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& s_attack_power, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_952(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_description, s_attack_power, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_id_N_item_description_N_attack_power_N_item_effect_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& s_attack_power, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_953(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_description, s_attack_power, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_id_N_item_description_N_attack_power_N_item_effect_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& s_attack_power, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_954(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_description, s_attack_power, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_id_N_item_description_N_attack_power_N_item_effect_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& s_attack_power, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_955(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_description, s_attack_power, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_id_N_item_description_N_attack_power_N_item_effect_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_description, const int32_t& s_attack_power, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_956(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_description, s_attack_power, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_item_name_N_item_description_N_attack_power_N_item_effect_where_EQ_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& s_attack_power, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_957(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_item_name, s_item_description, s_attack_power, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_item_name_N_item_description_N_attack_power_N_item_effect_where_LT_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& s_attack_power, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_958(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_item_name, s_item_description, s_attack_power, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_item_name_N_item_description_N_attack_power_N_item_effect_where_LE_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& s_attack_power, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_959(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_item_name, s_item_description, s_attack_power, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_item_name_N_item_description_N_attack_power_N_item_effect_where_GT_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& s_attack_power, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_960(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_item_name, s_item_description, s_attack_power, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_item_name_N_item_description_N_attack_power_N_item_effect_where_GE_id(tcp_connection* conn, const string& s_item_name, const string& s_item_description, const int32_t& s_attack_power, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_961(?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_item_name, s_item_description, s_attack_power, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_id_N_item_name_N_item_description_N_attack_power_N_item_effect_where_EQ_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& s_attack_power, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_962(?, ?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, s_item_description, s_attack_power, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_id_N_item_name_N_item_description_N_attack_power_N_item_effect_where_LT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& s_attack_power, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_963(?, ?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, s_item_description, s_attack_power, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_id_N_item_name_N_item_description_N_attack_power_N_item_effect_where_LE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& s_attack_power, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_964(?, ?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, s_item_description, s_attack_power, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_id_N_item_name_N_item_description_N_attack_power_N_item_effect_where_GT_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& s_attack_power, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_965(?, ?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, s_item_description, s_attack_power, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::update_item_weapon_set_id_N_item_name_N_item_description_N_attack_power_N_item_effect_where_GE_id(tcp_connection* conn, const int32_t& s_id, const string& s_item_name, const string& s_item_description, const int32_t& s_attack_power, const int32_t& s_item_effect, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_966(?, ?, ?, ?, ?, ?)");
        conn->execute(stmt.bind(s_id, s_item_name, s_item_description, s_attack_power, s_item_effect, w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::delete_from_item_weapon_where_EQ_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_967(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::delete_from_item_weapon_where_LT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_968(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::delete_from_item_weapon_where_LE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_969(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::delete_from_item_weapon_where_GT_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_970(?)");
        conn->execute(stmt.bind(w_id), result);
    }
    catch (const error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}

    
inline int item_weapon_orm::delete_from_item_weapon_where_GE_id(tcp_connection* conn, const int32_t& w_id)
{
    results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_971(?)");
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
