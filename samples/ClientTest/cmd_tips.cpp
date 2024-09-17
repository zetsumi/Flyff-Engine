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

void tip_fast_connect(void)
{
    login_connect();
    std::this_thread::sleep_for (std::chrono::milliseconds(200));
    login_query_tick_count();
    login_get_list_player();
    login_pre_join();

    std::this_thread::sleep_for (std::chrono::milliseconds(500));
    cache_connect();
    std::this_thread::sleep_for (std::chrono::milliseconds(500));
    cache_join();
}