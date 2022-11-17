#include "Character.hpp"


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
        }


        Character::Character():
        MovingEntity()
        {
            hp = 3;
            damage = 1;
            canJump = true;
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

    }// namespace MovingEntities
}// namespace Entities