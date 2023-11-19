#ifndef PRIMEENGINE_PLAYER_H
#define PRIMEENGINE_PLAYER_H

#include "../Components.h"
#include "../../PrimeEngine.h"

namespace Prime {

    class Player {
    public:
        Player(const char* playerSprite);

        void TickPlayer();
        void RenderPlayer();

    private:
        void HandlePlayerInput();

        Entity m_Entity;
        Sprite* m_Sprite = nullptr;
    };

} // Prime

#endif //PRIMEENGINE_PLAYER_H
