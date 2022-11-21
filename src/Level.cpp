#include "Level.hpp"

#define PLAYER_PATH "../assets/personagem/kakashi1.png"
#define ENEMY1_PATH "../assets/inimigos/enemy1.png"
#define ARCHER_PATH "../assets/inimigos/arqueiro.png"
#define CACTUS_PATH "../assets/mundo/Cactus4.png"
#define GROUND2_PATH "../assets/mundo/ground_tile.png" 
#define GROUND3_PATH "../assets/mundo/ground2_tile.png"
#define WEB_PATH "../assets/mundo/SpiderWeb.png"

namespace Levels
{
    Level::Level(std::string fileName, sf::Vector2f size, sf::Vector2f position, Entities::MovingEntities::Player* player):
    Being(fileName, size, position),
    entityList(new Lists::EntityList()),
    collisions(new Managers::CollisionManager())
    {
        pPlayer = player;
        Entities::Entity* pAux = static_cast<Entities::Entity*>(pPlayer);
        entityList->pushEntity(pAux);
        collisions->pushPlayer(player);

    }


    Level::Level():
    Being(),
    entityList(new Lists::EntityList())
    {
        pPlayer = NULL;
    }


    Level::~Level()
    {
        delete entityList;
        delete collisions;
        entityList = NULL;
        collisions = NULL;
    }


    void Level::execute()
    {
        draw();

        entityList->execute();
        collisions->Collision();
        entityList->draw();
    }


    void Level::draw()
    {
        /* TODO implementar mais coisas talvez?*/

        if(pGraphics->isWindowOpen())
            pGraphics->getWindow()->draw(*hitBox);
    }


    void Level::createPlayers(sf::Vector2f pos)
    {
        pPlayer->loadTexture(PLAYER_PATH);
        pPlayer->setSize(sf::Vector2f(50, 60));
        pPlayer->getHitBox()->setTexture(pPlayer->getTexture());
        pPlayer->setPos(pos);

    }

    void Level::createEnemy1(sf::Vector2f pos)
    {
        Entities::MovingEntities::Enemy1* enemy = new Entities::MovingEntities::Enemy1(ENEMY1_PATH, sf::Vector2f(50, 50), pos);
        Entities::Entity* pEntity = static_cast<Entities::Entity*>(enemy);
        Entities::MovingEntities::Enemy* pEnemy = static_cast<Entities::MovingEntities::Enemy*>(enemy);
        entityList->pushEntity(pEntity);
        collisions->pushEnemy(pEnemy);
    }

    void Level::createArcher(sf::Vector2f pos)
    {
        Entities::MovingEntities::Archer* archer = new Entities::MovingEntities::Archer(ARCHER_PATH, sf::Vector2f(50, 70), pos);
        archer->setPlayer(pPlayer);
        Entities::Entity* pEntity = static_cast<Entities::Entity*>(archer);
        Entities::MovingEntities::Enemy* pEnemy = static_cast<Entities::MovingEntities::Enemy*>(archer);
        entityList->pushEntity(pEntity);
        collisions->pushEnemy(pEnemy);

        pEntity = static_cast<Entities::Entity*>(archer->getArrow());
        entityList->pushEntity(pEntity);

    }
    void Level::createBoss(sf::Vector2f pos)
    {
        //TODO
    }

    void Level::createGround(std::string fileName, sf::Vector2f pos)
    {
        Entities::StaticEntities::Ground *pAuxObstacle = new Entities::StaticEntities::Ground(fileName, sf::Vector2f(20, 20), pos);
                
        Entities::StaticEntities::Obstacle* pCastObsAux = static_cast<Entities::StaticEntities::Obstacle*>(pAuxObstacle);
        collisions->pushObstacle(pCastObsAux);

        Entities::Entity* pCastAux = static_cast<Entities::Entity*>(pAuxObstacle);
        entityList->pushEntity(pCastAux);

    }

    void Level::createCactus(sf::Vector2f pos)
    {
        Entities::StaticEntities::Cactus *pAuxObstacle = new Entities::StaticEntities::Cactus( CACTUS_PATH, sf::Vector2f(80, 20), pos);

        Entities::StaticEntities::Obstacle* pCastObsAux = static_cast<Entities::StaticEntities::Obstacle*>(pAuxObstacle);
        collisions->pushObstacle(pCastObsAux);

        Entities::Entity* pCastAux = static_cast<Entities::Entity*>(pAuxObstacle);
        entityList->pushEntity(pCastAux);
    }

    void Level::createWeb(sf::Vector2f pos)
    {
        Entities::StaticEntities::Web *pAuxObstacle = new Entities::StaticEntities::Web( WEB_PATH, sf::Vector2f(80, 20), pos, 0.5f);

        Entities::StaticEntities::Obstacle* pCastObsAux = static_cast<Entities::StaticEntities::Obstacle*>(pAuxObstacle);
        collisions->pushObstacle(pCastObsAux);

        Entities::Entity* pCastAux = static_cast<Entities::Entity*>(pAuxObstacle);
        entityList->pushEntity(pCastAux);
    }

}// namespace Levels