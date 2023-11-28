#ifndef PRIMEENGINE_SPRITE_H
#define PRIMEENGINE_SPRITE_H

#include "SDL.h"
#include "../Managers/SpriteManager.h"
#include "Components.h"
#include "Transform.h"

namespace Prime {

    class Sprite: public Component {

    public:
        Sprite(const char *texturePath) {
            m_Texture = SpriteManager::LoadTexture(texturePath);

            m_TextureRect.x = 0;
            m_TextureRect.y = 0;
            m_TextureRect.w = m_TextureRect.h = 128;
        }

        void Tick() override {
            m_TextureRect.x = entity->GetComponent<Transform>()->Position.x;
            m_TextureRect.y = entity->GetComponent<Transform>()->Position.y;
            
            SpriteManager::Draw(m_Texture, m_TextureRect);
        }

    private:

        SDL_Texture *m_Texture;
        SDL_Rect m_TextureRect;
    };

}

#endif //PRIMEENGINE_SPRITE_H
