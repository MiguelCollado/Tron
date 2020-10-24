#include <Tron.h>

class ExampleLayer : public Tron::Layer {
public:
	ExampleLayer()
		: Layer("Example") {}

	void OnUpdate() override {
	
		if (Tron::Input::IsKeyPressed(TN_KEY_TAB))
			TN_TRACE("Tab key is pressed!");
	}

	void OnEvent(Tron::Event& event) override {
	}
};

class Sandbox : public Tron::Application {
public:
	Sandbox() {
		PushLayer(new ExampleLayer());
		PushOverlay(new Tron::ImGuiLayer());
	}

	~Sandbox() {

	}
};

Tron::Application* Tron::CreateApplication() {
	return new Sandbox();
}