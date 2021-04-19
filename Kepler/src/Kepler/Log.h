#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"

namespace Kepler
{
	class KEPLER_API Log
	{
	public:
		static void Init();
		static inline std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger;  }
		static inline std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger;  }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};
}

//++++ Core logging macros
#define KP_CORE_TRACE(...)	::Kepler::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define KP_CORE_INFO(...)	::Kepler::Log::GetCoreLogger()->info(__VA_ARGS__)
#define KP_CORE_WARN(...)	::Kepler::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define KP_CORE_ERROR(...)	::Kepler::Log::GetCoreLogger()->error(__VA_ARGS__)


//++++ Client logging macros
#define KP_TRACE(...)		::Kepler::Log::GetClientLogger()->trace(__VA_ARGS__)
#define KP_INFO(...)		::Kepler::Log::GetClientLogger()->info(__VA_ARGS__)
#define KP_WARN(...)		::Kepler::Log::GetClientLogger()->warn(__VA_ARGS__)
#define KP_ERROR(...)		::Kepler::Log::GetClientLogger()->error(__VA_ARGS__)
