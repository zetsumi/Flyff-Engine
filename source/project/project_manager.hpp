#pragma once

#include "framework.h"
#include "property_manager.hpp"
#include "reader_header.hpp"

#include "prop_item.hpp"
#include "prop_ctrl.hpp"
#include "prop_karma.hpp"
#include "prop_mover.hpp"
#include "prop_mover_ex.hpp"
#include "prop_skill.hpp"


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

		bool	loadPropItemXml(const std::string& fileName) noexcept;
		bool	loadPropCtrlXml(const std::string& fileName) noexcept;
		bool	loadPropKarmaXml(const std::string& fileName) noexcept;
		bool	loadPropSkillXml(const std::string& fileName) noexcept;


	public:
		ProjectManager();
		~ProjectManager();

		bool	loadHeader(const std::string& fileName, LOADER_MODE mode) noexcept;
		bool	loadPropItem(const std::string& fileName, LOADER_MODE mode) noexcept;
		bool	loadPropSkill(const std::string& fileName, LOADER_MODE mode) noexcept;
		bool	loadPropCtrl(const std::string& fileName, LOADER_MODE mode) noexcept;
		bool	loadPropKarma(const std::string& fileName, LOADER_MODE mode) noexcept;

		inline const ReaderHeader& getHeader() const noexcept
		{
			return std::ref(header);
		};

		inline PropItem* GetItem(fe::type::_uint id) noexcept
		{
			return dynamic_cast<PropItem*>(propitem.get(id));
		};
		inline PropSkill* GetSkill(fe::type::_uint id) noexcept
		{
			return dynamic_cast<PropSkill*>(propskill.get(id));
		};
		inline PropCtrl* GetCtrl(fe::type::_uint id) noexcept
		{
			return dynamic_cast<PropCtrl*>(propctrl.get(id));
		};
		inline PropKarma* GetKarma(fe::type::_uint id) noexcept
		{
			return dynamic_cast<PropKarma*>(propkarma.get(id));
		};
		inline PropMover* GetMover(fe::type::_uint id) noexcept
		{
			return dynamic_cast<PropMover*>(propmover.get(id));
		};
		inline PropSkill* GetSkillTroupe(fe::type::_uint id) noexcept
		{
			return dynamic_cast<PropSkill*>(propskilltroupe.get(id));
		};

		inline PropSkill* CreateSkill(fe::type::_uint id) noexcept
		{
			PropSkill* src = GetSkill(id);
			if (src == nullptr)
				return nullptr;
			PropSkill* copy = new PropSkill(src);
			return copy;
		}
	};
}