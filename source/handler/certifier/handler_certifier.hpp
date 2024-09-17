#pragma once

#include <framework_fengine.h>
#include <string>
#include <io/network/message/handler_message.hpp>
#include <io/network/message/packet_message.hpp>
#include <handler/certifier/packets/packet_certifiers.hpp>


namespace fe
{
    class API_DECLSPEC HandlerCertifier : public HandlerMessage
    {
        // recv
        [[nodiscard]] fe::PacketMessage* onServerList();

    public:
        HandlerCertifier() = default;
        HandlerCertifier(HandlerCertifier&& h) = default;
        HandlerCertifier(const HandlerCertifier& h) = default;
        HandlerCertifier& operator=(const HandlerCertifier& h) = default;
        ~HandlerCertifier() = default;

        // global
        void	initialize() override;
        constexpr uint32_t getAuthKey() const { return authKey; }

        // emit
        void	sendDisconnectAccount(fe::type::_SOCKET id, const char* account, const char* password);
        void	sendCertify(fe::type::_SOCKET id, const char* buildVersion, const char* account, const char* password);
        void	sendNewAccount(fe::type::_SOCKET id, const char* account, const char* password);
    };
}
