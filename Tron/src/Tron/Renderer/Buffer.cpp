#include "tnpch.h"
#include "Tron/Renderer/Buffer.h"

#include "Tron/Renderer/Renderer.h"

#include "Platform/OpenGL/OpenGLBuffer.h"

namespace Tron {

	Ref<VertexBuffer> VertexBuffer::Create(float* vertices, uint32_t size)
	{
		switch (Renderer::GetAPI()) {
		    case RendererAPI::API::None:	TN_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPI::API::OpenGL:	return CreateRef<OpenGLVertexBuffer>(vertices, size);
		}

		TN_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

	Ref<IndexBuffer> IndexBuffer::Create(uint32_t* indices, uint32_t size)
	{
		switch (Renderer::GetAPI()) {
			case RendererAPI::API::None:	TN_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPI::API::OpenGL:	return CreateRef<OpenGLIndexBuffer>(indices, size);
		}

		TN_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}