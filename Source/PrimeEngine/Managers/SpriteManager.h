#ifndef PRIMEENGINE_SPRITEMANAGER_H
#define PRIMEENGINE_SPRITEMANAGER_H

#include "SDL.h"
#include "SDL_image.h"
#include <vector>

namespace Prime {

    class SpriteManager {

    public:
        static SDL_Texture* LoadTexture(const char* filePath);
        static void Draw(SDL_Texture *texture, SDL_Rect destinationPosition);

    private:
        std::vector<SDL_Texture *> m_Textures;

    };

} // PrimeEngine

#endif //PRIMEENGINE_SPRITEMANAGER_H
