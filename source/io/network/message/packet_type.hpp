#pragma once

#define	PACKETTYPE_WELCOME						(DWORD)0x00000000
#define	PACKETTYPE_QUERYTICKCOUNT				(DWORD)0x0000000b
#define	PACKETTYPE_PING							(DWORD)0x00000014
#define	PACKETTYPE_CLOSE_EXISTING_CONNECTION	(DWORD)0x00000016
#define	PACKETTYPE_KEEP_ALIVE					(DWORD)0x00000018

#define	PACKETTYPE_NEW_ACCOUNT		(DWORD)0x000000f0
#define	PACKETTYPE_CACHE_ADDR		(DWORD)0x000000f2
#define PACKETTYPE_PLAYER_LIST		(DWORD)0x000000f3
#define	PACKETTYPE_CERTIFY			(DWORD)0x000000fc
#define	PACKETTYPE_SRVR_LIST		(DWORD)0x000000fd
#define	PACKETTYPE_ERROR			(DWORD)0x000000fe
#define	PACKETTYPE_GETPLAYERLIST	(DWORD)0x000000f6
#define PACKETTYPE_JOIN				(DWORD)0x0000ff00
#define	PACKETTYPE_PRE_JOIN			(DWORD)0x0000ff05

#define	PACKETTYPE_ERROR_STRING						(DWORD)0x70000003
#define PACKETTYPE_LOGIN_PROTECT_NUMPAD				(DWORD)0x88100200
#define PACKETTYPE_LOGIN_PROTECT_CERT				(DWORD)0x88100201

#define	PACKETTYPE_SNAPSHOT		(DWORD)0xffffff00
