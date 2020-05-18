#pragma once

namespace fe
{
	struct PacketStructure
	{
		unsigned int size = 0;
		unsigned char* data = nullptr;

		PacketStructure() = default;
		~PacketStructure() = default;
	};

	inline bool	isValid(PacketStructure* ps) { return ps != nullptr && ps->size > 0 && ps->data != nullptr; }
	inline bool	isInValid(PacketStructure* ps) { return !isValid(ps); }
}


