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

bool fe::ProjectManager::loadPropItemJson(const std::string& fileName) noexcept
{
    try
    {
        ReaderJson  reader;

        if (reader.loadJson(fileName) == false)
            return false;
    }
    catch (const std::exception&)
    {
        return false;
    }
    return true;
}