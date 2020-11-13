#include "tnpch.h"
#include "Tron/Core/Layer.h"

namespace Tron {
	Layer::Layer(const std::string& debugName)
		: m_DebugName(debugName)
	{
	}

	Layer::~Layer() {}
}
