#pragma once

#include <string>
#include "framework.h"
#include "property.hpp"

namespace fe
{
    struct API_DECLSPEC PropKarma : PropertyContainer
    {
        __int64                 id;
        std::string             name;
        unsigned __int64        karmaPoint;
        unsigned __int64        grade;
        unsigned __int64        color;
        unsigned __int64        karmaRecoverPoint;
        unsigned __int64        discountRate;
        unsigned __int64        sellPenaltyRate;
        unsigned __int64        guardReaction;
        unsigned __int64        subtractExpRate;
        __int64                 dropGoldPercent;
        __int64                 dropItem;
        __int64                 dropPercent;
        unsigned __int64        karmaRecoverNum;
        unsigned __int64        statLimitTime;
        unsigned __int64        statLimitNum;
        unsigned __int64        statLimitRate;
        std::string             comment;

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
        ~PropKarma() {}
    };
}