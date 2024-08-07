1. Simple ORM Generator를 만든 이유

일반적으로 C++ ORM을 만들 때 ODBC, ODB C++ 같은 것들을 사용한다.

주로 2가지 방식으로 구현하게 되는데

라이브러리에서 제공하는 방식으로 코드상에서 쿼리에 필요한 인자를 직접 바인딩 시키는 방식과

매크로를 활용하여 Reflection을 흉내내어 정적으로 meta data를 코드상에 심어

템플릿과 함께 응용하는 방식이 있다.

두가지 방법 모두 공통적인 단점이 존재한다.


1) 기존 방식의 ORM은 사용법을 익히는데 시간이 많이 소모됨

C++ 언어 자체가 가진 복잡성 때문에 이것 저것 시간이 많이 소요된다.

라이브러리나 프레임워크의 호환성 문제를 해결하기 위해 이것저것 환경 설정을 하는 것부터
사용법을 익히는까지 이 자체로도 시간적인 압박감이 크다.

안그래도 복잡한 매크로 코드와 템플릿 코드가 뒤섞여 복잡한데

거기서 예외 상황을 마주하면 머리가 아파진다.



2) 불완전한 호환성

ODBC 같은 것을 사용할 때 여러가지 호환 문제가 존재한다.(예 : 환경에 따른 매크로 정의 충돌 문제, windows 헤더 사용 시 매크로 충돌 등 )

새로운 환경에서 또 어떤 문제가 도사리고 있을지 두렵다.



3) 무겁다

특별히 복잡한 쿼리를 사용하는 경우 미리 안정성이 검증되어 사용 허가가난 SP를 사용하지

굳이 코드 상에서 개발자가 즉흥적으로 복잡한 쿼리를 사용하는 것은 리스크가 있다.


이외에는 솔직히 간단한 쿼리 정도를 사용하는 것이 대부분이다.

그런데 그 간단한 쿼리를 사용하지만

그렇게 간단한 인라인 쿼리를 사용함에도 

인자 전달시 의도치 않은 인젝션으로 인해 문제가 생기는 등의 찝찝한 리스크를 피하고 싶어서

굳이 무겁고 복잡한 ODBC같은 것들을 사용하게 된다.


그래서 미리 테이블 별로 간단한 쿼리를 모두 SP로 생성해두고 호출하는 방식으로 설계해보았다.

그리고 미리 생성된 SP를 호출하는 코드는 함수명이 인라인 쿼리 그자체라고 보면 된다.

샘플 코드)


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
    static int insert_into_auth_key_key_value(tcp_connection* conn, const string& new_key_value);
...
    static results select_id_from_auth_key_where_EQ_created_at(tcp_connection* conn, const datetime& w_created_at);
    static results select_id_from_auth_key_where_LT_created_at(tcp_connection* conn, const datetime& w_created_at);
    static results select_id_from_auth_key_where_LE_created_at(tcp_connection* conn, const datetime& w_created_at);
    static results select_id_from_auth_key_where_GT_created_at(tcp_connection* conn, const datetime& w_created_at);
...
    static int update_auth_key_set_key_value_where_EQ_id(tcp_connection* conn, const string& s_key_value, const int32_t& w_id);
    static int update_auth_key_set_key_value_where_LT_id(tcp_connection* conn, const string& s_key_value, const int32_t& w_id);
    static int update_auth_key_set_key_value_where_LE_id(tcp_connection* conn, const string& s_key_value, const int32_t& w_id);
    static int update_auth_key_set_key_value_where_GT_id(tcp_connection* conn, const string& s_key_value, const int32_t& w_id);
    static int update_auth_key_set_key_value_where_GE_id(tcp_connection* conn, const string& s_key_value, const int32_t& w_id);
...
    static int delete_from_auth_key_where_LE_id(tcp_connection* conn, const int32_t& w_id);
    static int delete_from_auth_key_where_GT_id(tcp_connection* conn, const int32_t& w_id);
    static int delete_from_auth_key_where_GE_id(tcp_connection* conn, const int32_t& w_id);
};


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
...

2. 특징


1) 사용법이 아주 간단하다.

- 그냥 connection string만 인자로 전달해주면
  database schema를 분석하여
  Table별로 자주 사용되는 쿼리를 SP로 생성하고
  이를 C++코드로 만들어준다.
  생성된 C++코드를 추가하여 함수를 호출하고 인자를 전달하기만 하면 끝이다.

- 쿼리를 사용하듯 간단하고 직관적인 사용 방식이다.



2) 간단한 쿼리만 사용할 목적이라면 충분히 커버된다.

- 단일 테이블에 대하여 기본적인 INSERT, SELECT, UPDATE, DELETE 쿼리를 자동으로 생성한다.

