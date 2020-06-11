#pragma once

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <utility>

#include <third_party/xml/pugixml.h>

namespace tools
{
	class XmlLoader final
	{
		[[nodiscard]] bool	load(pugi::xml_document& doc, const std::string& filename) noexcept;
		[[nodiscard]] bool	loadPacket(const std::string& filename) noexcept;

	public:
		XmlLoader() = default;
		XmlLoader(const XmlLoader&) = delete;
		XmlLoader(XmlLoader&&) = delete;
		~XmlLoader() = default;

		[[nodiscard]] bool	loadProject(const std::string & filename) noexcept;
	};
}
