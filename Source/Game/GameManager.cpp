#include "GameManager.h"
#include "../PrimeEngine/Math/Vector2.h"

#define LOG(X) std::cout<< X << std::endl;

using namespace Prime;

namespace Application {

    PrimeEngine engine;
    Entity entity;

    void GameManager::Init() {

        engine.CreateWindow("Game", 0, 0, 1020, 720);
        engine.InitEngine(GameManager::Tick, GameManager::Start, GameManager::Render);
    }

    void GameManager::Start() {
        entity.AddComponent<Sprite>("../Assets/Grass1.png");
    }

    void GameManager::Render() {

    }

    void GameManager::Tick() {
        entity.TickComponents();
    }
}