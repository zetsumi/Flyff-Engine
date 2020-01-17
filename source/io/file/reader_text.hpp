#pragma once

#include <sstream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <utility>

#include "framework.h"
#include "reader.hpp"

#pragma warning( disable: 4251 )

namespace fe
{
    class API_DECLSPEC ReaderText
    {
        std::unordered_map<std::string, std::string>    texts = {};

        bool    loadJson(const std::string& fileName, bool skillEmpty = false);

    public:
        ReaderText(const ReaderText* o) : ReaderText(*o)
        {
        }
        ReaderText() = default;
        ReaderText(const ReaderText&) = default;
        ReaderText(ReaderText&&) noexcept = default;
        ReaderText& operator=(const ReaderText&) = default;
        ReaderText& operator=(ReaderText&&) = default;
        virtual ~ReaderText() = default;

        inline const std::string    get(const std::string& key) const noexcept
        {
            auto it = texts.find(key);
            if (it != texts.end())
                return it->second;
            return std::forward<std::string>("");
        }
        inline bool    has(const std::string& key) const noexcept
        {
            return texts.find(key) != texts.end() ? true : false;
        }

        bool    load(const std::string& fileName, LOADER_MODE mode, bool skillEmpty = false) noexcept;
    };
}



#pragma warning( default: 4251 )