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

        void StartTicking(void (*tick)());
        void CreateWindow(const char* title, int xPos, int yPos, int width, int height);

    private:
        Window* m_Window = nullptr;
    };

}

#endif //PRIMEENGINE_PRIMEENGINE_H
