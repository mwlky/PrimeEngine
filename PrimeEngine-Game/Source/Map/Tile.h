#pragma once
#include "PrimeEngine.h"

namespace Application
{
    class Tile
    {
    public:
        Tile(const char* texturePath, Prime::Vector2 position)
        {
            m_Texture = Prime::SpriteManager::LoadTexture(texturePath);

            m_Entity.AddComponent<Prime::Transform>(position);
            m_Entity.AddComponent<Prime::Sprite>(m_Texture)->Tick();
        }

    private:
        SDL_Texture* m_Texture = nullptr;
        Prime::Entity m_Entity{};
    };
}


