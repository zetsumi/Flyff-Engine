#pragma once

#include <framework_fengine.h>
#include <winsock.h>
#include <thread>
#include <mutex>
#include <unordered_map>
#include <queue>

#include <io/network/emit/packet_structure.hpp>
#include <io/network/message/packet_type.hpp>
#include <io/network/message/packet_message.hpp>
#include <io/network/emit/transaction.hpp>

#pragma warning( disable: 4251 )
namespace fe
{
	constexpr unsigned int portCertifier = 23000;
	constexpr unsigned int portLoginServer = 28000;
	constexpr unsigned int portCacheServer = 5400;

	class API_DECLSPEC HandlerMessage
	{
		[[noreturn]] void	loadHeader(fe::type::_uchar& mark, fe::type::_32uint& length, fe::type::_32uint& packettype);

	protected:
		typedef  std::function<fe::PacketMessage* (SOCKET id)> callbackHandlerMesage;
		std::unordered_map<fe::type::_32uint, callbackHandlerMesage>	actions{};

		std::thread						ping{};
		Transaction*					transaction = nullptr;
		fe::PacketBuilder				packetBuilder{};
		fe::type::_32uint				sessionID = 0;
		std::mutex						lockerSend;
		fe::type::_32uint				dpid = 0xffffffff;
		HANDLER_PACKET_TYPE				handlerType = HANDLER_PACKET_TYPE::UNKNOW;
		std::queue<fe::PacketMessage*>	messages{};
		std::mutex						mtMessage{};
		fe::type::_32uint				authKey = 0;

		// global
		[[nodiscard]] bool	pushAction(fe::type::_32uint packetType, std::function<fe::PacketMessage* (SOCKET id)> action);

		// emit & receive
		[[noreturn]] void	sendPing(SOCKET id);
		[[noreturn]] void	processPing(SOCKET id);

	public:
		HandlerMessage() = default;
		HandlerMessage(HandlerMessage&& h) = default;
		HandlerMessage(const HandlerMessage& h) = default;
		HandlerMessage& operator=(const HandlerMessage& h) = default;
		virtual ~HandlerMessage();


		// global
		[[noreturn]] virtual void	initialize(void) = 0;
		[[noreturn]] void			setTransaction(Transaction* newTransaction);
		[[noreturn]] void			killPing(void);
		[[nodiscard]] fe::PacketMessage* getPacket(void);

		// emit
		[[noreturn]] void	sendKeepAlive(SOCKET id);
		[[noreturn]] void	sendError(SOCKET id);

		// recv
		[[noreturn]] void onMsg(SOCKET id, fe::PacketStructure* ps);
		[[nodiscard]] fe::PacketMessage* onWelcome(SOCKET id);
		[[nodiscard]] fe::PacketMessage* onKeepAlive(SOCKET id);
		[[nodiscard]] fe::PacketMessage* onPing(SOCKET id);
		[[nodiscard]] fe::PacketMessage* onError(SOCKET id);
		[[nodiscard]] fe::PacketMessage* onErrorString(SOCKET id);
	};
}
#pragma warning( default : 4251 )

#define	ON_PACKETTYPE(packettype, fct) \
	if (pushAction(packettype, std::bind(fct, this, std::placeholders::_1)) == false) \
		FE_CONSOLELOG("fail add action on packet type [%u]", packettype);
