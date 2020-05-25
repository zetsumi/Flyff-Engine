#pragma once


#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include <framework_fengine.h>

#include <util/log.hpp>
#include <util/vector.hpp>

#include <io/network/socket.hpp>
#include <io/network/socket_client.hpp>
#include <io/network/network.hpp>
#include <io/network/emit/transaction.hpp>
#include <io/network/message/packet_message.hpp>
#include <io/network/message/handler_message.hpp>

#include <handler/certifier/handler_certifier.hpp>
#include <handler/login/handler_login.hpp>
#include <handler/cache/handler_cache.hpp>
