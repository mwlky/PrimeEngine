#include "Map.h"

#include <iostream>

#include "Tile.h"
#include "Components/Sprite.h"
#include "Managers/SpriteManager.h"

namespace Application
{
    void Map::TickMap()
    {
    }

    void Application::Map::DrawMap()
    {
    }

    void Application::Map::RenderMap()
    {
        Tile* tile = new Tile(
            "C:/Users/damia/OneDrive/Pulpit/PrimeEngine/PrimeEngine-Game/Assets/Map/punyworld-overworld-tileset_0.png",
            Prime::Vector2().Zero());
    }
}
