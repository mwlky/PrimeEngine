#ifndef PRIMEENGINE_PLAYER_H
#define PRIMEENGINE_PLAYER_H


#include "PlayerAnimations.h"
#include "Components/Sprite.h"
#include "Components/Transform.h"
#include "Math/Vector2.h"

namespace Application {
    
    class Player {
    public:
        Player(Application::PlayerAnimationPack animation_pack, Prime::Vector2 startPosition);

        void TickPlayer();
        void RenderPlayer();
        
    private:

        void PlayAnimation(std::vector<SDL_Texture*> animations, float delay);

        int m_CurrentAnimationIndex = 0;
        int m_Speed = 5;

        float m_LastAnimationTime = 0;

        Prime::Transform* m_Transform = nullptr;
        Prime::Sprite* m_Sprite = nullptr;

        PlayerAnimationPack m_Animations {};
        Prime::Entity m_Entity {};
    };

} // Prime

#endif //PRIMEENGINE_PLAYER_H
