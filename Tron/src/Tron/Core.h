#pragma once

#ifdef TN_PLATFORM_WINDOWS
#if TN_DYNAMIC_LINK
	#ifdef TN_BUILD_DLL
		#define TRON_API __declspec(dllexport)
	#else
		#define TRON_API __declspec(dllimport)
	#endif
#else
	#define TRON_API
#endif
#else
	#error Tron only supports Windows!
#endif

#ifdef TN_DEBUG
	#define TN_ENABLE_ASSERTS
#endif

#ifdef TN_ENABLE_ASSERTS
	#define TN_ASSERT(x, ...) { if(!(x)) { TN_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define TN_CORE_ASSERT(x, ...) { if(!(x)) { TN_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define TN_ASSERT(x, ...)
	#define TN_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define TN_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)