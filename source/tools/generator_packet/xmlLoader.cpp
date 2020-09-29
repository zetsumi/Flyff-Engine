#include <tools/generator_packet/xmlLoader.hpp>
#include <util/log.hpp>
#include <algorithm>
#include <assert.h>

#define BEGIN_NAMESPACE(type)\
	file << "namespace fe" << std::endl;\
	file << "{" << std::endl;\
	file << "\t" << "namespace "; \
	if (type == tools::TYPE_PACKET::PACKETTYPE)\
		file << "packet" << std::endl;\
	else if (type == tools::TYPE_PACKET::SNAPSHOT)\
		file << "snapshot" << std::endl;\
	else if (type == tools::TYPE_PACKET::SERIALIZER)\
		file << "serialize" << std::endl;\
	file << "\t" << "{" << std::endl;

#define BEGIN_STRUCT(name, type)\
	file << "\t\t" << "struct API_DECLSPEC " << name << " final : public fe::PacketMessage" << std::endl;\
	file << "\t\t" << "{" << std::endl;

#define CONSTRUCTOR(name)\
	file << std::endl;\
	file << "\t\t\t" << name << "() = default;" << std::endl\
		<< "\t\t\t" << "~" << name << "() = default;" << std::endl\
		<< "\t\t\t" << name << "(const " << name << "&) = delete;" << std::endl\
		<< "\t\t\t" << name << "(" << name << "&&) = delete;" << std::endl;

#define BEGIN_OPERATOR_IN(name)\
	file << std::endl;\
	file << "\t\t\t" << "" << name << "& operator<<(fe::PacketBuilder& pb) override final" << std::endl;\
	file << "\t\t\t" << "{" << std::endl;

#define END_OPERATOR_IN()\
	file << "\t\t\t\t" << "return *this;" << std::endl;\
	file << "\t\t\t" << "}" << std::endl;

#define BEGIN_OPERATOR_OUT(name)\
	file << std::endl;\
	file << "\t\t\t" << "" << name << "& operator>>(fe::PacketBuilder& pb) override final" << std::endl;\
	file << "\t\t\t" << "{" << std::endl;

#define END_OPERATOR_OUT()\
	file << "\t\t\t\t" << "return *this;" << std::endl;\
	file << "\t\t\t" << "}" << std::endl;

#define BEGIN_RELEASE()\
	file << std::endl;\
	file << "\t\t\t" << "void release() override final" << std::endl;\
	file << "\t\t\t" << "{" << std::endl;

#define END_RELEASE()\
	file << "\t\t\t" << "}" << std::endl;

#define	END_STRUCT()\
	file << "\t\t" << "};" << std::endl;

#define END_NAMESPACE() \
	file << "\t" << "}" << std::endl; \
	file << "}" << std::endl;

