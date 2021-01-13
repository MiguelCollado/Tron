#pragma once

#include "Tron.h"

namespace Tron {

	class CameraController : public ScriptableEntity {
	public:
		void OnCreate() {
		}

		void OnDestroy() {

		}

		void OnUpdate(Timestep ts) {
			auto& transform = GetComponent<TransformComponent>().Transform;

			if (Input::IsKeyPressed(KeyCode::A))
				transform[3][0] -= m_Speed * ts;
			if (Input::IsKeyPressed(KeyCode::D))
				transform[3][0] += m_Speed * ts;
			if (Input::IsKeyPressed(KeyCode::W))
				transform[3][1] += m_Speed * ts;
			if (Input::IsKeyPressed(KeyCode::S))
				transform[3][1] -= m_Speed * ts;
		}

	private:
		float m_Speed = 5.0f;
	};
}