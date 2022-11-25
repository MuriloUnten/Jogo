#include "Obstacle.hpp"

namespace Entities
{
    namespace StaticEntities
    {
        Obstacle::Obstacle(ID id, const std::string fileName, sf::Vector2f size, sf::Vector2f position):
        Entity(id, fileName, size, position)
        {
            Odamage = false;
            buoyancy = -GRAVITY;
        }


        Obstacle::Obstacle():
        Entity()
        {
            Odamage = false;
            buoyancy = -GRAVITY;
        }


        Obstacle::~Obstacle()
        {
            
        }

        const bool Obstacle::getBoolDamage() 
        {
            return Odamage;
        }

        void Obstacle::execute()
        {
            float dt = pGraphics->getDeltaTime();

            vel.y += dt * buoyancy;
            update();
        }

    }// namespace Staticentities
}// namespace Entities
