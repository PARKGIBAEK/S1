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

	BYTE*			ReadPos() { return &buffer[readCursor]; }
	BYTE*			WritePos() { return &buffer[writeCursor]; }
	int32			DataSize() const { return writeCursor - readCursor; }
	int32			FreeSize () const { return capacity - writeCursor; }

private:
	int32			capacity = 0;
	int32			bufferSize = 0;
	int32			readCursor = 0;
	int32			writeCursor = 0;
	Vector<BYTE>	buffer;
};
}