# coding=utf-8
import os
import time
from itertools import combinations
from typing import Dict, List, Callable

import mysql.connector

from customed_logger import *
from column_info import ColumnInfo
from database_info import DatabaseInfo
from stored_procedures import *
from table_info import TableInfo
from type_converter import TypeConverter


class OrmGenerator:
    def __init__(self, output_path: str, host: str, user_name: str, password: str, database_name: str,
                 port: int = 3308):
        """ORM 생성기 초기화"""
        self.database: DatabaseInfo = DatabaseInfo(database_name, host, user_name, password, port)
        self.output_path: str = output_path
        self.sp_mapper: Dict[str, str] = {}  # { sp_name(sp_1, sp_2 ....), func_name(select_xxx_from_xxx_where_xxx)


    def generate_orm_for_database(self) -> None:
        """데이터베이스의 모든 테이블에 대한 ORM 생성"""

        self.database.load_schema()
        self.database.generate_stored_procedures()
        self.database.generate_extra_stored_procedures()  # 추후 Custom SP 추가 기능
        self.database.register_stored_procedures()
        for table_name, table in self.database.tables.items():
            self.generate_cpp_code(table)
        self.check_db_sync()


    def generate_cpp_code(self, table: TableInfo) -> None:
        """테이블별로 C++ 구조체와 관련 함수들을 생성"""
        print_success(f"Generate the cpp code for table {table.table_name}", end="")
        start_time = time.time()
        namespace = f"ORM_{self.database.database_name}"
        class_name = f"{table.table_name}_orm"
        code_str = f"""
#pragma once

#include <boost/mysql.hpp>
#include <boost/mysql/tcp.hpp>
#include <boost/describe.hpp>
#include <string>
#include <iostream>
#include <format>

using namespace boost::mysql;
using namespace std;

namespace {namespace} {{

struct {table.table_name}
{{
    {self._generate_member_variables(table.columns)}
}};

BOOST_DESCRIBE_STRUCT({table.table_name}, (), ({', '.join(col.column_name for col in table.columns)}));

class {class_name}
{{
public:
    // SP 호출 선언
    {self._generate_sp_func_declarations(table)}
}};

// SP 호출 구현
{self._generate_sp_func_implementations(table)}


}} // namespace ORM
"""

        path = self.output_path
        file_name = f"{table.table_name}_orm.hpp"
        full_path = os.path.join(path, file_name)

        with open(full_path, 'w', encoding='utf-8') as file:
            file.write(code_str)
        end_time = time.time()
        execution_time = end_time - start_time
        print_success(f" - {execution_time:.3f}s [done]")
        print(f"Generated C++ struct and functions for table {table.table_name} in : {full_path}")


    def _generate_sp_func_declarations(self, table: TableInfo) -> str:
        func_declarations: List[str] = []

        # sp_insert(required_when_insert는 NOT NULL + DEFAULT 값이 없는 INSERT 필수 기입 여부를 나타냄)

        insert_func_declarations: List[str] = []
        for sp in table.stored_procedures:
            if sp.sp_type is StoredProcedureType.INSERT:
                sp.generate_func()
                insert_func_declarations.append(sp.func_signature)

        select_func_declarations: List[str] = []
        for sp in table.stored_procedures:
            if sp.sp_type is StoredProcedureType.SELECT:
                sp.generate_func()
                select_func_declarations.append(sp.func_signature)

        update_func_declarations: List[str] = []
        for sp in table.stored_procedures:
            if sp.sp_type is StoredProcedureType.UPDATE:
                sp.generate_func()
                update_func_declarations.append(sp.func_signature)

        delete_func_declarations: List[str] = []
        for sp in table.stored_procedures:
            if sp.sp_type is StoredProcedureType.DELETE:
                sp.generate_func()
                delete_func_declarations.append(sp.func_signature)

        customized_func_declarations: List[str] = []
        for sp in table.stored_procedures:
            if sp.sp_type is StoredProcedureType.CUSTOMIZED:
                sp.generate_func()
                customized_func_declarations.append(sp.func_signature)

        func_declarations.extend(insert_func_declarations)
        func_declarations.extend(select_func_declarations)
        func_declarations.extend(update_func_declarations)
        func_declarations.extend(delete_func_declarations)
        func_declarations.extend(customized_func_declarations)

        return '\n    '.join(func_declarations)


    def _generate_sp_func_implementations(self, table: TableInfo) -> str:
        func_implemetations: List[str] = []

        # sp_insert(required_when_insert는 NOT NULL + DEFAULT 값이 없는 INSERT 필수 기입 여부를 나타냄)

        insert_func_implemetations: List[str] = []
        select_func_implemetations: List[str] = []
        update_func_implemetations: List[str] = []
        delete_func_implemetations: List[str] = []
        customized_func_implemetations: List[str] = []

        for sp in table.stored_procedures:
            sp.generate_func()
            if sp.sp_type is StoredProcedureType.INSERT:
                insert_func_implemetations.append(sp.func_implemetation)
            elif sp.sp_type is StoredProcedureType.SELECT:
                select_func_implemetations.append(sp.func_implemetation)
            elif sp.sp_type is StoredProcedureType.UPDATE:
                update_func_implemetations.append(sp.func_implemetation)
            elif sp.sp_type is StoredProcedureType.DELETE:
                delete_func_implemetations.append(sp.func_implemetation)
            elif sp.sp_type is StoredProcedureType.CUSTOMIZED:
                customized_func_implemetations.append(sp.func_implemetation)

        func_implemetations.extend(insert_func_implemetations)
        func_implemetations.extend(select_func_implemetations)
        func_implemetations.extend(update_func_implemetations)
        func_implemetations.extend(delete_func_implemetations)
        func_implemetations.extend(customized_func_implemetations)

        return '\n    '.join(func_implemetations)


    def _generate_member_variables(self, columns: List[ColumnInfo]) -> str:
        """멤버 변수 생성"""
        return '\n    '.join(
            f"{TypeConverter.mysql_to_cpp(col.data_type)} {col.column_name}; // {col.data_type_with_length}"
            for col in columns)


    def check_db_sync(self) -> None:
        """ 데이터베이스 동기화 상태 확인 """
        print_success("Check database sync...", end="")
        start_time = time.time()
        for table_name, table in self.database.tables.items():
            if table_name == '__efmigrationshistory':  # EF Core Migration용 테이블 스킵
                continue
            print(f"Checking table: {table_name}")
            self.database.cursor.execute("SHOW TABLES LIKE %s", (table_name,))
            if not self.database.cursor.fetchone():
                print(f"  Warning: Table {table_name} does not exist in the database.")
                continue

            for column in table.columns:
                self.database.cursor.execute(f"SHOW COLUMNS FROM {table_name} LIKE %s", (column.column_name,))
                if not self.database.cursor.fetchone():
                    print(f"  Warning: Column {column.column_name} does not exist in table {table_name}")
        end_time = time.time()
        execution_time = end_time - start_time
        print_success(f" - {execution_time:.3f}s [done]")


    def __del__(self):
        """ 소멸자 : 데이터베이스 연결 종료 """
        try:
            if hasattr(self, 'cursor'):
                self.cursor.close()
            if hasattr(self, 'conn'):
                self.connection.close()
        except:
            pass
