#pragma once

#include <unordered_map>

#include "property.hpp"

namespace fe
{
    class PropertyManager
    {
        std::unordered_map<unsigned __int64, fe::PropertyContainer*>    properties;

    public:
        constexpr void push(unsigned __int64 id, fe::PropertyContainer* property);
        constexpr fe::PropertyContainer* get(unsigned __int64 id);
        constexpr fe::PropertyContainer* remove(unsigned __int64 id);
    };
}
