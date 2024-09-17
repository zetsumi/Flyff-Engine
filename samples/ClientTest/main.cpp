#include <header.hpp>

fe::Transaction transCertifier{};
fe::Transaction transLogin{};
fe::Transaction transCache{};

fe::SocketClient _socketCert{};
fe::SocketClient _socketLog{};
fe::SocketClient _socketCache{};

fe::HandlerCertifier certifier{};
fe::HandlerLogin     login{};
fe::HandlerCache     cache{};


static void tgame()
{
    while (true)
    {
        auto msgCert = certifier.getPacket();
        auto msgLogin = login.getPacket();
        auto msgCache = cache.getPacket();

        if (msgCert != nullptr)
        {
            FE_CONSOLELOG("Certifier : type{%u}{%#010x}", msgCert->type, msgCert->type);
            msgCert->release();
            delete msgCert;
            msgCert = nullptr;
        }
        if (msgLogin != nullptr)
        {
            FE_CONSOLELOG("Login : type{%u}{%#010x}", msgLogin->type, msgLogin->type);
            msgLogin->release();
            delete msgLogin;
            msgLogin = nullptr;
        }
        if (msgCache != nullptr)
        {
            FE_CONSOLELOG("Cache : type{%u}{%#010x}", msgCache->type, msgCache->type);
            if (msgCache->type == fe::packet::PACKETTYPE::SNAPSHOT || msgCache->type == fe::packet::PACKETTYPE::JOIN)
            {
                fe::snapshot::SnapshotList* snapList = dynamic_cast<fe::snapshot::SnapshotList*>(msgCache);
                for (unsigned short i = 0; i < snapList->count; ++i)
                {
                    FE_CONSOLELOG("Cache Snapshot : count{%u} type{%#010x} objIdPlayer{%u} objid{%#u}",
                        i, snapList->type, snapList->snaps[i]->objIdPlayer, snapList->snaps[i]->objid);
                }
                msgCache->release();
            }
            delete msgCache;
            msgCache = nullptr;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
}

int main()
{
    std::thread tcert(handler_certifier);
    std::thread	console(prompt);
    std::thread game(tgame);

    tcert.join();
    console.join();
    game.join();
    return 0;
}