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

		[[noreturn]] virtual void	initialize(void);
	};
}
