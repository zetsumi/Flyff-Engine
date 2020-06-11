#include <tools/generator_packet/xmlLoader.hpp>
#include <util/log.hpp>

bool tools::XmlLoader::load(pugi::xml_document& doc, const std::string& filename) noexcept
{
	try
	{
		if (filename.empty() == true)
			return false;

		std::stringstream buffer;
		std::ifstream stream(filename);
		if (stream.is_open() == false)
			return false;
		buffer << stream.rdbuf();

		pugi::xml_parse_result result = doc.load_buffer(buffer.str().c_str(), buffer.str().size());
		if (result == false)
			return false;
	}
	catch (const std::exception& err)
	{
		FE_CONSOLELOG("error <%s>", err.what());
		return false;
	}
	return true;
}

bool tools::XmlLoader::loadPacket(const std::string& filename) noexcept
{
	pugi::xml_document doc;

	if (load(std::ref(doc), filename) == false)
		return false;

	try
	{
		const pugi::xml_node& root = doc.child("packets");
		for (const pugi::xml_node& nodePackets : root)
		{
			const pugi::xml_attribute& attr = nodePackets.attribute("name");
			const std::string& name = attr.as_string();
			FE_CONSOLELOG("name packet: %s", name.c_str());

			for (const pugi::xml_node& nodeAttr : nodePackets)
			{
				const pugi::xml_attribute& packetAttr = nodeAttr.attribute("name");
				const std::string& attrName = packetAttr.as_string();

				const pugi::xml_attribute& packetType = nodeAttr.attribute("type");
				const std::string& attrType = packetType.as_string();
				
				if (attrType.compare("ref") == 0)
				{
					const pugi::xml_attribute& packetType = nodeAttr.attribute("ref");
					const std::string& attrRef = packetType.as_string();
					FE_CONSOLELOG("Attribute Name[%s] Type[%s] Ref[%s]",
						attrName.c_str(),
						attrType.c_str(),
						attrRef.c_str()
					);
				}
				else
				{
					FE_CONSOLELOG("Attribute Name[%s] Type[%s]",
						attrName.c_str(),
						attrType.c_str()
					);
				}
			}
		}
	}
	catch (const std::exception& err)
	{
		FE_CONSOLELOG("error <%s>", err.what());
		return false;
	}


	return true;
}

bool tools::XmlLoader::loadProject(const std::string& filename) noexcept
{
	pugi::xml_document	docProject;

	if (load(std::ref(docProject), filename) == false)
		return false;
	try
	{
		const pugi::xml_node& root = docProject.child("project");
		const pugi::xml_attribute& attrPath = root.attribute("path");
		const std::string& path = attrPath.as_string();

		for (const pugi::xml_node& nodePacket : root)
		{
			const pugi::xml_attribute attr = nodePacket.attribute("filename");
			const std::string& fn = attr.as_string();
			const std::string& pathFilename = path + fn;
			FE_CONSOLELOG("path filename : %s", pathFilename.c_str());

			if (loadPacket(pathFilename) == false)
				return false;
		}
	}
	catch (const std::exception& err)
	{
		FE_CONSOLELOG("error <%s>", err.what());
		return false;
	}
	return true;
}
