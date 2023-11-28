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
        
        switch (m_Event.key.keysym.sym)
        {
        case SDLK_w:
            {
                KeyDownEvent keyDownEvent;
                keyDownEvent.KeyCode = KeyCode::W;
                SEND_KEY_EVENT(keyDownEvent);
                break;
            }

        case SDLK_a:
            {
                KeyDownEvent keyDownEvent;
                keyDownEvent.KeyCode = KeyCode::A;
                SEND_KEY_EVENT(keyDownEvent);
                break;
            }
        case SDLK_s:
            {
                KeyDownEvent keyDownEvent;
                keyDownEvent.KeyCode = KeyCode::S;
                SEND_KEY_EVENT(keyDownEvent);
                break;
            }

        case SDLK_d:
            {
                KeyDownEvent keyDownEvent;
                keyDownEvent.KeyCode = KeyCode::D;
                SEND_KEY_EVENT(keyDownEvent);
                break;
            }
        }
    }

    void PrimeEngine::InvokeKeyUpEvents()
    {
        if (m_Event.type != SDL_KEYUP)
        {
            return;
        }
        
        switch (m_Event.key.keysym.sym)
        {
        case SDLK_w:
            {
                KeyUpEvent keyUpEvent;
                keyUpEvent.KeyCode = KeyCode::W;
                SEND_KEY_EVENT(keyUpEvent);
                break;
            }

        case SDLK_a:
            {
                KeyUpEvent keyUpEvent;
                keyUpEvent.KeyCode = KeyCode::A;
                SEND_KEY_EVENT(keyUpEvent);
                break;
            }
        case SDLK_s:
            {
                KeyUpEvent keyUpEvent;
                keyUpEvent.KeyCode = KeyCode::S;
                SEND_KEY_EVENT(keyUpEvent);
                break;
            }

        case SDLK_d:
            {
                KeyUpEvent keyUpEvent;
                keyUpEvent.KeyCode = KeyCode::D;
                SEND_KEY_EVENT(keyUpEvent);
                break;
            }
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

    void PrimeEngine::InitEngine(const PrimeEngine::TickFunction& tick, const PrimeEngine::StartFunction& startFunction,
                                 const PrimeEngine::RenderFunction& renderFunction)
    {
        Uint32 frameStart;
        double frameTime;

        startFunction();

        while (m_IsRunning)
        {
            frameStart = SDL_GetTicks();
            
            SDL_RenderClear(Prime::Window::Renderer);

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
