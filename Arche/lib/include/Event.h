
# pragma once

#include "Core.h"
#include <string>
#include <memory>

namespace Arche
{
	enum class EventType
	{
		None = 0,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	// Function for turning an EventType into a string
	inline std::string eventTypeToString(EventType type)
	{
		switch (type)
		{
		case EventType::None: return "None";
		case EventType::KeyPressed: return "KeyPressed";
		case EventType::KeyReleased: return "KeyReleased";
		case EventType::MouseButtonPressed: return "MouseButtonPressed";
		case EventType::MouseButtonReleased: return "MouseButtonReleased";
		case EventType::MouseMoved: return "MouseMoved";
		case EventType::MouseScrolled: return "MouseScrolled";
		}

		return "Unknown";
	}

	enum EventCategory
	{
		None = 0,
		EventCategoryApplication = BIT(0),
		EventCategoryInput = BIT(1),
		EventCategoryKeyboard = BIT(2),
		EventCategoryMouse = BIT(3),
		EventCategoryMouseButton = BIT(4)
	};

	class Event
	{
		// Event has a type and a category
		// The type is the type of event that is being triggered
		// The category is the category of the event
		// The category is a bitfield that can be used to filter events
		// For example, if we want to filter out all events that are not input events, we can use the EventCategoryInput bitfield

	public:
		Event(EventType type, EventCategory category) : m_eventType(type), m_eventCategory(category) {}
		EventType getType() { return m_eventType; }
		EventCategory getCategory() { return m_eventCategory; }
		std::string toString() { eventTypeToString(m_eventType); };

	private:
		EventType m_eventType;
		EventCategory m_eventCategory;
	};
};
