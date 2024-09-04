#include "pch.h"
#include "ConsoleLog.h"
#include <iostream>
#ifdef _WIN32
#include <windows.h>
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#else
#include <unistd.h>
#endif


namespace ServerCore
{
// c 표준 입출력 핸들 받아오기
inline HANDLE ConsoleLog::m_stdOut = ::GetStdHandle(STD_OUTPUT_HANDLE);
inline HANDLE ConsoleLog::m_stdErr = ::GetStdHandle(STD_ERROR_HANDLE);

ConsoleLog::ConsoleLog()
{
    // m_stdOut = ::GetStdHandle(STD_OUTPUT_HANDLE);
    // m_stdErr = ::GetStdHandle(STD_ERROR_HANDLE);
}

ConsoleLog::~ConsoleLog()
{
}

void ConsoleLog::WriteStdOut(Color color, const WCHAR* format, ...)
{
    if (format == nullptr)
        return;

    SetColor(true, color);

    va_list ap;
    va_start(ap, format);
    ::vwprintf(format, ap);
    va_end(ap);

    fflush(stdout);

    SetColor(true, Color::WHITE);
}

void ConsoleLog::WriteStdOut(const WCHAR* format, ...)
{
    if (format == nullptr)
        return;

    SetColor(true, Color::WHITE);

    va_list ap;
    va_start(ap, format);
    ::vwprintf(format, ap);
    va_end(ap);

    fflush(stdout);

    SetColor(true, Color::WHITE);
}

void ConsoleLog::WriteStdOut(const std::wstring& str)
{
    if (str.empty())
        return;

    SetColor(false, Color::WHITE);

    std::wcout << str << std::endl;

    fflush(stdout);

    SetColor(true, Color::WHITE);
}

void ConsoleLog::WriteStdErr(Color color, const WCHAR* format, ...)
{
    WCHAR buffer[BUFFER_SIZE];

    if (format == nullptr)
        return;

    SetColor(false, color);

    va_list ap;
    va_start(ap, format);
    int ret = ::vswprintf_s(buffer, BUFFER_SIZE, format, ap);
    va_end(ap);

    if (ret < 0)
    {
        // 버퍼 초기화 실패 시 안전한 기본값 설정
        buffer[0] = L'\0';
    }

    ::fwprintf_s(stderr, L"%ls", buffer);

    fflush(stderr);

    SetColor(false, Color::WHITE);
}

void ConsoleLog::WriteStdErr(Color color, const std::wstring& str)
{
    if (str.empty())
        return;

    SetColor(false, color);

    std::wcerr << str << '\n';

    fflush(stderr);

    SetColor(false, Color::WHITE);
}

void ConsoleLog::WriteStdErr(const WCHAR* format, ...)
{
    WCHAR buffer[BUFFER_SIZE];

    if (format == nullptr)
        return;

    SetColor(false, Color::RED);

    va_list ap;
    va_start(ap, format);
    int ret = ::vswprintf_s(buffer, BUFFER_SIZE, format, ap);
    va_end(ap);

    if (ret < 0)
    {
        // 버퍼 초기화 실패 시 안전한 기본값 설정
        buffer[0] = L'\0';
    }

    ::fwprintf_s(stderr, L"%ls", buffer);

    fflush(stderr);

    SetColor(false, Color::WHITE);
}

void ConsoleLog::WriteStdErr(const std::wstring& str)
{
    if (str.empty())
        return;

    SetColor(false, Color::RED);

    std::wcerr << str << '\n';

    fflush(stderr);
    SetColor(false, Color::WHITE);
}

void ConsoleLog::SetColor(bool stdOut, Color color)
{
    static WORD SColors[]
    {
        0,
        FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
        FOREGROUND_RED | FOREGROUND_INTENSITY,
        FOREGROUND_GREEN | FOREGROUND_INTENSITY,
        FOREGROUND_BLUE | FOREGROUND_INTENSITY,
        FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY
    };

    ::SetConsoleTextAttribute(stdOut ? m_stdOut : m_stdErr, SColors[static_cast<int32>(color)]);
}
}
