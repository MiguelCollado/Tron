//
// Created by mcoll on 09/11/2020.
//
#include "tnpch.h"
#include "Sandbox2D.h"

#include <imgui.h>
#include <glm/gtc/type_ptr.hpp>

Sandbox2D::Sandbox2D()
    : Layer("Sandbox2D"), m_CameraController(1280.f / 720.f), m_SquareColor({ 0.2f, 0.3f, 0.8f, 1.0f }) {

}

void Sandbox2D::OnAttach() {
    TN_PROFILE_FUNCTION();

//    m_CheckboardTexture = Tron::Texture2D::Create("assets/textures/Check.png");
}

void Sandbox2D::OnDetach() {
    TN_PROFILE_FUNCTION();

    Layer::OnDetach();
}

void Sandbox2D::OnUpdate(Tron::Timestep ts) {

    TN_PROFILE_FUNCTION();
    // Update
    m_CameraController.OnUpdate(ts);

    // Render
    Tron::Renderer2D::ResetStats();
    {
        TN_PROFILE_SCOPE("Renderer Prep");
        Tron::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
        Tron::RenderCommand::Clear();
    }

    {
        static float rotation = 0.0f;
        rotation += ts * 50.0f;

        TN_PROFILE_SCOPE("Renderer Draw");
        Tron::Renderer2D::BeginScene(m_CameraController.GetCamera());
        Tron::Renderer2D::DrawRotatedQuad({0.0f, 0.0f}, {0.8f, 0.8f}, rotation, {0.2f, 0.8f, 0.3f, 1.0f});
        Tron::Renderer2D::DrawQuad({-1.0f, 0.6f}, {0.8f, 0.8f}, {0.8f, 0.2f, 0.3f, 1.0f});
        Tron::Renderer2D::DrawQuad({ 1.0f, 0.0f}, {0.5f, 0.75}, m_SquareColor);
//        Tron::Renderer2D::DrawQuad({ 0.0f, 0.0f, -0.2f}, {20.0f, 20.0f}, m_CheckboardTexture, 5.f);
        Tron::Renderer2D::EndScene();

        Tron::Renderer2D::BeginScene(m_CameraController.GetCamera());
        for (int y = -10; y < 10; y++) {
            for (int x = -10; x < 10; x++) {
                glm::vec4 color = { ((float)x + 10.0f) / 20.0f, 0.3f, ((float)y + 10.0f) / 20.0f, 0.7f };
                Tron::Renderer2D::DrawQuad({x, y, -0.1f}, {0.9f, 0.9f}, color);
            }
        }
        Tron::Renderer2D::EndScene();

    }
}

void Sandbox2D::OnImGuiRender() {
    TN_PROFILE_FUNCTION();

    ImGui::Begin("Settings");

    auto stats = Tron::Renderer2D::GetStats();
    ImGui::Text("Renderer2D Stats:");
    ImGui::Text("Draw Calls: %d", stats.DrawCalls);
    ImGui::Text("Quad Count: %d", stats.QuadCount);
    ImGui::Text("Vertices Count: %d", stats.GetTotalVertexCount());
    ImGui::Text("Indices Count: %d", stats.GetTotalIndexCount());

    ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));
    ImGui::End();
}

void Sandbox2D::OnEvent(Tron::Event &e) {
    m_CameraController.OnEvent(e);
}

