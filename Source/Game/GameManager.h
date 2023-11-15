//
// Created by mwlky on 11/12/23.
//

#ifndef PRIMEENGINE_GAMEMANAGER_H
#define PRIMEENGINE_GAMEMANAGER_H

namespace Application {

    class GameManager {
    public:
        void Run();

    private:
        static void Tick(float deltaTime);
        void Start();
    };

} // Application

#endif //PRIMEENGINE_GAMEMANAGER_H
