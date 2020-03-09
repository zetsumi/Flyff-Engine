#pragma once

#include <algorithm>
#include <unordered_map>

#include "framework.h"
#include "property.hpp"

#pragma warning( disable: 4251 )

namespace fe
{
    /**
     * @brief Object permettant de manager l'ensemble des propriété du project.
     * L'object permet de recevoir et de redonner des propriété creer en amont.
     * Une propriété stocker est relier un à ID
     * 
     */
    class API_DECLSPEC PropertyManager
    {
        std::unordered_map<fe::type::_uint, fe::PropertyContainer*>    properties;
    public:

        PropertyManager();
        ~PropertyManager();

        /**
         * @brief Ajout une nouvelle propriété sous la responsabilité du manager.
         * Le stocker est gérer via un std::pair<>
         * 
         * @param id ID correspond à la propriété, cette ID permet de recupérer plus tard d'information sur la structure stocké.
         * @param prop Pointeur representant la structure de donnée à stocker. Le pointeur ne doit pas etre nullptr.
         */
        void    push(fe::type::_uint id, fe::PropertyContainer* prop) noexcept;
        /**
         * @brief Permet de recupérer une structure de propriété stocké précedement via son ID unique
         * 
         * @param id ID correspondant à une structure de propriété.
         * @return fe::PropertyContainer* Si l'id est contenue le pointeur sur fe::PropertyContainer corespond aux propriété stocker sera retourner.
         * Si l'id n'est pas contenue nullptr sera retourné.
         */
        fe::PropertyContainer*  get(fe::type::_uint id) noexcept;
        /**
         * @brief Permet de recupérer une structure de propriété stocké précedement via son ID unique.
         * Le type de la propriété est dynamique.
         * 
         * @tparam C Type de l'object propriété rechargé
         * @param id ID correspondant à une structure de propriété.
         * @return C Type de l'object propriété rechargé
         */
        template<class C>
        C get(fe::type::_uint id) noexcept
        {
            auto val = get(id);
            if (val != nullptr)
                return dynamic_cast<C>(val);
            return nullptr;
        }
        /**
         * @brief Supprime la pair de donnée ID + Propriété stocké.
         * La propriété supprimer est free.
         * L'id doit être correct et connue pas le manager
         * 
         * @param id ID unique représentant la propriété qui doit etre supprimer du manager
         */
        void    remove(fe::type::_uint id) noexcept;
    };
}

#pragma warning( default: 4251 )
