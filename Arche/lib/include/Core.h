
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
