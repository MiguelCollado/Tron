#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Tron {

	class TRON_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
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
