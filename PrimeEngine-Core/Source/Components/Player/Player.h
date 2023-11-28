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
        void StopPlayer(const Event<KeyEvents>& event);
        
    private:
        int m_Speed = 5;
        
        Entity m_Entity {};
        Sprite* m_Sprite = nullptr;
        Transform* m_Transform = nullptr;
    };

} // Prime

#endif //PRIMEENGINE_PLAYER_H
