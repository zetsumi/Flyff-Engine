#pragma once

#include <framework_fengine.h>

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