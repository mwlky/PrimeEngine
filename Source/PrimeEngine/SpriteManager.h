#ifndef PRIMEENGINE_SPRITEMANAGER_H
#define PRIMEENGINE_SPRITEMANAGER_H

#include "SDL.h"
#include <vector>

namespace Prime {

    class SpriteManager {

    public:
        SDL_Texture* LoadTexture(const char* filePath);
        void Draw(SDL_Texture *texture, SDL_Renderer* renderer, SDL_Rect sourcePosition, SDL_Rect destinationPosition);

    private:
        std::vector<SDL_Texture *> m_Textures;

    };

} // PrimeEngine

#endif //PRIMEENGINE_SPRITEMANAGER_H
