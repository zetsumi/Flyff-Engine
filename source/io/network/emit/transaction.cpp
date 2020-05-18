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