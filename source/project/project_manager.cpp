#include "pch.h"
#include "project_manager.hpp"
#include "reader_json.hpp"
#include "reader_xml.hpp"



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

    fe::json_object root = reader.get<fe::json_object>(reader.root);
    fe::json_array& texts = reader.get<fe::json_array>(root["texts"]);
    for (auto& it : texts)
    {
        const std::string& fileNameText = reader.get<std::string>(it);
        if (loadText("../../ressource/json/text/" + fileNameText, fe::LOADER_MODE::JSON) == false)
            return false;
    }
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
