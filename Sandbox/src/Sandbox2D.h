//
// Created by mcoll on 09/11/2020.
//

#ifndef TRONENGINE_SANDBOX2D_H
#define TRONENGINE_SANDBOX2D_H

#include <Tron.h>

class Sandbox2D : public Tron::Layer {
public:
    Sandbox2D();
    ~Sandbox2D() override = default;

    void OnAttach() override;
    void OnDetach() override;

    void OnUpdate(Tron::Timestep ts) override;
    void OnImGuiRender() override;
    void OnEvent(Tron::Event& e) override;
private:
    Tron::OrthographicCameraController m_CameraController;

    // Temp
    Tron::Ref<Tron::VertexArray> m_SquareVA;
    Tron::Ref<Tron::Shader> m_FlatColorShader;

    Tron::Ref<Tron::Texture2D> m_CheckboardTexture;

    struct ProfileResult {
        const char* Name;
        float Time;
    };

    std::vector<ProfileResult> m_ProfileResults;

    glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f};
};


#endif //TRONENGINE_SANDBOX2D_H
