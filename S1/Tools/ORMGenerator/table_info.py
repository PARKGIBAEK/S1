# coding=utf-8
# ORMGenerator/table_info.py
from typing import Optional, List, Dict
from column_info import ColumnInfo
from index_info import IndexInfo
from stored_procedures import StoredProcedure


class TableInfo:
    def __init__(self, database_name: str, table_name: str,
                 columns: List[ColumnInfo] = None,
                 indices: Optional[List[IndexInfo]] = None,
                 stored_procedures: List[StoredProcedure] = None,
                 comment: Optional[str] = None):
        self.database_name: str = database_name
        self.table_name: str = table_name
        self.columns: List[ColumnInfo] = columns if columns is not None else []
        self.indices: List[IndexInfo] = indices if indices is not None else []
        self.stored_procedures: List[StoredProcedure] = stored_procedures if stored_procedures is not None else []
        self.comment: Optional[str] = comment if comment is not None else ""


    @property
    def join_column_names(self, delimiter: str = ', '):
        return delimiter.join(col.column_name for col in self.columns)