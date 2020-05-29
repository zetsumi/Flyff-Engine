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

void fe::HandlerMessage::loadHeader(fe::type::_uchar& mark, fe::type::_32uint& length, fe::type::_32uint& packettype)
{
	mark = packetBuilder.read<fe::type::_uchar>();
	length = packetBuilder.read<fe::type::_32uint>();
	packettype = packetBuilder.read<fe::type::_32uint>();
	FE_CONSOLELOG("header {%#02x} length{%#010x}{%u} packettype{%#08x}", mark, length, length, packettype);
}

bool fe::HandlerMessage::pushAction(fe::type::_32uint packetType, callbackHandlerMesage action)
{
	if (action == nullptr)
		return false;
	actions[packetType] = action;
	return true;
}

void fe::HandlerMessage::initialize(void)
{
	ON_PACKETTYPE(PACKETTYPE_WELCOME, &fe::HandlerMessage::onWelcome);
	ON_PACKETTYPE(PACKETTYPE_KEEP_ALIVE, &fe::HandlerMessage::onKeepAlive);
	ON_PACKETTYPE(PACKETTYPE_PING, &fe::HandlerMessage::onPing);
	ON_PACKETTYPE(PACKETTYPE_ERROR, &fe::HandlerMessage::onError);
	ON_PACKETTYPE(PACKETTYPE_ERROR_STRING, &fe::HandlerMessage::onErrorString);
}

void fe::HandlerMessage::setTransaction(Transaction* newTransaction)
{
	if (newTransaction != nullptr)
		transaction = newTransaction;
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
