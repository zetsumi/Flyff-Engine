#include <iostream>

#include "framework.h"
#include "property_manager.hpp"
#include "project/project_manager.hpp"

bool    sample_project()
{
    fe::ProjectManager project;

    bool val = project.load("../../ressource/json/project.json", fe::LOADER_MODE::JSON);
    if (val == false)
        return false;
    return true;
}