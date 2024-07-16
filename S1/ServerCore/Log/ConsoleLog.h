#pragma once
#include "Core/Core.h"
#include "Core/Types.h"


namespace ServerCore
{
typedef void* HANDLE;
enum class Color
{
	BLACK,
	WHITE,
	RED,
	GREEN,
	BLUE,
	YELLOW,
};

class ConsoleLog
{
	// typedef void *HANDLE;
	enum { BUFFER_SIZE = 4096 };

public:
	ConsoleLog();
	~ConsoleLog();

public:
	static void		WriteStdOut(Color color, const WCHAR* format, ...);
	static void		WriteStdErr(Color color, const WCHAR* format, ...);
	static void		WriteStdErr(const WCHAR* format, ...);
	static void		WriteStdErr(const std::wstring& str);

protected:
	static void		SetColor(bool stdOut, Color color);

private:
	static HANDLE		_stdOut;
	static HANDLE		_stdErr;
};
}