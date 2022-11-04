#pragma once

#include "Entity.hpp"

namespace Entities
{
    namespace MovingEntities
    {
        class MovingEntity: public Entity
        {
        protected:
            sf::Vector2f vel;
            sf::Vector2f acc;
        
        public:
            MovingEntity();
            ~MovingEntity();

            virtual void execute() = 0;
            void update(const double dt, sf::Vector2f newAcc=sf::Vector2f(0,0));
            void Collide(Entity* otherEntity, Math::Coordinate intersect)=0;

        };

    }// namespace MovingEntities
}// namespace Entities