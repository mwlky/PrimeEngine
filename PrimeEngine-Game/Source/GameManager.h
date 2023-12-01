#ifndef PRIMEENGINE_GAMEMANAGER_H
#define PRIMEENGINE_GAMEMANAGER_H

#include "PrimeEngine.h"
#include "Map/Map.h"
#include "Player/PlayerController.h"

namespace Application {

    class GameManager {
    public:
        
        void Init();

    private:
        void Tick();
        void Start();
        void Render();

        Map* m_Map = nullptr;
        
        PlayerController m_PlayerController {};
        Prime::PrimeEngine m_Engine {};

        const int WINDOW_HEIGHT = 720;
        const int WINDOW_WIDTH = 720;
    };

} // Application

#endif //PRIMEENGINE_GAMEMANAGER_H
