#include "Enemy1.hpp"


namespace Entities
{
    namespace MovingEntities
    {
        Enemy1::Enemy1(const std::string fileName, sf::Vector2f size, sf::Vector2f position, int hp):
        Enemy(Eenemy1,fileName, size, position, hp)
        {
            attackTimer->setLimit(ENEMY1_ATTACK_COOLDOWN);
        }


        void Enemy1::execute()
        { 
            float dt = Managers::GraphicsManager::getDeltaTime();
            collisionTimer->update(dt);
            attackTimer->update(dt);


            update();
        }
    }// namespace MovingEntities
}// namespace Entities