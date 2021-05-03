#pragma once

#ifdef KP_PLATFORM_WIN

extern Kepler::Application* Kepler::CreateApplication();

int main(int argc, char *argv[])
{
	Kepler::Log::Init();
	KP_CORE_WARN("Initialized Log!");
	KP_INFO("Hello!");

	auto app = Kepler::CreateApplication();
	app->Run();

	delete app;

	return 0;
}

#endif