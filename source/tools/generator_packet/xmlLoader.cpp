#include <tools/generator_packet/xmlLoader.hpp>
#include <util/log.hpp>
#include <algorithm>
#include <assert.h>

#define BEGIN_NAMESPACE(type)\
	file << "namespace " << std::endl;\
	file << "{" << std::endl;\
	file << "\t" << "namespace "; \
	if (type == tools::TYPE_PACKET::PACKETTYPE)\
		file << "packet" << std::endl;\
	else if (type == tools::TYPE_PACKET::SNAPSHOT)\
		file << "snapshot" << std::endl;\
	else if (type == tools::TYPE_PACKET::SERIALIZER)\
		file << "serialize" << std::endl;\
	file << "\t" << "{" << std::endl;

#define BEGIN_STRUCT(name)\
	file << "\t\t" << "struct API_DECLSPEC " << name << " final : public PacketMessage" << std::endl;\
	file << "\t\t" << "{" << std::endl;

#define CONSTRUCTOR(name)\
	file << "\t\t\t" << name << "() = default;" << std::endl\
		<< "\t\t\t" << "~" << name << "() = default;" << std::endl\
		<< "\t\t\t" << name << "(const " << name << "&) = delete;" << std::endl\
		<< "\t\t\t" << name << "(" << name << "&&) = delete;" << std::endl;

#define BEGIN_OPERATOR_IN(name)\
	file << std::endl;\
	file << "\t\t\t" << "inline " << name << "& operator<<(fe::PacketBuilder& pb) override final" << std::endl;\
	file << "\t\t\t" << "{" << std::endl;

#define END_OPERATOR_IN()\
	file << "\t\t\t\t" << "return *this;" << std::endl;\
	file << "\t\t\t" << "}" << std::endl;

#define BEGIN_OPERATOR_OUT(name)\
	file << std::endl;\
	file << "\t\t\t" << "inline " << name << "& operator>>(fe::PacketBuilder& pb) override final" << std::endl;\
	file << "\t\t\t" << "{" << std::endl;

#define END_OPERATOR_OUT()\
	file << "\t\t\t\t" << "return *this;" << std::endl;\
	file << "\t\t\t" << "}" << std::endl;

#define	END_STRUCT()\
	file << "\t\t" << "};" << std::endl;

#define END_NAMESPACE() \
	file << "\t" << "}" << std::endl; \
	file << "}" << std::endl;

#define DECLAR_VAR(type, name)\
	if (type.compare("vectorf") == 0)\
	{\
		file << "\t\t\t" << "fe::Vector<float> " << name << " = {0, 0, 0};" << std::endl;\
	}\
	else if(type[0] == '_')\
	{\
		file << "\t\t\t" << "fe::type::" << type << " " << name << " = 0;" << std::endl;\
	}\
	else\
	{\
		file << "\t\t\t" << type << " " << name << " = 0;" << std::endl;\
	}\

#define IN_VAR(type, name)\
	if (type.compare("vectorf") == 0)\
	{\
		file << "\t\t\t\t" << name << ".x = pb.read<float>();" << std::endl;\
		file << "\t\t\t\t" << name << ".y = pb.read<float>();" << std::endl;\
		file << "\t\t\t\t" << name << ".z = pb.read<float>();" << std::endl;\
	}\
	else if(type[0] == '_')\
	{\
		file << "\t\t\t\t" << "pb >> " << name << ";" << std::endl;\
	}\
	else\
	{\
		file << "\t\t\t\t" << name << " = pb.read<" << type << ">();" << std::endl; \
	}


#define OUT_VAR(type, name)\
	if (type.compare("vectorf") == 0)\
	{\
		file << "\t\t\t\t" << "pb.write<float>(" << name << ".x" << ");" << std::endl;\
		file << "\t\t\t\t" << "pb.write<float>(" << name << ".y" << ");" << std::endl;\
		file << "\t\t\t\t" << "pb.write<float>(" << name << ".z" << ");" << std::endl;\
	}\
	else if(type[0] == '_')\
	{\
		file << "\t\t\t\t" << "pb.write<fe::type::" << type <<">(" << name << ");" << std::endl;\
	}\
	else\
	{\
		file << "\t\t\t\t" << "pb.write<" << type <<">(" << name << ");" << std::endl;\
	}

