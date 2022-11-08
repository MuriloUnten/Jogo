#pragma once

#include "Coordinate.hpp"
#include "Entity.hpp"
#include "Player.hpp"
#include <math.h>
#include "Obstacle.hpp"
#include "Enemy.hpp"
#include "List.hpp"

namespace Managers{
    class CollisionManager{
    private:
        //ponteiro para Players, entidades móveis e estáticas
        Entities::MovingEntities::Player* pPlayer1;
        Entities::MovingEntities::Player* pPlayer2;
        Lists::List<Entities::StaticEntities::Obstacle> ListObstacle;
        Lists::List<Entities::MovingEntities::Enemy> ListEnemy;
    public:
        CollisionManager(Entities::MovingEntities::Player* P1, Entities::MovingEntities::Player* P2, 
        Lists::List<Entities::StaticEntities::Obstacle> LObstacle, Lists::List<Entities::MovingEntities::Enemy> LEnemy);
        ~CollisionManager();
        void Collision();
        void CollisionPlayerObstacle(Entities::MovingEntities::Player *Player, Entities::StaticEntities::Obstacle *Obstacle, Math::CoordF Intersection);
        void CollisionPlayerEnemy(Entities::MovingEntities::Player *Player, Entities::MovingEntities::Enemy *Enemy, Math::CoordF Intersection);
        void CollisionObstacleEnemy(Entities::MovingEntities::Enemy *Enemy, Entities::StaticEntities::Obstacle *Obstacle, Math::CoordF Intersection);
        void MoveX(Entities::Entity *Entity, float x);
        void MoveY(Entities::Entity *Entity, float y);
        //void Clear();
    };
}//namespace Managers