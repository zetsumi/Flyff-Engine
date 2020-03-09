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
	/**
	 * @brief Objet manupilant le projet de manière général
	 * Object permettant de stocker l'ensemble des PropertyManager.
	 * Permet d'avoir en son sein les fichier de configuration / traduction / header
	 * Permet le chargement des fichier JSON ou XML
	 * 
	 */
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

		/*************************/
		/*		LOADER JSON		 */
		/*************************/

		/**
		 * @brief Charge les propriétes des ITEM
		 * Format du fichier d'entrée JSON
		 * 
		 * @param fileName Nom du fichier stockant les propriétés
		 * @return true 
		 * @return false 
		 */
		bool	loadPropItemJson(const std::string& fileName) noexcept;
		/**
		 * @brief Charge les propriétes des SKILL
		 * Format du fichier d'entrée JSON
		 * 
		 * @param fileName Nom du fichier stockant les propriétés
		 * @return true 
		 * @return false 
		 */
		bool	loadPropSkillJson(const std::string& fileName) noexcept;
		/**
		 * @brief Charge les propriétes des CONTROLERS
		 * Format du fichier d'entrée JSON
		 * 
		 * @param fileName Nom du fichier stockant les propriétés
		 * @return true 
		 * @return false 
		 */
		bool	loadPropCtrlJson(const std::string& fileName) noexcept;
		/**
		 * @brief Charge les propriétes du KARMA
		 * Format du fichier d'entrée JSON
		 * 
		 * @param fileName Nom du fichier stockant les propriétés
		 * @return true 
		 * @return false 
		 */
		bool	loadPropKarmaJson(const std::string& fileName) noexcept;

		/************************/
		/*		LOADER XML		*/
		/************************/

		/**
		 * @brief Charge les propriétes des ITEM
		 * Format du fichier d'entrée XML
		 * 
		 * @param fileName Nom du fichier stockant les propriétés
		 * @return true 
		 * @return false 
		 */
		bool	loadPropItemXml(const std::string& fileName) noexcept;
		/**
		 * @brief Charge les propriétes des CONTROLERS
		 * Format du fichier d'entrée JSON
		 * 
		 * @param fileName Nom du fichier stockant les propriétés
		 * @return true 
		 * @return false 
		 */
		bool	loadPropCtrlXml(const std::string& fileName) noexcept;
		/**
		 * @brief Charge les propriétes du KARMA
		 * Format du fichier d'entrée JSON
		 * 
		 * @param fileName Nom du fichier stockant les propriétés
		 * @return true 
		 * @return false 
		 */		
		bool	loadPropKarmaXml(const std::string& fileName) noexcept;
		/**
		 * @brief Charge les propriétes des SKILLS
		 * Format du fichier d'entrée JSON
		 * 
		 * @param fileName Nom du fichier stockant les propriétés
		 * @return true 
		 * @return false 
		 */
		bool	loadPropSkillXml(const std::string& fileName) noexcept;


		/********************/
		/*		LOADER		*/
		/********************/

		/**
		 * @brief Récupère les valeurs contenue dans le fichier au format JSON
		 * 
		 * @param fileName Nom du fichier a charger
		 * @return true 
		 * @return false 
		 */
		bool	loadJson(const std::string& fileName) noexcept;
		/**
		 * @brief Récupère les valeurs contenue dans le fichier au format XML
		 * 
		 * @param fileName Nom du fichier a charger
		 * @return true 
		 * @return false 
		 */
		bool	loadXml(const std::string& fileName) noexcept;

	public:
		ProjectManager();
		~ProjectManager();

		/**
		 * @brief Charge le fichier en fonction du mode sélectionner
		 * 
		 * @param fileName nom du fichier
		 * @param mode LOADER_MODE (XML ou JSON)
		 * @return true 
		 * @return false 
		 */
		bool	load(const std::string& fileName, LOADER_MODE mode) noexcept;

		/**
		 * @brief Charge les HEADERS en fonction format sélectionner
		 * 
		 * @param fileName nom du fichier
		 * @param mode LOADER_MODE (XML ou JSON)
		 * @return true 
		 * @return false 
		 */
		bool	loadHeader(const std::string& fileName, LOADER_MODE mode) noexcept;
		/**
		 * @brief Charge les TEXTS en fonction format sélectionner
		 * 
		 * @param fileName nom du fichier
		 * @param mode LOADER_MODE (XML ou JSON)
		 * @return true 
		 * @return false 
		 */
		bool	loadText(const std::string& fileName, LOADER_MODE mode, bool skippEmpty = false) noexcept;
		/**
		 * @brief Charge les ITEMS en fonction format sélectionner
		 * 
		 * @param fileName nom du fichier
		 * @param mode LOADER_MODE (XML ou JSON)
		 * @return true 
		 * @return false 
		 */
		bool	loadPropItem(const std::string& fileName, LOADER_MODE mode) noexcept;
		/**
		 * @brief Charge les SKILLS en fonction format sélectionner
		 * 
		 * @param fileName nom du fichier
		 * @param mode LOADER_MODE (XML ou JSON)
		 * @return true 
		 * @return false 
		 */
		bool	loadPropSkill(const std::string& fileName, LOADER_MODE mode) noexcept;
		/**
		 * @brief Charge les CONTROLERS en fonction format sélectionner
		 * 
		 * @param fileName nom du fichier
		 * @param mode LOADER_MODE (XML ou JSON)
		 * @return true 
		 * @return false 
		 */
		bool	loadPropCtrl(const std::string& fileName, LOADER_MODE mode) noexcept;
		/**
		 * @brief Charge les KARMA en fonction format sélectionner
		 * 
		 * @param fileName nom du fichier
		 * @param mode LOADER_MODE (XML ou JSON)
		 * @return true 
		 * @return false 
		 */
		bool	loadPropKarma(const std::string& fileName, LOADER_MODE mode) noexcept;

		/**
		 * @brief Retourne un object permettant la lecture des fichier HEADER
		 * 
		 * @return const ReaderHeader& 
		 */
		inline const ReaderHeader& getHeader() const noexcept
		{
			return std::ref(header);
		};
		/**
		 * @brief Retourne un object permettant la lecture des fichiers TEXT
		 * 
		 * @return const ReaderText&
		 */
		inline const ReaderText& getText() const noexcept
		{
			return std::ref(text);
		};


		/**
		 * @brief Get the Item object
		 * 
		 * @param id 
		 * @return PropItem* 
		 */
		inline PropItem* getItem(fe::type::_uint id) noexcept
		{
			return dynamic_cast<PropItem*>(propitem.get(id));
		};
		/**
		 * @brief Get the Skill object
		 * 
		 * @param id 
		 * @return PropSkill* 
		 */
		inline PropSkill* getSkill(fe::type::_uint id) noexcept
		{
			return dynamic_cast<PropSkill*>(propskill.get(id));
		};
		/**
		 * @brief Get the Ctrl object
		 * 
		 * @param id 
		 * @return PropCtrl* 
		 */
		inline PropCtrl* getCtrl(fe::type::_uint id) noexcept
		{
			return dynamic_cast<PropCtrl*>(propctrl.get(id));
		};
		/**
		 * @brief Get the Karma object
		 * 
		 * @param id 
		 * @return PropKarma* 
		 */
		inline PropKarma* getKarma(fe::type::_uint id) noexcept
		{
			return dynamic_cast<PropKarma*>(propkarma.get(id));
		};
		/**
		 * @brief Get the Mover object
		 * 
		 * @param id 
		 * @return PropMover* 
		 */
		inline PropMover* getMover(fe::type::_uint id) noexcept
		{
			return dynamic_cast<PropMover*>(propmover.get(id));
		};
		/**
		 * @brief Get the Skill Troupe object
		 * 
		 * @param id 
		 * @return PropSkill* 
		 */
		inline PropSkill* getSkillTroupe(fe::type::_uint id) noexcept
		{
			return dynamic_cast<PropSkill*>(propskilltroupe.get(id));
		};

		/****************************/
		/*		PATTERN FACTORY		*/
		/****************************/

		/**
		 * @brief Create a Item object
		 * 
		 * @param id 
		 * @return PropItem* 
		 */
		inline PropItem* createItem(fe::type::_uint id) noexcept
		{
			PropItem* src = getItem(id);
			if (src == nullptr)
				return nullptr;
			PropItem* copy = new PropItem(src);
			return copy;
		}
		/**
		 * @brief Create a Skill object
		 * 
		 * @param id 
		 * @return PropSkill* 
		 */
		inline PropSkill* createSkill(fe::type::_uint id) noexcept
		{
			PropSkill* src = getSkill(id);
			if (src == nullptr)
				return nullptr;
			PropSkill* copy = new PropSkill(src);
			return copy;
		}
		/**
		 * @brief Create a Ctrl object
		 * 
		 * @param id 
		 * @return PropCtrl* 
		 */
		inline PropCtrl* createCtrl(fe::type::_uint id) noexcept
		{
			PropCtrl* src = getCtrl(id);
			if (src == nullptr)
				return nullptr;
			PropCtrl* copy = new PropCtrl(src);
			return copy;
		}
		/**
		 * @brief Create a Karma object
		 * 
		 * @param id 
		 * @return PropKarma* 
		 */
		inline PropKarma* createKarma(fe::type::_uint id) noexcept
		{
			PropKarma* src = getKarma(id);
			if (src == nullptr)
				return nullptr;
			PropKarma* copy = new PropKarma(src);
			return copy;
		}
		/**
		 * @brief Create a Mover object
		 * 
		 * @param id 
		 * @return PropMover* 
		 */
		inline PropMover* createMover(fe::type::_uint id) noexcept
		{
			PropMover* src = getMover(id);
			if (src == nullptr)
				return nullptr;
			PropMover* copy = new PropMover(src);
			return copy;
		}
		/**
		 * @brief Create a Skill Troupe object
		 * 
		 * @param id 
		 * @return PropSkill* 
		 */
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