#pragma once

#include "engine/Event.h"
#include <string>

namespace se {

    class Layer {
    public:
        Layer(const std::string& name = "Layer");
        virtual ~Layer() = default;

        virtual void OnAttach() {}
        virtual void OnDetach() {}
        virtual void OnUpdate(float ts) {}
        virtual void OnRender() {}
        virtual void OnImGuiRender() {}
        virtual void OnEvent(Event& event) {}

        const std::string& GetName() const { return debugName_; }

    protected:
        std::string debugName_;
    };

} // namespace se