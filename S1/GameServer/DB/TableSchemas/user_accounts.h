#pragma once
#include <string>
#include <boost/describe/class.hpp>
#include "Core/Types.h"

namespace ServerCore
{

/* test용 table schemas
 * database에 아래와 같은 schema를 가진 user라는 테이블이 존재해야 한다*/
struct user_accounts
{
    uint32_t id;
    std::string user_id;
    std::string username;
    std::string password;
    std::string email;
    std::string created_at;
    std::string updated_at;
};

BOOST_DESCRIBE_STRUCT(user_accounts, (), (user_id, username, password, email, created_at,updated_at));
}
