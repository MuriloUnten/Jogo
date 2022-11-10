#pragma once

#include "Level.hpp"


namespace Levels
{
    class FirstLevel: public Level
    {
        private:
            Entities::MovingEntities::Enemy* enemy;

        public:
            FirstLevel(std::string fileName, sf::Vector2f size, sf::Vector2f position=sf::Vector2f(0, 0), Entities::MovingEntities::Player* player=NULL);
            ~FirstLevel();
    };

}// namespace Levels
