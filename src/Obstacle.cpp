#include "Obstacle.hpp"

namespace Entities
{
    namespace StaticEntities
    {
        Obstacle::Obstacle(ID id, const std::string fileName, sf::Vector2f size, sf::Vector2f position, int newSlow):
        Entity(id, fileName, size, position)
        {
            slow = newSlow;
            buoyancy = -GRAVITY;
        }


        Obstacle::Obstacle():
        Entity()
        {
            slow = 0;
            buoyancy = -GRAVITY;
        }


        Obstacle::~Obstacle()
        {
            
        }

        const bool Obstacle::getDamage() // TODO arrumar
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
            float dt = pGraphics->getDeltaTime();

            vel.y += dt * buoyancy;
            update();
        }

    }// namespace Staticentities
}// namespace Entities
