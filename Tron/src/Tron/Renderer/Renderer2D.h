//
// Created by mcoll on 10/11/2020.
//

#ifndef TRONENGINE_RENDERER2D_H
#define TRONENGINE_RENDERER2D_H

#include "Tron/Renderer/OrthographicCamera.h"

#include "Tron/Renderer/Texture.h"

namespace Tron {

    class Renderer2D {
    public:
        static void Init();
        static void Shutdown();

        static void BeginScene(const OrthographicCamera& camera);
        static void EndScene();

        // Primitives
        static void DrawQuad(const glm::vec2& position, const glm::vec2& size, const glm::vec4& color);
        static void DrawQuad(const glm::vec3& position, const glm::vec2& size, const glm::vec4& color);
        static void DrawQuad(const glm::vec2& position, const glm::vec2& size, const Ref<Texture2D>& texture);
        static void DrawQuad(const glm::vec3& position, const glm::vec2& size, const Ref<Texture2D>& texture);
    };
}

#endif //TRONENGINE_RENDERER2D_H
