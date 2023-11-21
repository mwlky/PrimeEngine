#ifndef PRIMEENGINE_WINDOWEVENTS_H
#define PRIMEENGINE_WINDOWEVENTS_H

#include "Event.h"

namespace Prime{

    enum class WindowEvents{
        WindowResize,
        WindowClose
    };

    class WindowResizeEvent : public Event<WindowEvents>{
    public:
        WindowResizeEvent() : Event<WindowEvents>(WindowEvents::WindowResize, "WindowResize") {}
        ~WindowResizeEvent() override = default;

        int Width = 0;
        int Height = 0;
    };

    class WindowCloseEvent : public Event<WindowEvents>{
    public:
        WindowCloseEvent() : Event<WindowEvents>(WindowEvents::WindowClose, "WindowClose") {}
        ~WindowCloseEvent() override = default;
    };
}


#endif //PRIMEENGINE_WINDOWEVENTS_H
