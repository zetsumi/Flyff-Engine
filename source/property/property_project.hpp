#pragma once

#include <unordered_map>
#include "framework.h"
#include "property_manager.hpp"

namespace fe
{
	enum class PROPERTY_TYPE : unsigned __int64
	{
		PropItem
	};
	class API_DECLSPEC PropertyProject
	{
		std::unordered_map<PROPERTY_TYPE, PropertyManager*>	managers;
	public:
		PropertyProject();
		~PropertyProject();


		void	push(PROPERTY_TYPE typeProperty, PropertyManager* manager) noexcept;
		PropertyManager* get(PROPERTY_TYPE typeProperty) noexcept;
		fe::PropertyContainer* get(PROPERTY_TYPE typeProperty, unsigned __int64 id) noexcept;
		template<class C>
		C get(PROPERTY_TYPE typeProperty, unsigned __int64 id) noexcept
		{
			fe::PropertyContainer* container = get(id);
			if (container == nullptr)
				return nullptr;
			return dynamic_cast<C>(container);
		}

	private:

	};
}