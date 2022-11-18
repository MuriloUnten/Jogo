#pragma once

#define ENEMY1_ATTACK_COOLDOWN 2

#include "Enemy.hpp"


namespace Entities
{
    namespace MovingEntities
    {
        class Enemy1 : public Enemy
        {
        private:
            

        public:
            Enemy1(const std::string fileName, sf::Vector2f size, sf::Vector2f position=sf::Vector2f(0.0f, 0.0f), int hp=1);
            ~Enemy1();

            void execute();

        };
    }// namespace MovingEntities
}// namespace Entities