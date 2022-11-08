#include "Level.hpp"


namespace Levels
{
    Level::Level(std::string fileName, sf::Vector2f size, sf::Vector2f position, Entities::MovingEntities::Player* player):
    Being(fileName, size, position),
    entityList(new Lists::EntityList())
    {
        pPlayer = player;
        Entities::Entity* pAux = static_cast<Entities::Entity*>(pPlayer);
        entityList->pushEntity(pAux);
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
    }


    void Level::execute()
    {
        //update delta time
        draw();

        for(int i = 0; i < entityList->getSize(); i++)
            entityList->getList()[i]->execute();

    }

}// namespace Levels