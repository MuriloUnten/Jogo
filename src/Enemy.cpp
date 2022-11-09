#include "Enemy.hpp"

namespace Entities
{
    namespace MovingEntities
    {
        Enemy::Enemy(const std::string fileName, sf::Vector2f size, sf::Vector2f position, int hp):
        Character(fileName, size, position, hp)
        {

        }


        Enemy::Enemy()
        {
            hp = 1;
        }


        Enemy::~Enemy()
        {

        }


        void Enemy::execute()
        { 

        }

    }// namespace MovingEntities
}// namespace Entities