#ifndef PRIMEENGINE_PRIMEENGINE_H
#define PRIMEENGINE_PRIMEENGINE_H

#include <iostream>
#include <chrono>
#include <functional>
#include "Window.h"
#include "Managers/SpriteManager.h"
#include "Components/Sprite.h"
#include "Components/Player/Player.h"
#include "Math/Vector2.h"
#include "Events/EventHandler.h"

namespace Prime {

    class PrimeEngine {

    public:
        PrimeEngine();

        typedef std::function<void()> TickFunction;
        typedef std::function<void()> StartFunction;
        typedef std::function<void()> RenderFunction;

        void InitEngine(const PrimeEngine::TickFunction &tick, const PrimeEngine::StartFunction &startFunction,
                        const PrimeEngine::RenderFunction &renderFunction);

        void CreateWindow(const char *title, int xPos, int yPos, int width, int height);

        typedef std::function<void()> OnKeyDownEventFunction;

        static SDL_Event m_Event;

    private:
        void Clear();
        void HandleEvents();

        Window *m_Window = nullptr;
        bool m_IsRunning;


        const int FPS = 60;
        const int frameDelay = 1000 / FPS;
    };

}

#endif //PRIMEENGINE_PRIMEENGINE_H
