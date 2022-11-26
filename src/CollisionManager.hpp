#pragma once

#include "Coordinate.hpp"
#include "Entity.hpp"
#include "Player.hpp"
#include "Obstacle.hpp"
#include "Enemy.hpp"
#include "List.hpp"
#include "Projectile.hpp"

#include <math.h>
#include <vector>

namespace Managers
{
    class CollisionManager
    {
    private:
        Lists::List<Entities::MovingEntities::Player> playerList;
        Lists::List<Entities::MovingEntities::Enemy> enemyList;
        Lists::List<Entities::StaticEntities::Obstacle> obstacleList;
        Lists::List<Entities::MovingEntities::Projectile> projectileList;
    
    public:
        CollisionManager();
        ~CollisionManager();

        void Collision();

        void CollisionPlayerObstacle(Entities::MovingEntities::Player *Player, Entities::StaticEntities::Obstacle *obstacle, Math::CoordF Intersection);
        void CollisionPlayerEnemy(Entities::MovingEntities::Player *Player, Entities::MovingEntities::Enemy *Enemy, Math::CoordF Intersection);
        void CollisionPlayerProjectile(Entities::MovingEntities::Player *Player, Entities::MovingEntities::Projectile *projectile, Math::CoordF Intersection);
        void CollisionObstacleEnemy(Entities::MovingEntities::Enemy *Enemy,Entities::StaticEntities::Obstacle *obstacle, Math::CoordF Intersection);
        void CollisionObstacleProjectile( Entities::MovingEntities::Projectile *projectile, Entities::StaticEntities::Obstacle *obstacle, Math::CoordF Intersection);

        void pushPlayer(Entities::MovingEntities::Player* player);
		void pushEnemy(Entities::MovingEntities::Enemy* enemy);
		void pushObstacle(Entities::StaticEntities::Obstacle* obstacle);    
        void pushProjectile(Entities::MovingEntities::Projectile* projectile);
 
        void clearLists();
    };
}//namespace Managers