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
	FE_LOG("Sending Join Game");
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

void	cache_get_pos(void)
{
	cache.sendGetPosition(_socketCache.getSocket(),
		TEST_DEFAULT_ID_PLAYER
	);
}

fe::Vector3D<float> dest{ 6959.27734, 100.000000, 3462.15723 };

void	cache_dest_pos(void)
{
	dest.x += 3;
	cache.sendDestinationPosition(_socketCache.getSocket(),
		dest,
		1
	);
}
