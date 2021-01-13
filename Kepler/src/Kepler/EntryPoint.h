#pragma once

#ifdef KP_PLATFORM_WIN

extern Kepler::Application* Kepler::CreateApplication();

int main(int argc, char *argv[])
{
	auto app = Kepler::CreateApplication();
	app->Run();
	delete app;

	return 0;
}

#endif