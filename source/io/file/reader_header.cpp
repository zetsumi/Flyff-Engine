#include "pch.h"
#include "reader_header.hpp"
#include "reader_json.hpp"

fe::ReaderHeader::ReaderHeader()
{
}

fe::ReaderHeader::~ReaderHeader()
{
}

bool    fe::ReaderHeader::isValidLineHeader(const std::string& line) const noexcept
{
    if (line.size() == 0)
        return false;
    if (line.find("//") != std::string::npos
        || line.find("#ifndef") != std::string::npos
        || line.find("#endif") != std::string::npos
        || line.find("#pragma once") != std::string::npos)
        return false;
    if (line.find("#define") == std::string::npos)
        return false;
    bool    isFullSpace = true;
    for (auto it : line)
        if (it != ' ' && it != '\t')
            isFullSpace = false;
    if (isFullSpace)
        return false;
    return true;
}


void    fe::ReaderHeader::removeEmpty(std::string& line) const noexcept
{
    std::string tmp;
    size_t i = 0;
    size_t size = line.size();
    while (i < size && line[i])
    {
        tmp += line[i];
        if (line[i] == ' ' || line[i] == '\t')
        {
            tmp += ' ';
            while ((line[i] == ' ' || line[i] == '\t') && line[i])
                ++i;
        }
        else
            ++i;
    }
    if (tmp[tmp.size() - 1] == ' ')
        tmp[tmp.size() - 1] = '\0';
    line.clear();
    line.assign(tmp);
}

bool fe::ReaderHeader::loadFromHeaderHPP(const std::string& fileName) noexcept
{
    try
    {
        std::ifstream fd;
        fd.open(fileName);
        if (!fd.is_open())
            return false;

        std::string line;
        while (std::getline(fd, line))
        {
            if (!isValidLineHeader(line))
                continue;
            removeEmpty(line);
            std::istringstream ss(line);
            std::string tmp;
            std::vector<std::string> segments;
            while (std::getline(ss, tmp, ' '))
            {
                tmp.erase(std::remove(tmp.begin(), tmp.end(), ' '), tmp.end());
                tmp.erase(std::remove(tmp.begin(), tmp.end(), '\t'), tmp.end());
                if (tmp.size() > 0)
                    segments.push_back(std::string(tmp));
            }
            if (segments.size() < 3)
                continue;
            std::istringstream sid(segments[2].c_str());
            unsigned __int64 uid;
            sid >> uid;
            segments[1].erase(std::remove(segments[1].begin(), segments[1].end(), ' '), segments[1].end());
            segments[1].erase(std::remove(segments[1].begin(), segments[1].end(), '\t'), segments[1].end());
            if (segments[1].size() == 0)
                continue;
            defines[segments[1].c_str()] = static_cast<unsigned __int64>(uid);
        }
        fd.close();
    }
    catch (const std::exception&)
    {
        return false;
    }
    return true;
}

bool fe::ReaderHeader::loadFromJSON(const std::string& fileName) noexcept
{

    ReaderJson reader;

    if (reader.load(fileName) == false)
        return false;
    picojson::object& data = reader.root.get<picojson::object>();
    for (auto& it : data)
    {
        const std::string& key = it.first;
        unsigned __int64 value;
        try
        {
            // converstion en unisgned __int64 si la valeur d'origine n'est pas une string
            value  = static_cast<unsigned __int64>(it.second.get<double>());
        }
        catch (const std::exception&)
        {
            std::string& str = it.second.get<std::string>();
            try
            {
                if (str.find("0x") != std::string::npos) // si la valeur est en hexa
                    value = std::stoull(str, nullptr, 16);
                else
                    value = std::stoull(str, nullptr, 10); // si la valeur est en decimal
            }
            catch (const std::exception&)
            {
                const auto& refValue = defines.find(str);
                if (refValue != defines.end())
                    value = refValue->second; // fait reference a une autre valeur deja definie
                else
                    continue; // on ignore la valeur
            }
        }
        defines[key] = value;
    }
    return true;
}

bool fe::ReaderHeader::loadFromXML(const std::string& fileName) noexcept
{
    return true;
}

bool    fe::ReaderHeader::load(const std::string& fileName,LOADER_MODE mode) noexcept
{
    if (fileName.empty())
        return false;

    switch (mode)
    {
        case fe::LOADER_MODE::JSON:
            return loadFromJSON(fileName);
        case fe::LOADER_MODE::XML:
            return loadFromXML(fileName);
        default:
            if (fileName.find(".h") != std::string::npos)
                return loadFromHeaderHPP(fileName);
    }
    return false;
}

unsigned __int64    fe::ReaderHeader::get(const std::string& header) const noexcept
{
    auto it = defines.find(header);
    if (it != defines.end())
        return it->second;
    return 0;
}

bool fe::ReaderHeader::has(const std::string& key) const
{
    return defines.find(key) != defines.end();
}

void fe::ReaderHeader::write() const noexcept
{
    ReaderJson json;

    json.root.set<picojson::object>(picojson::object());
    picojson::object* o = &json.root.get<picojson::object>();
    for (auto& it : defines)
    {
        (*o)[it.first] = picojson::value(static_cast<double>(it.second));
    }
    json.write("header.json");
}
