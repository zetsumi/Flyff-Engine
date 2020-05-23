#pragma once

#include <framework_fengine.h>
#include <pch_fnetwork.h>
#include <iostream>
#include <string>


#define TEST_DEFAULT_BUILD_VERSION	"20100412"
#define TEST_DEFAULT_ACCOUNT		"test10"
#define TEST_DEFAULT_PASSWORD		"4d1677b3d55fd9c68e6baa7b1bd638d0"
#define	TEST_DEFAULT_ID_WORLD		1
#define	TEST_DEFAULT_ID_SERVER		1
#define	TEST_DEFAULT_ID_PLAYER		9
#define TEST_DEFAULT_PLAYER_NAME	"fperso"

bool	handler_login(void);
bool	handler_certifier(void);
bool	handler_cache(void);
void	prompt(void);

// Command tips
void tip_fast_connect(void);

// Commande Certifier
void	cert_disconnect(void);
void	certifier_connect(void);

// Commande LoginServer
void	login_connect(void);
void	login_query_tick_count(void);
void	login_disconnect(void);
void	login_get_list_player(void);
void	login_pre_join(void);

// Commande CacheServer
void	cache_connect(void);
void	cache_join(void);
void	cache_get_pos(void);
void	cache_dest_pos(void);

struct cmd_exe_1
{
	const char* command;
	const char* shortcut;
	void	(*process)(void);
};