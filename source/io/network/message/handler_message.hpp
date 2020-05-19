#pragma once

#include <framework_fengine.h>
#include <winsock.h>
#include <unordered_map>
#include <io/network/emit/packet_structure.hpp>
#include <io/network/message/packet_type.hpp>


namespace fe
{
	class API_DECLSPEC HandlerMessage
	{
		[[noreturn]] void	loadHeader(fe::type::_uchar& mark, fe::type::_32uint& length);

	protected:
		[[nodiscard]] bool	pushAction(fe::type::_uint packetType, std::function<void(SOCKET id)> action);

		std::unordered_map<fe::type::_uint, std::function<void(SOCKET id)>>	actions;
		fe::PacketBuilder	pb{};

	public:
		HandlerMessage() = default;
		virtual ~HandlerMessage() = default;

		[[noreturn]] virtual void	initialize() = 0;
		[[nodiscard]] void	onMsg(SOCKET id, fe::PacketStructure* ps);
	};

	typedef void	(*callbackOnMessage)(SOCKET id, fe::PacketStructure* ps);
	typedef void	(HandlerMessage::*callbackHandlerMessage)(SOCKET id, fe::PacketStructure* ps);
}
