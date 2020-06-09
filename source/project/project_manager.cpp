#include <pch_fressource.h>
#include <project/project_manager.hpp>
#include <io/file/reader_json.hpp>
#include <io/file/reader_xml.hpp>


fe::ProjectManager::ProjectManager() :
    header(),
    propitem(),
    propctrl(),
    propmover(),
    propkarma(),
    propskill(),
    propskilltroupe()
{
}

fe::ProjectManager::~ProjectManager()
{
}

bool fe::ProjectManager::load(const std::string& fileName, LOADER_MODE mode) noexcept
{
    if (fileName.empty() == true)
        return false;
    switch (mode)
    {
        case fe::LOADER_MODE::JSON:
            return loadJson(fileName);
            break;
        case fe::LOADER_MODE::XML:
            break;
        case fe::LOADER_MODE::CSV:
            break;
        default:
            break;
    }
    return false;
}

bool fe::ProjectManager::loadJson(const std::string& fileName) noexcept
{
    fe::ReaderJson reader;

    if (reader.load(fileName) == false)
        return false;
    fe::type::json::object root = reader.get<fe::type::json::object>(reader.root);

    // path ressource
    std::string& path = reader.get<std::string>(root["path_ressource"]);
    path.append("json/");
    
    // load texts
    fe::type::json::array& texts = reader.get<fe::type::json::array>(root["texts"]);
    for (auto& it : texts)
    {
        const std::string& filename = reader.get<std::string>(it);
        const std::string& fullpath = path + "text/" + filename;
        if (loadText(fullpath, fe::LOADER_MODE::JSON) == false)
            return false;
    }

    // load defines
    fe::type::json::array& defines = reader.get<fe::type::json::array>(root["defines"]);
    for(auto & it : defines)
    {
        const std::string& filename = reader.get<std::string>(it);
        const std::string& fullpath = path + "header/" + filename;
        if (loadHeader(fullpath, fe::LOADER_MODE::JSON) == false)
            return false;
    }

    // load props
    fe::type::json::object& props = reader.get<fe::type::json::object>(root["props"]);
    const std::string& propitem = reader.get<std::string>(reader.get<fe::type::json::object>(props["propitem"])["json"]);
    const std::string& propmover = reader.get<std::string>(reader.get<fe::type::json::object>(props["propmover"])["json"]);
    const std::string& propmover_extend = reader.get<std::string>(reader.get<fe::type::json::object>(props["propmover_extend"])["json"]);
    const std::string& propmover_ai = reader.get<std::string>(reader.get<fe::type::json::object>(props["propmover_ai"])["json"]);
    const std::string& propctrl = reader.get<std::string>(reader.get<fe::type::json::object>(props["propctrl"])["json"]);
    const std::string& propskill = reader.get<std::string>(reader.get<fe::type::json::object>(props["propskill"])["json"]);
    const std::string& proptroupeskill = reader.get<std::string>(reader.get<fe::type::json::object>(props["proptroupeskill"])["json"]);
    const std::string& propkarma = reader.get<std::string>(reader.get<fe::type::json::object>(props["propkarma"])["json"]);
    const std::string& propquest = reader.get<std::string>(reader.get<fe::type::json::object>(props["propquest"])["json"]);
    const std::string& random_event_monster = reader.get<std::string>(reader.get<fe::type::json::object>(props["random_event_monster"])["json"]);

    const std::string& fullPathProp = path + "prop/";
    loadPropItem(fullPathProp + propitem, fe::LOADER_MODE::JSON);
    loadPropCtrl(fullPathProp + propctrl, fe::LOADER_MODE::JSON);
    loadPropKarma(fullPathProp + propkarma, fe::LOADER_MODE::JSON);
    loadPropSkill(fullPathProp + propskill, fe::LOADER_MODE::JSON);

    return true;
}

bool fe::ProjectManager::loadXml(const std::string& fileName) noexcept
{
    return true;
}


bool    fe::ProjectManager::loadHeader(const std::string& fileName, LOADER_MODE mode) noexcept
{
    try
    {
        return header.load(fileName, mode);
    }
    catch (const std::exception&)
    {
        return false;
    }
}

bool fe::ProjectManager::loadText(const std::string& fileName, LOADER_MODE mode, bool skippEmpty) noexcept
{
    try
    {
        return text.load(fileName, mode, skippEmpty);
    }
    catch (const std::exception&)
    {
        return false;
    }
}
