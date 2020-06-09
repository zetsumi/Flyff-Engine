#pragma once

#include <string>
#include <framework_fengine.h>
#include <property/property.hpp>


namespace fe
{
    /**
     * @brief Structure representant les extension des Mover dans Flyff
     * Fichier "propmoverex.inc"
     * 
     */
    struct API_DECLSPEC PropMoverEx : public PropertyContainer
    {
        PropMoverEx(const PropMoverEx* o) : PropMoverEx(*o)
        {
        }

        PropMoverEx() = default;
        PropMoverEx(const PropMoverEx&) = default;
        PropMoverEx(PropMoverEx&&) noexcept = default;
        PropMoverEx& operator=(const PropMoverEx&) = default;
        PropMoverEx& operator=(PropMoverEx&&) = default;
        ~PropMoverEx() = default;
    };
}