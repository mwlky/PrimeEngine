#pragma once
#include "Coin.h"

namespace Application
{
    class CoinsController
    {
    public:
        CoinsController() = default;
        ~CoinsController();
        
        void SpawnCoin();
        void RenderCoins();
        void TickCoins();

    private:
        Coin* m_Coin;
    };
    
}


