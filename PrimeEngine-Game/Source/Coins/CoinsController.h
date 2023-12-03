#pragma once

namespace Application
{
    class CoinsController
    {
    public:
        CoinsController() = default;
        ~CoinsController() = default;
        
        void SpawnCoin();
        void RenderCoins();
        void TickCoins();
    };
    
}


