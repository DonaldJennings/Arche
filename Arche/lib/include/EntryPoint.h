
#include <Core.h>
#include <memory>

#include "Application.h"

#ifndef ARCHE_ENTRY_POINT
#define ARCHE_ENTRY_POINT

extern std::unique_ptr<Arche::Application> createApplication();

#endif // !ARCHE_ENTRY_POINT
