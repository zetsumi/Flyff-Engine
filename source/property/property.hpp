#pragma once
#include "framework.h"

namespace fe
{
    enum class PROP_ITEM_ELEMENT : unsigned __int64
    {
        NO_PROP = 0, FIRE, WATER, ELECTRICITY, WIND, EARTH, END_PROP
    };

    struct API_DECLSPEC PropertyContainer
    {
        PropertyContainer()
        {
        }

        virtual ~PropertyContainer()
        {
        }
    };
}
