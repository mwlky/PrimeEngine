#pragma once
#include "Managers/SpriteManager.h"

namespace Application
{
    struct PlayerAnimationPack
    {
        std::vector<SDL_Texture*> WalkDownTextures;
        std::vector<SDL_Texture*> WalkRightTextures;
        std::vector<SDL_Texture*> WalkLeftTextures;
        std::vector<SDL_Texture*> WalkUpTextures;
    };
    
    class PlayerAnimations
    {
    public:
        PlayerAnimationPack GetPlayerAnimationPack()
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

            PlayerAnimationPack animations{
                walkDownAnimations,
                WalkRightAnimations,
                WalkLeftAnimations,
                WalkUpAnimations
            };

            return animations;
        }
    };
}
