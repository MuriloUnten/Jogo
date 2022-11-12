#include "FirstLevel.hpp"

#define PLAYER_PATH "../assets/personagem/kakashi1.png"
#define TILE_PATH "../assets/mundo/plataform.png"
#define ENEMY_PATH "../assets/inimigos/enemy1.png"


namespace Levels
{
    FirstLevel::FirstLevel(std::string fileName, sf::Vector2f size, sf::Vector2f position, Entities::MovingEntities::Player* player):
    Level(fileName, size, position, player),
    enemy(new Entities::MovingEntities::Enemy(ENEMY_PATH, sf::Vector2f(100,100), sf::Vector2f(400,400) ))
    {
        pPlayer->loadTexture(PLAYER_PATH);
        pPlayer->getHitBox()->setSize(sf::Vector2f(100, 120));
        pPlayer->getHitBox()->setPosition(sf::Vector2f(300, 300));
        pPlayer->getHitBox()->setTexture(pPlayer->getTexture());
        pPlayer->setPos(sf::Vector2f(100, 300));


        Entities::Entity* pEnemy = static_cast<Entities::Entity*>(enemy);
        entityList->pushEntity(pEnemy);
        collisions->pushEnemy(enemy);

        // Temporary ground
        float obstacleSize = 50;
        for(int i = 0; i < int(WIDTH / obstacleSize); i++)
        {
            Entities::StaticEntities::Obstacle* pAuxObstacle = new Entities::StaticEntities::Obstacle(TILE_PATH, sf::Vector2f(obstacleSize, obstacleSize), sf::Vector2f(i * obstacleSize, HEIGHT - obstacleSize));
            Entities::Entity* pCastAux = static_cast<Entities::Entity*>(pAuxObstacle);
            entityList->pushEntity(pCastAux);
            collisions->pushObstacle(pAuxObstacle);
        }
        for(int i = 0; i < int(WIDTH / obstacleSize); i++)
        {
            Entities::StaticEntities::Obstacle* pAuxObstacle = new Entities::StaticEntities::Obstacle(TILE_PATH, sf::Vector2f(obstacleSize, obstacleSize), sf::Vector2f(i * obstacleSize, 0));
            Entities::Entity* pCastAux = static_cast<Entities::Entity*>(pAuxObstacle);
            entityList->pushEntity(pCastAux);
            collisions->pushObstacle(pAuxObstacle);
        }
        for(int i = 0; i < int(HEIGHT / obstacleSize); i++)
        {
            Entities::StaticEntities::Obstacle* pAuxObstacle = new Entities::StaticEntities::Obstacle(TILE_PATH, sf::Vector2f(obstacleSize, obstacleSize), sf::Vector2f( 0, i * obstacleSize));
            Entities::Entity* pCastAux = static_cast<Entities::Entity*>(pAuxObstacle);
            entityList->pushEntity(pCastAux);
            collisions->pushObstacle(pAuxObstacle);
        }
        for(int i = 0; i < int(HEIGHT / obstacleSize); i++)
        {
            Entities::StaticEntities::Obstacle* pAuxObstacle = new Entities::StaticEntities::Obstacle(TILE_PATH, sf::Vector2f(obstacleSize, obstacleSize), sf::Vector2f( (WIDTH- obstacleSize) , i * obstacleSize));
            Entities::Entity* pCastAux = static_cast<Entities::Entity*>(pAuxObstacle);
            entityList->pushEntity(pCastAux);
            collisions->pushObstacle(pAuxObstacle);
        }
    }


    FirstLevel::~FirstLevel()
    {
        delete enemy;
        entityList->clear();
        entityList = NULL;
    }

}// namespace Levels