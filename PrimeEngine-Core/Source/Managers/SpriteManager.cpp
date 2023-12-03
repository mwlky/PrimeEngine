#include "SpriteManager.h"
#include "../Window.h"
#include "iostream"

namespace Prime {
    SDL_Texture *SpriteManager::LoadTexture(const char *filePath) {

        SDL_Surface *tempSurface = IMG_Load(filePath);

        if (!tempSurface) {
            std::cerr << "Unable to load image " << filePath << "! SDL_image Error: " << IMG_GetError() << std::endl;
            return nullptr;
        }

        SDL_Texture *texture = SDL_CreateTextureFromSurface(Window::Renderer, tempSurface);

        if (!texture) {
            std::cerr << "Unable to create texture from " << filePath << "! SDL Error: " << SDL_GetError() << std::endl;
            return nullptr;
        }
        SDL_FreeSurface(tempSurface);


        return texture;
    }

    void SpriteManager::Draw(SDL_Texture *texture, SDL_Rect destinationPosition) {
        if(texture != nullptr){
            SDL_RenderCopy(Window::Renderer, texture, NULL, &destinationPosition);
        } else{
            std::cerr << "No texture find to draw" << std::endl;
        }
    }

    void SpriteManager::Draw(SDL_Texture* texture, SDL_Rect sourceRect, SDL_Rect position)
    {
        if(texture != nullptr){
            SDL_RenderCopy(Window::Renderer, texture, &sourceRect, &position);
        } else{
            std::cerr << "No texture find to draw" << std::endl;
        }
    }
} // PrimeEngine