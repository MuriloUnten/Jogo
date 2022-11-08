#include "CollisionManager.hpp"


namespace Managers{

CollisionManager::CollisionManager(Entities::MovingEntities::Player* P1, Entities::MovingEntities::Player* P2,
        Lists::EntityList* Obstacle, Lists::EntityList* Enemy){

        Entities::MovingEntities::Player *pPlayer1 = P1;
        Entities::MovingEntities::Player *pPlayer2 = P2;
        Lists::EntityList *pObstacle =  Obstacle;
        Lists::EntityList *pEnemy = Enemy;
}
CollisionManager::~CollisionManager(){
    Entities::MovingEntities::Player *pPlayer1 = nullptr;
        Entities::MovingEntities::Player *pPlayer2 = nullptr;
        Lists::EntityList *pObstacle =  nullptr;
        Lists::EntityList *pEnemy = nullptr;
}
void CollisionManager:: Collision(){

    Entities::Entity *Entity1 ,*Entity2;

    Math::Coordinate<float> Intersection;
    Math::Coordinate<float> CenterDistance;

    //testa colisão entre Player e Obstacle
    if(pPlayer1 != nullptr){
    for(int j=0; j < pObstacle->getSize(); j++ ){
        Entity1 = pObstacle->getList()[j];
        //módulo da distância entre o centro das entidades
        CenterDistance.x= fabs(pPlayer1->getPos().x - Entity1->getPos().x);
        CenterDistance.y= fabs(pPlayer1->getPos().y - Entity1->getPos().y);
        //distância que as extremidades mais próximas das entidades se econtram  
        Intersection.x= CenterDistance.x - (pPlayer1->getSize().x/2 + Entity1->getSize().x/2);
        Intersection.y= CenterDistance.y - (pPlayer1->getSize().y/2 + Entity1->getSize().y/2);
        //verifica se houve colisão
        if(Intersection.x < 0 && Intersection.y < 0){
            
        }
        }
    }
    }

    //testa colisão enter objetos móveis com móveis
    for(int i=0; i < pMovingEntities->getSize(); i++){
        Entity1 = pMovingEntities->getList()[i];
        for(int j=0; j < pMovingEntities->getSize(); j++ ){
            Entity2 = pMovingEntities->getList()[i];
            if(Entity1 != Entity2){

                CenterDistance.x= fabs(Entity1->getPos().x - Entity2->getPos().x);
                CenterDistance.y= fabs(Entity1->getPos().y - Entity2->getPos().y);

                Intersection.x= CenterDistance.x - (Entity1->getSize().x/2 + Entity2->getSize().x/2);
                Intersection.y= CenterDistance.y - (Entity1->getSize().y/2 + Entity2->getSize().y/2);

                //verifica se houve colisão0
                if(Intersection.x < 0 && Intersection.y < 0){
                    Entity1->Collide( Entity2, Intersection);
                }
            }
        }
    }
}
void CollisionManager::CollisionPlayerObstacle(){

}
void CollisionManager::CollisionPlayerEnemy(){

}
void CollisionManager::CollisionObstacle(){

}

}//namespace Manager
