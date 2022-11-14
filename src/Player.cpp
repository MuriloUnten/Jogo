#include "Player.hpp"

#include <math.h>

namespace Entities
{
    namespace MovingEntities
    {
        Player::Player(const std::string fileName, sf::Vector2f size, sf::Vector2f position, int hp):
        Character(fileName, size, position, hp)
        {

        }


        Player::Player()
        {
            hp = 3;
        }


        Player::~Player()
        {

        }


        void Player::execute()
        { 
            std::cout << "X: " << pos.x << "   Y: " << pos.y << std::endl;
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
                    vel.y = -1000;
                    jumping = true;
                    canJump = false;
                }
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                vel.x = -350;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                vel.x = 350;
            }
            else
            {
                vel.x = 0;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                vel.y += 4000 * pGraphics->getDeltaTime();
            }

            update();

        }

    }// namespace MovingEntities
}// namespace Entities

