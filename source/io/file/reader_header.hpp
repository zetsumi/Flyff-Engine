#pragma once

#include <sstream>
#include <fstream>
#include <string>
#include <unordered_map>

#include "framework.h"
#include "reader.hpp"

#pragma warning( disable: 4251 )

namespace fe
{
    class API_DECLSPEC ReaderHeader
    {
        std::unordered_map<std::string, fe::type::_uint>    defines = {};

        bool    isValidLineHeader(const std::string& line) const noexcept;
        void    removeEmpty(std::string& line) const noexcept;
        bool    loadFromHeaderHPP(const std::string& fileName) noexcept;
        bool    loadFromJSON(const std::string& fileName) noexcept;
        bool    loadFromXML(const std::string& fileName) noexcept;
    public:
        ReaderHeader(const ReaderHeader* o) : ReaderHeader(*o)
        {
        }
        ReaderHeader() = default;
        ReaderHeader(const ReaderHeader&) = default;
        ReaderHeader(ReaderHeader&&) noexcept = default;
        ReaderHeader& operator=(const ReaderHeader&) = default;
        ReaderHeader& operator=(ReaderHeader&&) = default;
        virtual ~ReaderHeader() = default;

        bool                load(const std::string& fileName, LOADER_MODE mode) noexcept;
        void                write() const noexcept;
        fe::type::_uint     get(const std::string& header) const noexcept;
        bool                has(const std::string& key) const;
    };
}

#pragma warning( default: 4251 )