#ifndef PRIMEENGINE_PRIMEENGINE_H
#define PRIMEENGINE_PRIMEENGINE_H

#include <iostream>
#include <chrono>
#include <functional>
#include "Window.h"

namespace Prime {

    class PrimeEngine {

    public:
        PrimeEngine();

        void InitEngine(void (*tick)());
        void CreateWindow(const char* title, int xPos, int yPos, int width, int height);

    private:
        void Clear();
        void HandleEvents();

        SDL_Event m_Event;
        Window* m_Window = nullptr;
        bool m_IsRunning;

        const int FPS = 60;
        const int frameDelay = 1000/ FPS;
    };

}

#endif //PRIMEENGINE_PRIMEENGINE_H
