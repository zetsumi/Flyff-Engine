#include <pch_fnetwork.h>
#include <util/vector.hpp>

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

void fe::HandlerCache::onMoverCorr(PARAMETERS_FUNCTION_SNAPSHOT)
{
	fe::Vector3D<float> pos, delta;

	pos.x = packetBuilder.read<float>();
	pos.y = packetBuilder.read<float>();
	pos.z = packetBuilder.read<float>();

	delta.x = packetBuilder.read<float>();
	delta.y = packetBuilder.read<float>();
	delta.z = packetBuilder.read<float>();

	FE_CONSOLELOG("pos(%f, %f, %f)", pos.x, pos.y, pos.z);
	FE_CONSOLELOG("delta(%f, %f, %f)", delta.x, delta.y, delta.z);

	float angle = packetBuilder.read<float>();
	fe::type::_32uint state = packetBuilder.read<fe::type::_32uint>();
	fe::type::_32uint flag = packetBuilder.read<fe::type::_32uint>();
	fe::type::_32uint motion = packetBuilder.read<fe::type::_32uint>();
	fe::type::_32uint motionExtend = packetBuilder.read<fe::type::_32uint>();
	fe::type::_32int loop = packetBuilder.read<fe::type::_32uint>();
	fe::type::_32uint motionOption = packetBuilder.read<fe::type::_32uint>();
	fe::type::_int tick = packetBuilder.read<fe::type::_32uint>();

	FE_CONSOLELOG("angle{%f} ", angle);
	FE_CONSOLELOG("state{%u} ", state);
	FE_CONSOLELOG("flag{%u} ", flag);
	FE_CONSOLELOG("motion{%u} ", motion);
	FE_CONSOLELOG("motionExtend{%u} ", motionExtend);
	FE_CONSOLELOG("loop{%d} ", loop);
	FE_CONSOLELOG("motionOption{%u} ", motionOption);
	FE_CONSOLELOG("tick{%d} ", tick);

}
