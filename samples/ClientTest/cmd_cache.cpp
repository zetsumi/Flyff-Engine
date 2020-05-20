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



void cache_connect(void)
{
	FE_LOG("connecting CacheServer");
	std::thread tproxy(handler_cache);
	tproxy.detach();
}

void	cache_join(void)
{
	cache.sendJoin(_socketCache.getSocket(),
		TEST_DEFAULT_ID_WORLD,
		TEST_DEFAULT_ID_PLAYER,
		certifier.getAuthKey(),
		0,
		0,
		0,
		1,
		0,
		TEST_DEFAULT_PLAYER_NAME,
		TEST_DEFAULT_ACCOUNT,
		TEST_DEFAULT_PASSWORD
	);
}