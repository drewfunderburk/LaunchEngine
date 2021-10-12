#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Launch
{
	class LAUNCH_API Log
	{
	public:
		Log();
		~Log();

		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log macros
#define LN_CORE_PRINT(...) printf(__VA_ARGS__);
#define LN_CORE_TRACE(...) ::Launch::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define LN_CORE_INFO(...) ::Launch::Log::GetCoreLogger()->info(__VA_ARGS__)
#define LN_CORE_WARN(...) ::Launch::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define LN_CORE_ERROR(...) ::Launch::Log::GetCoreLogger()->error(__VA_ARGS__)
#define LN_CORE_FATAL(...) ::Launch::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define LN_TRACE(...) ::Launch::Log::GetClientLogger()->trace(__VA_ARGS__)
#define LN_INFO(...) ::Launch::Log::GetClientLogger()->info(__VA_ARGS__)
#define LN_WARN(...) ::Launch::Log::GetClientLogger()->warn(__VA_ARGS__)
#define LN_ERROR(...) ::Launch::Log::GetClientLogger()->error(__VA_ARGS__)
#define LN_FATAL(...) ::Launch::Log::GetClientLogger()->fatal(__VA_ARGS__)