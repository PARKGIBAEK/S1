#pragma once
#include "Core/CoreMacro.h"
#include "Core/Types.h"


namespace ServerCore
{

class BufferReader
{
public:
	BufferReader(BYTE* _buffer, uint32 _size, uint32 _pos = 0);

	BYTE*			Buffer() const { return buffer; }
	uint32			Size() const { return size; }
	uint32			ReadSize() const { return pos; }
	uint32			FreeSize() const { return size - pos; }

	template<typename T>
	bool			Peek(T* _dest) { return Peek(_dest, sizeof(T)); }
	bool			Peek(void* _dest, uint32 _len);

	template<typename T>
	bool			Read(T* _dest) { return Read(_dest, sizeof(T)); }
	bool			Read(void* _dest, uint32 _len);

	template<typename T>
	BufferReader&	operator>>(OUT T& _dest);

private:
	BYTE*			buffer = nullptr;
	uint32			size = 0;
	uint32			pos = 0;
};

template<typename T>
inline BufferReader& BufferReader::operator>>(OUT T& _dest)
{
	_dest = *reinterpret_cast<T*>(&buffer[pos]);
	pos += sizeof(T);
	return *this;
}
}
