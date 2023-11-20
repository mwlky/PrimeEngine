#include "Player.h"

namespace Prime {
    Player::Player(const char *playerSprite) {
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

        if (Prime::PrimeEngine::m_Event.type == SDL_KEYDOWN) {
            switch (Prime::PrimeEngine::m_Event.key.keysym.sym) {
                case SDLK_w:
                    std::cout << "Move up" << std::endl;
                    break;

                case SDLK_a:
                    std::cout << "Move left" << std::endl;
                    break;

                case SDLK_s:
                    std::cout << "Move down" << std::endl;
                    break;

                case SDLK_d:
                    std::cout << "Move right" << std::endl;
                    break;

                default:
                    break;
            }
        }

    }
} // Prime