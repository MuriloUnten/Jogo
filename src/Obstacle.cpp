#include "Obstacle.hpp"

namespace Entities
{
    namespace StaticEntities
    {
        Obstacle::Obstacle(const std::string fileName, sf::Vector2f size, sf::Vector2f position, int newDamage, int newSlow):
        Entity(fileName, size, position)
        {
            damage = newDamage;
            slow = newSlow;
        }


        Obstacle::Obstacle():
        Entity()
        {
            damage = 0;
            slow = 0;
        }


        void Obstacle::setDamage(const int newDamage)
        {
            damage = newDamage;
        }


        const int Obstacle::getDamage() const
        {
            return damage;
        }


        void Obstacle::setSlow(const int newSlow)
        {
            slow = newSlow;
        }


        const int Obstacle::getSlow() const
        {
            return slow;
        }


        void Obstacle::execute()
        {
            draw();
        }

    }// namespace Staticentities
}// namespace Entities
