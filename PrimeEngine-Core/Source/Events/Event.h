#ifndef PRIMEENGINE_EVENT_H
#define PRIMEENGINE_EVENT_H

#include "iostream"

namespace Prime{

    template <typename T>
    class Event{
    public:

        Event() = default;
        Event(T type, const std::string& name = "") : m_Type(type), m_Name(name) {}

        virtual ~Event() {}

        inline const T GetType() const { return m_Type; }
        inline const std::string& GetName() const { return m_Name; }
        template<typename EventType>

        inline EventType ToType() const {
            return static_cast<const EventType&>(*this);
        }

        virtual bool IsHandled() const { return m_Handled; }

    protected:
        T m_Type;
        std::string m_Name;
        bool m_Handled = false;
    };

}

#endif //PRIMEENGINE_EVENT_H
