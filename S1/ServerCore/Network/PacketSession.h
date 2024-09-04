#pragma once
#include "SessionBase.h"

namespace ServerCore
{


class PacketSession : public SessionBase
{
public:
    virtual ~PacketSession() override;

protected:
    int32 OnRecv(BYTE* _buffer, int32 _len) override; // PacketHeader를 제거하고 Packet부분을 OnRecvPacket에 넘김
    virtual void OnRecvPacket(BYTE* _buffer, int32 _len) = 0; // PacketHandler에 Packet을 넘김

};
}
