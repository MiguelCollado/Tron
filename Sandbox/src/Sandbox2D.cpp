//
// Created by mcoll on 09/11/2020.
//
#include "tnpch.h"
#include "Sandbox2D.h"

#include <imgui.h>
#include <glm/gtc/type_ptr.hpp>

Sandbox2D::Sandbox2D()
    : Layer("Sandbox2D"), m_CameraController(1280.f / 720.f) {

}

void Sandbox2D::OnAttach() {
    TN_PROFILE_FUNCTION();

    m_CheckboardTexture = Tron::Texture2D::Create("assets/textures/Checkboard.png");
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
        Tron::Renderer2D::DrawQuad({1.0f, 0.0f}, {0.5f, 0.75}, {0.2f, 0.3f, 0.8f, 1.0f});
        Tron::Renderer2D::DrawQuad(glm::vec3(0.0f), {10.0f, 10.0f}, m_CheckboardTexture, 5.f);
        Tron::Renderer2D::DrawRotatedQuad({0.0f, -2.0f, 1.0f}, {1.0f, 1.0f}, 45.0f, m_CheckboardTexture, 5.f);
        Tron::Renderer2D::EndScene();
    }
}

void Sandbox2D::OnImGuiRender() {
    TN_PROFILE_FUNCTION();

    ImGui::Begin("Settings");
    ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));

    ImGui::End();
}

void Sandbox2D::OnEvent(Tron::Event &e) {
    m_CameraController.OnEvent(e);
}

