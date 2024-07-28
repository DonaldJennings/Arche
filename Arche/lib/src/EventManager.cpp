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

	void EventManager::addListener(std::shared_ptr<IEventListener> listener)
	{
		m_listeners.push_back(listener);
	}

	void EventManager::removeListener(std::shared_ptr<IEventListener> listener)
	{
		auto it = std::find(m_listeners.begin(), m_listeners.end(), listener);
		if (it != m_listeners.end())
		{
			m_listeners.erase(it);
		}
	}

	void EventManager::triggerEvent()
	{
		for (auto& listener : m_listeners)
		{
			listener->onEvent();
		}
	}

	std::shared_ptr<EventManager>& EventManager::getEventManager()
	{
		return s_eventManager;
	}
}