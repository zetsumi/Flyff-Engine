namespace 
{
	namespace packet
	{
		struct API_DECLSPEC b final : public PacketMessage
		{
			vector_f pos = 0;
			string tata = 0;
			bool dasdasd = 0;

			b() = default;
			~b() = default;
			b(const b&) = delete;
			b(b&&) = delete;

			inline b& operator<<(fe::PacketBuilder& pb) override final
			{
				pos = pb.read<vector_f>();
				tata = pb.read<string>();
				dasdasd = pb.read<bool>();
				return *this;
			}


			inline b& operator>>(fe::PacketBuilder& pb) override final
			{
				pb.write<vector_f>(pos);
				pb.write<string>(tata);
				pb.write<bool>(dasdasd);
				return *this;
			}
		};
	}
}
