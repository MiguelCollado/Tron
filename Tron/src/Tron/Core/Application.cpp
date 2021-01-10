#include "tnpch.h"
#include "Tron/Core/Application.h"

#include "Tron/Core/Log.h"

#include "Tron/Renderer/Renderer.h"

#include "Tron/Core/Input.h"

#include <GLFW/glfw3.h>

namespace Tron {

	Application* Application::s_Instance = nullptr;

	Application::Application(const std::string& name)
	{
        TN_PROFILE_FUNCTION();

        TN_CORE_ASSERT(!s_Instance, "Application already exists!");
		s_Instance = this;

        {
            TN_PROFILE_SCOPE("Window -> Create");

            m_Window = Window::Create(WindowProps(name));
            m_Window->SetEventCallback(TN_BIND_EVENT_FN(Application::OnEvent));
        }

        {
            TN_PROFILE_SCOPE("glfwCreateWindow");
            Renderer::Init();
        }

		m_ImGuiLayer = new ImGuiLayer();
		PushOverlay(m_ImGuiLayer);
	}

	Application::~Application()	{
        TN_PROFILE_FUNCTION();

        Renderer::Shutdown();
	}

	void Application::OnEvent(Event& e) {
        TN_PROFILE_FUNCTION();

        EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(TN_BIND_EVENT_FN(Application::OnWindowClose));
		dispatcher.Dispatch<WindowResizeEvent>(TN_BIND_EVENT_FN(Application::OnWindowResize));

        for (auto it = m_LayerStack.rbegin(); it != m_LayerStack.rend(); ++it) {
			if (e.Handled)
				break;

            (*it)->OnEvent(e);
		}
	}

	void Application::PushLayer(Layer* layer)
	{
        TN_PROFILE_FUNCTION();

        m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* overlay)
	{
        TN_PROFILE_FUNCTION();

        m_LayerStack.PushOverlay(overlay);
		overlay->OnAttach();
	}

	void Application::Close() {
	    m_Running = false;
	}

	void Application::Run() {
        TN_PROFILE_FUNCTION();

        while (m_Running) {
            TN_PROFILE_SCOPE("Application -> Run Loop");

			auto time = (float) glfwGetTime(); // Platform::GetTime()
			Timestep ts = time - m_LastFrameTime;
			m_LastFrameTime = time;

			if (!m_Minimized)  {
                {
                    TN_PROFILE_SCOPE("LayerStack -> OnUpdate");

                    for (Layer* layer : m_LayerStack)
                        layer->OnUpdate(ts);
                }

                m_ImGuiLayer->Begin();
                {
                    TN_PROFILE_SCOPE("LayerStack -> OnImGuiRender");

                    for (Layer* layer : m_LayerStack)
                        layer->OnImGuiRender();
                }
                m_ImGuiLayer->End();
			}
			m_Window->OnUpdate();
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e) {
		m_Running = false;
		return true;
	}

    bool Application::OnWindowResize(WindowResizeEvent &e) {
        TN_PROFILE_FUNCTION();

        if (e.GetWidth() == 0 || e.GetHeight() == 0) {
            m_Minimized = true;
            return false;
        }

        TN_CORE_TRACE("{0}", e);

        m_Minimized = false;
        Renderer::OnWindowResize(e.GetWidth(), e.GetHeight());

        return false;
    }


}


