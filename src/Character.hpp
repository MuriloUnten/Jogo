#pragma once

#include "MovingEntity.hpp"
#include "Timer.hpp"


namespace Entities
{
    namespace MovingEntities
    {
        class Character: public MovingEntity
        {
        protected:
            int hp;

            bool walking;
            bool canAttack;
            bool attacking;
            bool canJump;
            bool jumping;
            bool movingInX;

            Timer* collisionTimer;
            Timer* attackTimer;

        public:
            Character(ID id, const std::string fileName, sf::Vector2f size, sf::Vector2f position, int health=3, int newDamage=1);
            Character();
            ~Character();

            virtual void execute() = 0;

            void takeDamage(const int damageTaken=1);
            const int getHp() const;

            const int getDamage() const;

            const bool isAttacking() const;

            void setCanJump(const bool jump);

            Timer* getCollisionTimer() const;
            Timer* getAttackTimer() const;
        };

    }// namespace MovingEntities
}// namespace Entities
