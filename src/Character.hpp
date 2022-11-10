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
            int damage;

        public:
            Character(const std::string fileName, sf::Vector2f size, sf::Vector2f position, int health=3, int newDamage=1);
            Character();
            ~Character();

            void takeDamage(const int damageTaken=1);
            const int getHp() const;

            const int getDamage() const;
        
        };

    }// namespace MovingEntities
}// namespace Entities
