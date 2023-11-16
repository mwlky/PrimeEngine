#include "PrimeEngine.h"

namespace Prime {
    PrimeEngine::PrimeEngine() {
        m_IsRunning = true;

        m_SpriteManager = new SpriteManager;
    }

    void PrimeEngine::CreateWindow(const char *title, int xPos, int yPos, int width, int height) {
        m_Window = new Window(title, xPos, yPos, width, height);
    }

    void PrimeEngine::Clear() {

        delete m_Window;

        std::cout << "Game cleaned" << std::endl;
    }

    void PrimeEngine::HandleEvents() {
        SDL_PollEvent(&m_Event);

        switch (m_Event.type) {
            case SDL_QUIT:{
                m_IsRunning = false;
            }
        }
    }

    void PrimeEngine::InitEngine(const PrimeEngine::TickFunction& tick, const PrimeEngine::StartFunction& startFunction) {
        Uint32 frameStart;
        double frameTime;

        startFunction();

        while (m_IsRunning){

            frameStart = SDL_GetTicks();

            if(m_Window != nullptr){
                m_Window->RenderWindow();
            }

            tick();
            HandleEvents();

            frameTime = SDL_GetTicks() - frameStart;

            if(frameDelay > frameTime){
                SDL_Delay(frameDelay - frameTime);
            }
        }

        Clear();
    }
} // Prime