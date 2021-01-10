#include "tnpch.h"
#include "Framebuffer.h"

#include "Tron/Renderer/Renderer.h"

#include "Platform/OpenGL/OpenGLFramebuffer.h"

namespace Tron {

    Ref<Framebuffer> Framebuffer::Create(const FramebufferSpecification& spec) {

        switch (Renderer::GetAPI()) {
            case RendererAPI::API::None: TN_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
            case RendererAPI::API::OpenGL: return CreateRef<OpenGLFramebuffer>(spec);
        }

        TN_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }

}
