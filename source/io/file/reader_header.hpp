#pragma once

#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>

#include "framework.h"
#include "reader.hpp"

namespace fe
{
    class API_DECLSPEC ReaderHeader
    {
        std::unordered_map<std::string, unsigned __int64>    defines;

        bool    isValidLineHeader(const std::string& line) const noexcept;
        void    removeEmpty(std::string& line) const noexcept;
        bool    loadFromHeaderHPP(const std::string& fileName) noexcept;
        bool    loadFromJSON(const std::string& fileName) noexcept;
        bool    loadFromXML(const std::string& fileName) noexcept;
    public:
        ReaderHeader();
        ~ReaderHeader();

        bool                load(const std::string& fileName, LOADER_MODE mode) noexcept;
        void                write() const noexcept;
        unsigned __int64    get(const std::string& header) const noexcept;
        bool                has(const std::string& key) const;
    };
}

