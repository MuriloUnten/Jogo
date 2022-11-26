#pragma once

#include "time.h"

#include "State.hpp"
#include "EntityList.hpp"
#include "Player.hpp"
#include "Cactus.hpp"
#include "Ground.hpp"
#include "Enemy1.hpp"
#include "Archer.hpp"
#include "Boss.hpp"
#include "Web.hpp"
#include "CollisionManager.hpp"


namespace Levels
{
    class Level : public State
    {
    private:
	    Lists::EntityList* entityList;
        Entities::MovingEntities::Player* pPlayer1;
        Entities::MovingEntities::Player* pPlayer2;
        Managers::CollisionManager* collisions;

        int numberOfEnemies;
        bool TwoPlayers;

    public:
        Level(const char* nameLevel, std::string fileName, sf::Vector2f size, sf::Vector2f position=sf::Vector2f(0, 0), Entities::MovingEntities::Player* player1=NULL, Entities::MovingEntities::Player* player2=NULL);
        Level();
        ~Level();
        void execute();
        void draw();

        void createPlayers(Entities::MovingEntities::Player* player, sf::Vector2f pos);
        void createEnemy1(sf::Vector2f pos);
        void createArcher(sf::Vector2f pos);
        void createBoss(sf::Vector2f pos);
        void createGround(std::string fileName, sf::Vector2f pos);
        void createCactus(sf::Vector2f pos);
        void createWeb(sf::Vector2f pos);

        void createLevel(const char* nameLevel);

        void endLevel(const bool win);
        void countEnemies();

        void resetState();


    };
}// namespace Levels
