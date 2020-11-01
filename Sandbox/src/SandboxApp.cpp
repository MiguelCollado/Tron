#include <Tron.h>

#include "imgui/imgui.h"

class ExampleLayer : public Tron::Layer {
public:
	ExampleLayer()
		: Layer("Example"), m_Camera(-1.6f, 1.6f, -0.9f, 0.9f), m_CameraPosition(0.0f) {
	
		m_VertexArray.reset(Tron::VertexArray::Create());

		float vertices[3 * 7] = {
			-0.5f, -0.5f, 0.0f, 0.8f, 0.2f, 1.0f, 1.0f,
			 0.5f, -0.5f, 0.0f, 0.2f, 0.3f, 0.8f, 1.0f,
			 0.0f,  0.5f, 0.0f, 0.8f, 0.8f, 0.2f, 1.0f,
		};

		std::shared_ptr<Tron::VertexBuffer> vertexBuffer;
		vertexBuffer.reset(Tron::VertexBuffer::Create(vertices, sizeof(vertices)));

		Tron::BufferLayout layout = {
			{ Tron::ShaderDataType::Float3, "a_Position"},
			{ Tron::ShaderDataType::Float4, "a_Color"}
		};

		vertexBuffer->SetLayout(layout);
		m_VertexArray->AddVertexBuffer(vertexBuffer);

		uint32_t indices[3] = { 0, 1, 2 };
		std::shared_ptr<Tron::IndexBuffer> indexBuffer;
		indexBuffer.reset(Tron::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));
		m_VertexArray->SetIndexBuffer(indexBuffer);


		m_SquareVA.reset(Tron::VertexArray::Create());

		float squareVertices[3 * 4] = {
			-0.75f, -0.75f, 0.0f,
			 0.75f, -0.75f, 0.0f,
			 0.75f,  0.75f, 0.0f,
			-0.75f,  0.75f, 0.0f,
		};

		std::shared_ptr<Tron::VertexBuffer> squareVB;
		squareVB.reset(Tron::VertexBuffer::Create(squareVertices, sizeof(squareVertices)));

		squareVB->SetLayout({
			{ Tron::ShaderDataType::Float3, "a_Position"}
			});
		m_SquareVA->AddVertexBuffer(squareVB);

		uint32_t squareIndices[6] = { 0, 1, 2, 2, 3, 0 };
		std::shared_ptr<Tron::IndexBuffer> squareIB;
		squareIB.reset(Tron::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t)));
		m_SquareVA->SetIndexBuffer(squareIB);

		std::string vertexSrc = R"(
			#version 330 core
			
			layout(location = 0) in vec3 a_Position;
			layout(location = 1) in vec4 a_Color;

			uniform mat4 u_ViewProjection;

			out vec3 v_Position;
			out vec4 v_Color;

			void main() {
				v_Position = a_Position;
				v_Color = a_Color;
				gl_Position = u_ViewProjection * vec4(a_Position, 1.0);
			}
		)";


		std::string fragmentSrc = R"(
			#version 330 core
			
			layout(location = 0) out vec4 color;

			in vec3 v_Position;
			in vec4 v_Color;

			void main() {
				color = vec4(v_Position * 0.5 + 0.5, 1.0);
				color = v_Color;
			}
		)";

		m_Shader.reset(new Tron::Shader(vertexSrc, fragmentSrc));

		std::string blueShaderVertexSrc = R"(
			#version 330 core
			
			layout(location = 0) in vec3 a_Position;

			uniform mat4 u_ViewProjection;

			out vec3 v_Position;

			void main() {
				v_Position = a_Position;
				gl_Position = u_ViewProjection * vec4(a_Position, 1.0);
			}
		)";


		std::string blueShaderFragmentSrc = R"(
			#version 330 core
			
			layout(location = 0) out vec4 color;

			in vec3 v_Position;

			void main() {
				color = vec4(0.2, 0.3, 0.8, 1.0);
			}
		)";

		m_BlueShader.reset(new Tron::Shader(blueShaderVertexSrc, blueShaderFragmentSrc));
	}

	void OnUpdate(Tron::Timestep ts) override {

		if (Tron::Input::IsKeyPressed(TN_KEY_A)) {
			m_CameraPosition.x -= m_CameraMoveSpeed * ts;
		} else if (Tron::Input::IsKeyPressed(TN_KEY_D)) {
			m_CameraPosition.x += m_CameraMoveSpeed * ts;
		}

		if (Tron::Input::IsKeyPressed(TN_KEY_W)) {
			m_CameraPosition.y += m_CameraMoveSpeed * ts;
		} else if (Tron::Input::IsKeyPressed(TN_KEY_S)) {
			m_CameraPosition.y -= m_CameraMoveSpeed * ts;
		}

		if (Tron::Input::IsKeyPressed(TN_KEY_Q)) {
			m_CameraRotation += m_CameraRotationSpeed * ts;
		} else if (Tron::Input::IsKeyPressed(TN_KEY_E)) {
			m_CameraRotation -= m_CameraRotationSpeed * ts;
		}
		

		Tron::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		Tron::RenderCommand::Clear();

		m_Camera.SetPosition(m_CameraPosition);
		m_Camera.SetRotation(m_CameraRotation);

		Tron::Renderer::BeginScene(m_Camera);

		Tron::Renderer::Submit(m_BlueShader, m_SquareVA);
		Tron::Renderer::Submit(m_Shader, m_VertexArray);

		Tron::Renderer::EndScene();
	}

	virtual void OnImGuiRender() override {

	}

	void OnEvent(Tron::Event& event) override {
	}

private:

	std::shared_ptr<Tron::Shader> m_Shader;
	std::shared_ptr<Tron::VertexArray> m_VertexArray;

	std::shared_ptr<Tron::Shader> m_BlueShader;
	std::shared_ptr<Tron::VertexArray> m_SquareVA;

	Tron::OrthographicCamera m_Camera;
	glm::vec3 m_CameraPosition;

	float m_CameraRotation = 0.0f;

	float m_CameraRotationSpeed = 180.f;
	float m_CameraMoveSpeed = 5.0f;
};

class Sandbox : public Tron::Application {
public:
	Sandbox() {
		PushLayer(new ExampleLayer());
	}

	~Sandbox() {

	}
};

Tron::Application* Tron::CreateApplication() {
	return new Sandbox();
}