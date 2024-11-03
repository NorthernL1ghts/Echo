#pragma once

#include "Base.h"
#include "Log.h"
#include <filesystem>

#ifdef ECHO_ENABLE_ASSERTS
	// Alteratively we could use the same "default" message for both "WITH_MSG" and "NO_MSG" and
	// provide support for custom formatting by concatenating the formatting string instead of having the format inside the default message
	#define ECHO_INTERNAL_ASSERT_IMPL(type, check, msg, ...) { if(!(check)) { HZ##type##ERROR(msg, __VA_ARGS__); ECHO_DEBUGBREAK(); } }
	#define ECHO_INTERNAL_ASSERT_WITH_MSG(type, check, ...) ECHO_INTERNAL_ASSERT_IMPL(type, check, "Assertion failed: {0}", __VA_ARGS__)
	#define ECHO_INTERNAL_ASSERT_NO_MSG(type, check) ECHO_INTERNAL_ASSERT_IMPL(type, check, "Assertion '{0}' failed at {1}:{2}", ECHO_STRINGIFY_MACRO(check), std::filesystem::path(__FILE__).filename().string(), __LINE__)

	#define ECHO_INTERNAL_ASSERT_GET_MACRO_NAME(arg1, arg2, macro, ...) macro
	#define ECHO_INTERNAL_ASSERT_GET_MACRO(...) ECHO_EXPAND_MACRO( ECHO_INTERNAL_ASSERT_GET_MACRO_NAME(__VA_ARGS__, ECHO_INTERNAL_ASSERT_WITH_MSG, ECHO_INTERNAL_ASSERT_NO_MSG) )

	// Currently accepts at least the condition and one additional parameter (the message) being optional
	#define ECHO_ASSERT(...) ECHO_EXPAND_MACRO( ECHO_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_, __VA_ARGS__) )
	#define ECHO_CORE_ASSERT(...) ECHO_EXPAND_MACRO( ECHO_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_CORE_, __VA_ARGS__) )
#else
	#define ECHO_ASSERT(...)
	#define ECHO_CORE_ASSERT(...)
#endif