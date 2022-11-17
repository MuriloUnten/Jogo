#include "Enemy.hpp"

namespace Entities
{
    namespace MovingEntities
    {
        Enemy::Enemy(const std::string fileName, sf::Vector2f size, sf::Vector2f position, int hp):
        Character(fileName, size, position, hp)
        {

            vel = sf::Vector2f(100.0f, 0.0f);
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
            updateTimeCollision();

            update();
        }
    }// namespace MovingEntities
}// namespace Entities