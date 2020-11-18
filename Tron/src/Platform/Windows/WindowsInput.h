#pragma once

#include "Tron/Core/Base.h"
#include "Tron/Core/Input.h"

namespace Tron {

	class WindowsInput : public Input 
	{
	protected:
		bool IsKeyPressedImpl(KeyCode keycode) override;

		bool IsMouseButtonPressedImpl(MouseCode button) override;
		std::pair<float, float> GetMousePositionImpl() override;
		float GetMouseXImpl() override;
		float GetMouseYImpl() override;
	};
}


