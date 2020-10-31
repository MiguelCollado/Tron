#include "tnpch.h"
#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Tron {

	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI();

}