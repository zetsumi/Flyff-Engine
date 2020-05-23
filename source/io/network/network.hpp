#pragma once

#include <framework_fengine.h>
#include <string>

namespace fe
{
	class API_DECLSPEC Network
	{
		std::string		ip{""};
		unsigned int	port = 0;

	public:
		Network() = default;
		~Network() = default;
		Network(const Network& n) = default;
		Network(Network* n) : Network(*n) {};

		bool	isValid(void) const;
		bool	setIP(const std::string& newIP);
		bool	setIP(const char* newIP);
		void	setPort(unsigned int newPort);
		const char* getIP(void) const { return ip.c_str(); }
		unsigned int getPort(void) const { return port; }
	};
}
