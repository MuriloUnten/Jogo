#include "Level.hpp"


namespace Levels
{
    Level::Level(std::string fileName, sf::Vector2f size, sf::Vector2f position):
    Being(fileName, size, position),
    player(),
    entityList(new Lists::EntityList())
    {
        Entities::Entity* pAux = static_cast<Entities::Entity*>(&player);
        entityList->pushEntity(pAux);
    }


    Level::Level():
    Being(),
    entityList(new Lists::EntityList())
    {
        
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