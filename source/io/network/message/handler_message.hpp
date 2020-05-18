#pragma once

#include <winsock.h>
#include <unordered_map>
#include <io/network/emit/packet_structure.hpp>


namespace fe
{
	class API_DECLSPEC HandlerMessage
	{
		std::unordered_map<fe::type::_uint, std::function<void(SOCKET id)>>	actions;
		fe::PacketBuilder	pb{};
		
		void	loadHeader(fe::type::_uchar& mark, fe::type::_32uint& length);

	public:
		HandlerMessage() = default;
		~HandlerMessage() = default;

		bool	pushAction(fe::type::_uint packetType, std::function<void(SOCKET id)> action);
		virtual	void	onMsg(SOCKET id, fe::PacketStructure* ps);
		void	onWelcome(SOCKET id);
	};

	typedef void	(*callbackOnMessage)(SOCKET id, fe::PacketStructure* ps);
	typedef void	(HandlerMessage::*callbackHandlerMessage)(SOCKET id, fe::PacketStructure* ps);
	typedef void	(HandlerMessage::*callbackPacketType)(SOCKET id);
}
