#include "CoinsController.h"

#include "Coin.h"

namespace Application
{
    static std::vector<Coin*> coins;
    
    void CoinsController::SpawnCoin()
    {
        Coin* coin = new Coin("C:/Users/damia/OneDrive/Pulpit/PrimeEngine/PrimeEngine-Game/Assets/Coins/MonedaD.png", Prime::Vector2().Zero());
        coins.push_back(coin);
    }

    void CoinsController::RenderCoins()
    {
        for (auto& coin : coins)
        {
            coin->Render();
        }
    }

    void CoinsController::TickCoins()
    {
        for (auto& coin : coins)
        {
            coin->Tick();
        }
    }
}
