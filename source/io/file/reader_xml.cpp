#include <pch_fressource.h>
#include <io/file/reader_header.hpp>
#include <io/file/reader_xml.hpp>


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
		fe::type::xml::result result = document.load_buffer(buffer.str().c_str(), buffer.str().size());
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

std::string fe::ReaderXml::getString(fe::type::xml::node& node, const std::string& nameAttribute) noexcept
{
	fe::type::xml::attribute attr = node.attribute(nameAttribute.c_str());
	if (attr.empty() == true)
		return std::string();
	return attr.as_string();
}

bool fe::ReaderXml::getBoolean(fe::type::xml::node& node, const std::string& nameAttribute) noexcept
{
	fe::type::xml::attribute attr = node.attribute(nameAttribute.c_str());
	if (attr.empty() == true)
		return false;
	return attr.as_bool();
}
