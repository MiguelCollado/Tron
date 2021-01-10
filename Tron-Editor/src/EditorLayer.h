#ifndef TRONENGINE_EDITORLAYER_H
#define TRONENGINE_EDITORLAYER_H

#include <Tron.h>
#include <Tron/Renderer/Framebuffer.h>

namespace Tron {
    class EditorLayer : public Layer {
    public:
        EditorLayer();
        ~EditorLayer() override = default;

        void OnAttach() override;
        void OnDetach() override;

        void OnUpdate(Timestep ts) override;
        void OnImGuiRender() override;
        void OnEvent(Event &e) override;

    private:
        Tron::OrthographicCameraController m_CameraController;

        // Temp
        Ref<VertexArray> m_SquareVA;
        Ref<Shader> m_FlatColorShader;
        Ref<Framebuffer> m_Framebuffer;

        Ref<Texture2D> m_CheckboardTexture;

        bool m_ViewportFocused = false, m_ViewportHovered = false;
        glm::vec2 m_ViewportSize = {0.0f, 0.0f};

        glm::vec4 m_SquareColor = {0.2f, 0.3f, 0.8f, 1.0f};
    };
}

#endif //TRONENGINE_EDITORLAYER_H
