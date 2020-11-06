#pragma once

#include "Tron/Core/Core.h"
#include "Tron/Core/Input.h"

namespace Tron {

	class WindowsInput : public Input 
	{
	protected:
		virtual bool IsKeyPressedImpl(int keycode) override;

		virtual bool IsMouseButtonPressedImpl(int button) override;
		virtual std::pair<float, float> GetMousePositionImpl() override;
		virtual float GetMouseXImpl() override;
		virtual float GetMouseYImpl() override;
	};
}


