#include "framework_fengine.h"

#pragma warning( disable : 4251 )
namespace fe
{
	struct LandScape
	{
        unsigned int    width = 0;
        unsigned int    height = 0;
        unsigned int**  heightTerrain = nullptr;
        unsigned int**  heightWater = nullptr;
        unsigned int**  waterTexture = nullptr;

        LandScape(const LandScape* p) : LandScape(*p) {}
        LandScape() = default;
        LandScape(const LandScape&) = default;
        LandScape(LandScape&&) noexcept = default;
        LandScape& operator=(const LandScape&) = default;
        LandScape& operator=(LandScape&&) = default;
        virtual ~LandScape() = default;
	};
}
#pragma warning( default : 4251 )
