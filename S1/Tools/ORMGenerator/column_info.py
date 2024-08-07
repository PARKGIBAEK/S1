# coding=utf-8
# ORMGenerator/column_info.py
from dataclasses import dataclass
from typing import Optional


@dataclass
class ColumnInfo:
    table_name: str
    column_id: int
    column_name: str
    data_type: str
    max_length: Optional[int] = None
    is_nullable: bool = False
    default_definition: Optional[str] = None
    column_comment: Optional[str] = None
    is_auto_increment: bool = False
    is_primary_key: bool = False
    timestamp_on_update: bool = False
    timestamp_on_create: bool = False
    required_when_insert: bool = False
    auto_generated: bool = False
    is_comparable: bool = False


    #
    # def __init__(self, table_name: str, column_id: int, column_name: str, data_type: str):
    #     self.table_name = table_name
    #     self.column_id = column_id
    #     self.column_name = column_name
    #     self.data_type = data_type

    def __eq__(self, other):
        if not isinstance(other, ColumnInfo):
            return NotImplemented
        return self.column_name == other.column_name and self.table_name == other.table_name


    def __hash__(self):
        return hash((self.column_name, self.table_name))


    @property
    def data_type_with_length(self) -> str:
        if self.max_length is not None:
            return f"{self.data_type}({self.max_length})"
        else:
            return self.data_type


    @property
    def column_name_and_data_type_with_length(self) -> str:
        if self.max_length is not None:
            return f"{self.column_name} {self.data_type}({self.max_length})"
        else:
            return f"{self.column_name} {self.data_type}"
