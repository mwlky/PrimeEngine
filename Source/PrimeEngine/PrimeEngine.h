#ifndef PRIMEENGINE_PRIMEENGINE_H
#define PRIMEENGINE_PRIMEENGINE_H

#include <iostream>
#include <chrono>
#include <functional>
#include "Window.h"
#include "SpriteManager.h"

namespace Prime {

    class PrimeEngine {

    public:
        PrimeEngine();

        typedef std::function<void()> TickFunction;
        typedef std::function<void()> StartFunction;

        void InitEngine(const PrimeEngine::TickFunction& tick, const PrimeEngine::StartFunction& startFunction);
        void CreateWindow(const char *title, int xPos, int yPos, int width, int height);

        SpriteManager* GetSpriteManager() { return m_SpriteManager; }
        Window* GetCurrentWindow(){ return m_Window; }

    private:
        void Clear();
        void HandleEvents();

        SpriteManager *m_SpriteManager = nullptr;

        SDL_Event m_Event;
        Window *m_Window = nullptr;
        bool m_IsRunning;

        const int FPS = 60;
        const int frameDelay = 1000 / FPS;
    };

}

#endif //PRIMEENGINE_PRIMEENGINE_H
