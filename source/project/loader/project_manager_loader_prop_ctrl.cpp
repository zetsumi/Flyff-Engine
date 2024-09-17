#include <pch_fressource.h>
#include <project/project_manager.hpp>
#include <io/file/reader_json.hpp>
#include <io/file/reader_xml.hpp>
#include <property/prop_ctrl.hpp>


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

        prop->id = reader.getNumber<uint64_t>(item["dwID"]);
        prop->name = reader.get<std::string>(item["szName"]);
        prop->ctrlKind1 = reader.getNumber<uint64_t>(item["dwCtrlKind1"]);
        prop->ctrlKind2 = reader.getNumber<uint64_t>(item["dwCtrlKind2"]);
        prop->ctrlKind3 = reader.getNumber<uint64_t>(item["dwCtrlKind3"]);
        prop->sfxCtrl = reader.getNumber<uint64_t>(item["dwSfxCtrl"]);
        prop->soundDamage = reader.getNumber<uint64_t>(item["dwSndDamage"]);
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
            prop->id = reader.getNumber<uint64_t>(ctrl, "dwID");
            prop->name = reader.getString(ctrl, "szName");
            prop->ctrlKind1 = reader.getNumber<uint64_t>(ctrl, "dwCtrlKind1");
            prop->ctrlKind2 = reader.getNumber<uint64_t>(ctrl, "dwCtrlKind2");
            prop->ctrlKind3 = reader.getNumber<uint64_t>(ctrl, "dwCtrlKind3");
            prop->sfxCtrl = reader.getNumber<uint64_t>(ctrl, "dwSfxCtrl");
            prop->soundDamage = reader.getNumber<uint64_t>(ctrl, "dwSndDamage");
            prop->comment = reader.getString(ctrl, "szComment");

            propctrl.push(prop->id, prop);
        }
    }
    return true;
}

