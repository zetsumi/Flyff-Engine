#pragma once

#include <cstdint>


#if defined(_WIN64)
#include <WinSock2.h>
    #if defined(FLYFFENGINE_EXPORTS) || defined(FLYFFNETWORK_EXPORTS) || defined(FLYFFRESSOURCE_EXPORTS)
    # define API_DECLSPEC __declspec(dllexport)
    #else
    # define API_DECLSPEC __declspec(dllimport)
    #endif
#else
#include <inttypes.h>
# define API_DECLSPEC
#endif

// TODO : a definir directement dans la solution.
#define FLYFFENGINE_JSON_PICOJSON
#define FLYFFENGINE_XML_PUGIXML

#pragma warning( disable: 4251 )
namespace fe
{
    /**
     * @brief Redifinition des types pour le multi platform
     * 
     */
    namespace type
    {
#if defined(_WIN64)
        typedef SOCKET              _SOCKET;
#elif defined(__APPLE__)
        typedef int                 _SOCKET;
#endif // _WIN64
    }
}
#pragma warning( default: 4251 )
