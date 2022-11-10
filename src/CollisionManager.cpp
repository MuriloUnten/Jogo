#include "CollisionManager.hpp"

namespace Managers{
    CollisionManager::CollisionManager(Entities::MovingEntities::Player* P1, Entities::MovingEntities::Player* P2,
            Lists::List<Entities::StaticEntities::Obstacle> LObstacle, Lists::List<Entities::MovingEntities::Enemy> LEnemy)
    {
            Entities::MovingEntities::Player *pPlayer1 = P1;
            Entities::MovingEntities::Player *pPlayer2 = P2;
            Lists::List<Entities::StaticEntities::Obstacle> ListObstacle= LObstacle;
            Lists::List<Entities::MovingEntities::Enemy> ListEnemy= LEnemy;
    }
    
    
    CollisionManager::~CollisionManager()
    {
        pPlayer1 = nullptr;
        pPlayer2 = nullptr;
        //delete lists
        ListObstacle.clear();
        ListEnemy.clear();
    }
    
    
    void CollisionManager::Collision()
    {
        /* Talvez ter lista de players, para nao precisar ficar testando muita coisa */

        Entities::StaticEntities::Obstacle *Obstacle1=nullptr;
        Entities::MovingEntities::Enemy *Enemy1= nullptr;

        Math::Coordinate<float> Intersection;
        Math::Coordinate<float> CenterDistance;

        /*------------------------------Collision between Player1 and Obstacles------------------------------------------------------------*/
        if(pPlayer1 != nullptr){
            for(int j=0; j < ListObstacle.getSize(); j++)
            {
                Obstacle1 = ListObstacle[j];
                //módulo da distância entre o centro das entidades
                CenterDistance.x= fabs(pPlayer1->getPos().x - Obstacle1->getPos().x);
                CenterDistance.y= fabs(pPlayer1->getPos().y - Obstacle1->getPos().y);
                //distância que as extremidades mais próximas das entidades se econtram  
                Intersection.x= CenterDistance.x - (pPlayer1->getSize().x/2 + Obstacle1->getSize().x/2);
                Intersection.y= CenterDistance.y - (pPlayer1->getSize().y/2 + Obstacle1->getSize().y/2);
                //verifica se houve colisão
                if(Intersection.x < 0 && Intersection.y < 0)
                {
                    CollisionPlayerObstacle( pPlayer1,  Intersection);
                }
            }
        }
        /*------------------------------Collision between entre Player2 and Obstacle---------------------------------------------------------------*/
        if( pPlayer2 != nullptr){
            for(int j=0; j < ListObstacle.getSize(); j++ )
            {
                Obstacle1 = ListObstacle[j];
                //módulo da distância entre o centro das entidades
                CenterDistance.x= fabs(pPlayer2->getPos().x - Obstacle1->getPos().x);
                CenterDistance.y= fabs(pPlayer2->getPos().y - Obstacle1->getPos().y);
                //distância que as extremidades mais próximas das entidades se econtram  
                Intersection.x= CenterDistance.x - (pPlayer2->getSize().x/2 + Obstacle1->getSize().x/2);
                Intersection.y= CenterDistance.y - (pPlayer2->getSize().y/2 + Obstacle1->getSize().y/2);
                //verifica se houve colisão
                if(Intersection.x < 0 && Intersection.y < 0)
                {
                    CollisionPlayerObstacle( pPlayer2, Intersection);
                }
            }
        }
        /*------------------------------Collision between Player1 and Enemy---------------------------------------------------------------*/
        if( pPlayer1 != nullptr){
            for(int j=0; j < ListEnemy.getSize(); j++ )
            {
                Enemy1 = ListEnemy[j];
                //módulo da distância entre o centro das entidades
                CenterDistance.x= fabs(pPlayer1->getPos().x - Enemy1->getPos().x);
                CenterDistance.y= fabs(pPlayer1->getPos().y - Enemy1->getPos().y);
                //distância que as extremidades mais próximas das entidades se econtram  
                Intersection.x= CenterDistance.x - (pPlayer1->getSize().x/2 + Enemy1->getSize().x/2);
                Intersection.y= CenterDistance.y - (pPlayer1->getSize().y/2 + Enemy1->getSize().y/2);
                //verifica se houve colisão
                if(Intersection.x < 0 && Intersection.y < 0)
                {
                    CollisionPlayerEnemy( pPlayer1, Enemy1, Intersection);
                }
            }
        }
        /*------------------------------Collision between Player2 and Enemy---------------------------------------------------------------*/
        if( pPlayer2 != nullptr)
        {
            for(int j=0; j < ListEnemy.getSize(); j++ )
            {
                Enemy1 = ListEnemy[j];
                //módulo da distância entre o centro das entidades
                CenterDistance.x= fabs(pPlayer2->getPos().x - Enemy1->getPos().x);
                CenterDistance.y= fabs(pPlayer2->getPos().y - Enemy1->getPos().y);
                //distância que as extremidades mais próximas das entidades se econtram  
                Intersection.x= CenterDistance.x - (pPlayer2->getSize().x/2 + Enemy1->getSize().x/2);
                Intersection.y= CenterDistance.y - (pPlayer2->getSize().y/2 + Enemy1->getSize().y/2);
                //verifica se houve colisão
                if(Intersection.x < 0 && Intersection.y < 0)
                {
                    CollisionPlayerEnemy( pPlayer2, Enemy1, Intersection);
                }
            }
        }

        /*------------------------------Collision between Obstacle and Enemy---------------------------------------------------------------*/
        for(int i = 0; i < ListObstacle.getSize(); i++)
        {
            Obstacle1=ListObstacle[i];
            for(int j=0; j < ListEnemy.getSize(); j++ )
            {
                Enemy1 = ListEnemy[j];
                //módulo da distância entre o centro das entidades
                CenterDistance.x= fabs(Obstacle1->getPos().x - Enemy1->getPos().x);
                CenterDistance.y= fabs(Obstacle1->getPos().y - Enemy1->getPos().y);
                //distância que as extremidades mais próximas das entidades se econtram  
                Intersection.x= CenterDistance.x - (Obstacle1->getSize().x/2 + Enemy1->getSize().x/2);
                Intersection.y= CenterDistance.y - (Obstacle1->getSize().y/2 + Enemy1->getSize().y/2);
                //verifica se houve colisão
                if(Intersection.x < 0 && Intersection.y < 0){
                    CollisionObstacleEnemy( Enemy1, Intersection);
                }
            }
        }
    }

