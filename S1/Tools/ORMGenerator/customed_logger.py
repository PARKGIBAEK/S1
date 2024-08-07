# coding=utf-8
from enum import Enum


class ConsoleColor(Enum):
    RESET = "\033[0m"
    BLACK = "\033[30m"
    RED = "\033[31m"
    GREEN = "\033[32m"
    YELLOW = "\033[33m"
    BLUE = "\033[34m"
    MAGENTA = "\033[35m"
    CYAN = "\033[36m"
    WHITE = "\033[37m"


def print_error(message: str, color: ConsoleColor = ConsoleColor.RED):
    print(f"{color.value}{message}{ConsoleColor.RESET.value}")


def print_warning(message: str, color: ConsoleColor = ConsoleColor.YELLOW):
    print(f"{color.value}{message}{ConsoleColor.RESET.value}")


def print_success(message: str, end: str = '\n', color: ConsoleColor = ConsoleColor.GREEN):
    print(f"{color.value}{message}{ConsoleColor.RESET.value}", end=end)


def __print_color(message: str, color: ConsoleColor):
    """
    주어진 메시지를 주어진 색상으로 콘솔에 출력합니다.

    :param message: 출력할 메시지
    :param color: ConsoleColor 클래스의 색상 속성
    """
    print(f"{color.value}{message}{ConsoleColor.RESET.value}")


# 모듈 내에서 __all__ 리스트를 정의하여, from module import * 방식으로 import할 때 공개할 요소를 제한할 수 있습니다.
__all__ = ['print_error', 'print_warning', 'print_success']
