#pragma once

namespace fe
{
	namespace packet
	{
#pragma warning( disable: 4251 )
		struct API_DECLSPEC PacketGetCorePlayer : public fe::PacketMessage
		{

			fe::type::_ushort count = 0;
			char ** playersName = nullptr;

			PacketGetCorePlayer() = default;
			~PacketGetCorePlayer() = default;
			PacketGetCorePlayer(const PacketGetCorePlayer&) = delete;
			PacketGetCorePlayer(PacketGetCorePlayer&&) = delete;

			PacketGetCorePlayer& operator<<(fe::PacketBuilder& pb)
			{
				pb >> count;
				playersName = new char*[count]();
				for (fe::type::_ushort i = 0; i < count; ++i)
					playersName[i] = const_cast<char*>(pb.readString());
				return *this;
			}

			void	release() override final
			{
				for (fe::type::_ushort i = 0; i < count; ++i)
					delete playersName[i];
				delete[] playersName;
			}
		};
#pragma warning( default : 4251 )
	}
}
