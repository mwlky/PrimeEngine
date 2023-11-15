#include "GameManager.h"
#include "../PrimeEngine/PrimeEngine.h"

#define LOG(X) std::cout<< X << std::endl;

namespace Application {

    void GameManager::Init() {

        Prime::PrimeEngine primeEngine;

        primeEngine.CreateWindow("Game", 0, 0, 500, 500);
        primeEngine.StartTicking(GameManager::Tick);

        Start();
    }

    void GameManager::Start() {

    }

    void GameManager::Tick(float deltaTime) {
        LOG("tick");
    }
}