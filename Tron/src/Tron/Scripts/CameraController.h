#pragma once

#include "Tron.h"

namespace Tron {

	class CameraController : public ScriptableEntity {
	public:
		void OnCreate() {
			std::cout << "OnCreate!" << std::endl;

		}

		void OnDestroy() {

		}

		void OnUpdate(Timestep ts) {
			std::cout << "Timestep: " << ts << std::endl;
		}
	};

}