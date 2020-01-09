#include "pch.h"
#include "property_project.hpp"

fe::PropertyProject::PropertyProject()
{
}

fe::PropertyProject::~PropertyProject()
{
}

void fe::PropertyProject::push(fe::PROPERTY_TYPE typeProperty, fe::PropertyManager* manager) noexcept
{
    if (manager == nullptr)
        return;
    if (managers.find(typeProperty) == managers.end())
    {
        auto data = std::make_pair(typeProperty, manager);
        managers.insert(data);
    }
    else
    {
        auto it = managers.find(typeProperty);
        delete it->second;
        it->second = nullptr;
        managers.at(typeProperty) = manager;
    }
}

fe::PropertyManager* fe::PropertyProject::get(PROPERTY_TYPE typeProperty) noexcept
{
    auto manager = managers.find(typeProperty);
    if (manager == managers.end())
        return nullptr;
    return manager->second;
}

fe::PropertyContainer* fe::PropertyProject::get(PROPERTY_TYPE typeProperty, unsigned __int64 id) noexcept
{
    PropertyManager* manager = get(typeProperty);
    if (manager == nullptr)
        return nullptr;
    return manager->get(id);
}