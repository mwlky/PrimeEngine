#pragma once

#include "TileGenerator.h"

namespace Application
{
    class Map
    {
    public:
        Map() = default;

        void TickMap();
        void DrawMap(const int& height, const int& width);

    private:
        TileGenerator m_TileGenerator;
    };
}


