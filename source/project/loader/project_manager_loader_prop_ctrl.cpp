#include "pch_fressource.h"
#include "project_manager.hpp"
#include "reader_json.hpp"
#include "reader_xml.hpp"
#include "prop_ctrl.hpp"

bool    fe::ProjectManager::loadPropCtrl(const std::string& fileName, LOADER_MODE mode) noexcept
{
    if (fileName.empty())
        return false;
    switch (mode)
    {
        case fe::LOADER_MODE::JSON:
            return loadPropCtrlJson(fileName);
            break;
        case fe::LOADER_MODE::XML:
            return loadPropCtrlXml(fileName);
            break;
        default:
            return false;
    }
}

bool fe::ProjectManager::loadPropCtrlJson(const std::string& fileName) noexcept
{
    ReaderJson  reader;
    reader.header = getHeader();

    if (reader.load(fileName) == false)
        return false;

    fe::type::json::object& datas = reader.get<fe::type::json::object>(reader.root);
    for (auto& it : datas)
    {
        fe::type::json::object& item = reader.get<fe::type::json::object>(it.second);
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



bool fe::ProjectManager::loadPropCtrlXml(const std::string& fileName) noexcept
{
    ReaderXml reader;
    reader.header = getHeader();

    if (reader.load(fileName) == false)
        return false;
    fe::type::xml::node head = reader.document.child("ctrls");
    for (fe::type::xml::node& group : head)
    {
        for (fe::type::xml::node& ctrl : group)
        {
            fe::PropCtrl* prop = new fe::PropCtrl();
            prop->id = reader.getNumber<type::_uint>(ctrl, "dwID");
            prop->name = reader.getString(ctrl, "szName");
            prop->ctrlKind1 = reader.getNumber<type::_uint>(ctrl, "dwCtrlKind1");
            prop->ctrlKind2 = reader.getNumber<type::_uint>(ctrl, "dwCtrlKind2");
            prop->ctrlKind3 = reader.getNumber<type::_uint>(ctrl, "dwCtrlKind3");
            prop->sfxCtrl = reader.getNumber<type::_uint>(ctrl, "dwSfxCtrl");
            prop->soundDamage = reader.getNumber<type::_uint>(ctrl, "dwSndDamage");
            prop->comment = reader.getString(ctrl, "szComment");

            propctrl.push(prop->id, prop);
        }
    }
    return true;
}

