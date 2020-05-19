#pragma once

#include <framework_fengine.h>
#include <string>
#include <mutex>
#include <io/network/message/handler_message.hpp>

#define TEST_DEFAULT_BUILD_VERSION	"20100412"
#define TEST_DEFAULT_ACCOUNT		"test10"
#define TEST_DEFAULT_PASSWORD		"4d1677b3d55fd9c68e6baa7b1bd638d0"

namespace fe
{
	class API_DECLSPEC HandlerCertifier : public HandlerMessage
	{
		std::mutex			lockerSend;
		fe::type::_32uint	sessionID = 0;

		[[noreturn]] void	sendDisconnectAccount(SOCKET id, const char* account, const char* password);
		[[noreturn]] void	sendCertify(SOCKET id, const char* buildVersion, const char* account, const char* password);
		[[noreturn]] void	sendKeepAlive(SOCKET id);
		[[noreturn]] void	sendError(SOCKET id);
		[[noreturn]] void	sendNewAccount(SOCKET id, const char* account, const char* password);

	public:
		HandlerCertifier() = default;
		~HandlerCertifier() = default;

		[[noreturn]] void	initialize(void) override;
		[[noreturn]] void	onWelcome(SOCKET id);
		[[noreturn]] void	onKeepAlive(SOCKET id);
		[[noreturn]] void	onPing(SOCKET id);
		[[noreturn]] void	onServerList(SOCKET id);
		[[noreturn]] void	onError(SOCKET id);
		[[noreturn]] void	onErrorString(SOCKET id);

	};
}

#define	ON_PACKETTYPE(packettype, fct) \
	if (pushAction(packettype, std::bind(fct, this, std::placeholders::_1)) == false) \
		FE_CONSOLELOG("fail add action on packet type [%u]", packettype);

#define	FE_SEND(pb) \
	auto buffer = pb.getData(); \
	auto length = pb.getSize(); \
	if (buffer != nullptr && length > 0) \
		::send(id, (char*)buffer, length, 0);
