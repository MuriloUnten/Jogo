#include "Player.hpp"

#include <math.h>

namespace Entities
{
    namespace MovingEntities
    {
        Player::Player(const std::string fileName, sf::Vector2f size, sf::Vector2f position, int hp):
        Character(Eplayer, fileName, size, position, hp),
        controls(this)        
        {
            facingRight = true;
            attackTimer->setLimit(PLAYER_ATTACK_COOLDOWN);
            controls.setKeys("W", "A", "S", "D", "Space");
        }


        Player::Player():
        Character(),
        controls(this)
        {
            hp = 3;
            facingRight = true;
            attackTimer->setLimit(PLAYER_ATTACK_COOLDOWN);
        }


        Player::~Player()
        {

        }


        void Player::execute()
        { 
            float dt = Managers::GraphicsManager::getDeltaTime();
            collisionTimer->update(dt);

            // TODO Rever
            if(walking)
            {
                if(facingRight)
                    vel.x = 350.0f;
                else
                    vel.x = -350.0f;
            }
            else
                vel.x = 0;

            update();
        }

        void Player::jump()
        {
            if(canJump)
            {
                vel.y = -600;
                jumping = true;
                canJump = false;
            }
        }


        void Player::move(bool right)
        {
            walking = true;
            facingRight = right;
        }


        void Player::moveDown()
        {
            vel.y += 4000 * Managers::GraphicsManager::getDeltaTime();
        }


        void Player::attack()
        {
            attacking = true;
        }


        void Player::stopWalking(bool side)
        {
            if(side == facingRight)
            walking = false;
        }


        void Player::stopAttacking()
        {
                attacking = false;
        }

    }// namespace MovingEntities
}// namespace Entities

