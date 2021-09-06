#include "tnpch.h"
#include "OpenGLContext.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Tron {

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		TN_CORE_ASSERT(windowHandle, "Window handle is null!");
	}

	void OpenGLContext::Init()
	{
        TN_PROFILE_FUNCTION();

        glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		TN_CORE_ASSERT(status, "Failed to initialize Glad!");

		TN_CORE_INFO("OpenGL Info:");
		TN_CORE_INFO("  Vendor:   {0}", glGetString(GL_VENDOR));
		TN_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
		TN_CORE_INFO("  Version:  {0}", glGetString(GL_VERSION));

		TN_CORE_ASSERT(GLVersion.major > 4 || (GLVersion.major == 4 && GLVersion.minor >= 5), "Tron requires at least OpenGL version 4.5!");
	}

	void OpenGLContext::SwapBuffers()
	{
        TN_PROFILE_FUNCTION();

        glfwSwapBuffers(m_WindowHandle);
	}

}
