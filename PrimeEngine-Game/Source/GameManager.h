#ifndef PRIMEENGINE_GAMEMANAGER_H
#define PRIMEENGINE_GAMEMANAGER_H

#include "PrimeEngine.h"
#include "Coins/CoinsController.h"
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
        void HandleCollisions();
        void Clean();

        Map* m_Map = nullptr;

        Prime::UILabel* m_Label = new Prime::UILabel(
            "../../PrimeEngine/PrimeEngine-Game/Assets/Fonts/PixelFonts/PixelEmulator-xq08.ttf",
            25);
        
        CoinsController m_CoinsController {};
        PlayerController m_PlayerController {};
        Prime::PrimeEngine m_Engine {};

        const int WINDOW_HEIGHT = 720;
        const int WINDOW_WIDTH = 720;

        int m_PointsNumber = 0;
    };

} // Application

#endif //PRIMEENGINE_GAMEMANAGER_H
