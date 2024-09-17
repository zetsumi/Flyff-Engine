#pragma once

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <utility>
#include <vector>
#include <unordered_map>

#include <third_party/xml/pugixml.h>

namespace tools
{
    enum class TYPE_OPERATOR : unsigned short
    {
        OP_DECLAR,
        OP_IN,
        OP_OUT,
        OP_RELEASE
    };

    enum class TYPE_PACKET : unsigned short
    {
        PACKETTYPE,
        SNAPSHOT,
        SERIALIZER,
        UNKNOW
    };


    class XmlLoader final
    {
        [[nodiscard]] bool	load(
            pugi::xml_document& doc,
            std::string const& filename) noexcept;
        [[nodiscard]] bool	loadPacket(
            std::string const& filename,
            std::string const& outdir) noexcept;

        void writeOperator(
            pugi::xml_node const& node,
            TYPE_PACKET packetType,
            std::ofstream& file,
            TYPE_OPERATOR op);
        void writeConfig(
            std::string const& outdir,
            std::string const& product,
            pugi::xml_node const& node,
            TYPE_PACKET type);

    public:
        XmlLoader() = default;
        XmlLoader(XmlLoader const&) = delete;
        XmlLoader(XmlLoader&&) = delete;
        ~XmlLoader() = default;

        [[nodiscard]] bool	loadProject(std::string const& filename) noexcept;
    };
}
