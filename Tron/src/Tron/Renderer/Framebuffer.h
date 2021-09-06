#pragma once

#include "Tron/Core/Base.h"

namespace Tron {

    struct FramebufferSpecification
    {
        uint32_t Width = 0, Height = 0;
        // FramebufferFormat Format =
        uint32_t Samples = 1;

        bool SwapChainTarget = false;
    };

    class Framebuffer {
    public:
        virtual ~Framebuffer() = default;

        virtual void Bind() = 0;
        virtual void Unbind() = 0;

        virtual void Resize(uint32_t width, uint32_t height) = 0;

        [[nodiscard]] virtual uint32_t GetColorAttachmentRendererID() const = 0;
        [[nodiscard]] virtual const FramebufferSpecification& GetSpecification() const = 0;

        static Ref<Framebuffer> Create(const FramebufferSpecification& spec);
    };
}


