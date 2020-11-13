//
// Created by mcoll on 09/11/2020.
//
#include "tnpch.h"
#include "Sandbox2D.h"

#include <imgui.h>
#include <glm/gtc/type_ptr.hpp>

template<typename Fn>
class Timer {
public:
    explicit Timer(const char* name, Fn&& func)
        : m_Name(name), m_Stopped(false), m_Func(func) {
        m_StartTimePoint = std::chrono::high_resolution_clock::now();
    }

    void Stop() {
        auto endTimePoint = std::chrono::high_resolution_clock::now();

        long long start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimePoint).time_since_epoch().count();
        long long end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimePoint).time_since_epoch().count();

        m_Stopped = true;

        float duration = (end - start) * 0.001f;

        std::cout<< m_Name << ": " << duration << "ms" << std::endl;
        m_Func({m_Name, duration});
    }

    ~Timer() {
        if (!m_Stopped)
            Stop();
    }

private:
    const char* m_Name;
    Fn m_Func;
    std::chrono::time_point<std::chrono::steady_clock> m_StartTimePoint;
    bool m_Stopped;
};

#define PROFILE_SCOPE(name) Timer timer##__LINE__(name, [&](ProfileResult profileResult) { m_ProfileResults.push_back(profileResult); })

Sandbox2D::Sandbox2D()
    : Layer("Sandbox2D"), m_CameraController(1280.f / 720.f) {

}

void Sandbox2D::OnAttach() {
    m_CheckboardTexture = Tron::Texture2D::Create("assets/textures/Checkboard.png");
}

void Sandbox2D::OnDetach() {
    Layer::OnDetach();
}

void Sandbox2D::OnUpdate(Tron::Timestep ts) {

    PROFILE_SCOPE("Sandbox2D::OnUpdate");
    // Update
    {
        PROFILE_SCOPE("CameraController::OnUpdate");
        m_CameraController.OnUpdate(ts);
    }

    // Render
    {
        PROFILE_SCOPE("Renderer Prep");
        Tron::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
        Tron::RenderCommand::Clear();
    }

    {
        PROFILE_SCOPE("Renderer Draw");
        Tron::Renderer2D::BeginScene(m_CameraController.GetCamera());
        Tron::Renderer2D::DrawQuad({-1.0f, 0.0f}, {0.8f, 0.8f}, {0.8f, 0.2f, 0.3f, 1.0f});
        Tron::Renderer2D::DrawQuad({0.5f, -0.5f}, {0.5f, 0.75}, {0.2f, 0.3f, 0.8f, 1.0f});
        Tron::Renderer2D::DrawQuad({0.0f, 0.0f, -0.1f}, {10.0f, 10.0f}, m_CheckboardTexture);
        Tron::Renderer2D::EndScene();
    }

}

void Sandbox2D::OnImGuiRender() {
    ImGui::Begin("Settings");
    ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));

    for (auto& result : m_ProfileResults) {
        char label[50];
        strcpy_s(label, "%.3fms ");
        strcat_s(label, result.Name);

        ImGui::Text(label, result.Time);
    }
    m_ProfileResults.clear();

    ImGui::End();
}

void Sandbox2D::OnEvent(Tron::Event &e) {
    m_CameraController.OnEvent(e);
}

