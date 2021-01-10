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
		~ImGuiLayer() override;

		void OnAttach() override;
		void OnDetach() override;
        void OnEvent(Event& e) override;
		void OnImGuiRender() override;

		void Begin();
		void End();

		void BlockEvents(bool block) { m_BlockEvents = block; }
	private:
	    bool m_BlockEvents = true;
		float m_Time = 0.0f;
	};

}

