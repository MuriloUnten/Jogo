#include "Archer.hpp"

namespace Entities 
{
    namespace MovingEntities
    {
        Archer::Archer(const std::string fileName, sf::Vector2f size, sf::Vector2f position, int hp, Player* player):
        Enemy(Earcher, fileName, size, position),
        pArrow(new Arrow())
        {
            attackTime = TIME_ARCHER;
            pPlayer = player;
            vel = sf::Vector2f(0.0f, 0.0f);
        }


        Archer::Archer():
        Enemy()
        {
            attackTime = TIME_ARCHER;
            pPlayer = NULL;
            pArrow = NULL;
            vel = sf::Vector2f(0.0f, 0.0f);
        }


        Archer::~Archer()
        {
            pPlayer = NULL;
            pArrow = NULL;
        }


        void Archer::setPlayer(Player* player)
        {
            pPlayer = player;
        }


        Arrow* Archer::getArrow() const
        {
            return pArrow;
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
            if(pPlayer != NULL)
            {
                if(attackTime == TIME_ARCHER && alcancePlayer())
                {
                    float deltaH = pPlayer->getPos().y - getPos().y;
                    float deltaX = pPlayer->getPos().x - getPos().x;
                    float time = abs(pPlayer->getPos().y - getPos().y) / ARROW_VELOCITYX;

                    float vy;
                    
                    if (deltaH < 0)
                        vy = -(deltaH + GRAVITY * time * time / 2) / time; 
                    else
                        vy = -(-deltaH + GRAVITY * time * time / 2) / time;

                    sf::Vector2f pos = getPos() + getSize();
                    
                    if(deltaX > 0)
                        pArrow->shoot(pos, sf::Vector2f(ARROW_VELOCITYX, vy));
                    else
                        pArrow->shoot(pos, sf::Vector2f(-ARROW_VELOCITYX, vy));
                    
                }

                if( attackTime < TIME_ARCHER)
                {
                    attackTime -= Managers::GraphicsManager::getDeltaTime();
                    if(attackTime <= 0.0f)
                    {
                        attackTime = TIME_ARCHER;
                    }
                }
            }

            update();
        }
        
    }//namespace MovingEntities
}//namespace Entities