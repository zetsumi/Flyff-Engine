#include <pch_fnetwork.h>
#include <io/network/message/handler_certifier.hpp>


void fe::HandlerCertifier::initialize(void)
{
	ON_PACKETTYPE(PACKETTYPE_WELCOME, &fe::HandlerCertifier::onWelcome);
	ON_PACKETTYPE(PACKETTYPE_KEEP_ALIVE, &fe::HandlerCertifier::onKeepAlive);
	ON_PACKETTYPE(PACKETTYPE_PING, &fe::HandlerCertifier::onPing);
	ON_PACKETTYPE(PACKETTYPE_SRVR_LIST, &fe::HandlerCertifier::onServerList);
}

void fe::HandlerCertifier::onWelcome(SOCKET id)
{
	FE_CONSOLELOG("welcome");
	sessionID = pb.read<fe::type::_32uint>();

	sendCertify(id, TEST_DEFAULT_BUILD_VERSION, TEST_DEFAULT_ACCOUNT, TEST_DEFAULT_PASSWORD);
}

void fe::HandlerCertifier::onKeepAlive(SOCKET id)
{
	FE_CONSOLELOG("keep alive");
	sendKeepAlive(id);
}

void fe::HandlerCertifier::onPing(SOCKET id)
{
	FE_CONSOLELOG("ping");
}

void fe::HandlerCertifier::onServerList(SOCKET id)
{
	FE_CONSOLELOG("server list");
	fe::type::_32uint authKey = pb.read<fe::type::_32uint>();
	fe::type::_uchar accountFlag = pb.read<fe::type::_uchar>();
	const char* account = pb.readString();
	fe::type::_32uint numberServer = pb.read<fe::type::_32uint>();

	FE_CONSOLELOG("authKey:[%u] accountFlag:[%u] account:[%s] numberServer:[%u]",
		authKey, accountFlag,
		account,
		numberServer
		);

	for (fe::type::_32uint i = 0; i < numberServer; ++i)
	{
		fe::type::_32uint parent = pb.read<fe::type::_32uint>();
		fe::type::_32uint id = pb.read<fe::type::_32uint>();
		const char* name = pb.readString();
		const char* addr = pb.readString();
		fe::type::_32uint unknow = pb.read<fe::type::_32uint>();
		fe::type::_32uint count = pb.read<fe::type::_32uint>();
		fe::type::_32uint enable = pb.read<fe::type::_32uint>();
		fe::type::_32uint max = pb.read<fe::type::_32uint>();

		FE_CONSOLELOG("parent:[%u] id:[%u] name:[%s] addr:[%s] unknow:[%u] count:[%u] enamble:[%u] max:[%u]",
			parent, id,
			name, addr,
			unknow,
			count, enable,
			max
			);

	}
}
