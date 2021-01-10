#pragma once

#include "Tron/Core/Base.h"

#include "Tron/Core/Window.h"
#include "Tron/Core/LayerStack.h"
#include "Tron/Events/Event.h"
#include "Tron/Events/ApplicationEvent.h"
#include "Tron/Core/Timestep.h"

#include "Tron/ImGui/ImGuiLayer.h"

int main(int argc, char** argv);

namespace Tron {
	class Application
	{
	public:
		Application(const std::string& name = "Tron App");
		virtual ~Application();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		Window& GetWindow() { return *m_Window; }
		void Close();

		ImGuiLayer* GetImGuiLayer() {return m_ImGuiLayer;}

		static Application& Get() { return *s_Instance; }
	private:
        void Run();
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);
	private:
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;

		bool m_Running = true;
		bool m_Minimized = false;

		LayerStack m_LayerStack;
		float m_LastFrameTime = 0.0f;
	private:
		static Application* s_Instance;
        friend int ::main(int argc, char** argv);
	};

	// Definido en el cliente
	Application* CreateApplication();
}


