#include <pch_fressource.h>
#include <world/world_manager.hpp>
#include <io/file/reader_header.hpp>
#include <io/file/reader_xml.hpp>
#include <io/file/reader_json.hpp>

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
