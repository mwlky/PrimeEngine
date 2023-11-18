#ifndef PRIMEENGINE_SPRITE_H
#define PRIMEENGINE_SPRITE_H

#include "SDL.h"
#include "../Managers/SpriteManager.h"
#include "Components.h"

namespace Prime {

    class Sprite: public Component {

    public:
        Sprite(const char *texturePath) {
            m_Texture = SpriteManager::LoadTexture(texturePath);



            m_TextureRect.x = 510;
            m_TextureRect.y = 360;
            m_TextureRect.w = m_TextureRect.h = 128;
        }

        void Draw() override {
            SpriteManager::Draw(m_Texture, m_TextureRect);
        }

    private:

        SDL_Texture *m_Texture;
        SDL_Rect m_TextureRect;

    };

}

#endif //PRIMEENGINE_SPRITE_H
