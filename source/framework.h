#pragma once

#if defined(_USRDLL)
# define API_DECLSPEC __declspec(dllexport)
#else
# define API_DECLSPEC __declspec(dllimport)
#endif
