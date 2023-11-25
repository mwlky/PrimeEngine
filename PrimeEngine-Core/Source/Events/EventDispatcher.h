#ifndef PRIMEENGINE_EVENTDISPATCHER_H
#define PRIMEENGINE_EVENTDISPATCHER_H

#include "Event.h"
#include <string>
#include <map>
#include <functional>
#include <vector>

namespace Prime{

    template<typename T>
    class EventDispatcher{

    private:
        using Func = std::function<void(const Event<T>&)>;
        std::map<T, std::vector<Func>> m_Listeners;

    public:
        void AddListener(T type, const Func& func){
            m_Listeners[type].push_back(func);
        }

        void SendEvent(const Event<T>& event){
            if(m_Listeners.find(event.GetType()) == m_Listeners.end())
                return;

            for (auto&& listener: m_Listeners.at(event.GetType())) {
                if(!event.IsHandled())
                    listener(event);
            }
        }
    };

}


#endif //PRIMEENGINE_EVENTDISPATCHER_H
