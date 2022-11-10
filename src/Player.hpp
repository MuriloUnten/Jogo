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
            bool walking;
            bool canAttack;
            bool attacking;
            bool canJump;
            bool jumping;

        public:
            Player(const std::string fileName, sf::Vector2f size, sf::Vector2f position=sf::Vector2f(0, 0), int hp=3);
            Player();
            ~Player();

            void execute();

            bool isAttacking();

        };
    }// namespace MovingEntities

}// namespace Entities
