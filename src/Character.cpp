#include "Character.hpp"


namespace Entities
{
    namespace MovingEntities
    {
        Character::Character(const std::string fileName, sf::Vector2f size, sf::Vector2f position, int health):
        MovingEntity(fileName, size, position)
        {
            hp = health;
        }


        Character::Character():
        MovingEntity()
        {
            hp = 3;
        }


        Character::~Character()
        {

        }



    }// namespace MovingEntities
}// namespace Entities