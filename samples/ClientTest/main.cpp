#include "./header.hpp"

fe::Transaction			transCertifier{};
fe::Transaction			transLogin{};
fe::Transaction			transCache{};

fe::SocketClient			_socketCert{};
fe::SocketClient			_socketLog{};
fe::SocketClient			_socketCache{};

fe::HandlerCertifier		certifier{};
fe::HandlerLogin			login{};
fe::HandlerCache			cache{};


static void tgame(void)
{
	while (true)
	{
		auto msgCert = certifier.getPacket();
		auto msgLogin = login.getPacket();
		auto msgCache = cache.getPacket();

		if (msgCert != nullptr)
		{
			FE_CONSOLELOG("Certifier : type{%u}{%#010x}", msgCert->type, msgCert->type);
		}
		if (msgLogin != nullptr)
		{
			FE_CONSOLELOG("Certifier : type{%u}{%#010x}", msgLogin->type, msgLogin->type);
		}
		if (msgCache != nullptr)
		{
			FE_CONSOLELOG("Certifier : type{%u}{%#010x}", msgCache->type, msgCache->type);
		}
		std::this_thread::sleep_for (std::chrono::milliseconds(300));
	}
}

int main()
{
	std::thread tcert(handler_certifier);
	std::thread	console(prompt);
	std::thread game(tgame);

	tcert.join();
	console.join();
	game.join();
	return 0;
}