#include "./header.hpp"


extern fe::Transaction			transCertifier;
extern fe::Transaction			transLogin;
extern fe::HandlerCertifier		certifier;
extern fe::SocketClient			_socketCert;
extern fe::HandlerLogin			login;
extern fe::SocketClient			_socketLog;



static void	connect_login(void)
{
	FE_LOG("connecting LoginServer");
	std::thread tlogin(handler_login);
	tlogin.detach();
}

static void	login_query_tick_count(void)
{
	login.sendQueryTickCount(_socketLog.getSocket());
}

static void	help(void)
{
	FE_LOG("Liste des commandes :");
	FE_LOG("	connect_login | cl");
	FE_LOG("	login_query_tick_count | lqtc");
}


void		prompt(void)
{
	FE_LOG("BUILD[% s] ACCOUNT[% s] PASSWORD[% s]", TEST_DEFAULT_BUILD_VERSION, TEST_DEFAULT_ACCOUNT, TEST_DEFAULT_PASSWORD);

	FE_PROMPT("press to loging !");
	std::string line;
	std::getline(std::cin, line);
	certifier.sendCertify(_socketCert.getSocket(), TEST_DEFAULT_BUILD_VERSION, TEST_DEFAULT_ACCOUNT, TEST_DEFAULT_PASSWORD);

	
	cmd_exe_1 listCommandeSimple[] = {
		{"help", help},
		{"connect_login", connect_login},
		{"cl", connect_login},
		{"login_query_tick_count", login_query_tick_count},
		{"lqtc", login_query_tick_count},
		{nullptr, nullptr}
	};

	bool r = false;
	unsigned int i = 0;
	FE_PROMPT("");
	while (std::getline(std::cin, line))
	{
		while (listCommandeSimple[i].token != nullptr)
		{
			FE_CONSOLELOG("%s", listCommandeSimple[i].token);
			if (line.compare(listCommandeSimple[i].token) == 0)
			{
				listCommandeSimple[i].process();
				r = true;
				break;
			}
			++i;
		}
		i = 0;

		if (r == false)
		{
			FE_LOG("commande non reconnue !");
			help();
		}
		r = false;
		FE_PROMPT("");
	}
}
