#pragma once

#ifdef KP_PLATFORM_WIN
#ifdef KP_BUILD_DLL
#define KEPLER_API __declspec(dllexport)
#else
#define KEPLER_API __declspec(dllimport)
#endif
#else
#error Kepler only supports Widows!
#endif