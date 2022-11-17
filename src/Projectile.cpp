#include "Projectile.hpp"

namespace Entities
{
    namespace MovingEntities
    {
        Projectile::Projectile(const std::string fileName, sf::Vector2f size, sf::Vector2f position, int newdamage):
        MovingEntity(fileName, size, position)
        {
            discard = true;
        }

        Projectile::Projectile():
        MovingEntity()
        {
            discard = true;
        }
        Projectile::~Projectile()
        {

        }

        bool Projectile::getDiscard()
        {
            return discard;
        }

        void Projectile::setDiscard( bool condition)
        {
            discard = condition;
        }


        void  Projectile::shoot(sf::Vector2f newPos, sf::Vector2f newVel)
        {
            setPos(newPos);
            setVel(newVel);
            discard = false;
        }

    }//namespace MovingEntities
}//Entities