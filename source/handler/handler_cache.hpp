#pragma once

#include <framework_fengine.h>
#include <io/network/message/handler_message.hpp>

#define	PARAMETERS_FUNCTION_SNAPSHOT SOCKET id, fe::type::_32uint objid

namespace fe
{
	class API_DECLSPEC HandlerCache : public HandlerMessage
	{
		std::unordered_map<unsigned short, std::function<void(PARAMETERS_FUNCTION_SNAPSHOT)>> snapshots;

	public:
		HandlerCache() = default;
		virtual ~HandlerCache() = default;

		typedef void (HandlerCache::*callbackSnap)(SOCKET id, fe::type::_32uint objid);
		[[noreturn]] void addSnapShot(unsigned short, callbackSnap action);

		// emit
		[[noreturn]] void	sendJoin(SOCKET id, fe::type::_32uint idWorld, fe::type::_32uint idPlayer, fe::type::_32uint authKey,
			fe::type::_32uint idParty, fe::type::_32uint idGuild, fe::type::_32uint idWar,
			fe::type::_32uint idOfMulti, fe::type::_uchar slot,
			const char* playerName, const char* account, const char* password
		);

		// global
		[[noreturn]] void	initialize(void) override;

		// packet type
		[[noreturn]] void	onSnapShot(SOCKET id);

		// snapshottype
		[[noreturn]] void	onQueryPlayerData(PARAMETERS_FUNCTION_SNAPSHOT);
		[[noreturn]] void	onDestPos(PARAMETERS_FUNCTION_SNAPSHOT);
	};
}
