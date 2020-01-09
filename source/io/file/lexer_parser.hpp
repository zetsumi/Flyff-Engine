#pragma once

#include <sstream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <algorithm>

namespace fe
{
    class API_DECLSPEC LexerParser
    {
        std::unordered_map<const char*, unsigned __int64>    defines;

        bool    isValidLineHeader(const std::string& line) const noexcept;
        void    removeEmpty(std::string& line) const noexcept;

    public:
        LexerParser();
        ~LexerParser();

        bool            loadHeader(const std::string& pszFileName) noexcept;
        unsigned __int64    getHeader(const char* szHeader) const noexcept;
        void            loadJson(picojson::value& v, const std::string& szFileJson);
        BOOL            writeJson(picojson::value& v, const std::string& szFileName) noexcept;
    };
}
