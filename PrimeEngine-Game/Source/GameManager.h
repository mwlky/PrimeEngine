#ifndef PRIMEENGINE_GAMEMANAGER_H
#define PRIMEENGINE_GAMEMANAGER_H

#include "PrimeEngine.h"
#include "Player/PlayerController.h"

namespace Application {

    class GameManager {
    public:
        void Init();

    private:
        void Tick();
        void Start();
        void Render();

        PlayerController m_PlayerController {};
        Prime::PrimeEngine m_Engine {};
    };

} // Application

#endif //PRIMEENGINE_GAMEMANAGER_H
