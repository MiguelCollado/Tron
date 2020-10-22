#pragma once

#include "tnpch.h"
#include "Core.h"

#include "Events/Event.h"
#include "Window.h"

namespace Tron {

	class TRON_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	// Definido en el cliente
	Application* CreateApplication();
}


