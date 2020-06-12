#pragma once

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <utility>
#include <vector>
#include <unordered_map>

#include <third_party/xml/pugixml.h>

namespace tools
{
	enum class TYPE_OPERATOR : unsigned short
	{
		OP_DECLAR,
		OP_IN,
		OP_OUT
	};

	enum class TYPE_PACKET : unsigned short
	{
		PACKETTYPE,
		SNAPSHOT,
		SERIALIZER,
		UNKNOW
	};


	class XmlLoader final
	{
		[[nodiscard]] bool	load(pugi::xml_document& doc, const std::string& filename) noexcept;
		[[nodiscard]] bool	loadPacket(const std::string& filename) noexcept;

		void	writeOperator(const pugi::xml_node& node, TYPE_PACKET packetType, std::ofstream& file, TYPE_OPERATOR op);
		void	writeConfig(const pugi::xml_node& node, TYPE_PACKET type);

	public:
		XmlLoader() = default;
		XmlLoader(const XmlLoader&) = delete;
		XmlLoader(XmlLoader&&) = delete;
		~XmlLoader() = default;

		[[nodiscard]] bool	loadProject(const std::string & filename) noexcept;
	};
}
