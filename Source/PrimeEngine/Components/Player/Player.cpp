#include "Player.h"

namespace Prime {
    Player::Player(const char* playerSprite) {
        Entity entity;

        m_Entity = entity;
        m_Entity.AddComponent<Transform>();
        m_Sprite = m_Entity.AddComponent<Sprite>(playerSprite);
    }

    void Player::TickPlayer() {
        m_Entity.TickComponents();
        HandlePlayerInput();
    }

    void Player::HandlePlayerInput() {
        //TODO: Player Input
    }
} // Prime