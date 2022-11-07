#pragma once

#include "Being.hpp"
#include "EntityList.hpp"
#include "PLayer.hpp"


namespace Levels
{
    class Level : public Being
    {
    protected:
	    Lists::EntityList* entityList;
        Entities::MovingEntities::Player player;

    public:
        Level(std::string fileName, sf::Vector2f size, sf::Vector2f position=sf::Vector2f(0, 0));
        Level();
        ~Level();
        void execute();
    };
}// namespace Levels
