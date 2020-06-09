#include <iostream>

#include <framework_fengine.h>
#include <property/property_manager.hpp>
#include <project/project_manager.hpp>
#include <util/log.hpp>

bool load_text_json()
{
    fe::ProjectManager  project;


    if (!project.loadText("../../ressource/json/text/text_ctrl.json", fe::LOADER_MODE::JSON))
        return false;
    if (!project.loadText("../../ressource/json/text/text_item.json", fe::LOADER_MODE::JSON, true))
        return false;

    FE_CONSOLELOG("IDS_PROPCTRL_TXT_000013 : has(%d) value[%s]",
        project.getText().has("IDS_PROPCTRL_TXT_000013"),
        project.getText().get("IDS_PROPCTRL_TXT_000013").c_str());

    FE_CONSOLELOG("IDS_PROPCTRL_TXT_000016 : has(%d) value[%s]",
        project.getText().has("IDS_PROPCTRL_TXT_000016"),
        project.getText().get("IDS_PROPCTRL_TXT_000016").c_str());

    FE_CONSOLELOG("IDS_PROPITEM_TXT_000101 : has(%d) value[%s]",
        project.getText().has("IDS_PROPITEM_TXT_000101"),
        project.getText().get("IDS_PROPITEM_TXT_000101").c_str());

    return true;
}
