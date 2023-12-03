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
        m_CoinsController.TickCoins();
    }

    void GameManager::Render()
    {
        m_CoinsController.RenderCoins();
        m_PlayerController.Render();
    }
}
