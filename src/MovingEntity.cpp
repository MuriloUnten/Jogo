#include "MovingEntity.hpp"


namespace Entities
{
    namespace MovingEntities
    {
        MovingEntity::MovingEntity()
        {
            vel = sf::Vector2f(0, 0);
            acc = sf::Vector2f(0, 0);
        }


        MovingEntity::~MovingEntity()
        {

        }


        void update(const double dt, sf::Vector2f newAcc)
        {

        }

    }// namespace MovingEntities
}// namespace Entities