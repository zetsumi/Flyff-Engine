#pragma once

#if defined(FLYFFENGINE_EXPORTS)
# define API_DECLSPEC __declspec(dllexport)
#else
# define API_DECLSPEC __declspec(dllimport)
#endif

#define FLYFFENGINE_JSON_PICOJSON
#define FLYFFENGINE_XML_PUGIXML

namespace fe
{
    /**
     * @brief Redifinition des types pour le mode 32 64 bits de flyff-engine
     * 
     */
    namespace type
    {
        typedef unsigned __int64 _uint;
        typedef __int64          _int;
    }
}

