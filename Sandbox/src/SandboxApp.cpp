#include <Kepler.h>

class Sandbox : public Kepler::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Kepler::Application* Kepler::CreateApplication()
{
	return new Sandbox();
}