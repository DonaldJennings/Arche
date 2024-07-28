#pragma once

namespace Arche
{
	class IEventListener
	{
	public:
		virtual void onEvent() = 0;
	};
}