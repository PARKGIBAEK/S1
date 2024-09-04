#include "pch.h"
#include "BufferWriter.h"

namespace ServerCore
{

BufferWriter::BufferWriter(BYTE* _buffer, uint32 _size, uint32 _pos)
	: buffer(_buffer), size(_size), pos(_pos)
{

}

bool BufferWriter::Write(void* _src, uint32 _len)
{
	if (FreeSize() < _len)
		return false;

	::memcpy(&buffer[pos], _src, _len);
	pos += _len;
	return true;
}
}
