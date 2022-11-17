#include "Obstacle.hpp"

namespace Entities
{
    namespace StaticEntities
    {
        Obstacle::Obstacle(const std::string fileName, sf::Vector2f size, sf::Vector2f position, int newSlow):
        Entity(fileName, size, position)
        {
            slow = newSlow;
            buoancy = -GRAVITY;
        }


        Obstacle::Obstacle():
        Entity()
        {
            slow = 0;
            buoancy = -GRAVITY;
        }


        Obstacle::~Obstacle()
        {
            
        }

        const bool Obstacle::getDamage()
        {
            return Odamage;
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
            float dt = getDT();

            vel.y += dt * buoancy;
            update();
        }

    }// namespace Staticentities
}// namespace Entities
