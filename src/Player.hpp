#pragma once

#define PLAYER_ATTACK_COOLDOWN 1

#include "Character.hpp"
#include "Enemy.hpp"


namespace Entities
{
    namespace MovingEntities
    {
        class Player : public Character
        {
        private:
            bool posDirection;

        public:
            Player(const std::string fileName, sf::Vector2f size, sf::Vector2f position=sf::Vector2f(0, 0), int hp=3);
            Player();
            ~Player();
            bool getPositiveDirection() const;
            void execute();
        };
    }// namespace MovingEntities

}// namespace Entities
