#pragma once
#include "framework.h"

namespace fe
{
    enum class PROP_ITEM_ELEMENT : fe::type::_uint
    {
        NO_PROP = 0,
        FIRE,
        WATER,
        ELECTRICITY,
        WIND,
        EARTH,
        END_PROP
    };

    struct API_DECLSPEC PropertyContainer
    {

        PropertyContainer(const PropertyContainer* o) : PropertyContainer(*o)
        {
        }

        PropertyContainer() = default;
        PropertyContainer(const PropertyContainer&) = default;
        PropertyContainer(PropertyContainer&&) noexcept = default;
        PropertyContainer& operator=(const PropertyContainer&) = default;
        PropertyContainer& operator=(PropertyContainer&&) = default;
        virtual ~PropertyContainer() = default;
    };
}
