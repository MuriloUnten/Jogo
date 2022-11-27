#include "Boss.hpp"

#define BOSS_ATTACKING_PATH "../assets/inimigos/boss_attack.png"
#define BOSS_RUN_PATH "../assets/inimigos/Boss_Run.png"
#define LIMITE_Y 100.0f

namespace Entities
{
    namespace MovingEntities
    {
        Boss::Boss(const std::string fileName, sf::Vector2f size, sf::Vector2f position, int hp, Player* player1, Player* player2):
        Enemy(Eboss, fileName, size, position, hp)
        {
            pPlayer1 = player1;
            pPlayer2 = player2;
            attackTimer->setLimit(BOSS_ATTACK_COOLDOWN);
            attackAnimationTimer->setLimit(BOSS_ANIMATION_TIME);
        }
        Boss::~Boss()
        {

        }

        void Boss::setPlayer1(Player* player)
        {
            pPlayer1 = player;
        }

        void Boss::setPlayer2(Player* player)
        {
            pPlayer2 = player;
        }

        void Boss::execute()
        {
             bool alcance1 ,alcance2;

            float dy1 = pPlayer1->getPos().y - pos.y;
            float dx1 = pPlayer1->getPos().x - pos.x;
            
            if(dy1 <= LIMITE_Y)
                alcance1 = true;
            else 
                alcance1 = false;
           
            if(pPlayer1 != NULL && pPlayer2 != NULL )
            {
               
                float dy2 = pPlayer2->getPos().y - pos.y;
                if(dy2 <= LIMITE_Y)
                    alcance2 = true;
                else 
                    alcance2 = false;

                float dx2 = pPlayer2->getPos().x - pos.x;
                //follow player 1

                if( (fabs(dx1) < fabs(dx2)) && alcance1)
                {
                    if(dx1 > 0)
                    {
                        vel.x = 200.0f;
                    }
                    else
                    {
                        vel.x = -200.0f;
                    }
                }
                //follow player 2
                else if (alcance2)
                {
                    if(dx2 > 0)
                    {
                        vel.x = 200.0f;
                    }
                    else
                    {
                        vel.x = -200.0f;
                    }
                }
            }
            //Player 1
            else
            {
                if(alcance1)
                {
                    if(dx1 > 0)
                    {
                        vel.x = 200.0f;
                    }
                    else
                    {
                        vel.x = -200.0f;
                    }
                }
            }
            
            // Updating timers
            float dt = Managers::GraphicsManager::getDeltaTime();
            collisionTimer->update(dt);
            attackTimer->update(dt);
            attackAnimationTimer->update(dt);
            
            // Checks if it's attacking and sets texture accordingly
            if(attackAnimationTimer->getElapsedTime() == attackAnimationTimer->getLimit())
            {
                attacking = false;
                loadTexture(BOSS_RUN_PATH);
            }
            else
            {
                attacking = true;
                loadTexture(BOSS_ATTACKING_PATH);
            }
            hitBox->setTexture(texture);

            update();
        }


        void Boss::affectPlayer(MovingEntities::Player* player)
        {
            
        }

    }//namespace MovingEntities

}//namespace Entities