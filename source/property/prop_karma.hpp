#pragma once

#include <string>
#include "framework.h"
#include "property.hpp"

#pragma warning( disable : 4251 )

namespace fe
{
    struct API_DECLSPEC PropKarma : PropertyContainer
    {
        fe::type::_int  id = 0;
        std::string     name = "";
        fe::type::_int  karmaPoint = 0;
        fe::type::_uint grade = 0;
        fe::type::_uint color = 0;
        fe::type::_uint karmaRecoverPoint = 0;
        fe::type::_uint discountRate = 0;
        fe::type::_uint sellPenaltyRate = 0;
        fe::type::_uint guardReaction = 0;
        fe::type::_int  subtractExpRate = 0;
        fe::type::_int  dropGoldPercent = 0;
        fe::type::_int  dropItem = 0;
        fe::type::_int  dropPercent = 0;
        fe::type::_uint karmaRecoverNum = 0;
        fe::type::_uint statLimitTime = 0;
        fe::type::_uint statLimitNum = 0;
        fe::type::_uint statLimitRate = 0;
        std::string     comment = "";

        PropKarma(const PropKarma* o) : PropKarma(*o)
        {
        }

        PropKarma() = default;
        PropKarma(const PropKarma&) = default;
        PropKarma(PropKarma&&) noexcept = default;
        PropKarma& operator=(const PropKarma&) = default;
        PropKarma& operator=(PropKarma&&) = default;
        ~PropKarma() = default;
    };
}

#pragma warning( default : 4251 )
