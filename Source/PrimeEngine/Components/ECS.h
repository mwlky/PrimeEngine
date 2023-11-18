#ifndef PRIMEENGINE_ECS_H
#define PRIMEENGINE_ECS_H

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>

namespace Prime {

    class Component;
    class Entity;

    using ComponentID = std::size_t;

    inline ComponentID GetComponentTypeID() {
        static ComponentID lastID = 0;
        return lastID++;
    }

    template<typename T>
    inline ComponentID GetComponentTypeID() noexcept {
        static ComponentID typeID = GetComponentTypeID();
        return typeID;
    }

    constexpr std::size_t maxComponents = 32;

    using ComponentBitSet = std::bitset<maxComponents>;
    using ComponentArray = std::array<Component *, maxComponents>;

    class Component {
    public:
        Entity *entity;

        virtual void Init() {}

        virtual void Tick() {}

        virtual void Draw() {}

        virtual ~Component() {}
    };

    class Entity {
    private:
        bool active = true;
        std::vector<std::unique_ptr<Component>> components;

        ComponentArray componentArray;
        ComponentBitSet componentBitSet;

    public:
        void Tick() {
            for (auto &component: components) {
                component->Tick();
                component->Draw();
            }
        }

        void Draw() {
            for (auto &component: components) {
                component->Draw();
            }
        }

        void Destroy() { active = false; }

        bool isActive() const { return active; }

        template <typename T> bool HasComponent() const {
            return componentBitSet[GetComponentTypeID<T>()];
        }

        template <typename T, typename... TArgs>
        T& AddComponent(TArgs&&... args){
            T* component(new T(std::forward<TArgs>(args)...));
            component->entity = this;
            std::unique_ptr<Component> uPtr { component};
            components.emplace_back(std::move(uPtr));

            componentArray[GetComponentTypeID<T>()] = component;
            componentBitSet[GetComponentTypeID<T>()] = true;

            component->Init();
            return *component;
        }

        template <typename T> T& GetComponent() const {
            auto ptr(componentArray[GetComponentTypeID<T>()]);
            return *static_cast<T*>(ptr);
        }
    };

    class Manager{
    private:
        std::vector<std::unique_ptr<Entity>> entities;

    public:
        void Tick(){
            for (auto& entity: entities) {
                entity->Tick();
            }
        }

        void Draw(){
            for (auto& entity : entities) {
                entity->Draw();
            }
        }

        void Refresh(){
            entities.erase(std::remove_if(std::begin(entities), std::end(entities),
                                          [](const std::unique_ptr<Entity> &mEntity){
                                              return !mEntity->isActive();
                                          }), std::end(entities));
        }

        Entity& AddEntity(){
            Entity* entity = new Entity();
            std::unique_ptr<Entity> uPtr{entity};
            entities.emplace_back(std::move(uPtr));

            return *entity;
        }
    };
}

#endif //PRIMEENGINE_ECS_H