void tools::XmlLoader::writeOperator(
	const pugi::xml_node & node,
	TYPE_PACKET packetType,
	std::ofstream& file,
	tools::TYPE_OPERATOR op)
{
	for (const pugi::xml_node& nodeAttr : node)
	{
		const pugi::xml_attribute& attrName = nodeAttr.attribute("name");
		const std::string& name = attrName.as_string();

		const pugi::xml_attribute& attrType = nodeAttr.attribute("type");
		const std::string& typeVar = attrType.as_string();


		if (typeVar.compare("ref") == 0)
		{
			const pugi::xml_attribute& attrRef = nodeAttr.attribute("ref");
			const std::string& ref = attrRef.as_string();
		}
		else
		{
			if (op == tools::TYPE_OPERATOR::OP_DECLAR)
			{
				DECLAR_VAR(typeVar, name);
			}
			else if (op == tools::TYPE_OPERATOR::OP_IN)
			{
				IN_VAR(typeVar, name);
			}
			else if (op == tools::TYPE_OPERATOR::OP_OUT)
			{
				OUT_VAR(typeVar, name);
			}
		}
	}

}

void tools::XmlLoader::writeConfig(const pugi::xml_node& node, TYPE_PACKET type)
{

	const pugi::xml_attribute& attrNameConfig = node.attribute("name");
	const std::string& nameConfig = attrNameConfig.as_string();
	const pugi::xml_attribute& attrFilenameConfig = node.attribute("filename");
	const std::string& filenameConfig = attrFilenameConfig.as_string();
	FE_CONSOLELOG("Node name: %s", filenameConfig.c_str());

	std::ofstream	file;
	if (type == TYPE_PACKET::PACKETTYPE)
		file.open("../../ressource/xml/tools/packet/packet_" + filenameConfig + ".hpp");
	else if (type == TYPE_PACKET::SNAPSHOT)
		file.open("../../ressource/xml/tools/snap/packet_snap_" + filenameConfig + ".hpp");
	else if (type == TYPE_PACKET::SNAPSHOT)
		file.open("../../ressource/xml/tools/serializer/seriliazer_" + filenameConfig + ".hpp");

	if (file.is_open() == false)
		return;

	BEGIN_NAMESPACE(type);
	BEGIN_STRUCT(nameConfig);
	writeOperator(node, type, std::ref(file), tools::TYPE_OPERATOR::OP_DECLAR);
	file << std::endl;
	CONSTRUCTOR(nameConfig);
	BEGIN_OPERATOR_IN(nameConfig);
	writeOperator(node, type, std::ref(file), tools::TYPE_OPERATOR::OP_IN);
	END_OPERATOR_IN();
	file << std::endl;
	BEGIN_OPERATOR_OUT(nameConfig);
	writeOperator(node, type, std::ref(file), tools::TYPE_OPERATOR::OP_OUT);
	END_OPERATOR_OUT();
	END_STRUCT();
	END_NAMESPACE();
	file.close();
}

bool tools::XmlLoader::loadPacket(const std::string& filename) noexcept
{
	pugi::xml_document doc;

	if (load(std::ref(doc), filename) == false)
		return false;

	try
	{
		const pugi::xml_node& nodeSerializers = doc.child("serializers");
		const pugi::xml_node& nodePackets = doc.child("packets");
		const pugi::xml_node& nodeSnaps = doc.child("snaps");

		for (const pugi::xml_node& node : nodeSerializers)
			writeConfig(node, TYPE_PACKET::SERIALIZER);
		for (const pugi::xml_node& node : nodePackets)
			writeConfig(node, TYPE_PACKET::PACKETTYPE);
		for (const pugi::xml_node& node : nodeSnaps)
			writeConfig(node, TYPE_PACKET::SNAPSHOT);
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
