#pragma once
#include <SDL_ttf.h>
#include <iostream>

namespace Prime
{
    class UILabel
    {
    public:
        UILabel(const std::string& path, int fontSize);
        ~UILabel();
        
        void DrawLabel(const std::string& text, int x, int y, SDL_Color color);

    private:
        void CleanUp();
        
        TTF_Font* m_Font = nullptr;
    };
}


