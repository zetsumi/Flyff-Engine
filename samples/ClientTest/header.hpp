#pragma once

#include <framework_fengine.h>
#include <pch_fnetwork.h>
#include <iostream>
#include <string>

bool	handler_login(void);
bool	handler_certifier(void);
bool	handler_cache(void);
void	prompt(void);

// Commande Certifier
void	cert_disconnect(void);
void	certifier_connect(void);

// Commande LoginServer
void	login_connect(void);
void	login_query_tick_count(void);
void	login_disconnect(void);
void	login_get_list_player(void);

// Commande CacheServer
void	cache_connect(void);

struct cmd_exe_1
{
	const char* command;
	const char* shortcut;
	void	(*process)(void);
};