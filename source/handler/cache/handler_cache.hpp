#pragma once

#include <framework_fengine.h>
#include <io/network/message/handler_message.hpp>
#include <io/network/message/packet_message.hpp>
#include <handler/cache/packets_type/packets_type.hpp>
#include <handler/cache/packets_snap/packets_snap.hpp>


#define	PARAMETERS_FUNCTION_SNAPSHOT fe::type::_SOCKET id, fe::type::_32uint objid

#pragma warning( disable: 4251 )
namespace fe
{
	class API_DECLSPEC HandlerCache : public HandlerMessage
	{
		std::unordered_map<unsigned short, std::function<fe::snapshot::Snapshot* (void)>>	snapshotPacket;

		[[noreturn]] void	initializePacketType(void);
		[[noreturn]] void	initializeSnapshop(void);

		// packet type
		fe::PacketMessage* onSnapShot(void);
	public:
		HandlerCache() = default;
		virtual ~HandlerCache() = default;

		// global
		[[noreturn]] void	initialize(void) override;

		// emit
		[[noreturn]] void	sendJoin(fe::type::_SOCKET id, fe::type::_32uint idWorld, fe::type::_32uint idPlayer, fe::type::_32uint authKey,
			fe::type::_32uint idParty, fe::type::_32uint idGuild, fe::type::_32uint idWar,
			fe::type::_32uint idOfMulti, fe::type::_uchar slot,
			const char* playerName, const char* account, const char* password
		);
		[[noreturn]] void	sendGetPosition(fe::type::_SOCKET id, fe::type::_32uint idMover);
		[[noreturn]] void	sendDestinationPosition(fe::type::_SOCKET id, const fe::Vector3D<float>& destination, fe::type::_uchar forward);
	};
}
#pragma warning( default : 4251 )
