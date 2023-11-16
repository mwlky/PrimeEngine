#include "SpriteManager.h"

namespace Prime {
    SDL_Texture *SpriteManager::LoadTexture(const char *filePath) {

//        m_Textures.push_back()

        return nullptr;
    }

    void SpriteManager::Draw(SDL_Texture *texture, SDL_Renderer* renderer ,SDL_Rect sourcePosition, SDL_Rect destinationPosition) {

        SDL_RenderCopy(renderer, texture, &sourcePosition, &destinationPosition);
    }
} // PrimeEngine