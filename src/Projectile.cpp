#include "Projectile.hpp"

namespace Entities
{
    namespace MovingEntities
    {
        Projectile::Projectile(const std::string fileName, sf::Vector2f size, sf::Vector2f position, int newdamage):
        MovingEntity(fileName, size, position)
        {
            executable = false;
        }

        Projectile::Projectile():
        MovingEntity()
        {
            executable = false;
        }


        Projectile::~Projectile()
        {

        }


        void  Projectile::shoot(sf::Vector2f newPos, sf::Vector2f newVel)
        {
            std::cout << "Atirando flecha\n";
            executable = true;
            setPos(newPos);
            setVel(newVel);
        }

    }// namespace MovingEntities
}// namespace Entities