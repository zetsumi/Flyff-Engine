#pragma once

#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>

#include "framework.h"

namespace fe
{
    class API_DECLSPEC ReaderHeader
    {
        std::unordered_map<const char*, unsigned __int64>    defines;

        bool    isValidLineHeader(const std::string& line) const noexcept;
        void    removeEmpty(std::string& line) const noexcept;
    public:
        ReaderHeader();
        ~ReaderHeader();

        bool                loadHeader(const std::string& pszFileName) noexcept;
        unsigned __int64    getHeader(const char* szHeader) const noexcept;

    };
}

