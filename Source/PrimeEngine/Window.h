#include "SDL.h"

namespace Prime{

    class Window{

    public:
        Window(const char* title, int xPos, int yPos, int width, int height);
        void RenderWindow();

        ~Window();

        static SDL_Window* CurrentWindow;
        static SDL_Renderer* Renderer;

    private:
        SDL_Surface* m_Surface = nullptr;
        SDL_Window* m_Window = nullptr;
        SDL_Renderer* m_Renderer = nullptr;
    };
}
