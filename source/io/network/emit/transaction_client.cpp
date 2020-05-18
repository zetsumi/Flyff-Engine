#include <pch_fnetwork.h>
#include <io/network/emit/transaction.hpp>
#include <io/network/emit/packet_structure.hpp>

bool fe::Transaction::runClient()
{
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

void fe::Transaction::loopReceive(SOCKET idClient)
{
	while (true)
	{
		fe::PacketStructure* ps = receiver(idClient);
		if (ps == nullptr)
			break;
		if (onPacketMessage != nullptr)
		{
			onPacketMessage(idClient, ps);
		}
	}
}
