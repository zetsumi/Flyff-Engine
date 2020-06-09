#pragma once

namespace fe
{
	namespace packet
	{
#pragma warning( disable: 4251 )
		struct API_DECLSPEC PacketGetPlayerAddr : public fe::PacketMessage
		{
			const char* playerName = nullptr;
			const char* addr = nullptr;

			PacketGetPlayerAddr() = default;
			~PacketGetPlayerAddr() = default;
			PacketGetPlayerAddr(const PacketGetPlayerAddr&) = delete;
			PacketGetPlayerAddr(PacketGetPlayerAddr&&) = delete;

			PacketGetPlayerAddr& operator<<(fe::PacketBuilder& pb)
			{
				playerName = pb.readString();
				addr = pb.readString();
				return *this;
			}

			void	release() override final
			{
				delete playerName;
				delete addr;
				playerName = nullptr;
				addr = nullptr;
			}
		};
#pragma warning( default : 4251 )
	}
}
