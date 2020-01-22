#pragma once
#include <sstream>
#include <fstream>
#include <string>
#include <utility>

#include "framework.h"
#include "reader.hpp"
#if defined(FLYFFENGINE_XML_PUGIXML)
#include "third_party/xml/pugixml.h"
#else
#endif

#include <iostream>

#pragma warning( disable : 4251 )

namespace fe
{
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

    class API_DECLSPEC ReaderXml
    {
    public:
        ReaderHeader   header;
        fe::type::xml::document   document;

        ReaderXml();
        ~ReaderXml();

        std::string getString(fe::type::xml::node& node, const std::string& nameAttribute) noexcept;
        bool    getBoolean(fe::type::xml::node& node, const std::string& nameAttribute) noexcept;

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

        bool    load(const std::string& fileName) noexcept;
    };
}

#pragma warning( default: 4251 )