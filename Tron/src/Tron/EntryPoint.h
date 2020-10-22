#pragma once

#ifdef TN_PLATFORM_WINDOWS

extern Tron::Application* Tron::CreateApplication();

int main(int argc, char** argv) {

	Tron::Log::Init();
	
	TN_CORE_WARN("Initialized Log!");
	int a = 5;
	TN_INFO("Hello! Var={0}", a);

	auto app = Tron::CreateApplication();
	app->Run();
	delete app;
}

#endif
