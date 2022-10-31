#include "Player.hpp"


namespace Entities
{
    namespace MovingEntities
    {
        Player::Player(const std::string fileName, sf::Vector2f size, sf::Vector2f position, int hp):
        Character(fileName, size, position, hp)
        {

        }


        Player::~Player()
        {

        }


        void Player::execute()
        {

        }

    }// namespace MovingEntities
}// namespace Entities

