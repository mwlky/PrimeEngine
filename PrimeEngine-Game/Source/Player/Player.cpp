#include "Player.h"

using namespace Prime;

namespace Application
{
    Player::Player(PlayerAnimationPack animation_pack, Vector2 startPosition)
    {
        Entity entity;

        m_Entity = entity;
        m_Transform = m_Entity.AddComponent<Transform>();
        m_Sprite = m_Entity.AddComponent<Sprite>(animation_pack.WalkDownTextures[0]);
        m_Animations = animation_pack;
        
        m_Transform->Position = startPosition;
    }

    void Player::TickPlayer()
    {
        m_Entity.TickComponents();

        const Uint8* keyStates = SDL_GetKeyboardState(NULL);
        
        if (keyStates[SDL_SCANCODE_W])
        {
            m_Transform->Velocity = Vector2().Up() * -1 * m_Speed;
            PlayAnimation(m_Animations.WalkUpTextures, 200);
        }
        else if (keyStates[SDL_SCANCODE_A])
        {
            m_Transform->Velocity = Vector2().Left() * m_Speed;
            PlayAnimation(m_Animations.WalkLeftTextures, 110);
        }
        else if (keyStates[SDL_SCANCODE_S])
        {
            m_Transform->Velocity = Vector2().Down() * -1 * m_Speed;
            PlayAnimation(m_Animations.WalkDownTextures, 200);
        }
        else if (keyStates[SDL_SCANCODE_D])
        {
            m_Transform->Velocity = Vector2().Right() * m_Speed;
            PlayAnimation(m_Animations.WalkRightTextures, 110);
        }
        else
        {
            m_Transform->Velocity = Vector2().Zero();
        }
    }

    void Player::RenderPlayer()
    {
        
    }

    void Player::PlayAnimation(std::vector<SDL_Texture*> animations, float delay)
    {
        Uint32 currentTime = SDL_GetTicks();
        Uint32 frameTime = currentTime - m_LastAnimationTime;

        if (frameTime >= delay)
        {
            m_CurrentAnimationIndex = (m_CurrentAnimationIndex + 1) % animations.size();
            m_LastAnimationTime = currentTime;
        }
        else
        {
            if (m_CurrentAnimationIndex >= animations.size())
            {
                m_CurrentAnimationIndex = 0;
            }
        }

        m_Entity.GetComponent<Sprite>()->ChangeSprite(animations[m_CurrentAnimationIndex]);
    }
} // Prime
