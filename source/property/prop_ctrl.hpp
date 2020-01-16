#pragma once

#include <string>
#include "framework.h"
#include "property.hpp"

#pragma warning( disable : 4251 )

namespace fe
{
    struct API_DECLSPEC PropCtrl : PropertyContainer
    {
        unsigned __int64    id;
        std::string         name;
        unsigned __int64    ctrlKind1;
        unsigned __int64    ctrlKind2;
        unsigned __int64    ctrlKind3;
        unsigned __int64    sfxCtrl;
        unsigned __int64    soundDamage;
        std::string         comment;

        PropCtrl() :
            id(0),
            ctrlKind1(0),
            ctrlKind2(0),
            ctrlKind3(0),
            sfxCtrl(0),
            soundDamage(0),
            comment()
        {}

        ~PropCtrl() {}

    };
}
#pragma warning( default : 4251 )
