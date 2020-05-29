#pragma once

#include <io/network/emit/packet_builder.hpp>

namespace fe
{
	namespace serialize
	{
		struct SerializeMoverPlayer
		{

			char*				name = nullptr;
			fe::type::_uchar	sex = 0;
#pragma region Mesh
			fe::type::_uchar	skin = 0;
			fe::type::_uchar	hairMesh = 0;
			fe::type::_32uint	hairColor = 0x00;
			fe::type::_uchar	headMesh = 0;
#pragma endregion

#pragma region Statistique
			fe::type::_32uint	idPlayer = 0;
			fe::type::_uchar	job = 0;
			fe::type::_ushort	str = 0;
			fe::type::_ushort	sta = 0;
			fe::type::_ushort	dex = 0;
			fe::type::_ushort	intel = 0;
			fe::type::_ushort	level = 0;
#pragma endregion

			SerializeMoverPlayer() = default;
			~SerializeMoverPlayer() = default;

			SerializeMoverPlayer& operator<<(fe::PacketBuilder& pb)
			{
				name = const_cast<char*>(pb.readString());
				sex = pb.read<fe::type::_uchar>();
#pragma region Mesh
				skin = pb.read<fe::type::_uchar>();
				hairMesh = pb.read<fe::type::_uchar>();
				hairColor = pb.read<fe::type::_32uint>();
				headMesh = pb.read<fe::type::_uchar>();
#pragma endregion

#pragma region Statistique
				fe::type::_32uint	idPlayer = pb.read<fe::type::_uchar>();
				fe::type::_uchar	job = pb.read<fe::type::_uchar>();
				fe::type::_ushort	str = pb.read<fe::type::_uchar>();
				fe::type::_ushort	sta = pb.read<fe::type::_uchar>();
				fe::type::_ushort	dex = pb.read<fe::type::_uchar>();
				fe::type::_ushort	intel = pb.read<fe::type::_uchar>();
				fe::type::_ushort	level = pb.read<fe::type::_uchar>();
#pragma endregion
				return *this;
			}
		};
	}
}