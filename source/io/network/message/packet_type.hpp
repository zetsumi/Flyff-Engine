#pragma once

#define	PACKETTYPE_WELCOME						(fe::type::_32uint)0x00000000
#define	PACKETTYPE_QUERYTICKCOUNT				(fe::type::_32uint)0x0000000b
#define	PACKETTYPE_PING							(fe::type::_32uint)0x00000014
#define	PACKETTYPE_CLOSE_EXISTING_CONNECTION	(fe::type::_32uint)0x00000016
#define	PACKETTYPE_KEEP_ALIVE					(fe::type::_32uint)0x00000018

#define	PACKETTYPE_NEW_ACCOUNT		(fe::type::_32uint)0x000000f0
#define	PACKETTYPE_CACHE_ADDR		(fe::type::_32uint)0x000000f2
#define PACKETTYPE_PLAYER_LIST		(fe::type::_32uint)0x000000f3
#define	PACKETTYPE_CERTIFY			(fe::type::_32uint)0x000000fc
#define	PACKETTYPE_SRVR_LIST		(fe::type::_32uint)0x000000fd
#define	PACKETTYPE_ERROR			(fe::type::_32uint)0x000000fe
#define	PACKETTYPE_GETPLAYERLIST	(fe::type::_32uint)0x000000f6
#define PACKETTYPE_JOIN				(fe::type::_32uint)0x0000ff00
#define	PACKETTYPE_PRE_JOIN			(fe::type::_32uint)0x0000ff05

#define	PACKETTYPE_ERROR_STRING						(fe::type::_32uint)0x70000003
#define PACKETTYPE_LOGIN_PROTECT_NUMPAD				(fe::type::_32uint)0x88100200
#define PACKETTYPE_LOGIN_PROTECT_CERT				(fe::type::_32uint)0x88100201

#define	PACKETTYPE_SNAPSHOT		(fe::type::_32uint)0xffffff00
#define	PACKETTYPE_QUERYGETPOS	(fe::type::_32uint)0xffffff08
