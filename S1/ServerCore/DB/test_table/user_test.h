#pragma once
#include <string>
#include <boost/describe/class.hpp>
#include "Core/Types.h"

namespace ServerCore
{
/* test용 table schemas
 * database에 아래와 같은 schema를 가진 user라는 테이블이 존재해야 한다*/
struct user_test
{
    uint32_t user_id;
    std::string m_name;
    std::string password;
    std::string email;
    std::string created_at;
    std::string updated_at;
};
BOOST_DESCRIBE_STRUCT(user_test, (), (user_id, m_name,password,email,created_at,updated_at));

}
