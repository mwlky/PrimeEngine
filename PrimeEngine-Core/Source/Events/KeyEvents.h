#ifndef PRIMEENGINE_KEYEVENTS_H
#define PRIMEENGINE_KEYEVENTS_H

#include "Event.h"

namespace Prime
{
    enum class KeyEvents
    {
        KeyDown,
        KeyUp
    };

    enum class KeyCode
    {
        W,
        A,
        S,
        D
    };

    class KeyDownEvent : public Event<KeyEvents>
    {
    public:
        KeyDownEvent() : Event<KeyEvents>(KeyEvents::KeyDown, "KeyDownEvent")
        {
        }

        ~KeyDownEvent() override = default;

        KeyCode KeyCode;
    };

    class KeyUpEvent : public Event<KeyEvents>
    {
    public:
        KeyUpEvent() : Event<KeyEvents>(KeyEvents::KeyUp, "KeyUpEvent")
        {
        }

        ~KeyUpEvent() override = default;

        KeyCode KeyCode;
    };
}

#endif //PRIMEENGINE_KEYEVENTS_H
