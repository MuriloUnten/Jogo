#pragma once

#include "Character.hpp"
#include "Enemy.hpp"

namespace Entities
{
    namespace MovingEntities
    {
        class Player : public Character
        {
        private:
            bool run;
            bool atack;
            bool jump;

        public:
            Player(const std::string fileName, sf::Vector2f size, sf::Vector2f position=sf::Vector2f(0, 0), int hp=3);
            Player();
            ~Player();

            void execute();

            bool isAtack();
            void takeDamage(Enemy *Enemy );

        };
    }// namespace MovingEntities

}// namespace Entities