# coding=utf-8
# ORMGenerator/index_info.py
from dataclasses import dataclass
from typing import List
from column_info import ColumnInfo


class IndexInfo:
    def __init__(self, index_name: str, table_name: str, columns: List[ColumnInfo] = None):
        self.index_name: str = index_name
        self.table_name: str = table_name
        self.columns: List[ColumnInfo] = columns if columns is not None else []
