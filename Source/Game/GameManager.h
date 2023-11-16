#ifndef PRIMEENGINE_GAMEMANAGER_H
#define PRIMEENGINE_GAMEMANAGER_H

namespace Application {

    class GameManager {
    public:
        void Init();

    private:
        static void Tick();
        void Start();
    };

} // Application

#endif //PRIMEENGINE_GAMEMANAGER_H
