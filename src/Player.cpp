#include "Player.hpp"

#include <math.h>

namespace Entities
{
    namespace MovingEntities
    {
        Player::Player(const std::string fileName, sf::Vector2f size, sf::Vector2f position, int hp):
        Character(Eplayer, fileName, size, position, hp)
        {
            facingRight = true;
            attackTimer->setLimit(PLAYER_ATTACK_COOLDOWN);
        }


        Player::Player():
        Character()
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
            if(vel.x != 0 && !jumping)
                walking = true;
            else
                walking = false;

            if(vel.y != 0)
            {
                jumping = true;
            }
            else
            {
                jumping = false;
            }

            // Provisory test for keys pressed. TODO Remove
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                attacking = true;
                //std::cout<<"apertou:"<<canAttack<<std::endl;
            }
            else
                attacking = false;

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            {
                if(canJump)
                {
                    vel.y = -600;
                    jumping = true;
                    canJump = false;
                }
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                vel.x = -350;
                facingRight= false;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                vel.x = 350;
                facingRight= true;
            }
            else
            {
                vel.x = 0;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                vel.y += 4000 * dt;
            }

            //std::cout<< "hp Player:"<< hp;
            update();

        }

    }// namespace MovingEntities
}// namespace Entities

