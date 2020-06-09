#pragma once

namespace fe
{
	namespace packet
	{
#pragma warning( disable: 4251 )
		struct API_DECLSPEC PacketGmSay : public fe::PacketMessage
		{
			const char* playerFrom = nullptr;
			const char* playerTo = nullptr;
			const char* message = nullptr;

			PacketGmSay() = default;
			~PacketGmSay() = default;
			PacketGmSay(const PacketGmSay&) = delete;
			PacketGmSay(PacketGmSay&&) = delete;

			PacketGmSay& operator<<(fe::PacketBuilder& pb)
			{
				playerFrom = pb.readString();
				playerTo = pb.readString();
				message = pb.readString();
				return *this;
			}

			void	release() override final
			{
				delete playerFrom;
				delete playerTo;
				delete message;
				playerFrom = nullptr;
				playerTo = nullptr;
				message = nullptr;
			}

		};
#pragma warning( default : 4251 )
	}
}
