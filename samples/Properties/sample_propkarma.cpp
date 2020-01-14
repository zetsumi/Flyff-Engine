#include <iostream>
#include <ctime>

#include "framework.h"
#include "prop_ctrl.hpp"
#include "property_manager.hpp"
#include "project/project_manager.hpp"

bool    propkarma_load_from_file()
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

    if (project.loadPropKarma("../../ressource/json/prop/propKarma.json", fe::LOADER_MODE::JSON) == false)
        return false;
    return true;
}