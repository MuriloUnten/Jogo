#pragma once

#include "time.h"

#include "Being.hpp"
#include "EntityList.hpp"
#include "Player.hpp"
#include "Cactus.hpp"
#include "Ground.hpp"
#include "Enemy1.hpp"
#include "Archer.hpp"
#include "Web.hpp"
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

        virtual void createLevel() = 0;

        void createPlayers(sf::Vector2f pos);
        void createEnemy1(sf::Vector2f pos);
        void createArcher(sf::Vector2f pos);
        void createBoss(sf::Vector2f pos);
        void createGround(std::string fileName, sf::Vector2f pos);
        void createCactus(sf::Vector2f pos);
        void createWeb(sf::Vector2f pos);

    };
}// namespace Levels
