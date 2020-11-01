#pragma once

#include "Core.h"

#include "Window.h"
#include "Tron/LayerStack.h"
#include "Tron/Events/Event.h"
#include "Tron/Events/ApplicationEvent.h"
#include "Tron/Core/Timestep.h"

#include "Tron/ImGui/ImGuiLayer.h"

namespace Tron {

	class Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		inline static Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);
	private:
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;
		float m_LastFrameTime = 0.0f;
	private:
		static Application* s_Instance;
	};

	// Definido en el cliente
	Application* CreateApplication();
}


