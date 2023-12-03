#include "PrimeEngine.h"

namespace Prime
{
    PrimeEngine::PrimeEngine()
    {
        m_IsRunning = true;
    }

    void PrimeEngine::CreateWindow(const char* title, int xPos, int yPos, int width, int height)
    {
        m_Window = new Window(title, xPos, yPos, width, height);
    }

    void PrimeEngine::Clear()
    {
        SDL_DestroyWindow(m_Window->CurrentWindow);
        delete m_Window;

        std::cout << "Game cleaned" << std::endl;
    }

    void PrimeEngine::InvokeKeyDownEvents()
    {
        if (m_Event.type != SDL_KEYDOWN)
        {
            return;
        }

        KeyDownEvent event;
        
        switch (m_Event.key.keysym.sym)
        {
        case SDLK_e:
            event.KeyCode = KeyCode::E;
            SEND_KEY_EVENT(event);
            
        }
    }

    void PrimeEngine::InvokeKeyUpEvents()
    {
        if (m_Event.type != SDL_KEYUP)
        {
            return;
        }

        KeyUpEvent event;

        switch (m_Event.key.keysym.sym)
        {
        case SDLK_e:
            event.KeyCode = KeyCode::E;
            SEND_KEY_EVENT(event);
        }
    }

    void PrimeEngine::HandleEvents()
    {
        SDL_PollEvent(&m_Event);

        // Important on Linux!
        // The SDL_MOUSEMOTION Eventtracker slows down everything by A LOT on linux.
        // We can still track mouseposition with functions, so don't worry about it too much.
        // My theory is, that it just tracks IF you move the mouse.
        SDL_EventState(SDL_MOUSEMOTION, SDL_IGNORE);

        switch (m_Event.type)
        {
        case SDL_QUIT:
            {
                m_IsRunning = false;
            }
        }

        InvokeKeyDownEvents();
        InvokeKeyUpEvents();
    }

    void PrimeEngine::InitEngine(const TickFunction& tick, const StartFunction& startFunction,
                                 const RenderFunction& renderFunction)
    {
        Uint32 frameStart;
        double frameTime;

        startFunction();

        while (m_IsRunning)
        {
            frameStart = SDL_GetTicks();

            if (SDL_RenderClear(Window::Renderer) != 0)
            {
                std::cerr << "Renderer error" << SDL_GetError() << std::endl;
                break;
            }

            HandleEvents();
            tick();
            renderFunction();
            SDL_SetRenderDrawColor(Window::Renderer, 150, 150, 185, 255);

            SDL_RenderPresent(Prime::Window::Renderer);

            frameTime = SDL_GetTicks() - frameStart;

            if (frameDelay > frameTime)
            {
                SDL_Delay(frameDelay - frameTime);
            }
        }
        
        Clear();
    }
} // Prime
