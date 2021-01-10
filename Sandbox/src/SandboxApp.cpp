#include <Tron.h>
#include <Tron/Core/EntryPoint.h>

#include "Sandbox2D.h"

class Sandbox : public Tron::Application {
public:
	Sandbox() {
		PushLayer(new Sandbox2D());
	}

	~Sandbox() override = default;
};

Tron::Application* Tron::CreateApplication() {
	return new Sandbox();
}