#include <tools/generator_packet/xmlLoader.hpp>
#include <util/log.hpp>
#include <algorithm>
#include <assert.h>

#define HEADER_INCLUDE()\
	file << "#include <cstdint>" << "\n";\
	file << "\n\n";

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
		<< "\t\t\t" << name << "(" << name << " const&) = delete;" << std::endl\
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
			file << "\t\t\t\t" << "for (auto i{ 0u }; i <" << name << "_count; ++i)" << std::endl;\
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
			file << "\t\t\t\t" << "for (std::uint32_t i = 0; i <" << name << "_count; ++i)" << std::endl;\
			file << "\t\t\t\t\t" << "pb.writeString(" << name << "[i])"  << std::endl;\
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
	if (type.compare("ptr") == 0)\
	{\
		file << "\t\t\t\t" << "delete " << name << ";" << std::endl;\
		file << "\t\t\t\t" << name << " = nullptr;" << std::endl;\
	}\
	else if (type.compare("array") == 0)\
	{\
		file << "\t\t\t\t" << "for (auto i{ 0u }; i < " << name << "_count; ++i)" << std::endl;\
		file << "\t\t\t\t" << "{" << std::endl;\
		file << "\t\t\t\t\t" << "delete " << name << "[i];" << std::endl;\
		file << "\t\t\t\t\t" << name << " = nullptr;" << std::endl;\
		file << "\t\t\t\t" << "}" << std::endl;\
		file << "\t\t\t\t" << "delete[] " << name << ";" << std::endl;\
		file << "\t\t\t\t" << name << " = nullptr;" << std::endl;\
	}

void tools::XmlLoader::writeOperator(
	pugi::xml_node const& node,
	TYPE_PACKET packetType,
	std::ofstream& file,
	tools::TYPE_OPERATOR op)
{
	for (auto const& nodeAttr : node)
	{
		if (op != TYPE_OPERATOR::OP_RELEASE && strcmp(nodeAttr.name(), "attr") == 0)
		{
			std::string const& name{ nodeAttr.attribute("name").as_string() };
			std::string const& typeVar{ nodeAttr.attribute("type").as_string() };

			if (typeVar.compare("ref") == 0)
			{
				pugi::xml_attribute const& attrRef{ nodeAttr.attribute("ref") };
				std::string const& ref{ attrRef.as_string() };

				switch (op)
				{
					case tools::TYPE_OPERATOR::OP_DECLAR:
						DECLARE_SERIALIZE(ref, name);
						break;
					case tools::TYPE_OPERATOR::OP_IN:
						IN_VAR_SERILIAZE(name);
						break;
					case tools::TYPE_OPERATOR::OP_OUT:
						OUT_VAR_SERILIAZE(name);
						break;
					case tools::TYPE_OPERATOR::OP_RELEASE:
						break;
					default:
						break;
				}
			}
			else
			{
				switch (op)
				{
					case tools::TYPE_OPERATOR::OP_DECLAR:
						DECLAR_VAR(typeVar, name);
						break;
					case tools::TYPE_OPERATOR::OP_IN:
						IN_VAR(typeVar, name);
						break;
					case tools::TYPE_OPERATOR::OP_OUT:
						OUT_VAR(typeVar, name);
						break;
					case tools::TYPE_OPERATOR::OP_RELEASE:
						break;
					default:
						break;
				}
			}
		}
		else if (op == TYPE_OPERATOR::OP_RELEASE)
		{
			for (auto const& nodeRelease : nodeAttr)
			{
				std::string const& varName = nodeRelease.attribute("name").as_string();
				std::string const& varType = nodeRelease.attribute("type").as_string();
				RELEASE_VAR(varType, varName);
			}
		}
	}

}

