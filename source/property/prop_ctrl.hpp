#pragma once

#include <string>
#include "framework.h"
#include "property.hpp"

#pragma warning( disable : 4251 )

namespace fe
{
    struct API_DECLSPEC PropCtrl : PropertyContainer
    {
        fe::type::_uint     id;
        std::string         name;
        fe::type::_uint     ctrlKind1;
        fe::type::_uint     ctrlKind2;
        fe::type::_uint     ctrlKind3;
        fe::type::_uint     sfxCtrl;
        fe::type::_uint     soundDamage;
        std::string         comment;

        PropCtrl() :
            id(0),
            ctrlKind1(0),
            ctrlKind2(0),
            ctrlKind3(0),
            sfxCtrl(0),
            soundDamage(0),
            comment()
        {
        }

        PropCtrl(PropCtrl* o) :
            id(o->id),
            ctrlKind1(o->ctrlKind1),
            ctrlKind2(o->ctrlKind2),
            ctrlKind3(o->ctrlKind3),
            sfxCtrl(o->sfxCtrl),
            soundDamage(o->soundDamage),
            comment(o->comment)
        {
        }

        PropCtrl(PropCtrl& o) :
            id(o.id),
            ctrlKind1(o.ctrlKind1),
            ctrlKind2(o.ctrlKind2),
            ctrlKind3(o.ctrlKind3),
            sfxCtrl(o.sfxCtrl),
            soundDamage(o.soundDamage),
            comment(o.comment)
        {
        }

        ~PropCtrl() {}

    };
}
#pragma warning( default : 4251 )
