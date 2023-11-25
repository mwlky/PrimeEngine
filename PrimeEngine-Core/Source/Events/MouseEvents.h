#ifndef PRIMEENGINE_MOUSEEVENTS_H
#define PRIMEENGINE_MOUSEEVENTS_H

#include "Event.h"

namespace Prime{

    enum class MouseEvents{
        MouseMove,
        MouseButtonDown,
        MouseButtonUp
    };

    class MouseMoveEvent : public Event<MouseEvents>{

    public:
        MouseMoveEvent() : Event<MouseEvents>(MouseEvents::MouseMove, "MouseMove") {}
        ~MouseMoveEvent() override = default;

        int X = -1;
        int Y = -1;
    };

    class MouseButtonDownEvent : public Event<MouseEvents> {

    public:
        MouseButtonDownEvent() : Event<MouseEvents>(MouseEvents::MouseButtonDown, "MouseButtonDown") {}
        ~MouseButtonDownEvent() override = default;

        int Button = -1;
        // 1 - LMB
        // 2 - NMB
        // 3 - RMB
    };

    class MouseButtonUpEvent : public Event<MouseEvents> {

    public:
        MouseButtonUpEvent() : Event<MouseEvents>(MouseEvents::MouseButtonUp, "MouseButtonUp") {}
        ~MouseButtonUpEvent() override = default;

        int Button = -1;
        // 1 - LMB
        // 2 - NMB
        // 3 - RMB
    };

}

#endif //PRIMEENGINE_MOUSEEVENTS_H
