#pragma once

namespace fe
{
	namespace packet
	{
#pragma warning( disable: 4251 )
		struct API_DECLSPEC PacketSay : public fe::PacketMessage
		{

			const char* playerFrom = nullptr;
			const char* playerTo = nullptr;
			const char* message = nullptr;
			fe::type::_32uint	idFrom = 0;
			fe::type::_32uint	idTo = 0;
			fe::type::_32int	search = 0;

			PacketSay() = default;
			~PacketSay() = default;
			PacketSay(const PacketSay&) = delete;
			PacketSay(PacketSay&&) = delete;

			PacketSay& operator<<(fe::PacketBuilder& pb)
			{
				playerFrom = pb.readString();
				playerTo = pb.readString();
				message = pb.readString();

				pb >> idFrom >> idTo >> search;
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
