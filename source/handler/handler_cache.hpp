#pragma once

#include <framework_fengine.h>
#include <io/network/message/handler_message.hpp>
#include <io/network/message/packet_message.hpp>


#define	PARAMETERS_FUNCTION_SNAPSHOT SOCKET id, fe::type::_32uint objid

namespace fe
{
	class API_DECLSPEC HandlerCache : public HandlerMessage
	{
		std::unordered_map<unsigned short, std::function<const fe::PacketMessage* (PARAMETERS_FUNCTION_SNAPSHOT)>> snapshots;

		[[noreturn]] void	initializeSnapshop(void);

		// packet type
		const fe::PacketMessage* onSnapShot(SOCKET id);

		// snapshottype
		const fe::PacketMessage* onEnvironmentAll(PARAMETERS_FUNCTION_SNAPSHOT);
		const fe::PacketMessage* onWorldReadInfo(PARAMETERS_FUNCTION_SNAPSHOT);
		const fe::PacketMessage* onAddObj(PARAMETERS_FUNCTION_SNAPSHOT);
		const fe::PacketMessage* onQueryPlayerData(PARAMETERS_FUNCTION_SNAPSHOT);
		const fe::PacketMessage* onDestPos(PARAMETERS_FUNCTION_SNAPSHOT);
		const fe::PacketMessage* onMoverCorr(PARAMETERS_FUNCTION_SNAPSHOT);
		const fe::PacketMessage* onGetPosition(PARAMETERS_FUNCTION_SNAPSHOT);

	public:
		HandlerCache() = default;
		virtual ~HandlerCache() = default;

		typedef const fe::PacketMessage* (HandlerCache::*callbackSnap)(SOCKET id, fe::type::_32uint objid);
		[[noreturn]] void addSnapShot(unsigned short, callbackSnap action);

		// emit
		[[noreturn]] void	sendJoin(SOCKET id, fe::type::_32uint idWorld, fe::type::_32uint idPlayer, fe::type::_32uint authKey,
			fe::type::_32uint idParty, fe::type::_32uint idGuild, fe::type::_32uint idWar,
			fe::type::_32uint idOfMulti, fe::type::_uchar slot,
			const char* playerName, const char* account, const char* password
		);
		[[noreturn]] void	sendGetPosition(SOCKET id, fe::type::_32uint idMover);
		[[noreturn]] void	sendDestinationPosition(SOCKET id, const fe::Vector3D<float>& destination, fe::type::_uchar forward);

		// global
		[[noreturn]] void	initialize(void) override;

	};
}
