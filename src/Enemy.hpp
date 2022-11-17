
#pragma once

#include "Character.hpp"
#include "Coordinate.hpp"

namespace Entities
{
    namespace MovingEntities
    {
        class Enemy : public Character
        {
        protected:
            

        public:
            Enemy(const std::string fileName, sf::Vector2f size, sf::Vector2f position=sf::Vector2f(0, 0), int hp=1);
            Enemy();
            ~Enemy();

            void execute();

        };
    }// namespace MovingEntities

}// namespace Entities