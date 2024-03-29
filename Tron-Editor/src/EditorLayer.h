#ifndef TRONENGINE_EDITORLAYER_H
#define TRONENGINE_EDITORLAYER_H

#include <Tron.h>
#include <Tron/Renderer/Framebuffer.h>
#include "Panels/SceneHierarchyPanel.h"

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

        Ref<Scene> m_ActiveScene;
        Entity m_SquareEntity;
        Entity m_CameraEntity;
        Entity m_SecondCamera;

        bool m_PrimaryCamera = true;

        Ref<Texture2D> m_CheckboardTexture;

        bool m_ViewportFocused = false, m_ViewportHovered = false;
        glm::vec2 m_ViewportSize = {0.0f, 0.0f};

        glm::vec4 m_SquareColor = {0.2f, 0.3f, 0.8f, 1.0f};

		// Panels
		SceneHierarchyPanel m_SceneHierarchyPanel;
    };
}

#endif //TRONENGINE_EDITORLAYER_H
