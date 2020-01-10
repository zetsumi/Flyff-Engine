#include "pch.h"
#include "project_manager.hpp"
#include "reader_json.hpp"


bool    fe::ProjectManager::loadPropItem(const std::string& fileName, LOADER_MODE mode) noexcept
{
    try
    {
        if (fileName.empty())
            return false;

        switch (mode)
        {
            case fe::LOADER_MODE::JSON:
                loadPropItemJson(fileName);
                break;
            case fe::LOADER_MODE::XML:
                break;
            default:
                return false;
        }
    }
    catch (const std::exception&)
    {
        return false;
    }
    return true;
}

const fe::ReaderHeader& fe::ProjectManager::getHeader() const
{
    return std::ref(header);
}

bool fe::ProjectManager::loadPropItemJson(const std::string& fileName) noexcept
{
    try
    {
        ReaderJson  reader;

        if (reader.load(fileName) == false)
            return false;
        picojson::object& data = reader.root.get<picojson::object>();
        for (auto& it : data)
        {
            //std::cout << it.first << std::endl;
        }
    }
    catch (const std::exception&)
    {
        return false;
    }
    return true;
}