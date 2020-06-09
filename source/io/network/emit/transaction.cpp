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

void fe::Transaction::setLengthBuffer(unsigned int len)
{
	if (len > 0)
		lengthBuffer = len;
}

const fe::Socket * const fe::Transaction::getSocket() const
{
	return _socket;
}

bool fe::Transaction::isMode(MODE_TRANSACTION modeTransaction)
{
	return mode == modeTransaction;
}