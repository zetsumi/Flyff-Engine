#pragma once

#include <framework_fengine.h>
#include <io/network/message/handler_message.hpp>
#include <io/network/message/packet_message.hpp>
#include <handler/login/packets/packet_logins.hpp>

namespace fe
{
	class API_DECLSPEC HandlerLogin : public HandlerMessage
	{
		char* cacheServerAddr = nullptr;

		// recv
		[[nodiscard]] fe::PacketMessage* onQueryTickCount();
		[[nodiscard]] fe::PacketMessage* onCacheAddr();
		[[nodiscard]] fe::PacketMessage* onPlayerList();
		[[nodiscard]] fe::PacketMessage* onProtectNumPad();
		[[nodiscard]] fe::PacketMessage* onProtectLoginCert();
		[[nodiscard]] fe::PacketMessage* onPreJoin();

	public:
		HandlerLogin() = default;
		HandlerLogin(HandlerLogin&& h) = default;
		HandlerLogin(const HandlerLogin& h) = default;
		HandlerLogin& operator=(const HandlerLogin& h) = default;
		~HandlerLogin();

		// global
		void	initialize() override;
		const char* getCacheServerAddr() const;

		// emit
		void	sendQueryTickCount(fe::type::_SOCKET id);
		void	sendGetListPlayer(fe::type::_SOCKET id, const char* protocolVersion, uint32_t authKey, const char* account, const char* password, uint32_t idServer);
		void	sendPreJoin(fe::type::_SOCKET id, const char* account, uint32_t idPlayer, const char* playerName, int32_t secretPIN);
	};
}
