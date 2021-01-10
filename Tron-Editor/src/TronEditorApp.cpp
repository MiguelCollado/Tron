#include <Tron.h>
#include <Tron/Core/EntryPoint.h>

#include "EditorLayer.h"


namespace Tron {
    class TronEditor : public Application {
    public:
        TronEditor() {
            PushLayer(new EditorLayer());
        }

        ~TronEditor() override = default;
    };

    Application* CreateApplication() {
        return new TronEditor();
    }
}
