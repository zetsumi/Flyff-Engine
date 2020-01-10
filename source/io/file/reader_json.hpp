#pragma once

#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>

#include "framework.h"
#include "reader.hpp"
#include "third_party/json/picojson.h"

namespace fe
{
    class API_DECLSPEC ReaderJson
    {
    public:
        picojson::value root;

        ReaderJson();
        ~ReaderJson();

        bool    load(const std::string& szFileJson) noexcept;
        bool    write(const std::string& szFileName) noexcept;
        bool    write(picojson::value& v, const std::string& szFileName) noexcept;
    };

}
