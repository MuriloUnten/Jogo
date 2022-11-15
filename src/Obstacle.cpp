#include "Obstacle.hpp"

namespace Entities
{
    namespace StaticEntities
    {
        Obstacle::Obstacle(const std::string fileName, sf::Vector2f size, sf::Vector2f position, int newSlow=0):
        Entity(fileName, size, position)
        {
            slow = newSlow;
        }


        Obstacle::Obstacle():
        Entity()
        {
            slow = 0;
        }


        void Obstacle::setSlow(const int newSlow)
        {
            slow = newSlow;
        }


        const int Obstacle::getSlow() const
        {
            return slow;
        }

    }// namespace Staticentities
}// namespace Entities
