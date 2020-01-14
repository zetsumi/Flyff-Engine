#include "pch.h"
#include "project_manager.hpp"
#include "reader_json.hpp"
#include "prop_ctrl.hpp"

bool    fe::ProjectManager::loadPropCtrl(const std::string& fileName, LOADER_MODE mode) noexcept
{
    if (fileName.empty())
        return false;
    switch (mode)
    {
        case fe::LOADER_MODE::JSON:
            loadPropCtrlJson(fileName);
            break;
        case fe::LOADER_MODE::XML:
            break;
        default:
            return false;
    }
}

bool fe::ProjectManager::loadPropCtrlJson(const std::string& fileName) noexcept
{
    ReaderJson  reader;
    reader.header = &header;

    if (reader.load(fileName) == false)
        return false;

    fe::json_object& datas = reader.get<json_object>(reader.root);
    for (auto& it : datas)
    {
        fe::json_object& item = reader.get<fe::json_object>(it.second);
        fe::PropCtrl* prop = new fe::PropCtrl();

        prop->id = reader.getNumber<fe::type::_uint>(item["dwID"]);
        prop->name = reader.get<std::string>(item["szName"]);
        prop->ctrlKind1 = reader.getNumber<fe::type::_uint>(item["dwCtrlKind1"]);
        prop->ctrlKind2 = reader.getNumber<fe::type::_uint>(item["dwCtrlKind2"]);
        prop->ctrlKind3 = reader.getNumber<fe::type::_uint>(item["dwCtrlKind3"]);
        prop->sfxCtrl = reader.getNumber<fe::type::_uint>(item["dwSfxCtrl"]);
        prop->soundDamage = reader.getNumber<fe::type::_uint>(item["dwSndDamage"]);
        prop->comment = reader.get<std::string>(item["szComment"]);
        
        propctrl.push(prop->id, prop);
    }
    return true;
}

