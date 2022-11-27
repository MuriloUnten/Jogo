#include "Enemy1.hpp"
#include "Player.hpp"


namespace Entities
{
    namespace MovingEntities
    {
        Enemy1::Enemy1(const std::string fileName, sf::Vector2f size, sf::Vector2f position, int hp):
        Enemy(Eenemy1,fileName, size, position, hp)
        {
            attackTimer->setLimit(ENEMY1_ATTACK_COOLDOWN);
        }


        Enemy1::~Enemy1()
        {
            
        }


        void Enemy1::execute()
        { 
            float dt = Managers::GraphicsManager::getDeltaTime();
            collisionTimer->update(dt);
            attackTimer->update(dt);


            update();
        }


        void Enemy1::affectPlayer(MovingEntities::Player* player)
        {
            
        }
    }// namespace MovingEntities
}// namespace Entities