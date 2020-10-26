#pragma once

#include "Core.h"

#include "Window.h"
#include "Tron/LayerStack.h"
#include "Tron/Events/Event.h"
#include "Tron/Events/ApplicationEvent.h"

#include "Tron/ImGui/ImGuiLayer.h"

#include "Tron/Renderer/Shader.h";

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

		inline static Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);
	private:
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;

		unsigned int m_VertexArray, m_VertexBuffer, m_IndexBuffer;
		std::unique_ptr<Shader> m_Shader;
	private:
		static Application* s_Instance;
	};

	// Definido en el cliente
	Application* CreateApplication();
}


