#include <pch_fnetwork.h>

void fe::HandlerCache::onQueryPlayerData(PARAMETERS_FUNCTION_SNAPSHOT)
{
	FE_CONSOLELOG("");
}

void fe::HandlerCache::onDestPos(PARAMETERS_FUNCTION_SNAPSHOT)
{
	float x = packetBuilder.read<float>();
	float y = packetBuilder.read<float>();
	float z = packetBuilder.read<float>();
	fe::type::_uchar forward = packetBuilder.read<fe::type::_uchar>();

	FE_CONSOLELOG("objid{%u} Dest(%f, %f, %f) forward{%u}",
		objid,
		x, y, z,
		forward);
}