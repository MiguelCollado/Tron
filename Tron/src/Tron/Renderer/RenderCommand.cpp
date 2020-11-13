#include "tnpch.h"
#include "Tron/Renderer/RenderCommand.h"

namespace Tron {

    Scope<RendererAPI> RenderCommand::s_RendererAPI = RendererAPI::Create();

}