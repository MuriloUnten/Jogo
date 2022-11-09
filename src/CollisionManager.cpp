#include "CollisionManager.hpp"

namespace Managers{

CollisionManager::CollisionManager(Entities::MovingEntities::Player* P1, Entities::MovingEntities::Player* P2,
        Lists::List<Entities::StaticEntities::Obstacle> LObstacle, Lists::List<Entities::MovingEntities::Enemy> LEnemy){

        Entities::MovingEntities::Player *pPlayer1 = P1;
        Entities::MovingEntities::Player *pPlayer2 = P2;
        Lists::List<Entities::StaticEntities::Obstacle> ListObstacle= LObstacle;
        Lists::List<Entities::MovingEntities::Enemy> ListEnemy= LEnemy;
}
CollisionManager::~CollisionManager(){
    pPlayer1 = nullptr;
    pPlayer2 = nullptr;
    //delete lists
    ListObstacle.clear();
    ListEnemy.clear();
}
void CollisionManager:: Collision(){

    Entities::StaticEntities::Obstacle *Obstacle1=nullptr;
    Entities::MovingEntities::Enemy *Enemy1= nullptr;

    Math::Coordinate<float> Intersection;
    Math::Coordinate<float> CenterDistance;

    /*------------------------------Collision between Player1 and Obstacles------------------------------------------------------------*/
    if(pPlayer1 != nullptr){
        for(int j=0; j < ListObstacle.getSize(); j++ ){
            Obstacle1 = ListObstacle.operator[](j);
            //módulo da distância entre o centro das entidades
            CenterDistance.x= fabs(pPlayer1->getPos().x - Obstacle1->getPos().x);
            CenterDistance.y= fabs(pPlayer1->getPos().y - Obstacle1->getPos().y);
            //distância que as extremidades mais próximas das entidades se econtram  
            Intersection.x= CenterDistance.x - (pPlayer1->getSize().x/2 + Obstacle1->getSize().x/2);
            Intersection.y= CenterDistance.y - (pPlayer1->getSize().y/2 + Obstacle1->getSize().y/2);
            //verifica se houve colisão
            if(Intersection.x < 0 && Intersection.y < 0){
                CollisionPlayerObstacle( pPlayer1, Obstacle1, Intersection);
            }
            }
        }
    /*------------------------------Collision between entre Player2 and Obstacle---------------------------------------------------------------*/
    if( pPlayer2 != nullptr){
        for(int j=0; j < ListObstacle.getSize(); j++ ){
            Obstacle1 = ListObstacle.operator[](j);
            //módulo da distância entre o centro das entidades
            CenterDistance.x= fabs(pPlayer2->getPos().x - Obstacle1->getPos().x);
            CenterDistance.y= fabs(pPlayer2->getPos().y - Obstacle1->getPos().y);
            //distância que as extremidades mais próximas das entidades se econtram  
            Intersection.x= CenterDistance.x - (pPlayer2->getSize().x/2 + Obstacle1->getSize().x/2);
            Intersection.y= CenterDistance.y - (pPlayer2->getSize().y/2 + Obstacle1->getSize().y/2);
            //verifica se houve colisão
            if(Intersection.x < 0 && Intersection.y < 0){
                CollisionPlayerObstacle( pPlayer2, Obstacle1, Intersection);
            }
            }
        }
    /*------------------------------Collision between Player1 and Enemy---------------------------------------------------------------*/
    if( pPlayer1 != nullptr){
        for(int j=0; j < ListEnemy.getSize(); j++ ){
            Enemy1 = ListEnemy.operator[](j);
            //módulo da distância entre o centro das entidades
            CenterDistance.x= fabs(pPlayer1->getPos().x - Enemy1->getPos().x);
            CenterDistance.y= fabs(pPlayer1->getPos().y - Enemy1->getPos().y);
            //distância que as extremidades mais próximas das entidades se econtram  
            Intersection.x= CenterDistance.x - (pPlayer1->getSize().x/2 + Enemy1->getSize().x/2);
            Intersection.y= CenterDistance.y - (pPlayer1->getSize().y/2 + Enemy1->getSize().y/2);
            //verifica se houve colisão
            if(Intersection.x < 0 && Intersection.y < 0){
                CollisionPlayerEnemy( pPlayer1, Enemy1, Intersection);
            }
            }
        }
    /*------------------------------Collision between Player2 and Enemy---------------------------------------------------------------*/
    if( pPlayer2 != nullptr){
        for(int j=0; j < ListEnemy.getSize(); j++ ){
            Enemy1 = ListEnemy.operator[](j);
            //módulo da distância entre o centro das entidades
            CenterDistance.x= fabs(pPlayer2->getPos().x - Enemy1->getPos().x);
            CenterDistance.y= fabs(pPlayer2->getPos().y - Enemy1->getPos().y);
            //distância que as extremidades mais próximas das entidades se econtram  
            Intersection.x= CenterDistance.x - (pPlayer2->getSize().x/2 + Enemy1->getSize().x/2);
            Intersection.y= CenterDistance.y - (pPlayer2->getSize().y/2 + Enemy1->getSize().y/2);
            //verifica se houve colisão
            if(Intersection.x < 0 && Intersection.y < 0){
                CollisionPlayerEnemy( pPlayer2, Enemy1, Intersection);
            }
            }
        }

    /*------------------------------Collision between Obstacle and Enemy---------------------------------------------------------------*/
    for(int i = 0; i < ListObstacle.getSize(); i++){
        Obstacle1=ListObstacle[i];
        for(int j=0; j < ListEnemy.getSize(); j++ ){
            Enemy1 = ListEnemy.operator[](j);
            //módulo da distância entre o centro das entidades
            CenterDistance.x= fabs(Obstacle1->getPos().x - Enemy1->getPos().x);
            CenterDistance.y= fabs(Obstacle1->getPos().y - Enemy1->getPos().y);
            //distância que as extremidades mais próximas das entidades se econtram  
            Intersection.x= CenterDistance.x - (Obstacle1->getSize().x/2 + Enemy1->getSize().x/2);
            Intersection.y= CenterDistance.y - (Obstacle1->getSize().y/2 + Enemy1->getSize().y/2);
            //verifica se houve colisão
            if(Intersection.x < 0 && Intersection.y < 0){
                CollisionObstacleEnemy( Enemy1, Obstacle1, Intersection);
            }
            }
        }
}


void CollisionManager::MoveX(Entities::Entity *Entity, float x){

}


void CollisionManager::MoveY(Entities::Entity *Entity, float y){

}

//altera velocidade na direção que bateu e reposiciona o jogador
void CollisionManager::CollisionPlayerObstacle(Entities::MovingEntities::Player *Player, Entities::StaticEntities::Obstacle *Obstacle, 
Math::CoordF Intersection){


}

//dano no jogador, a menos que ele esja atacando
void CollisionManager::CollisionPlayerEnemy(Entities::MovingEntities::Player *Player, Entities::MovingEntities::Enemy *Enemy, 
Math::CoordF Intersection){

}

////altera velocidade na direção que bateu e reposiciona o inimigo
void CollisionManager::CollisionObstacleEnemy(Entities::MovingEntities::Enemy *Enemy ,
Entities::StaticEntities::Obstacle *Obstacle, Math::CoordF Intersection){

}

}//namespace Manager
