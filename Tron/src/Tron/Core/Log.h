#pragma once

#include "Tron/Core/Core.h"

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

namespace Tron {

	class Log
	{
	public:
		static void Init();

		inline static Ref<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static Ref<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static Ref<spdlog::logger> s_CoreLogger;
		static Ref<spdlog::logger> s_ClientLogger;
	};
}

// Core log macros
#define TN_CORE_TRACE(...)  ::Tron::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define TN_CORE_INFO(...)   ::Tron::Log::GetCoreLogger()->info(__VA_ARGS__)
#define TN_CORE_WARN(...)   ::Tron::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define TN_CORE_ERROR(...)  ::Tron::Log::GetCoreLogger()->error(__VA_ARGS__)
#define TN_CORE_FATAL(...)  ::Tron::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define TN_TRACE(...)  ::Tron::Log::GetClientLogger()->trace(__VA_ARGS__)
#define TN_INFO(...)   ::Tron::Log::GetClientLogger()->info(__VA_ARGS__)
#define TN_WARN(...)   ::Tron::Log::GetClientLogger()->warn(__VA_ARGS__)
#define TN_ERROR(...)  ::Tron::Log::GetClientLogger()->error(__VA_ARGS__)
#define TN_FATAL(...)  ::Tron::Log::GetClientLogger()->fatal(__VA_ARGS__)
