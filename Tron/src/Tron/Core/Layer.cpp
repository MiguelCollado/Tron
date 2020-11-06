#include "tnpch.h"
#include "Layer.h"

namespace Tron {
	Layer::Layer(const std::string& debugName)
		: m_DebugName(debugName)
	{
	}

	Layer::~Layer() {}
}
