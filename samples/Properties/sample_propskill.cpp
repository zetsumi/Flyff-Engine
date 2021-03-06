#include <iostream>
#include <ctime>

#include <framework_fengine.h>
#include <property/prop_skill.hpp>
#include <property/property_manager.hpp>
#include <project/project_manager.hpp>
#include <util/log.hpp>


bool    propskill_load_from_file(fe::LOADER_MODE mode)
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
    if (project.loadPropSkill("../../ressource/" + extension + "/prop/propSkill." + extension, mode) == false)
        return false;

    fe::PropSkill* skill = project.getSkill(1);
    fe::PropSkill* skillCopy = project.createSkill(1);

    FE_CONSOLELOG("Skill Name[%s]", skill->name.c_str());
    FE_CONSOLELOG("skillCopy Name[%s]", skillCopy->name.c_str());
    return true;
}