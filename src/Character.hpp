#pragma once

#include "Entity.hpp"

namespace Entities
{
    namespace MovingEntities
    {
        class Character: public Entity
        {
        protected:
            sf::Vector2f vel;
            sf::Vector2f acc;
        
        public:
            Character(const std::string fileName, sf::Vector2f size, sf::Vector2f position, int hp=3);
            ~Character();

            virtual void execute() = 0;
            void update(const double dt, sf::Vector2f newVel=sf::Vector2f(0,0));

        };

    }// namespace MovingEntities
}// namespace Entities