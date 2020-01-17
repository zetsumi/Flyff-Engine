#pragma once

#include <string>
#include "framework.h"
#include "property.hpp"

namespace fe
{
    class API_DECLSPEC PropMoverEx : public PropertyContainer
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