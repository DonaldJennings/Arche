#pragma once

#include <Core.h>
#include <Logger.h>

#include <memory>
#include <Event.h>
#include <IEventListener.h>
#include <unordered_map>
#include <vector>

namespace Arche
{
	class EventManager
	{
	public:
		static void init();
		void addListener(EventType, std::shared_ptr<IEventListener> listener);
		void removeListener(EventType, std::shared_ptr<IEventListener> listener);
		void triggerEvent(Event event);
		static std::shared_ptr<EventManager>& getEventManager();

	private:
		static std::shared_ptr<EventManager> s_eventManager;
		std::unordered_map<EventType, std::vector<std::shared_ptr<IEventListener>>> m_listeners;
	};
}