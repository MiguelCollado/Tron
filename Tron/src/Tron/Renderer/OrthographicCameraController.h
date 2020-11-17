#pragma once

#include <Tron/Core/Timestep.h>

#include <Tron/Events/ApplicationEvent.h>
#include <Tron/Events/MouseEvent.h>

#include "OrthographicCamera.h"

namespace Tron {

    class OrthographicCameraController {
    public:
        explicit OrthographicCameraController(float aspectRatio, bool rotation = false);

        void OnUpdate(Timestep ts);
        void OnEvent(Event& e);

        OrthographicCamera& GetCamera() {return m_Camera;}
        [[nodiscard]] const OrthographicCamera& GetCamera() const {return m_Camera;}

        void SetZoomLevel(float level) { m_ZoomLevel = level; }
        float GetZoomLevel(float level) const { return m_ZoomLevel; }
    private:
        bool OnMouseScrolled(MouseScrolledEvent& e);
        bool OnWindowResized(WindowResizeEvent& e);
    private:
        float m_AspectRatio;
        float m_ZoomLevel = 1.0f;
        OrthographicCamera m_Camera;

        bool m_Rotation;

        glm::vec3 m_CameraPosition = { 0.0f, 0.0f, 0.0f };
        float m_CameraRotation = 0.0f;

        float m_CameraTranslationSpeed = 5.0f;
        float m_CameraRotationSpeed = 180.0f;
    };

}
