#include "pch_fressource.h"
#include "reader_header.hpp"
#include "reader_json.hpp"

fe::ReaderJson::ReaderJson() :
    root(),
    header()
{

}

fe::ReaderJson::~ReaderJson()
{
}


bool fe::ReaderJson::load(const std::string& szFileJson) noexcept
{
    try
    {
#if defined(FLYFFENGINE_JSON_PICOJSON)
        std::stringstream ss;
        std::ifstream f;
        f.open(szFileJson);
        if (!f.is_open())
            return false;
        ss << f.rdbuf();
        f.close();
        ss >> root;
        if (!picojson::get_last_error().empty())
            return false;
#else
        return false;
#endif
    }
    catch (const std::exception&)
    {
        return false;
    }
    return true;
}


bool    fe::ReaderJson::write(fe::type::json::value& v, const std::string& szFileName) noexcept
{
    try
    {
#if defined(FLYFFENGINE_JSON_PICOJSON)
        std::ofstream myfile;
        myfile.open(szFileName);
        if (!myfile.is_open())
            return false;
        myfile << fe::type::json::value(v).serialize(true);
        myfile.close();
#else
        return false;
#endif
    }
    catch (const std::exception&)
    {
        return false;
    }
    return true;
}

bool    fe::ReaderJson::write(const std::string& szFileName) noexcept
{
    try
    {
#if defined(FLYFFENGINE_JSON_PICOJSON)
        std::ofstream myfile;
        myfile.open(szFileName);
        if (!myfile.is_open())
            return false;
        myfile << fe::type::json::value(root).serialize(true);
        myfile.close();
#else
        return false;
#endif
    }
    catch (const std::exception&)
    {
        return false;
    }
    return true;
}