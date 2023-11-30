#ifndef PRIMEENGINE_GAMEMANAGER_H
#define PRIMEENGINE_GAMEMANAGER_H

#include "PlayerAnimations.h"
#include "PrimeEngine.h"
#include "Player/Player.h"

namespace Application {

    class GameManager {
    public:
        void Init();

    private:
        void Tick();
        void Start();
        void Render();

        Player* m_Player = nullptr;
        Prime::PrimeEngine m_Engine {};
        
    };

} // Application

#endif //PRIMEENGINE_GAMEMANAGER_H
