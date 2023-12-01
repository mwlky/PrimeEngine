#pragma once
#include "Player.h"

namespace Application
{
    class PlayerController
    {
    public:
        PlayerController();
        ~PlayerController();

        Player* GetPlayer() const
        {
            return m_Player;
        }

        void Init();
        void Tick();
        void Render();

    private:
        Player* m_Player = nullptr;
    };
}
