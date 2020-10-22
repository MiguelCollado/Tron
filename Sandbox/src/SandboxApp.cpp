#include <Tron.h>

class ExampleLayer : public Tron::Layer {
public:
	ExampleLayer()
		: Layer("Example") {}

	void OnUpdate() override {
		TN_INFO("ExampleLayer::Update");
	}

	void OnEvent(Tron::Event& event) override {
		TN_TRACE("{0}", event);
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