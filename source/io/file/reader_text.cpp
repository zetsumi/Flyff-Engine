#include "pch.h"
#include "reader_text.hpp"
#include "reader_json.hpp"

bool fe::ReaderText::load(const std::string& fileName, LOADER_MODE mode, bool skillEmpty) noexcept
{
    switch (mode)
    {
    case fe::LOADER_MODE::JSON:
        return loadJson(fileName, skillEmpty);
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

bool fe::ReaderText::loadJson(const std::string& fileName, bool skillEmpty)
{
    fe::ReaderJson reader;

    if (reader.load(fileName) == false)
        return false;
    fe::json_object& data = reader.root.get<fe::json_object>();
    for (auto& it : data)
    {
        try
        {
            const std::string& key = it.first;
            const std::string& value = reader.get<std::string>(it.second);
            if (skillEmpty == true && value.empty() == true)
                continue;
            texts[key] = value;
        }
        catch (const std::exception&)
        {
            return false;
        }
    }
    return true;
}
