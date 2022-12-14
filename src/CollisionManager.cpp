#include "CollisionManager.hpp"

namespace Managers
{
    CollisionManager::CollisionManager()
    {

    }
    
    
    CollisionManager::~CollisionManager()
    {
        /*delete lists*/
        // playerList.clear();
        // enemyList.clear();
        // obstacleList.clear();
        // projectileList.clear();
    }
    
    
    void CollisionManager::Collision()
    {
        /* Talvez ter lista de players, para nao precisar ficar testando muita coisa */

        Entities::StaticEntities::Obstacle *Obstacle1 = nullptr;
        Entities::MovingEntities::Enemy *Enemy1 = nullptr;
        Entities::MovingEntities::Projectile *Projectile1 = nullptr;

        Math::Coordinate<float> Intersection;
        Math::Coordinate<float> CenterDistance;

        /* Player collision */
        for(int i = 0; i < playerList.getSize(); i++)
        {
            Entities::MovingEntities::Player* pAuxPlayer = playerList[i];
            if(pAuxPlayer == NULL || !pAuxPlayer->getExecutable())
                continue;

            /* Collision between Player and Enemy */
            for(int j = 0; j < enemyList.getSize(); j++)
            {
                Enemy1 = enemyList[j];
                if(Enemy1 == NULL || !Enemy1->getExecutable())
                    continue;
            
                //módulo da distância entre o centro das entidades
                CenterDistance.x= fabs((pAuxPlayer->getPos().x + pAuxPlayer->getSize().x/2.0)- (Enemy1->getPos().x + Enemy1->getSize().x/2.0));
                CenterDistance.y= fabs((pAuxPlayer->getPos().y + pAuxPlayer->getSize().y/2.0) - (Enemy1->getPos().y + Enemy1->getSize().y/2.0));
                //distância que as extremidades mais próximas das entidades se econtram
                Intersection.x = CenterDistance.x - (pAuxPlayer->getSize().x/2.0 + Enemy1->getSize().x/2.0);
                Intersection.y = CenterDistance.y - (pAuxPlayer->getSize().y/2.0 + Enemy1->getSize().y/2.0);
                //verifica se houve colisão
                if(Intersection.x < 0 && Intersection.y < 0)
                {
                    CollisionPlayerEnemy(pAuxPlayer, Enemy1, Intersection);
                }
            }

            /* Collision between Player and Obstacles */
            for(int j = 0; j < obstacleList.getSize(); j++)
            {
                //módulo da distância entre o centro das entidades
                Obstacle1 = obstacleList[j];
                if(Obstacle1 == NULL || !Obstacle1->getExecutable())
                    continue;

                CenterDistance.x = fabs(pAuxPlayer->getPos().x + pAuxPlayer->getSize().x/2 - (Obstacle1->getPos().x + Obstacle1->getSize().x/2));
                CenterDistance.y = fabs(pAuxPlayer->getPos().y + pAuxPlayer->getSize().y/2 - (Obstacle1->getPos().y + Obstacle1->getSize().y/2));
                Intersection.x = CenterDistance.x - (pAuxPlayer->getSize().x/2 + Obstacle1->getSize().x/2);
                Intersection.y = CenterDistance.y - (pAuxPlayer->getSize().y/2 + Obstacle1->getSize().y/2);
                //distância que as extremidades mais próximas das entidades se econtram  
                //verifica se houve colisão
                if(Intersection.x < 0 && Intersection.y < 0)
                {
                    CollisionPlayerObstacle(pAuxPlayer, Obstacle1, Intersection);
                }
            }

            /* Collision between Player and Projectiles */
            for(int j = 0; j < projectileList.getSize(); j++)
            {
                //módulo da distância entre o centro das entidades
                Projectile1 = projectileList[j];
                if(Projectile1 == NULL || !Projectile1->getExecutable())
                    continue;

                CenterDistance.x = fabs(pAuxPlayer->getPos().x + pAuxPlayer->getSize().x/2 - (Projectile1->getPos().x + Projectile1->getSize().x/2));
                CenterDistance.y = fabs(pAuxPlayer->getPos().y + pAuxPlayer->getSize().y/2 - (Projectile1->getPos().y + Projectile1->getSize().y/2));
                Intersection.x = CenterDistance.x - (pAuxPlayer->getSize().x/2 + Projectile1->getSize().x/2);
                Intersection.y = CenterDistance.y - (pAuxPlayer->getSize().y/2 + Projectile1->getSize().y/2);
                //distância que as extremidades mais próximas das entidades se econtram  
                //verifica se houve colisão
                if(Intersection.x < 0 && Intersection.y < 0)
                {
                    CollisionPlayerProjectile(pAuxPlayer, Projectile1, Intersection);
                }
            }


        }

        /*------------------------------Collision between Obstacle---------------------------------------------------------------*/
        for(int i = 0; i < obstacleList.getSize(); i++)
        {
            Obstacle1 = obstacleList[i];
            if(Obstacle1 == NULL)
                continue;
             //Obstacle and Enemy
            for(int j = 0; j < enemyList.getSize(); j++)
            {
                Enemy1 = enemyList[j];
                if(Enemy1 == NULL || !Enemy1->getExecutable())
                    continue;

                CenterDistance.x = fabs(Enemy1->getPos().x + Enemy1->getSize().x/2.0 - (Obstacle1->getPos().x + Obstacle1->getSize().x/2.0));
                CenterDistance.y = fabs(Enemy1->getPos().y + Enemy1->getSize().y/2.0 - (Obstacle1->getPos().y + Obstacle1->getSize().y/2.0));
                Intersection.x = CenterDistance.x - (Enemy1->getSize().x/2.0 + Obstacle1->getSize().x/2.0);
                Intersection.y = CenterDistance.y - (Enemy1->getSize().y/2.0 + Obstacle1->getSize().y/2.0);
                //verifica se houve colisão
                if(Intersection.x < 0 && Intersection.y < 0)
                {
                    CollisionObstacleEnemy( Enemy1, Obstacle1, Intersection);
                }
            }
            //Obstacle and Projectile
            for(int j = 0; j < projectileList.getSize(); j++)
            {
                Projectile1 = projectileList[j];
                if(Projectile1 == NULL || !Projectile1->getExecutable())
                    continue;

                CenterDistance.x = fabs(Projectile1->getPos().x + Projectile1->getSize().x/2.0 - (Obstacle1->getPos().x + Obstacle1->getSize().x/2.0));
                CenterDistance.y = fabs(Projectile1->getPos().y + Projectile1->getSize().y/2.0 - (Obstacle1->getPos().y + Obstacle1->getSize().y/2.0));
                Intersection.x = CenterDistance.x - (Projectile1->getSize().x/2.0 + Obstacle1->getSize().x/2.0);
                Intersection.y = CenterDistance.y - (Projectile1->getSize().y/2.0 + Obstacle1->getSize().y/2.0);
                //verifica se houve colisão
                if(Intersection.x < 0 && Intersection.y < 0)
                {
                    CollisionObstacleProjectile( Projectile1, Obstacle1, Intersection);
                    //Projectile1->setExecutable(false);
                }
            }
        }
    }

