# ORMGenerator/ColumnInfo.py
from dataclasses import dataclass
from typing import Optional


@dataclass
class ColumnInfo:
    table_name: str
    column_name: str
    column_id: int
    data_type: str
    max_length: Optional[int]
    is_nullable: bool
    default_definition: Optional[str]
    is_auto_increment: bool  # 변경된 부분
    seed_value: Optional[int]
    is_primary_key: bool
    has_default_current_timestamp: bool
    has_on_update_current_timestamp: bool
