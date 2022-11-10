#include "Enemy.hpp"

namespace Entities
{
    namespace MovingEntities
    {
        Enemy::Enemy(const std::string fileName, sf::Vector2f size, sf::Vector2f position, int hp):
        Character(fileName, size, position, hp)
        {
            damage=1;
        }


        Enemy::Enemy()
        {
            hp = 1;
            damage= 1;
        }


        Enemy::~Enemy()
        {

        }


        void Enemy::execute()
        { 

        }


        int Enemy::takeDamage(){
            hp-=1;
        }

        int Enemy::getDamage(){

            return damage;
        }
        int Enemy::getHp(){

            return hp;
        }

    }// namespace MovingEntities
}// namespace Entities