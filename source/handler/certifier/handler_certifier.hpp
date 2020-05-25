#pragma once

#include <framework_fengine.h>
#include <string>
#include <io/network/message/handler_message.hpp>
#include <io/network/message/packet_message.hpp>
#include <handler/certifier/packets/packet_certifiers.hpp>


namespace fe
{
	class API_DECLSPEC HandlerCertifier : public HandlerMessage
	{
		// recv
		[[nodiscard]] fe::PacketMessage* onServerList(fe::type::_SOCKET id);

	public:
		HandlerCertifier() = default;
		HandlerCertifier(HandlerCertifier&& h) = default;
		HandlerCertifier(const HandlerCertifier& h) = default;
		HandlerCertifier& operator=(const HandlerCertifier& h) = default;
		~HandlerCertifier() = default;

		// global
		[[noreturn]] void	initialize(void) override;
		inline constexpr fe::type::_32uint getAuthKey(void) const { return authKey; }

		// emit
		[[noreturn]] void	sendDisconnectAccount(fe::type::_SOCKET id, const char* account, const char* password);
		[[noreturn]] void	sendCertify(fe::type::_SOCKET id, const char* buildVersion, const char* account, const char* password);
		[[noreturn]] void	sendNewAccount(fe::type::_SOCKET id, const char* account, const char* password);
	};
}
