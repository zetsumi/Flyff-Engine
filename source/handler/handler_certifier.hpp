#pragma once

#include <framework_fengine.h>
#include <string>
#include <io/network/message/handler_message.hpp>

#define TEST_DEFAULT_BUILD_VERSION	"20100412"
#define TEST_DEFAULT_ACCOUNT		"test10"
#define TEST_DEFAULT_PASSWORD		"4d1677b3d55fd9c68e6baa7b1bd638d0"

namespace fe
{
	class API_DECLSPEC HandlerCertifier : public HandlerMessage
	{
	public:
		HandlerCertifier() = default;
		HandlerCertifier(HandlerCertifier&& h) = default;
		HandlerCertifier(const HandlerCertifier& h) = default;
		HandlerCertifier& operator=(const HandlerCertifier& h) = default;
		~HandlerCertifier() = default;

		// emit
		[[noreturn]] void	sendDisconnectAccount(SOCKET id, const char* account, const char* password);
		[[noreturn]] void	sendCertify(SOCKET id, const char* buildVersion, const char* account, const char* password);
		[[noreturn]] void	sendNewAccount(SOCKET id, const char* account, const char* password);

		// receive
		[[noreturn]] void	initialize(void) override;
		[[noreturn]] void	onServerList(SOCKET id);
		[[noreturn]] void	onError(SOCKET id);
		[[noreturn]] void	onErrorString(SOCKET id);

	};
}
