
#include <Application.h>
#include <iostream>
#include <Logger.h>

namespace Arche
{
	void Application::run()
	{
		Logger::init();

		ARCHE_INFO("Application is running");

		while (true);
	}
}