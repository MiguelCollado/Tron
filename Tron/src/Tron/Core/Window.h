#pragma once

#include "tnpch.h"

#include "Base.h"
#include "Tron/Events/Event.h"

namespace Tron {

    struct WindowProps {
        std::string Title;
        uint32_t Width;
        uint32_t Height;

        WindowProps(const std::string &title = "Tron Engine",
                    uint32_t width = 1280,
                    uint32_t height = 720)
                : Title(title), Width(width), Height(height) {}
    };

    class Window {
    public:
        using EventCallbackFn = std::function<void(Event &)>;

        virtual ~Window() = default;

        virtual void OnUpdate() = 0;

        [[nodiscard]] virtual uint32_t GetWidth() const = 0;
        [[nodiscard]] virtual uint32_t GetHeight() const = 0;

        // Window attributes
        virtual void SetEventCallback(const EventCallbackFn &callback) = 0;

        virtual void SetVSync(bool enabled) = 0;

        [[nodiscard]] virtual bool IsVSync() const = 0;

        [[nodiscard]] virtual void *GetNativeWindow() const = 0;

        static Scope<Window> Create(const WindowProps &props = WindowProps());
    };
}

