#include "tnpch.h"
#include "Tron/Renderer/VertexArray.h"

#include "Tron/Renderer/Renderer.h"

#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace Tron {

	Ref<VertexArray> VertexArray::Create()
	{
        switch (Renderer::GetAPI()) {
            case RendererAPI::API::None:	TN_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPI::API::OpenGL:  return CreateRef<OpenGLVertexArray>();
		}

		TN_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}