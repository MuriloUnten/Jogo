#include "MovingEntity.hpp"

namespace Entities
{
    namespace MovingEntities
    {
        MovingEntity::MovingEntity(ID id, const std::string fileName, sf::Vector2f size, sf::Vector2f position, int newdamage):
        Entity(id, fileName, size, position)
        {
            
        }


        MovingEntity::MovingEntity()
        {

        }


        MovingEntity::~MovingEntity()
        {

        }


        void MovingEntity::setFacingRight(const bool isFacingRight)
        {
            facingRight = isFacingRight;
        }


        const bool MovingEntity::getFacingRight() const
        {
            return facingRight;
        }


    }// namespace MovingEntities
}// namespace Entities