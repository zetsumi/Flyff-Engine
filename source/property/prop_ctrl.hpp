#pragma once

#include <string>
#include <framework_fengine.h>
#include <property/property.hpp>

#pragma warning( disable : 4251 )


namespace fe
{
    /**
     * @brief Structure representant les propriétes des controler dans FLYFF.
     * Fichier "propctrl.txt"
     * 
     */
    struct API_DECLSPEC PropCtrl : PropertyContainer
    {
        uint64_t  id = { 0ull };
        std::string    name{};
        uint64_t  ctrlKind1{ 0ull };
        uint64_t  ctrlKind2{ 0ull };
        uint64_t  ctrlKind3{ 0ull };
        uint64_t  sfxCtrl{ 0ull };
        uint64_t  soundDamage{ 0ull };
        std::string    comment{};

        PropCtrl(const PropCtrl* o) : PropCtrl(*o) {}
        PropCtrl() = default;
        PropCtrl(const PropCtrl&) = default;
        PropCtrl(PropCtrl&&) noexcept = default;
        PropCtrl& operator=(const PropCtrl&) = default;
        PropCtrl& operator=(PropCtrl&&) = default;
        ~PropCtrl() = default;

    };
}
#pragma warning( default : 4251 )
