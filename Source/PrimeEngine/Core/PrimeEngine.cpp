#include "PrimeEngine.h"
#include "../Events/EventHandler.h"

namespace Prime {

    SDL_Event Prime::PrimeEngine::m_Event;

    PrimeEngine::PrimeEngine() {
        m_IsRunning = true;
    }

    void PrimeEngine::CreateWindow(const char *title, int xPos, int yPos, int width, int height) {
        m_Window = new Window(title, xPos, yPos, width, height);
    }

    void PrimeEngine::Clear() {

        SDL_DestroyWindow(m_Window->CurrentWindow);
        delete m_Window;

        std::cout << "Game cleaned" << std::endl;
    }

    void PrimeEngine::HandleEvents() {
        SDL_PollEvent(&m_Event);

        // Important on Linux!
        // The SDL_MOUSEMOTION Eventtracker slows down everything by A LOT on linux.
        // We can still track mouseposition with functions, so don't worry about it too much.
        // My theory is, that it just tracks IF you move the mouse.
        SDL_EventState(SDL_MOUSEMOTION, SDL_IGNORE);

        switch (m_Event.type) {
            case SDL_QUIT:{
                m_IsRunning = false;
            }
//            case SDL_KEYDOWN:
//                if(m_Event.key.keysym.sym){
//                    MouseButtonDownEvent mouseButtonDownEvent;
//                    mouseButtonDownEvent.Button = 2;
//                    SEND_MOUSE_EVENT(mouseButtonDownEvent);
//                }
//                break;
        }
    }

    void PrimeEngine::InitEngine(const PrimeEngine::TickFunction &tick, const PrimeEngine::StartFunction &startFunction,
                                 const PrimeEngine::RenderFunction &renderFunction) {
        Uint32 frameStart;
        double frameTime;

        startFunction();

        while (m_IsRunning){

            frameStart = SDL_GetTicks();

            SDL_RenderClear(Prime::Window::Renderer);

            HandleEvents();
            tick();
            renderFunction();

            SDL_RenderPresent(Prime::Window::Renderer);

            frameTime = SDL_GetTicks() - frameStart;

            if(frameDelay > frameTime){
                SDL_Delay(frameDelay - frameTime);
            }
        }

        Clear();
    }
} // Prime