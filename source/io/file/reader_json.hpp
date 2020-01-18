#pragma once

#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>

#include "framework.h"
#include "reader.hpp"
#include "reader_header.hpp"
#if defined(FLYFFENGINE_JSON_PICOJSON)
#include "third_party/json/picojson.h"
#else
#endif

#pragma warning( disable : 4251 )
namespace fe
{
#if defined(FLYFFENGINE_JSON_PICOJSON)
    typedef picojson::object    json_object;
    typedef picojson::array     json_array;
    typedef picojson::value     json_value;
#else
#endif

    class API_DECLSPEC ReaderJson
    {
    public:
        json_value  root;
        ReaderHeader header;

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
            return container.evaluate_as_boolean();
#else
#endif
        }

        template<typename T, typename U>
        constexpr T getNumber(U& container)
        {

#if defined(FLYFFENGINE_JSON_PICOJSON)
            if (container.is<std::string>() == true)
            {
                std::string& str = container.get<std::string>();
                if (str.find("0x") != std::string::npos)
                    return static_cast<T>(std::stoll(str.c_str(), nullptr, 16));
                if (header.has(str) == true)
                    return static_cast<T>(header.get(str));
                if (std::is_same<type::_int, T>::value)
                    return static_cast<T>(std::atoll(str.c_str()));
                if (std::is_same<type::_uint, T>::value)
                    return static_cast<T>(std::stoll(str.c_str(), nullptr, 10));
            }
            return static_cast<T>(container.get<double>());
#else
#endif
        }
    };
}

#pragma warning( default: 4251 )