#pragma once

#include "tnpch.h"
#include "Core.h"
#include "Events/Event.h"
#include "Tron/Events/ApplicationEvent.h"

#include "Window.h"

namespace Tron {

	class TRON_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);
	private:
		bool OnWindowClose(WindowCloseEvent& e);
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	// Definido en el cliente
	Application* CreateApplication();
}


