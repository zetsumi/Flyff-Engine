#pragma once

#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>
#include "framework.h"
#include "third_party/json/picojson.h"

namespace fe
{
    class API_DECLSPEC ReaderJson
    {
    public:
        picojson::value root;

        ReaderJson();
        ~ReaderJson();

        bool    loadJson(picojson::value& v, const std::string& szFileJson) noexcept;
        bool    writeJson(picojson::value& v, const std::string& szFileName) noexcept;
    };

}
