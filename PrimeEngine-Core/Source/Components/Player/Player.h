#ifndef PRIMEENGINE_PLAYER_H
#define PRIMEENGINE_PLAYER_H

#include "../Components.h"
#include "../../PrimeEngine.h"
#include "../../Events/Event.h"
#include "../../Events/EventHandler.h"

namespace Prime {
    
    struct PlayerAnimationPack
    {
        std::vector<SDL_Texture*> WalkDownTextures;
        std::vector<SDL_Texture*> WalkRightTextures;
        std::vector<SDL_Texture*> WalkLeftTextures;
        std::vector<SDL_Texture*> WalkUpTextures;
    };
    
    class Player {
    public:
        Player(PlayerAnimationPack animation_pack, Vector2 startPosition);

        void TickPlayer();
        void RenderPlayer();
        
    private:

        void PlayAnimation(std::vector<SDL_Texture*> animations, float delay);

        int m_CurrentAnimationIndex = 0;
        int m_Speed = 5;

        float m_LastAnimationTime = 0;

        Transform* m_Transform = nullptr;
        Sprite* m_Sprite = nullptr;

        PlayerAnimationPack m_Animations {};
        Entity m_Entity {};
    };

} // Prime

#endif //PRIMEENGINE_PLAYER_H
