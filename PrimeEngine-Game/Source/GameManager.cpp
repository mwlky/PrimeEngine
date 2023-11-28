#include "GameManager.h"

#define LOG(X) std::cout<< X << std::endl;

namespace Application {

    Prime::PrimeEngine engine;
    Prime::Player* player;

    void GameManager::Init() {

        engine.CreateWindow("Game", 450 , 180, 1020, 720);
        engine.InitEngine(Tick, Start, Render);
    }

    void GameManager::Start() {
        player = new Prime::Player("../PrimeEngine-Game/Assets/Grass1.png");
    }

    void GameManager::Render() {

    }

    void GameManager::Tick() {
        player->TickPlayer();
    }
}