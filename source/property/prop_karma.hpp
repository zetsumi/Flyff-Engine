#pragma once

#include <string>
#include <framework_fengine.h>
#include <property/property.hpp>


#pragma warning( disable : 4251 )


namespace fe
{
    /**
     * @brief Strucutre representant les propriétés du Karma dans FLYFF.
     * Fichier "propkarma.txt"
     * 
     */
    struct API_DECLSPEC PropKarma : PropertyContainer
    {
        std::int64_t  id = 0;
        std::string     name = "";
        std::int64_t  karmaPoint = 0;
        std::uint64_t grade = 0;
        std::uint64_t color = 0;
        std::uint64_t karmaRecoverPoint = 0;
        std::uint64_t discountRate = 0;
        std::uint64_t sellPenaltyRate = 0;
        std::uint64_t guardReaction = 0;
        std::int64_t  subtractExpRate = 0;
        std::int64_t  dropGoldPercent = 0;
        std::int64_t  dropItem = 0;
        std::int64_t  dropPercent = 0;
        std::uint64_t karmaRecoverNum = 0;
        std::uint64_t statLimitTime = 0;
        std::uint64_t statLimitNum = 0;
        std::uint64_t statLimitRate = 0;
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
