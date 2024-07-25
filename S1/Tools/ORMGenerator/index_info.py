# ORMGenerator/index_info.py
from dataclasses import dataclass
from typing import List
from column_info import ColumnInfo


@dataclass
class IndexInfo:
    table_name: str
    index_name: str
    columns: List[ColumnInfo]
    is_unique: bool
