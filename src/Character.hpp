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
            int hp;

        public:
            Character(const std::string fileName, sf::Vector2f size, sf::Vector2f position, int hp=3);
            Character();
            ~Character();

            virtual void execute() = 0;
            void update(const double dt, sf::Vector2f newVel=sf::Vector2f(0,0));

            void takeDamage(const int damage=1);

        };

    }// namespace MovingEntities
}// namespace Entities