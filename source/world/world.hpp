#pragma once

#include <framework_fengine.h>
#include <string>

#pragma warning( disable : 4251 )


namespace fe
{
    /*
    ** @brief structure representant un monde
    */
    struct API_DECLSPEC World
    {
        std::string title = "";
        std::string directory = "";
        uint32_t id = 0;
        uint32_t MPU = 4;
        uint32_t width = 0;
        uint32_t height = 0;
        bool         indoor = false;
        bool         fly = false;

        // Parameters missing !
        //self.ambient = str() #hexa
        //self.bgColor = str() #hexa
        //self.diffuse = str()
        //self.size = Vector(0, 0, 0)
        //self.camera = list()
        //self.revival = list()
        //self.text = OrderedDict()
        //self.lightDir = list()
        //self.fogSetting = list()
        //self.bgm = list()
        //self.pkmode = list()

        World() = default;
        World(const World&) = default;
        World(World&&) noexcept = default;
        World& operator=(const World&) = default;
        World& operator=(World&&) = default;
        virtual ~World() = default;
    };
}
#pragma warning( default : 4251 )
