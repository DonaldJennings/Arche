#include "EventManager.h"

namespace Arche
{
	std::shared_ptr<EventManager> EventManager::s_eventManager = nullptr;

	void EventManager::init()
	{
		if (s_eventManager == nullptr)
		{
			s_eventManager = std::make_shared<EventManager>();
		}
	}

	void EventManager::addListener(EventType type, std::shared_ptr<IEventListener> listener)
	{
		// If the event type does not exist in the map, add it
		if (m_listeners.find(type) == m_listeners.end())
		{
			m_listeners[type] = { listener };
		} 
		m_listeners.find(type)->second.push_back(listener);

		ARCHE_TRACE("Listener added");
	}

	void EventManager::removeListener(EventType type, std::shared_ptr<IEventListener> listener)
	{
		return;
	}

	void EventManager::triggerEvent(Event event)
	{
		auto listeners = m_listeners.find(event.getType());
		if (listeners != m_listeners.end())
		{
			for (auto listener : listeners->second)
			{
				listener->onEvent();
			}
		}
	}

	std::shared_ptr<EventManager>& EventManager::getEventManager()
	{
		return s_eventManager;
	}
}