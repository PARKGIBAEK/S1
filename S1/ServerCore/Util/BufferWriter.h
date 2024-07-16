#pragma once
#include "Core/Types.h"


namespace ServerCore
{

class BufferWriter
{
public:
	BufferWriter(BYTE* _buffer, uint32 size, uint32 pos = 0);

BYTE*				Buffer() const { return buffer; }
	uint32			Size() const { return size; }
	uint32			WriteSize() const { return pos; }
	uint32			FreeSize() const { return size - pos; }

	template<typename T>
	bool				Write(T* _src) { return Write(_src, sizeof(T)); }
	bool				Write(void* _src, uint32 _len);

	template<typename T>
	T*					Reserve(uint16 _count = 1);

	template<typename T>
	BufferWriter&	operator<<(T&& _src);

private:
	BYTE*			buffer = nullptr;
	uint32			size = 0;
	uint32			pos = 0;
};

template<typename T>
T* BufferWriter::Reserve(uint16 _count)
{
	if (FreeSize() < (sizeof(T) * _count))
		return nullptr;

	T* ret = reinterpret_cast<T*>(&buffer[pos]);
	pos += (sizeof(T) * _count);
	return ret;
}

template<typename T>
BufferWriter& BufferWriter::operator<<(T&& _src)
{
	using DataType = std::remove_reference_t<T>;
	*reinterpret_cast<DataType*>(&buffer[pos]) = std::forward<DataType>(_src);
	pos += sizeof(T);
	return *this;
}
}