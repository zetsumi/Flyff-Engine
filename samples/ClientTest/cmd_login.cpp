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



void	login_connect(void)
{
    FE_LOG("connecting LoginServer");
    std::thread tlogin(handler_login);
    tlogin.detach();
}

void	login_query_tick_count(void)
{
    login.sendQueryTickCount(_socketLog.getSocket());
}

void login_disconnect(void)
{
    // TODO :
}

void login_get_list_player(void)
{
    FE_LOG("GETLISTPLAYER : Build{%s} AuthKey{%u} Account{%s} Password{%s} IdServer{%u}",
        TEST_DEFAULT_BUILD_VERSION,
        certifier.getAuthKey(),
        TEST_DEFAULT_ACCOUNT,
        TEST_DEFAULT_PASSWORD,
        TEST_DEFAULT_ID_SERVER);
    login.sendGetListPlayer(_socketLog.getSocket(),
        TEST_DEFAULT_BUILD_VERSION,
        certifier.getAuthKey(),
        TEST_DEFAULT_ACCOUNT,
        TEST_DEFAULT_PASSWORD,
        TEST_DEFAULT_ID_SERVER);
}

void	login_pre_join(void)
{
    FE_LOG("PREJOIN : Account{%s} IdPlayer{%u} PlayerName{%s}",
        TEST_DEFAULT_ACCOUNT,
        TEST_DEFAULT_ID_PLAYER,
        TEST_DEFAULT_PLAYER_NAME
    );
    login.sendPreJoin(_socketLog.getSocket(),
        TEST_DEFAULT_ACCOUNT,
        TEST_DEFAULT_ID_PLAYER,
        TEST_DEFAULT_PLAYER_NAME,
        -1);
}

