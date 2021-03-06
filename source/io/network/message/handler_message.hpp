#pragma once

#include <framework_fengine.h>
#if defined(_WIN64)
#include <winsock.h>
#endif
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
		void	loadHeader(fe::type::_uchar& mark, fe::type::_32uint& length, fe::packet::PACKETTYPE& packettype);

	protected:
		typedef	std::function<fe::PacketMessage* ()>	callbackHandlerMesage;
		typedef	std::function<fe::PacketMessage* ()>		fctPacketOperator;
		typedef std::unordered_map<fe::packet::PACKETTYPE, callbackHandlerMesage>	mapAction;
		typedef std::unordered_map<fe::packet::PACKETTYPE, callbackHandlerMesage>	mapOperator;
		mapAction	actions{};
		mapOperator	packetOperator{};

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
		bool	pushAction(fe::packet::PACKETTYPE packetType, callbackHandlerMesage action);

		// emit & receive
		void	sendPing();
		void	processPing();

	public:
		HandlerMessage() = default;
		HandlerMessage(HandlerMessage&& h) = default;
		HandlerMessage(const HandlerMessage& h) = default;
		HandlerMessage& operator=(const HandlerMessage& h) = default;
		~HandlerMessage();


		// global
		virtual void	initialize();
		void			setTransaction(Transaction* newTransaction);
		void			killPing();
		[[nodiscard]] fe::PacketMessage* getPacket();

		// emit
		void	sendKeepAlive();
		void	sendError();

		// recv
		void onMsg(fe::PacketStructure* ps);
		[[nodiscard]] fe::PacketMessage* onWelcome();
		[[nodiscard]] fe::PacketMessage* onKeepAlive();
		[[nodiscard]] fe::PacketMessage* onPing();
		[[nodiscard]] fe::PacketMessage* onError();
		[[nodiscard]] fe::PacketMessage* onErrorString();
	};
}
#pragma warning( default : 4251 )
