#include "Character.hpp"

#define TIMECOLLISON 0.3

namespace Entities
{
    namespace MovingEntities
    {
        Character::Character(const std::string fileName, sf::Vector2f size, sf::Vector2f position, int health, int newDamage):
        MovingEntity(fileName, size, position)
        {
            hp = health;
            damage = newDamage;
            canJump = true;
    		timeCollision = TIMECOLLISON;

        }


        Character::Character():
        MovingEntity()
        {
            hp = 3;
            damage = 1;
            canJump = true;
    		timeCollision = TIMECOLLISON;
        }


        Character::~Character()
        {

        }


        void Character::takeDamage(const int damageTaken)
        {
            hp -= damageTaken;
            std::cout<< "hp: "<<hp<<std::endl;
        }


        const int Character::getHp() const
        {
            return hp;
        }


        const int Character::getDamage() const
        {
            return damage;
        }


        const bool Character::isAttacking() const
        {
            return attacking;
        }


        void Character::setCanJump(const bool jump)
        {
            canJump = jump;
        }


        void Character::updateTimeCollision()
        {
            timeCollision -= Managers::GraphicsManager::getDeltaTime();
            if(timeCollision <= 0.0f)
                timeCollision = -1.0f;
        }


        void Character::restartTimeCollision()
        {
            timeCollision = TIMECOLLISON;
        }


        float Character::getTimeCollision() const 
        {
            return timeCollision;
        }



    }// namespace MovingEntities
}// namespace Entities