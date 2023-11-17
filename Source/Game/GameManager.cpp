#include "GameManager.h"

#define LOG(X) std::cout<< X << std::endl;

namespace Application {

    Prime::PrimeEngine engine;
    Prime::Sprite* testSprite;

    void GameManager::Init() {

        engine.CreateWindow("Game", 0, 0, 1020, 720);
        engine.InitEngine(GameManager::Tick, GameManager::Start, GameManager::Render);
    }

    void GameManager::Start() {

        testSprite = new Prime::Sprite("../Assets/Grass1.png");
    }

    void GameManager::Render() {
        testSprite->Draw();
    }

    void GameManager::Tick() {

    }
}