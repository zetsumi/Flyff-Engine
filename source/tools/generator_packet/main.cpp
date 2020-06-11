#include <iostream>
#include <tools/generator_packet/xmlLoader.hpp>


int main()
{
	tools::XmlLoader	loader;

	loader.loadProject("../../ressource/xml/tools/generator_packet.xml");
	return 0;
}