#define DECLAR_VAR(type, name)\
	if (type.compare("vector3f") == 0)\
	{\
		file << "\t\t\t" << "fe::util::Vector3D<float> " << name << " = {0, 0, 0};" << std::endl;\
	}\
	else if(type.compare("string") == 0)\
	{\
		file << "\t\t\t" << "char* " << name << " = nullptr;" << std::endl;\
	}\
	else if(type.compare("string[]") == 0)\
	{\
		file << "\t\t\t" << "char** " << name << " = nullptr;" << std::endl;\
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
	if (type.compare("vector3f") == 0)\
	{\
		file << "\t\t\t\t" << name << ".x = pb.read<float>();" << std::endl;\
		file << "\t\t\t\t" << name << ".y = pb.read<float>();" << std::endl;\
		file << "\t\t\t\t" << name << ".z = pb.read<float>();" << std::endl;\
	}\
	else if(type.compare("string") == 0)\
	{\
		file << "\t\t\t\t" << name << " = pb.readString();" << std::endl;\
	}\
	else if (type.compare("string[]") == 0)\
	{\
			file << "\t\t\t\t" << name << " = new char*[" << name << "_count" << "]();" << std::endl; \
			file << "\t\t\t\t" << "for (fe::type::_u32int i = 0; i <" << name << "_count; ++i)" << std::endl;\
			file << "\t\t\t\t\t" << name << "[i] = const_cast<char*>(pb.readString());" << std::endl;\
	}\
	else if(type[0] == '_')\
	{\
		file << "\t\t\t\t" << "pb >> " << name << ";" << std::endl;\
	}\
	else\
	{\
		file << "\t\t\t\t" << name << " = pb.read<" << type << ">();" << std::endl; \
	}\


#define OUT_VAR(type, name)\
	if (type.compare("vector3f") == 0)\
	{\
		file << "\t\t\t\t" << "pb.write<float>(" << name << ".x" << ");" << std::endl;\
		file << "\t\t\t\t" << "pb.write<float>(" << name << ".y" << ");" << std::endl;\
		file << "\t\t\t\t" << "pb.write<float>(" << name << ".z" << ");" << std::endl;\
	}\
	else if(type.compare("string") == 0)\
	{\
		file << "\t\t\t\t" << "pb.writeString(" << name << ");" << std::endl;\
	}\
	else if (type.compare("string[]") == 0)\
	{\
			file << "\t\t\t\t" << name << " = new char* [" << name << "_count" << "]();" << std::endl; \
			file << "\t\t\t\t" << "for (fe::type::_32uint i = 0; i <" << name << "_count; ++i)" << std::endl;\
			file << "\t\t\t\t\t" << "pb.writeString(" << name << "[i])"  << std::endl;\
	}\
	else if(type[0] == '_')\
	{\
		file << "\t\t\t\t" << "pb.write<fe::type::" << type <<">(" << name << ");" << std::endl;\
	}\
	else\
	{\
		file << "\t\t\t\t" << "pb.write<" << type <<">(" << name << ");" << std::endl;\
	}\

#define DECLARE_SERIALIZE(type, name)\
	file << "\t\t\t" << "fe::serialize::" << type << " " << name << "{};" << std::endl;\

#define IN_VAR_SERILIAZE(name)\
	file << "\t\t\t\t" << "pb >> " << name << ";" << std::endl;\

#define OUT_VAR_SERILIAZE(name)\
	file << "\t\t\t\t" << name << " >> pb;" << std::endl;\

#define RELEASE_VAR(type, name)\
	if (type.compare("simple") == 0)\
	{\
		file << "\t\t\t\t" << "delete " << name << ";" << std::endl;\
		file << "\t\t\t\t" << name << " = nullptr;" << std::endl;\
	}\
	else if (type.compare("array") == 0)\
	{\
		file << "\t\t\t\t" << "for (unsigned int i = 0; i < " << name << "_count; ++i)" << std::endl;\
		file << "\t\t\t\t" << "{" << std::endl;\
		file << "\t\t\t\t\t" << "delete " << name << "[i];" << std::endl;\
		file << "\t\t\t\t\t" << name << " = nullptr;" << std::endl;\
		file << "\t\t\t\t" << "}" << std::endl;\
		file << "\t\t\t\t" << "delete[] " << name << ";" << std::endl;\
		file << "\t\t\t\t" << name << " = nullptr;" << std::endl;\
	}

void tools::XmlLoader::writeOperator(
	const pugi::xml_node & node,
	TYPE_PACKET packetType,
	std::ofstream& file,
	tools::TYPE_OPERATOR op)
{
	for (const pugi::xml_node& nodeAttr : node)
	{
		if (op != TYPE_OPERATOR::OP_RELEASE && strcmp(nodeAttr.name(), "attr") == 0)
		{
			const std::string& name = nodeAttr.attribute("name").as_string();
			const std::string& typeVar = nodeAttr.attribute("type").as_string();

			if (typeVar.compare("ref") == 0)
			{
				const pugi::xml_attribute& attrRef = nodeAttr.attribute("ref");
				const std::string& ref = attrRef.as_string();

				if (op == tools::TYPE_OPERATOR::OP_DECLAR)
				{
					DECLARE_SERIALIZE(ref, name);
				}
				else if (op == tools::TYPE_OPERATOR::OP_IN)
				{
					IN_VAR_SERILIAZE(name);
				}
				else if (op == tools::TYPE_OPERATOR::OP_OUT)
				{
					OUT_VAR_SERILIAZE(name);
				}
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
		else if (op == TYPE_OPERATOR::OP_RELEASE)
		{
			for (const pugi::xml_node& nodeRelease : nodeAttr)
			{
				const std::string& varName = nodeRelease.attribute("name").as_string();
				const std::string& varType = nodeRelease.attribute("type").as_string();
				RELEASE_VAR(varType, varName);
			}
		}
	}

}

void tools::XmlLoader::writeConfig(const std::string& product, const pugi::xml_node& node, TYPE_PACKET type)
{

	const pugi::xml_attribute& attrNameConfig = node.attribute("name");
	const std::string& nameConfig = attrNameConfig.as_string();
	const pugi::xml_attribute& attrFilenameConfig = node.attribute("filename");
	const std::string& filenameConfig = attrFilenameConfig.as_string();
	FE_LOG("Node name: %s", filenameConfig.c_str());

	std::string dir = "../../ressource/xml/tools/" + product;
	CreateDirectoryA(dir.c_str(), 0);

	if (type == TYPE_PACKET::PACKETTYPE)
		dir += "/packet";
	else if (type == TYPE_PACKET::SNAPSHOT)
		dir += "/snap";
	else if (type == TYPE_PACKET::SERIALIZER)
		dir += "/serializer";
	else
		assert(false);
	CreateDirectoryA(dir.c_str(), 0);


	if (type == TYPE_PACKET::PACKETTYPE)
		dir += "/packet_" + filenameConfig + ".hpp";
	else if (type == TYPE_PACKET::SNAPSHOT)
		dir += "/snap_" + filenameConfig + ".hpp";
	else if (type == TYPE_PACKET::SERIALIZER)
		dir += "/seriliazer_" + filenameConfig + ".hpp";
	else
		assert(false);
	FE_LOG("create file: %s", dir.c_str());

	std::ofstream	file;
	file.open(dir);
	if (file.is_open() == false)
		return;

	BEGIN_NAMESPACE(type);
	BEGIN_STRUCT(nameConfig, type);

	writeOperator(node, type, std::ref(file), tools::TYPE_OPERATOR::OP_DECLAR);

	CONSTRUCTOR(nameConfig);

	BEGIN_OPERATOR_IN(nameConfig);
	writeOperator(node, type, std::ref(file), tools::TYPE_OPERATOR::OP_IN);
	END_OPERATOR_IN();

	BEGIN_OPERATOR_OUT(nameConfig);
	writeOperator(node, type, std::ref(file), tools::TYPE_OPERATOR::OP_OUT);
	END_OPERATOR_OUT();

	BEGIN_RELEASE();
	writeOperator(node, type, std::ref(file), tools::TYPE_OPERATOR::OP_RELEASE);
	END_RELEASE();

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
		auto fctWriteConfigNode = [&](
			const std::string& nodeName,
			tools::TYPE_PACKET type)
		{
			const pugi::xml_node& root= doc.child(nodeName.c_str());
			const std::string& product = root.attribute("product").as_string();
			for (const pugi::xml_node& node : root)
				writeConfig(product, node, type);
		};
		fctWriteConfigNode("serializers", tools::TYPE_PACKET::SERIALIZER);
		fctWriteConfigNode("packets", tools::TYPE_PACKET::PACKETTYPE);
		fctWriteConfigNode("snaps", tools::TYPE_PACKET::SNAPSHOT);
	}
	catch (const std::exception& err)
	{
		FE_LOG("error <%s>", err.what());
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
			FE_LOG("path filename : %s", pathFilename.c_str());

			if (loadPacket(pathFilename) == false)
				return false;
		}
	}
	catch (const std::exception& err)
	{
		FE_LOG("error <%s>", err.what());
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
		FE_LOG("error <%s>", err.what());
		return false;
	}
	return true;
}
