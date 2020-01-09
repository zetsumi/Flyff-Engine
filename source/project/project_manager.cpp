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

bool    fe::ProjectManager::loadHeader(const std::string& fileName) noexcept
{
    try
    {
        return header.loadHeader(fileName);
    }
    catch (const std::exception&)
    {
        return false;
    }
}
