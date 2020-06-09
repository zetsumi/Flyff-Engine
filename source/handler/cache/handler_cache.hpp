#pragma once

#include <framework_fengine.h>
#include <io/network/message/handler_message.hpp>
#include <io/network/message/packet_message.hpp>
#include <handler/cache/serializer/serializes.hpp>
#include <handler/cache/packets_type/packets_type.hpp>
#include <handler/cache/packets_snap/packets_snap.hpp>


#define	PARAMETERS_FUNCTION_SNAPSHOT fe::type::_SOCKET id, fe::type::_32uint objid

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
		void	sendJoin(fe::type::_SOCKET id, fe::type::_32uint idWorld, fe::type::_32uint idPlayer, fe::type::_32uint authKey,
			fe::type::_32uint idParty, fe::type::_32uint idGuild, fe::type::_32uint idWar,
			fe::type::_32uint idOfMulti, fe::type::_uchar slot,
			const char* playerName, const char* account, const char* password
		);
		void	sendGetPosition(fe::type::_SOCKET id, fe::type::_32uint idMover);
		void	sendDestinationPosition(fe::type::_SOCKET id, const fe::Vector3D<float>& destination, fe::type::_uchar forward);
	};
}
#pragma warning( default : 4251 )
