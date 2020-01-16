#pragma once

#include <string>
#include "framework.h"
#include "property.hpp"

#pragma warning( disable : 4251 )

namespace fe
{
    struct API_DECLSPEC PropKarma : PropertyContainer
    {
        fe::type::_int  id;
        std::string     name;
        fe::type::_int  karmaPoint;
        fe::type::_uint grade;
        fe::type::_uint color;
        fe::type::_uint karmaRecoverPoint;
        fe::type::_uint discountRate;
        fe::type::_uint sellPenaltyRate;
        fe::type::_uint guardReaction;
        fe::type::_int  subtractExpRate;
        fe::type::_int  dropGoldPercent;
        fe::type::_int  dropItem;
        fe::type::_int  dropPercent;
        fe::type::_uint karmaRecoverNum;
        fe::type::_uint statLimitTime;
        fe::type::_uint statLimitNum;
        fe::type::_uint statLimitRate;
        std::string     comment;

        PropKarma() :
            id(0),
            name(),
            karmaPoint(0),
            grade(0),
            color(0),
            karmaRecoverPoint(0),
            discountRate(0),
            sellPenaltyRate(0),
            guardReaction(0),
            subtractExpRate(0),
            dropGoldPercent(0),
            dropItem(0),
            dropPercent(0),
            karmaRecoverNum(0),
            statLimitTime(0),
            statLimitNum(0),
            statLimitRate(0),
            comment()
        {}
        PropKarma(PropKarma* o) :
            id(o->id),
            name(o->name),
            karmaPoint(o->karmaPoint),
            grade(o->grade),
            color(o->color),
            karmaRecoverPoint(o->karmaRecoverPoint),
            discountRate(o->discountRate),
            sellPenaltyRate(o->sellPenaltyRate),
            guardReaction(o->guardReaction),
            subtractExpRate(o->subtractExpRate),
            dropGoldPercent(o->dropGoldPercent),
            dropItem(o->dropItem),
            dropPercent(o->dropPercent),
            karmaRecoverNum(o->karmaRecoverNum),
            statLimitTime(o->statLimitTime),
            statLimitNum(o->statLimitNum),
            statLimitRate(o->statLimitRate),
            comment(o->comment)
        {
        }

        PropKarma(PropKarma& o) :
            id(o.id),
            name(o.name),
            karmaPoint(o.karmaPoint),
            grade(o.grade),
            color(o.color),
            karmaRecoverPoint(o.karmaRecoverPoint),
            discountRate(o.discountRate),
            sellPenaltyRate(o.sellPenaltyRate),
            guardReaction(o.guardReaction),
            subtractExpRate(o.subtractExpRate),
            dropGoldPercent(o.dropGoldPercent),
            dropItem(o.dropItem),
            dropPercent(o.dropPercent),
            karmaRecoverNum(o.karmaRecoverNum),
            statLimitTime(o.statLimitTime),
            statLimitNum(o.statLimitNum),
            statLimitRate(o.statLimitRate),
            comment(o.comment)
        {
        }
        ~PropKarma() {}


    };
}

#pragma warning( default : 4251 )
