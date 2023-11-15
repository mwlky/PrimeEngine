#ifndef PRIMEENGINE_PRIMEENGINE_H
#define PRIMEENGINE_PRIMEENGINE_H

#include "SDL2/SDL.h"
#include <iostream>

namespace Prime {

    class PrimeEngine {

    public:
        PrimeEngine();

        void StartTicking(void(*tick)(float));

    private:
        SDL_Window* m_Window = nullptr;
        SDL_Renderer* m_Renderer = nullptr;
        int m_TickCounter = 0;
        bool m_IsRunning;
    };

}

#endif //PRIMEENGINE_PRIMEENGINE_H
