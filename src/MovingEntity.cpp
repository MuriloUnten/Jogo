#include "MovingEntity.hpp"

namespace Entities
{
    namespace MovingEntities
    {
        MovingEntity::MovingEntity(ID id, const std::string fileName, sf::Vector2f size, sf::Vector2f position, int newdamage):
        Entity(id, fileName, size, position)
        {
            facingRight = true;
        }


        MovingEntity::MovingEntity()
        {
            facingRight = true;
        }


        MovingEntity::~MovingEntity()
        {

        }

        const int MovingEntity::getDamage() const
        {
            return damage;
        }

        void MovingEntity::setFacingRight(const bool isFacingRight)
        {
            facingRight = isFacingRight;
            //hitBox->scale(-1,1);
        }



        const bool MovingEntity::getFacingRight() const
        {
            return facingRight;
        }


        void MovingEntity::flipImage()
        {
            float posX = pos.x;
            hitBox->scale(-1, 1);
            setPos(sf::Vector2f(pos.x + (pos.x - posX)/2, pos.y));
        }


    }// namespace MovingEntities
}// namespace Entities