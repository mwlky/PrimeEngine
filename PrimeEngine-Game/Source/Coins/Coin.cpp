// Coin.cpp
#include "Coin.h"

namespace Application
{
    Coin::~Coin()
    {
        SDL_DestroyTexture(m_Texture);
    }

    Coin::Coin(const char* spritePath, Prime::Vector2 position)
    {
        m_Texture = Prime::SpriteManager::LoadTexture(spritePath);

        if(!m_Texture)
        {
            std::cout << "Failed to load texture:" << SDL_GetError() << std::endl;
        }

        if(SDL_QueryTexture(m_Texture, NULL, NULL, &m_TextureWidth, &m_TextureHeight))
        {
            std::cout << "SDL Query Error:" << SDL_GetError() << std::endl;
        }

        m_SourceRect = { 0,0, 16,16};
        m_DestRect = {187,200, 32,32};
    }

    void Coin::Render()
    {
        Prime::SpriteManager::Draw(m_Texture, m_SourceRect, m_DestRect);
    }

    void Coin::Tick()
    {
        Uint32 currentTime = SDL_GetTicks();
        
        if(currentTime - m_LastFrame > m_FrameDelay)
        {
            m_SourceRect.x = m_CurrentFrame * m_FrameWidth;
            m_CurrentFrame = (m_CurrentFrame + 1) % (m_TextureWidth / m_FrameWidth);
            m_LastFrame = currentTime;
        }
    }
}
