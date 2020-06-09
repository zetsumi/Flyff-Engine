#include <pch_fnetwork.h>
#include "Network.hpp"


bool fe::Network::isValid() const
{
	if (ip.empty() == true)
		return false;
	if (port == 0)
		return false;
	return true;
}

bool fe::Network::setIP(const std::string& newIP)
{
	if (newIP.empty() == true)
		return false;
	ip.assign(newIP);
	return true;
}

bool fe::Network::setIP(const char* newIP)
{
	if (newIP == nullptr)
		return false;
	ip = newIP;
	return true;
}

void fe::Network::setPort(unsigned int newPort)
{
	port = newPort;
}