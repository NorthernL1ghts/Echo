#pragma once

#include "../Core/PlatformDetection.h"

#include <memory>

#ifdef ECHO_DEBUG
	#if defined(ECHO_PLATFORM_WINDOWS)
		#define ECHO_DEBUGBREAK() __debugbreak()
#elif defined(ECHO_PLATFORM_LINUX)
#include <signal.h>
	#define ECHO_DEBUGBREAK() raise(SIGTRAP)
#else
	#error "Platform doesn't support debugbreak yet!"
#endif
	#define ECHO_ENABLE_ASSERTS
#else
	#define ECHO_DEBUGBREAK()
#endif

#define ECHO_EXPAND_MACRO(x) x
#define ECHO_STRINGIFY_MACRO(x) #x

#define BIT(x) (1 << x)

#define ECHO_BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }

namespace Echo {
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

#include "../Core/Log.h"
#include "../Core/Assert.h"