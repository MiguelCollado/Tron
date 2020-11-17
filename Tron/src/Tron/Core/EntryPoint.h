#pragma once
#include "Tron/Core/Core.h"

#ifdef TN_PLATFORM_WINDOWS

extern Tron::Application* Tron::CreateApplication();

int main(int argc, char** argv) {

	Tron::Log::Init();

	TN_PROFILE_BEGIN_SESSION("Startup", "TronProfile-Startup.json");
	auto app = Tron::CreateApplication();
	TN_PROFILE_END_SESSION();

    TN_PROFILE_BEGIN_SESSION("Runtime", "TronProfile-Runtime.json");
    app->Run();
    TN_PROFILE_END_SESSION();

    TN_PROFILE_BEGIN_SESSION("Shutdown", "TronProfile-Shutdown.json");
    delete app;
    TN_PROFILE_END_SESSION();
}

#endif
