#pragma once

#include "Core.h"
#include <memory>
#include <IEventListener.h>

#include <vector>

namespace Arche
{
	class EventManager
	{
	public:
		static void init();
		void addListener(std::shared_ptr<IEventListener> listener);
		void removeListener(std::shared_ptr<IEventListener> listener);
		void triggerEvent();
		static std::shared_ptr<EventManager>& getEventManager();

	private:
		static std::shared_ptr<EventManager> s_eventManager;

		std::vector<std::shared_ptr<IEventListener>> m_listeners;
	};
}