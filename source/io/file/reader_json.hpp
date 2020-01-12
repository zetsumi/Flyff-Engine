#pragma once

#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>

#include "framework.h"
#include "reader.hpp"
#if defined(FLYFFENGINE_JSON_PICOJSON)
#include "third_party/json/picojson.h"
#else
#endif

namespace fe
{
#if defined(FLYFFENGINE_JSON_PICOJSON)
    typedef picojson::object    json_object;
    typedef picojson::value     json_value;
#else
#endif

    class API_DECLSPEC ReaderJson
    {
    public:
        json_value root;
        ReaderHeader* header;

        ReaderJson();
        ~ReaderJson();

        bool    load(const std::string& szFileJson) noexcept;
        bool    write(const std::string& szFileName) noexcept;
        bool    write(json_value& v, const std::string& szFileName) noexcept;

        template<typename T, typename U>
        constexpr T& get(U& container)
        {
#if defined(FLYFFENGINE_JSON_PICOJSON)
            return container.get<T>();
#else
            return 0;
#endif
        }

        template<typename T>
        constexpr bool getBoolean(T& container)
        {
#if defined(FLYFFENGINE_JSON_PICOJSON)
            if (container.is<bool>())
                return container.get<bool>();
            else if (container.is<double>())
                return static_cast<bool>(container.get<double>());
            std::string& str = container.get<std::string>();
            if (str == "true" || str == "True" || str == "TRUE")
                return true;
            if (str == "false" || str == "False" || str == "FALSE" || str == "=")
                return false;
            throw std::exception("error");
#else
#endif
        }

        template<typename T, typename U>
        constexpr T getNumber(U& container)
        {
            try
            {
#if defined(FLYFFENGINE_JSON_PICOJSON)
                if (std::is_same<T, double>::value && container.is<double>())
                    return container.get<double>();
                T value = static_cast<T>(container.get<double>());
                return value;
#else
                return 0;
#endif
            }
            catch (const std::exception&)
            {
                try
                {
#if defined(FLYFFENGINE_JSON_PICOJSON)
                    std::string& str = container.get<std::string>();
#else
                    return 0;
#endif
                    if (header->has(str))
                        return header->get(str);
                    else if (str == "=")
                        return 0;
                    else if (str.find("0x") != std::string::npos)
                    {
                        long long hexa = std::stoll(str.c_str(), nullptr, 16);
                        return static_cast<T>(hexa);
                    }
                }
                catch (const std::exception&)
                {
                    return 0;
                }
            }
        }
    };
}
