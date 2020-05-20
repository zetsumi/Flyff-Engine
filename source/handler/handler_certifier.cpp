#include <pch_fnetwork.h>
#include <handler/handler_certifier.hpp>


void fe::HandlerCertifier::initialize(void)
{

	handlerType = HANDLER_PACKET_TYPE::CERTIFIER;

	ON_PACKETTYPE(PACKETTYPE_WELCOME, &fe::HandlerMessage::onWelcome);
	ON_PACKETTYPE(PACKETTYPE_KEEP_ALIVE, &fe::HandlerMessage::onKeepAlive);
	ON_PACKETTYPE(PACKETTYPE_PING, &fe::HandlerMessage::onPing);
	ON_PACKETTYPE(PACKETTYPE_ERROR, &fe::HandlerMessage::onError);
	ON_PACKETTYPE(PACKETTYPE_ERROR_STRING, &fe::HandlerMessage::onErrorString);

	ON_PACKETTYPE(PACKETTYPE_SRVR_LIST, &fe::HandlerCertifier::onServerList);
}


void fe::HandlerCertifier::onServerList(SOCKET id)
{
	FE_CONSOLELOG("server list");
	authKey = packetBuilder.read<fe::type::_32uint>();
	fe::type::_uchar accountFlag = packetBuilder.read<fe::type::_uchar>();
	const char* account = packetBuilder.readString();
	fe::type::_32uint numberServer = packetBuilder.read<fe::type::_32uint>();

	FE_CONSOLELOG("authKey:[%u] accountFlag:[%u] account:[%s] numberServer:[%u]",
		authKey, accountFlag,
		account,
		numberServer
		);

	for (fe::type::_32uint i = 0; i < numberServer; ++i)
	{
		fe::type::_32uint parent = packetBuilder.read<fe::type::_32uint>();
		fe::type::_32uint id = packetBuilder.read<fe::type::_32uint>();
		const char* name = packetBuilder.readString();
		const char* addr = packetBuilder.readString();
		fe::type::_32uint unknow = packetBuilder.read<fe::type::_32uint>();
		fe::type::_32uint count = packetBuilder.read<fe::type::_32uint>();
		fe::type::_32uint enable = packetBuilder.read<fe::type::_32uint>();
		fe::type::_32uint max = packetBuilder.read<fe::type::_32uint>();

		FE_CONSOLELOG("parent:[%u] id:[%u] name:[%s] addr:[%s] unknow:[%u] count:[%u] enamble:[%u] max:[%u]",
			parent, id,
			name, addr,
			unknow,
			count, enable,
			max
			);

	}
}
