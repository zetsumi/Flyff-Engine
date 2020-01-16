#include "pch.h"
#include "project_manager.hpp"



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
