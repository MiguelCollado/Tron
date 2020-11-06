#pragma once

#include "Tron/Renderer/RendererAPI.h"

namespace Tron {
	class OpenGLRendererAPI : public RendererAPI
	{
	public:
		// Heredado vía RendererAPI
		void Init() override;

        void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) override;
        void SetClearColor(const glm::vec4& color) override;
		void Clear() override;

		void DrawIndexed(const Ref<VertexArray>& vertexArray) override;
	};
}


