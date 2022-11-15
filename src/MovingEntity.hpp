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
            int damage;

        public:
            MovingEntity(const std::string fileName, sf::Vector2f size, sf::Vector2f position, int newdamage=1);
            MovingEntity();
            ~MovingEntity();

            virtual void execute() = 0;
            void update();

            void setVel(sf::Vector2f velocity);
            sf::Vector2f getVel();
        };

    }// namespace MovingEntities
}// namespace Entities