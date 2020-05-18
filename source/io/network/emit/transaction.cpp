#include <pch_fnetwork.h>
#include <io/network/emit/transaction.hpp>


bool fe::Transaction::setSocket(Socket* s)
{
	if (s == nullptr)
		return false;
	_socket = s;
	return true;
}

void fe::Transaction::setMode(MODE_TRANSACTION modeTransaction)
{
	mode = modeTransaction;
}

bool fe::Transaction::isMode(MODE_TRANSACTION modeTransaction)
{
	return mode == modeTransaction;
}

bool fe::Transaction::run(callbackOnMessage callback)
{
	if (_socket == nullptr)
		return false;
	if (_socket->getSocket() == INVALID_SOCKET)
		return false;
	if (mode == MODE_TRANSACTION::MODE_UNKNOW)
		return false;
	this->onPacketMessage = callback;
	if (mode == MODE_TRANSACTION::MODE_CLIENT)
		return runClient();
	return true;
}

void fe::Transaction::wait(bool waiting)
{
	if (waiting == true)
		main.join();
	else
		main.detach();
}