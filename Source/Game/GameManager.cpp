#include "GameManager.h"

#define LOG(X) std::cout<< X << std::endl;

using namespace Prime;

namespace Application {

    PrimeEngine engine;
    Player* player;

    void GameManager::Init() {

        engine.CreateWindow("Game", 0, 0, 1020, 720);
        engine.InitEngine(GameManager::Tick, GameManager::Start, GameManager::Render);
    }

    void GameManager::Start() {
        player = new Player("../Assets/Grass1.png");
    }

    void GameManager::Render() {

    }

    void GameManager::Tick() {
        player->TickPlayer();
    }
}