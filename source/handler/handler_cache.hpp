#pragma once

#include <framework_fengine.h>
#include <io/network/message/handler_message.hpp>


#define	PARAMETERS_FUNCTION_SNAPSHOT SOCKET id, fe::type::_32uint objid

namespace fe
{
	class API_DECLSPEC HandlerCache : public HandlerMessage
	{
		std::unordered_map<unsigned short, std::function<void(PARAMETERS_FUNCTION_SNAPSHOT)>> snapshots;

		[[noreturn]] void	initializeSnapshop(void);

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
		[[noreturn]] void	sendGetPosition(SOCKET id, fe::type::_32uint idMover);
		[[noreturn]] void	sendDestinationPosition(SOCKET id, const fe::Vector3D<float>& destination, fe::type::_uchar forward);

		// global
		[[noreturn]] void	initialize(void) override;

		// packet type
		[[noreturn]] void	onSnapShot(SOCKET id);

		// snapshottype
		[[noreturn]] void	onEnvironmentAll(PARAMETERS_FUNCTION_SNAPSHOT);
		[[noreturn]] void	onWorldReadInfo(PARAMETERS_FUNCTION_SNAPSHOT);
		[[noreturn]] void	onAddObj(PARAMETERS_FUNCTION_SNAPSHOT);

		[[noreturn]] void	onQueryPlayerData(PARAMETERS_FUNCTION_SNAPSHOT);
		[[noreturn]] void	onDestPos(PARAMETERS_FUNCTION_SNAPSHOT);
		[[noreturn]] void	onMoverCorr(PARAMETERS_FUNCTION_SNAPSHOT);
		[[noreturn]] void	onGetPosition(PARAMETERS_FUNCTION_SNAPSHOT);

	};
}
