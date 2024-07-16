#pragma once
#include <memory>
#include "Core/Types.h"

namespace ServerCore
{

class SendBufferChunk;

class SendBuffer
{
public:
	SendBuffer(std::shared_ptr<SendBufferChunk> _owner, BYTE* _buffer, uint32 _allocSize);
	~SendBuffer();

	BYTE*				Buffer() const;
	uint32				AllocSize() const;
	uint32				WriteSize() const;
	void				Close(uint32 _writeSize);

	
	SendBuffer(const SendBuffer&) = delete;
	SendBuffer(SendBuffer&&)=delete;
	SendBuffer& operator=(const SendBuffer&) = delete;
	SendBuffer& operator=(const SendBuffer&&) = delete;
	
private:
	BYTE*				                m_Buffer;
	uint32				                m_AllocSize;
	uint32				                m_WriteSize;
	std::shared_ptr<SendBufferChunk>	m_Owner;
};


}