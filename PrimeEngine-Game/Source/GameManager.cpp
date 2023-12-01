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
        m_Map->DrawMap();
        m_PlayerController.Init();
    }

    void GameManager::Tick()
    {
        m_Map->TickMap();
        m_PlayerController.Tick();
    }

    void GameManager::Render()
    {
        m_Map->RenderMap();
        m_PlayerController.Render();
    }
}
