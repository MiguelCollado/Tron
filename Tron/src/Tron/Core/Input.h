#pragma once

#include <glm/glm.hpp>

#include "Tron/Core/KeyCodes.h"
#include "Tron/Core/MouseCodes.h"

namespace Tron {

	class Input {
	public:
		static bool IsKeyPressed(KeyCode key);

		static bool IsMouseButtonPressed(MouseCode button);
		static glm::vec2 GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};
}