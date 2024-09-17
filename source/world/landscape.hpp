#include <framework_fengine.h>


namespace fe
{
    struct LandScape
    {
        unsigned int    width = 0;
        unsigned int    height = 0;
        unsigned int**  heightTerrain = nullptr;
        unsigned int**  heightWater = nullptr;
        unsigned int**  waterTexture = nullptr;

        LandScape() = default;
        LandScape(const LandScape&) = default;
        LandScape(LandScape&&) = delete;
        LandScape& operator=(const LandScape&) = delete;
        virtual ~LandScape() = default;
    };
}
#pragma warning( default : 4251 )
