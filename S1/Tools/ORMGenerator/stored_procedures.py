# coding=utf-8
from enum import Enum, auto
from typing import Optional, List, Tuple

from jinja2 import Template

from column_info import ColumnInfo
from type_converter import TypeConverter


class StoredProcedureType(Enum):
    NONE = auto()
    INSERT = auto()
    SELECT = auto()
    UPDATE = auto()
    DELETE = auto()
    CUSTOMIZED = auto()


class StoredProcedure:
    __AND_IN_FUNC_NAME = '_N_'


    def __init__(self, name: str,
                 table_name: str,
                 return_type: Optional[str] = None,
                 sp_type: StoredProcedureType = StoredProcedureType.NONE):
        from table_info import TableInfo
        self.sp_type: StoredProcedureType = sp_type
        self.table_name: str = table_name
        self.sp_name: Optional[str] = name
        self.content: Optional[str] = None
        self.insert_params: Optional[List[ColumnInfo]] = None
        self.select_params: Optional[List[ColumnInfo]] = None
        self.select_where_params: Optional[List[Tuple[ColumnInfo, str, str]]] = None
        self.update_set_params: Optional[List[ColumnInfo]] = None
        self.update_where_params: Optional[List[Tuple[ColumnInfo, str, str]]] = None
        self.delete_where_params: Optional[List[Tuple[ColumnInfo, str, str]]] = None
        self.return_type: Optional[str] = return_type
        self.func_name: Optional[str] = None
        self.func_signature: Optional[str] = None
        self.func_param_str: Optional[str] = None
        self.func_implemetation: Optional[str] = None
        self.class_name: Optional[str] = None
        self.owner_table: Optional[TableInfo] = None


    #  region param setter
    def set_insert_params(self, insert_params: List[ColumnInfo]):
        self.insert_params = insert_params


    def set_select_params(self, select_params: List[ColumnInfo],
                          where_params: Optional[List[Tuple[ColumnInfo, str, str]]]):
        self.select_params = select_params
        self.select_where_params = where_params


    def set_update_params(self, update_params: List[ColumnInfo],
                          where_params: Optional[List[Tuple[ColumnInfo, str, str]]]):
        self.update_set_params = update_params
        self.update_where_params = where_params


    def set_delete_params(self, where_params: Optional[List[Tuple[ColumnInfo, str, str]]]):
        self.delete_where_params = where_params


    def check_sp_type(self):
        if self.insert_params:
            if self.select_params or self.select_where_params or self.update_where_params or self.update_set_params or self.delete_where_params:
                raise Exception("Invalid params")
            else:
                self.sp_type = StoredProcedureType.INSERT
        elif self.select_params or self.select_where_params:
            if self.insert_params or self.update_where_params or self.update_set_params or self.delete_where_params:
                raise Exception("Invalid params")
            else:
                self.sp_type = StoredProcedureType.SELECT
        elif self.update_set_params or self.update_where_params:
            if self.insert_params or self.select_params or self.select_where_params or self.delete_where_params:
                raise Exception("Invalid params")
            else:
                self.sp_type = StoredProcedureType.UPDATE
        elif self.delete_where_params:
            if self.insert_params or self.select_params or self.select_where_params or self.update_set_params or self.update_where_params:
                raise Exception("Invalid params")
            else:
                self.sp_type = StoredProcedureType.DELETE


    # endregion param setter

    # region generate a sp creation query
    def generate_content(self):
        self.check_sp_type()
        if self.sp_type is StoredProcedureType.INSERT:
            self._generate_sp_creation_query_insert()
        elif self.sp_type is StoredProcedureType.SELECT:
            self._generate_sp_creation_query_select()
        elif self.sp_type is StoredProcedureType.UPDATE:
            self._generate_sp_creation_query_update()
        elif self.sp_type is StoredProcedureType.DELETE:
            self._generate_sp_creation_query_delete()


    def _generate_sp_creation_query_insert(self):
        insert_params = ',\n    '.join(
            f'IN new_{param.column_name} {param.data_type_with_length}' for param in self.insert_params)
        insert_columns = ',\n    '.join(f'{column.column_name}' for column in self.insert_params)
        insert_values = ',\n    '.join(f'new_{param.column_name}' for param in self.insert_params)
        content = f"""
CREATE PROCEDURE {self.sp_name}(
    {insert_params}
)
BEGIN
    INSERT INTO {self.table_name}
    ({insert_columns})
    VALUES ({insert_values});
END;
"""
        self.content = content


    def _generate_sp_creation_query_select(self):
        where_params = ',\n    '.join(
            f'IN w_{param.column_name} {param.data_type_with_length}' for param, comp_op, logic_op in
            self.select_where_params)
        select_columns = ',\n           '.join(f'{column.column_name}' for column in self.select_params)
        where_clause = self._generated_sp_where_clause(StoredProcedureType.SELECT)
        content = f"""
CREATE PROCEDURE {self.sp_name}(
    {where_params}
)
BEGIN
    SELECT {select_columns} 
    FROM {self.table_name}
    {where_clause}
END;
"""
        self.content = content


    def _generate_sp_creation_query_update(self):
        where_params = ',\n    '.join(
            f'IN w_{param.column_name} {param.data_type_with_length}' for param, _, _ in
            self.update_where_params)
        update_set_params = ',\n    '.join(
            f'IN s_{param.column_name} {param.data_type_with_length}' for param in self.update_set_params)
        update_set_clause = ',\n        '.join(
            f'{col.column_name} = s_{col.column_name}' for col in self.update_set_params)
        where_clause = self._generated_sp_where_clause(StoredProcedureType.UPDATE)
        content = f"""
CREATE PROCEDURE {self.sp_name}(
    {update_set_params},
    {where_params}
)
BEGIN
    UPDATE {self.table_name} 
    SET  {update_set_clause}
    {where_clause}
END;
"""
        self.content = content


    def _generate_sp_creation_query_delete(self):
        where_params = ',\n    '.join(
            f'IN w_{param.column_name} {param.data_type_with_length}' for param, _, _ in self.delete_where_params)
        where_clause = self._generated_sp_where_clause(StoredProcedureType.DELETE)
        content = f"""
CREATE PROCEDURE {self.sp_name}(
    {where_params}
)
BEGIN
    DELETE FROM {self.table_name} 
    {where_clause}
END;
"""
        self.content = content


    # endregion generate a sp creation query

    # region generate a sp function

    def generate_func(self):
        if self.sp_type == StoredProcedureType.INSERT:
            self.return_type = 'int'
            self._generate_insert_func_name()
            self._generate_insert_func_param_str()
            self._generate_insert_func_signature()
            self._generate_insert_func_implementation()
        elif self.sp_type == StoredProcedureType.SELECT:
            self.return_type = 'results'
            self._generate_select_func_name()
            self._generate_select_func_param_str()
            self._generate_select_func_signature()
            self._generate_select_func_implementation()
        elif self.sp_type == StoredProcedureType.UPDATE:
            self.return_type = 'int'
            self._generate_update_func_name()
            self._generate_update_func_param_str()
            self._generate_update_func_signature()
            self._generate_update_func_implementation()
        elif self.sp_type == StoredProcedureType.DELETE:
            self.return_type = 'int'
            self._generate_delete_func_name()
            self._generate_delete_func_param_str()
            self._generate_delete_func_signature()
            self._generate_delete_func_implementation()


    def _generate_insert_func_name(self):
        self.func_name = f"""insert_into_{self.table_name}_{self.__AND_IN_FUNC_NAME.join(f'{param.column_name}' for param in self.insert_params)}"""


    def _generate_insert_func_param_str(self):
        param_str = ', '.join(
            f'{TypeConverter.mysql_to_cpp_with_const_ref(param.data_type)} new_{param.column_name}' for param in
            self.insert_params)
        self.func_param_str = f'tcp_connection* conn, {param_str}'


    def _generate_insert_func_signature(self):
        self.func_signature = f"static {self.return_type} {self.func_name}({self.func_param_str});"


    def _generate_insert_func_implementation(self):
        class_name = f"{self.owner_table.table_name}_orm"
        bind_params = ', '.join(f'new_{param.column_name}' for param in self.insert_params)
        func_implementation = f"""
inline {self.return_type} {class_name}::{self.func_name}({self.func_param_str})
{{
    results result;
    try
    {{
        auto stmt = conn->prepare_statement("CALL {self.sp_name}({', '.join('?' for _ in self.insert_params)})");
        conn->execute(stmt.bind({bind_params}), result);
    }}
    catch (const error_with_diagnostics& e)
    {{
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return -1;
    }}

    return result.affected_rows();
}}
"""
        self.func_implemetation = func_implementation


    def _generate_select_func_name(self):
        colunm_cnt = len(self.owner_table.columns)
        select_param_str = '_N_'.join(f'{parama.column_name}' for parama in self.select_params)
        select_param_str = 'all' if len(self.select_params) == colunm_cnt else select_param_str

        self.func_name = f"""select_{select_param_str}_from_{self.table_name}"""
        if self.select_where_params:
            self.func_name += self._get_func_name_where_clause(self.select_where_params)


    def _generate_select_func_param_str(self):
        param_str = ', '.join(
            f'{TypeConverter.mysql_to_cpp_with_const_ref(param.data_type)} w_{param.column_name}' for param, _, _ in
            self.select_where_params)
        self.func_param_str = f'tcp_connection* conn, {param_str}'  # select sp는 인자로 where clause에 필요한 인자만 전달한다


    def _generate_select_func_signature(self):
        self.func_signature = f"static {self.return_type} {self.func_name}({self.func_param_str});"


    def _generate_select_func_implementation(self):
        class_name = f"{self.owner_table.table_name}_orm"
        bind_params = ', '.join(f'w_{param.column_name}' for param, _, _ in self.select_where_params)
        func_implementation = f"""
inline {self.return_type} {class_name}::{self.func_name}({self.func_param_str})
{{
    results result;
    try
    {{
        auto stmt = conn->prepare_statement("CALL {self.sp_name}({', '.join('?' for _ in self.select_where_params)})");
        conn->execute(stmt.bind({bind_params}), result);
    }}
    catch (const error_with_diagnostics& e)
    {{
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return result;
    }}

    return result;
}}
"""
        self.func_implemetation = func_implementation


    def _generate_update_func_name(self):
        func_name_update_set_param = '_N_'.join(f'{parama.column_name}' for parama in self.update_set_params)
        func_name_update_where_clause = self._get_func_name_where_clause(self.update_where_params)
        self.func_name = f"""update_{self.table_name}_set_{func_name_update_set_param}{func_name_update_where_clause}"""


    def _generate_update_func_param_str(self):
        update_set_param_str = ', '.join(
            f'{TypeConverter.mysql_to_cpp_with_const_ref(param.data_type)} s_{param.column_name}' for param in
            self.update_set_params)
        update_where_param_str = ', '.join(
            f'{TypeConverter.mysql_to_cpp_with_const_ref(param.data_type)} w_{param.column_name}' for param, op, logic
            in
            self.update_where_params)
        self.func_param_str = f'tcp_connection* conn, {update_set_param_str}, {update_where_param_str}'  # select sp는 인자로 where clause에 필요한 인자만 전달한다


    def _generate_update_func_signature(self):
        self.func_signature = f"static {self.return_type} {self.func_name}({self.func_param_str});"


    def _generate_update_func_implementation(self):
        class_name = f"{self.owner_table.table_name}_orm"
        bind_params = ', '.join(f's_{param.column_name}' for param in self.update_set_params)
        bind_params += ', ' + ', '.join(f'w_{param.column_name}' for param, _, _ in self.update_where_params)
        func_implementation = f"""
inline {self.return_type} {class_name}::{self.func_name}({self.func_param_str})
{{
    results result;
    try
    {{
        auto stmt = conn->prepare_statement("CALL {self.sp_name}({', '.join('?' for _ in self.update_set_params)}, {', '.join('?' for _ in self.update_where_params)})");
        conn->execute(stmt.bind({bind_params}), result);
    }}
    catch (const error_with_diagnostics& e)
    {{
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }}

    return result.affected_rows();
}}
"""
        self.func_implemetation = func_implementation


    def _generate_delete_func_name(self):
        func_name_delete_where_clause = self._get_func_name_where_clause(self.delete_where_params)
        self.func_name = f"""delete_from_{self.table_name}{func_name_delete_where_clause}"""


    def _generate_delete_func_param_str(self):
        param_str = ', '.join(
            f'{TypeConverter.mysql_to_cpp_with_const_ref(param.data_type)} w_{param.column_name}' for param, _, _ in
            self.delete_where_params)
        self.func_param_str = f'tcp_connection* conn, {param_str}'  # select sp는 인자로 where clause에 필요한 인자만 전달한다


    def _generate_delete_func_signature(self):
        self.func_signature = f"static {self.return_type} {self.func_name}({self.func_param_str});"


    def _generate_delete_func_implementation(self):
        class_name = f"{self.owner_table.table_name}_orm"
        bind_params = ', '.join(f'w_{param.column_name}' for param, _, _ in self.delete_where_params)
        func_implementation = f"""
inline {self.return_type} {class_name}::{self.func_name}({self.func_param_str})
{{
    results result;
    try
    {{
        auto stmt = conn->prepare_statement("CALL {self.sp_name}({', '.join('?' for _ in self.delete_where_params)})");
        conn->execute(stmt.bind({bind_params}), result);
    }}
    catch (const error_with_diagnostics& e)
    {{
        std::cerr << "Error in sp_insert: " << e.what() << std::endl;
        return false;
    }}

    return result.affected_rows();
}}
"""
        self.func_implemetation = func_implementation

    # endregion generate a sp function
    def _get_func_name_where_clause(self, where_params: Optional[List[Tuple[ColumnInfo, str, str]]]) -> str:
        where_clause_in_func_name = '_where'
        counter = 0
        if not where_params:
            return ""
        for col, comp_op, logic_op in where_params:
            if logic_op is not None:
                where_clause_in_func_name += f'_{self._get_op_name(comp_op)}_{col.column_name}_{self._get_op_name(logic_op)}_'
            else:
                where_clause_in_func_name += f'_{self._get_op_name(comp_op)}_{col.column_name}'
        return where_clause_in_func_name


    def _get_op_name(self, op: Optional[str]) -> str:
        if op == '=':
            return 'EQ'  # 'equaa'
        elif op == '<':
            return 'LT'  # 'less than'
        elif op == '<=':
            return 'LE'  # 'less or equal'
        elif op == '>':
            return 'GT'  # 'greater than'
        elif op == '>=':
            return 'GE'  # 'greater or equal'
        elif op == 'AND':
            return 'N'
        elif op == 'OR':
            return 'OR'
        elif op is None:
            return ''


    def _generated_sp_where_clause(self, sp_type: StoredProcedureType) -> str:
        where_params: Optional[List[Tuple[ColumnInfo, str, str]]] = None
        if self.sp_type == StoredProcedureType.SELECT:
            where_params = self.select_where_params
        elif self.sp_type == StoredProcedureType.UPDATE:
            where_params = self.update_where_params
        elif self.sp_type == StoredProcedureType.DELETE:
            where_params = self.delete_where_params
        else:
            raise Exception(f"StoredProcedureType({sp_type}) for where clause is invalid ")

        if not where_params or len(where_params) == 0:  # None 또는 길이가 0이면
            return ''

        where_clause = "WHERE "
        for col, comp_op, logical_op in where_params:
            where_clause += f'{col.column_name} {comp_op} w_{col.column_name}'
            if logical_op:
                where_clause += f' {logical_op}\n         '
        where_clause += ';'
        return where_clause


    def generate_func_name(self):
        if self.sp_type == StoredProcedureType.INSERT:
            self._generate_insert_func_name()
        elif self.sp_type == StoredProcedureType.SELECT:
            self._generate_select_func_name()
        elif self.sp_type == StoredProcedureType.UPDATE:
            self._generate_update_func_name()
        elif self.sp_type == StoredProcedureType.DELETE:
            self._generate_delete_func_name()
