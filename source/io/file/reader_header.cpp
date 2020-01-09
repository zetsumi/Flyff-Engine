#include "pch.h"
#include "reader_header.hpp"

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

bool    fe::ReaderHeader::loadHeader(const std::string& fileName) noexcept
{
    if (fileName.empty())
        return false;

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
    return true;
}

unsigned __int64    fe::ReaderHeader::getHeader(const char* header) const noexcept
{
    auto it = defines.find(header);
    if (it != defines.end())
        return it->second;
    return 0;
}