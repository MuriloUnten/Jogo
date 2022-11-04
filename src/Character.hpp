#pragma once

#include "MovingEntity.hpp"


namespace Entities
{
    namespace MovingEntities
    {
        class Character: public MovingEntity
        {
        protected:
            int hp;

        public:
            Character(const std::string fileName, sf::Vector2f size, sf::Vector2f position, int health=3);
            Character();
            ~Character();

            void takeDamage(const int damage=1);

        };

    }// namespace MovingEntities
}// namespace Entities
