#include "Map.h"

namespace Application
{
    static std::vector<Tile*> m_Tiles;

    void Map::TickMap()
    {
        for (auto tile : m_Tiles)
        {
            tile->Draw();
        }
    }

    void Map::DrawMap(const int& height, const int& width)
    {
        int targetWidth = width / 64 + 1;
        int targetHeight = height / 64 + 1;
        
        for (int i = 0; i < targetWidth; ++i)
        {
            for (int j = 0; j < targetHeight; ++j)
            {
                int x = 0 + 64 * i;
                int y = 0 + 64 * j;

                Prime::Vector2 position(x, y);

                std::cout << "Started" << std::endl;
                Tile* tile = m_TileGenerator.GetRandomTile(position);
                
                m_Tiles.push_back(tile);
            }
        } 
    }
}
