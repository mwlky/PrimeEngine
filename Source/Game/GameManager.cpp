#include "GameManager.h"
#include <iostream>
#include <chrono>
#include "../PrimeEngine/PrimeEngine.h"

#define LOG(X) std::cout<< X << std::endl;

namespace Application {

    void GameManager::Run() {

        Prime::PrimeEngine* primeEngine;
        primeEngine->StartTicking(GameManager::Tick);

        Start();
    }

    void GameManager::Start() {

    }

    void GameManager::Tick(float deltaTime) {
        LOG(deltaTime);
    }
}