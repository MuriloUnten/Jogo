#include "Projectile.hpp"

namespace Entities
{
    namespace MovingEntities
    {
        Projectile::Projectile(ID id, const std::string fileName, sf::Vector2f size, sf::Vector2f position, int newdamage):
        MovingEntity(id, fileName, size, position)
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
            std::cout << "Atirando projetil Vy = " << newVel.y << std::endl;
            executable = true;
            setPos(newPos);
            setVel(newVel);
        }

    }// namespace MovingEntities
}// namespace Entities