#include "pch.h"
#include "property_manager.hpp"

constexpr void fe::PropertyManager::push(unsigned __int64 id, fe::PropertyContainer* property)
{
    if (!property)
        return;
    if (properties.find(id) == properties.end())
    {
        auto data = std::make_pair(id, property);
        properties.insert(data);
    }
    else
    {
        properties.at(id) = property;
    }
}

constexpr fe::PropertyContainer* fe::PropertyManager::get(unsigned __int64 id)
{
    auto it = properties.find(id);
    if (it == properties.end())
        return nullptr;
    return it->second;
}

constexpr fe::PropertyContainer* fe::PropertyManager::remove(unsigned __int64 id)
{
    auto property = get(id);
    if (property)
    {
        delete property;
        property = nullptr;
    }
}

#undef FE_PROPERTY_CLASSNAME
#define FE_PROPERTY_CLASSNAME Test

FE_PROPERTY_CLASS_BEGIN

FE_PROPERTY_VAR(int, toto)
FE_PROPERTY_VAR(int, tata)
FE_PROPERTY_VAR(char*, title)

FE_PROPERTY_INITIALIZE_BEGIN
FE_PROPERTY_INITIALIZE_VAR(toto, 0)
FE_PROPERTY_INITIALIZE_VAR(tata, 0)
FE_PROPERTY_INITIALIZE_VAR(title, new char[2]())
FE_PROPERTY_INITIALIZE_END

FE_PROPERTY_DESTROY_DEGIN
FE_PROPERTRY_DESTROY_VAR(title, delete)
FE_PROPERTY_DESTROY_END

FE_PROPERTY_CLASS_END


