# coding=utf-8
from typing import Dict, Optional


class TypeConverter:
    __MYSQL_TO_CPP: Dict[str, str] = {
        # 정수형
        "TINYINT": 'std::int8_t',
        "tinyint": 'std::int8_t',

        "SMALLINT": 'std::int16_t',
        "smallint": 'std::int16_t',

        "INT": 'std::int32_t',
        "int": 'std::int32_t',

        "BIGINT": 'std::int64_t',
        "bigint": 'std::int64_t',

        "TINYINT UNSIGNED": 'std::uint8_t',
        "tinyint unsigned": 'std::uint8_t',

        "SMALLINT UNSIGNED": 'std::uint16_t',
        "smallint unsigned": 'std::uint16_t',

        "INT UNSIGNED": 'std::uint32_t',
        "int unsigned": 'std::uint32_t',

        "BIGINT UNSIGNED": 'std::uint64_t',
        "bigint unsigned": 'std::uint64_t',

        # 부동소수점
        "FLOAT": 'float',
        "float": 'float',

        "DOUBLE": 'double',
        "double": 'double',

        # 문자열
        "VARCHAR": 'std::string',
        "varchar": 'std::string',

        "TEXT": 'std::string',
        "text": 'std::string',

        # 날짜/시간
        "DATETIME": 'boost::mysql::datetime',
        "datetime": 'boost::mysql::datetime',

        "TIMESTAMP": 'boost::mysql::datetime',
        "timestamp": 'boost::mysql::datetime',

        "DATE": 'boost::mysql::date',
        "date": 'boost::mysql::date',

        "TIME": 'boost::mysql::time',
        "time": 'boost::mysql::time',
    }
    __MYSQL_TO_CPP_WITHOUT_NAMESPACE: Dict[str, str] = {
        # 정수형
        "TINYINT": 'int8_t',
        "tinyint": 'int8_t',

        "SMALLINT": 'int16_t',
        "smallint": 'int16_t',

        "INT": 'int32_t',
        "int": 'int32_t',

        "BIGINT": 'int64_t',
        "bigint": 'int64_t',

        "TINYINT UNSIGNED": 'uint8_t',
        "tinyint unsigned": 'uint8_t',

        "SMALLINT UNSIGNED": 'uint16_t',
        "smallint unsigned": 'uint16_t',

        "INT UNSIGNED": 'uint32_t',
        "int unsigned": 'uint32_t',

        "BIGINT UNSIGNED": 'uint64_t',
        "bigint unsigned": 'uint64_t',

        # 부동소수점
        "FLOAT": 'float',
        "float": 'float',

        "DOUBLE": 'double',
        "double": 'double',

        # 문자열
        "VARCHAR": 'string',
        "varchar": 'string',

        "TEXT": 'string',
        "text": 'string',

        # 날짜/시간
        "DATETIME": 'datetime',
        "datetime": 'datetime',

        "TIMESTAMP": 'datetime',
        "timestamp": 'datetime',

        "DATE": 'date',
        "date": 'date',

        "TIME": 'time',
        "time": 'time',
    }
    __CPP_TO_MYSQL: Dict[str, str] = {
        'std::int8_t': "TINYINT",
        'std::int16_t': "SMALLINT",
        'std::int32_t': "INT",
        'std::int64_t': "BIGINT",

        'std::uint8_t': "TINYINT UNSIGNED",
        'std::uint16_t': "SMALLINT UNSIGNED",
        'std::uint32_t': "INT UNSIGNED",
        'std::uint64_t': "BIGINT UNSIGNED",

        'float': "FLOAT",
        'double': "DOUBLE",
        'std::string': "VARCHAR",

        'boost::mysql::datetime': "DATETIME",
        'boost::mysql::date': "DATE",
        'boost::mysql::time': "TIME",
    }
    __CPP_WITHOUT_NAMESPACE_TO_MYSQL: Dict[str, str] = {
        'int8_t': "TINYINT",
        'int16_t': "SMALLINT",
        'int32_t': "INT",
        'int64_t': "BIGINT",

        'uint8_t': "TINYINT UNSIGNED",
        'uint16_t': "SMALLINT UNSIGNED",
        'uint32_t': "INT UNSIGNED",
        'uint64_t': "BIGINT UNSIGNED",

        'float': "FLOAT",
        'double': "DOUBLE",
        'string': "VARCHAR",

        'datetime': "DATETIME",
        'date': "DATE",
        'time': "TIME",
    }


    @staticmethod
    def mysql_to_cpp(mysql_type: str, with_namespace: bool = False) -> Optional[str]:
        if mysql_type not in TypeConverter.__MYSQL_TO_CPP:
            raise Exception(f"Invalid mysql_type : {mysql_type}")
        if with_namespace:
            return TypeConverter.__MYSQL_TO_CPP[mysql_type]
        else:
            return TypeConverter.__MYSQL_TO_CPP_WITHOUT_NAMESPACE[mysql_type]


    @staticmethod
    def mysql_to_cpp_with_const_ref(mysql_type: str, with_namespace: bool = False) -> Optional[str]:
        if mysql_type not in TypeConverter.__MYSQL_TO_CPP:
            raise Exception(f"Invalid mysql_type : {mysql_type}")
        if with_namespace:
            return f'const {TypeConverter.__MYSQL_TO_CPP[mysql_type]}&'
        else:
            return f'const {TypeConverter.__MYSQL_TO_CPP_WITHOUT_NAMESPACE[mysql_type]}&'


    @staticmethod
    def cpp_to_mysql(cpp_type: str) -> Optional[str]:
        if cpp_type not in TypeConverter.__CPP_TO_MYSQL:
            raise Exception(f"Invalid cpp_type : {cpp_type}")
        return TypeConverter.__CPP_TO_MYSQL[cpp_type]


    @staticmethod
    def mysql_to_cpp_without_namespace(mysql_type: str) -> Optional[str]:
        if mysql_type not in TypeConverter.__MYSQL_TO_CPP_WITHOUT_NAMESPACE:
            raise Exception(f"Invalid mysql_type : {mysql_type}")
        return TypeConverter.__MYSQL_TO_CPP_WITHOUT_NAMESPACE[mysql_type]


    @staticmethod
    def cpp_to_mysql(cpp_type: str) -> Optional[str]:
        if cpp_type not in TypeConverter.__CPP_TO_MYSQL:
            raise Exception(f"Invalid cpp_type : {cpp_type}")
        return TypeConverter.__CPP_TO_MYSQL[cpp_type]
