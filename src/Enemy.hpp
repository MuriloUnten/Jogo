
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
            Enemy(ID id, const std::string fileName, sf::Vector2f size, sf::Vector2f position=sf::Vector2f(0, 0), int hp=1);
            Enemy();
            ~Enemy();

            virtual void execute() = 0;
            virtual void affectPlayer(MovingEntities::Player* player) = 0;

        };
    }// namespace MovingEntities

}// namespace Entities