#include "pch_fressource.h"
#include "world_manager.hpp"
#include "reader_json.hpp"
#include "reader_xml.hpp"

fe::WorldManager::WorldManager() :
	worlds()
{
}

fe::WorldManager::~WorldManager()
{
	for (auto w : worlds)
	{
		delete w;
		w = nullptr;
	}
	worlds.clear();
}

bool fe::WorldManager::load(const std::string& filename)
{
	return false;
}

bool fe::WorldManager::loadWorld(const std::string& filename)
{
	World* world = new World();
	worlds.emplace_back(world);

	fe::ReaderJson	reader;
	if (reader.load(filename) == false)
		return false;

	fe::type::json::object root = reader.get<fe::type::json::object>(reader.root);

	return true;
}
