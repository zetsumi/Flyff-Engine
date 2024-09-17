#pragma once

namespace fe
{
    namespace snapshot
    {
        struct SnapshotQueryPlayerData : public Snapshot
        {

            uint32_t	idPlayer = 0;
            const char* playerName = nullptr;
            uint8_t	job = 0;
            uint8_t	level = 0;
            uint8_t	sex = 0;
            int32_t	ver = 0;
            int32_t	login = 0;

            SnapshotQueryPlayerData() = default;
            ~SnapshotQueryPlayerData() = default;
            SnapshotQueryPlayerData& operator<<(fe::PacketBuilder& pb) override
            {
                uint32_t idPlayer = pb.read<uint32_t>();
                const char* playerName = pb.readString();

                uint8_t	job = pb.read<uint8_t>();
                uint8_t	level = pb.read<uint8_t>();
                uint8_t	sex = pb.read<uint8_t>();
                pb.read<uint8_t>();
                int32_t	ver = pb.read<int32_t>();
                int32_t	login = pb.read<int32_t>();

                FE_CONSOLELOG("job{%02x}", job);
                FE_CONSOLELOG("level{%02x}", level);
                FE_CONSOLELOG("sex{%02x}", sex);
                FE_CONSOLELOG("ver{%d}", ver);
                FE_CONSOLELOG("login{%d}", login);

                return *this;
            }

            void	release() override final
            {
                delete playerName;
                playerName = nullptr;
            }
        };
    }
}