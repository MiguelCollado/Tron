#include "tnpch.h"
#include "Tron/Renderer/GraphicsContext.h"

#include "Tron/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLContext.h"

namespace Tron {

    Scope<GraphicsContext> GraphicsContext::Create(void* window)
    {
        switch (Renderer::GetAPI())
        {
            case RendererAPI::API::None:    TN_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
            case RendererAPI::API::OpenGL:  return CreateScope<OpenGLContext>(static_cast<GLFWwindow*>(window));
        }

        TN_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }

} 