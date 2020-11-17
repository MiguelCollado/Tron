#include "tnpch.h"
#include "Tron/Core/Window.h"

#ifdef TN_PLATFORM_WINDOWS
    #include "Platform/Windows/WindowsWindow.h"
#endif

namespace Tron
{

    Scope<Window> Window::Create(const WindowProps& props)
    {
        #ifdef TN_PLATFORM_WINDOWS
            return CreateScope<WindowsWindow>(props);
        #else
            TN_CORE_ASSERT(false, "Unknown platform!");
            return nullptr;
        #endif
    }

} 