#include <Tron.h>

class Sandbox : public Tron::Application {
public:
	Sandbox() {

	}

	~Sandbox() {

	}
};

Tron::Application* Tron::CreateApplication() {
	return new Sandbox();
}