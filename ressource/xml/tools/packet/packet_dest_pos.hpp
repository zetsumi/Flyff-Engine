namespace 
{
	namespace packet
	{
		struct API_DECLSPEC DestPos final : public PacketMessage
		{
			fe::Vector<float> pos = {0, 0, 0};
			fe::type::_uchar forward = 0;
			float angle = 0;
			fe::type::_32uint id = 0;

			DestPos() = default;
			~DestPos() = default;
			DestPos(const DestPos&) = delete;
			DestPos(DestPos&&) = delete;

			inline DestPos& operator<<(fe::PacketBuilder& pb) override final
			{
				pos.x = pb.read<float>();
				pos.y = pb.read<float>();
				pos.z = pb.read<float>();
				pb >> forward;
				angle = pb.read<float>();
				pb >> id;
				return *this;
			}


			inline DestPos& operator>>(fe::PacketBuilder& pb) override final
			{
				pb.write<float>(pos.x);
				pb.write<float>(pos.y);
				pb.write<float>(pos.z);
				pb.write<fe::type::_uchar>(forward);
				pb.write<float>(angle);
				pb.write<fe::type::_32uint>(id);
				return *this;
			}
		};
	}
}
