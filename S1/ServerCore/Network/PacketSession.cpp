#include "pch.h"
#include "PacketSession.h"

namespace ServerCore
{


PacketSession::~PacketSession()
{
}

// _buffer는 m_recvBuffer.ReadPos()
// _len은 m_recvBuffer.DataSize()를 넘겨받은 상태
int32 PacketSession::OnRecv(BYTE* _buffer, int32 _len)
{
    while (true)
    {
        // 패킷 헤더 사이즈 확인
        if (m_recvBuffer.DataSize() < PACKET_HEADER_SIZE)
            break;
        // 파싱 가능한 크기 만큼 수신했는지 확인
        PacketHeader* packetHeader = reinterpret_cast<PacketHeader*>(m_recvBuffer.ReadPos());
        if (m_recvBuffer.DataSize() < packetHeader->size)
            break; // 완전한 패킷을 수신하지 못한 경우 빠져 나가서 ContinueAsyncRecv재호출
        OnRecvPacket(_buffer, _len); // TODO : 자식 클래스에서 OnRecvPacket 메서드 재정의 필수
        return packetHeader->size; // 처리한 패킷 크기
    }

    return 0;
}


}
