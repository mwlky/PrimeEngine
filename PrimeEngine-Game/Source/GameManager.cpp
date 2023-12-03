#include "GameManager.h"

#define LOG(X) std::cout<< X << std::endl

namespace Application
{
    void GameManager::Init()
    {
        m_Engine.CreateWindow("Game", 450, 180, WINDOW_WIDTH, WINDOW_HEIGHT);
        m_Engine.InitEngine([this] { Tick(); },
                            [this] { Start(); },
                            [this] { Render(); });

        m_Map = new Map();
    }

    void GameManager::Start()
    {
        m_Map->DrawMap(WINDOW_HEIGHT, WINDOW_WIDTH);
        m_CoinsController.SpawnCoin();
        
        m_PlayerController.Init();
    }

    void GameManager::Tick()
    {
        m_Map->TickMap();
        m_PlayerController.Tick();
        m_CoinsController.TickCoin();
        HandleCollisions();
    }

    void GameManager::Render()
    {
        m_CoinsController.RenderCoin();
        m_PlayerController.Render();
    }

    void GameManager::HandleCollisions()
    {
        Prime::Transform* playerTransform = m_PlayerController.GetPlayer()->GetEntity()->GetComponent<Prime::Transform>();
        
        int playerX = playerTransform->Position.x;
        int playerY = playerTransform->Position.y;

        int coinX = m_CoinsController.GetCoin()->GetPosition().x;
        int coinY =  m_CoinsController.GetCoin()->GetPosition().y;

        int positionXDif = Prime::Math::Clamp::ClampValue(coinX - playerX, 100, -100);

        int positionYDif = Prime::Math::Clamp::ClampValue(coinY - playerY, 100, -100);
        
        if(positionXDif <= 35 && positionXDif >= -5 && positionYDif <= 50 && positionYDif >= -1)
        {
            m_CoinsController.DestroyCoin();
        }
    }
}
