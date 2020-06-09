#pragma once
#include <sstream>
#include <fstream>
#include <string>
#include <utility>

#include <framework_fengine.h>
#include <io/file/reader.hpp>
#if defined(FLYFFENGINE_XML_PUGIXML)
#include <third_party/xml/pugixml.h>
#else
#endif

#include <iostream>

#pragma warning( disable : 4251 )

namespace fe
{
    /**
     * @brief Redifinition des types XML cela les bliotheque utiliser
     * Le principe etant d'abstraire et ne pas etre liée a une bibliotheque tout le long du projet
     * 
     */
    namespace type
    {
    namespace xml
    {
    #if defined(FLYFFENGINE_XML_PUGIXML)
            typedef pugi::xml_document      document;
            typedef pugi::xml_parse_result  result;
            typedef pugi::xml_node          node;
            typedef pugi::xml_attribute     attribute;
    #else
    #endif
        }
    }

    /**
     * @brief Object permettant le chargement des fichier XML
     * L'object et concue pour abstraire différent type de bibliotheque XML utilisable
     * 
     */
    class API_DECLSPEC ReaderXml
    {
    public:
        ReaderHeader   header;
        fe::type::xml::document   document;

        ReaderXml();
        ~ReaderXml();

        /**
         * @brief Recupérer le chaîne de caractères
         * 
         * @param node Noeud de travaille
         * @param nameAttribute Nom de l'attribute stockant la chaîne de caractère
         * @return std::string 
         */
        std::string getString(fe::type::xml::node& node, const std::string& nameAttribute) noexcept;
        /**
         * @brief Recupérer le boolean
         * 
         * @param node Noeud de travaille
         * @param nameAttribute Nom de l'attribute stockant le boolean
         * @return bool
         */
        bool    getBoolean(fe::type::xml::node& node, const std::string& nameAttribute) noexcept;        
        /**
         * @brief Recupérer un nombre
         * 
         * @tparam T Le type du nombre (int, float, double,...)
         * @param node Noeud de travaille
         * @param nameAttribute Nom de l'attribute stockant le nombre
         * @return T Le type du nombre (int, float, double,...)
         */
        template<typename T>
        T getNumber(fe::type::xml::node& node, const std::string& nameAttribute) noexcept
        {
            fe::type::xml::attribute attr = node.attribute(nameAttribute.c_str());
            if (attr.empty())
                return static_cast<T>(0);
            if (header.has(attr.as_string()))
                return static_cast<T>(header.get(attr.as_string()));
            return static_cast<T>(attr.as_llong());
        }

        /**
         * @brief Charge le fichier XML
         * 
         * @param fileName Nom du fichier
         * @return true 
         * @return false 
         */
        bool    load(const std::string& fileName) noexcept;
    };
}

#pragma warning( default: 4251 )