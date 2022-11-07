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

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            {
                hitBox->move(sf::Vector2f(0, -3));
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                hitBox->move(sf::Vector2f(-3, 0));
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                hitBox->move(sf::Vector2f(0, 3));
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                hitBox->move(sf::Vector2f(3, 0));
            }

            draw();
        }

    }// namespace MovingEntities
}// namespace Entities

