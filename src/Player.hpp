#pragma once

#include "Character.hpp"
#include "Coordinate.hpp"

namespace Entities
{
    namespace MovingEntities
    {
        class Player : public Character
        {
        private:


        public:
            Player(const std::string fileName, sf::Vector2f size, sf::Vector2f position=sf::Vector2f(0, 0), int hp=3);
            Player();
            ~Player();

            void execute();
            void Collide(Entity* otherEntity, Math::CoordF intersect);

        };
    }// namespace MovingEntities

}// namespace Entities

