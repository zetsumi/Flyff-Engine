#include "pch.h"
#include "reader_json.hpp"

fe::ReaderJson::ReaderJson()
{

}

fe::ReaderJson::~ReaderJson()
{
}


bool fe::ReaderJson::load(const std::string& szFileJson) noexcept
{
    try
    {
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
    }
    catch (const std::exception&)
    {
        return false;
    }
    return true;
}


bool    fe::ReaderJson::write(picojson::value& v, const std::string& szFileName) noexcept
{
    try
    {
        std::ofstream myfile;
        myfile.open(szFileName);
        if (!myfile.is_open())
            return false;
        myfile << picojson::value(v).serialize(true);
        myfile.close();
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
        std::ofstream myfile;
        myfile.open(szFileName);
        if (!myfile.is_open())
            return false;
        myfile << picojson::value(root).serialize(true);
        myfile.close();
    }
    catch (const std::exception&)
    {
        return false;
    }
    return true;
}