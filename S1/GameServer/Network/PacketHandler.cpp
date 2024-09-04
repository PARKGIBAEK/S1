#include "pch.h"
#include "PacketHandler.h"

namespace GameServer
{


PacketHandlerFunc g_MessageHandler[std::numeric_limits<uint16_t>::max()];

bool Handle_INVALID_PACKET(PacketSessionRef _session, BYTE* _buffer, int32 _len)
{
    return true;
}

bool Handle_SIGNUP_ACK(PacketSessionRef& _session, Protocol::SIGNUP_ACK& _msg)
{
    return true;
}

bool Handle_CREATE_CHARACTER_ACK(PacketSessionRef& _session, Protocol::CREATE_CHARACTER_ACK& _msg)
{
    return true;
}

bool Handle_LOGIN_ACK(PacketSessionRef& _session, Protocol::LOGIN_ACK& _msg)
{
    return true;
}

bool Handle_ENTER_GAME_ACK(PacketSessionRef& _session, Protocol::ENTER_GAME_ACK& _msg)
{
    return true;
}

bool Handle_CHAT_ACK(PacketSessionRef& _session, Protocol::CHAT_ACK& _msg)
{
    return true;
}


}
