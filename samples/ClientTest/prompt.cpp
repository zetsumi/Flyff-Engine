#include "./header.hpp"


extern fe::Transaction			transCertifier;
extern fe::Transaction			transLogin;
extern fe::HandlerCertifier		certifier;
extern fe::SocketClient			_socketCert;
extern fe::HandlerLogin			login;
extern fe::SocketClient			_socketLog;


static void help(void);

cmd_exe_1 listCommandeSimple[] = {
	{"help", "h", help},

	// certifier
	{"cert_connect", "cc", certifier_connect},

	//login
	{"login_connect", "lc", login_connect},
	{"login_query_tick_count", "lqtc", login_query_tick_count},
	{"login_get_list_player", "lglp", login_get_list_player},
	{nullptr, nullptr}
};

void	help(void)
{
	FE_LOG("Liste des commandes :");
	unsigned int i = 0;
	while (listCommandeSimple[i].command != nullptr)
	{
		FE_LOG("\t%s | %s", listCommandeSimple[i].command, listCommandeSimple[i].shortcut);
		++i;
	}
}

void		prompt(void)
{
	FE_LOG("BUILD[% s] ACCOUNT[% s] PASSWORD[% s]", TEST_DEFAULT_BUILD_VERSION, TEST_DEFAULT_ACCOUNT, TEST_DEFAULT_PASSWORD);

	FE_PROMPT("press enter to connect certifier !");
	std::string line;
	std::getline(std::cin, line);
	certifier.sendCertify(_socketCert.getSocket(), TEST_DEFAULT_BUILD_VERSION, TEST_DEFAULT_ACCOUNT, TEST_DEFAULT_PASSWORD);

	bool r = false;
	unsigned int i = 0;
	FE_PROMPT("");
	while (std::getline(std::cin, line))
	{
		while (listCommandeSimple[i].command != nullptr)
		{
			if (line.compare(listCommandeSimple[i].command) == 0 || line.compare(listCommandeSimple[i].shortcut) == 0)
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
