#include <iostream>
#include <ctime>

#include "framework.h"
#include "prop_ctrl.hpp"
#include "property_manager.hpp"
#include "project/project_manager.hpp"

bool    propkarma_load_from_file(fe::LOADER_MODE mode)
{
    fe::ProjectManager project;

    if (project.loadHeader("../../ressource/json/header/header_attribute.json", fe::LOADER_MODE::JSON) == false)
        return false;
    if (project.loadHeader("../../ressource/json/header/header_define.json", fe::LOADER_MODE::JSON) == false)
        return false;
    if (project.loadHeader("../../ressource/json/header/header_item.json", fe::LOADER_MODE::JSON) == false)
        return false;
    if (project.loadHeader("../../ressource/json/header/header_itemkind.json", fe::LOADER_MODE::JSON) == false)
        return false;
    if (project.loadHeader("../../ressource/json/header/header_job.json", fe::LOADER_MODE::JSON) == false)
        return false;
    if (project.loadHeader("../../ressource/json/header/header_neuz.json", fe::LOADER_MODE::JSON) == false)
        return false;
    if (project.loadHeader("../../ressource/json/header/header_obj.json", fe::LOADER_MODE::JSON) == false)
        return false;
    if (project.loadHeader("../../ressource/json/header/header_sound.json", fe::LOADER_MODE::JSON) == false)
        return false;
    if (project.loadHeader("../../ressource/json/header/header_skill.json", fe::LOADER_MODE::JSON) == false)
        return false;
    if (project.loadHeader("../../ressource/json/header/header_world.json", fe::LOADER_MODE::JSON) == false)
        return false;

    std::string extension;
    switch (mode)
    {
    case fe::LOADER_MODE::JSON:
        extension = "json";
        break;
    case fe::LOADER_MODE::XML:
        extension = "xml";
        break;
    case fe::LOADER_MODE::CSV:
        extension = "csv";
        break;
    default:
        break;
    }
    if (project.loadPropKarma("../../ressource/"+extension+"/prop/propKarma."+extension, mode) == false)
        return false;
    return true;
}