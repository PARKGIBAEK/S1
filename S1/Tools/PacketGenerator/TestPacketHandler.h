#pragma once
#include <functional>
#include <memory>
#include "Network/Session.h"
#include "Protocol.pb.h"
#include "Core/Types.h"
#include "Network/SendBuffer.h"
#include "Core/CoreInitializer.h"
#include "Core/CoreMacro.h"
#include "Network/PacketSession.h"
#include "Network/PacketHeader.h"
#include "Network/SendBufferManager.h"

namespace #error
{

using namespace ServerCore;

using PacketHandlerFunc = std::function<bool(std::shared_ptr<PacketSession>&, BYTE*, int32)>;

extern PacketHandlerFunc GPacketHandler[UINT16_MAX];

enum : uint16
{

};

// Custom Handlers
bool Handle_INVALID(std::shared_ptr<PacketSession>& session, BYTE* buffer, int32 len);



class TestPacketHandler
{
public:
	static void Init()
	{
		for (int32 i = 0; i < UINT16_MAX; i++)
			GPacketHandler[i] = Handle_INVALID;


	}

	static bool HandlePacket(std::shared_ptr<PacketSession>& session, BYTE* buffer, int32 len)
	{
		PacketHeader* header = reinterpret_cast<PacketHeader*>(buffer);
		return GPacketHandler[header->id](session, buffer, len);
	}



private:
	template<typename PacketType, typename ProcessFunc>
	static bool HandlePacket(ProcessFunc func, std::shared_ptr<PacketSession>& session, BYTE* buffer, int32 len)
	{
		PacketType pkt;
		if (pkt.ParseFromArray(buffer + sizeof(PacketHeader), len - sizeof(PacketHeader)) == false)
			return false;

		return func(session, pkt);
	}

	template<typename T>
	static std::shared_ptr<SendBuffer> MakeSendBuffer(T& pkt, uint16 pktId)
	{
		const uint16 dataSize = static_cast<uint16>(pkt.ByteSizeLong());
		const uint16 packetSize = dataSize + sizeof(PacketHeader);

		std::shared_ptr<SendBuffer> sendBuffer = GSendBufferManager->Open(packetSize);
		PacketHeader* header = reinterpret_cast<PacketHeader*>(sendBuffer->Buffer());
		header->size = packetSize;
		header->id = pktId;
		ASSERT_CRASH(pkt.SerializeToArray(&header[1], dataSize));
		sendBuffer->Close(packetSize);

		return sendBuffer;
	}
};
}