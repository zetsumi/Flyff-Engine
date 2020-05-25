#pragma once

#if defined(FLYFFENGINE_EXPORTS) || defined(FLYFFNETWORK_EXPORTS) || defined(FLYFFRESSOURCE_EXPORTS)
# define API_DECLSPEC __declspec(dllexport)
# elif defined(FLYFFENGINE_IMPORT_COMPIL) || defined(FLYFFNETWORK_IMPORT_COMPIL) || defined(FLYFFRESSOURCE_IMPORT_COMPIL)
#define API_DECLSPEC
#else
# define API_DECLSPEC __declspec(dllimport)
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
#else defined(_WIN32)
        typedef unsigned __int64    _uint;
        typedef __int64             _int;
        typedef unsigned __int32    _32uint;
        typedef __int32             _32int;
        typedef unsigned char       _uchar;
#endif // _WIN64
    }
}
#pragma warning( default: 4251 )
