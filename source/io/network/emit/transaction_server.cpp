#include "pch_tcp_network.h"
#include "Transaction.hpp"

bool Transaction::accept(void)
{
	// accept new client
	if (_socket == nullptr)
		return false;
	SOCKET idClient = ::accept(_socket->getSocket(), nullptr, nullptr);
	if (idClient == INVALID_SOCKET)
		return false;

	// add client
	SocketServer* server = dynamic_cast<SocketServer*>(_socket);
	if (server == nullptr)
		return false;
	bool accepted = server->addClient(idClient);

	// thread client
	auto fct = std::bind(&Transaction::loopReceive, this, idClient);
	std::thread t(fct);
	t.detach();

	// print number client
	unsigned int numberClients = server->getNumberClient();
	LOGCONSOLE("clients<%u>", numberClients);

	return accepted;
}

void Transaction::wait(void)
{
	if (isMode(MODE_TRANSACTION::MODE_SERVER) == true)
	{
		threadAccept.join();
	}
}

bool Transaction::runServer(void)
{
	runningServer = true;
	auto fctAccept = std::bind(&Transaction::loopAccept, this);
	threadAccept = std::thread(fctAccept);
	return true;
}

void	Transaction::loopAccept(void)
{
	bool accepted = false;
	while (runningServer == true)
	{
		accepted = accept();
		if (_socket == nullptr)
		{
			runningServer = false;
			break;
		}
	}
}

