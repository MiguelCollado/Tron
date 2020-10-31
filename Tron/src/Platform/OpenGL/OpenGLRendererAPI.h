#pragma once

#include "Tron/Renderer/RendererAPI.h"

namespace Tron {
	class OpenGLRendererAPI : public RendererAPI
	{
	public:
		// Heredado vía RendererAPI
		virtual void SetClearColor(const glm::vec4& color) override;
		virtual void Clear() override;

		virtual void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray) override;
	};
}


