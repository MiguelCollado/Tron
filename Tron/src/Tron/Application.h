#pragma once

#include "Core.h"

#include "Window.h"
#include "Tron/LayerStack.h"
#include "Tron/Events/Event.h"
#include "Tron/Events/ApplicationEvent.h"


namespace Tron {

	class TRON_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
	private:
		bool OnWindowClose(WindowCloseEvent& e);
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	// Definido en el cliente
	Application* CreateApplication();
}


