#pragma once

namespace fe
{
	namespace packet
	{
#pragma warning( disable: 4251 )
		struct API_DECLSPEC PacketCaption : public fe::PacketMessage
		{
			fe::type::_32int	smallCaption = 0;
			fe::type::_32uint	worldId = 0;
			const char* caption = nullptr;

			PacketCaption() = default;
			~PacketCaption() = default;
			PacketCaption(const PacketCaption&) = delete;
			PacketCaption(PacketCaption&&) = delete;

			PacketCaption& operator<<(fe::PacketBuilder& pb)
			{
				pb >> smallCaption >> worldId;
				caption = pb.readString();
				return *this;
			}

			void	release(void) override final
			{
				delete caption;
				caption = nullptr;
			}
		};
#pragma warning( default : 4251 )
	}
}
