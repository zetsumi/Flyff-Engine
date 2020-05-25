#if defined(_WIN64)
#pragma once
#else

#ifndef __FRAMEWORK_FLYFF_ENGINE_HPP__
#define __FRAMEWORK_FLYFF_ENGINE_HPP__

#endif

#include <inttypes.h>

#if defined(_WIN64)
    #if defined(FLYFFENGINE_EXPORTS) || defined(FLYFFNETWORK_EXPORTS) || defined(FLYFFRESSOURCE_EXPORTS)
    # define API_DECLSPEC __declspec(dllexport)
    #else
    # define API_DECLSPEC __declspec(dllimport)
    #endif
#else
    # define API_DECLSPEC
#endif

// TODO : a definir directement dans la solution.
#define FLYFFENGINE_JSON_PICOJSON
#define FLYFFENGINE_XML_PUGIXML

#pragma warning( disable: 4251 )
namespace fe
{
    /**
     * @brief Redifinition des types pour le mode 32 64 bits de flyff-engine
     * 
     */
    namespace type
    {
#if defined(_WIN64)
        typedef unsigned __int64    _uint;
        typedef __int64             _int;
        typedef unsigned __int32    _32uint;
        typedef __int32             _32int;
        typedef unsigned char       _uchar;
#else defined(__linux__) || defined(__unix__)
        typedef uint64_t    _uint;
        typedef int32_t             _int;
        typedef uint32_t    _32uint;
        typedef int32_t             _32int;
        typedef unsigned char       _uchar;
#endif // _WIN64
    }
}
#pragma warning( default: 4251 )

#endif //__FRAMEWORK_FLYFF_ENGINE_HPP__
