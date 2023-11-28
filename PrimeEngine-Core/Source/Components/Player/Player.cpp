#include "Player.h"

namespace Prime {
    Player::Player(const char *playerSprite) {
        Entity entity;

        m_Entity = entity;
        m_Entity.AddComponent<Transform>();
        m_Sprite = m_Entity.AddComponent<Sprite>(playerSprite);

        ADD_KEY_EVENT_LISTENER(KeyEvents::KeyDown, Player::MovePlayer, this);        
    }

    void Player::TickPlayer() {
        m_Entity.TickComponents();
    }

    void Player::MovePlayer(const Event<KeyEvents>& event)
    {
        KeyDownEvent key = event.ToType<KeyDownEvent>();

        switch (key.KeyCode)
        {
        case KeyCode::W:
            std::cout << "Moving player up" << std::endl;
            break;
            
        case KeyCode::A:
            std::cout << "Moving player left" << std::endl;
            break;

        case KeyCode::S:
            std::cout << "Moving player down" << std::endl;
            break;

        case KeyCode::D:
            std::cout << "Moving player right" << std::endl;
            break;
        }
    }
} // Prime