    //altera velocidade na direção que bateu e reposiciona o jogador
    void CollisionManager::CollisionPlayerObstacle(Entities::MovingEntities::Player *Player, Entities::StaticEntities::Obstacle *obstacle, Math::CoordF Intersection)
    {
        
        obstacle->affectPlayer(Player);

        /* Velocidade em y pode ser > 0 e mesmo assim a colisao ser em x, e vice versa */
        sf::Vector2f coordinate;
        coordinate = Player->getPos();
        //collision in the Y direction
        if(Intersection.y > Intersection.x)
        {
            if (Player->getPos().y < obstacle->getPos().y)
            {
                //change position
                coordinate.y += Intersection.y;
                Player->setPos(coordinate);
                //change velocity
                coordinate = Player->getVel();
                coordinate.y = 0.0;
                Player->setVel(coordinate);
                Player->setCanJump(true);
            }
            //change position
            else
            {
                coordinate.y -= Intersection.y;
                Player->setPos(coordinate);
                //change velocity
                coordinate = Player->getVel();
                coordinate.y = 0.0f;
            }
            
        }
        //collision in the x direction
        else
        {
            if (Player->getPos().x < obstacle->getPos().x)
                {
                    //change position
                    coordinate.x += Intersection.x;
                    Player->setPos(coordinate);
                    //change velocity
                    coordinate = Player->getVel();
                    coordinate.x = 0.0;
                }
                //change position
            else
            {
                coordinate.x -= Intersection.x;
                Player->setPos(coordinate);
                //change velocity
                coordinate = Player->getVel();
                coordinate.x = 0.0;
            }
        }
        Player->setVel(coordinate);
    }

