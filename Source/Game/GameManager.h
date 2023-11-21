#ifndef PRIMEENGINE_GAMEMANAGER_H
#define PRIMEENGINE_GAMEMANAGER_H

#include "../PrimeEngine/Core/PrimeEngine.h"

namespace Application {

    class GameManager {
    public:
        void Init();

    private:
        static void Tick();
        static void Start();
        static void Render();
    };

} // Application

#endif //PRIMEENGINE_GAMEMANAGER_H
