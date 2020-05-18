#pragma once

#include <Windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include <cstdarg>

namespace fe
{
	inline static void _log(bool console, const char* functionName, const char* format, ...)
	{
		try
		{
			if (functionName == nullptr || format == nullptr)
				return;
			auto temp = std::vector<char>{};
			auto length = std::size_t{ 1024 };
			std::va_list args;
			while (temp.size() <= length)
			{
				temp.resize(length + 1);
				va_start(args, format);
				const auto status = std::vsnprintf(temp.data(), temp.size(), format, args);
				va_end(args);
				if (status < 0)
					throw std::runtime_error{ "string formatting error" };
				length = static_cast<std::size_t>(status);
			}

			// Ajout de prefix au message
			std::string message;
			message.append(functionName);
			message.append(": ");
			message.append(std::string{ temp.data(), length });
			message.append("\n");

			if (console == true)
				::OutputDebugStringA(message.c_str());
			else
				std::cout << message << std::endl;
		}
		catch (const std::exception&)
		{
		}
	}
}


#if defined(_DEBUG)
#define FE_LOG(format, ...)			fe::_log(true, __FUNCTION__, format, __VA_ARGS__)
#define FE_CONSOLELOG(format, ...)	fe::_log(true, __FUNCTION__, format, __VA_ARGS__)
#else
#define FE_CONSOLELOG(format, ...)	fe::_log(true, __FUNCTION__, format, __VA_ARGS__)
#define FE_LOG(format, ...)			fe::_log(false, __FUNCTION__, format, __VA_ARGS__)
#endif //_DEBUG