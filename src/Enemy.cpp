#include "Enemy.hpp"

namespace Entities
{
    namespace MovingEntities
    {
        Enemy::Enemy(ID id, const std::string fileName, sf::Vector2f size, sf::Vector2f position, int hp):
        Character(id, fileName, size, position, hp)
        {

            vel = sf::Vector2f(100.0f, 0.0f);
            damage=1;
            punctuationPlayer = 100;
        }


        Enemy::Enemy():
        Character()
        {
            hp = 1;
            damage= 1;
        }


        Enemy::~Enemy()
        {

        }

        const int Enemy::getPonctuation() const
        {
            return punctuationPlayer;
        }
    }// namespace MovingEntities
}// namespace Entities