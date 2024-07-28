#pragma once

#include <string>
#include "Event.h"

namespace Arche
{
	class ApplicationEvent : public Event
	{
	public:
		ApplicationEvent(EventType type, EventCategory category) : Event(type, category) {}
		std::string toString() override { return "Application Event" };
	};
}
