#include "GameManager.h"

#define LOG(X) std::cout<< X << std::endl;

namespace Application
{
    Prime::PrimeEngine engine;
    Prime::Player* player;

    void GameManager::Init()
    {
        engine.CreateWindow("Game", 450, 180, 1020, 720);
        engine.InitEngine(Tick, Start, Render);
    }

    void GameManager::Start()
    {
        Prime::PlayerAnimationPack animations = GetPlayerAnimationPack();
        player = new Prime::Player(animations, Prime::Vector2(500,400));
    }

    void GameManager::Render()
    {
    }

    Prime::PlayerAnimationPack GameManager::GetPlayerAnimationPack()
    {
        Prime::SpriteManager spriteManager;

        std::vector walkDownAnimations{
            spriteManager.LoadTexture("../PrimeEngine-Game/Assets/Player/WalkDown/Archer-Green_2.png"),
            spriteManager.LoadTexture("../PrimeEngine-Game/Assets/Player/WalkDown/Archer-Green_3.png"),
        };

        std::vector WalkRightAnimations{
            spriteManager.LoadTexture("../PrimeEngine-Game/Assets/Player/WalkRight/Archer-Green_50.png"),
            spriteManager.LoadTexture("../PrimeEngine-Game/Assets/Player/WalkRight/Archer-Green_49.png"),
            spriteManager.LoadTexture("../PrimeEngine-Game/Assets/Player/WalkRight/Archer-Green_51.png")
        };

        std::vector WalkLeftAnimations{
            spriteManager.LoadTexture("../PrimeEngine-Game/Assets/Player/WalkLeft/Archer-Green_146.png"),
            spriteManager.LoadTexture("../PrimeEngine-Game/Assets/Player/WalkLeft/Archer-Green_147.png"),
            spriteManager.LoadTexture("../PrimeEngine-Game/Assets/Player/WalkLeft/Archer-Green_148.png")

        };

        std::vector WalkUpAnimations{
            spriteManager.LoadTexture("../PrimeEngine-Game/Assets/Player/WalkUp/Archer-Green_103.png"),
            spriteManager.LoadTexture("../PrimeEngine-Game/Assets/Player/WalkUp/Archer-Green_104.png"),

        };

        Prime::PlayerAnimationPack animations{
            walkDownAnimations,
            WalkRightAnimations,
            WalkLeftAnimations,
            WalkUpAnimations
        };

        return animations;
    }

    void GameManager::Tick()
    {
        player->TickPlayer();
    }
}
