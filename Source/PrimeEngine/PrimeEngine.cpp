
#include "PrimeEngine.h"

namespace Prime {
    PrimeEngine::PrimeEngine() {

    }

    void PrimeEngine::StartTicking(void (*tick)()) {

        const int FPS = 60;
        const int frameDelay = 1000/ FPS;

        Uint32 frameStart;
        double frameTime;

        while (true){

            frameStart = SDL_GetTicks();

            if(m_Window != nullptr){
                m_Window->RenderWindow();
            }

            tick();

            frameTime = SDL_GetTicks() - frameStart;

            if(frameDelay > frameTime){
                SDL_Delay(frameDelay - frameTime);
            }
        }
    }

    void PrimeEngine::CreateWindow(const char *title, int xPos, int yPos, int width, int height) {
        m_Window = new Window(title, xPos, yPos, width, height);
    }
} // Prime