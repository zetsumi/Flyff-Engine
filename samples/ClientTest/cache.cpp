#include "./header.hpp"


extern fe::Transaction			transCertifier;
extern fe::Transaction			transLogin;
extern fe::Transaction			transCache;

extern fe::SocketClient			_socketCert;
extern fe::SocketClient			_socketLog;
extern fe::SocketClient			_socketCache;

extern fe::HandlerCertifier		certifier;
extern fe::HandlerLogin			login;
extern fe::HandlerCache			cache;


bool	handler_cache(void)
{
	fe::Network network;


	network.setIP(login.getCacheServerAddr());
	network.setPort(5400);
	if (network.isValid() == false)
		return false;

	if (_socketCache.connect(network) == false)
		return false;
	if (transCache.setSocket(&_socketCache) == false)
		return false;
	transCache.setMode(fe::MODE_TRANSACTION::MODE_CLIENT);
	transCache.setLengthBuffer(500);

	cache.initialize();
	cache.setTransaction(&transCache);

	auto onMsg = std::bind(&fe::HandlerMessage::onMsg, &cache, std::placeholders::_1, std::placeholders::_2);
	if (transCache.run(onMsg) == false)
		return false;

	transCache.wait();
	FE_CONSOLELOG("out");
	return true;
}