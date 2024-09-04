#pragma once
#include "Memory/Container.h"
#include "Core/Types.h"



namespace ServerCore
{



class RecvBuffer
{
	enum { BUFFER_COUNT = 10 };

public:
	RecvBuffer();
	RecvBuffer(int32 _bufferSize);

	void			Clean();
	bool			OnRead(int32 _numOfBytes); // readCursor 조정
	bool			OnWrite(int32 _numOfBytes); // writeCursor 조정

	BYTE*			ReadPos() { return &m_Buffer[m_ReadCursor]; }
	BYTE*			WritePos() { return &m_Buffer[m_WriteCursor]; }
	int32			DataSize() const { return m_WriteCursor - m_ReadCursor; }
	int32			FreeSize () const { return m_Capacity - m_WriteCursor; }

private:
	int32			m_Capacity = 0;
	int32			m_BufferSize = 0;
	int32			m_ReadCursor = 0;
	int32			m_WriteCursor = 0;
	Vector<BYTE>	m_Buffer;
};
}
