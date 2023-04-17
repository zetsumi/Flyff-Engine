namespace fe
{
	namespace packet
	{
		struct API_DECLSPEC GuildWarEnd final : public fe::PacketMessage
		{
			fe::type::_32uint idWar = 0;
			fe::type::_32int wptDeclared = 0;
			fe::type::_32int wptAcpt = 0;
			fe::type::_32int type = 0;

			GuildWarEnd() = default;
			~GuildWarEnd() = default;
			GuildWarEnd(GuildWarEnd const&) = delete;
			GuildWarEnd(GuildWarEnd&&) = delete;

			GuildWarEnd& operator<<(fe::PacketBuilder& pb) override final
			{
				pb >> idWar;
				pb >> wptDeclared;
				pb >> wptAcpt;
				pb >> type;
				return *this;
			}

			GuildWarEnd& operator>>(fe::PacketBuilder& pb) override final
			{
				pb.write<fe::type::_32uint>(idWar);
				pb.write<fe::type::_32int>(wptDeclared);
				pb.write<fe::type::_32int>(wptAcpt);
				pb.write<fe::type::_32int>(type);
				return *this;
			}

			void release() override final
			{
			}
		};
	}
}
