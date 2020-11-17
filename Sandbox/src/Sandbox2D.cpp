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
    Tron::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
    Tron::RenderCommand::Clear();

    Tron::Renderer2D::BeginScene(m_CameraController.GetCamera());
    Tron::Renderer2D::DrawRotatedQuad({-1.0f, 0.0f}, {0.8f, 0.8f},glm::radians(-45.0f), {0.8f, 0.2f, 0.3f, 1.0f});
    Tron::Renderer2D::DrawQuad({0.5f, -0.5f}, {0.5f, 0.75}, {0.2f, 0.3f, 0.8f, 1.0f});
    Tron::Renderer2D::DrawQuad({0.0f, 0.0f, -0.1f}, {10.0f, 10.0f}, m_CheckboardTexture, 10.f);
    Tron::Renderer2D::EndScene();
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

