#pragma once
#include "Tron/Core/Core.h"

#ifdef TN_PLATFORM_WINDOWS

extern Tron::Application* Tron::CreateApplication();

int main(int argc, char** argv) {

	Tron::Log::Init();

	auto app = Tron::CreateApplication();
	app->Run();
	delete app;
}

#endif
