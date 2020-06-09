#pragma once

namespace fe
{
	namespace packet
	{
#pragma warning( disable: 4251 )
		struct API_DECLSPEC PacketSystem : public fe::PacketMessage
		{
			const char* message = nullptr;

			PacketSystem() = default;
			~PacketSystem() = default;
			PacketSystem(const PacketSystem&) = delete;
			PacketSystem(PacketSystem&&) = delete;

			PacketSystem& operator<<(fe::PacketBuilder& pb)
			{
				message = pb.readString();
				return *this;
			}

			void	release() override final
			{
				delete message;
				message = nullptr;
			}
		};
#pragma warning( default : 4251 )
	}
}
