#include "tnpch.h"
#include "Tron/Core/Input.h"

#ifdef TN_PLATFORM_WINDOWS
#include "Platform/Windows/WindowsInput.h"
#endif

namespace Tron {

    Scope<Input> Input::s_Instance = Input::Create();

    Scope<Input> Input::Create()
    {
        #ifdef TN_PLATFORM_WINDOWS
            return CreateScope<WindowsInput>();
        #else
            TN_CORE_ASSERT(false, "Unknown platform!");
            return nullptr;
        #endif
    }
}
