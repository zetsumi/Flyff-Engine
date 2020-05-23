#pragma once

#include <framework_fengine.h>
#include <io/network/message/handler_message.hpp>
#include <io/network/message/packet_message.hpp>

namespace fe
{
	class API_DECLSPEC HandlerLogin : public HandlerMessage
	{
		char* cacheServerAddr = nullptr;

		// recv
		fe::PacketMessage* onQueryTickCount(SOCKET id);
		fe::PacketMessage* onCacheAddr(SOCKET id);
		fe::PacketMessage* onPlayerList(SOCKET id);
		fe::PacketMessage* onProtectNumPad(SOCKET id);
		fe::PacketMessage* onProtectLoginCert(SOCKET id);
		fe::PacketMessage* onPreJoin(SOCKET id);

	public:
		HandlerLogin() = default;
		HandlerLogin(HandlerLogin&& h) = default;
		HandlerLogin(const HandlerLogin& h) = default;
		HandlerLogin& operator=(const HandlerLogin& h) = default;
		~HandlerLogin() = default;

		// global
		[[noreturn]] void	initialize(void) override;
		[[nodiscard]] const char* getCacheServerAddr(void) const;

		// emit
		[[noreturn]] void	sendQueryTickCount(SOCKET id);
		[[noreturn]] void	sendGetListPlayer(SOCKET id, const char* protocolVersion, fe::type::_32uint authKey,
												const char* account, const char* password, fe::type::_32uint idServer);
		[[noreturn]] void	sendPreJoin(SOCKET id, const char* account, fe::type::_32uint idPlayer, const char* playerName, fe::type::_32int secretPIN);
	};
}
