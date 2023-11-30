#include "GameManager.h"

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
        m_PlayerController.Init();
    }

    void GameManager::Tick()
    {
        m_PlayerController.Tick();
    }

    void GameManager::Render()
    {
        m_PlayerController.Render();
    }
}
