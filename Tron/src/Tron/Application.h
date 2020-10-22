#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace Tron {

	class TRON_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// Definido en el cliente
	Application* CreateApplication();
}


