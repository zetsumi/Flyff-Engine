#include <iostream>
#include <tools/generator_packet/xmlLoader.hpp>


int main()
{
	tools::XmlLoader loader;

	if (false == loader.loadProject("packets/generator_packet.xml"))
	{
		return 1;
	}
	return 0;
}
