#pragma once
#include "Tile.h"
#include "Math/Prandom.h"

namespace Application
{
    class TileGenerator
    {
    public:
        TileGenerator() = default;
        
        Tile* GetRandomTile(Prime::Vector2 position) const
        {
            std::vector tilePaths{
                "../../PrimeEngine/PrimeEngine-Game/Assets/Map/punyworld-overworld-tileset_0.png",
                "../../PrimeEngine/PrimeEngine-Game/Assets/Map/punyworld-overworld-tileset_1.png",
                "../../PrimeEngine/PrimeEngine-Game/Assets/Map/punyworld-overworld-tileset_22.png",
                "../../PrimeEngine/PrimeEngine-Game/Assets/Map/punyworld-overworld-tileset_23.png",
                "../../PrimeEngine/PrimeEngine-Game/Assets/Map/punyworld-overworld-tileset_24.png",
            };
            
            int min = 0;
            int max = tilePaths.size();
            
            int random = Prime::Math::Prandom::GetRandomIntInRange(min, max - 1);
            
            const char* path = tilePaths[random];

            return new Tile(path, position);
        }

    };
}
