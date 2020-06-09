#pragma once

#include <framework_fengine.h>
#include <string>

namespace fe
{
#pragma warning( disable : 4251 )
	class API_DECLSPEC Network
	{
		std::string		ip{""};
		unsigned int	port = 0;

	public:
		Network() = default;
		~Network() = default;
		Network(const Network& n) = default;
		Network(Network* n) : Network(*n) {};

		bool	isValid() const;
		bool	setIP(const std::string& newIP);
		bool	setIP(const char* newIP);
		void	setPort(unsigned int newPort);
		const char* getIP() const { return ip.c_str(); }
		unsigned int getPort() const { return port; }
	};
#pragma warning( default : 4251 )
}
