#pragma once
#include "Coin.h"

namespace Application
{
    class CoinsController
    {
    public:
        CoinsController();
        ~CoinsController();
        
        void SpawnCoin();
        void RenderCoin();
        void TickCoin();
        void DestroyCoin();

        Coin* GetCoin() const
        {
            return m_Coin;
        }

    private:
        Coin* m_Coin = nullptr;
        
    };
    
}