- WHERE clause는 index를 기반으로 생성된다.
  즉, index가 없다면 WHERE clause도 생성되지 않는다.

- WHERE Clause의 비교 연산자는 comparable type에 대하여
  5가지 비교 연산자 'EQAUL(=)', 'GREAT(>)', 'LESS(<)', 'GREAT OR EQUAL(>=)', 'LESS OR EQAUL(<=)'과
  2가지 논리 연산자 'AND', 'OR'을 지원한다.

  non-comparable type에 대해서는
  'EQAUL(=)'연산자와 'AND', 'OR'을 지원한다.
  'EQAUL(=)'과 'AND'만 가능하다.

- 추가로 필요한 쿼리가 있다면 사용자가 직접 추가할 수 있다.

- 보다 다양한 쿼리를 지원하려면 자동 생성되는 sp의 개수가 기하급수로 늘어나서 커버가 불가능하다.
  위의 언급한 내용만해도 컬럼 6개에 단일 컬럼 index가 5개짜리 테이블 하나에 대하여 sp가 대략 수백만개가 생성된다.
  때문에 index는 최소한으로 설정하도록 한다.(ORM Generator의 목적은 C++에서 간단한 DB 쿼리 사용이다)


3) 코드 상에서 쿼리를 직접 사용하는듯 직관적이면서도 리스크가 없는 간단한 방식이다.

- 샘플 코드

class auth_key_orm
{
public:

    static bool sp_insert_into_auth_key_key_value(tcp_connection* conn, const std::string& new_key_value);

    static boost::mysql::results sp_select_id_from_auth_key(tcp_connection* conn );

    static std::uint64_t sp_update_auth_key_set_id_where_key_value_and_created_at(tcp_connection* conn, const std::string& w_key_value, const datetime& w_created_at, const std::int32_t& new_id);

    static std::uint64_t sp_delete_from_auth_key_where_id_and_key_value(tcp_connection* conn, const std::int32_t& w_id, const std::string& w_key_value);

...

...
}


inline bool auth_key_orm::sp_insert_into_auth_key_key_value(boost::mysql::tcp_connection* conn, std::string new_key_value)
{
    boost::mysql::results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_1(?)");
        conn->execute(stmt.bind(new_key_value), result);
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }

    return result.affected_rows();
}


inline boost::mysql::results auth_key_orm::sp_select_id_from_auth_key(boost::mysql::tcp_connection* conn)
{
    boost::mysql::results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_5()");
        conn->execute(stmt.bind(), result);
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_select_id_from_auth_key: " << e.what() << std::endl;
    }
    return result;
}


inline std::uint64_t auth_key_orm::sp_update_auth_key_set_id_where_key_value_and_created_at(boost::mysql::tcp_connection* conn, std::string w_key_value, boost::mysql::datetime w_created_at, std::int32_t new_id)
{
    boost::mysql::results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_66(?, ?, ?)");
        conn->execute(stmt.bind(new_id, w_key_value, w_created_at), result);
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_update_auth_key_set_id_where_key_value_and_created_at: " << e.what() << std::endl;
        return 0;
    }
    return result.affected_rows();
}


inline std::uint64_t auth_key_orm::sp_delete_from_auth_key_where_id_and_key_value(boost::mysql::tcp_connection* conn, std::int32_t w_id, std::string w_key_value)
{
    boost::mysql::results result;
    try
    {
        auto stmt = conn->prepare_statement("CALL sp_113(?, ?)");
        conn->execute(stmt.bind(w_id, w_key_value), result);
    }
    catch (const boost::mysql::error_with_diagnostics& e)
    {
        std::cerr << "Error in sp_delete_from_auth_key_where_id_and_key_value: " << e.what() << std::endl;
        return 0;
    }
    return result.affected_rows();
}



3. 사용법

1) orm_generator.exe에 command line arguments로 인자 전달


orm_generator.exe --host=localhost --user=root --password=tkdring --database=test --port=3308 --output=../../GameServer/DB/ORM



2) 생성된 코드를 Include하고, 

 ORM class의 API에 boost::mysql::tcp_connection과

 SP에 필요한 인자만 전달하면 SP가 호출된다.


4. 장점이자 한계점

- 함수명이 쿼리와 비슷하며 내부적으로 미리 생성된 sp에 인자만 전달하여 사용하는 방식이라서
  사용법이 매우 간단하다.
  그냥 코드 생성하고 사용하면 끝이다.
- 단점은 미리 sp를 생성해야한다는 점 때문에
  자동 생성되는 쿼리의 범위가 제한적이다.
- 하지만 복잡한 쿼리를 추가하여 사용할 수 있으므로
  해당 쿼리를 추가하기만 하면 간편하게 사용할 수 있다.