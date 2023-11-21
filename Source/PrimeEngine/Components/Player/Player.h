#ifndef PRIMEENGINE_PLAYER_H
#define PRIMEENGINE_PLAYER_H

#include "../Components.h"
#include "../../Core/PrimeEngine.h"
#include "../../Events/Event.h"
#include "../../Events/EventHandler.h"

namespace Prime {

    class Player {
    public:
        Player(const char* playerSprite);

        void TickPlayer();
        void RenderPlayer();

//        void Test(const Event<MouseEvents>& event);

    private:
        void HandlePlayerInput();

        Entity m_Entity;
        Sprite* m_Sprite = nullptr;
    };

} // Prime

#endif //PRIMEENGINE_PLAYER_H
