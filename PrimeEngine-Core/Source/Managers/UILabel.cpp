#include "UILabel.h"

#include "Window.h"

namespace Prime
{
    UILabel::UILabel(const std::string& path, int fontSize) : m_Font(nullptr)
    {
        if(TTF_Init() == -1)
        {
            std::cerr << "TTF Init failed: " << TTF_GetError() << std::endl;
        }

        m_Font = TTF_OpenFont(path.c_str(), fontSize);
        if(!m_Font)
        {
            std::cerr << "Failed opening font: " << TTF_GetError() << std::endl;
        }
    }

    void UILabel::DrawLabel(const std::string& text, int x, int y, SDL_Color color)
    {
        if(!m_Font)
        {
            std::cerr << "UILabel not initialized!" << std::endl;
            return;
        }

        SDL_Surface* surface = TTF_RenderText_Solid(m_Font, text.c_str(), color);
        if(!surface)
        {
            std::cerr << "TTF_RenderTextSolid failed: " << TTF_GetError() << std::endl;
            return;
        }

        SDL_Texture* texture = SDL_CreateTextureFromSurface(Window::Renderer, surface);
        if(!texture)
        {
            std::cerr << "SDL_CreateTextureFromSurface failed" << SDL_GetError() << std::endl;
            SDL_FreeSurface(surface);
            return;
        }

        SDL_Rect destRect = { x, y, surface->w, surface->h };
        SDL_RenderCopy(Window::Renderer, texture, nullptr, &destRect);

        SDL_DestroyTexture(texture);
        SDL_FreeSurface(surface);
    }

    void UILabel::CleanUp()
    {
        TTF_CloseFont(m_Font);
        TTF_Quit();
    }
}
