#include "BufferReader.h"



namespace ServerCore
{
BufferReader::BufferReader(BYTE* _buffer, uint32 _size, uint32 _pos)
	: buffer(_buffer), size(_size), pos(_pos)
{

}


bool BufferReader::Peek(void* _dest, uint32 _len)
{
	if (FreeSize() < _len)
		return false;

	::memcpy(_dest, &buffer[pos], _len);
	return true;
}

bool BufferReader::Read(void* _dest, uint32 _len)
{
	if (Peek(_dest, _len) == false)
		return false;

	pos += _len;
	return true;
}
}