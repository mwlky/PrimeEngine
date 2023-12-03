#include "CoinsController.h"
#include "Coin.h"
#include "Math/Prandom.h"

namespace Application
{
    CoinsController::CoinsController()
    {
    }

    CoinsController::~CoinsController()
    {
        delete m_Coin;
    }

    void CoinsController::SpawnCoin()
    {
        int randomX = Prime::Math::Prandom::GetRandomIntInRange(0, 670);
        int randomY = Prime::Math::Prandom::GetRandomIntInRange(0, 670);
        
        Prime::Vector2 position = Prime::Vector2(randomX, randomY);

        m_Coin = new Coin("C:/Users/damia/OneDrive/Pulpit/PrimeEngine/PrimeEngine-Game/Assets/Coins/MonedaD.png",
                              position);
    }

    void CoinsController::RenderCoin()
    {
        if(m_Coin == nullptr)
            return;
        
        m_Coin->Render();
    }

    void CoinsController::TickCoin()
    {
        if(m_Coin == nullptr)
        {
            SpawnCoin();
            return;
        }
    
        m_Coin->Tick();
    }

    void CoinsController::DestroyCoin()
    {
        delete m_Coin;
        SpawnCoin();
    }
}
