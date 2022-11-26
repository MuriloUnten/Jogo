#include "Archer.hpp"
#include "Player.hpp"


namespace Entities 
{
    namespace MovingEntities
    {
        Archer::Archer(const std::string fileName, sf::Vector2f size, sf::Vector2f position, int hp, Player* player):
        Enemy(Earcher, fileName, size, position, hp),
        pArrow(new Arrow())
        {
            pPlayer = player;
            vel = sf::Vector2f(0.0f, 0.0f);
            attackTimer->setLimit(ARCHER_ATTACK_COOLDOWN);
        
        }


        Archer::Archer():
        Enemy(),
        pArrow(new Arrow())
        {
            pPlayer = NULL;
            pArrow = NULL;
            vel = sf::Vector2f(0.0f, 0.0f);
            attackTimer->setLimit(ARCHER_ATTACK_COOLDOWN);
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

            if(distanceY <= 120.0f)
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
            float dt = Managers::GraphicsManager::getDeltaTime();
            attackTimer->update(dt);

            if(pPlayer != NULL)
            {
                if(attackTimer->getElapsedTime() == attackTimer->getLimit() && alcancePlayer())
                {
                    float deltaH = (pPlayer->getPos().y + pPlayer->getSize().y/2) - (getPos().y + getSize().y/2);
                    float deltaX = (pPlayer->getPos().x + pPlayer->getSize().x/2) - (getPos().x + getSize().y/2);
                    float time = fabs(deltaX) / ARROW_VELOCITYX;

                    float vy;
                    vy = (deltaH + (-GRAVITY * time * time / 2)) / time; 

                    sf::Vector2f pos = getPos() + getSize()/2.0f;
                    
                    if(deltaX > 0)
                        pArrow->shoot(pos, sf::Vector2f(ARROW_VELOCITYX, vy));
                    else
                        pArrow->shoot(pos, sf::Vector2f(-ARROW_VELOCITYX, vy));
                }

                if( attackTimer->getElapsedTime() == attackTimer->getLimit())
                    attackTimer->restart();

            }

            update();
        }

        void Archer::affectPlayer(MovingEntities::Player* player)        
        {
            
        }
    }//namespace MovingEntities
}//namespace Entities