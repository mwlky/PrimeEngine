#include "Window.h"

#include <iostream>

SDL_Renderer *Prime::Window::Renderer = nullptr;
SDL_Window *Prime::Window::CurrentWindow = nullptr;

Prime::Window::Window(const char *title, int xPos, int yPos, int width, int height) {
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(SDL_INIT_EVERYTHING);
    TTF_Init();

    m_Window = SDL_CreateWindow(title, xPos, yPos, width, height, SDL_WINDOW_SHOWN);
    if (m_Window) {
        m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        m_Surface = SDL_GetWindowSurface(CurrentWindow);

        if(m_Renderer == nullptr)
        {
            std::cerr << "Unable to create renderer: " << SDL_GetError() << std::endl;
            return;
        }

        Renderer = m_Renderer;
        CurrentWindow = m_Window;

        SDL_SetRenderDrawColor(m_Renderer, 255, 255, 255, 255);
    }
}

Prime::Window::~Window() {
    SDL_DestroyWindow(CurrentWindow);
    SDL_DestroyRenderer(Renderer);
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}


