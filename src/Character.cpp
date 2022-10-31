#include "Character.hpp"


namespace Entities
{
    namespace MovingEntities
    {
        Character::Character(const std::string fileName, sf::Vector2f size, sf::Vector2f position, int hp):
        Entity(fileName, size, position)
        {
            vel = sf::Vector2f(0, 0);
            acc = sf::Vector2f(0, 0);
        }


        Character::~Character()
        {

        }


        void Character::update(const double dt, sf::Vector2f newVel)
        {
            vel.x = newVel.x;
            vel.y = newVel.y + GRAVITY * dt;

            pos.x += vel.x * dt;
            pos.y += vel.y * dt;
        }


    }// namespace MovingEntities
}// namespace Entities