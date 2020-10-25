#include <Tron.h>

#include "imgui/imgui.h"

class ExampleLayer : public Tron::Layer {
public:
	ExampleLayer()
		: Layer("Example") {}

	void OnUpdate() override {
	}

	virtual void OnImGuiRender() override {
		ImGui::Begin("Test");
		ImGui::Text("Hello Wolds");
		ImGui::End();
	}

	void OnEvent(Tron::Event& event) override {
	}
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