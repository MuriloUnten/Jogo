#include "Character.hpp"

#define TIMECOLLISON 0.3

namespace Entities
{
    namespace MovingEntities
    {
        Character::Character(ID id, const std::string fileName, sf::Vector2f size, sf::Vector2f position, int health, int newDamage):
        MovingEntity(id, fileName, size, position),
        collisionTimer(new Timer(TIMECOLLISON)),
        attackTimer(new Timer())
        {
            hp = health;
            damage = newDamage;
            canJump = true;
            Id = id;
        }


        Character::Character():
        MovingEntity(),
        collisionTimer(new Timer(TIMECOLLISON)),
        attackTimer(new Timer())
        {
            hp = 3;
            damage = 1;
            canJump = true;
            Id = Eempty;
        }


        Character::~Character()
        {
            delete collisionTimer;
        }


        const int Character::getHp() const
        {
            return hp;
        }

        void Character::takeDamage(const int damageTaken)
        {
            hp -= damageTaken;
            std::cout<< "hp: "<<hp<<std::endl;
        }

        


        const bool Character::isAttacking() const
        {
            return attacking;
        }


        void Character::setCanJump(const bool jump)
        {
            canJump = jump;
        }


        Timer* Character::getCollisionTimer() const
        {
            return collisionTimer;
        }


        Timer* Character::getAttackTimer() const
        {
            return attackTimer;
        }
    }// namespace MovingEntities
}// namespace Entities