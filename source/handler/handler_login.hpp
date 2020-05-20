#pragma once

#include <framework_fengine.h>

namespace fe
{
	class API_DECLSPEC HandlerLogin : public HandlerMessage
	{
		char* cacheServerAddr = nullptr;

	public:
		HandlerLogin() = default;
		HandlerLogin(HandlerLogin&& h) = default;
		HandlerLogin(const HandlerLogin& h) = default;
		HandlerLogin& operator=(const HandlerLogin& h) = default;
		~HandlerLogin() = default;

		// global
		[[noreturn]] virtual void	initialize(void);
		[[nodiscard]] const char* getCacheServerAddr(void) const;

		// emit
		[[noreturn]] void	sendQueryTickCount(SOCKET id);
		[[noreturn]] void	sendGetListPlayer(SOCKET id, const char* protocolVersion, fe::type::_32uint authKey,
												const char* account, const char* password, fe::type::_32uint idServer);
		[[noreturn]] void	sendPreJoin(SOCKET id, const char* account, fe::type::_32uint idPlayer, const char* playerName, fe::type::_32int secretPIN);


		// receiver
		[[noreturn]] virtual void	onQueryTickCount(SOCKET id);
		[[noreturn]] virtual void	onCacheAddr(SOCKET id);
		[[noreturn]] virtual void	onPlayerList(SOCKET id);
		[[noreturn]] virtual void	onProtectNumPad(SOCKET id);
		[[noreturn]] virtual void	onProtectLoginCert(SOCKET id);
		[[noreturn]] virtual void	onPreJoin(SOCKET id);


	};
}
