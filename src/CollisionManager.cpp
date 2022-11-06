#include "CollisionManager.hpp"
#include "Coordinate.hpp"


namespace Managers{

CollisionManager::CollisionManager(Lists::EntityList *pSE, Lists::EntityList *pME){
    Lists::EntityList *pStaticEntities =pSE;
    Lists::EntityList *pMovingEntities =pME;
}
CollisionManager::~CollisionManager(){
    Lists::EntityList *pStaticEntities= nullptr;
    Lists::EntityList *pMovingEntities= nullptr;
}
void CollisionManager:: Collision(){

    Entities::Entity *Entity1 = nullptr;
    Entities::Entity *Entity2 = nullptr;
    Math::Coordinate<float> Intersection;
    Math::Coordinate<float> CenterDistance;

    //testa colisão enter objetos móveis com estáticos
    for(int i=0; i < pStaticEntities->getSize(); i++){
        Entity1 = pStaticEntities->getList()[i];
        for(int j=0; j < pMovingEntities->getSize(); j++ ){
            Entity2 = pMovingEntities->getList()[i];
            if(Entity1 != Entity2){
                //módulo da distância entre o centro das entidades
                CenterDistance.x= fabs(Entity1->getPos().x - Entity2->getPos().x);
                CenterDistance.y= fabs(Entity1->getPos().y - Entity2->getPos().y);
                //distância que as extremidades mais próximas das entidades se econtram  
                Intersection.x= CenterDistance.x - (Entity1->getSize().x/2 + Entity2->getSize().x/2);
                Intersection.y= CenterDistance.y - (Entity1->getSize().y/2 + Entity2->getSize().y/2);
                //verifica se houve colisão
                if(Intersection.x < 0 && Intersection.y < 0){
                    Entity1->Collide( Entity2, Intersection);
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
}//namespace CllisionManager
