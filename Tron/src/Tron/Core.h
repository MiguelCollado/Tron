#pragma once

#ifdef TN_PLATFORM_WINDOWS
	#ifdef TN_BUILD_DLL
		#define TRON_API __declspec(dllexport)
	#else
		#define TRON_API __declspec(dllimport)
	#endif
#else
	#error Tron only supports Windows!
#endif

#define BIT(x) (1 << x)