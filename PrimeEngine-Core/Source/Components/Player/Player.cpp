#include "Player.h"

namespace Prime
{
    Player::Player(const char* playerSprite)
    {
        Entity entity;

        m_Entity = entity;
        m_Transform = m_Entity.AddComponent<Transform>();
        m_Sprite = m_Entity.AddComponent<Sprite>(playerSprite);

        ADD_KEY_EVENT_LISTENER(KeyEvents::KeyDown, Player::MovePlayer, this);
        
        ADD_KEY_EVENT_LISTENER(KeyEvents::KeyUp, Player::StopPlayer, this);
    }

    void Player::TickPlayer()
    {
        m_Entity.TickComponents();
    }

    void Player::MovePlayer(const Event<KeyEvents>& event)
    {
        const KeyDownEvent key = event.ToType<KeyDownEvent>();

        if (key.KeyCode == KeyCode::W)
        {
            m_Transform->Velocity = Vector2().Up() * -1 * m_Speed;
        }
        if (key.KeyCode == KeyCode::A)
        {
            m_Transform->Velocity = Vector2().Left() * m_Speed;
        }
        if (key.KeyCode == KeyCode::S)
        {
            m_Transform->Velocity = Vector2().Down() * -1 * m_Speed;
        }
        if (key.KeyCode == KeyCode::D)
        {
            m_Transform->Velocity = Vector2().Right() * m_Speed;
        }
    }

    void Player::StopPlayer(const Event<KeyEvents>& event)
    {
        KeyUpEvent key = event.ToType<KeyUpEvent>();

        if (key.KeyCode == KeyCode::W)
        {
            m_Transform->Velocity = Vector2().Zero();
        }
        if (key.KeyCode == KeyCode::A)
        {
            m_Transform->Velocity = Vector2().Zero();
        }
        if (key.KeyCode == KeyCode::S)
        {
            m_Transform->Velocity = Vector2().Zero();
        }
        if (key.KeyCode == KeyCode::D)
        {
            m_Transform->Velocity = Vector2().Zero();
        }
    }
} // Prime
