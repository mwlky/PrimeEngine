#include "SDL.h"
#include <SDL_image.h>
#include <SDL_ttf.h>

namespace Prime{

    class Window{

    public:
        Window(const char* title, int xPos, int yPos, int width, int height);

        ~Window();

        static SDL_Window* CurrentWindow;
        static SDL_Renderer* Renderer;

    private:
        SDL_Surface* m_Surface = nullptr;
        SDL_Window* m_Window = nullptr;
        SDL_Renderer* m_Renderer = nullptr;
    };
}
