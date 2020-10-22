#include "Application.h"

#include "Tron/Events/ApplicationEvent.h"
#include "Tron/Log.h"

namespace Tron {
	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run() {

		WindowResizeEvent e(1280, 720);
		TN_TRACE(e);

		while (true);
	}
}


