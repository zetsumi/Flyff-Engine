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
		typedef fe::PacketMessage* (HandlerCache::* callbackSnap)(PARAMETERS_FUNCTION_SNAPSHOT);
		std::unordered_map<unsigned short, std::function<fe::PacketMessage* (PARAMETERS_FUNCTION_SNAPSHOT)>> snapshots;

		[[noreturn]] void	initializePacketType(void);
		[[noreturn]] void	initializeSnapshop(void);
		[[noreturn]] void	addSnapShot(unsigned short, callbackSnap action);

		// packet type
		fe::PacketMessage* onSnapShot(fe::type::_SOCKET id);

		// snapshottype
		[[nodiscard]] fe::PacketMessage* onEnvironmentAll(PARAMETERS_FUNCTION_SNAPSHOT);
		[[nodiscard]] fe::PacketMessage* onWorldReadInfo(PARAMETERS_FUNCTION_SNAPSHOT);
		[[nodiscard]] fe::PacketMessage* onAddObj(PARAMETERS_FUNCTION_SNAPSHOT);
		[[nodiscard]] fe::PacketMessage* onQueryPlayerData(PARAMETERS_FUNCTION_SNAPSHOT);
		[[nodiscard]] fe::PacketMessage* onDestPos(PARAMETERS_FUNCTION_SNAPSHOT);
		[[nodiscard]] fe::PacketMessage* onMoverCorr(PARAMETERS_FUNCTION_SNAPSHOT);
		[[nodiscard]] fe::PacketMessage* onGetPosition(PARAMETERS_FUNCTION_SNAPSHOT);

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
