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

			if (Input::IsKeyPressed(Key::A))
				transform[3][0] -= m_Speed * ts;
			if (Input::IsKeyPressed(Key::D))
				transform[3][0] += m_Speed * ts;
			if (Input::IsKeyPressed(Key::W))
				transform[3][1] += m_Speed * ts;
			if (Input::IsKeyPressed(Key::S))
				transform[3][1] -= m_Speed * ts;
		}

	private:
		float m_Speed = 5.0f;
	};
}