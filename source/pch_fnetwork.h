#pragma once

#pragma warning( disable: 4251 )

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include <framework_fengine.h>

#include <util/log.hpp>
#include <io/network/socket.hpp>
#include <io/network/socket_client.hpp>
#include <io/network/network.hpp>
#include <io/network/emit/transaction.hpp>
#include <io/network/message/handler_message.hpp>
#include <handler/handler_certifier.hpp>
#include <handler/handler_login.hpp>
#include <handler/handler_cache.hpp>
