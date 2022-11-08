#pragma once

#include "Coordinate.hpp"
#include "EntityList.hpp"
#include "Player.hpp"
#include <math.h>

namespace Managers{
    class CollisionManager{
    private:
        //ponteiro para Players, entidades móveis e estáticas
        Entities::MovingEntities::Player* pPlayer1;
        Entities::MovingEntities::Player* pPlayer2;
        Lists::EntityList *pObstacle;
        Lists::EntityList *pEnemy;
    public:
        CollisionManager(Entities::MovingEntities::Player* pPlayer1, Entities::MovingEntities::Player* pPlayer2,
        Lists::EntityList *pObstacle, Lists::EntityList *pEnemy);
        ~CollisionManager();
        void Collision();
        void CollisionPlayerObstacle();
        void CollisionPlayerEnemy();
        void CollisionObstacle();
        //void Clear();
    };
}//namespace Managers