
#include "Application.h"

#ifndef SANDOX_APPLICATION
#define SANDBOX_APPLICATION

class Sandbox : public Arche::Application
{
public:
	Sandbox()
	{
	}

	~Sandbox()
	{
	}

};

int main()
{
	std::unique_ptr<Sandbox> sandbox = std::make_unique<Sandbox>();
	sandbox->run();
	return 0;
}

#endif // !SANDOX_APPLICATION
