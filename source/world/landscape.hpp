#include <framework_fengine.h>


namespace fe
{
    struct LandScape
    {
        uint32_t    width = 0;
        uint32_t    height = 0;
        uint32_t**  heightTerrain = nullptr;
        uint32_t**  heightWater = nullptr;
        uint32_t**  waterTexture = nullptr;

        LandScape() = default;
        LandScape(const LandScape&) = default;
        LandScape(LandScape&&) = delete;
        LandScape& operator=(const LandScape&) = delete;
        virtual ~LandScape() = default;
    };
}
#pragma warning( default : 4251 )
