#pragma once

#include <framework_fengine.h>
#include <io/network/message/handler_message.hpp>
#include <io/network/message/packet_message.hpp>
#include <handler/cache/serializer/serializes.hpp>
#include <handler/cache/packets_type/packets_type.hpp>
#include <handler/cache/packets_snap/packets_snap.hpp>


#define	PARAMETERS_FUNCTION_SNAPSHOT fe::type::_SOCKET id, uint32_t objid

#pragma warning( disable: 4251 )
namespace fe
{
	class API_DECLSPEC HandlerCache : public HandlerMessage
	{
		std::unordered_map<fe::snapshot::SNAPSHOTTYPE, std::function<fe::snapshot::Snapshot* ()>>	snapshotPacket;

		void	initializePacketType();
		void	initializeSnapshop();

		// packet type
		fe::PacketMessage* onSnapShot();
	public:
		HandlerCache() = default;
		virtual ~HandlerCache() = default;

		// global
		void	initialize() override;

		// emit
		void	sendJoin(fe::type::_SOCKET id, uint32_t idWorld, uint32_t idPlayer, uint32_t authKey,
			uint32_t idParty, uint32_t idGuild, uint32_t idWar,
			uint32_t idOfMulti, uint8_t slot,
			const char* playerName, const char* account, const char* password
		);
		void	sendGetPosition(fe::type::_SOCKET id, uint32_t idMover);
		void	sendDestinationPosition(fe::type::_SOCKET id, const fe::util::Vector3D<float>& destination, uint8_t forward);
	};
}
#pragma warning( default : 4251 )