    //dano no jogador, a menos que ele esja atacando
    void CollisionManager::CollisionPlayerEnemy(Entities::MovingEntities::Player *Player, Entities::MovingEntities::Enemy *Enemy, 
    Math::CoordF Intersection)
    {

        //collision in the Y direction
        sf::Vector2f coordinate;
        coordinate = Player->getPos();

        //collision in the Y direction
        if(Intersection.y > Intersection.x)
        {
            if (Player->getPos().y < Enemy->getPos().y)
            {
                //change position
                coordinate.y += Intersection.y;
                Player->setPos(coordinate);
                //change velocity
                coordinate = Player->getVel();
                coordinate.y = 0.0;
                Player->setCanJump(true);
                Enemy->setExecutable(false);
                Player->addScore(Enemy->getPonctuation());
                
            }
            //change position
            else
            {
                coordinate.y -= Intersection.y;
                Player->setPos(coordinate);
                //change velocity
                coordinate = Player->getVel();
                coordinate.y = 0.0;
                Enemy->setCanJump(true);
                Player->takeDamage(Enemy->getDamage());
            }
            
        }
        //collision in the x direction
        else
        {
            if(Player->isAttacking())
            {
                //Enemy takes damage
                if(( Player->getFacingRight()) && ((Player->getPos().x - Enemy->getPos().x) < 0) ||
                    ((!Player->getFacingRight()) && ((Player->getPos().x - Enemy->getPos().x) > 0)))
                    {
                        Enemy->takeDamage(Player->getDamage());
                        if(Enemy->getHp() <= 0)
                            Enemy->setExecutable(false);
                        Player->addScore(Enemy->getPonctuation());
                    }
            }
            else
            {
                if(Enemy->getAttackTimer()->getElapsedTime() == Enemy->getAttackTimer()->getLimit() && !Enemy->isAttacking())
                {
                    Player->takeDamage(Enemy->getDamage());
                    Enemy->getAttackTimer()->restart();
                    Enemy->getAttackAnimationTimer()->restart();
                }
            }

            if (Player->getPos().x < Enemy->getPos().x)
                {
                    //change position
                    coordinate.x += Intersection.x;
                    Player->setPos(coordinate);
                    //change velocity
                    coordinate = Player->getVel();
                    coordinate.x = 0.0;
                }
                //change position
                else
                {
                    coordinate.x -= Intersection.x;
                    Player->setPos(coordinate);
                    //change velocity
                    coordinate = Player->getVel();
                    coordinate.x = 0.0;
                }
        }
        Player->setVel(coordinate);
    }
    //
    

    ////altera velocidade na direção que bateu e reposiciona o inimigo
    void CollisionManager::CollisionObstacleEnemy(Entities::MovingEntities::Enemy* Enemy, Entities::StaticEntities::Obstacle *obstacle, Math::CoordF Intersection)
    {
        
        //inimigo sendo um projetil
        if(Enemy->getId() == Earrow)
        {
            Enemy->setExecutable(false);
        }
        else
        {
            sf::Vector2f coordinate;
            coordinate = Enemy->getPos();
            //collision in the Y direction
            if(Intersection.y > Intersection.x)
            {
                if (Enemy->getPos().y < obstacle->getPos().y)
                {
                    //change position
                    coordinate.y += Intersection.y;
                    Enemy->setPos(coordinate);
                    //change velocity
                    coordinate = Enemy->getVel();
                    coordinate.y = 0.0;
                    Enemy->setCanJump(true);
                }
                //change position
                else
                {
                    coordinate.y -= Intersection.y;
                    Enemy->setPos(coordinate);
                    //change velocity
                    coordinate = Enemy->getVel();
                    coordinate.y = 0.0;
                }
                
            }
            //collision in the x direction
            else
            {
                if (Enemy->getPos().x < obstacle->getPos().x)
                    {
                    //change position
                    coordinate.x += Intersection.x;
                    Enemy->setPos(coordinate);
                    //change velocity
                    coordinate = Enemy->getVel();
                    }
                      
                else
                    {
                    //change position
                    coordinate.x -= Intersection.x;
                    Enemy->setPos(coordinate);
                    //change velocity
                    coordinate = Enemy->getVel();
                    }
                coordinate.x *= -1;
            }
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


    void CollisionManager::CollisionObstacleProjectile(Entities::MovingEntities::Projectile *projectile, Entities::StaticEntities::Obstacle *obstacle, Math::CoordF Intersection)
    {
        projectile->setExecutable(false);
    }


    void CollisionManager::CollisionPlayerProjectile(Entities::MovingEntities::Player *Player, Entities::MovingEntities::Projectile *projectile, Math::CoordF Intersection)
    {
        projectile->affectPlayer(Player);
    }


    void CollisionManager::pushProjectile(Entities::MovingEntities::Projectile* projectile)
    {
        projectileList.pushElement(projectile);
    }


    void CollisionManager::clearLists()
    {
        playerList.clear();
        enemyList.clear();
        obstacleList.clear();
        projectileList.clear();
    }
}//namespace Managers