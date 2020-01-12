#pragma once

#include <algorithm>
#include <unordered_map>

#include "framework.h"
#include "property.hpp"

#pragma warning( disable: 4251 )

namespace fe
{
    class API_DECLSPEC PropertyManager
    {
        std::unordered_map<fe::type::_uint, fe::PropertyContainer*>    properties;
    public:

        PropertyManager();
        ~PropertyManager();

        void    push(fe::type::_uint id, fe::PropertyContainer* prop) noexcept;
        fe::PropertyContainer*  get(fe::type::_uint id) noexcept;
        template<class C>
        C get(fe::type::_uint id) noexcept
        {
            auto val = get(id);
            if (val != nullptr)
                return dynamic_cast<C>(val);
            return nullptr;
        }
        void    remove(fe::type::_uint id) noexcept;
    };
}

#pragma warning( default: 4251 )
