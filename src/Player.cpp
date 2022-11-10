#include "Player.hpp"


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
            // TODO Rever
            if(vel.x != 0 && !jumping)
                walking = true;
            else
                walking = false;

            if(vel.y != 0)
            {
                jumping = true;
                canJump = false;
            }
            else
            {
                jumping = false;
                canJump = true;
            }

            draw();
            // Provisory test for keys pressed. TODO Remove
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                attacking = true;
                std::cout<<"apertou:"<<canAttack<<std::endl;
            }
            else
                attacking = false;

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            {
                hitBox->move(sf::Vector2f(0, -1));
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                hitBox->move(sf::Vector2f(-1, 0));
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                hitBox->move(sf::Vector2f(0, 1));
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                hitBox->move(sf::Vector2f(1, 0));
            }

        }
        
        bool Player::isAttacking()
        {
            return attacking;
        }

    }// namespace MovingEntities
}// namespace Entities

