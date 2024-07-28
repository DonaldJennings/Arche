
#ifndef ARCHE_CORE
#define ARCHE_CORE

#if defined(_WIN32) || defined(_WIN64)
	#if defined(BUILD_SHARED_LIB)
		#define LIB_API __declspec(dllexport)
	#else
		#define LIB_API __declspec(dllimport)
	#endif
#else
	#define LIB_API
#endif

#endif // !ARCHE_CORE


// Define logging macros with ARCHE_ prefix
#define ARCHE_TRACE(...)    ::Arche::Logger::getLogger()->trace(__VA_ARGS__)
#define ARCHE_INFO(...)     ::Arche::Logger::getLogger()->info(__VA_ARGS__)
#define ARCHE_WARN(...)     ::Arche::Logger::getLogger()->warn(__VA_ARGS__)
#define ARCHE_ERROR(...)    ::Arche::Logger::getLogger()->error(__VA_ARGS__)

// Define event macros with ARCHE_ prefix
#define ARCHE_EVENT_ADD_LISTENER(listener) ::Arche::EventManager::getEventManager()->addListener(listener)
#define ARCHE_EVENT_REMOVE_LISTENER(listener) ::Arche::EventManager::getEventManager()->removeListener(listener)
#define ARCHE_EVENT_TRIGGER() ::Arche::EventManager::getEventManager()->triggerEvent()