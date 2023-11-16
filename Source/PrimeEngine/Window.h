#include "SDL.h"

namespace Prime{

    class Window{

    public:
        Window(const char* title, int xPos, int yPos, int width, int height){
            SDL_Init(SDL_INIT_EVERYTHING);

            m_Window = SDL_CreateWindow(title, xPos, yPos, width, height, 0);

            m_Surface = SDL_GetWindowSurface(m_Window);
        }

        void RenderWindow(){
            SDL_UpdateWindowSurface(m_Window);
        }

        ~Window(){
            SDL_DestroyWindow(m_Window);
            SDL_DestroyRenderer(m_Renderer);
            SDL_Quit();
        }

    private:
        SDL_Window* m_Window = nullptr;
        SDL_Renderer* m_Renderer = nullptr;
        SDL_Surface* m_Surface = nullptr;
    };
}
