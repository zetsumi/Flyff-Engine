#pragma once

#include "framework.h"

namespace fe
{
	/**
	 * @brief Les différents mode de fichier exploitable par Flyff-Engine
	 * 
	 */
	enum class LOADER_MODE : short
	{
		JSON,
		XML,
		CSV
	};
}