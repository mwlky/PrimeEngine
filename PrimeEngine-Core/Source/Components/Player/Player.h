#ifndef PRIMEENGINE_PLAYER_H
#define PRIMEENGINE_PLAYER_H

#include "../Components.h"
#include "../../PrimeEngine.h"
#include "../../Events/Event.h"
#include "../../Events/EventHandler.h"

namespace Prime {

    class Player {
    public:
        Player(const char* playerSprite);

        void TickPlayer();
        void RenderPlayer();

        void MovePlayer(const Event<KeyEvents>& event);

    private:
        
        
        Entity m_Entity;
        Sprite* m_Sprite = nullptr;
    };

} // Prime

#endif //PRIMEENGINE_PLAYER_H
