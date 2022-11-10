#include "CollisionManager.hpp"

namespace Managers
{
    CollisionManager::CollisionManager()
    {

    }
    
    
    CollisionManager::~CollisionManager()
    {
        //delete lists
        playerList.clear();
        enemyList.clear();
        obstacleList.clear();
    }
    
    
    void CollisionManager::Collision()
    {
        /* Talvez ter lista de players, para nao precisar ficar testando muita coisa */

        Entities::StaticEntities::Obstacle *Obstacle1=nullptr;
        Entities::MovingEntities::Enemy *Enemy1= nullptr;

        Math::Coordinate<float> Intersection;
        Math::Coordinate<float> CenterDistance;

        /* Player collision */
        for(int i = 0; i < playerList.getSize(); i++)
        {
            Entities::MovingEntities::Player* pAuxPlayer = playerList[i];
            if(pAuxPlayer == NULL)
                continue;

            /* Collision between Player and Obstacles */
            for(int j = 0; j < obstacleList.getSize(); j++)
            {
                //módulo da distância entre o centro das entidades
                Obstacle1 = obstacleList[j];
                //CenterDistance.x = fabs(pAuxPlayer->getPos().x - Obstacle1->getPos().x);
                //CenterDistance.y = fabs(pAuxPlayer->getPos().y - Obstacle1->getPos().y);
                CenterDistance.x = fabs(pAuxPlayer->getPos().x + pAuxPlayer->getSize().x/2 - (Obstacle1->getPos().x + Obstacle1->getSize().x/2));
                CenterDistance.y = fabs(pAuxPlayer->getPos().y + pAuxPlayer->getSize().y/2 - (Obstacle1->getPos().y + Obstacle1->getSize().y/2));
                Intersection.x = CenterDistance.x - (pAuxPlayer->getSize().x/2 + Obstacle1->getSize().x/2);
                Intersection.y = CenterDistance.y - (pAuxPlayer->getSize().y/2 + Obstacle1->getSize().y/2);
                //distância que as extremidades mais próximas das entidades se econtram  
                //Intersection.x = CenterDistance.x - (pAuxPlayer->getSize().x/2 + Obstacle1->getSize().x/2);
                //Intersection.y = CenterDistance.y - (pAuxPlayer->getSize().y/2 + Obstacle1->getSize().y/2);
                //verifica se houve colisão
                if(Intersection.x < 0 && Intersection.y < 0)
                {
                    CollisionPlayerObstacle(pAuxPlayer, Intersection);
                }
            }

            /* Collision between Player and Enemy */
            for(int j = 0; j < enemyList.getSize(); j++)
            {
                Enemy1 = enemyList[j];
                //módulo da distância entre o centro das entidades
                CenterDistance.x= fabs((pAuxPlayer->getPos().x + pAuxPlayer->getSize().x/2)- (Enemy1->getPos().x + Enemy1->getSize().x/2));
                CenterDistance.y= fabs((pAuxPlayer->getPos().y + pAuxPlayer->getSize().y/2) - (Enemy1->getPos().y + Enemy1->getSize().y/2));
                //distância que as extremidades mais próximas das entidades se econtram
                Intersection.x = CenterDistance.x - (pAuxPlayer->getSize().x/2 + Enemy1->getSize().x/2);
                Intersection.y = CenterDistance.y - (pAuxPlayer->getSize().y/2 + Enemy1->getSize().y/2);
                //verifica se houve colisão
                if(Intersection.x < 0 && Intersection.y < 0)
                {
                    CollisionPlayerEnemy(pAuxPlayer, Enemy1, Intersection);
                }
            }
        }

        /*------------------------------Collision between Obstacle and Enemy---------------------------------------------------------------*/
        for(int i = 0; i < obstacleList.getSize(); i++)
        {
            Obstacle1 = obstacleList[i];
            for(int j = 0; j < enemyList.getSize(); j++)
            {
                Enemy1 = enemyList[j];
                //módulo da distância entre o centro das entidades
                //CenterDistance.x= fabs(Obstacle1->getPos().x - Enemy1->getPos().x);
                //CenterDistance.y= fabs(Obstacle1->getPos().y - Enemy1->getPos().y);
                //distância que as extremidades mais próximas das entidades se econtram  
                //Intersection.x= CenterDistance.x - (Obstacle1->getSize().x/2 + Enemy1->getSize().x/2);
                //Intersection.y= CenterDistance.y - (Obstacle1->getSize().y/2 + Enemy1->getSize().y/2);
                CenterDistance.x = fabs(Enemy1->getPos().x + Enemy1->getSize().x/2 - (Obstacle1->getPos().x + Obstacle1->getSize().x/2));
                CenterDistance.y = fabs(Enemy1->getPos().y + Enemy1->getSize().y/2 - (Obstacle1->getPos().y + Obstacle1->getSize().y/2));
                Intersection.x = CenterDistance.x - (Enemy1->getSize().x/2 + Obstacle1->getSize().x/2);
                Intersection.y = CenterDistance.y - (Enemy1->getSize().y/2 + Obstacle1->getSize().y/2);
                //verifica se houve colisão
                if(Intersection.x < 0 && Intersection.y < 0)
                {
                    CollisionObstacleEnemy( Enemy1, Intersection);
                }
            }
        }
    }

