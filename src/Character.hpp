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

            bool walking;
            bool canAttack;
            bool attacking;
            bool canJump;
            bool jumping;

        public:
            Character(const std::string fileName, sf::Vector2f size, sf::Vector2f position, int health=3, int newDamage=1);
            Character();
            ~Character();

            virtual void execute() = 0;

            void takeDamage(const int damageTaken=1);
            const int getHp() const;

            const int getDamage() const;

            const bool isAttacking() const;

            void setCanJump(const bool jump);
        };

    }// namespace MovingEntities
}// namespace Entities
