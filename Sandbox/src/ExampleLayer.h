//
// Created by mcoll on 17/11/2020.
//

#pragma once

#include "Tron.h"

class ExampleLayer : public Tron::Layer
{
public:
    ExampleLayer();
    virtual ~ExampleLayer() = default;

    virtual void OnAttach() override;
    virtual void OnDetach() override;

    void OnUpdate(Tron::Timestep ts) override;
    virtual void OnImGuiRender() override;
    void OnEvent(Tron::Event& e) override;
private:
    Tron::ShaderLibrary m_ShaderLibrary;
    Tron::Ref<Tron::Shader> m_Shader;
    Tron::Ref<Tron::VertexArray> m_VertexArray;

    Tron::Ref<Tron::Shader> m_FlatColorShader;
    Tron::Ref<Tron::VertexArray> m_SquareVA;

    Tron::Ref<Tron::Texture2D> m_Texture, m_ChernoLogoTexture;

    Tron::OrthographicCameraController m_CameraController;
    glm::vec3 m_SquareColor = { 0.2f, 0.3f, 0.8f };
};


