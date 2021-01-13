#pragma once

#include "Core.h"

namespace Kepler
{
	class KEPLER_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};

	//++++ To be defined in client
	Application* CreateApplication();
}

