#include "./header.hpp"


extern fe::Transaction			transCertifier;
extern fe::Transaction			transLogin;
extern fe::HandlerCertifier		certifier;
extern fe::SocketClient			_socketCert;
extern fe::HandlerLogin			login;

static void	help(void)
{
	FE_LOG("liste des commandes!");
}

void		prompt(void)
{
	FE_LOG("BUILD[% s] ACCOUNT[% s] PASSWORD[% s]", TEST_DEFAULT_BUILD_VERSION, TEST_DEFAULT_ACCOUNT, TEST_DEFAULT_PASSWORD);

	FE_PROMPT("press to loging !");
	std::string line;
	std::getline(std::cin, line);
	certifier.sendCertify(_socketCert.getSocket(), TEST_DEFAULT_BUILD_VERSION, TEST_DEFAULT_ACCOUNT, TEST_DEFAULT_PASSWORD);

	FE_LOG("Connecto to LoginServer");
	std::thread tlogin(handler_login);
	tlogin.detach();

	FE_PROMPT("");
	while (std::getline(std::cin, line))
	{
		if (line.compare("help") == 0)
			help();
		FE_PROMPT("");
	}
}
