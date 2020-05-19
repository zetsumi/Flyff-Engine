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
		[[nodiscard]] bool	pushAction(fe::type::_32uint packetType, std::function<void(SOCKET id)> action);

		std::unordered_map<fe::type::_32uint, std::function<void(SOCKET id)>>	actions;
		fe::PacketBuilder	packetBuilder{};

	public:
		HandlerMessage() = default;
		virtual ~HandlerMessage() = default;

		[[noreturn]] virtual void	initialize(void) = 0;
		[[nodiscard]] void	onMsg(SOCKET id, fe::PacketStructure* ps);
	};

	typedef void	(*callbackOnMessage)(SOCKET id, fe::PacketStructure* ps);
	typedef void	(HandlerMessage::*callbackHandlerMessage)(SOCKET id, fe::PacketStructure* ps);
}

#define	ON_PACKETTYPE(packettype, fct) \
	if (pushAction(packettype, std::bind(fct, this, std::placeholders::_1)) == false) \
		FE_CONSOLELOG("fail add action on packet type [%u]", packettype);

#define	FE_SEND(pb) \
	auto buffer = pb.getData(); \
	auto length = pb.getSize(); \
	if (buffer != nullptr && length > 0) \
		::send(id, (char*)buffer, length, 0);