#include "PlayerController.h"

#include "Helpers/Log.h"

namespace Application
{
    
    PlayerController::PlayerController()
    {
    }

    PlayerController::~PlayerController()
    {
        delete m_Player;
    }

    void PlayerController::Init()
    {
        PlayerAnimations playerAnimations;
        PlayerAnimationPack animations = playerAnimations.GetPlayerAnimationPack();
        
        m_Player = new Player(animations, Prime::Vector2(500, 400));
    }

    void PlayerController::Tick()
    {
        m_Player->TickPlayer();
    }

    void PlayerController::Render()
    {
        m_Player->RenderPlayer();
    }
}
