#ifndef PRIMEENGINE_ECS_H
#define PRIMEENGINE_ECS_H

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>
#include <unordered_map>

namespace Prime {

    class Entity;

    class Component {
    public:
        Entity *entity;

        virtual void Tick() {}

    };

    class Entity {

    public:
        template<typename T, typename ... Args>
        T *AddComponent(Args&&... args) {
            T *component = new T(std::forward<Args>(args)...);
            component->entity = this;

            m_Components[typeid(T).name()] = component;
            return component;
        }

        template<typename T>
        T *GetComponent() const {
            auto it = m_Components.find(typeid(T).name());

            if(it != m_Components.end()){
                return dynamic_cast<T*>(it->second);
            }

            return nullptr;
        };

        void TickComponents(){
            for (auto& pair: m_Components) {
                pair.second->Tick();
            }
        }

        ~Entity() {
            for (auto &pair: m_Components) {
                delete pair.second;
            }
            m_Components.clear();
        }

    private:
        std::unordered_map<std::string, Component *> m_Components;
    };
}

#endif //PRIMEENGINE_ECS_H
