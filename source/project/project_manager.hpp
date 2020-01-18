#pragma once

#include "framework.h"
#include "property_manager.hpp"
#include "reader_header.hpp"
#include "reader_text.hpp"

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
		ReaderText		text;
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

		bool	loadJson(const std::string& fileName) noexcept;
		bool	loadXml(const std::string& fileName) noexcept;

	public:
		ProjectManager();
		~ProjectManager();

		bool	load(const std::string& fileName, LOADER_MODE mode) noexcept;

		bool	loadHeader(const std::string& fileName, LOADER_MODE mode) noexcept;
		bool	loadText(const std::string& fileName, LOADER_MODE mode, bool skippEmpty = false) noexcept;
		bool	loadPropItem(const std::string& fileName, LOADER_MODE mode) noexcept;
		bool	loadPropSkill(const std::string& fileName, LOADER_MODE mode) noexcept;
		bool	loadPropCtrl(const std::string& fileName, LOADER_MODE mode) noexcept;
		bool	loadPropKarma(const std::string& fileName, LOADER_MODE mode) noexcept;

		inline const ReaderHeader& getHeader() const noexcept
		{
			return std::ref(header);
		};
		inline const ReaderText& getText() const noexcept
		{
			return std::ref(text);
		};


		inline PropItem* getItem(fe::type::_uint id) noexcept
		{
			return dynamic_cast<PropItem*>(propitem.get(id));
		};
		inline PropSkill* getSkill(fe::type::_uint id) noexcept
		{
			return dynamic_cast<PropSkill*>(propskill.get(id));
		};
		inline PropCtrl* getCtrl(fe::type::_uint id) noexcept
		{
			return dynamic_cast<PropCtrl*>(propctrl.get(id));
		};
		inline PropKarma* getKarma(fe::type::_uint id) noexcept
		{
			return dynamic_cast<PropKarma*>(propkarma.get(id));
		};
		inline PropMover* getMover(fe::type::_uint id) noexcept
		{
			return dynamic_cast<PropMover*>(propmover.get(id));
		};
		inline PropSkill* getSkillTroupe(fe::type::_uint id) noexcept
		{
			return dynamic_cast<PropSkill*>(propskilltroupe.get(id));
		};

		inline PropItem* createItem(fe::type::_uint id) noexcept
		{
			PropItem* src = getItem(id);
			if (src == nullptr)
				return nullptr;
			PropItem* copy = new PropItem(src);
			return copy;
		}
		inline PropSkill* createSkill(fe::type::_uint id) noexcept
		{
			PropSkill* src = getSkill(id);
			if (src == nullptr)
				return nullptr;
			PropSkill* copy = new PropSkill(src);
			return copy;
		}
		inline PropCtrl* createCtrl(fe::type::_uint id) noexcept
		{
			PropCtrl* src = getCtrl(id);
			if (src == nullptr)
				return nullptr;
			PropCtrl* copy = new PropCtrl(src);
			return copy;
		}
		inline PropKarma* createKarma(fe::type::_uint id) noexcept
		{
			PropKarma* src = getKarma(id);
			if (src == nullptr)
				return nullptr;
			PropKarma* copy = new PropKarma(src);
			return copy;
		}
		inline PropMover* createMover(fe::type::_uint id) noexcept
		{
			PropMover* src = getMover(id);
			if (src == nullptr)
				return nullptr;
			PropMover* copy = new PropMover(src);
			return copy;
		}
		inline PropSkill* createSkillTroupe(fe::type::_uint id) noexcept
		{
			PropSkill* src = getSkillTroupe(id);
			if (src == nullptr)
				return nullptr;
			PropSkill* copy = new PropSkill(src);
			return copy;
		}
	};
}