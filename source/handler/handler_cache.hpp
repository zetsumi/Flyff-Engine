#pragma once

#include <framework_fengine.h>
#include <io/network/message/handler_message.hpp>

namespace fe
{
	class API_DECLSPEC HandlerCache : public HandlerMessage
	{
	public:
		HandlerCache() = default;
		~HandlerCache() = default;

		// emit
		[[noreturn]] void	sendJoin(SOCKET id, fe::type::_32uint idWorld, fe::type::_32uint idPlayer, fe::type::_32uint authKey,
			fe::type::_32uint idParty, fe::type::_32uint idGuild, fe::type::_32uint idWar,
			fe::type::_32uint idOfMulti, fe::type::_uchar slot,
			const char* playerName, const char* account, const char* password
		);

		// global
		[[noreturn]] void	initialize(void) override;

		// receive
		[[noreturn]] void	onSnapShot(SOCKET id);
		[[noreturn]] void	onJoin(SOCKET id);
	};
}
