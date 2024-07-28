
#include <Application.h>
#include <iostream>
#include <Logger.h>
#include <EventManager.h>

namespace Arche
{
	void Application::run()
	{
		Arche::Logger::init();
		EventManager::init();

		// Add the application as a listener
		EventManager::getEventManager()->addListener(std::shared_ptr<IEventListener>(this));
		ARCHE_INFO("Application is running");


		// Emit an event asynchonously every 2 seconds
		do
		{
			EventManager::getEventManager()->triggerEvent();
			std::this_thread::sleep_for(std::chrono::seconds(2));
		}

		while (true);
	}
}