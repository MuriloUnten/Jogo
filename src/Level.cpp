#include "Level.hpp"


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


    void Level::createLevel()
    {
        createPlayers();
        createEnemies();
        createObstacles();
    }

}// namespace Levels