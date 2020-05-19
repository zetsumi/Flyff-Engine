#pragma once

#include <framework_fengine.h>
#include <winsock.h>
#include <thread>
#include <mutex>
#include <unordered_map>
#include <io/network/emit/packet_structure.hpp>
#include <io/network/message/packet_type.hpp>


namespace fe
{
	class API_DECLSPEC HandlerMessage
	{
		[[noreturn]] void	loadHeader(fe::type::_uchar& mark, fe::type::_32uint& length);

	protected:
		std::unordered_map<fe::type::_32uint, std::function<void(SOCKET id)>>	actions{};
		std::thread	ping{};
		fe::PacketBuilder	packetBuilder{};
		fe::type::_32uint	sessionID = 0;
		std::mutex			lockerSend;
		fe::type::_32uint	dpid = 0xffffffff;
		HANDLER_PACKET_TYPE	handlerType = HANDLER_PACKET_TYPE::UNKNOW;

		// global
		[[nodiscard]] bool	pushAction(fe::type::_32uint packetType, std::function<void(SOCKET id)> action);

		// emit & receive
		[[noreturn]] void	sendPing(SOCKET id);
		[[noreturn]] void	processPing(SOCKET id);

	public:
		HandlerMessage() = default;
		HandlerMessage(HandlerMessage&& h) = default;
		HandlerMessage(const HandlerMessage& h) = default;
		HandlerMessage& operator=(const HandlerMessage& h) = default;
		virtual ~HandlerMessage() = default;

		[[noreturn]] void	sendKeepAlive(SOCKET id);
		[[noreturn]] void	sendError(SOCKET id);

		[[noreturn]] virtual void	initialize(void) = 0;
		[[nodiscard]] void	onMsg(SOCKET id, fe::PacketStructure* ps);
		[[noreturn]] void	onWelcome(SOCKET id);
		[[noreturn]] void	onKeepAlive(SOCKET id);
		[[noreturn]] void	onPing(SOCKET id);
	};

	typedef void	(*callbackOnMessage)(SOCKET id, fe::PacketStructure* ps);
	typedef void	(HandlerMessage::*callbackHandlerMessage)(SOCKET id, fe::PacketStructure* ps);
}

#define	ON_PACKETTYPE(packettype, fct) \
	if (pushAction(packettype, std::bind(fct, this, std::placeholders::_1)) == false) \
		FE_CONSOLELOG("fail add action on packet type [%u]", packettype);

#define	FE_SEND(pb, idSocket) \
	auto buffer = pb.getData(); \
	auto length = pb.getSize(); \
	if (buffer != nullptr && length > 0) \
		::send(idSocket, (char*)buffer, length, 0);