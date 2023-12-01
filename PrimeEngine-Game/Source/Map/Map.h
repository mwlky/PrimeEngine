#pragma once
#include <vector>

#include "Tile.h"

namespace Application
{
    class Map
    {
    public:
        Map() = default;

        void TickMap();
        void DrawMap(const int& height, const int& width);
        
    private:
        void RenderMap();
    };
}


