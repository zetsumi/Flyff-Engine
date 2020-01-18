#include <iostream>

#include "framework.h"
#include "property_manager.hpp"
#include "project/project_manager.hpp"

bool load_text_json()
{
    fe::ProjectManager  project;

    bool val = project.load("../../ressource/json/project.json", fe::LOADER_MODE::JSON);

    //if (!project.loadText("../../ressource/json/text/text_ctrl.json", fe::LOADER_MODE::JSON))
    //    return false;
    //if (!project.loadText("../../ressource/json/text/text_item.json", fe::LOADER_MODE::JSON, true))
    //    return false;
    //std::cout << "IDS_PROPCTRL_TXT_000013 : has("
    //    << std::boolalpha << project.getText().has("IDS_PROPCTRL_TXT_000013") << std::noboolalpha
    //    << ") value[" << project.getText().get("IDS_PROPCTRL_TXT_000013")
    //    << "]" << std::endl;

    //std::cout << "IDS_PROPCTRL_TXT_000016 : has("
    //    << std::boolalpha << project.getText().has("IDS_PROPCTRL_TXT_000016") << std::noboolalpha
    //    << ") value[" << project.getText().get("IDS_PROPCTRL_TXT_000016")
    //    << "]" << std::endl;

    //std::cout << "IDS_PROPITEM_TXT_000106 : has("
    //    << std::boolalpha << project.getText().has("IDS_PROPITEM_TXT_000106") << std::noboolalpha
    //    << ") value[" << project.getText().get("IDS_PROPITEM_TXT_000106")
    //    << "]" << std::endl;

    //std::cout << "IDS_PROPITEM_TXT_000101 : has("
    //    << std::boolalpha << project.getText().has("IDS_PROPITEM_TXT_000101") << std::noboolalpha
    //    << ") value[" << project.getText().get("IDS_PROPITEM_TXT_000101")
    //    << "]" << std::endl;

    return true;
}
