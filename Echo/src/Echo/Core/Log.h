#pragma once

#include <memory>

#include "spdlog/spdlog.h"

namespace Echo {

	class Log
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
#define ECHO_CORE_TRACE(...)    ::Echo::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define ECHO_CORE_INFO(...)     ::Echo::Log::GetCoreLogger()->info(__VA_ARGS__)
#define ECHO_CORE_WARN(...)     ::Echo::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define ECHO_CORE_ERROR(...)    ::Echo::Log::GetCoreLogger()->error(__VA_ARGS__)
#define ECHO_CORE_FATAL(...)    ::Echo::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define ECHO_TRACE(...)	        ::Echo::Log::GetClientLogger()->trace(__VA_ARGS__)
#define ECHO_INFO(...)			::Echo::Log::GetClientLogger()->info(__VA_ARGS__)
#define ECHO_WARN(...)			::Echo::Log::GetClientLogger()->warn(__VA_ARGS__)
#define ECHO_ERROR(...)			::Echo::Log::GetClientLogger()->error(__VA_ARGS__)
#define ECHO_FATAL(...)			::Echo::Log::GetClientLogger()->fatal(__VA_ARGS__)