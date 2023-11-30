#include "GameManager.h"

#include "PlayerAnimations.h"
#include "Player/Player.h"

#define LOG(X) std::cout<< X << std::endl

namespace Application
{
    void GameManager::Init()
    {
        m_Engine.CreateWindow("Game", 450, 180, 1020, 720);
        m_Engine.InitEngine([this] { Tick(); },
                            [this] { Start(); },
                            [this] { Render(); });
    }

    void GameManager::Start()
    {
        PlayerAnimations player_animations;
        
        PlayerAnimationPack animations = player_animations.GetPlayerAnimationPack();
        
        m_Player = new Player(animations, Prime::Vector2(500, 400));
    }

    void GameManager::Tick()
    {
        m_Player->TickPlayer();
    }

    void GameManager::Render()
    {
    }
}