void tools::XmlLoader::writeConfig(
	std::string const& outdir,
	std::string const& product,
	pugi::xml_node const& node,
	TYPE_PACKET type)
{

	auto const& attrNameConfig{ node.attribute("name") };
	auto const& nameConfig{ attrNameConfig.as_string() };
	auto const& attrFilenameConfig{ node.attribute("filename") };
	auto const& filenameConfig{ std::string(attrFilenameConfig.as_string()) };
	FE_LOG("Node name: %s", filenameConfig.c_str());

	std::string dir{ "packets/" + product };
	CreateDirectoryA(dir.c_str(), 0);

	switch (type)
	{
        case TYPE_PACKET::PACKETTYPE:
            dir += "/packet";
            break;
        case TYPE_PACKET::SNAPSHOT:
            dir += "/snap";
            break;
        case TYPE_PACKET::SERIALIZER:
            dir += "/serializer";
            break;
		default:
			assert(false);
	}

	CreateDirectoryA(dir.c_str(), 0);

    switch (type)
    {
        case TYPE_PACKET::PACKETTYPE:
            dir += "/packet_" + filenameConfig + ".hpp";
            break;
        case TYPE_PACKET::SNAPSHOT:
            dir += "/snap_" + filenameConfig + ".hpp";
            break;
        case TYPE_PACKET::SERIALIZER:
            dir += "/seriliazer_" + filenameConfig + ".hpp";
            break;
        default:
            assert(false);
    }

	FE_LOG("create file: %s", dir.c_str());

	std::ofstream file;
	file.open(dir);
	if (file.is_open() == false)
	{
        return;
	}

	HEADER_INCLUDE();

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

bool tools::XmlLoader::loadPacket(
	std::string const& filename,
	std::string const& outdir) noexcept
{
	pugi::xml_document doc;

	if (load(std::ref(doc), filename) == false)
	{
        return false;
	}

	try
	{
		auto fctWriteConfigNode = [&](
			const std::string& nodeName,
			tools::TYPE_PACKET type)
		{
			auto const& root{ doc.child(nodeName.c_str()) };
			auto const& product{ root.attribute("product").as_string() };
			for (auto const& node : root)
			{
				writeConfig(outdir, product, node, type);
			}
		};
		fctWriteConfigNode("serializers", tools::TYPE_PACKET::SERIALIZER);
		fctWriteConfigNode("packets", tools::TYPE_PACKET::PACKETTYPE);
		fctWriteConfigNode("snaps", tools::TYPE_PACKET::SNAPSHOT);
	}
	catch (std::exception const& err)
	{
		FE_LOG("error <%s>", err.what());
		return false;
	}

	return true;
}

bool tools::XmlLoader::loadProject(std::string const& filename) noexcept
{
	pugi::xml_document	docProject;

	if (load(std::ref(docProject), filename) == false)
	{
		return false;
	}

	try
	{
		auto const& root{ docProject.child("project") };
		auto const& attrPath{ root.attribute("path") };
		auto const& basedir{ attrPath.as_string() };

		for (auto const& nodePacket : root)
		{
			auto const attr{ nodePacket.attribute("filename") };
			auto const& fn{ std::string(attr.as_string()) };
			auto const& pathFilename{ basedir + fn };
			FE_LOG("path filename : %s", pathFilename.c_str());

			if (loadPacket(pathFilename, basedir) == false)
			{
				return false;
			}
		}
	}
	catch (std::exception const& err)
	{
		FE_LOG("error <%s>", err.what());
		return false;
	}
	return true;
}

bool tools::XmlLoader::load(pugi::xml_document& doc, std::string const& filename) noexcept
{
	try
	{
		if (filename.empty() == true)
		{
			return false;
		}

		std::stringstream buffer;
		std::ifstream stream(filename);
		if (stream.is_open() == false)
		{
			return false;
		}
		buffer << stream.rdbuf();

		auto const result{ doc.load_buffer(buffer.str().c_str(), buffer.str().size()) };
		if (result == false)

		{return false;
		}
	}
	catch (std::exception const& err)
	{
		FE_LOG("error <%s>", err.what());
		return false;
	}
	return true;
}
