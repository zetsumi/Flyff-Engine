#include <pch_fnetwork.h>
#include <io/network/emit/transaction.hpp>


bool fe::Transaction::sender(fe::type::_SOCKET idSocket, unsigned int size, const char* data)
{
	if (_socket == nullptr)
		return false;
	int errorCode = ::send(idSocket, data, size, 0);
#if defined(_WIN64)
	if (errorCode == SOCKET_ERROR)
#elif defined(__APPLE__)
	if (errorCode <= 0)
#endif
	{
		FE_CONSOLELOG("SOCKET ERROR<%u> with client<%u>", errorCode, idSocket);
		return false;
	}
	return true;
}

bool fe::Transaction::sender(fe::type::_SOCKET idSocket, PacketBuilder& packet)
{
	if (_socket == nullptr)
		return false;
	return sender(idSocket, packet.getSize(), reinterpret_cast<const char*>(packet.getData()));
}

bool fe::Transaction::sender(PacketBuilder& packet)
{
	fe::type::_SOCKET idSocket = _socket->getSocket();
	return sender(idSocket, packet);
}

fe::PacketStructure* fe::Transaction::receiver(fe::type::_SOCKET idSocket)
{
	return receiver(idSocket, lengthBuffer);
}

fe::PacketStructure* fe::Transaction::receiver(fe::type::_SOCKET idSocket, unsigned int bufferSize)
{
	char* buffer = new char[bufferSize];
	int octects = 0;
#if defined(_WIN64)
	ZeroMemory(buffer, sizeof(buffer));
#elif defined(__APPLE__)
	memset(buffer, 0x00, bufferSize);
#endif
	octects =  ::recv(idSocket, buffer, bufferSize, 0);
	if (octects <= 0)
		return nullptr;
	if (octects > static_cast<int>(bufferSize))
		return nullptr;

	fe::PacketStructure* ps = new fe::PacketStructure();
	if (ps == nullptr)
		return nullptr;
	ps->data = (unsigned char*)buffer;
	ps->size = octects;
	return ps;
}
