#ifndef PRIMEENGINE_GAMEMANAGER_H
#define PRIMEENGINE_GAMEMANAGER_H

#include "../PrimeEngine/PrimeEngine.h"

namespace Application {

    class GameManager {
    public:
        void Init();

    private:
        static void Tick();
        static void Start();
    };

} // Application

#endif //PRIMEENGINE_GAMEMANAGER_H
