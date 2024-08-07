# coding=utf-8
import time
from itertools import combinations, product, chain
from typing import Dict, Optional, List, Callable, Tuple, Set

import mysql
from mysql.connector import MySQLConnection

from customed_logger import *
from stored_procedures import *
from table_info import TableInfo
from column_info import ColumnInfo
from index_info import IndexInfo


class DatabaseInfo:
    # static members
    __COMPARABLE_OPERATORS: List[str] = ['=', '<', '<=', '>', '>=']
    __COMPARABLE_OPERATORS_NAMES: List[str] = ['eq', 'lt', 'le', 'gt',
                                               'ge']  # less than, less or equal, greater than, greater or eqaul
    __NON_COMPARABLE_OPERATORS: List[str] = ['=']
    __NONCOMPARABLE_OPERATORS_NAME: List[str] = 'eq'
    __SKIP_TABLES = ['__efmigrationshistory']
    __LOGICAL_OPERATORS = ['AND', 'OR']


    def __init__(self, database_name: str, host: str, user_name: str, password: str, port: int = 3308):
        """ORM 생성기 초기화"""
        self.database_name: str = database_name
        self.connection: MySQLConnection = mysql.connector.connect(
            host=host,
            user=user_name,
            password=password,
            database=database_name,
            port=port
        )
        self.cursor = self.connection.cursor(dictionary=True)
        self.tables: Dict[str, TableInfo] = {}
        self.sp_map: Dict[str, StoredProcedure] = {}
        self.sp_counter: int = 1


    def load_schema(self) -> None:
        """데이터베이스 내의 모든 테이블 스키마 가져오기"""
        print(f"Load database({self.database_name}) schema", end="")
        start_time = time.time()
        column_query = """
SELECT
    c.TABLE_NAME AS table_name,
    c.COLUMN_NAME AS column_name,
    c.ORDINAL_POSITION AS column_id,
    c.DATA_TYPE AS data_type,
    c.CHARACTER_MAXIMUM_LENGTH AS max_length,
    c.IS_NULLABLE AS is_nullable,
    c.COLUMN_DEFAULT AS default_definition,
    c.COLUMN_COMMENT AS column_comment,
    kcu.COLUMN_NAME IS NOT NULL AS is_primary_key,
    c.EXTRA LIKE '%CURRENT_TIMESTAMP%' OR c.COLUMN_DEFAULT LIKE '%CURRENT_TIMESTAMP%' AS timestamp_on_create,
    c.EXTRA LIKE '%ON UPDATE CURRENT_TIMESTAMP%' AS timestamp_on_update,
    c.IS_NULLABLE = 'NO' AND c.COLUMN_DEFAULT IS NULL AND c.EXTRA NOT LIKE '%auto_increment%' AS required_when_insert,
    CASE
        WHEN kcu.COLUMN_NAME IS NOT NULL AND c.EXTRA LIKE '%auto_increment%' THEN TRUE
        WHEN c.EXTRA LIKE '%CURRENT_TIMESTAMP%' THEN TRUE
        WHEN c.COLUMN_DEFAULT LIKE '%CURRENT_TIMESTAMP%' THEN TRUE
        WHEN c.EXTRA LIKE '%ON UPDATE CURRENT_TIMESTAMP%' THEN TRUE
        WHEN c.COLUMN_COMMENT LIKE '%auto_generated%' THEN TRUE
        ELSE FALSE
    END AS auto_generated,
    CASE
        WHEN c.DATA_TYPE IN ('tinyint', 'smallint', 'mediumint', 'int', 'bigint', 'decimal', 'float', 'double', 'real',
                            'serial', 'date', 'datetime', 'timestamp', 'time', 'year',
                             'char') THEN TRUE
        ELSE FALSE
    END AS is_comparable
FROM
    information_schema.COLUMNS AS c
LEFT JOIN
    information_schema.KEY_COLUMN_USAGE AS kcu
    ON c.TABLE_SCHEMA = kcu.TABLE_SCHEMA
    AND c.TABLE_NAME = kcu.TABLE_NAME
    AND c.COLUMN_NAME = kcu.COLUMN_NAME
    AND kcu.CONSTRAINT_NAME = 'PRIMARY'
WHERE
    c.TABLE_SCHEMA = %s
ORDER BY
    c.TABLE_NAME, c.ORDINAL_POSITION;
"""
        self.cursor.execute(column_query, (self.database_name,))
        column_result = self.cursor.fetchall()

        for idx in column_result:
            column_info = ColumnInfo(
                table_name=idx['table_name'],
                column_name=idx['column_name'],
                column_id=idx['column_id'],
                data_type=idx['data_type'],
                max_length=idx['max_length'],
                is_nullable=idx['is_nullable'] == 'YES',
                default_definition=idx['default_definition'],
                column_comment=idx['column_comment'],
                is_primary_key=bool(idx['is_primary_key']),
                timestamp_on_create=bool(idx['timestamp_on_create']),
                timestamp_on_update=bool(idx['timestamp_on_update']),
                required_when_insert=bool(idx['required_when_insert']),
                auto_generated=bool(idx['auto_generated']),
                is_comparable=bool(idx['is_comparable'])
            )

            if column_info.table_name in self.__SKIP_TABLES:
                continue
            if column_info.table_name not in self.tables:
                self.tables[column_info.table_name] = TableInfo(self.database_name, column_info.table_name)
            self.tables[column_info.table_name].columns.append(column_info)

        """데이터베이스 내의 모든 테이블의 index 정보 가져오기"""
        index_query = """
SELECT
    TABLE_NAME,
    INDEX_NAME,
    GROUP_CONCAT(COLUMN_NAME ORDER BY SEQ_IN_INDEX DESC) AS columns,
    CASE
        WHEN NON_UNIQUE = 0 THEN 1
        ELSE 0
    END AS is_unique
FROM
    information_schema.STATISTICS
WHERE
    TABLE_SCHEMA = %s
GROUP BY
    TABLE_NAME, INDEX_NAME
ORDER BY
    TABLE_NAME, INDEX_NAME;
        """
        self.cursor.execute(index_query, (self.database_name,))
        index_result = self.cursor.fetchall()

        index_infos: Dict[str, List[IndexInfo]] = {}
        for idx in index_result:
            table_name = idx['TABLE_NAME']
            if table_name in self.__SKIP_TABLES:
                continue
            index_name = idx['INDEX_NAME']
            column_names = idx['columns'].split(',')
            is_unique = bool(idx['is_unique'])

            if table_name not in index_infos:
                index_infos[table_name] = []

            index: IndexInfo = IndexInfo(index_name, table_name)
            # column_names에 있는 column들을 table에서 찾아서 index에 넣기
            for column_name in column_names:
                for col in self.tables[table_name].columns:
                    if col.column_name == column_name:
                        index.columns.append(col)
            sorted(index.columns, key=lambda x: x.column_id)
            self.tables[table_name].indices.append(index)

        end_time = time.time()
        execution_time = end_time - start_time
        print_success(f" - {execution_time:.3f}s [done]")


    def generate_stored_procedures(self) -> None:
        print_success(f"Generate the stored procedures for {self.database_name}...", end="")
        start_time = time.time()
        for table_name, table in self.tables.items():
            self.tables[table_name].stored_procedures.extend(self.generate_insert_sp(table))
            self.tables[table_name].stored_procedures.extend(self.generate_select_sp(table))
            self.tables[table_name].stored_procedures.extend(self.generate_update_sp(table))
            self.tables[table_name].stored_procedures.extend(self.generate_delete_sp(table))
        end_time = time.time()
        execution_time = end_time - start_time
        print_success(f" - {execution_time:.3f}s [done]")


    def register_stored_procedures(self):
        # 저장 프로시저 등록하기
        for table_name, table in self.tables.items():
            counter = 0
            print_success(f"Register the stored procedures for table {table_name}", end="")
            start_time = time.time()
            for sp in table.stored_procedures:
                try:
                    # 프로시저가 이미 존재하면 삭제
                    drop_query = f"DROP PROCEDURE IF EXISTS {sp.sp_name}"
                    self.cursor.execute(drop_query)
                    # 프로시저 생성
                    sp.generate_content()
                    self.cursor.execute(sp.content)
                    # print_success(f"Created stored procedure: {sp.sp_name}")
                    # print_success(f"{sp.content}\n========================================================")
                    counter += 1
                except mysql.connector.Error as err:
                    print_error(f"Failed to create stored procedure: {err}")
                    print_error(f"Query: {sp.content}")  # 디버깅을 위해 실패한 쿼리 출력
                    raise Exception("query failed")
            end_time = time.time()
            execution_time = end_time - start_time
            print_success(f" - {execution_time:.3f}s [done]")
            print_success(f"Created {counter} stored procedures for table '{table_name}'")

        self.connection.commit()


    def generate_insert_sp(self, table: TableInfo) -> List[StoredProcedure]:
        # INSERT 쿼리
        # INSERT INTO 'table_name' (columns...) VALUES (values...);
        insert_sp: List[StoredProcedure] = []
        insert_combinations = self.generate_column_combinations(table.columns,
                                                                filter_required_columns=lambda
                                                                    col: col.required_when_insert,
                                                                filter_auto_generated_columns=lambda
                                                                    col: col.auto_generated)

        for combo in insert_combinations:
            sp = StoredProcedure(str(f'sp_{self.sp_counter}'), table.table_name, 'bool',
                                 sp_type=StoredProcedureType.INSERT)
            sp.set_insert_params(combo)
            sp.owner_table = table
            insert_sp.append(sp)
            self.sp_counter += 1

        return insert_sp


    def generate_select_sp(self, table: TableInfo) -> List[StoredProcedure]:
        # SELECT SP (조회 대상 컬럼은 SP에 인자로 전달되지 않는다. 조건만 인자로 전달된다)
        # SELECT * FROM TABLE
        # SELECT * FROM TABLE WHERE ...
        # SELECT ... FROM TABLE WHERE ...
        select_sp: List[StoredProcedure] = []
        select_combinations = self.generate_column_combinations(table.columns, None)
        select_where_clause_combinations = self.generate_where_clause_combinations(table.indices)
        for select_comb in select_combinations:
            for where_comb in select_where_clause_combinations:
                if len(select_comb) == 0:
                    continue
                sp = StoredProcedure(str(f'sp_{self.sp_counter}'), table.table_name)
                sp.set_select_params(select_params=select_comb, where_params=where_comb)
                sp.check_sp_type()
                sp.owner_table = table
                select_sp.append(sp)

                self.sp_counter += 1

        return select_sp


    def generate_update_sp(self, table: TableInfo) -> List[StoredProcedure]:

        # UPDATE SP(WHERE 절 없는 UPDATE 쿼리는 위험하므로 생성하지 않음)
        # UPDATE TABLE SET ... WHERE ...
        update_sp: List[StoredProcedure] = []

        update_set_combinations = self.generate_column_combinations(table.columns)
        update_where_combinations = self.generate_where_clause_combinations(table.indices)
        for update_comb in update_set_combinations:
            for where_comb in update_where_combinations:
                if len(update_comb) == 0 or len(where_comb) == 0:  # 변경할 항목이 없거나 조건이 없는 경우 스킵
                    continue
                sp = StoredProcedure(str(f'sp_{self.sp_counter}'), table.table_name)
                sp.set_update_params(update_params=update_comb, where_params=where_comb)
                sp.check_sp_type()
                sp.owner_table = table
                update_sp.append(sp)
                self.sp_counter += 1

        return update_sp


    def generate_delete_sp(self, table: TableInfo) -> List[StoredProcedure]:
        # DELETE 프로시저
        delete_sp: List[StoredProcedure] = []

        where_combinations = self.generate_where_clause_combinations(table.indices)
        for where_comb in where_combinations:
            if len(where_comb) == 0:  # 삭제 조건이 없으면 스킵
                continue
            sp = StoredProcedure(str(f'sp_{self.sp_counter}'), table.table_name)
            sp.set_delete_params(where_comb)
            sp.check_sp_type()
            sp.owner_table = table
            delete_sp.append(sp)
            self.sp_counter += 1

        return delete_sp


    # region generate combination
    def generate_column_combinations(self, columns: List[ColumnInfo],
                                     filter_required_columns: Callable[[ColumnInfo], bool] = None,
                                     filter_auto_generated_columns: Callable[[ColumnInfo], bool] = None) -> List[List[ColumnInfo]]:

        # 필수 기입 컬럼
        required_columns: List[ColumnInfo] = [
            col for col in columns if filter_required_columns(col)
        ] if filter_required_columns else []

        # 자동 생성으로만 사용될 컬럼
        auto_generated_columns: List[ColumnInfo] = [
            col for col in columns if filter_auto_generated_columns(col)
        ] if filter_auto_generated_columns else []

        # 옵션 컬럼(기입해도 되고 안해도 되는 컬럼)
        optional_columns: List[ColumnInfo] = [col for col in columns if
                                              col not in required_columns and col not in auto_generated_columns]

        all_combinations: List[List[ColumnInfo]] = [required_columns + list(comb)
                                                    for i in range(len(optional_columns) + 1)
                                                    for comb in combinations(optional_columns, i)
                                                    ]

        # 컬럼 순서 유지를 위해 column_id 오름차순으로 정렬
        for comb in all_combinations:
            comb.sort(key=lambda col: col.column_id)

        all_combinations.sort(key=lambda comb: len(comb))

        return all_combinations


    def generate_where_clause_combinations(self, indices: List[IndexInfo], combine_indices: bool = False) -> List[List[Tuple[ColumnInfo, str, str]]]:
        if combine_indices:
            return self._generate_combined_where_clauses(indices)
        else:
            return self._generate_single_index_where_clauses(indices)


    def _generate_combined_where_clauses(self, indices: List[IndexInfo]) -> List[List[Tuple[ColumnInfo, str, str]]]:
        all_columns = set()
        for index in indices:
            all_columns.update(index.columns)

        all_combinations = []
        for r in range(1, len(all_columns) + 1):
            for combo in combinations(all_columns, r):
                all_combinations.append(list(combo))

        where_clauses = []
        for columns in all_combinations:
            operator_combinations = self._generate_operator_combinations(columns)
            logical_operator_combinations = self._generate_logical_operator_combinations(len(columns) - 1)

            for ops in operator_combinations:
                for logical_ops in logical_operator_combinations:
                    clause = []
                    for i, (col, op) in enumerate(zip(columns, ops)):
                        logical_op = logical_ops[i] if i < len(logical_ops) else None
                        clause.append((col, op, logical_op))
                    where_clauses.append(clause)

        return where_clauses


    def _generate_single_index_where_clauses(self, indices: List[IndexInfo]) -> List[List[Tuple[ColumnInfo, str, str]]]:
        where_clauses = []
        for index in indices:
            for column in index.columns:
                operators = self.__COMPARABLE_OPERATORS if column.is_comparable else self.__NON_COMPARABLE_OPERATORS
                where_clauses.extend([[(column, op, None)] for op in operators])
        return where_clauses


    def _generate_operator_combinations(self, columns: List[ColumnInfo]) -> List[List[str]]:
        operator_lists = []
        for column in columns:
            if column.is_comparable:
                operator_lists.append(self.__COMPARABLE_OPERATORS)
            else:
                operator_lists.append(self.__NON_COMPARABLE_OPERATORS)

        return list(product(*operator_lists))


    def _generate_logical_operator_combinations(self, count: int) -> List[List[str]]:
        return list(product(self.__LOGICAL_OPERATORS, repeat=count))


    # endregion generate combination

    def generate_extra_stored_procedures(self):
        pass
# # 사용 예시
# index1 = IndexInfo("idx1", "index_test",
#                    [ColumnInfo("index_test", 1, "id", "int"), ColumnInfo("index_test", 3, "name", "varchar")])
# index2 = IndexInfo("idx2", "index_test",
#                    [ColumnInfo("index_test", 2, "password", "varchar"),
#                     ColumnInfo("index_test", 4, "email", "varchar")])
# indices = [index1, index2]
#
# clauses = generate_where_clause_combinations(indices)
# for clause in clauses:
#     print(clause)