    //altera velocidade na direção que bateu e reposiciona o jogador
    void CollisionManager::CollisionPlayerObstacle(Entities::MovingEntities::Player *Player, Math::CoordF Intersection)
    {
        /* Velocidade em y pode ser > 0 e mesmo assim a colisao ser em x, e vice versa */
        
        sf::Vector2f coordinate;
        //collision in the Y direction
        if( Player->getVel().y > 0 )        {
            //change position
            coordinate = Player->getPos();
            coordinate.y+= Intersection.y;
            Player->setPos(coordinate);

            //change velocity
            coordinate= Player->getVel();
            coordinate.y = 0.0;
            Player->setVel(coordinate);
        }
        //collision in the x direction
        else if( Player->getVel().x > 0 )
        {
            //change position
            coordinate = Player->getPos();
            coordinate.x+= Intersection.x;
            Player->setPos(coordinate);
            
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
        if(Player->isAtack())
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
                Player->takeDamage(Enemy);
            }
        }
        //Player not atacking
        else
        {
            //Player takes damage
            Player->takeDamage(Enemy);
        }
    }

    ////altera velocidade na direção que bateu e reposiciona o inimigo
    void CollisionManager::CollisionObstacleEnemy(Entities::MovingEntities::Enemy *Enemy , Math::CoordF Intersection)
    {
        sf::Vector2f coordinate;
        //collision in the Y direction
        if( Enemy->getVel().y > 0 )
        {
            //change position
            coordinate = Enemy->getPos();
            coordinate.y+= Intersection.y;
            Enemy->setPos(coordinate);

            //change velocity
            coordinate= Enemy->getVel();
            coordinate.y = 0.0;
            Enemy->setVel(coordinate);
        }
        //collision in the x direction
        else if( Enemy->getVel().x > 0 )
        {
            //change position
            coordinate = Enemy->getPos();
            coordinate.x+= Intersection.x;
            Enemy->setPos(coordinate);
            
            //change velocity
            coordinate= Enemy->getVel();
            coordinate.x *= -1;
            Enemy->setVel(coordinate);
        }
    }

}//namespace Manager
