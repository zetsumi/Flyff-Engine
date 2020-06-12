namespace 
{
	namespace packet
	{
		struct API_DECLSPEC a final : public PacketMessage
		{
			string tata = 0;

			a() = default;
			~a() = default;
			a(const a&) = delete;
			a(a&&) = delete;

			inline a& operator<<(fe::PacketBuilder& pb) override final
			{
				tata = pb.read<string>();
				return *this;
			}


			inline a& operator>>(fe::PacketBuilder& pb) override final
			{
				pb.write<string>(tata);
				return *this;
			}
		};
	}
}
