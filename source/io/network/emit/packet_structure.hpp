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

	[[nodiscard]] inline bool	isValid(PacketStructure* ps) { return ps != nullptr && ps->size > 0 && ps->data != nullptr; }
	[[nodiscard]] inline bool	isInValid(PacketStructure* ps) { return !isValid(ps); }
}


