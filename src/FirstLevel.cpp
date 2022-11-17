#include "FirstLevel.hpp"
#include <cstdlib>

#define PLAYER_PATH "../assets/personagem/kakashi1.png"
#define ENEMY1_PATH "../assets/inimigos/enemy1.png"
#define ARCHER_PATH "../assets/inimigos/arqueiro.png"
#define CACTUS_PATH "../assets/mundo/espinho_tile.png"
#define GROUND2_PATH "../assets/mundo/ground_tile.png" 
#define GROUND3_PATH "../assets/mundo/ground2_tile.png"
#define ARROW_PATH "../assets/inimigos/flecha.png"


namespace Levels
{
    FirstLevel::FirstLevel(std::string fileName, sf::Vector2f size, sf::Vector2f position, Entities::MovingEntities::Player* player):
    Level(fileName, size, position, player)
    {
        createLevel();
    }


    FirstLevel::~FirstLevel()
    {

    }


    void FirstLevel::createPlayers()
    {
        pPlayer->loadTexture(PLAYER_PATH);
        pPlayer->setSize(sf::Vector2f(50, 60));
        pPlayer->getHitBox()->setTexture(pPlayer->getTexture());
        pPlayer->setPos(sf::Vector2f(400, 380));
    }


    void FirstLevel::createEnemies()
    {
        Entities::MovingEntities::Enemy1* enemy = new Entities::MovingEntities::Enemy1(ENEMY1_PATH, sf::Vector2f(50, 50), sf::Vector2f(780, 390));
        Entities::Entity* pEntity = static_cast<Entities::Entity*>(enemy);
        Entities::MovingEntities::Enemy* pEnemy = static_cast<Entities::MovingEntities::Enemy*>(enemy);
        entityList->pushEntity(pEntity);
        collisions->pushEnemy(pEnemy);

        enemy = new Entities::MovingEntities::Enemy1(ENEMY1_PATH, sf::Vector2f(50, 50), sf::Vector2f(1000, 100));
        pEntity = static_cast<Entities::Entity*>(enemy);
        pEnemy = static_cast<Entities::MovingEntities::Enemy*>(enemy);
        entityList->pushEntity(pEntity);
        collisions->pushEnemy(pEnemy);
        
        enemy = new Entities::MovingEntities::Enemy1(ENEMY1_PATH, sf::Vector2f(50, 50), sf::Vector2f(100, 600));
        pEntity = static_cast<Entities::Entity*>(enemy);
        pEnemy = static_cast<Entities::MovingEntities::Enemy*>(enemy);
        entityList->pushEntity(pEntity);
        collisions->pushEnemy(pEnemy);


        Entities::MovingEntities::Archer* archer = new Entities::MovingEntities::Archer(ARCHER_PATH, sf::Vector2f(50, 50), sf::Vector2f(440.0f, 40));
        archer->setPlayer(pPlayer);
        pEntity = static_cast<Entities::Entity*>(archer);
        pEnemy = static_cast<Entities::MovingEntities::Enemy*>(archer);
        entityList->pushEntity(pEntity);
        collisions->pushEnemy(pEnemy);

        pEntity = static_cast<Entities::Entity*>(archer->getArrow());
        entityList->pushEntity(pEntity);
    }


    void FirstLevel::createObstacles()
    {
        FILE *file;
        int ch;
        float obstacleSize = 20.0;
        float width = 0.0, height = 0.0;
        file = fopen("FirstLevel.txt", "r");
        if(file == NULL)
        {
            std::cout << "Error opening File.\n";
            exit(1);
        }

        while((ch = fgetc(file)) != EOF)
        {
            //cactus
            if(ch == '1')
            {
                Entities::StaticEntities::Cactus *pAuxObstacle = new Entities::StaticEntities::Cactus(CACTUS_PATH, sf::Vector2f(obstacleSize,obstacleSize), sf::Vector2f(width * obstacleSize, height * obstacleSize));

                Entities::StaticEntities::Obstacle* pCastObsAux = static_cast<Entities::StaticEntities::Obstacle*>(pAuxObstacle);
                collisions->pushObstacle(pCastObsAux);

                Entities::Entity* pCastAux = static_cast<Entities::Entity*>(pAuxObstacle);
                entityList->pushEntity(pCastAux);
            }

            //ground
            else if(ch == '2')
            {
                Entities::StaticEntities::Ground *pAuxObstacle = new Entities::StaticEntities::Ground(GROUND2_PATH, sf::Vector2f(obstacleSize,obstacleSize), sf::Vector2f(width * obstacleSize, height * obstacleSize));
                
                Entities::StaticEntities::Obstacle* pCastObsAux = static_cast<Entities::StaticEntities::Obstacle*>(pAuxObstacle);
                collisions->pushObstacle(pCastObsAux);

                Entities::Entity* pCastAux = static_cast<Entities::Entity*>(pAuxObstacle);
                entityList->pushEntity(pCastAux);
            }

            else if(ch == '3')
            {
                Entities::StaticEntities::Ground* pAuxObstacle = new Entities::StaticEntities::Ground(GROUND3_PATH, sf::Vector2f(obstacleSize,obstacleSize), sf::Vector2f(width * obstacleSize, height * obstacleSize));
                
                Entities::StaticEntities::Obstacle* pCastObsAux = static_cast<Entities::StaticEntities::Obstacle*>(pAuxObstacle);
                collisions->pushObstacle(pCastObsAux);
                
                Entities::Entity* pCastAux = static_cast<Entities::Entity*>(pAuxObstacle);
                entityList->pushEntity(pCastAux);
            }

            width++;

            if(width == 65)
            {
                width = 0;
                height++;
            }
        }
        fclose(file);
    }

}// namespace Levels