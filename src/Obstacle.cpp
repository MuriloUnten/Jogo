#include "Obstacle.hpp"

namespace Entities
{
    namespace StaticEntities
    {
        Obstacle::Obstacle(ID id, const std::string fileName, sf::Vector2f size, sf::Vector2f position, float newSlow):
        Entity(id, fileName, size, position)
        {
            Odamage = false;
            slow = newSlow;
            buoyancy = -GRAVITY;
        }


        Obstacle::Obstacle():
        Entity()
        {
            Odamage = false;
            slow = 0;
            buoyancy = -GRAVITY;
        }


        Obstacle::~Obstacle()
        {
            
        }

        const bool Obstacle::getDamage() 
        {
            return Odamage;
        }


        void Obstacle::setSlow(const float newSlow)
        {
            slow = newSlow;
        }


        const float Obstacle::getSlow() const
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
