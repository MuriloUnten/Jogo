#include "Archer.hpp"

namespace Entities 
{
    namespace MovingEntities
    {
        Archer::Archer( const std::string fileName, sf::Vector2f size, sf::Vector2f position, int hp, Player* player, Arrow* arrow):
        Enemy(Eplayer, fileName, size, position)
        {
            attacktime = TIME_ARCHER;
            pPlayer = player;
            pArrow = arrow;
        }

        Archer::Archer():
        Enemy()
        {
            attacktime = TIME_ARCHER;
            pPlayer = NULL;
            pArrow = NULL;
        }

        Archer::~Archer()
        {
            pPlayer = NULL;
            pArrow = NULL;
        }

        bool Archer::alcancePlayer()
        {
            float distanceY = fabs( pPlayer->getPos().y - getPos().y);

            if(distanceY <= 50.f)
            {
                return true;
            }
            else
            {
                return false;
            }

        }

        void Archer::execute()
        {
    
            if(attacktime == TIME_ARCHER && alcancePlayer())
            {
                float deltaH = pPlayer->getPos().y - getPos().y;
                float deltaX = pPlayer->getPos().x - getPos().x;
                float time = abs(pPlayer->getPos().x - getPos().y) / ARROW_VELOCITYX;

                float vy;
                if (deltaH < 0)
                {
                    vy = -(deltaH + GRAVITY * time * time / 2) / time; 
                }
                else
                {
                    vy = -(-deltaH + GRAVITY * time * time / 2) / time;
                }

                sf::Vector2f pos = getPos()+ getSize();
                if(deltaX > 0)
                {
                    pArrow->shoot(pos, sf::Vector2f(ARROW_VELOCITYX, vy));
                }
                else
                {
                     pArrow->shoot(pos, sf::Vector2f(-ARROW_VELOCITYX, vy));
                }
                
                
            }

            if( attacktime < TIME_ARCHER)
            {
                attacktime -= Managers::GraphicsManager::getDeltaTime();
                if(attacktime <= 0.f)
                {
                    attacktime = TIME_ARCHER;
                }
            }

            update();
        }
        
    }//namespace MovingEntities
}//namespace Entities