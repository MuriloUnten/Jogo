#include "Enemy.hpp"

namespace Entities
{
    namespace MovingEntities
    {
        Enemy::Enemy(const std::string fileName, sf::Vector2f size, sf::Vector2f position, int hp):
        Character(fileName, size, position, hp)
        {

            vel = sf::Vector2f(10,0);
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
            /*if((pos.x < 200) || (pos.x > 700) )
            {
                vel.x*=-1;
            }
            update();*/

        }
    }// namespace MovingEntities
}// namespace Entities