#include "FirstLevel.hpp"

#define PLAYER_PATH "../assets/personagem/correndo.png"
#define TILE_PATH "../assets/mundo/plataform.png"


namespace Levels
{
    FirstLevel::FirstLevel(std::string fileName, sf::Vector2f size, sf::Vector2f position, Entities::MovingEntities::Player* player):
    Level(fileName, size, position, player)
    {
        pPlayer->loadTexture(PLAYER_PATH);
        pPlayer->getHitBox()->setSize(sf::Vector2f(100, 100));
        pPlayer->getHitBox()->setPosition(sf::Vector2f(0, 0));
        pPlayer->getHitBox()->setTexture(pPlayer->getTexture());
        pPlayer->setPos(sf::Vector2f(0, 300));


        // Temporary ground
        float obstacleSize = 50;
        for(int i = 0; i < int(WIDTH / obstacleSize); i++)
        {
            Entities::StaticEntities::Obstacle* pAuxObstacle = new Entities::StaticEntities::Obstacle(TILE_PATH, sf::Vector2f(obstacleSize, obstacleSize), sf::Vector2f(i * obstacleSize, HEIGHT - obstacleSize));
            Entities::Entity* pCastAux = static_cast<Entities::Entity*>(pAuxObstacle);
            entityList->pushEntity(pCastAux);
            collisions->pushObstacle(pAuxObstacle);
        }
    }


    FirstLevel::~FirstLevel()
    {

    }

}// namespace Levels