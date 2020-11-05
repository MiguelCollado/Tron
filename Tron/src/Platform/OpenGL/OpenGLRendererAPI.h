#pragma once

#include "Tron/Renderer/RendererAPI.h"

namespace Tron {
	class OpenGLRendererAPI : public RendererAPI
	{
	public:
		// Heredado v�a RendererAPI
		virtual void Init() override;

		virtual void SetClearColor(const glm::vec4& color) override;
		virtual void Clear() override;

		virtual void DrawIndexed(const Ref<VertexArray>& vertexArray) override;
	};
}


