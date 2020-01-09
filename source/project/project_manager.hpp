#pragma once

#include "framework.h"
#include "property_manager.hpp"
#include "reader_header.hpp"


namespace fe
{
	enum class LOADER_MODE : short
	{
		JSON,
		XML
	};

	class API_DECLSPEC ProjectManager
	{
		ReaderHeader	header;
		PropertyManager	propitem;
		PropertyManager	propctrl;
		PropertyManager	propmover;
		PropertyManager	propkarma;
		PropertyManager	propskill;
		PropertyManager	propskilltroupe;

		bool	loadPropItemJson(const std::string& fileName) noexcept;

	public:
		ProjectManager();
		~ProjectManager();

		bool	loadHeader(const std::string& fileName) noexcept;
		bool	loadPropItem(const std::string& fileName, LOADER_MODE mode) noexcept;
	};
}