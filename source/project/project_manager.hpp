#pragma once

#include "framework.h"
#include "property_manager.hpp"
#include "reader_header.hpp"


namespace fe
{
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
		bool	loadPropSkillJson(const std::string& fileName) noexcept;
		bool	loadPropCtrlJson(const std::string& fileName) noexcept;
		bool	loadPropKarmaJson(const std::string& fileName) noexcept;

		bool	loadPropCtrlXml(const std::string& fileName) noexcept;
		bool	loadPropKarmaXml(const std::string& fileName) noexcept;


	public:
		ProjectManager();
		~ProjectManager();

		bool	loadHeader(const std::string& fileName, LOADER_MODE mode) noexcept;
		bool	loadPropItem(const std::string& fileName, LOADER_MODE mode) noexcept;
		bool	loadPropSkill(const std::string& fileName, LOADER_MODE mode) noexcept;
		bool	loadPropCtrl(const std::string& fileName, LOADER_MODE mode) noexcept;
		bool	loadPropKarma(const std::string& fileName, LOADER_MODE mode) noexcept;
		const ReaderHeader& getHeader() const;
	};
}