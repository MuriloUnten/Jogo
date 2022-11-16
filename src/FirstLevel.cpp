#include "FirstLevel.hpp"
#include <cstdlib>

#define PLAYER_PATH "../assets/personagem/kakashi1.png"
#define ENEMY_PATH "../assets/inimigos/enemy1.png"
#define CACTUS_PATH "../assets/mundo/espinho_tile.png"
#define GROUND2_PATH "../assets/mundo/ground_tile.png" 
#define GROUND3_PATH "../assets/mundo/ground2_tile.png"


namespace Levels
{
    FirstLevel::FirstLevel(std::string fileName, sf::Vector2f size, sf::Vector2f position, Entities::MovingEntities::Player* player):
    Level(fileName, size, position, player),
    enemy(new Entities::MovingEntities::Enemy(ENEMY_PATH, sf::Vector2f(50, 50), sf::Vector2f(780, 390)))
    {
        pPlayer->loadTexture(PLAYER_PATH);
        pPlayer->setSize(sf::Vector2f(50, 60));
        pPlayer->getHitBox()->setTexture(pPlayer->getTexture());
        pPlayer->setPos(sf::Vector2f(100, 250));


        Entities::Entity* pEnemy = static_cast<Entities::Entity*>(enemy);
        entityList->pushEntity(pEnemy);
        collisions->pushEnemy(enemy);

        //Construindo fase
        FILE *file;
        int ch;
        float obstacleSize = 20.0;
        float width = 0.0, height = 0.0;
        file = fopen("Firstlevel.txt", "r");
        if(file == NULL)
        {
            std::cout << "Error opening File.\n";
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


    FirstLevel::~FirstLevel()
    {
        delete enemy;
        entityList->clear();
        entityList = NULL;
    }

}// namespace Levels