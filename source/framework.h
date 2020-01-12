#pragma once

#if defined(FLYFFENGINE_EXPORTS)
# define API_DECLSPEC __declspec(dllexport)
#else
# define API_DECLSPEC __declspec(dllimport)
#endif

#define FLYFFENGINE_JSON_PICOJSON

namespace fe
{
    namespace type
    {
        typedef unsigned __int64 _uint;
        typedef __int64          _int;
    }
}

