#include "tnpch.h"
#include "Platform/OpenGL/OpenGLBuffer.h"

#include <glad/glad.h>

namespace Tron {

	/////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////// VertexBuffer ///////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////
	OpenGLVertexBuffer::OpenGLVertexBuffer(float* vertices, uint32_t size)
	{
        TN_PROFILE_FUNCTION();

        glCreateBuffers(1, &m_RendererID);
		glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
		glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
	}

	OpenGLVertexBuffer::~OpenGLVertexBuffer()
	{
        TN_PROFILE_FUNCTION();

        glDeleteBuffers(1, &m_RendererID);
	}

	void Tron::OpenGLVertexBuffer::Bind() const
	{
        TN_PROFILE_FUNCTION();

        glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
	}

	void Tron::OpenGLVertexBuffer::Unbind() const
	{
        TN_PROFILE_FUNCTION();

        glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
	
	/////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////// IndexBuffer ////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////

	OpenGLIndexBuffer::OpenGLIndexBuffer(uint32_t* indices, uint32_t count)
		: m_Count(count)
	{
        TN_PROFILE_FUNCTION();

        glCreateBuffers(1, &m_RendererID);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(uint32_t), indices, GL_STATIC_DRAW);
	}

	OpenGLIndexBuffer::~OpenGLIndexBuffer()
	{
        TN_PROFILE_FUNCTION();

        glDeleteBuffers(1, &m_RendererID);
	}

	void Tron::OpenGLIndexBuffer::Bind() const
	{
        TN_PROFILE_FUNCTION();

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
	}

	void Tron::OpenGLIndexBuffer::Unbind() const
	{
        TN_PROFILE_FUNCTION();

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

}

