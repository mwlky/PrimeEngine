#include "GameManager.h"
#include "../PrimeEngine/Math/Vector2.h"

#define LOG(X) std::cout<< X << std::endl;

using namespace Prime;

namespace Application {

    PrimeEngine engine;
    Sprite* testSprite;

    void GameManager::Init() {

        engine.CreateWindow("Game", 0, 0, 1020, 720);
        engine.InitEngine(GameManager::Tick, GameManager::Start, GameManager::Render);
    }

    void GameManager::Start() {

        testSprite = new Sprite("../Assets/Grass1.png");
    }

    void GameManager::Render() {
        testSprite->Draw();
    }

    void GameManager::Tick() {

    }
}