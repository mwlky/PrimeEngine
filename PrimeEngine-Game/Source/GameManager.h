#ifndef PRIMEENGINE_GAMEMANAGER_H
#define PRIMEENGINE_GAMEMANAGER_H

#include "PrimeEngine.h"

namespace Application {

    class GameManager {
    public:
        void Init();

    private:
        static void Tick();
        static void Start();
        static void Render();

        static Prime::PlayerAnimationPack GetPlayerAnimationPack();
    };

} // Application

#endif //PRIMEENGINE_GAMEMANAGER_H
