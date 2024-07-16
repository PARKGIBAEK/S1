#include "SendBuffer.h"

#include "Core/CoreMacro.h"
#include "Network/SendBufferChunk.h"


namespace ServerCore
{
SendBuffer::SendBuffer(std::shared_ptr<SendBufferChunk>  _owner, BYTE* _buffer, uint32 _allocSize)
	: m_Buffer(_buffer), m_AllocSize(_allocSize), m_WriteSize(0), m_Owner(_owner)
{
}

SendBuffer::~SendBuffer()
{
}

BYTE* SendBuffer::Buffer() const
{ return m_Buffer; }

uint32 SendBuffer::AllocSize() const
{ return m_AllocSize; }

uint32 SendBuffer::WriteSize() const
{ return m_WriteSize; }

void SendBuffer::Close(uint32 _writeSize)
{
	ASSERT_CRASH(m_AllocSize >= _writeSize);
	m_WriteSize = _writeSize;
	m_Owner->Close(_writeSize);
}

}
