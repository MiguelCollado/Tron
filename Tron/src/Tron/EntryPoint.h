#pragma once

#ifdef TN_PLATFORM_WINDOWS

extern Tron::Application* Tron::CreateApplication();

int main(int argc, char** argv) {
	auto app = Tron::CreateApplication();
	app->Run();
	delete app;
}

#endif
