#include "pch.h"
#include "reader_json.hpp"

fe::ReaderJson::ReaderJson()
{

}

fe::ReaderJson::~ReaderJson()
{
}


bool fe::ReaderJson::loadJson(picojson::value& v, const std::string& szFileJson) noexcept
{
    std::stringstream ss;
    std::ifstream f;
    f.open(szFileJson);
    if (!f.is_open())
        return false;
    ss << f.rdbuf();
    f.close();
    ss >> v;
    if (!picojson::get_last_error().empty())
        return false;
    return true;
}


bool    fe::ReaderJson::writeJson(picojson::value& v, const std::string& szFileName) noexcept
{
    std::ofstream myfile;
    myfile.open(szFileName);
    if (!myfile.is_open())
        return false;
    myfile << picojson::value(v).serialize(true);
    myfile.close();
    return true;
}