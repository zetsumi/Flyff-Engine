#pragma once

#include <framework_fengine.h>
#include <vector>
#include <list>

#include <world/world.hpp>

namespace fe
{
    class WorldManager
    {
        std::vector<fe::World*>	worlds{};

    public:
        WorldManager() = default;
        ~WorldManager();

        [[nodiscard]] bool	load(const std::string& filename);
        [[nodiscard]] bool	loadWorld(const std::string& filename);
    };
}