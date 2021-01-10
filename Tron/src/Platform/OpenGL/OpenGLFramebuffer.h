#pragma once

#include "Tron/Renderer/Framebuffer.h"

namespace Tron {
    class OpenGLFramebuffer : public Framebuffer {

    public:
        OpenGLFramebuffer(const FramebufferSpecification& spec);
        virtual ~OpenGLFramebuffer();

        void Invalidate();

        void Bind() override;
        void Unbind() override;
        void Resize(uint32_t width, uint32_t height) override;

        [[nodiscard]] uint32_t GetColorAttachmentRendererID() const override { return m_ColorAttachment;}
        [[nodiscard]] const FramebufferSpecification& GetSpecification() const override { return m_Specification; }

    private:
        uint32_t m_RendererID = 0;
        uint32_t m_ColorAttachment = 0, m_DepthAttachment = 0;
        FramebufferSpecification m_Specification;
    };
}


