#pragma once

#include "Tron/Core/Layer.h"

#include "Tron/Events/KeyEvent.h"
#include "Tron/Events/MouseEvent.h"
#include "Tron/Events/ApplicationEvent.h"

namespace Tron {

	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual	void OnAttach() override;
		virtual	void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();
	private:
		float m_Time = 0.0f;
	};

}

