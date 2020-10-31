#pragma once

#include "Core.h"

#include "Window.h"
#include "Tron/LayerStack.h"
#include "Tron/Events/Event.h"
#include "Tron/Events/ApplicationEvent.h"

#include "Tron/ImGui/ImGuiLayer.h"

#include "Tron/Renderer/Shader.h"
#include "Tron/Renderer/Buffer.h"
#include "Tron/Renderer/VertexArray.h"

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

		std::shared_ptr<Shader> m_Shader;
		std::shared_ptr<VertexArray> m_VertexArray;

		std::shared_ptr<Shader> m_BlueShader;
		std::shared_ptr<VertexArray> m_SquareVA;

	private:
		static Application* s_Instance;
	};

	// Definido en el cliente
	Application* CreateApplication();
}


