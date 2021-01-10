#pragma once

#include "Tron/Core/Base.h"
#include "Tron/Core/KeyCodes.h"
#include "Tron/Core/MouseCodes.h"

namespace Tron {

	class Input {
	public:
		static bool IsKeyPressed(KeyCode key);

		static bool IsMouseButtonPressed(MouseCode button);
		static std::pair<float, float> GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};
}