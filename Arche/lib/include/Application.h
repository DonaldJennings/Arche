
#include <Core.h>
#include <memory>
#include <IEventListener.h>
#include <Logger.h>

#ifndef ARCHE_APPLICATION
#define ARCHE_APPLICATION

namespace Arche
{
	class LIB_API Application : public IEventListener
	{
	public:
		Application()
		{

		}

		~Application()
		{

		}

		void run();

		void onEvent() override
		{
			ARCHE_WARN("Event has been triggered");
		}
	};
}

#endif // !ARCHE_APPLICATION
