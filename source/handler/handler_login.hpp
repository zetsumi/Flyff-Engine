#pragma once

#include <framework_fengine.h>

namespace fe
{
	class API_DECLSPEC HandlerLogin : public HandlerMessage
	{
	public:
		HandlerLogin() = default;
		HandlerLogin(HandlerLogin&& h) = default;
		HandlerLogin(const HandlerLogin& h) = default;
		HandlerLogin& operator=(const HandlerLogin& h) = default;
		~HandlerLogin() = default;

		//[[noreturn]] void	sendPreJoin(void);

		[[noreturn]] virtual void	initialize(void);
	};
}


