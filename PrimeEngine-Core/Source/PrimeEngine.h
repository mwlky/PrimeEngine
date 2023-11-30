#ifndef PRIMEENGINE_PRIMEENGINE_H
#define PRIMEENGINE_PRIMEENGINE_H

#include <iostream>
#include <chrono>
#include <functional>
#include "Window.h"
#include "Managers/SpriteManager.h"
#include "Components/Sprite.h"
#include "Math/Vector2.h"
#include "Events/EventHandler.h"

namespace Prime {

    class PrimeEngine {

    public:
        PrimeEngine();

        typedef std::function<void()> TickFunction;
        typedef std::function<void()> StartFunction;
        typedef std::function<void()> RenderFunction;
        typedef std::function<void()> ClearFunction;

        void InitEngine(const TickFunction &tick, const StartFunction &startFunction,
                        const RenderFunction &renderFunction);

        void CreateWindow(const char *title, int xPos, int yPos, int width, int height);

    private:
        void Clear();
        void InvokeKeyDownEvents();
        void InvokeKeyUpEvents();
        void HandleEvents();

        SDL_Event m_Event; 
        Window *m_Window = nullptr;
        bool m_IsRunning;

        const int FPS = 60;
        const int frameDelay = 1000 / FPS;
    };

}

#endif //PRIMEENGINE_PRIMEENGINE_H
