cmake_minimum_required(VERSION 3.16)
project(Tron)

set(CMAKE_CXX_STANDARD 17)

include_directories(vendor/spdlog/include)
include_directories(vendor/Glad/include)
include_directories(vendor/GLFW/include)
include_directories(vendor/imgui)
include_directories(vendor/stb_image)
include_directories(vendor/glm)

add_subdirectory(vendor/glm)
add_subdirectory(vendor/GLFW)

set(IMGUI_SRC
        vendor/imgui/imgui.h
        vendor/imgui/imgui.cpp
        vendor/imgui/imgui_widgets.cpp
        vendor/imgui/imgui_demo.cpp
        vendor/imgui/imgui_draw.cpp)

set(STBIMG_SRC
        vendor/stb_image/stb_image.cpp)

set(GLAD_SRC
        vendor/Glad/src/glad.c)

set(SOURCES
        src/Tron/Core/Application.cpp
        src/Tron/Core/Application.h
        src/Tron/Core/Core.h
        src/Tron/Core/EntryPoint.h
        src/Tron/Core/Input.h
        src/Tron/Core/KeyCodes.h
        src/Tron/Core/Layer.cpp
        src/Tron/Core/Layer.h
        src/Tron/Core/LayerStack.cpp
        src/Tron/Core/LayerStack.h
        src/Tron/Core/Log.cpp
        src/Tron/Core/Log.h
        src/Tron/Core/Timestep.h
        src/Tron/Core/Window.h
        src/Tron/Events/ApplicationEvent.h
        src/Tron/Events/Event.h
        src/Tron/Events/KeyEvent.h
        src/Tron/Events/MouseEvent.h
        src/Tron/ImGui/ImGuiBuild.cpp
        src/Tron/ImGui/ImGuiLayer.cpp
        src/Tron/ImGui/ImGuiLayer.h
        src/Tron/Renderer/Buffer.cpp
        src/Tron/Renderer/Buffer.h
        src/Tron/Renderer/GraphicsContext.h
        src/Tron/Renderer/OrthographicCamera.cpp
        src/Tron/Renderer/OrthographicCamera.h
        src/Tron/Renderer/RenderCommand.cpp
        src/Tron/Renderer/RenderCommand.h
        src/Tron/Renderer/Renderer.cpp
        src/Tron/Renderer/Renderer.h
        src/Tron/Renderer/RendererAPI.cpp
        src/Tron/Renderer/RendererAPI.h
        src/Tron/Renderer/Shader.cpp
        src/Tron/Renderer/Shader.h
        src/Tron/Renderer/Texture.cpp
        src/Tron/Renderer/Texture.h
        src/Tron/Renderer/VertexArray.cpp
        src/Tron/Renderer/VertexArray.h
        src/Platform/OpenGL/OpenGLBuffer.cpp
        src/Platform/OpenGL/OpenGLBuffer.h
        src/Platform/OpenGL/OpenGLContext.cpp
        src/Platform/OpenGL/OpenGLContext.h
        src/Platform/OpenGL/OpenGLRendererAPI.cpp
        src/Platform/OpenGL/OpenGLRendererAPI.h
        src/Platform/OpenGL/OpenGLShader.cpp
        src/Platform/OpenGL/OpenGLShader.h
        src/Platform/OpenGL/OpenGLTexture.cpp
        src/Platform/OpenGL/OpenGLTexture.h
        src/Platform/OpenGL/OpenGLVertexArray.cpp
        src/Platform/OpenGL/OpenGLVertexArray.h
        src/Platform/Windows/WindowsInput.cpp
        src/Platform/Windows/WindowsInput.h
        src/Platform/Windows/WindowsWindow.cpp
        src/Platform/Windows/WindowsWindow.h
        src/Tron.h
        src/tnpch.cpp
        src/tnpch.h
        src/Tron/Renderer/OrthographicCameraController.cpp
        src/Tron/Renderer/OrthographicCameraController.h
        src/Tron/Renderer/Renderer2D.cpp
        src/Tron/Renderer/Renderer2D.h
        src/Tron/Renderer/GraphicsContext.cpp
        src/Tron/Debug/Instrumentor.h
        src/Tron/Core/MouseCodes.h src/Tron/Core/Input.cpp src/Tron/Core/Window.cpp)

include_directories(src)

add_library(${PROJECT_NAME} STATIC ${SOURCES} ${IMGUI_SRC} ${GLAD_SRC} ${STBIMG_SRC})

target_link_libraries(${PROJECT_NAME} glfw)