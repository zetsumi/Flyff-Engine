#include <pch_fnetwork.h>
#include <io/network/emit/transaction.hpp>
#include <io/network/emit/packet_structure.hpp>


void fe::Transaction::loopReceive(SOCKET idClient)
{
	while (true)
	{
		fe::PacketStructure* ps = receiver(idClient);
		if (ps == nullptr)
			break;
		if (handlerMessageCallBack != nullptr)
			handlerMessageCallBack(idClient, ps);
		if (onPacketMessage != nullptr)
			onPacketMessage(idClient, ps);
	}
}

bool fe::Transaction::run(void)
{
	if (_socket == nullptr)
		return false;
	if (_socket->getSocket() == INVALID_SOCKET)
		return false;
	if (mode != MODE_TRANSACTION::MODE_CLIENT)
		return false;
	try
	{
		auto fct = std::bind(&Transaction::loopReceive, this, this->_socket->getSocket());
		main = std::thread(fct);
	}
	catch (const std::exception& e)
	{
		FE_CONSOLELOG("%s", e.what());
		return false;
	}
	return true;
}

bool fe::Transaction::run(callbackOnMessage callback)
{
	if (callback == nullptr)
		return false;
	onPacketMessage = callback;
	return run();
}

bool fe::Transaction::run(std::function<void(SOCKET id, fe::PacketStructure* ps)> callback)
{
	if (callback == nullptr)
		return false;
	handlerMessageCallBack = callback;
	return run();
}

void fe::Transaction::wait(bool waiting)
{
	if (waiting == true)
		main.join();
	else
		main.detach();
}