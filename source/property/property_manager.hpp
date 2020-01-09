#pragma once

#include <unordered_map>
#include "framework.h"
#include "property.hpp"

#pragma warning( disable: 4251 )

namespace fe
{
    class API_DECLSPEC PropertyManager
    {
        std::unordered_map<unsigned __int64, fe::PropertyContainer*>    properties;
    public:

        PropertyManager();
        ~PropertyManager();

        void    push(unsigned __int64 id, fe::PropertyContainer* prop) noexcept;
        fe::PropertyContainer*  get(unsigned __int64 id) noexcept;
        template<class C>
        C get(unsigned __int64 id) noexcept
        {
            auto val = get(id);
            if (val != nullptr)
                return dynamic_cast<C>(val);
            return nullptr;
        }
        void    remove(unsigned __int64 id) noexcept;
    };
}

#pragma warning( default: 4251 )
