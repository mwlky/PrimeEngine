#include "GameManager.h"

#define LOG(X) std::cout<< X << std::endl;

namespace Application {

    Prime::PrimeEngine engine;

    void GameManager::Init() {

        engine.CreateWindow("Game", 0, 0, 1020, 720);
        engine.InitEngine(GameManager::Tick, GameManager::Start);
    }

    void GameManager::Start() {
    }

    void GameManager::Tick() {
    }
}