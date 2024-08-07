# coding=utf-8
from dataclasses import dataclass
from typing import Optional


@dataclass
class TypeInfo:
    type_name: str
    length: Optional[int]
    column_id: int
    data_type: str
    max_length: Optional[int]
    is_nullable: bool
    default_definition: Optional[str]
    is_auto_increment: bool
    is_primary_key: bool
    has_default: bool  # 모든 종류의 DEFAULT를 포함
    comment: Optional[str]