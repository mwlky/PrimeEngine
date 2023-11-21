#ifndef PRIMEENGINE_KEYEVENTS_H
#define PRIMEENGINE_KEYEVENTS_H

#include "Event.h"

namespace Prime{

    enum class KeyEvents{
        KeyDown,
        KeyUp
    };

    class KeyDownEvent : public Event<KeyEvents>{

    public:
        KeyDownEvent() : Event<KeyEvents>(KeyEvents::KeyDown, "KeyDownEvent"){}
        ~KeyDownEvent() override = default;

        int KeyCode = -1;
        // ASCII of the key that was pressed down
    };

    class KeyUpEvent : public Event<KeyEvents>{

    public:
        KeyUpEvent() : Event<KeyEvents>(KeyEvents::KeyUp, "KeyUpEvent"){}
        ~KeyUpEvent() override = default;

        int KeyCode = -1;
        // ASCII of the key that was pressed down
    };

}

#endif //PRIMEENGINE_KEYEVENTS_H
