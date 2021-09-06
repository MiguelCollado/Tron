#pragma once

#include <memory>

#include "Tron/Core/PlatformDetection.h"

#ifdef TN_DEBUG
#if defined(TN_PLATFORM_WINDOWS)
		#define TN_DEBUGBREAK() __debugbreak()
	#elif defined(TN_PLATFORM_LINUX)
		#include <signal.h>
		#define TN_DEBUGBREAK() raise(SIGTRAP)
	#else
		#error "Platform doesn't support debugbreak yet!"
	#endif
	#define TN_ENABLE_ASSERTS
#else
    #define TN_DEBUGBREAK()
#endif

#ifdef TN_ENABLE_ASSERTS
    #define TN_ASSERT(x, ...) { if(!(x)) { TN_ERROR("Assertion Failed: {0}", __VA_ARGS__); TN_DEBUGBREAK(); } }
    #define TN_CORE_ASSERT(x, ...) { if(!(x)) { TN_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); TN_DEBUGBREAK(); } }
#else
	#define TN_ASSERT(x, ...)
	#define TN_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define TN_BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }

namespace Tron {

	template<typename T>
	using Scope = std::unique_ptr<T>;

    template<typename T, typename ... Args>
    constexpr Scope<T> CreateScope(Args&& ... args)
    {
        return std::make_unique<T>(std::forward<Args>(args)...);
    }

	template<typename T>
	using Ref = std::shared_ptr<T>;

    template<typename T, typename ... Args>
    constexpr Ref<T> CreateRef(Args&& ... args)
    {
        return std::make_shared<T>(std::forward<Args>(args)...);
    }

}