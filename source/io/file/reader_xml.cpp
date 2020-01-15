#include "pch.h"
#include "reader_header.hpp"
#include "reader_xml.hpp"

fe::ReaderXml::ReaderXml() :
    header(),
	document()
{
}

fe::ReaderXml::~ReaderXml()
{
}

bool fe::ReaderXml::load(const std::string& fileName) noexcept
{
	try
	{
		if (fileName.empty())
        return false;

		std::stringstream buffer;
		std::ifstream stream(fileName);
		if (stream.is_open() == false)
			return false;
		buffer << stream.rdbuf();
#if defined(FLYFFENGINE_XML_PUGIXML)
		xml::result result = document.load_buffer(buffer.str().c_str(), buffer.str().size());
		if (!result)
			return false;
#else
#endif
	}
	catch (const std::exception&)
	{
		return false;
	}
    return true;
}
