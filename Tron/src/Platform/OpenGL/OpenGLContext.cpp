#include "tnpch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Tron {

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		TN_CORE_ASSERT(windowHandle, "Window handle is null!");
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		TN_CORE_ASSERT(status, "Failed to initialize Glad!");

		TN_CORE_INFO("OpenGL Info:");
		TN_CORE_INFO("  Vendor:   {0}", glGetString(GL_VENDOR));
		TN_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
		TN_CORE_INFO("  Version:  {0}", glGetString(GL_VERSION));
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}

}
