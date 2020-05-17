#pragma once

#include "framework_fressource.h"
#include <vector>
#include <list>

#include "world.hpp"

namespace fe
{
	class WorldManager
	{
		std::vector<fe::World*>	worlds;

	public:
		WorldManager();
		~WorldManager();

		bool	load(const std::string& filename);
		bool	loadWorld(const std::string& filename);
	};
}