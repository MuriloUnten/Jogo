#pragma once

#include "Being.hpp"
#include "EntityList.hpp"
#include "Player.hpp"
#include "Cactus.hpp"
#include "Ground.hpp"
#include "Enemy1.hpp"
#include "CollisionManager.hpp"


namespace Levels
{
    class Level : public Being
    {
    protected:
	    Lists::EntityList* entityList;
        Entities::MovingEntities::Player* pPlayer;
        Managers::CollisionManager* collisions;

    public:
        Level(std::string fileName, sf::Vector2f size, sf::Vector2f position=sf::Vector2f(0, 0), Entities::MovingEntities::Player* player=NULL);
        Level();
        ~Level();
        void execute();
        void draw();

        void createLevel();
        virtual void createPlayers() = 0;
        virtual void createEnemies() = 0;
        virtual void createObstacles() = 0;

    };
}// namespace Levels
