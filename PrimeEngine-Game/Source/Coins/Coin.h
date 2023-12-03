#pragma once
#include "PrimeEngine.h"

namespace Application
{
    class Coin
    {
    public:
        Coin() = default;
        ~Coin();
        
        Coin(const char* spritePath, Prime::Vector2 position);

        void Render();
        void Tick();

    private:
        SDL_Texture* m_Texture = nullptr;
        SDL_Rect m_SourceRect;
        SDL_Rect m_DestRect;

        int m_FrameWidth = 16;
        int m_TextureWidth = 80;
        int m_TextureHeight = 16;

        int m_CurrentFrame {};
        int m_FrameDelay {75};
        Uint32 m_LastFrame {};
    };
}


