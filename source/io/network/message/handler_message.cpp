#include <pch_fnetwork.h>
#include <io/network/message/handler_message.hpp>


fe::HandlerMessage::~HandlerMessage()
{
	mtMessage.lock();
	while (messages.empty() == false)
	{
		auto msg = messages.front();
		delete msg;
		msg = nullptr;
		messages.pop();
	}
	mtMessage.unlock();

	delete transaction;
}


void fe::HandlerMessage::processPing()
{
	std::chrono::seconds sec = std::chrono::seconds(30);
	while (true)
	{
		std::this_thread::sleep_for(sec);
		sendPing();
	}
	FE_CONSOLELOG("out");
}

void fe::HandlerMessage::loadHeader(fe::type::_uchar& mark, fe::type::_32uint& length, fe::packet::PACKETTYPE& packettype)
{
	mark = packetBuilder.read<fe::type::_uchar>();
	length = packetBuilder.read<fe::type::_32uint>();
	packettype = packetBuilder.read<fe::packet::PACKETTYPE>();
	FE_CONSOLELOG("header {%#02x} length{%#010x}{%u} packettype{%#08x}", mark, length, length, packettype);
}

bool fe::HandlerMessage::pushAction(fe::packet::PACKETTYPE packetType, callbackHandlerMesage action)
{
	if (action == nullptr)
		return false;
	actions[packetType] = action;
	return true;
}

void fe::HandlerMessage::initialize(void)
{
	pushAction(fe::packet::PACKETTYPE::WELCOME, std::bind(&fe::HandlerMessage::onWelcome, this));
	pushAction(fe::packet::PACKETTYPE::KEEP_ALIVE, std::bind(&fe::HandlerMessage::onKeepAlive, this));
	pushAction(fe::packet::PACKETTYPE::PING, std::bind(&fe::HandlerMessage::onPing, this));
	pushAction(fe::packet::PACKETTYPE::PERROR, std::bind(&fe::HandlerMessage::onError, this));
	pushAction(fe::packet::PACKETTYPE::ERROR_STRING, std::bind(&fe::HandlerMessage::onErrorString, this));
}

void fe::HandlerMessage::setTransaction(Transaction* newTransaction)
{
	if (newTransaction != nullptr)
		transaction = newTransaction;
	else
		FE_CONSOLELOG("newTransaction is null");
}

void	fe::HandlerMessage::killPing(void)
{
#if defined(_WIN64)
	if (::TerminateThread(ping.native_handle(), 1) != 0)
		FE_CONSOLELOG("can not terminate thread opcode{%u}", ::GetLastError());
#endif // _WIN64 || _WIN32
}

fe::PacketMessage* fe::HandlerMessage::getPacket(void)
{
	mtMessage.lock();
	if (messages.size() == 0)
	{
		mtMessage.unlock();
		return nullptr;
	}
	fe::PacketMessage* msg = messages.front();
	messages.pop();
	mtMessage.unlock();
	return msg;
}
