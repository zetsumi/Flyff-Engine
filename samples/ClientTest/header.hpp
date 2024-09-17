#pragma once

#include <framework_fengine.h>
#include <pch_fnetwork.h>
#include <iostream>
#include <string>


#define TEST_DEFAULT_BUILD_VERSION  "20100412"
#define TEST_DEFAULT_ACCOUNT        "test10"
#define TEST_DEFAULT_PASSWORD       "4d1677b3d55fd9c68e6baa7b1bd638d0"
#define	TEST_DEFAULT_ID_WORLD       1
#define	TEST_DEFAULT_ID_SERVER      1
#define	TEST_DEFAULT_ID_PLAYER      9
#define TEST_DEFAULT_PLAYER_NAME    "fperso"

bool	handler_login();
bool	handler_certifier();
bool	handler_cache();
void	prompt();

// Command tips
void tip_fast_connect();

// Commande Certifier
void cert_disconnect();
void certifier_connect();

// Commande LoginServer
void login_connect();
void login_query_tick_count();
void login_disconnect();
void login_get_list_player();
void login_pre_join();

// Commande CacheServer
void cache_connect();
void cache_join();
void cache_get_pos();
void cache_dest_pos();


struct cmd_exe_1
{
    const char* command{ nullptr };
    const char* shortcut{ nullptr };
    void (*process)(){ nullptr };
};
