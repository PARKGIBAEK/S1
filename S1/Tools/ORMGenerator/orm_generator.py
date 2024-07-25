import os
import mysql.connector
from mysql.connector import MySQLConnection
from typing import Dict, List, Tuple, Optional
from column_info import ColumnInfo
from index_info import IndexInfo


class OrmGenerator:
    def __init__(self, host: str, user: str, password: str, database: str, port: int = 3308):
        """ORM 생성기 초기화"""
        self.conn: MySQLConnection = mysql.connector.connect(
            host=host,
            user=user,
            password=password,
            database=database,
            port=port
        )
        self.cursor = self.conn.cursor(dictionary=True)
        self.sp_mapping = {}  # 저장 프로시저 매핑을 위한 딕셔너리
        self.sp_counter = 1


    def generate_orm_for_database(self, output_path: str, database_name: str) -> None:
        """데이터베이스의 모든 테이블에 대한 ORM 생성"""
        tables_info, indices_info = self.get_database_schema(database_name)
        for table_name, columns in tables_info.items():
            if table_name.lower() != '__efmigrationshistory':  # EF Core Migration용 테이블 스킵
                self.generate_stored_procedures(table_name, columns, indices_info.get(table_name, []))
                self.generate_table_class(output_path, table_name, columns, indices_info.get(table_name, []))
        self.check_db_sync(database_name, tables_info)


    def get_database_schema(self, database_name: str) -> Tuple[
        Dict[str, List[ColumnInfo]], Dict[str, List[IndexInfo]]]:
        """데이터베이스 스키마 정보 가져오기"""
        column_query = """
        SELECT 
            c.TABLE_NAME AS table_name,
            c.COLUMN_NAME AS column_name,
            c.ORDINAL_POSITION AS column_id,
            c.DATA_TYPE AS data_type,
            c.CHARACTER_MAXIMUM_LENGTH AS max_length,
            c.IS_NULLABLE AS is_nullable,
            c.COLUMN_DEFAULT AS default_definition,
            CASE WHEN c.EXTRA LIKE '%auto_increment%' THEN 1 ELSE 0 END AS is_auto_increment,
            t.AUTO_INCREMENT AS seed_value,
            CASE WHEN kcu.COLUMN_NAME IS NOT NULL THEN 1 ELSE 0 END AS is_primary_key,
            CASE WHEN c.COLUMN_DEFAULT = 'CURRENT_TIMESTAMP' THEN 1 ELSE 0 END AS has_default_current_timestamp,
            CASE WHEN c.EXTRA LIKE '%on update CURRENT_TIMESTAMP%' THEN 1 ELSE 0 END AS has_on_update_current_timestamp
        FROM 
            information_schema.COLUMNS c
        JOIN 
            information_schema.TABLES t ON c.TABLE_NAME = t.TABLE_NAME AND c.TABLE_SCHEMA = t.TABLE_SCHEMA
        LEFT JOIN 
            information_schema.KEY_COLUMN_USAGE kcu ON c.TABLE_SCHEMA = kcu.TABLE_SCHEMA 
            AND c.TABLE_NAME = kcu.TABLE_NAME AND c.COLUMN_NAME = kcu.COLUMN_NAME AND kcu.CONSTRAINT_NAME = 'PRIMARY'
        WHERE 
            t.TABLE_TYPE = 'BASE TABLE' AND c.TABLE_SCHEMA = %s
        ORDER BY 
            c.TABLE_NAME, c.ORDINAL_POSITION;
        """
        self.cursor.execute(column_query, (database_name,))
        column_result = self.cursor.fetchall()

        tables_info: Dict[str, List[ColumnInfo]] = {}
        for row in column_result:
            col = ColumnInfo(
                table_name=row['table_name'],
                column_name=row['column_name'],
                column_id=row['column_id'],
                data_type=row['data_type'],
                max_length=row['max_length'],
                is_nullable=row['is_nullable'] == 'YES',
                default_definition=row['default_definition'],
                is_auto_increment=bool(row['is_auto_increment']),
                seed_value=row['seed_value'],
                is_primary_key=bool(row['is_primary_key']),
                has_default_current_timestamp=bool(row['has_default_current_timestamp']),
                has_on_update_current_timestamp=bool(row['has_on_update_current_timestamp'])
            )
            if col.table_name not in tables_info:
                tables_info[col.table_name] = []
            tables_info[col.table_name].append(col)

        index_query = """
        SELECT 
            TABLE_NAME,
            INDEX_NAME,
            GROUP_CONCAT(COLUMN_NAME ORDER BY SEQ_IN_INDEX) AS columns,
            CASE WHEN NON_UNIQUE = 0 THEN 1 ELSE 0 END AS is_unique
        FROM 
            information_schema.STATISTICS
        WHERE 
            TABLE_SCHEMA = %s
        GROUP BY 
            TABLE_NAME, INDEX_NAME
        ORDER BY 
            TABLE_NAME, INDEX_NAME;
        """
        self.cursor.execute(index_query, (database_name,))
        index_result = self.cursor.fetchall()

        indices_info: Dict[str, List[IndexInfo]] = {}
        for row in index_result:
            table_name = row['TABLE_NAME']
            index_name = row['INDEX_NAME']
            column_names = row['columns'].split(',')
            is_unique = bool(row['is_unique'])

            if table_name not in indices_info:
                indices_info[table_name] = []

            columns = [next(col for col in tables_info[table_name] if col.column_name == col_name) for col_name in
                       column_names]
            index = IndexInfo(table_name, index_name, columns, is_unique)
            indices_info[table_name].append(index)

        return tables_info, indices_info


    def generate_table_class(self, output_path: str, table_name: str, columns: List[ColumnInfo],
                             indices: List[IndexInfo]) -> None:
        """테이블별로 C++ 구조체와 관련 함수들을 생성"""
        struct_str = f"""
#pragma once

#include <boost/mysql.hpp>
#include <boost/mysql/tcp.hpp>
#include <boost/describe.hpp>
#include <vector>
#include <string>
#include <chrono>

namespace ORM {{

struct {table_name}
{{
    // 멤버 변수
    {self._generate_member_variables(columns)}
}};
BOOST_DESCRIBE_STRUCT({table_name}, (), ({', '.join(col.column_name for col in columns)}));

// 데이터베이스 연산
void insert(boost::mysql::tcp_connection& conn, const {table_name}& obj);
std::vector<{table_name}> select_all(boost::mysql::tcp_connection& conn);
{self._generate_select_by_index_declarations(table_name, indices)}
{self._generate_update_declarations(table_name, columns, indices)}
{self._generate_delete_declarations(table_name, indices)}

// 저장 프로시저 호출
{self._generate_sp_declarations(table_name, columns, indices)}

// 구현부
{self._generate_insert_implementation(table_name, columns)}
{self._generate_select_all_implementation(table_name, columns)}
{self._generate_select_by_index_implementations(table_name, columns, indices)}
{self._generate_update_implementations(table_name, columns, indices)}
{self._generate_delete_implementations(table_name, indices)}
{self._generate_sp_implementations(table_name, columns, indices)}

}} // namespace ORM
"""
        path = output_path
        file_name = f"{table_name}.hpp"
        full_path = os.path.join(path, file_name)
        with open(full_path, 'w', encoding='utf-8') as file:
            file.write(struct_str)

        print(f"Generated C++ struct and functions for table {table_name} in : {full_path}")

        self.generate_stored_procedures(table_name, columns, indices)  # DB상에 SP생성


    def generate_stored_procedures(self, table_name: str, columns: List[ColumnInfo],
                                   indices: List[IndexInfo]) -> None:
        sp_queries = []

        # INSERT 프로시저
        insertable_columns = [col for col in columns if not (col.is_auto_increment or
                                                             col.has_default_current_timestamp or
                                                             col.has_on_update_current_timestamp)]
        params = ', '.join([f'IN p_{col.column_name} {self.mysql_type(col.data_type)}' for col in insertable_columns])
        columns_str = ', '.join([col.column_name for col in insertable_columns])
        values_str = ', '.join([f'p_{col.column_name}' for col in insertable_columns])
        sp_name = f"sp_{self.sp_counter}"
        sp_queries.append((sp_name, f"""
    CREATE PROCEDURE {sp_name}({params})
    BEGIN
        INSERT INTO {table_name} ({columns_str}) VALUES ({values_str});
    END
    """))
        self.sp_mapping[f"insert_{table_name}"] = sp_name
        self.sp_counter += 1

        # SELECT ALL 프로시저
        sp_name = f"sp_{self.sp_counter}"
        sp_queries.append((sp_name, f"""
    CREATE PROCEDURE {sp_name}()
    BEGIN
        SELECT * FROM {table_name};
    END
    """))
        self.sp_mapping[f"select_all_from_{table_name}"] = sp_name
        self.sp_counter += 1

        # SELECT BY INDEX 프로시저
        for index in indices:
            params = ', '.join([f'IN p_{col.column_name} {self.mysql_type(col.data_type)}' for col in index.columns])
            where_clause = ' AND '.join([f'{col.column_name} = p_{col.column_name}' for col in index.columns])
            sp_name = f"sp_{self.sp_counter}"
            sp_queries.append((sp_name, f"""
    CREATE PROCEDURE {sp_name}({params})
    BEGIN
        SELECT * FROM {table_name} WHERE {where_clause};
    END
    """))
            self.sp_mapping[
                f"select_all_by_{'_and_'.join([col.column_name for col in index.columns])}_from_{table_name}"] = sp_name
            self.sp_counter += 1

        # UPDATE 프로시저
        for col in columns:
            if not col.is_auto_increment:
                for index in indices:
                    params = f'IN p_new_{col.column_name} {self.mysql_type(col.data_type)}, ' + ', '.join(
                        [f'IN p_{idx_col.column_name} {self.mysql_type(idx_col.data_type)}' for idx_col in
                         index.columns])
                    where_clause = ' AND '.join(
                        [f'{idx_col.column_name} = p_{idx_col.column_name}' for idx_col in index.columns])
                    sp_name = f"sp_{self.sp_counter}"
                    sp_queries.append((sp_name, f"""
    CREATE PROCEDURE {sp_name}({params})
    BEGIN
        UPDATE {table_name} SET {col.column_name} = p_new_{col.column_name} WHERE {where_clause};
    END
    """))
                    self.sp_mapping[
                        f"update_{col.column_name}_by_{'_and_'.join([idx_col.column_name for idx_col in index.columns])}_from_{table_name}"] = sp_name
                    self.sp_counter += 1

        # DELETE 프로시저
        for index in indices:
            params = ', '.join([f'IN p_{col.column_name} {self.mysql_type(col.data_type)}' for col in index.columns])
            where_clause = ' AND '.join([f'{col.column_name} = p_{col.column_name}' for col in index.columns])
            sp_name = f"sp_{self.sp_counter}"
            sp_queries.append((sp_name, f"""
    CREATE PROCEDURE {sp_name}({params})
    BEGIN
        DELETE FROM {table_name} WHERE {where_clause};
    END
    """))
            self.sp_mapping[
                f"delete_by_{'_and_'.join([col.column_name for col in index.columns])}_from_{table_name}"] = sp_name
            self.sp_counter += 1

        # 저장 프로시저 실행
        for sp_name, query in sp_queries:
            try:
                # 프로시저가 이미 존재하면 삭제
                drop_query = f"DROP PROCEDURE IF EXISTS {sp_name}"
                self.cursor.execute(drop_query)

                # 프로시저 생성
                self.cursor.execute(query)

                print(f"Created stored procedure: {sp_name}")
            except mysql.connector.Error as err:
                print(f"Failed to create stored procedure: {err}")
                print(f"Query: {query}")  # 디버깅을 위해 실패한 쿼리 출력

        self.conn.commit()


    def _generate_member_variables(self, columns: List[ColumnInfo]) -> str:
        """멤버 변수 생성"""
        return '\n    '.join(
            [f"{self.cpp_type(col.data_type)} {col.column_name}; // {self._get_mysql_type_with_length(col)}" for col in
             columns]
        )


    def _generate_select_by_index_declarations(self, table_name: str, indices: List[IndexInfo]) -> str:
        """인덱스를 이용한 Select 메서드 선언 생성"""
        declarations = []
        for index in indices:
            params = ', '.join([f"{self.cpp_type(col.data_type)} {col.column_name}" for col in index.columns])
            declarations.append(
                f"std::vector<{table_name}> select_all_by_{'_N_'.join([col.column_name for col in index.columns])}(boost::mysql::tcp_connection& conn, {params});")
        return '\n'.join(declarations)


    def _generate_update_declarations(self, table_name: str, columns: List[ColumnInfo],
                                      indices: List[IndexInfo]) -> str:
        """Update 메서드 선언 생성"""
        declarations = []
        for col in columns:
            if not (col.is_auto_increment or col.is_primary_key or col.has_on_update_current_timestamp):
                for index in indices:
                    params = f"{self.cpp_type(col.data_type)} new_{col.column_name}, " + ', '.join(
                        [f"{self.cpp_type(idx_col.data_type)} {idx_col.column_name}" for idx_col in index.columns])
                    declarations.append(
                        f"void update_{col.column_name}_by_{'_N_'.join([idx_col.column_name for idx_col in index.columns])}(boost::mysql::tcp_connection& conn, {params});")
        return '\n'.join(declarations)


    def _generate_delete_declarations(self, table_name: str, indices: List[IndexInfo]) -> str:
        """Delete 메서드 선언 생성"""
        declarations = []
        for index in indices:
            params = ', '.join([f"{self.cpp_type(col.data_type)} {col.column_name}" for col in index.columns])
            declarations.append(
                f"void delete_by_{'_N_'.join([col.column_name for col in index.columns])}(boost::mysql::tcp_connection& conn, {params});")
        return '\n'.join(declarations)


    def _generate_sp_declarations(self, table_name: str, columns: List[ColumnInfo], indices: List[IndexInfo]) -> str:
        """저장 프로시저 호출 메서드 선언 생성"""
        declarations = []
        declarations.append(f"void sp_insert(boost::mysql::tcp_connection& conn, const {table_name}& obj);")
        declarations.append(f"std::vector<{table_name}> sp_select_all(boost::mysql::tcp_connection& conn);")
        for index in indices:
            params = ', '.join([f"{self.cpp_type(col.data_type)} {col.column_name}" for col in index.columns])
            declarations.append(
                f"std::vector<{table_name}> sp_select_all_by_{'_N_'.join([col.column_name for col in index.columns])}(boost::mysql::tcp_connection& conn, {params});")
        for col in columns:
            if not (col.is_auto_increment or col.is_primary_key or col.has_on_update_current_timestamp):
                for index in indices:
                    params = f"{self.cpp_type(col.data_type)} new_{col.column_name}, " + ', '.join(
                        [f"{self.cpp_type(idx_col.data_type)} {idx_col.column_name}" for idx_col in index.columns])
                    declarations.append(
                        f"void sp_set_{col.column_name}_by_{'_N_'.join([idx_col.column_name for idx_col in index.columns])}(boost::mysql::tcp_connection& conn, {params});")
        for index in indices:
            params = ', '.join([f"{self.cpp_type(col.data_type)} {col.column_name}" for col in index.columns])
            declarations.append(
                f"void sp_delete_by_{'_N_'.join([col.column_name for col in index.columns])}(boost::mysql::tcp_connection& conn, {params});")
        return '\n'.join(declarations)


    def _generate_insert_implementation(self, table_name: str, columns: List[ColumnInfo]) -> str:
        """Insert 메서드 구현 생성"""
        insertable_columns = [col for col in columns if not (col.is_auto_increment or
                                                             col.has_default_current_timestamp or
                                                             col.has_on_update_current_timestamp)]
        insert_columns = ', '.join([col.column_name for col in insertable_columns])
        placeholders = ', '.join(['?' for _ in insertable_columns])
        values = ', '.join([f'obj.{col.column_name}' for col in insertable_columns])

        return f"""
void ORM::insert(boost::mysql::tcp_connection& conn, const {table_name}& obj) {{
    conn.execute("INSERT INTO {table_name} ({insert_columns}) VALUES ({placeholders})",
                 {values});
}}
"""


    def _generate_select_all_implementation(self, table_name: str, columns: List[ColumnInfo]) -> str:
        """SelectAll 메서드 구현 생성"""
        assignments = '\n        '.join(
            [f"obj.{col.column_name} = {self.field_view_to_cpp_type(col.data_type, f'row[{i}]')};"
             for i, col in enumerate(columns)])

        return f"""
std::vector<{table_name}> ORM::select_all(boost::mysql::tcp_connection& conn) {{
    boost::mysql::results result;
    conn.execute("SELECT * FROM {table_name}", result);
    std::vector<{table_name}> objects;
    for (const auto& row : result.rows()) {{
        {table_name} obj;
        {assignments}
        objects.push_back(obj);
    }}
    return objects;
}}
"""


    def _generate_select_by_index_implementations(self, table_name: str, columns: List[ColumnInfo],
                                                  indices: List[IndexInfo]) -> str:
        """인덱스를 이용한 Select 메서드 구현 생성"""
        implementations = []
        for index in indices:
            params = ', '.join([f"{self.cpp_type(col.data_type)} {col.column_name}" for col in index.columns])
            where_clause = ' AND '.join([f"{col.column_name} = ?" for col in index.columns])
            assignments = '\n        '.join(
                [f"obj.{col.column_name} = {self.field_view_to_cpp_type(col.data_type, f'row[{i}]')};"
                 for i, col in enumerate(columns)])

            implementations.append(f"""
std::vector<{table_name}> ORM::select_all_by_{'_N_'.join([col.column_name for col in index.columns])}(boost::mysql::tcp_connection& conn, {params}) {{
    boost::mysql::results result;
    conn.execute("SELECT * FROM {table_name} WHERE {where_clause}",
                 {', '.join([col.column_name for col in index.columns])});
    std::vector<{table_name}> objects;
    for (const auto& row : result.rows()) {{
        {table_name} obj;
        {assignments}
        objects.push_back(obj);
    }}
    return objects;
}}
""")
        return '\n'.join(implementations)


    def _generate_update_implementations(self, table_name: str, columns: List[ColumnInfo],
                                         indices: List[IndexInfo]) -> str:
        """Update 메서드 구현 생성"""
        implementations = []
        for col in columns:
            if not (col.is_auto_increment or col.is_primary_key or col.has_on_update_current_timestamp):
                for index in indices:
                    params = f"{self.cpp_type(col.data_type)} new_{col.column_name}, " + ', '.join(
                        [f"{self.cpp_type(idx_col.data_type)} {idx_col.column_name}" for idx_col in index.columns])
                    where_clause = ' AND '.join([f"{idx_col.column_name} = ?" for idx_col in index.columns])

                    implementations.append(f"""
void ORM::update_{col.column_name}_by_{'_N_'.join([idx_col.column_name for idx_col in index.columns])}(boost::mysql::tcp_connection& conn, {params}) {{
    conn.execute("UPDATE {table_name} SET {col.column_name} = ? WHERE {where_clause}",
                 new_{col.column_name}, {', '.join([idx_col.column_name for idx_col in index.columns])});
}}
""")
        return '\n'.join(implementations)


    def _generate_delete_implementations(self, table_name: str, indices: List[IndexInfo]) -> str:
        """Delete 메서드 구현 생성"""
        implementations = []
        for index in indices:
            params = ', '.join([f"{self.cpp_type(col.data_type)} {col.column_name}" for col in index.columns])
            where_clause = ' AND '.join([f"{col.column_name} = ?" for col in index.columns])

            implementations.append(f"""
void ORM::delete_by_{'_N_'.join([col.column_name for col in index.columns])}(boost::mysql::tcp_connection& conn, {params}) {{
    conn.execute("DELETE FROM {table_name} WHERE {where_clause}",
                 {', '.join([col.column_name for col in index.columns])});
}}
""")
        return '\n'.join(implementations)


    def _generate_sp_implementations(self, table_name: str, columns: List[ColumnInfo], indices: List[IndexInfo]) -> str:
        implementations = []

        # sp_insert
        sp_name = self.sp_mapping.get(f"insert_{table_name}")
        if sp_name:
            insertable_columns = [col for col in columns if not (col.is_auto_increment or
                                                                 col.has_default_current_timestamp or
                                                                 col.has_on_update_current_timestamp)]
            params = ', '.join([f"{self.cpp_type(col.data_type)} {col.column_name}" for col in insertable_columns])
            values = ', '.join([f"obj.{col.column_name}" for col in insertable_columns])
            implementations.append(f"""
    void ORM::sp_insert(boost::mysql::tcp_connection& conn, const {table_name}& obj) {{
        try {{
            auto stmt = conn.prepare_statement("CALL {sp_name}({', '.join(['?' for _ in insertable_columns])})");
            boost::mysql::results result;
            conn.execute(stmt.bind({values}), result);
            std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        }} catch (const boost::mysql::error_with_diagnostics& e) {{
            std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        }}
    }}
    """)

        # sp_select_all
        sp_name = self.sp_mapping.get(f"select_all_from_{table_name}")
        if sp_name:
            implementations.append(f"""
    std::vector<{table_name}> ORM::sp_select_all(boost::mysql::tcp_connection& conn) {{
        std::vector<{table_name}> objects;
        try {{
            auto stmt = conn.prepare_statement("CALL {sp_name}()");
            boost::mysql::results result;
            conn.execute(stmt.bind(), result);
            for (const auto& row : result.rows()) {{
                {table_name} obj;
                {self._generate_row_to_object_assignments(columns)}
                objects.push_back(obj);
            }}
        }} catch (const boost::mysql::error_with_diagnostics& e) {{
            std::cerr << "Error in sp_select_all: " << e.what() << std::endl;
        }}
        return objects;
    }}
    """)

        # sp_select_by_index
        for index in indices:
            sp_name = self.sp_mapping.get(
                f"select_all_by_{'_and_'.join([col.column_name for col in index.columns])}_from_{table_name}")
            if sp_name:
                params = ', '.join([f"{self.cpp_type(col.data_type)} {col.column_name}" for col in index.columns])
                bind_params = ', '.join([col.column_name for col in index.columns])
                implementations.append(f"""
    std::vector<{table_name}> ORM::sp_select_all_by_{'_N_'.join([col.column_name for col in index.columns])}(boost::mysql::tcp_connection& conn, {params}) {{
        std::vector<{table_name}> objects;
        try {{
            auto stmt = conn.prepare_statement("CALL {sp_name}({', '.join(['?' for _ in index.columns])})");
            boost::mysql::results result;
            conn.execute(stmt.bind({bind_params}), result);
            for (const auto& row : result.rows()) {{
                {table_name} obj;
                {self._generate_row_to_object_assignments(columns)}
                objects.push_back(obj);
            }}
        }} catch (const boost::mysql::error_with_diagnostics& e) {{
            std::cerr << "Error in sp_select_all_by_{'_N_'.join([col.column_name for col in index.columns])}: " << e.what() << std::endl;
        }}
        return objects;
    }}
    """)

        # sp_update
        for col in columns:
            if not (col.is_auto_increment or col.is_primary_key or col.has_on_update_current_timestamp):
                for index in indices:
                    sp_name = self.sp_mapping.get(
                        f"update_{col.column_name}_by_{'_and_'.join([idx_col.column_name for idx_col in index.columns])}_from_{table_name}")
                    if sp_name:
                        params = f"{self.cpp_type(col.data_type)} new_{col.column_name}, " + ', '.join(
                            [f"{self.cpp_type(idx_col.data_type)} {idx_col.column_name}" for idx_col in index.columns])
                        bind_params = f"new_{col.column_name}, " + ', '.join(
                            [idx_col.column_name for idx_col in index.columns])
                        implementations.append(f"""
    void ORM::sp_set_{col.column_name}_by_{'_N_'.join([idx_col.column_name for idx_col in index.columns])}(boost::mysql::tcp_connection& conn, {params}) {{
        try {{
            auto stmt = conn.prepare_statement("CALL {sp_name}({', '.join(['?' for _ in range(len(index.columns) + 1)])})");
            boost::mysql::results result;
            conn.execute(stmt.bind({bind_params}), result);
            std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        }} catch (const boost::mysql::error_with_diagnostics& e) {{
            std::cerr << "Error in sp_set_{col.column_name}_by_{'_N_'.join([idx_col.column_name for idx_col in index.columns])}: " << e.what() << std::endl;
        }}
    }}
    """)

        # sp_delete
        for index in indices:
            sp_name = self.sp_mapping.get(
                f"delete_by_{'_and_'.join([col.column_name for col in index.columns])}_from_{table_name}")
            if sp_name:
                params = ', '.join([f"{self.cpp_type(col.data_type)} {col.column_name}" for col in index.columns])
                bind_params = ', '.join([col.column_name for col in index.columns])
                implementations.append(f"""
    void ORM::sp_delete_by_{'_N_'.join([col.column_name for col in index.columns])}(boost::mysql::tcp_connection& conn, {params}) {{
        try {{
            auto stmt = conn.prepare_statement("CALL {sp_name}({', '.join(['?' for _ in index.columns])})");
            boost::mysql::results result;
            conn.execute(stmt.bind({bind_params}), result);
            std::cout << "Affected rows: " << result.affected_rows() << std::endl;
        }} catch (const boost::mysql::error_with_diagnostics& e) {{
            std::cerr << "Error in sp_delete_by_{'_N_'.join([col.column_name for col in index.columns])}: " << e.what() << std::endl;
        }}
    }}
    """)

        return '\n'.join(implementations)


    def _generate_row_to_object_assignments(self, columns: List[ColumnInfo]) -> str:
        return '\n            '.join(
            [f"obj.{col.column_name} = {self.field_view_to_cpp_type(col.data_type, f'row[{i}]')};" for i, col in
             enumerate(columns)])


    @staticmethod
    def cpp_type(mysql_type: str) -> str:
        """MySQL 데이터 타입을 C++ 데이터 타입으로 변환"""
        mysql_type = mysql_type.lower()
        if 'int' in mysql_type:
            if 'unsigned' in mysql_type:
                return 'unsigned int' if mysql_type == 'int' else 'unsigned long long'
            return 'int' if mysql_type == 'int' else 'long long'
        elif mysql_type in ['varchar', 'char', 'text', 'tinytext', 'mediumtext', 'longtext']:
            return 'std::string'
        elif mysql_type in ['float', 'double']:
            return 'double'
        elif mysql_type == 'decimal':
            return 'std::string'  # Decimal은 정확도를 위해 문자열로 처리
        elif mysql_type == 'bool' or mysql_type == 'boolean':
            return 'bool'
        elif mysql_type == 'datetime' or mysql_type == 'timestamp':
            return 'boost::mysql::datetime'
        elif mysql_type == 'date':
            return 'boost::mysql::date'
        elif mysql_type == 'time':
            return 'boost::mysql::time'
        elif mysql_type in ['binary', 'varbinary', 'tinyblob', 'blob', 'mediumblob', 'longblob']:
            return 'std::vector<unsigned char>'
        elif mysql_type == 'year':
            return 'std::uint16_t'
        elif mysql_type in ['enum', 'set']:
            return 'std::string'
        elif mysql_type == 'json':
            return 'std::string'
        else:
            return 'std::string'  # 기본값으로 문자열 처리


    def field_view_to_cpp_type(self, data_type: str, field_view_expr: str) -> str:
        """field_view를 적절한 C++ 타입으로 변환하는 표현식 생성"""
        data_type = data_type.lower()
        if 'int' in data_type:
            return f"{field_view_expr}.as_int64()" if 'unsigned' not in data_type else f"{field_view_expr}.as_uint64()"
        elif data_type in ['varchar', 'char', 'text', 'tinytext', 'mediumtext', 'longtext', 'enum', 'set', 'json']:
            return f"{field_view_expr}.as_string()"
        elif data_type in ['float', 'double']:
            return f"{field_view_expr}.as_double()"
        elif data_type == 'decimal':
            return f"{field_view_expr}.as_string()"
        elif data_type == 'bool' or data_type == 'boolean':
            return f"{field_view_expr}.as_int64() != 0"
        elif data_type == 'datetime' or data_type == 'timestamp':
            return f"boost::mysql::datetime({field_view_expr}.as_datetime())"
        elif data_type == 'date':
            return f"boost::mysql::date({field_view_expr}.as_date())"
        elif data_type == 'time':
            return f"boost::mysql::time({field_view_expr}.as_time())"
        elif data_type in ['binary', 'varbinary', 'tinyblob', 'blob', 'mediumblob', 'longblob']:
            return f"{field_view_expr}.as_blob()"
        elif data_type == 'year':
            return f"{field_view_expr}.as_uint64()"
        else:
            return f"{field_view_expr}.as_string()"


    @staticmethod
    def mysql_type(data_type: str) -> str:
        """Python 데이터 타입을 MySQL 데이터 타입으로 변환"""
        type_map = {
            'int': 'INT',
            'bigint': 'BIGINT',
            'varchar': 'VARCHAR(255)',
            'text': 'TEXT',
            'datetime': 'DATETIME',
            'float': 'FLOAT',
            'double': 'DOUBLE',
            'bool': 'BOOLEAN',
            'timestamp': 'TIMESTAMP'
        }
        return type_map.get(data_type.lower(), 'VARCHAR(255)')


    def _get_mysql_type_with_length(self, col: ColumnInfo) -> str:
        """MySQL 데이터 타입을 길이 정보와 함께 반환"""
        if col.max_length:
            return f"{col.data_type}({col.max_length})"
        return col.data_type


    def check_db_sync(self, database_name: str, tables_info: Dict[str, List[ColumnInfo]]) -> None:
        """데이터베이스 동기화 상태 확인"""
        for table_name, columns in tables_info.items():
            if table_name == '__efmigrationshistory':  # EF Core Migration용 테이블 스킵
                continue
            print(f"Checking table: {table_name}")
            self.cursor.execute("SHOW TABLES LIKE %s", (table_name,))
            if not self.cursor.fetchone():
                print(f"  Warning: Table {table_name} does not exist in the database.")
                continue

            for column in columns:
                self.cursor.execute(f"SHOW COLUMNS FROM {table_name} LIKE %s", (column.column_name,))
                if not self.cursor.fetchone():
                    print(f"  Warning: Column {column.column_name} does not exist in table {table_name}")


    def __del__(self):
        """소멸자: 데이터베이스 연결 종료"""
        try:
            if hasattr(self, 'cursor'):
                self.cursor.close()
            if hasattr(self, 'conn'):
                self.conn.close()
        except:
            pass
