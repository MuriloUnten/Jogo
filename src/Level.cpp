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
    }


    void Level::execute()
    {
        //update delta time
        draw();

        //std::cout << pPlayer->getPos().x << "   " << pPlayer->getPos().y << std::endl;

        // TODO Fix. 1st move, 2nd collide, 3rd draw
        for(int i = 0; i < entityList->getSize(); i++)
            entityList->getList()[i]->execute();
            
        collisions->Collision();
        
        for(int i = 0; i < entityList->getSize(); i++)
            entityList->getList()[i]->draw();
        
        //std::cout << pPlayer->getPos().x << "   " << pPlayer->getPos().y << std::endl;

    }

}// namespace Levels