    //altera velocidade na direção que bateu e reposiciona o jogador
    void CollisionManager::CollisionPlayerObstacle(Entities::MovingEntities::Player *Player, Math::CoordF Intersection)
    {
        /* Velocidade em y pode ser > 0 e mesmo assim a colisao ser em x, e vice versa */
        //std::cout << "entrando na CollisionPlayerObstacle\n";

        sf::Vector2f coordinate;
        //collision in the Y direction
        if(Intersection.y > Intersection.x)
        {
            //change position
            coordinate = Player->getPos();
            coordinate.y += Intersection.y;
            Player->setPos(coordinate);
            Player->getHitBox()->setPosition(coordinate);

            //change velocity
            coordinate = Player->getVel();
            coordinate.y = 0.0;
            Player->setVel(coordinate);
        }

        //collision in the x direction
        else
        {
            //change position
            coordinate = Player->getPos();
            coordinate.x += Intersection.x;
            Player->setPos(coordinate);
            Player->getHitBox()->setPosition(coordinate);
            
            //change velocity
            coordinate= Player->getVel();
            coordinate.x = 0.0;
            Player->setVel(coordinate);
        }
    }

    //dano no jogador, a menos que ele esja atacando
    void CollisionManager::CollisionPlayerEnemy(Entities::MovingEntities::Player *Player, Entities::MovingEntities::Enemy *Enemy, 
    Math::CoordF Intersection)
    {
        //Player atacking
        if(Player->isAttacking())
        {
            //Enemy takes damage
            if(( Player->getVel().x > 0) && ((Player->getPos().x - Enemy->getPos().x) < 0) ||
                ((Player->getVel().x < 0) && ((Player->getPos().x - Enemy->getPos().x) > 0)))
                {
                    Enemy->takeDamage();
                    if( Enemy->getHp() == 0)
                    {
                        //desaloco ou reposiciono Enemy
                    }
                
                }
            //Player takes damage
            else
            {
                Player->takeDamage(Enemy->getDamage());
            }
        }
        //Player not atacking
        else
        {
            //Player takes damage
            Player->takeDamage(Enemy->getDamage());
        }
    }

    ////altera velocidade na direção que bateu e reposiciona o inimigo
    void CollisionManager::CollisionObstacleEnemy(Entities::MovingEntities::Enemy *Enemy , Math::CoordF Intersection)
    {
        sf::Vector2f coordinate;
        //collision in the Y direction
        if(Intersection.y > Intersection.x)
        {
            //change position
            coordinate = Enemy->getPos();
            coordinate.y += Intersection.y;
            Enemy->setPos(coordinate);

            //change velocity
            coordinate = Enemy->getVel();
            coordinate.y = 0.0;
            Enemy->setVel(coordinate);
        }

        //collision in the x direction
        else
        {
            //change position
            coordinate = Enemy->getPos();
            coordinate.x += Intersection.x;
            Enemy->setPos(coordinate);
            
            //change velocity
            coordinate= Enemy->getVel();
            coordinate.x = 0.0;
            Enemy->setVel(coordinate);
        }
    }


        void CollisionManager::pushPlayer(Entities::MovingEntities::Player* player)
        {
            playerList.pushElement(player);
        }


		void CollisionManager::pushEnemy(Entities::MovingEntities::Enemy* enemy)
        {
            enemyList.pushElement(enemy);
        }


		void CollisionManager::pushObstacle(Entities::StaticEntities::Obstacle* obstacle)
        {
            obstacleList.pushElement(obstacle);
        }

}//namespace Managers